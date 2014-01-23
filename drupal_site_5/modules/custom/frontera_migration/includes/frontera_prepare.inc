<?php

/**
 * Class FronteraPrepare
 */
class FronteraPrepare extends Migration {
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $this->description = t('Import all rows from the spreadsheet into a sql table.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'csvrownum' => array(
          'type' => 'varchar',
          'length' => 24,
          'notnull' => TRUE,
          'description' => 'CSV Row number.',
        ),
      ),
      MigrateDestinationTable::getKeySchema('frontera_migration_prepared')
    );

    // The standard source file
    $source_file = DRUPAL_ROOT .'/../assets/Frontera-Recordings-data.csv';

    // Debug facility, --idlist doesn't work well with csv and multilines
    // Put the header and line to debug in this separate file and test
    $test = FALSE;
    if ($test) {
      $source_file = DRUPAL_ROOT .'/../assets/frontera-test.csv';
    }

    $options = array(
      'header_rows' => 1,
      'embedded_newlines' => TRUE,
    );
    $this->source = new MigrateSourceCSV($source_file, $this->csvcolumns(), $options);
    $this->destination = new MigrateDestinationTable('frontera_migration_prepared');

    $this->addFieldMapping('Accompaniment', 'Accompaniment');
    $this->addFieldMapping('ArtistonLabel', 'ArtistonLabel');
    $this->addFieldMapping('ArtistsRealNames', 'ArtistsRealNames');
    $this->addFieldMapping('ArtistsStandardName', 'ArtistsStandardName');
    $this->addFieldMapping('Catalognumberalpha', 'Catalognumberalpha');
    $this->addFieldMapping('CatNumberSort', 'CatNumberSort');
    $this->addFieldMapping('Composer', 'Composer');
    $this->addFieldMapping('Condition_val', 'Condition');
    $this->addFieldMapping('CountryofLabel', 'CountryofLabel');
    $this->addFieldMapping('Holding', 'Holding');
    $this->addFieldMapping('KeyWord', 'KeyWord');
    $this->addFieldMapping('labelphonenumber', 'labelphonenumber');
    $this->addFieldMapping('LabelSongType', 'LabelSongType');
    $this->addFieldMapping('LabelTitle', 'LabelTitle');
    $this->addFieldMapping('MatrixNumber', 'MatrixNumber');
    $this->addFieldMapping('Notes', 'Notes');
    $this->addFieldMapping('Producer', 'Producer');
    $this->addFieldMapping('Publisher', 'Publisher');
    $this->addFieldMapping('RecordLabel', 'RecordLabel');
    $this->addFieldMapping('RecordingDate', 'RecordingDate');
    $this->addFieldMapping('RecordingFormat', 'RecordingFormat');
    $this->addFieldMapping('RecordingLocation', 'RecordingLocation');
    $this->addFieldMapping('Side', 'Side');
    $this->addFieldMapping('Styli', 'Styli');
    $this->addFieldMapping('Time', 'Time');
    $this->addFieldMapping('TitleofAlbum', 'TitleofAlbum');
    $this->addFieldMapping('TrackNumber', 'TrackNumber');
    $this->addFieldMapping('TransferFileName', 'TransferFileName');
    $this->addFieldMapping('TransferEquipt', 'TransferEquipt');
    $this->addFieldMapping('Yearofcopyright', 'Yearofcopyright');
    $this->addFieldMapping('AlbumArtist', 'AlbumArtist');
  }

  protected function csvcolumns() {
    $columns[0] = array('Accompaniment', 'Accompaniment');
    $columns[1] = array('AlbumArtist', 'Album Artist');
    $columns[2] = array('ArtistonLabel', 'Artist on Label');
    $columns[3] = array('ArtistsRealNames', "Artist's Real Names");
    $columns[4] = array('ArtistsStandardName', 'Artists Standard Name');
    $columns[5] = array('Catalognumberalpha', 'Catalog number alpha');
    $columns[6] = array('CatNumberSort', 'Cat Number Sort');
    $columns[7] = array('Composer', 'Composer');
    $columns[8] = array('Condition', 'Condition');
    $columns[9] = array('CountryofLabel', 'Country of Label');
    $columns[10] = array('Holding', 'Holding');
    $columns[11] = array('KeyWord', 'Key Word');
    $columns[12] = array('labelphonenumber', 'labelphonenumber');
    $columns[13] = array('LabelSongType', 'LabelSongType');
    $columns[14] = array('LabelTitle', 'Label Title');
    $columns[15] = array('MatrixNumber', 'MatrixNumber');
    $columns[16] = array('Notes', 'Notes');
    $columns[17] = array('Producer', 'Producer');
    $columns[18] = array('Publisher', 'Publisher');
    $columns[19] = array('RecordLabel', 'Record Label');
    $columns[20] = array('RecordingDate', 'Recording Date');
    $columns[21] = array('RecordingFormat', 'Recording Format');
    $columns[22] = array('RecordingLocation', 'Recording Location');
    $columns[23] = array('Side', 'Side');
    $columns[24] = array('Styli', 'Styli');
    $columns[25] = array('Time', 'Time');
    $columns[26] = array('TitleofAlbum', 'Title of Album');
    $columns[27] = array('TrackNumber', 'Track Number');
    $columns[28] = array('TransferEquipt', 'Transfer Equipt');
    $columns[29] = array('TransferFileName', 'Transfer File Name');
    $columns[30] = array('Yearofcopyright', 'Year of copyright');

    return $columns;
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $fields = array_keys((array)$row);
    foreach ($fields as $field_name) {
      $source = $row->$field_name;

      mb_substitute_character("none");

      $source_encoding = mb_detect_encoding($source, "auto");
      //$source_encoding = 'Windows-1252';

      $row->$field_name = mb_convert_encoding($source, $source_encoding, 'UTF-8');

      // Some names may be enclosed in spaces or quotes
      $row->$field_name = trim($row->$field_name, " '\"");
    }
  }
}

