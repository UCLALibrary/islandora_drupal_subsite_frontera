<?php

/**
 * @file
 *
 */

/**
 * Implements hook_migrate_api().
 *
 * @return array
 */
function frontera_migration_migrate_api() {
  $api = array(
    'api' => 2,

    'groups' => array(
      'frontera_csv_import' => array(
        'title' => 'Frontera CSV Import ',
      ),

      'frontera_recordings' => array(
        'title' => 'Frontera Recordings',
      ),

      'frontera_entities' => array(
        'title' => 'Frontera Artists, Labels, etc..'
      ),
    ),

    'migrations' => array(
      'FronteraPrepare' => array(
        'class_name' => 'FronteraPrepare',
        'group_name' => 'frontera_csv_import',
      ),
      'FronteraHistories' => array(
        'class_name' => 'FronteraHistories',
        'group_name' => 'frontera_csv_import',
      ),

      'FronteraRecordings' => array(
        'class_name' => 'FronteraRecordings',
        'group_name' => 'frontera_recordings',
        'dependencies' => array(
          'FronteraPrepare',
        ),
      ),

      'FronteraArtists' => array(
        'class_name' => 'FronteraNames',
        'group_name' => 'frontera_entities',
        'dependencies' => array('FronteraPrepare'),
        'soft_dependencies' => array('FronteraRecordings'),
        'field_name' => 'ArtistsStandardName',
      ),

      'FronteraComposers' => array(
        'class_name' => 'FronteraNames',
        'group_name' => 'frontera_entities',
        'dependencies' => array('FronteraPrepare'),
        'soft_dependencies' => array('FronteraRecordings'),
        'field_name' => 'Composer',
      ),

      'FronteraProducers' => array(
        'class_name' => 'FronteraNames',
        'group_name' => 'frontera_entities',
        'dependencies' => array('FronteraPrepare'),
        'soft_dependencies' => array('FronteraRecordings'),
        'field_name' => 'Producer',
      ),

      'FronteraPublishers' => array(
        'class_name' => 'FronteraNames',
        'group_name' => 'frontera_entities',
        'dependencies' => array('FronteraPrepare'),
        'soft_dependencies' => array('FronteraRecordings'),
        'field_name' => 'Publisher',
      ),

      'FronteraLabels' => array(
        'class_name' => 'FronteraLabels',
        'group_name' => 'frontera_entities',
        'dependencies' => array('FronteraPrepare'),
        'soft_dependencies' => array('FronteraRecordings'),
      ),

      'FronteraAlbums' => array(
        'class_name' => 'FronteraAlbums',
        'group_name' => 'frontera_entities',
        'dependencies' => array('FronteraPrepare'),
        'soft_dependencies' => array('FronteraRecordings'),
      ),
    ),

    // This is necessary due to date module not having been upgraded to
    // migrate api 2. https://drupal.org/node/1832544
    'field handlers' => array(
      'DateMigrateFieldHandler',
    ),

  );

  return $api;
}
