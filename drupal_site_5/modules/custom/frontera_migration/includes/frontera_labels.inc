<?php

/**
 * Class FronteraLabels
 */
class FronteraLabels extends Migration {
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $this->description = t('Import label names from the recordings spreadsheet.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'RecordLabel' => array(
          'type' => 'varchar',
          'length' => 255,
          'notnull' => TRUE,
          'description' => 'ID column of the frontera_migration_prepared table.',
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $query = db_select('frontera_migration_prepared', 'f')
      ->fields('f', array('id', 'RecordLabel', 'CountryofLabel'))
      ->groupBy('RecordLabel');

    $query->condition('f.RecordLabel', '[a-zA-Z0-9]+', 'REGEXP');

    $map_table = $this->getMap()->getMapTable();
    $query->innerJoin($map_table, 'mt', 'mt.sourceid1 = f.RecordLabel');

    $query->leftJoin('frontera_label_histories', 'flh', 'flh.label = RecordLabel');
    $query->fields('flh', array('history'));

    $extra_fields = array('image_file');

    $this->source = new MigrateSourceSQL($query, $extra_fields);
    $this->destination = new MigrateDestinationTerm('label');

    $this->vocab = taxonomy_vocabulary_machine_name_load('label');

    $this->addFieldMapping('name', 'RecordLabel');

    $this->addFieldMapping('field_country', 'CountryofLabel');
    $this->addFieldMapping('field_country:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_country:ignore_case')
      ->defaultValue(TRUE);

    $this->addFieldMapping('description', 'history')
      ->defaultValue('');

    $this->addUnmigratedDestinations(array(
        'path',
      )
    );

    $this->addFieldMapping('field_images', 'image_file');
    $this->addFieldMapping('field_images:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);

    $this->addUnmigratedDestinations(array(
      'parent',
      'parent_name',
      'format',
      'weight',
      'field_images:file_class',
      'field_images:language',
      'field_images:preserve_files',
      'field_images:destination_dir',
      'field_images:destination_file',
      'field_images:urlencode',
      'field_images:alt',
      'field_images:title',
      'field_images:source_dir',

      'field_country:source_type',
    ));

  }

  /**
   * Implements prepareRow();
   *
   * @param $row
   *
   * @return bool
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Avoid start/end spaces
    $row->RecordLabel = trim($row->RecordLabel);

    if (empty($row->RecordLabel)) {
      return FALSE;
    }

    // Migration of image files

    $source_dir = DRUPAL_ROOT . '/../assets/label_images';

    $lc_name = $row->RecordLabel;

    // Filenames usually start with the label name.
    // Case insensitive
    // Numbers may be appended for multiple images.
    $mask = '@.*' . $lc_name . '.*\.jpg$@i';
    $files = file_scan_directory($source_dir, $mask);

    // In some cases instead of spaces they use dashes
    $lc_name = str_replace(' ', '_', $lc_name);
    $mask = '@.*' . $lc_name . '.*\.jpg$@i';
    $files_temp = file_scan_directory($source_dir, $mask);

    $files = array_merge_recursive($files, $files_temp);

    $image_files = array();
    foreach ($files as $file) {
      $image_files[] = $file->uri;
    }
    $row->image_file = $image_files;
  }

  /**
   * Implementation of Migration::createStub().
   *
   * @param $migration
   * @return array|bool
   */
  protected function createStub(Migration $migration, $source_key) {
    migrate_instrument_start(__CLASS__ . '::createStub');

    $name = trim($source_key[0]);
    if (empty($name)) {
      return FALSE;
    }

    // Avoid overflow of titles
    $name = substr($name, 0, 200);

    $term = new stdClass;
    $term->vocabulary_machine_name = $this->destination->getBundle();
    $term->vid = $this->vocab->vid;

    $term->name = $name . ' (STUB)';

    $message = t('This term is a migration stub. It means it has been created because it is referenced from another migrated term but its content is not valid until the migration FronteraLabels is run.');
    $term->description = $message;
    $term->format = 'filtered_html';
    $term->weight = 0;

    taxonomy_term_save($term);

    migrate_instrument_stop(__CLASS__ . '::createStub');

    if (isset($term->tid)) {
      return array($term->tid);
    }
    else {
      return FALSE;
    }
  }
}
