<?php

/**
 * @file
 * Provides a social links pane.
 */

$plugin = array(
  'title' => t('Social Links Pane'),
  'description' => t('Provide the home page social links pane.'),
  'single' => TRUE,
  'render callback' => 'frontera_home_page_social_pane_pane_render',
  'defaults' => array(),
  'category' => t('Frontera'),
  'edit form' => 'frontera_home_page_social_pane_pane_edit_form',
  'defaults' => array(
    'facebook_id' => '',
    'twitter_id' => '',
    'googleplus_id' => '',
    'simplenews_tid' => '',
  )
);

/**
 * Run-time rendering of the body of the block.
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time.
 * @param $args
 * @param $context
 *   Context - in this case we don't have any.
 *
 * @return
 *   An object with at least title and content.
 */
function frontera_home_page_social_pane_pane_render($subtype, $conf, $args, $context) {
  // Generate simplenews subscription form
  module_load_include('inc', 'simplenews', 'includes/simplenews.subscription');
  $subscription_form = drupal_get_form('simplenews_block_form_' . $conf['simplenews_tid']);
  $subscription_form = render($subscription_form);
  $block = new stdClass();
  $block->title = '';
  $block->content = "
    <h3>Connect</h3>
    <p>Stay on top of the lastest news</p>
    {$subscription_form}
    <ul>
      <li class='first'>
        <a href='https://www.facebook.com/{$conf['facebook_id']}' tile='Frontera on Facebook'>
          <i class='icon-facebook'><span>Facebook</span></i>
        </a>
      </li>
      <li>
        <a href='http://twitter.com/{$conf['twitter_id']}' title='Follow Frontera on Twitter' class=''>
          <i class='icon-twitter'><span>Twitter</span></i>
        </a>
      </li>
      <li class='last'>
        <a href='https://plus.google.com/{$conf['googleplus_id']}' title='Frontera on Google+' class=''>
          <i class='icon-googleplus'><span>Google+</span></i>
        </a>
      </li>
    </ul>
  ";
  return $block;
}

/**
 * 'Edit form' callback.
 */
function frontera_home_page_social_pane_pane_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['facebook_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook Username'),
    '#default_value' => $conf['facebook_id'],
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['twitter_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Username'),
    '#default_value' => $conf['twitter_id'],
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['googleplus_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Plus Username'),
    '#default_value' => $conf['googleplus_id'],
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['simplenews_tid'] = array(
    '#type' => 'textfield',
    '#title' => t('Simple News tid, used to identify to which list the user is subscribed.'),
    '#default_value' => $conf['simplenews_tid'],
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );


  return $form;
}

/**
 * Submit callback.
 */
function frontera_home_page_social_pane_pane_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
