<?php
/**
 * @file
 * frontera_promotional_block.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function frontera_promotional_block_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function frontera_promotional_block_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function frontera_promotional_block_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: promotional_block
  $nodequeues['promotional_block'] = array(
    'name' => 'promotional_block',
    'title' => 'Promotional Block',
    'subqueue_title' => '',
    'size' => 0,
    'link' => 'add to queue "Promotional Block"',
    'link_remove' => 'remove from queue "Promotional Block"',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 0,
    'i18n' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'promotional',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function frontera_promotional_block_image_default_styles() {
  $styles = array();

  // Exported image style: promo_block_124x94.
  $styles['promo_block_124x94'] = array(
    'name' => 'promo_block_124x94',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 124,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 94,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function frontera_promotional_block_node_info() {
  $items = array(
    'promotional' => array(
      'name' => t('Promotional'),
      'base' => 'node_content',
      'description' => t('Promotional content used to have an advertisement block in the site front page'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
