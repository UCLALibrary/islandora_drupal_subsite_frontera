<?php
/**
 * @file
 * frontera_sharethis.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function frontera_sharethis_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['sharethis-sharethis_block'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'sharethis_block',
    'module' => 'sharethis',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'ember' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'ember',
        'weight' => 0,
      ),
      'frontera_omega' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'frontera_omega',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
