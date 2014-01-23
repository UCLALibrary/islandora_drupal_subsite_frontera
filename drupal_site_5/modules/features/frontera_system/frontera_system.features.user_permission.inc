<?php
/**
 * @file
 * frontera_system.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function frontera_system_user_default_permissions() {
  $permissions = array();

  // Exported permission: access bean overview.
  $permissions['access bean overview'] = array(
    'name' => 'access bean overview',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'bean',
  );

  // Exported permission: administer bean settings.
  $permissions['administer bean settings'] = array(
    'name' => 'administer bean settings',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: administer bean types.
  $permissions['administer bean types'] = array(
    'name' => 'administer bean types',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'bean',
  );

  // Exported permission: administer beans.
  $permissions['administer beans'] = array(
    'name' => 'administer beans',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'bean',
  );

  // Exported permission: edit bean view mode.
  $permissions['edit bean view mode'] = array(
    'name' => 'edit bean view mode',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: view bean page.
  $permissions['view bean page'] = array(
    'name' => 'view bean page',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'bean',
  );

  // Exported permission: view bean revisions.
  $permissions['view bean revisions'] = array(
    'name' => 'view bean revisions',
    'roles' => array(),
    'module' => 'bean',
  );

  return $permissions;
}
