<?php
/**
 * @file
 * frontera_footer.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function frontera_footer_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer:node/1831
  $menu_links['menu-footer:node/1831'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/1831',
    'router_path' => 'node/%',
    'link_title' => 'The Project',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: menu-footer:node/1832
  $menu_links['menu-footer:node/1832'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/1832',
    'router_path' => 'node/%',
    'link_title' => 'The Collection',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
  );
  // Exported menu link: menu-footer:node/1833
  $menu_links['menu-footer:node/1833'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/1833',
    'router_path' => 'node/%',
    'link_title' => 'Sponsors',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
  );
  // Exported menu link: menu-footer:node/1834
  $menu_links['menu-footer:node/1834'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/1834',
    'router_path' => 'node/%',
    'link_title' => 'Copyright and Takedown',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
  );
  // Exported menu link: menu-footer:node/1835
  $menu_links['menu-footer:node/1835'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'node/1835',
    'router_path' => 'node/%',
    'link_title' => 'Copyright and Access',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Copyright and Access');
  t('Copyright and Takedown');
  t('Sponsors');
  t('The Collection');
  t('The Project');


  return $menu_links;
}
