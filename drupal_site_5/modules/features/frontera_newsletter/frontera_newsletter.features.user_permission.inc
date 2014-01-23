<?php
/**
 * @file
 * frontera_newsletter.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function frontera_newsletter_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer newsletters.
  $permissions['administer newsletters'] = array(
    'name' => 'administer newsletters',
    'roles' => array(
      'newsletters manager' => 'newsletters manager',
    ),
    'module' => 'simplenews',
  );

  // Exported permission: administer simplenews settings.
  $permissions['administer simplenews settings'] = array(
    'name' => 'administer simplenews settings',
    'roles' => array(
      'newsletters manager' => 'newsletters manager',
    ),
    'module' => 'simplenews',
  );

  // Exported permission: administer simplenews subscriptions.
  $permissions['administer simplenews subscriptions'] = array(
    'name' => 'administer simplenews subscriptions',
    'roles' => array(
      'newsletters manager' => 'newsletters manager',
    ),
    'module' => 'simplenews',
  );

  // Exported permission: send newsletter.
  $permissions['send newsletter'] = array(
    'name' => 'send newsletter',
    'roles' => array(
      'newsletters manager' => 'newsletters manager',
    ),
    'module' => 'simplenews',
  );

  // Exported permission: subscribe to newsletters.
  $permissions['subscribe to newsletters'] = array(
    'name' => 'subscribe to newsletters',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'newsletters manager' => 'newsletters manager',
    ),
    'module' => 'simplenews',
  );

  return $permissions;
}
