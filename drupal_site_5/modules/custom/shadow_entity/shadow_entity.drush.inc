<?php

/**
 * @file
 * Description of the file goes here.
 */

/**
 * @return mixed
 */
function shadow_entity_drush_command() {
  $items['shadow-full'] = array(
    'description' => t('Ensure all entities for all configs are shadowed.'),
  );

  return $items;
}

/**
 * Callback for the full shadow command.
 */
function drush_shadow_entity_shadow_full() {
  shadow_entity_ensure_full_config();
}
