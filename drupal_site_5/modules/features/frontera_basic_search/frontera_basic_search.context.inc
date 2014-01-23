<?php
/**
 * @file
 * frontera_basic_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function frontera_basic_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontera_basic_search';
  $context->description = 'Frontera basic search page context';
  $context->tag = 'search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'frontera_basic_search' => 'frontera_basic_search',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'facetapi-DNku5GtUK0s7Hj0Fxj4jRr04MB0YH6t6' => array(
          'module' => 'facetapi',
          'delta' => 'DNku5GtUK0s7Hj0Fxj4jRr04MB0YH6t6',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'facetapi-1KGjSMXrENEpmuNAUfum5P6oUVvUcEBZ' => array(
          'module' => 'facetapi',
          'delta' => '1KGjSMXrENEpmuNAUfum5P6oUVvUcEBZ',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'facetapi-qUJcsPfcCnA6KmaOO60SC0hUHsrNrmzI' => array(
          'module' => 'facetapi',
          'delta' => 'qUJcsPfcCnA6KmaOO60SC0hUHsrNrmzI',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'facetapi-fVwNdIufpeSln8NBHyg0sZc0PmnAYC11' => array(
          'module' => 'facetapi',
          'delta' => 'fVwNdIufpeSln8NBHyg0sZc0PmnAYC11',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'frontera_jump_to_rec-jtr_block' => array(
          'module' => 'frontera_jump_to_rec',
          'delta' => 'jtr_block',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Frontera basic search page context');
  t('search');
  $export['frontera_basic_search'] = $context;

  return $export;
}
