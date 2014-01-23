<?php
/**
 * @file
 * ct_container.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function ct_container_field_default_field_instances() {
  $field_instances = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Recording');

  return $field_instances;
}
