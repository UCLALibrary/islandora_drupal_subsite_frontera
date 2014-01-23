<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Frontera: Label Image Count'),
  'icon' => 'icon_node.png',
  'description' => t('Provide the number of images available in the Label content type.'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('FRONTERA'),
  'defaults' => array(
  ),
);

function ct_label_label_image_counter_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  // Get a shortcut to the node.
  $label_node = $context->data;

  $gallery_path = isset($conf['config_label_images_path']) ? $conf['config_label_images_path'] : 'gallery';

  $output = '';

  // Load the artist node assuming there is only just one
  if (isset($label_node->field_images[$label_node->language])) {
    // Create the appropriate string based on the number of images
    $images_number = count($label_node->field_images[$label_node->language]);
    $link = url('node/' . $label_node->nid, array('absolute' => TRUE)) . '/' . $gallery_path;

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
function ct_label_label_image_counter_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['config_label_images_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Gallery path'),
    '#size' => 50,
    '#description' => t('Configure the gallery\'s path of the Label.'),
    '#default_value' => $conf['config_label_images_path'],
    '#prefix' => '<div class="clear-block no-float">',
    '#suffix' => '</div>',
  );

  return $form;
}