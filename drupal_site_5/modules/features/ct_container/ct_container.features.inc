<?php
/**
 * @file
 * ct_container.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_container_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ct_container_node_info() {
  $items = array(
    'container' => array(
      'name' => t('Container'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
