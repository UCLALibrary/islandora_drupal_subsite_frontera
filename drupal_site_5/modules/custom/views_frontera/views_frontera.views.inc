<?php
/**
 * @file
 * Views-specific implementations and functions.
 */

/**
 * Implements hook_views_plugins().
 */
function views_frontera_views_plugins() {
  return array(
    'query' => array(
      'efq_query' => array(
        'title' => t('EntityFieldQuery Frontera'),
        'help' => t('Uses Frontera EntityFieldQuery for querying entities and fields.'),
        'handler' => 'views_frontera_plugin_query',
      ),
    ),
//    'style' => array(
//      'frontera_grid' => array(
//        'title' => t('Frontera grid'),
//        'help' => t('Display content in using the Frontera grid.'),
//        'handler' => 'views_frontera_plugin_style',
//        'theme' => 'views_view_frontera',
//        'uses row plugin' => TRUE,
//        'uses row class' => FALSE,
//        'uses options' => TRUE,
//        'uses grouping' => TRUE,
//        'type' => 'normal',
//      ),
//    ),
  );
}

/**
 * Implements hook_views_handlers().
 */
function views_frontera_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'views'),
    ),
    'handlers' => array(
      'views_frontera_handler_sort' => array(
        // must be the same used by our handler as parent class
        'parent' => 'views_handler_sort',
      ),
    ),
  );
}

/**
 * Implements hook_views_data().
 */
function views_frontera_views_data() {
  $data['frontera']['table']['group'] = t('Frontera');
  $data['frontera']['table']['join'] = array(
    '#global' => array(),
  );

  // Define our sort method
  $data['frontera']['frontera_sort'] = array(
    'title' => t('Frontera'),
    'help' => t('Frontera display order.'),
    'sort' => array(
      'handler' => 'views_frontera_handler_sort',
    ),
  );

  $data['frontera']['frontera_glossary'] = array(
    'title' => t('Glossary'),
    'help' => t('Provide a full Glossary.'),
    'area' => array(
      'handler' => 'views_handler_area_glossary',
    ),
  );

  $data['frontera']['frontera_string_link'] = array(
    'title' => t('String with link'),
    'help' => t('Provide a custom string with a custom link.'),
    'area' => array(
      'handler' => 'views_handler_area_string_link',
    ),
  );

  $data['frontera']['frontera_no_results'] = array(
    'title' => t('Alert Message'),
    'help' => t('Show a configurable alert message.'),
    'area' => array(
      'handler' => 'views_handler_area_no_results',
    ),
  );

  return $data;
}