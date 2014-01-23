<?php
/**
 * @file
 * frontera_sharethis.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function frontera_sharethis_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer sharethis.
  $permissions['administer sharethis'] = array(
    'name' => 'administer sharethis',
    'roles' => array(),
    'module' => 'sharethis',
  );

  return $permissions;
}
