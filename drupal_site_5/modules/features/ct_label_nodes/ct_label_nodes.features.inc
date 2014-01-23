<?php
/**
 * @file
 * ct_label_nodes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_label_nodes_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ct_label_nodes_node_info() {
  $items = array(
    'label' => array(
      'name' => t('Label'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
