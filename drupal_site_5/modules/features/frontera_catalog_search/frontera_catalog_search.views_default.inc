<?php
/**
 * @file
 * frontera_catalog_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function frontera_catalog_search_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'catalog_artists_solr';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_frontera_basic_index';
  $view->human_name = 'Catalog Artists Solr';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_artist_recordings_count' => 'field_artist_recordings_count',
    'field_artist_composed_count' => 'field_artist_composed_count',
    'field_artist_images_count' => 'field_artist_images_count',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_artist_recordings_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_artist_composed_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_artist_images_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Frontera: Alert Message */
  $handler->display->display_options['empty']['frontera_no_results']['id'] = 'frontera_no_results';
  $handler->display->display_options['empty']['frontera_no_results']['table'] = 'frontera';
  $handler->display->display_options['empty']['frontera_no_results']['field'] = 'frontera_no_results';
  $handler->display->display_options['empty']['frontera_no_results']['empty'] = TRUE;
  $handler->display->display_options['empty']['frontera_no_results']['alert_message'] = '<@searchedterm> returned no results, please try another term.';
  $handler->display->display_options['empty']['frontera_no_results']['message_type'] = 'drupal_alert';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title_1']['alter']['max_length'] = '30';
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_entity'] = 0;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Artists';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<div class="frontera-tipsy-cut-text">
[title_1]
<div class="frontera-tipsy-long-text">
[title]
</div>
</div>';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Node: Artist Recordings Count */
  $handler->display->display_options['fields']['field_artist_recordings_count']['id'] = 'field_artist_recordings_count';
  $handler->display->display_options['fields']['field_artist_recordings_count']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['field_artist_recordings_count']['field'] = 'field_artist_recordings_count';
  $handler->display->display_options['fields']['field_artist_recordings_count']['label'] = 'Recordings';
  $handler->display->display_options['fields']['field_artist_recordings_count']['link_to_entity'] = 0;
  /* Field: Indexed Node: Artist Composed Count */
  $handler->display->display_options['fields']['field_artist_composed_count']['id'] = 'field_artist_composed_count';
  $handler->display->display_options['fields']['field_artist_composed_count']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['field_artist_composed_count']['field'] = 'field_artist_composed_count';
  $handler->display->display_options['fields']['field_artist_composed_count']['label'] = 'Composed';
  $handler->display->display_options['fields']['field_artist_composed_count']['link_to_entity'] = 0;
  /* Field: Indexed Node: Artist Images Count */
  $handler->display->display_options['fields']['field_artist_images_count']['id'] = 'field_artist_images_count';
  $handler->display->display_options['fields']['field_artist_images_count']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['field_artist_images_count']['field'] = 'field_artist_images_count';
  $handler->display->display_options['fields']['field_artist_images_count']['label'] = 'Images';
  $handler->display->display_options['fields']['field_artist_images_count']['link_to_entity'] = 0;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'name' => 'name',
  );
  /* Filter criterion: Indexed Node: Artist Song Titles */
  $handler->display->display_options['filters']['field_artist_song_titles']['id'] = 'field_artist_song_titles';
  $handler->display->display_options['filters']['field_artist_song_titles']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['field_artist_song_titles']['field'] = 'field_artist_song_titles';
  $handler->display->display_options['filters']['field_artist_song_titles']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_artist_song_titles']['expose']['operator_id'] = 'field_artist_song_titles_op';
  $handler->display->display_options['filters']['field_artist_song_titles']['expose']['label'] = 'Filter by Song Title';
  $handler->display->display_options['filters']['field_artist_song_titles']['expose']['operator'] = 'field_artist_song_titles_op';
  $handler->display->display_options['filters']['field_artist_song_titles']['expose']['identifier'] = 'field_artist_song_titles';
  $handler->display->display_options['filters']['field_artist_song_titles']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Node: Arstist Artist Name */
  $handler->display->display_options['filters']['field_artist_artist_name']['id'] = 'field_artist_artist_name';
  $handler->display->display_options['filters']['field_artist_artist_name']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['field_artist_artist_name']['field'] = 'field_artist_artist_name';
  $handler->display->display_options['filters']['field_artist_artist_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_artist_artist_name']['expose']['operator_id'] = 'field_artist_artist_name_op';
  $handler->display->display_options['filters']['field_artist_artist_name']['expose']['label'] = 'Filter by Artist Name';
  $handler->display->display_options['filters']['field_artist_artist_name']['expose']['operator'] = 'field_artist_artist_name_op';
  $handler->display->display_options['filters']['field_artist_artist_name']['expose']['identifier'] = 'field_artist_artist_name';
  $handler->display->display_options['filters']['field_artist_artist_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Node: Artist Labels */
  $handler->display->display_options['filters']['field_artist_labels']['id'] = 'field_artist_labels';
  $handler->display->display_options['filters']['field_artist_labels']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['field_artist_labels']['field'] = 'field_artist_labels';
  $handler->display->display_options['filters']['field_artist_labels']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_artist_labels']['expose']['operator_id'] = 'field_artist_labels_op';
  $handler->display->display_options['filters']['field_artist_labels']['expose']['label'] = 'Filter by Label';
  $handler->display->display_options['filters']['field_artist_labels']['expose']['operator'] = 'field_artist_labels_op';
  $handler->display->display_options['filters']['field_artist_labels']['expose']['identifier'] = 'field_artist_labels';
  $handler->display->display_options['filters']['field_artist_labels']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Node: Artist Genres */
  $handler->display->display_options['filters']['field_artist_genres']['id'] = 'field_artist_genres';
  $handler->display->display_options['filters']['field_artist_genres']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['field_artist_genres']['field'] = 'field_artist_genres';
  $handler->display->display_options['filters']['field_artist_genres']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_artist_genres']['expose']['operator_id'] = 'field_artist_genres_op';
  $handler->display->display_options['filters']['field_artist_genres']['expose']['label'] = 'Filter by Genre';
  $handler->display->display_options['filters']['field_artist_genres']['expose']['operator'] = 'field_artist_genres_op';
  $handler->display->display_options['filters']['field_artist_genres']['expose']['identifier'] = 'field_artist_genres';
  $handler->display->display_options['filters']['field_artist_genres']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Node: Artist Subjects */
  $handler->display->display_options['filters']['field_artist_subjects']['id'] = 'field_artist_subjects';
  $handler->display->display_options['filters']['field_artist_subjects']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['field_artist_subjects']['field'] = 'field_artist_subjects';
  $handler->display->display_options['filters']['field_artist_subjects']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_artist_subjects']['expose']['operator_id'] = 'field_artist_subjects_op';
  $handler->display->display_options['filters']['field_artist_subjects']['expose']['label'] = 'Filter by Subject';
  $handler->display->display_options['filters']['field_artist_subjects']['expose']['operator'] = 'field_artist_subjects_op';
  $handler->display->display_options['filters']['field_artist_subjects']['expose']['identifier'] = 'field_artist_subjects';
  $handler->display->display_options['filters']['field_artist_subjects']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: By Artists Pane */
  $handler = $view->new_display('panel_pane', 'By Artists Pane', 'catalog_artists_solr_pane');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['catalog_artists_solr'] = $view;

  $view = new view();
  $view->name = 'catalog_labels_solr';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_frontera_taxonomy_index';
  $view->human_name = 'Catalog Labels Solr';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'field_label_artists_count' => 'field_label_artists_count',
    'field_label_recordings_count' => 'field_label_recordings_count',
    'field_label_images_count' => 'field_label_images_count',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_label_artists_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_label_recordings_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_label_images_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Frontera: Alert Message */
  $handler->display->display_options['empty']['frontera_no_results']['id'] = 'frontera_no_results';
  $handler->display->display_options['empty']['frontera_no_results']['table'] = 'frontera';
  $handler->display->display_options['empty']['frontera_no_results']['field'] = 'frontera_no_results';
  $handler->display->display_options['empty']['frontera_no_results']['empty'] = TRUE;
  $handler->display->display_options['empty']['frontera_no_results']['alert_message'] = '<@searchedterm> returned no results, please try another term.';
  $handler->display->display_options['empty']['frontera_no_results']['message_type'] = 'drupal_alert';
  /* Field: Indexed Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'search_api_index_frontera_taxonomy_index';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Labels';
  $handler->display->display_options['fields']['name']['link_to_entity'] = 1;
  /* Field: Indexed Taxonomy term: Label Artists Count */
  $handler->display->display_options['fields']['field_label_artists_count']['id'] = 'field_label_artists_count';
  $handler->display->display_options['fields']['field_label_artists_count']['table'] = 'search_api_index_frontera_taxonomy_index';
  $handler->display->display_options['fields']['field_label_artists_count']['field'] = 'field_label_artists_count';
  $handler->display->display_options['fields']['field_label_artists_count']['label'] = 'Artists';
  $handler->display->display_options['fields']['field_label_artists_count']['link_to_entity'] = 0;
  /* Field: Indexed Taxonomy term: Label Recordings Count */
  $handler->display->display_options['fields']['field_label_recordings_count']['id'] = 'field_label_recordings_count';
  $handler->display->display_options['fields']['field_label_recordings_count']['table'] = 'search_api_index_frontera_taxonomy_index';
  $handler->display->display_options['fields']['field_label_recordings_count']['field'] = 'field_label_recordings_count';
  $handler->display->display_options['fields']['field_label_recordings_count']['label'] = 'Recordings';
  $handler->display->display_options['fields']['field_label_recordings_count']['link_to_entity'] = 0;
  /* Field: Indexed Taxonomy term: Label Images Count */
  $handler->display->display_options['fields']['field_label_images_count']['id'] = 'field_label_images_count';
  $handler->display->display_options['fields']['field_label_images_count']['table'] = 'search_api_index_frontera_taxonomy_index';
  $handler->display->display_options['fields']['field_label_images_count']['field'] = 'field_label_images_count';
  $handler->display->display_options['fields']['field_label_images_count']['label'] = 'Images';
  $handler->display->display_options['fields']['field_label_images_count']['link_to_entity'] = 0;
  /* Filter criterion: Indexed Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vocabulary']['id'] = 'vocabulary';
  $handler->display->display_options['filters']['vocabulary']['table'] = 'search_api_index_frontera_taxonomy_index';
  $handler->display->display_options['filters']['vocabulary']['field'] = 'vocabulary';
  $handler->display->display_options['filters']['vocabulary']['value'] = '10';
  /* Filter criterion: Song Title */
  $handler->display->display_options['filters']['field_label_song_titles']['id'] = 'field_label_song_titles';
  $handler->display->display_options['filters']['field_label_song_titles']['table'] = 'search_api_index_frontera_taxonomy_index';
  $handler->display->display_options['filters']['field_label_song_titles']['field'] = 'field_label_song_titles';
  $handler->display->display_options['filters']['field_label_song_titles']['ui_name'] = 'Song Title';
  $handler->display->display_options['filters']['field_label_song_titles']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_label_song_titles']['expose']['operator_id'] = 'field_label_song_titles_op';
  $handler->display->display_options['filters']['field_label_song_titles']['expose']['label'] = 'Filter by Song Title';
  $handler->display->display_options['filters']['field_label_song_titles']['expose']['operator'] = 'field_label_song_titles_op';
  $handler->display->display_options['filters']['field_label_song_titles']['expose']['identifier'] = 'field_label_song_titles';
  $handler->display->display_options['filters']['field_label_song_titles']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Artist */
  $handler->display->display_options['filters']['field_label_artist_titles']['id'] = 'field_label_artist_titles';
  $handler->display->display_options['filters']['field_label_artist_titles']['table'] = 'search_api_index_frontera_taxonomy_index';
  $handler->display->display_options['filters']['field_label_artist_titles']['field'] = 'field_label_artist_titles';
  $handler->display->display_options['filters']['field_label_artist_titles']['ui_name'] = 'Artist';
  $handler->display->display_options['filters']['field_label_artist_titles']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_label_artist_titles']['expose']['operator_id'] = 'field_label_artist_titles_op';
  $handler->display->display_options['filters']['field_label_artist_titles']['expose']['label'] = 'Filter by Artist Name';
  $handler->display->display_options['filters']['field_label_artist_titles']['expose']['operator'] = 'field_label_artist_titles_op';
  $handler->display->display_options['filters']['field_label_artist_titles']['expose']['identifier'] = 'field_label_artist_titles';
  $handler->display->display_options['filters']['field_label_artist_titles']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Taxonomy term: Label Name (fulltext) */
  $handler->display->display_options['filters']['field_label_name_fulltext']['id'] = 'field_label_name_fulltext';
  $handler->display->display_options['filters']['field_label_name_fulltext']['table'] = 'search_api_index_frontera_taxonomy_index';
  $handler->display->display_options['filters']['field_label_name_fulltext']['field'] = 'field_label_name_fulltext';
  $handler->display->display_options['filters']['field_label_name_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_label_name_fulltext']['expose']['operator_id'] = 'field_label_name_fulltext_op';
  $handler->display->display_options['filters']['field_label_name_fulltext']['expose']['label'] = 'Filter by Label';
  $handler->display->display_options['filters']['field_label_name_fulltext']['expose']['operator'] = 'field_label_name_fulltext_op';
  $handler->display->display_options['filters']['field_label_name_fulltext']['expose']['identifier'] = 'field_label_name_fulltext';
  $handler->display->display_options['filters']['field_label_name_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Taxonomy term: Label Genres */
  $handler->display->display_options['filters']['field_label_genres']['id'] = 'field_label_genres';
  $handler->display->display_options['filters']['field_label_genres']['table'] = 'search_api_index_frontera_taxonomy_index';
  $handler->display->display_options['filters']['field_label_genres']['field'] = 'field_label_genres';
  $handler->display->display_options['filters']['field_label_genres']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_label_genres']['expose']['operator_id'] = 'field_label_genres_op';
  $handler->display->display_options['filters']['field_label_genres']['expose']['label'] = 'Filter by Genre';
  $handler->display->display_options['filters']['field_label_genres']['expose']['operator'] = 'field_label_genres_op';
  $handler->display->display_options['filters']['field_label_genres']['expose']['identifier'] = 'field_label_genres';
  $handler->display->display_options['filters']['field_label_genres']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Taxonomy term: Label Subjects */
  $handler->display->display_options['filters']['field_label_subjects']['id'] = 'field_label_subjects';
  $handler->display->display_options['filters']['field_label_subjects']['table'] = 'search_api_index_frontera_taxonomy_index';
  $handler->display->display_options['filters']['field_label_subjects']['field'] = 'field_label_subjects';
  $handler->display->display_options['filters']['field_label_subjects']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_label_subjects']['expose']['operator_id'] = 'field_label_subjects_op';
  $handler->display->display_options['filters']['field_label_subjects']['expose']['label'] = 'Filter by Subject';
  $handler->display->display_options['filters']['field_label_subjects']['expose']['operator'] = 'field_label_subjects_op';
  $handler->display->display_options['filters']['field_label_subjects']['expose']['identifier'] = 'field_label_subjects';
  $handler->display->display_options['filters']['field_label_subjects']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: By Labels */
  $handler = $view->new_display('panel_pane', 'By Labels', 'catalog_labels_solr_pane');
  $handler->display->display_options['display_description'] = 'Catalog by Labels.';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['catalog_labels_solr'] = $view;

  $view = new view();
  $view->name = 'catalog_songs_solr';
  $view->description = 'Songs catalog using SearchAPI Solr.';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_frontera_basic_index';
  $view->human_name = 'Catalog Songs Solr';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_recording_artist_name_string' => 'field_recording_artist_name_string',
    'field_recording_composer_string' => 'field_recording_composer_string',
    'field_recording_label_string' => 'field_recording_label_string',
    'field_catalog_number_alpha' => 'field_catalog_number_alpha',
    'field_matrix_number_computed' => 'field_matrix_number_computed',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_recording_artist_name_string' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_recording_composer_string' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_recording_label_string' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_catalog_number_alpha' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_matrix_number_computed' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Frontera: Alert Message */
  $handler->display->display_options['empty']['frontera_no_results']['id'] = 'frontera_no_results';
  $handler->display->display_options['empty']['frontera_no_results']['table'] = 'frontera';
  $handler->display->display_options['empty']['frontera_no_results']['field'] = 'frontera_no_results';
  $handler->display->display_options['empty']['frontera_no_results']['empty'] = TRUE;
  $handler->display->display_options['empty']['frontera_no_results']['alert_message'] = '<@searchedterm> returned no results, please try another term.';
  $handler->display->display_options['empty']['frontera_no_results']['message_type'] = 'drupal_alert';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Artist Real Name */
  $handler->display->display_options['fields']['field_artist_real_name']['id'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['field_artist_real_name']['field'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['label'] = 'Performer';
  $handler->display->display_options['fields']['field_artist_real_name']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_artist_real_name']['view_mode'] = 'full';
  /* Field: Indexed Node: Composer */
  $handler->display->display_options['fields']['field_composer']['id'] = 'field_composer';
  $handler->display->display_options['fields']['field_composer']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['field_composer']['field'] = 'field_composer';
  $handler->display->display_options['fields']['field_composer']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_composer']['view_mode'] = 'full';
  /* Field: Record Label: Name (indexed) */
  $handler->display->display_options['fields']['field_record_label_t_name']['id'] = 'field_record_label_t_name';
  $handler->display->display_options['fields']['field_record_label_t_name']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['field_record_label_t_name']['field'] = 'field_record_label_t_name';
  $handler->display->display_options['fields']['field_record_label_t_name']['label'] = 'Label';
  $handler->display->display_options['fields']['field_record_label_t_name']['link_to_entity'] = 0;
  /* Field: Indexed Node: Catalog Number Alpha */
  $handler->display->display_options['fields']['field_catalog_number_alpha']['id'] = 'field_catalog_number_alpha';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['field'] = 'field_catalog_number_alpha';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['label'] = 'Catalog #';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recording' => 'recording',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Node: Recording Title (fulltext) */
  $handler->display->display_options['filters']['field_recording_title_fulltext']['id'] = 'field_recording_title_fulltext';
  $handler->display->display_options['filters']['field_recording_title_fulltext']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['field_recording_title_fulltext']['field'] = 'field_recording_title_fulltext';
  $handler->display->display_options['filters']['field_recording_title_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['field_recording_title_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_recording_title_fulltext']['expose']['operator_id'] = 'field_recording_title_fulltext_op';
  $handler->display->display_options['filters']['field_recording_title_fulltext']['expose']['label'] = 'Filter by Song Title';
  $handler->display->display_options['filters']['field_recording_title_fulltext']['expose']['operator'] = 'field_recording_title_fulltext_op';
  $handler->display->display_options['filters']['field_recording_title_fulltext']['expose']['identifier'] = 'field_recording_title_fulltext';
  $handler->display->display_options['filters']['field_recording_title_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Node: Recording Album Name (fulltext) */
  $handler->display->display_options['filters']['field_recording_album_fulltext']['id'] = 'field_recording_album_fulltext';
  $handler->display->display_options['filters']['field_recording_album_fulltext']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['field_recording_album_fulltext']['field'] = 'field_recording_album_fulltext';
  $handler->display->display_options['filters']['field_recording_album_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['field_recording_album_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_recording_album_fulltext']['expose']['operator_id'] = 'field_recording_album_fulltext_op';
  $handler->display->display_options['filters']['field_recording_album_fulltext']['expose']['label'] = 'Filter by Album';
  $handler->display->display_options['filters']['field_recording_album_fulltext']['expose']['operator'] = 'field_recording_album_fulltext_op';
  $handler->display->display_options['filters']['field_recording_album_fulltext']['expose']['identifier'] = 'field_recording_album_fulltext';
  $handler->display->display_options['filters']['field_recording_album_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Node: Recording Artist Name (fulltext) */
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['id'] = 'field_recording_artist_name_fulltext';
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['field'] = 'field_recording_artist_name_fulltext';
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['expose']['operator_id'] = 'field_recording_artist_name_fulltext_op';
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['expose']['label'] = 'Filter by Artist Name';
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['expose']['operator'] = 'field_recording_artist_name_fulltext_op';
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['expose']['identifier'] = 'field_recording_artist_name_fulltext';
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Node: Recording Label (fulltext) */
  $handler->display->display_options['filters']['field_recording_label_fulltext']['id'] = 'field_recording_label_fulltext';
  $handler->display->display_options['filters']['field_recording_label_fulltext']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['field_recording_label_fulltext']['field'] = 'field_recording_label_fulltext';
  $handler->display->display_options['filters']['field_recording_label_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['field_recording_label_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_recording_label_fulltext']['expose']['operator_id'] = 'field_recording_label_fulltext_op';
  $handler->display->display_options['filters']['field_recording_label_fulltext']['expose']['label'] = 'Filter by Label';
  $handler->display->display_options['filters']['field_recording_label_fulltext']['expose']['operator'] = 'field_recording_label_fulltext_op';
  $handler->display->display_options['filters']['field_recording_label_fulltext']['expose']['identifier'] = 'field_recording_label_fulltext';
  $handler->display->display_options['filters']['field_recording_label_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: By Songs Pane */
  $handler = $view->new_display('panel_pane', 'By Songs Pane', 'catalog_songs_solr_pane');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Recording Artist Name (string) */
  $handler->display->display_options['fields']['field_recording_artist_name_string']['id'] = 'field_recording_artist_name_string';
  $handler->display->display_options['fields']['field_recording_artist_name_string']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['field_recording_artist_name_string']['field'] = 'field_recording_artist_name_string';
  $handler->display->display_options['fields']['field_recording_artist_name_string']['label'] = 'Performer';
  $handler->display->display_options['fields']['field_recording_artist_name_string']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_recording_artist_name_string']['link_to_entity'] = 0;
  /* Field: Indexed Node: Recording Composer (string) */
  $handler->display->display_options['fields']['field_recording_composer_string']['id'] = 'field_recording_composer_string';
  $handler->display->display_options['fields']['field_recording_composer_string']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['field_recording_composer_string']['field'] = 'field_recording_composer_string';
  $handler->display->display_options['fields']['field_recording_composer_string']['label'] = 'Composer';
  $handler->display->display_options['fields']['field_recording_composer_string']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_recording_composer_string']['link_to_entity'] = 0;
  /* Field: Indexed Node: Recording Label (string) */
  $handler->display->display_options['fields']['field_recording_label_string']['id'] = 'field_recording_label_string';
  $handler->display->display_options['fields']['field_recording_label_string']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['field_recording_label_string']['field'] = 'field_recording_label_string';
  $handler->display->display_options['fields']['field_recording_label_string']['label'] = 'Label';
  $handler->display->display_options['fields']['field_recording_label_string']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_recording_label_string']['link_to_entity'] = 0;
  /* Field: Indexed Node: Catalog Number Alpha */
  $handler->display->display_options['fields']['field_catalog_number_alpha']['id'] = 'field_catalog_number_alpha';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['field'] = 'field_catalog_number_alpha';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['label'] = 'Catalog #';
  /* Field: Indexed Node: Matrix Number Computed */
  $handler->display->display_options['fields']['field_matrix_number_computed']['id'] = 'field_matrix_number_computed';
  $handler->display->display_options['fields']['field_matrix_number_computed']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['field_matrix_number_computed']['field'] = 'field_matrix_number_computed';
  $handler->display->display_options['fields']['field_matrix_number_computed']['label'] = 'Matrix Number Computed - HIDDEN';
  $handler->display->display_options['fields']['field_matrix_number_computed']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Node: Matrix Number Computed */
  $handler->display->display_options['arguments']['field_matrix_number_computed']['id'] = 'field_matrix_number_computed';
  $handler->display->display_options['arguments']['field_matrix_number_computed']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['arguments']['field_matrix_number_computed']['field'] = 'field_matrix_number_computed';
  $handler->display->display_options['arguments']['field_matrix_number_computed']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_matrix_number_computed']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['field_matrix_number_computed']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_matrix_number_computed']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_matrix_number_computed']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recording' => 'recording',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Node: Recording Title (fulltext) */
  $handler->display->display_options['filters']['field_recording_title_fulltext']['id'] = 'field_recording_title_fulltext';
  $handler->display->display_options['filters']['field_recording_title_fulltext']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['field_recording_title_fulltext']['field'] = 'field_recording_title_fulltext';
  $handler->display->display_options['filters']['field_recording_title_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['field_recording_title_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_recording_title_fulltext']['expose']['operator_id'] = 'field_recording_title_fulltext_op';
  $handler->display->display_options['filters']['field_recording_title_fulltext']['expose']['label'] = 'Filter by Song Title';
  $handler->display->display_options['filters']['field_recording_title_fulltext']['expose']['operator'] = 'field_recording_title_fulltext_op';
  $handler->display->display_options['filters']['field_recording_title_fulltext']['expose']['identifier'] = 'field_recording_title_fulltext';
  $handler->display->display_options['filters']['field_recording_title_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Node: Recording Album Name (fulltext) */
  $handler->display->display_options['filters']['field_recording_album_fulltext']['id'] = 'field_recording_album_fulltext';
  $handler->display->display_options['filters']['field_recording_album_fulltext']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['field_recording_album_fulltext']['field'] = 'field_recording_album_fulltext';
  $handler->display->display_options['filters']['field_recording_album_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['field_recording_album_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_recording_album_fulltext']['expose']['operator_id'] = 'field_recording_album_fulltext_op';
  $handler->display->display_options['filters']['field_recording_album_fulltext']['expose']['label'] = 'Filter by Album';
  $handler->display->display_options['filters']['field_recording_album_fulltext']['expose']['operator'] = 'field_recording_album_fulltext_op';
  $handler->display->display_options['filters']['field_recording_album_fulltext']['expose']['identifier'] = 'field_recording_album_fulltext';
  $handler->display->display_options['filters']['field_recording_album_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Node: Recording Artist Name (fulltext) */
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['id'] = 'field_recording_artist_name_fulltext';
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['field'] = 'field_recording_artist_name_fulltext';
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['expose']['operator_id'] = 'field_recording_artist_name_fulltext_op';
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['expose']['label'] = 'Filter by Artist Name';
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['expose']['operator'] = 'field_recording_artist_name_fulltext_op';
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['expose']['identifier'] = 'field_recording_artist_name_fulltext';
  $handler->display->display_options['filters']['field_recording_artist_name_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Node: Recording Label (fulltext) */
  $handler->display->display_options['filters']['field_recording_label_fulltext']['id'] = 'field_recording_label_fulltext';
  $handler->display->display_options['filters']['field_recording_label_fulltext']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['field_recording_label_fulltext']['field'] = 'field_recording_label_fulltext';
  $handler->display->display_options['filters']['field_recording_label_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['field_recording_label_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_recording_label_fulltext']['expose']['operator_id'] = 'field_recording_label_fulltext_op';
  $handler->display->display_options['filters']['field_recording_label_fulltext']['expose']['label'] = 'Filter by Label';
  $handler->display->display_options['filters']['field_recording_label_fulltext']['expose']['operator'] = 'field_recording_label_fulltext_op';
  $handler->display->display_options['filters']['field_recording_label_fulltext']['expose']['identifier'] = 'label';
  $handler->display->display_options['filters']['field_recording_label_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Node: Recording Genre (fulltext) */
  $handler->display->display_options['filters']['field_recording_genre']['id'] = 'field_recording_genre';
  $handler->display->display_options['filters']['field_recording_genre']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['field_recording_genre']['field'] = 'field_recording_genre';
  $handler->display->display_options['filters']['field_recording_genre']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_recording_genre']['expose']['operator_id'] = 'field_recording_genre_op';
  $handler->display->display_options['filters']['field_recording_genre']['expose']['label'] = 'Filter by Genre';
  $handler->display->display_options['filters']['field_recording_genre']['expose']['operator'] = 'field_recording_genre_op';
  $handler->display->display_options['filters']['field_recording_genre']['expose']['identifier'] = 'field_recording_genre';
  $handler->display->display_options['filters']['field_recording_genre']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Indexed Node: Recording Subject (fulltext) */
  $handler->display->display_options['filters']['field_recording_subject']['id'] = 'field_recording_subject';
  $handler->display->display_options['filters']['field_recording_subject']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['field_recording_subject']['field'] = 'field_recording_subject';
  $handler->display->display_options['filters']['field_recording_subject']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_recording_subject']['expose']['operator_id'] = 'field_recording_subject_op';
  $handler->display->display_options['filters']['field_recording_subject']['expose']['label'] = 'Filter by Subject';
  $handler->display->display_options['filters']['field_recording_subject']['expose']['operator'] = 'field_recording_subject_op';
  $handler->display->display_options['filters']['field_recording_subject']['expose']['identifier'] = 'field_recording_subject';
  $handler->display->display_options['filters']['field_recording_subject']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['argument_input'] = array(
    'field_matrix_number_computed' => array(
      'type' => 'panel',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Indexed Node: Matrix Number Computed',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['catalog_songs_solr'] = $view;

  return $export;
}
