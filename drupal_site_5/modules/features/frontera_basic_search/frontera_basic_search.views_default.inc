<?php
/**
 * @file
 * frontera_basic_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function frontera_basic_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'frontera_basic_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_frontera_basic_index';
  $view->human_name = 'Frontera_basic_search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search Frontera';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_entity'] = 1;
  /* Field: Indexed Node: Content type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['type']['format_name'] = 1;
  /* Field: Search: Excerpt */
  $handler->display->display_options['fields']['search_api_excerpt']['id'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['search_api_excerpt']['field'] = 'search_api_excerpt';
  $handler->display->display_options['fields']['search_api_excerpt']['label'] = '';
  $handler->display->display_options['fields']['search_api_excerpt']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['search_api_excerpt']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['search_api_excerpt']['link_to_entity'] = 0;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 's';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'field_alternative_names' => 'field_alternative_names',
    'field_biography' => 'field_biography',
    'field_accompaniment' => 'field_accompaniment',
    'field_artist_on_label' => 'field_artist_on_label',
    'field_cat_number_sort' => 'field_cat_number_sort',
    'field_catalog_number_alpha' => 'field_catalog_number_alpha',
    'field_matrix_number' => 'field_matrix_number',
    'field_matrix_number_computed' => 'field_matrix_number_computed',
    'field_notes' => 'field_notes',
    'field_recording_location' => 'field_recording_location',
    'field_time' => 'field_time',
    'field_recording_album_fulltext' => 'field_recording_album_fulltext',
    'field_recording_artist_name_fulltext' => 'field_recording_artist_name_fulltext',
    'field_recording_label_fulltext' => 'field_recording_label_fulltext',
    'field_recording_title_fulltext' => 'field_recording_title_fulltext',
    'field_recording_artist_name_string' => 'field_recording_artist_name_string',
    'field_artist_song_titles' => 'field_artist_song_titles',
    'field_artist_artist_name' => 'field_artist_artist_name',
    'field_artist_real_name:title' => 'field_artist_real_name:title',
    'field_artist_real_name:field_alternative_names' => 'field_artist_real_name:field_alternative_names',
    'field_artist_real_name:field_biography' => 'field_artist_real_name:field_biography',
    'field_keyword:name' => 'field_keyword:name',
    'field_keyword:description' => 'field_keyword:description',
    'field_record_label_t:name' => 'field_record_label_t:name',
    'field_record_label_t:description' => 'field_record_label_t:description',
    'field_styli:name' => 'field_styli:name',
    'field_styli:description' => 'field_styli:description',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');

  /* Display: Context */
  $handler = $view->new_display('ctools_context', 'Context', 'frontera_basic_search_context');
  $handler->display->display_options['style_plugin'] = 'ctools_context';
  $handler->display->display_options['row_plugin'] = 'fields';
  $export['frontera_basic_search'] = $view;

  $view = new view();
  $view->name = 'search_solr';
  $view->description = 'Global site search using searchapi with solr engine.';
  $view->tag = 'default';
  $view->base_table = 'search_api_multi_frontera_solr_server';
  $view->human_name = 'Search Solr';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Frontera: Alert Message */
  $handler->display->display_options['empty']['frontera_no_results']['id'] = 'frontera_no_results';
  $handler->display->display_options['empty']['frontera_no_results']['table'] = 'frontera';
  $handler->display->display_options['empty']['frontera_no_results']['field'] = 'frontera_no_results';
  $handler->display->display_options['empty']['frontera_no_results']['empty'] = TRUE;
  $handler->display->display_options['empty']['frontera_no_results']['alert_message'] = '<@searchedterm> returned no results, please try another term.';
  $handler->display->display_options['empty']['frontera_no_results']['message_type'] = 'drupal_alert';
  /* Field: Frontera basic index: Title (indexed) */
  $handler->display->display_options['fields']['frontera_basic_index_title']['id'] = 'frontera_basic_index_title';
  $handler->display->display_options['fields']['frontera_basic_index_title']['table'] = 'search_api_multi_frontera_solr_server';
  $handler->display->display_options['fields']['frontera_basic_index_title']['field'] = 'frontera_basic_index_title';
  $handler->display->display_options['fields']['frontera_basic_index_title']['label'] = '';
  $handler->display->display_options['fields']['frontera_basic_index_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['frontera_basic_index_title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['frontera_basic_index_title']['link_to_entity'] = 1;
  /* Field: Frontera Taxonomy Index: Name (indexed) */
  $handler->display->display_options['fields']['frontera_taxonomy_index_name']['id'] = 'frontera_taxonomy_index_name';
  $handler->display->display_options['fields']['frontera_taxonomy_index_name']['table'] = 'search_api_multi_frontera_solr_server';
  $handler->display->display_options['fields']['frontera_taxonomy_index_name']['field'] = 'frontera_taxonomy_index_name';
  $handler->display->display_options['fields']['frontera_taxonomy_index_name']['label'] = '';
  $handler->display->display_options['fields']['frontera_taxonomy_index_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['frontera_taxonomy_index_name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['frontera_taxonomy_index_name']['link_to_entity'] = 1;
  /* Field: Frontera basic index: Entity Bundle (indexed) */
  $handler->display->display_options['fields']['frontera_basic_index_field_entity_bundle']['id'] = 'frontera_basic_index_field_entity_bundle';
  $handler->display->display_options['fields']['frontera_basic_index_field_entity_bundle']['table'] = 'search_api_multi_frontera_solr_server';
  $handler->display->display_options['fields']['frontera_basic_index_field_entity_bundle']['field'] = 'frontera_basic_index_field_entity_bundle';
  $handler->display->display_options['fields']['frontera_basic_index_field_entity_bundle']['label'] = '';
  $handler->display->display_options['fields']['frontera_basic_index_field_entity_bundle']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['frontera_basic_index_field_entity_bundle']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['frontera_basic_index_field_entity_bundle']['format_name'] = 1;
  /* Field: Frontera basic index » The main body text: Text (indexed) */
  $handler->display->display_options['fields']['frontera_basic_index_body_value']['id'] = 'frontera_basic_index_body_value';
  $handler->display->display_options['fields']['frontera_basic_index_body_value']['table'] = 'search_api_multi_frontera_solr_server';
  $handler->display->display_options['fields']['frontera_basic_index_body_value']['field'] = 'frontera_basic_index_body_value';
  $handler->display->display_options['fields']['frontera_basic_index_body_value']['label'] = '';
  $handler->display->display_options['fields']['frontera_basic_index_body_value']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['frontera_basic_index_body_value']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['frontera_basic_index_body_value']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['frontera_basic_index_body_value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['frontera_basic_index_body_value']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['frontera_basic_index_body_value']['link_to_entity'] = 0;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_multi_frontera_solr_server';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Filter criterion: Frontera basic index: Recording Title (fulltext) (indexed) */
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_title_fulltext']['id'] = 'frontera_basic_index_field_recording_title_fulltext';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_title_fulltext']['table'] = 'search_api_multi_frontera_solr_server';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_title_fulltext']['field'] = 'frontera_basic_index_field_recording_title_fulltext';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_title_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_title_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_title_fulltext']['expose']['operator_id'] = 'frontera_basic_index_field_recording_title_fulltext_op';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_title_fulltext']['expose']['label'] = 'Filter by Song Title';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_title_fulltext']['expose']['operator'] = 'frontera_basic_index_field_recording_title_fulltext_op';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_title_fulltext']['expose']['identifier'] = 'frontera_basic_index_field_recording_title_fulltext';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_title_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Frontera basic index: Arstist Artist Name (indexed) */
  $handler->display->display_options['filters']['frontera_basic_index_field_artist_artist_name']['id'] = 'frontera_basic_index_field_artist_artist_name';
  $handler->display->display_options['filters']['frontera_basic_index_field_artist_artist_name']['table'] = 'search_api_multi_frontera_solr_server';
  $handler->display->display_options['filters']['frontera_basic_index_field_artist_artist_name']['field'] = 'frontera_basic_index_field_artist_artist_name';
  $handler->display->display_options['filters']['frontera_basic_index_field_artist_artist_name']['group'] = 1;
  $handler->display->display_options['filters']['frontera_basic_index_field_artist_artist_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['frontera_basic_index_field_artist_artist_name']['expose']['operator_id'] = 'frontera_basic_index_field_artist_artist_name_op';
  $handler->display->display_options['filters']['frontera_basic_index_field_artist_artist_name']['expose']['label'] = 'Filter by Artist Name';
  $handler->display->display_options['filters']['frontera_basic_index_field_artist_artist_name']['expose']['operator'] = 'frontera_basic_index_field_artist_artist_name_op';
  $handler->display->display_options['filters']['frontera_basic_index_field_artist_artist_name']['expose']['identifier'] = 'frontera_basic_index_field_artist_artist_name';
  $handler->display->display_options['filters']['frontera_basic_index_field_artist_artist_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Frontera basic index: Recording Album Name (fulltext) (indexed) */
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_album_fulltext']['id'] = 'frontera_basic_index_field_recording_album_fulltext';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_album_fulltext']['table'] = 'search_api_multi_frontera_solr_server';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_album_fulltext']['field'] = 'frontera_basic_index_field_recording_album_fulltext';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_album_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_album_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_album_fulltext']['expose']['operator_id'] = 'frontera_basic_index_field_recording_album_fulltext_op';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_album_fulltext']['expose']['label'] = 'Filter by Album';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_album_fulltext']['expose']['operator'] = 'frontera_basic_index_field_recording_album_fulltext_op';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_album_fulltext']['expose']['identifier'] = 'frontera_basic_index_field_recording_album_fulltext';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_album_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Frontera Taxonomy Index: Label Name (fulltext) (indexed) */
  $handler->display->display_options['filters']['frontera_taxonomy_index_field_label_name_fulltext']['id'] = 'frontera_taxonomy_index_field_label_name_fulltext';
  $handler->display->display_options['filters']['frontera_taxonomy_index_field_label_name_fulltext']['table'] = 'search_api_multi_frontera_solr_server';
  $handler->display->display_options['filters']['frontera_taxonomy_index_field_label_name_fulltext']['field'] = 'frontera_taxonomy_index_field_label_name_fulltext';
  $handler->display->display_options['filters']['frontera_taxonomy_index_field_label_name_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['frontera_taxonomy_index_field_label_name_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['frontera_taxonomy_index_field_label_name_fulltext']['expose']['operator_id'] = 'frontera_taxonomy_index_field_label_name_fulltext_op';
  $handler->display->display_options['filters']['frontera_taxonomy_index_field_label_name_fulltext']['expose']['label'] = 'Filter by Label';
  $handler->display->display_options['filters']['frontera_taxonomy_index_field_label_name_fulltext']['expose']['operator'] = 'frontera_taxonomy_index_field_label_name_fulltext_op';
  $handler->display->display_options['filters']['frontera_taxonomy_index_field_label_name_fulltext']['expose']['identifier'] = 'frontera_taxonomy_index_field_label_name_fulltext';
  $handler->display->display_options['filters']['frontera_taxonomy_index_field_label_name_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Frontera basic index: Recording Genre (fulltext) (indexed) */
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_genre']['id'] = 'frontera_basic_index_field_recording_genre';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_genre']['table'] = 'search_api_multi_frontera_solr_server';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_genre']['field'] = 'frontera_basic_index_field_recording_genre';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_genre']['exposed'] = TRUE;
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_genre']['expose']['operator_id'] = 'frontera_basic_index_field_recording_genre_op';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_genre']['expose']['label'] = 'Filter by Genre';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_genre']['expose']['operator'] = 'frontera_basic_index_field_recording_genre_op';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_genre']['expose']['identifier'] = 'frontera_basic_index_field_recording_genre';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_genre']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Frontera basic index: Recording Subject (fulltext) (indexed) */
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_subject']['id'] = 'frontera_basic_index_field_recording_subject';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_subject']['table'] = 'search_api_multi_frontera_solr_server';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_subject']['field'] = 'frontera_basic_index_field_recording_subject';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_subject']['exposed'] = TRUE;
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_subject']['expose']['operator_id'] = 'frontera_basic_index_field_recording_subject_op';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_subject']['expose']['label'] = 'Filter by Subject';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_subject']['expose']['operator'] = 'frontera_basic_index_field_recording_subject_op';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_subject']['expose']['identifier'] = 'frontera_basic_index_field_recording_subject';
  $handler->display->display_options['filters']['frontera_basic_index_field_recording_subject']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_multi_fulltext']['id'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['table'] = 'search_api_multi_frontera_solr_server';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['field'] = 'search_api_multi_fulltext';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator_id'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['label'] = 'Fulltext search';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['operator'] = 'search_api_multi_fulltext_op';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['identifier'] = 'keywords';
  $handler->display->display_options['filters']['search_api_multi_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['search_api_multi_fulltext']['mode'] = 'filter';

  /* Display: Search Pane */
  $handler = $view->new_display('panel_pane', 'Search Pane', 'search_solr_pane');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['search_solr'] = $view;

  return $export;
}
