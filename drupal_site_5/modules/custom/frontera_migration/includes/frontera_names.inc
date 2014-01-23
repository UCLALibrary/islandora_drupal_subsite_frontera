<?php

/**
 * Class FronteraNames
 *
 * Generalization of the names migration.
 *
 * There is a required argument field_name that specifies what column from the
 * source table is going to be used as node title.
 *
 * Example:
 *
 * class FronteraArtists extends FronteraNames {
 *   public function __construct($arguments = array()) {
 *
 *     $arguments['field_name'] = 'ArtistsStandardName';
 *
 *     parent::__construct($arguments);
 *   }
 * }
 *
 */
class FronteraNames extends Migration {
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $field_name = $arguments['field_name'];
    $this->field_name = $field_name;

    $this->description = t('Import names from the recordings spreadsheet.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        $field_name => array(
          'type' => 'varchar',
          'length' => 255,
          'notnull' => TRUE,
          'description' => 'ID column of the frontera_migration_prepared table.',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $query = db_select('frontera_migration_prepared', 'f')
      ->fields('f', array('id', $field_name))
      ->groupBy($field_name);

    // Make sure the title is not empty
    $query->condition("f.$field_name", '[a-zA-Z0-9]+', 'REGEXP');

    // This is a special case
    $query->condition("f.$field_name", '#+', 'NOT REGEXP');

    $map_table = $this->getMap()->getMapTable();
    $query->innerJoin($map_table, 'mt', 'mt.sourceid1 = f.' . $field_name);

    $extra_fields = array('image_file');

    $this->source = new MigrateSourceSQL($query, $extra_fields);
    $this->destination = new MigrateDestinationNode('name');

    $this->addFieldMapping('title', $field_name);

    $this->addFieldMapping('field_biography')
      ->defaultValue('');

    $this->addFieldMapping('uid')
      ->defaultValue(1);

    $this->addFieldMapping('field_images', 'image_file');
    $this->addFieldMapping('field_images:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);

    $this->addUnmigratedDestinations(array(
        'created',
        'changed',
        'status',
        'promote',
        'sticky',
        'revision',
        'log',
        'language',
        'tnid',
        'translate',
        'revision_uid',
        'is_new',
        'path',
        'comment',
      )
    );

    $this->addUnmigratedDestinations(array(
      // todo: is this stored anywhere?
      'field_alternative_names',
      'field_alternative_names:language',

      // todo: is this stored anywhere?
      'field_biography:language',

      'field_images:file_class',
      'field_images:language',
      'field_images:preserve_files',
      'field_images:destination_dir',
      'field_images:destination_file',
      'field_images:source_dir',
      'field_images:urlencode',
      'field_images:alt',
      'field_images:title',

      // todo: make sure this is populated by corresponding references
      'field_recordings_composed',
      'field_recordings_produced',
      'field_recordings_recorded',
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

    $field_name = $this->field_name;

    if (empty($row->{$field_name})) {
      return FALSE;
    }

    // Avoid start end spaces
    $clean_name = trim($row->{$field_name});
    $row->{$field_name} = $clean_name;

    // Migration of image files

    // Escape preg_match chars
    $clean_name = str_replace('(', '\(', $clean_name);
    $clean_name = str_replace(')', '\)', $clean_name);
    $clean_name = str_replace('[', '\]', $clean_name);

    $source_dir = DRUPAL_ROOT . '/../assets/artist_images';

    // Filenames usually start with the artist name.
    // Case insensitive
    // Numbers may be appended for multiple images.
    $mask = '@.*' . $clean_name . '.*\.jpg$@i';
    $files = file_scan_directory($source_dir, $mask);

    // In some cases instead of spaces they use dashes.
    $d_name = str_replace(' ', '_', $clean_name);
    $mask = '@.*' . $d_name . '.*\.jpg$@i';
    $files_temp = file_scan_directory($source_dir, $mask);
    $files = array_merge_recursive($files, $files_temp);

    // In other cases the name of the artist imported is like Fender, Freddy
    // and the filename is Freddy_Fender.jpg
    $parts = explode(', ', $clean_name);
    if (count($parts) == 2) {
      $rev_name = $parts[1] . '_' . $parts[0];
      $mask = '@.*' . $rev_name . '.*\.jpg$@i';
      $files_temp = file_scan_directory($source_dir, $mask);
      $files = array_merge_recursive($files, $files_temp);

      // Also with spaces.
      $rev_name = $parts[1] . ' ' . $parts[0];
      $mask = '@.*' . $rev_name . '.*\.jpg$@i';
      $files_temp = file_scan_directory($source_dir, $mask);
      $files = array_merge_recursive($files, $files_temp);
    }

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
    $name = trim($source_key[0]);
    if (empty($name)) {
      return FALSE;
    }

    migrate_instrument_start(__CLASS__ . '::createStub');
    $node = new stdClass;

    $node->type = $this->destination->getBundle();
    $node->language = LANGUAGE_NONE;

    node_object_prepare($node);

    $node->uid = 1;

    // Avoid overflow of titles
    $name = substr($name, 0, 200);

    $node->title = $name . ' (STUB)';

    $message = t('This node is a migration stub. It means it has been created because it is referenced from another migrated node but its content is not valid until the full migration is run.');

    $node->body = $message;

    $node->field_biography = array(
      LANGUAGE_NONE => array(
        array('value' => $message),
      ),
    );

    node_save($node);
    migrate_instrument_stop(__CLASS__ . '::createStub');

    if (isset($node->nid)) {
      return array($node->nid);
    }
    else {
      return FALSE;
    }
  }


  /**
   * Implements prepare().
   *
   * @param $node
   * @param $row
   */
  public function prepare($node, $row) {
    if ($node->nid) {
      // In case of an update run, never override some fields
      $old_node = node_load($node->nid);
      $node->field_recordings_recorded = $old_node->field_recordings_recorded;
      $node->field_recordings_composed = $old_node->field_recordings_composed;
      $node->field_recordings_produced = $old_node->field_recordings_produced;
    }
  }
}
