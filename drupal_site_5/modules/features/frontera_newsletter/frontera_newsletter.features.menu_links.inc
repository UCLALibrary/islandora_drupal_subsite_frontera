<?php
/**
 * @file
 * frontera_newsletter.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function frontera_newsletter_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-news-letters-management:admin/config/services/simplenews
  $menu_links['menu-news-letters-management:admin/config/services/simplenews'] = array(
    'menu_name' => 'menu-news-letters-management',
    'link_path' => 'admin/config/services/simplenews',
    'router_path' => 'admin/config/services/simplenews',
    'link_title' => 'Simplenews',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-news-letters-management:admin/content/simplenews
  $menu_links['menu-news-letters-management:admin/content/simplenews'] = array(
    'menu_name' => 'menu-news-letters-management',
    'link_path' => 'admin/content/simplenews',
    'router_path' => 'admin/content/simplenews',
    'link_title' => 'Newsletters Content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: menu-news-letters-management:admin/people/simplenews
  $menu_links['menu-news-letters-management:admin/people/simplenews'] = array(
    'menu_name' => 'menu-news-letters-management',
    'link_path' => 'admin/people/simplenews',
    'router_path' => 'admin/people/simplenews',
    'link_title' => 'Newsletters Subscription',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Newsletters Content');
  t('Newsletters Subscription');
  t('Simplenews');


  return $menu_links;
}
