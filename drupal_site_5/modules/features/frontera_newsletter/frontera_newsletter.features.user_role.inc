<?php
/**
 * @file
 * frontera_newsletter.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function frontera_newsletter_user_default_roles() {
  $roles = array();

  // Exported role: newsletters manager.
  $roles['newsletters manager'] = array(
    'name' => 'newsletters manager',
    'weight' => 2,
  );

  return $roles;
}
