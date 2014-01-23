<?php

/**
 * Class FronteraRecordings
 */
class FronteraRecordings extends Migration {
  public function __construct($arguments = array()) {
    parent::__construct($arguments);

    $this->description = t('Import recordings from the recordings spreadsheet.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'length' => 8,
          'notnull' => TRUE,
          'description' => 'ID column of the frontera_migration_prepared table.',
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $query = db_select('frontera_migration_prepared', 'f')
      ->fields('f');

    // These dummy fields are added to the source to be populated in prepareRow().
    $extra_fields = array(
      'image_url' => t('Image url procesed in prepareRow from TransferFileName'),
      'image_filepath' => t('The final filepath of the recoding image. Set in prepareRow'),
    );

    $this->source = new MigrateSourceSQL($query, $extra_fields);
    $this->destination = new MigrateDestinationNode('recording');

    $this->addFieldMapping('title', 'LabelTitle');

    $this->addFieldMapping('uid')
      ->defaultValue(1);

    $this->addFieldMapping('field_catalog_number_alpha', 'Catalognumberalpha');
    $this->addFieldMapping('field_accompaniment', 'Accompaniment');
    $this->addFieldMapping('field_matrix_number', 'MatrixNumber');
    $this->addFieldMapping('field_notes', 'Notes');
    $this->addFieldMapping('field_artist_on_label', 'ArtistonLabel');
    $this->addFieldMapping('field_recording_location', 'RecordingLocation');
    $this->addFieldMapping('field_side', 'Side');
    $this->addFieldMapping('field_time', 'Time');
    $this->addFieldMapping('field_track_number', 'TrackNumber');
    $this->addFieldMapping('field_cat_number_sort', 'CatNumberSort');

    /**
     * Dates
     */
    $this->addFieldMapping('field_year_of_copyright', 'Yearofcopyright');

    $this->addFieldMapping('field_recording_date', 'RecordingDate');

    /**
     * Term references.
     */
    $this->addFieldMapping('field_condition', 'Condition_val');
    $this->addFieldMapping('field_condition:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_condition:ignore_case')
      ->defaultValue(TRUE);

    $this->addFieldMapping('field_holding', 'Holding');
    $this->addFieldMapping('field_holding:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_holding:ignore_case')
      ->defaultValue(TRUE);

    $this->addFieldMapping('field_keyword', 'KeyWord')
      ->separator(' ');
    $this->addFieldMapping('field_keyword:create_term')
      ->defaultValue('TRUE');
    $this->addFieldMapping('field_keyword:ignore_case')
      ->defaultValue(TRUE);

    $this->addFieldMapping('field_label_song_type', 'LabelSongType');
    $this->addFieldMapping('field_label_song_type:create_term')
      ->defaultValue('TRUE');
    $this->addFieldMapping('field_label_song_type:ignore_case')
      ->defaultValue(TRUE);

    $this->addFieldMapping('field_recording_format', 'RecordingFormat');
    $this->addFieldMapping('field_recording_format:create_term')
      ->defaultValue('TRUE');
    $this->addFieldMapping('field_recording_format:ignore_case')
      ->defaultValue(TRUE);

    $this->addFieldMapping('field_transfer_equipment', 'TransferEquipt');
    $this->addFieldMapping('field_transfer_equipment:create_term')
      ->defaultValue('TRUE');
    $this->addFieldMapping('field_transfer_equipment:ignore_case')
      ->defaultValue(TRUE);

    $this->addFieldMapping('field_styli', 'Styli');
    $this->addFieldMapping('field_styli:create_term')
      ->defaultValue('TRUE');
    $this->addFieldMapping('field_styli:ignore_case')
      ->defaultValue(TRUE);

    /**
     * Container references.
     */
    $this->addFieldMapping('field_title_of_album', 'TitleofAlbum')
      ->sourceMigration('FronteraAlbums');

    /**
     * Label references.
     */
    $this->addFieldMapping('field_record_label_t', 'RecordLabel')
      ->sourceMigration('FronteraLabels');

    $this->addFieldMapping('field_record_label_t:source_type')
      ->defaultValue('tid');

    /**
     * Name references
     */
    $this->addFieldMapping('field_artist_real_name', 'ArtistsStandardName')
      ->sourceMigration('FronteraArtists');

    // Detailed multiline text field with info about all artists involved
    $this->addFieldMapping('field_artists_real_names', 'ArtistsRealNames');

    $this->addFieldMapping('field_producer', 'Producer')
      ->sourceMigration('FronteraProducers');

    $this->addFieldMapping('field_composer', 'Composer')
      ->sourceMigration('FronteraComposers');

    $this->addFieldMapping('field_publisher', 'Publisher')
      ->sourceMigration('FronteraPublishers');

    $this->addFieldMapping('field_transfer_file_name', 'TransferFileName');

    // Image field
    $this->addFieldMapping('field_images', 'image_url');
    $this->addFieldMapping('field_images:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('field_images:destination_file', 'image_filepath');

    $this->addUnmigratedSources(array(
      'CatNumberSort',
      'CountryofLabel',
      'labelphonenumber',
      'AlbumArtist',
    ));

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

      'field_accompaniment:language',
      'field_artist_on_label:language',
      'field_cat_number_sort:language',
      'field_catalog_number_alpha:language',
      'field_full_recording:language',
      'field_matrix_number:language',
      'field_notes:language',
      'field_recording_location:language',
      'field_sample_recording:language',
      'field_time:language',
      'field_track_number:language',
      'field_transfer_file_name:language',
      'field_artists_real_names:language',

      'field_images:language',
      'field_images:file_class',
      'field_images:preserve_files',
      'field_images:destination_dir',
      'field_images:source_dir',
      'field_images:urlencode',
      'field_images:alt',
      'field_images:title',
      'field_matrix_number_computed',
      'path',
      'comment',

      'field_full_recording',
      'field_full_recording:title',
      'field_full_recording:attributes',

      'field_condition:source_type',
      'field_holding:source_type',
      'field_keyword:source_type',
      'field_label_song_type:source_type',
      'field_recording_format:source_type',
      'field_styli:source_type',
      'field_transfer_equipment:source_type',

      'field_sample_recording',
      'field_sample_recording:title',
      'field_sample_recording:attributes',
    ));
  }

  /**
   * Implements prepareRow().
   *
   * @param $row
   *
   * @return bool
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    if (empty($row->LabelTitle)) {
      return FALSE;
    }

    // Avoid start/end spaces
    $row->LabelTitle = trim($row->LabelTitle);

    if (strtotime($row->RecordingDate) === FALSE) {
      $row->RecordingDate = NULL;
    }

    // Build the complete source image url
    $transfer_name = strtolower($row->TransferFileName);

    // The same image can be used for several tracks in the same recording side
    // In this case the transfer file name has the track number appended
    // We need to remove it because the image file doesn't have this number
    if (isset($row->TrackNumber) && is_numeric($row->TrackNumber)) {
      if (substr($transfer_name, -1) == $row->TrackNumber) {
        $transfer_name = substr($transfer_name, 0, -1);
      }
    }

    // The source of images can either be a filesystem location or a url
    if ($source_dir = variable_get('frontera_migration_recording_image_dir', '')) {
      // If source is in the filesystem, the base url is just the directory path
      // This can be ser using a variable or $conf in settings.php
      $base_url = $source_dir;
    }
    else {
      // The base url can be changed using a variable
      $default_base_url = 'http://bluespark.library.ucla.edu/frontera';
      $base_url = variable_get('frontera_migration_image_base_url', $default_base_url);
    }

    // Images are sorted using the first character as subdir
    $first_char = substr($transfer_name, 0, 1);

    if (is_numeric($first_char)) {
      $first_char = '0-9';
    }
    else {
      $first_char = strtoupper($first_char);
    }

    $filename = $transfer_name .'.jpg';

    // Filepath with dir and filename
    $image_filepath = $first_char .'/'. $filename;

    // Complete source url
    $image_source_url = $base_url . '/'. $image_filepath;

    $row->image_url = $image_source_url;
    $row->image_filepath = $image_filepath;
  }
}
