<?php
/**
 * @file
 * ct_name.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ct_name_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'image_gallery_name';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Image Gallery Name';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'infinite_scroll';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['type'] = 'colorbox';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'colorbox_node_style' => 'image_gallery_thumb_150_150',
    'colorbox_image_style' => '',
    'colorbox_gallery' => 'post',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'auto',
    'colorbox_caption_custom' => '',
  );
  $handler->display->display_options['fields']['field_images']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_images']['delta_offset'] = '0';
  /* Contextual filter: NID node being viewed */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'NID node being viewed';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'name' => 'name',
  );
  /* Filter criterion: Field: Images (field_images:fid) */
  $handler->display->display_options['filters']['field_images_fid']['id'] = 'field_images_fid';
  $handler->display->display_options['filters']['field_images_fid']['table'] = 'field_data_field_images';
  $handler->display->display_options['filters']['field_images_fid']['field'] = 'field_images_fid';
  $handler->display->display_options['filters']['field_images_fid']['operator'] = 'not empty';

  /* Display: Name: images tab */
  $handler = $view->new_display('panel_pane', 'Name: images tab', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'NID node being viewed',
    ),
  );
  $export['image_gallery_name'] = $view;

  $view = new view();
  $view->name = 'more_like_this__name';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_frontera_basic_index';
  $view->human_name = 'More Like This - Name';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'MLT on Recording';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Contextual filter: Search: More like this */
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['id'] = 'search_api_views_more_like_this';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['field'] = 'search_api_views_more_like_this';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['fields'] = array(
    'field_artist_recordings_count' => 'field_artist_recordings_count',
    'field_artist_real_name:field_biography' => 'field_artist_real_name:field_biography',
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'name' => 'name',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_mlt_on_recording');
  $handler->display->display_options['block_description'] = 'MLT on Recording';
  $export['more_like_this__name'] = $view;

  $view = new view();
  $view->name = 'name_recorded_composed';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Name Recorded Composed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Compositions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_artist_real_name' => 'field_artist_real_name',
  );
  /* Footer: Frontera: String with link */
  $handler->display->display_options['footer']['frontera_string_link']['id'] = 'frontera_string_link';
  $handler->display->display_options['footer']['frontera_string_link']['table'] = 'frontera';
  $handler->display->display_options['footer']['frontera_string_link']['field'] = 'frontera_string_link';
  $handler->display->display_options['footer']['frontera_string_link']['string'] = 'See all @total results >>';
  $handler->display->display_options['footer']['frontera_string_link']['url'] = 'songs?f[0]=field_composer:[nid]';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_composer_target_id']['id'] = 'field_composer_target_id';
  $handler->display->display_options['relationships']['field_composer_target_id']['table'] = 'field_data_field_composer';
  $handler->display->display_options['relationships']['field_composer_target_id']['field'] = 'field_composer_target_id';
  $handler->display->display_options['relationships']['field_composer_target_id']['label'] = 'Composer from field_composer';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_composer_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'image_gallery_thumb_150_150',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_images']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_recordings_composed_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Artist on Label */
  $handler->display->display_options['fields']['field_artist_on_label']['id'] = 'field_artist_on_label';
  $handler->display->display_options['fields']['field_artist_on_label']['table'] = 'field_data_field_artist_on_label';
  $handler->display->display_options['fields']['field_artist_on_label']['field'] = 'field_artist_on_label';
  $handler->display->display_options['fields']['field_artist_on_label']['label'] = '';
  $handler->display->display_options['fields']['field_artist_on_label']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_artist_on_label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_artist_on_label']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_artist_on_label']['hide_empty'] = TRUE;
  /* Field: Content: Artist Real Name */
  $handler->display->display_options['fields']['field_artist_real_name']['id'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['table'] = 'field_data_field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['field'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['label'] = 'by ';
  $handler->display->display_options['fields']['field_artist_real_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_artist_real_name']['empty'] = '[field_artist_on_label]';
  $handler->display->display_options['fields']['field_artist_real_name']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_artist_real_name']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_composer_target_id';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Composer (field_composer) */
  $handler->display->display_options['arguments']['field_composer_target_id']['id'] = 'field_composer_target_id';
  $handler->display->display_options['arguments']['field_composer_target_id']['table'] = 'field_data_field_composer';
  $handler->display->display_options['arguments']['field_composer_target_id']['field'] = 'field_composer_target_id';
  $handler->display->display_options['arguments']['field_composer_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_composer_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_composer_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_composer_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_composer_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_recordings_composed_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_recordings_composed_target_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recording' => 'recording',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'field_composer_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Composer (field_composer)',
    ),
  );
  $export['name_recorded_composed'] = $view;

  $view = new view();
  $view->name = 'name_recorded_recordings';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Name Recorded Recordings';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'See all recordings >>';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_artist_real_name' => 'field_artist_real_name',
  );
  /* Footer: Frontera: String with link */
  $handler->display->display_options['footer']['frontera_string_link']['id'] = 'frontera_string_link';
  $handler->display->display_options['footer']['frontera_string_link']['table'] = 'frontera';
  $handler->display->display_options['footer']['frontera_string_link']['field'] = 'frontera_string_link';
  $handler->display->display_options['footer']['frontera_string_link']['string'] = 'See all @total recordings >>';
  $handler->display->display_options['footer']['frontera_string_link']['url'] = 'songs?f[]=field_artist_real_name:[nid]';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_artist_real_name_target_id']['id'] = 'field_artist_real_name_target_id';
  $handler->display->display_options['relationships']['field_artist_real_name_target_id']['table'] = 'field_data_field_artist_real_name';
  $handler->display->display_options['relationships']['field_artist_real_name_target_id']['field'] = 'field_artist_real_name_target_id';
  $handler->display->display_options['relationships']['field_artist_real_name_target_id']['label'] = 'Artists from field_artist_real_name';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_artist_real_name_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'image_gallery_thumb_150_150',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_images']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_recordings_recorded_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Artist Real Name */
  $handler->display->display_options['fields']['field_artist_real_name']['id'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['table'] = 'field_data_field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['field'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['label'] = 'by ';
  $handler->display->display_options['fields']['field_artist_real_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_artist_real_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_artist_real_name']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_artist_real_name']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_artist_real_name_target_id';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Artist Real Name (field_artist_real_name) */
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['id'] = 'field_artist_real_name_target_id';
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['table'] = 'field_data_field_artist_real_name';
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['field'] = 'field_artist_real_name_target_id';
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_recordings_recorded_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_recordings_recorded_target_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recording' => 'recording',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'field_artist_real_name_target_id' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Artist Real Name (field_artist_real_name)',
    ),
  );
  $export['name_recorded_recordings'] = $view;

  return $export;
}
