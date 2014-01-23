<?php
/**
 * @file
 * ct_name.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ct_name_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panels" && $api == "layouts") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ct_name_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ct_name_node_info() {
  $items = array(
    'name' => array(
      'name' => t('Name'),
      'base' => 'node_content',
      'description' => t('An artist/producer/composer Content Type.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
