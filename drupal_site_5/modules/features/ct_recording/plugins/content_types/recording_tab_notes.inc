<?php
$plugin = array(
  'single' => TRUE,
  'title' => t('Frontera: Tabs Notes'),
  'icon' => 'icon_node.png',
  'description' => t('Provides a mini panel implementing tab Notes used to visualize content'),
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('FRONTERA'),
  'defaults' => array()
);

/**
 * Function that implement panels (ctools) plugin - in this case to show the content of the node visualized 
 *  
 * @param $subtype       -> the name of the plugin
 * @param $conf          -> array with plugin configuration values
 * @param $panel_args    -> panels arguments passed through url
 * @param $context       -> panel's context with their data $context->data
 * @return void|stdClass ->
 */
function ct_recording_recording_tab_notes_content_type_render($subtype, $conf, $panel_args, $context) {

  if (empty($context) || empty($context->data)) {
    return;
  }

  // Get a shortcut to the node.
  $recording_node = $context->data;
  $output = "";

  // which behaviour have to follow the plugin if the field_notes is empty?

  if (isset($recording_node->field_notes['und'][0]['safe_value']) && !empty($recording_node->field_notes['und'][0]['safe_value'])){
    $output = check_markup($recording_node->field_notes['und'][0]['safe_value'], 'plain_text');
  }

  // Build the content type block.
  $block = new stdClass();
  $block->title = "Staff Notes";
  $block->content = $output;
  
  return $block;
}