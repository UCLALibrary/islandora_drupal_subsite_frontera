<?php
/**
 * @file
 * frontera_footer.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function frontera_footer_user_default_permissions() {
  $permissions = array();

  // Exported permission: create any footer bean.
  $permissions['create any footer bean'] = array(
    'name' => 'create any footer bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: delete any footer bean.
  $permissions['delete any footer bean'] = array(
    'name' => 'delete any footer bean',
    'roles' => array(),
    'module' => 'bean',
  );

  // Exported permission: edit any footer bean.
  $permissions['edit any footer bean'] = array(
    'name' => 'edit any footer bean',
    'roles' => array(
      'content editor' => 'content editor',
    ),
    'module' => 'bean',
  );

  // Exported permission: view any footer bean.
  $permissions['view any footer bean'] = array(
    'name' => 'view any footer bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
