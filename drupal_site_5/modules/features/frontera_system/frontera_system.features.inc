<?php
/**
 * @file
 * frontera_system.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function frontera_system_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "panels" && $api == "layouts") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
