<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Frontera: Name Image Count'),
  'icon' => 'icon_node.png',
  'description' => t('Provide the number of images available in the Name content type.'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('FRONTERA'),
  'defaults' => array(
  ),
);

function ct_name_name_image_counter_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  // Get a shortcut to the node.
  $name_node = $context->data;

  $gallery_path = isset($conf['config_name_images_path']) ? $conf['config_name_images_path'] : 'gallery';

  $output = '';

  // Load the artist node assuming there is only just one
  if (isset($name_node->field_images[$name_node->language])) {
    // Create the appropriate string based on the number of images
    $images_number = count($name_node->field_images[$name_node->language]);
    $link = url('node/' . $name_node->nid, array('absolute' => TRUE)) . '/' . $gallery_path;

    if ($images_number > 1) {
      $output .= '<a  href="'. $link .'">See all ' . $images_number . ' images&#62;</a>';
    }
    else {
      $output .= '';
    }
  }

  // Build the content type block.
  $block = new stdClass();
  $block->content = $output;

  return $block;
}

/**
 * Returns an edit form for custom type settings.
 */
function ct_name_name_image_counter_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['config_name_images_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Gallery path'),
    '#size' => 50,
    '#description' => t('Configure the gallery\'s path of the Name.'),
    '#default_value' => $conf['config_name_images_path'],
    '#prefix' => '<div class="clear-block no-float">',
    '#suffix' => '</div>',
  );

  return $form;
}