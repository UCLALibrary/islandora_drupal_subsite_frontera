<?php
/**
 * @file
 * ct_label.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ct_label_taxonomy_default_vocabularies() {
  return array(
    'label' => array(
      'name' => 'Label',
      'machine_name' => 'label',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
