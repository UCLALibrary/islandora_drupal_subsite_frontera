<?php
/**
 * @file
 * frontera_newsletter.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function frontera_newsletter_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-news-letters-management.
  $menus['menu-news-letters-management'] = array(
    'menu_name' => 'menu-news-letters-management',
    'title' => 'Newsletters Management',
    'description' => 'Menù with links to management pages of the News Letters',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Menù with links to management pages of the News Letters');
  t('Newsletters Management');


  return $menus;
}
