<?php

/**
 * Implements hook_preprocess_html().
 */
function frontera_omega_preprocess_html(&$variables) {
  // Load the fallback.css for Internet Explorer 8 and lower.
  $path = drupal_get_path('theme', 'frontera_omega');
  drupal_add_css("$path/css/frontera_omega.fallback.css", array(
    'browsers' => array(
      '!IE' => FALSE,
      'IE' => 'lte IE 8',
    ),
    'group' => CSS_THEME,
    'weight' => 1000,
  ));

  // Support font stack with Typekit fonts.
  drupal_add_js('//use.typekit.net/tus0ykb.js', 'external');
  drupal_add_js('try{Typekit.load();}catch(e){}', 'inline');
}
