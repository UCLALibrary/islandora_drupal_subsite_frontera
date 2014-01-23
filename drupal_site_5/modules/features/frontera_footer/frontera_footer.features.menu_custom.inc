<?php
/**
 * @file
 * frontera_footer.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function frontera_footer_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer.
  $menus['menu-footer'] = array(
    'menu_name' => 'menu-footer',
    'title' => 'Footer',
    'description' => 'Footer menu links.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer');
  t('Footer menu links.');


  return $menus;
}
