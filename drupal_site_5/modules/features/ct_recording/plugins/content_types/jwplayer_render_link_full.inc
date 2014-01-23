<?php
$plugin = array(
	'single' => TRUE,
	'title' => t('Frontera: Play the Full Recording'),
	'icon' => 'icon_node.png',
	'description' => t('Provides a player to listen the Full Recording'),
	'required context' => new ctools_context_required(t('Node'), 'node'),
	'category' => t('FRONTERA'),
	'defaults' => array(
	),
);

/**
 * Renders a block that contains two players, one for the full audio recording and
 * another one for the sample.
 */
function ct_recording_jwplayer_render_link_full_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  // Get a shortcut to the node.
  $node = $context->data;

  $output = ct_recording_get_player_output($node, 'full');

  // Build the content type block.
  $block = new stdClass();
  $block->content = $output;

  return $block;
}

/**
 * Returns an edit form for custom type settings.
 */
function ct_recording_jwplayer_render_link_full_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  
  return $form;
}