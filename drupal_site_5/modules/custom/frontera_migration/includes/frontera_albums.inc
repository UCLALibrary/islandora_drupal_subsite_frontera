<?php

/**
 * Class FronteraAlbums
 */
class FronteraAlbums extends Migration {
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $this->description = t('Import album names from the recordings spreadsheet.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'TitleofAlbum' => array(
          'type' => 'varchar',
          'length' => 255,
          'notnull' => TRUE,
          'description' => 'ID column of the frontera_migration_prepared table.',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $query = db_select('frontera_migration_prepared', 'f')
      ->fields('f', array('id', 'TitleofAlbum'))
      ->groupBy('TitleofAlbum');

    $query->condition('f.TitleofAlbum', '[a-zA-Z0-9]+', 'REGEXP');

    $map_table = $this->getMap()->getMapTable();
    $query->innerJoin($map_table, 'mt', 'mt.sourceid1 = f.TitleofAlbum');

    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationNode('container');

    $this->addFieldMapping('title', 'TitleofAlbum');

    $this->addFieldMapping('uid')
      ->defaultValue(1);

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
      'field_container_recording',
      )
    );
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

    if (empty($row->TitleofAlbum)) {
      return FALSE;
    }

    // Avoid start/end spaces
    $row->TitleofAlbum = trim($row->TitleofAlbum);
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

    // Avoid overflow of titles
    $name = substr($name, 0, 200);

    migrate_instrument_start(__CLASS__ . '::createStub');
    $node = new stdClass;

    $node->type = $this->destination->getBundle();
    $node->language = LANGUAGE_NONE;

    node_object_prepare($node);

    $node->uid = 1;
    $node->title = $name . ' (STUB)';

    $message = t('This node is a migration stub. It means it has been created because it is referenced from another migrated node but its content is not valid until the full migration is run.');

    $node->body = $message;

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
      $node->field_container_recording = $old_node->field_container_recording;
    }
  }
}
