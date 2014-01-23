<?php
/**
 * @file
 * frontera_basic_search.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function frontera_basic_search_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:search
  $menu_links['main-menu:search'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Search',
    'options' => array(),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Search');


  return $menu_links;
}
