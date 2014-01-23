<?php
/**
 * @file
 * frontera_taxonomies.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function frontera_taxonomies_taxonomy_default_vocabularies() {
  return array(
    'condition_types' => array(
      'name' => 'Condition Types',
      'machine_name' => 'condition_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'country' => array(
      'name' => 'Country',
      'machine_name' => 'country',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'formats' => array(
      'name' => 'Formats',
      'machine_name' => 'formats',
      'description' => 'The Recording Format',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'holding' => array(
      'name' => 'Holding',
      'machine_name' => 'holding',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'keywords' => array(
      'name' => 'Keywords',
      'machine_name' => 'keywords',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'label_song_type' => array(
      'name' => 'Label Song Type',
      'machine_name' => 'label_song_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'styli' => array(
      'name' => 'Styli',
      'machine_name' => 'styli',
      'description' => 'a phonograph or gramophone needle used to play back sound on gramophone records',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'transfer_equipment' => array(
      'name' => 'Transfer Equipment',
      'machine_name' => 'transfer_equipment',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
