<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * Frontera Omega theme.
 */

/**
 * Implements theme_tablesort_indicator().
 */
function frontera_omega_tablesort_indicator($variables) {
  $path = drupal_get_path('theme', 'frontera_omega');
  if ($variables['style'] == "asc") {
    return theme('image', array('path' => $path . '/images/sort-asc.png', 'width' => 13, 'height' => 6, 'alt' => t('sort ascending'), 'title' => t('sort ascending')));
  }
  else {
    return theme('image', array('path' => $path . '/images/sort-desc.png', 'width' => 13, 'height' => 6, 'alt' => t('sort descending'), 'title' => t('sort descending')));
  }
}

/**
 * Implements hook_preprocess_print().
 * See: https://drupal.org/node/565856#comment-7615625
 */
/*function frontera_omega_preprocess_print(&$variables) {
  $panels_node_type = array(
    'name',
    'recording'
  );

  // Check type node type
  if (isset($variables['node']) && in_array($variables['node']->type, $panels_node_type)) {
    $node = $variables['node'];
    // Load the panels node view task plugin.
    $task = page_manager_get_task('node_view');

    // Load the node into a context.
    ctools_include('context');
    ctools_include('context-task-handler');
    $contexts = ctools_context_handler_get_task_contexts($task, '', array($node));

    // Attempt to render the node with its contexts using CTools.
    $output = ctools_context_handler_render($task, '', $contexts, array($node->nid));
    if ($output !== FALSE) {
      kpr($output['content']);
      if (user_access('administer site configuration')) {
        $variables['print']['content'] = drupal_render($output['content']);
      }
      else {
        $variables['print']['content'] = $output;
      }
    }
  }
}*/

/**
 * Another solution is to use this function and add a templates/print--node--node-type.tpl file
 * See: https://drupal.org/node/565856#comment-5403068
 */
function frontera_get_panel_view(&$node) {
    // Load the panels node view task plugin.
    $task = page_manager_get_task('node_view');

    // Load the node into a context.
    ctools_include('context');
    ctools_include('context-task-handler');
    $contexts = ctools_context_handler_get_task_contexts($task, '', array($node));
   
    // Attempt to render the node with its contexts using CTools.
    $output = ctools_context_handler_render($task, '', $contexts, array($node->nid));
    if ($output !== FALSE) {
      if (user_access('administer site configuration')) {
        return drupal_render($output['content']);
      }
      else{
        return $output;
      }
    }
    // Otherwise, fall back.
    return drupal_render(node_view(node_load($node->nid)));
}

/**
 * https://drupal.org/node/1678810
 */
/*function frontera_omega_preprocess_panels_pane(&$variables) {
  $path = explode('/', $_SERVER["REQUEST_URI"]);
  $hide_panels = array(
    'artist_tab_recordings',
    'artist_tab_composed',
//    'image_gallery_name-panel_pane_1',
    'artist_tab_images',
    'node_comment_form',
    'container-panel_pane_1',
    'name_images-panel_pane_2'
  );

  if ($path[1] == "print") {
    // We are on a print page
    
    if (in_array($variables['pane']->subtype, $hide_panels)) {
      $variables['content'] = '';
    }
    else {
      // kpr ($variables);
    }
  }
}*/

