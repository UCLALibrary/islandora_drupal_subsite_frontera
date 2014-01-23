<?php

/**
 * @file
 * Migration for importing label histories into db.
 */

/**
 * Class FronteraHistories
 */
class FronteraHistories extends Migration {
  /**
   * Migration Constructor.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $this->description = t('Import all label histories into a sql table.');

    // Create a map object for tracking the relationships between source rows.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'csvrownum' => array(
          'type' => 'varchar',
          'length' => 24,
          'notnull' => TRUE,
          'description' => 'CSV row num',
        ),
      ),
      MigrateDestinationTable::getKeySchema('frontera_label_histories')
    );

    // The standard source file.
    $source_file = DRUPAL_ROOT . '/../assets/label-histories.csv';

    $options = array(
      'header_rows' => 1,
      'embedded_newlines' => TRUE,
    );
    $this->source = new MigrateSourceCSV($source_file, $this->csvcolumns(), $options);
    $this->destination = new MigrateDestinationTable('frontera_label_histories');

    $this->addFieldMapping('label', 'LabelName');
    $this->addFieldMapping('history', 'Bio');
  }

  /**
   * Return csv columns order.
   */
  protected function csvcolumns() {
    $columns[0] = array('Bio', 'Bio');
    $columns[1] = array('LabelName', 'LabelName');

    return $columns;
  }
}
