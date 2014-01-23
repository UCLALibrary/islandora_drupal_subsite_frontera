<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Frontera: Image Count'),
  'icon' => 'icon_node.png',
  'description' => t('Provide the number of images available'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('FRONTERA'),
  'defaults' => array(
  ),
);

function ct_recording_image_counter_content_type_render($subtype, $conf, $panel_args, $context) {

  if (empty($context) || empty($context->data)) {
    return;
  }

  // Get a shortcut to the node.
  $recording_node = $context->data;

  $output = '';

  // Load the artist node assuming there is only just one
  if (isset($recording_node->field_artist_real_name[$recording_node->language]) && (count
      ($recording_node->field_artist_real_name[$recording_node->language]) == 1)) {
    $artist_node = node_load($recording_node->field_artist_real_name[$recording_node->language][0]['target_id']);
    // Need to check the image field is set and the count on that
    if (isset($artist_node->field_images[$artist_node->language])) {
      // Create the appropriate string based on the number of images
      $images_number = count($artist_node->field_images[$artist_node->language]);
      if ($images_number > 1) {
        $output .= '<a  href="#">See all ' . $images_number . ' images&#62;</a>';
      } elseif ($images_number == 1) {
        $output .= '';
      }
      else {
        $output .= '';
      }
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
function ct_recording_image_counter_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  return $form;
}