<?php

$plugin = array(
  'single' => TRUE,
  'title' => t('Frontera: Recording by Artist'),
  'icon' => 'icon_node.png',
  'description' => t('Provides a list of recording performed by artist(s) of actual recording'), // da rivedere il testo
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'category' => t('FRONTERA'),
  'defaults' => array()
);

/**
 * this function get other recordings whose performer/performers is/are the same of the recording actually viewed
 *
 * @param $subtype       -> the name of the plugin
 * @param $conf          -> array with plugin configuration values
 * @param $panel_args    -> panels arguments passed through url
 * @param $context       -> panel's context with their data $context->data
 */
function ct_recording_recording_by_artist_content_type_render($subtype, $conf, $panel_args, $context) {

  if (empty($context) || empty($context->data)) {
    return;
  }

  // Get a shortcut to the node.
  $recording_node = $context->data;

  // watchdog('ct_recording_by_artist', 'il nid del nodo artista e\' @nid', array('@nid' => $recording_node->nid));

  $nids = array();
  foreach($recording_node->field_artist_real_name['und'] as $value){
    $nids[] = $value['target_id'];
  }

  $nids = implode("+", $nids);

  // watchdog('ct_recording_by_artist', 'i nids sono @nid', array('@nid' => $nids));

  $view = views_get_view('recording_by_artist');
  $view->set_arguments(array($nids));

  // this is for avoid error on executing views
  $view->dom_id = !empty($view->dom_id) ? $view->dom_id : md5($view->name . REQUEST_TIME . rand());

  $view->execute();

  // sort recording
  // first  - the recordings with all performer of the node being viewed
  // second - the recordings with less one performer
  // third  - the recordings with less two performer ....
  if(!usort($view->result, 'ct_recording_recording_by_artist_sort')){
    watchdog('ct_recording', 'error in sorting views result', array(), WATCHDOG_WARNING);
  }

  // removes from results the node displayed
  foreach($view->result as $key => $result){
    if( $result->nid == $recording_node->nid ){
      // watchdog('ct_recording', 'remove from \'other recording by artist\' @nid', array('@nid' => $recording_node->nid));
      unset($view->result[$key]);
    }
  }
  unset($key); unset($result);

  // If removing the current node leaves the result set empty, then
  // don't display anything!
  if(!count($view->result)) {
    return;
  }

  $output = $view->render();

  if (isset($recording_node->field_artist_real_name[$recording_node->language])) {

    $performers_links = array();
    foreach ($recording_node->field_artist_real_name[$recording_node->language] as $recording_node) {
      $performer = node_load($recording_node['target_id']);
      $performers_links[] = $performer->title;
    }
    $artists = implode(", ", $performers_links);
  }

  // Build the content type block.
  $block = new stdClass();
  $block->title = "Other Recordings by " . $artists;
  $block->content = $output;

  return $block;
}

/**
 * sort
 *
 * @param $a an item of the views results
 * @param $b an item of the views results
 */
function ct_recording_recording_by_artist_sort($a, $b){
  // $na = count($a->nids);
  $na = count($a->_field_data['nid']['entity']->field_artist_real_name['und']);
  // $nb = count($b->nids);
  $nb = count($b->_field_data['nid']['entity']->field_artist_real_name['und']);

  if($na < $nb) return 1;
  elseif ($na > $nb) return -1;
  else return 0;
}

/**
 * Returns an edit form for custom type settings.
 */
function ct_recording_recording_by_artist_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  return $form;
}
