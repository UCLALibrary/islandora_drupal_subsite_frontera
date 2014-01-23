<?php
/**
 * @file
 * frontera_catalog_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function frontera_catalog_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontera_catalog_search_artist';
  $context->description = '';
  $context->tag = 'search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'frontera_catalog_search_artists' => 'frontera_catalog_search_artists',
        'frontera_catalog_search_artists:frontera_catalog_search_artists_page' => 'frontera_catalog_search_artists:frontera_catalog_search_artists_page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-6fd42f56a7cacd2f962d1814d78bf874' => array(
          'module' => 'views',
          'delta' => '6fd42f56a7cacd2f962d1814d78bf874',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('search');
  $export['frontera_catalog_search_artist'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontera_catalog_search_labels';
  $context->description = '';
  $context->tag = 'search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'frontera_catalog_search_labels' => 'frontera_catalog_search_labels',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-31766feb924ec3fbee368329c2fe6328' => array(
          'module' => 'views',
          'delta' => '31766feb924ec3fbee368329c2fe6328',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('search');
  $export['frontera_catalog_search_labels'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'frontera_catalog_search_songs';
  $context->description = '';
  $context->tag = 'search';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'frontera_catalog_search_song' => 'frontera_catalog_search_song',
        'frontera_catalog_search_song:frontera_catalog_search_song_page' => 'frontera_catalog_search_song:frontera_catalog_search_song_page',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-eeb3e681be32f3d3f959ddc316bed3c1' => array(
          'module' => 'views',
          'delta' => 'eeb3e681be32f3d3f959ddc316bed3c1',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'frontera_jump_to_rec-jtr_block' => array(
          'module' => 'frontera_jump_to_rec',
          'delta' => 'jtr_block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('search');
  $export['frontera_catalog_search_songs'] = $context;

  return $export;
}
