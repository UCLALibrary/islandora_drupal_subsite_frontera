<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Frontera: List of Performers'),
  'icon' => 'icon_node.png',
  'description' => t('Provide a list of Performers'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('FRONTERA'),
  'defaults' => array(
  ),
);

function ct_recording_performers_list_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  // Get a shortcut to the node.
  $recording_nodes = $context->data;

  $output = '';

  // Load the performer nodes
  if (isset($recording_nodes->field_artist_real_name[$recording_nodes->language])) {
    $output .= t('by') . ' ';

    $performers_links = array();
    foreach ($recording_nodes->field_artist_real_name[$recording_nodes->language] as $recording_node) {
      $performer = node_load($recording_node['target_id']);
      $performers_links[] = l($performer->title, 'node/' . $performer->nid);
    }
    $output.= implode(", ", $performers_links);
  }

  // Build the content type block.
  $block = new stdClass();
  $block->content = $output;

  return $block;
}

/**
 * Returns an edit form for custom type settings.
 */
function ct_recording_performers_list_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  return $form;
}
