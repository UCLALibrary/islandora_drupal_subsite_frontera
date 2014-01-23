<?php
/**
 * @file
 * ct_recording.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ct_recording_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'commenti';
  $view->description = 'views that gather comments used in Recordings Panel';
  $view->tag = 'default';
  $view->base_table = 'comment';
  $view->human_name = 'Comments Recording';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'created' => 'created',
  );
  /* Relationship: Comment: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Field: Comment: Title */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['label'] = '';
  $handler->display->display_options['fields']['subject']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['subject']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['subject']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['subject']['element_wrapper_type'] = 'h3';
  $handler->display->display_options['fields']['subject']['link_to_comment'] = FALSE;
  /* Field: Comment: Author */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'comment';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'by';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name],';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Comment: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'comment';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['custom_date_format'] = '1';
  /* Field: Comment: Comment */
  $handler->display->display_options['fields']['comment_body']['id'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['table'] = 'field_data_comment_body';
  $handler->display->display_options['fields']['comment_body']['field'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['label'] = '';
  $handler->display->display_options['fields']['comment_body']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['comment_body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['comment_body']['element_label_colon'] = FALSE;
  /* Sort criterion: Comment: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'comment';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Comment: Approved */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_node']['id'] = 'status_node';
  $handler->display->display_options['filters']['status_node']['table'] = 'node';
  $handler->display->display_options['filters']['status_node']['field'] = 'status';
  $handler->display->display_options['filters']['status_node']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_node']['value'] = 1;
  $handler->display->display_options['filters']['status_node']['group'] = 1;
  $handler->display->display_options['filters']['status_node']['expose']['operator'] = FALSE;

  /* Display: Preview Comments */
  $handler = $view->new_display('panel_pane', 'Preview Comments', 'panel_pane_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: NID node being viewed */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'NID node being viewed';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
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
  $export['commenti'] = $view;

  $view = new view();
  $view->name = 'container';
  $view->description = 'views that gather Container nodes used in Recordings Panel';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Container Recording';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_container_recording' => 'field_container_recording',
    'field_artist_real_name' => 'field_artist_real_name',
  );
  /* Field: Content: Artist Real Name */
  $handler->display->display_options['fields']['field_artist_real_name']['id'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['table'] = 'field_data_field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['field'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['label'] = 'by';
  $handler->display->display_options['fields']['field_artist_real_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_artist_real_name']['settings'] = array(
    'link' => 0,
  );
  /* Sort criterion: Content: Side (field_side) */
  $handler->display->display_options['sorts']['field_side_value']['id'] = 'field_side_value';
  $handler->display->display_options['sorts']['field_side_value']['table'] = 'field_data_field_side';
  $handler->display->display_options['sorts']['field_side_value']['field'] = 'field_side_value';
  $handler->display->display_options['sorts']['field_side_value']['relationship'] = 'reverse_field_title_of_album_node';
  /* Sort criterion: Content: Track Number (field_track_number) */
  $handler->display->display_options['sorts']['field_track_number_value']['id'] = 'field_track_number_value';
  $handler->display->display_options['sorts']['field_track_number_value']['table'] = 'field_data_field_track_number';
  $handler->display->display_options['sorts']['field_track_number_value']['field'] = 'field_track_number_value';
  $handler->display->display_options['sorts']['field_track_number_value']['relationship'] = 'reverse_field_title_of_album_node';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'reverse_field_title_of_album_node';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
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
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'container' => 'container',
  );

  /* Display: Also on this Media */
  $handler = $view->new_display('panel_pane', 'Also on this Media', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Also on this Media';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_side',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_track_number' => 'field_track_number',
    'title' => 'title',
    'field_artist_real_name' => 'field_artist_real_name',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_title_of_album_node']['id'] = 'reverse_field_title_of_album_node';
  $handler->display->display_options['relationships']['reverse_field_title_of_album_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_title_of_album_node']['field'] = 'reverse_field_title_of_album_node';
  $handler->display->display_options['relationships']['reverse_field_title_of_album_node']['label'] = 'Recording from field_title_of_album';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Track Number */
  $handler->display->display_options['fields']['field_track_number']['id'] = 'field_track_number';
  $handler->display->display_options['fields']['field_track_number']['table'] = 'field_data_field_track_number';
  $handler->display->display_options['fields']['field_track_number']['field'] = 'field_track_number';
  $handler->display->display_options['fields']['field_track_number']['relationship'] = 'reverse_field_title_of_album_node';
  $handler->display->display_options['fields']['field_track_number']['label'] = '';
  $handler->display->display_options['fields']['field_track_number']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_track_number']['alter']['text'] = '[field_track_number]. ';
  $handler->display->display_options['fields']['field_track_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_track_number']['empty'] = '<span class="no-track-number">•</span>';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_title_of_album_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Artist Real Name */
  $handler->display->display_options['fields']['field_artist_real_name']['id'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['table'] = 'field_data_field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['field'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['relationship'] = 'reverse_field_title_of_album_node';
  $handler->display->display_options['fields']['field_artist_real_name']['label'] = 'by';
  $handler->display->display_options['fields']['field_artist_real_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_artist_real_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_artist_real_name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_artist_real_name']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_artist_real_name']['delta_offset'] = '0';
  /* Field: Content: Side */
  $handler->display->display_options['fields']['field_side']['id'] = 'field_side';
  $handler->display->display_options['fields']['field_side']['table'] = 'field_data_field_side';
  $handler->display->display_options['fields']['field_side']['field'] = 'field_side';
  $handler->display->display_options['fields']['field_side']['relationship'] = 'reverse_field_title_of_album_node';
  $handler->display->display_options['fields']['field_side']['label'] = '';
  $handler->display->display_options['fields']['field_side']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_side']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_side']['alter']['text'] = 'Side [field_side]';
  $handler->display->display_options['fields']['field_side']['element_type'] = '0';
  $handler->display->display_options['fields']['field_side']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_side']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_side']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_side']['field_api_classes'] = TRUE;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['container'] = $view;

  $view = new view();
  $view->name = 'image_gallery_recording';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Image Gallery Recording';
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
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Field: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['type'] = 'colorbox';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'colorbox_node_style' => 'image_gallery_thumb_150_150',
    'colorbox_image_style' => '',
    'colorbox_gallery' => 'custom',
    'colorbox_gallery_custom' => 'recording',
    'colorbox_caption' => 'auto',
    'colorbox_caption_custom' => '',
  );
  $handler->display->display_options['fields']['field_images']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_images']['delta_offset'] = '0';
  /* Field: Field: Images (field_images:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['element_type'] = '0';
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delta']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['delta']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['delta']['separator'] = '';
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
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recording' => 'recording',
  );
  /* Filter criterion: Field: Images (field_images:fid) */
  $handler->display->display_options['filters']['field_images_fid']['id'] = 'field_images_fid';
  $handler->display->display_options['filters']['field_images_fid']['table'] = 'field_data_field_images';
  $handler->display->display_options['filters']['field_images_fid']['field'] = 'field_images_fid';
  $handler->display->display_options['filters']['field_images_fid']['operator'] = 'not empty';
  /* Filter criterion: Field: Images (field_images:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_images';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['operator'] = '>';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';

  /* Display: Recording: images tab */
  $handler = $view->new_display('panel_pane', 'Recording: images tab', 'panel_pane_1');
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
  $export['image_gallery_recording'] = $view;

  $view = new view();
  $view->name = 'more_like_this__recording';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_frontera_basic_index';
  $view->human_name = 'More Like This - Recording';
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
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_artist_real_name' => 'field_artist_real_name',
  );
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Artist Real Name */
  $handler->display->display_options['fields']['field_artist_real_name']['id'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['fields']['field_artist_real_name']['field'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['label'] = 'by';
  $handler->display->display_options['fields']['field_artist_real_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_artist_real_name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_artist_real_name']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_artist_real_name']['view_mode'] = 'full';
  /* Contextual filter: Search: More like this */
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['id'] = 'search_api_views_more_like_this';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['field'] = 'search_api_views_more_like_this';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['fields'] = array(
    'field_label_song_type' => 'field_label_song_type',
    'field_record_label_t' => 'field_record_label_t',
  );
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_frontera_basic_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recording' => 'recording',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_mlt_on_recording');
  $handler->display->display_options['block_description'] = 'MLT on Recording';
  $export['more_like_this__recording'] = $view;

  $view = new view();
  $view->name = 'name_images';
  $view->description = 'Views that gather Name nodes';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Name Recording';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_images']['delta_offset'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'name' => 'name',
  );

  /* Display: First Image of an Artist */
  $handler = $view->new_display('panel_pane', 'First Image of an Artist', 'panel_pane_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Images */
  $handler->display->display_options['fields']['field_images']['id'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['table'] = 'field_data_field_images';
  $handler->display->display_options['fields']['field_images']['field'] = 'field_images';
  $handler->display->display_options['fields']['field_images']['label'] = '';
  $handler->display->display_options['fields']['field_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_images']['settings'] = array(
    'image_style' => 'name_img_400_400',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_images']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Name Content NID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Name Content NID';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Name Content NID',
    ),
  );

  /* Display: Other Recordings by Artist */
  $handler = $view->new_display('panel_pane', 'Other Recordings by Artist', 'panel_pane_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'title_1' => 'title_1',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_artist_real_name_node']['id'] = 'reverse_field_artist_real_name_node';
  $handler->display->display_options['relationships']['reverse_field_artist_real_name_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_artist_real_name_node']['field'] = 'reverse_field_artist_real_name_node';
  $handler->display->display_options['relationships']['reverse_field_artist_real_name_node']['label'] = 'to Recording from field_artist_real_name';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'reverse_field_artist_real_name_node';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'by';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'name content nid',
    ),
  );
  $export['name_images'] = $view;

  $view = new view();
  $view->name = 'recording_by_artist';
  $view->description = 'view used in "Other Recording by artist" element - Recording Variant';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recording by artist';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Other recordings by %1';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_artist_real_name' => 'field_artist_real_name',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Artist Real Name */
  $handler->display->display_options['fields']['field_artist_real_name']['id'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['table'] = 'field_data_field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['field'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['label'] = 'by';
  $handler->display->display_options['fields']['field_artist_real_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_artist_real_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_artist_real_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_artist_real_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_artist_real_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_artist_real_name']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_artist_real_name']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_artist_real_name']['field_api_classes'] = TRUE;
  /* Contextual filter: Content: Artist Real Name (field_artist_real_name) */
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['id'] = 'field_artist_real_name_target_id';
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['table'] = 'field_data_field_artist_real_name';
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['field'] = 'field_artist_real_name_target_id';
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_artist_real_name_target_id']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recording' => 'recording',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['recording_by_artist'] = $view;

  $view = new view();
  $view->name = 'recording_details';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recording Details';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Contextual filter: Recording NID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Recording NID';
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
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recording' => 'recording',
  );

  /* Display: Performer section */
  $handler = $view->new_display('panel_pane', 'Performer section', 'panel_pane_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_artist_real_name' => 'field_artist_real_name',
    'field_artist_on_label' => 'field_artist_on_label',
    'field_composer' => 'field_composer',
    'field_accompaniment' => 'field_accompaniment',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Artist Real Name */
  $handler->display->display_options['fields']['field_artist_real_name']['id'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['table'] = 'field_data_field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['field'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['label'] = 'Performer';
  $handler->display->display_options['fields']['field_artist_real_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_artist_real_name']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_artist_real_name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_artist_real_name']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_artist_real_name']['delta_offset'] = '0';
  /* Field: Content: Artist on Label */
  $handler->display->display_options['fields']['field_artist_on_label']['id'] = 'field_artist_on_label';
  $handler->display->display_options['fields']['field_artist_on_label']['table'] = 'field_data_field_artist_on_label';
  $handler->display->display_options['fields']['field_artist_on_label']['field'] = 'field_artist_on_label';
  $handler->display->display_options['fields']['field_artist_on_label']['label'] = 'Performer Listed on Media';
  $handler->display->display_options['fields']['field_artist_on_label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_artist_on_label']['hide_empty'] = TRUE;
  /* Field: Content: Composer */
  $handler->display->display_options['fields']['field_composer']['id'] = 'field_composer';
  $handler->display->display_options['fields']['field_composer']['table'] = 'field_data_field_composer';
  $handler->display->display_options['fields']['field_composer']['field'] = 'field_composer';
  $handler->display->display_options['fields']['field_composer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_composer']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_composer']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_composer']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Accompaniment */
  $handler->display->display_options['fields']['field_accompaniment']['id'] = 'field_accompaniment';
  $handler->display->display_options['fields']['field_accompaniment']['table'] = 'field_data_field_accompaniment';
  $handler->display->display_options['fields']['field_accompaniment']['field'] = 'field_accompaniment';
  $handler->display->display_options['fields']['field_accompaniment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_accompaniment']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_accompaniment']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_accompaniment']['delta_offset'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Recording NID',
    ),
  );

  /* Display: Recording section */
  $handler = $view->new_display('panel_pane', 'Recording section', 'panel_pane_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_recording_format' => 'field_recording_format',
    'field_side' => 'field_side',
    'field_recording_date' => 'field_recording_date',
    'field_condition' => 'field_condition',
    'field_keyword' => 'field_keyword',
    'field_track_number' => 'field_track_number',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Recording Format */
  $handler->display->display_options['fields']['field_recording_format']['id'] = 'field_recording_format';
  $handler->display->display_options['fields']['field_recording_format']['table'] = 'field_data_field_recording_format';
  $handler->display->display_options['fields']['field_recording_format']['field'] = 'field_recording_format';
  $handler->display->display_options['fields']['field_recording_format']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_recording_format']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_recording_format']['hide_empty'] = TRUE;
  /* Field: Content: Side */
  $handler->display->display_options['fields']['field_side']['id'] = 'field_side';
  $handler->display->display_options['fields']['field_side']['table'] = 'field_data_field_side';
  $handler->display->display_options['fields']['field_side']['field'] = 'field_side';
  $handler->display->display_options['fields']['field_side']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_side']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_side']['hide_empty'] = TRUE;
  /* Field: Content: Recording Date */
  $handler->display->display_options['fields']['field_recording_date']['id'] = 'field_recording_date';
  $handler->display->display_options['fields']['field_recording_date']['table'] = 'field_data_field_recording_date';
  $handler->display->display_options['fields']['field_recording_date']['field'] = 'field_recording_date';
  $handler->display->display_options['fields']['field_recording_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_recording_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_recording_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_recording_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Condition */
  $handler->display->display_options['fields']['field_condition']['id'] = 'field_condition';
  $handler->display->display_options['fields']['field_condition']['table'] = 'field_data_field_condition';
  $handler->display->display_options['fields']['field_condition']['field'] = 'field_condition';
  $handler->display->display_options['fields']['field_condition']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_condition']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_condition']['hide_empty'] = TRUE;
  /* Field: Content: Keyword */
  $handler->display->display_options['fields']['field_keyword']['id'] = 'field_keyword';
  $handler->display->display_options['fields']['field_keyword']['table'] = 'field_data_field_keyword';
  $handler->display->display_options['fields']['field_keyword']['field'] = 'field_keyword';
  $handler->display->display_options['fields']['field_keyword']['label'] = 'Subject';
  $handler->display->display_options['fields']['field_keyword']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_keyword']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_keyword']['delta_offset'] = '0';
  /* Field: Content: Track Number */
  $handler->display->display_options['fields']['field_track_number']['id'] = 'field_track_number';
  $handler->display->display_options['fields']['field_track_number']['table'] = 'field_data_field_track_number';
  $handler->display->display_options['fields']['field_track_number']['field'] = 'field_track_number';
  $handler->display->display_options['fields']['field_track_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_track_number']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_track_number']['hide_empty'] = TRUE;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Recording NID',
    ),
  );

  /* Display: Album title section */
  $handler = $view->new_display('panel_pane', 'Album title section', 'panel_pane_3');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_title_of_album' => 'field_title_of_album',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title of Album */
  $handler->display->display_options['fields']['field_title_of_album']['id'] = 'field_title_of_album';
  $handler->display->display_options['fields']['field_title_of_album']['table'] = 'field_data_field_title_of_album';
  $handler->display->display_options['fields']['field_title_of_album']['field'] = 'field_title_of_album';
  $handler->display->display_options['fields']['field_title_of_album']['label'] = 'Album title';
  $handler->display->display_options['fields']['field_title_of_album']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_title_of_album']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_title_of_album']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Recording NID',
    ),
  );

  /* Display: Label section */
  $handler = $view->new_display('panel_pane', 'Label section', 'panel_pane_4');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
    'field_country' => 'field_country',
    'field_publisher' => 'field_publisher',
    'field_catalog_number_alpha' => 'field_catalog_number_alpha',
    'field_matrix_number' => 'field_matrix_number',
    'field_label_song_type' => 'field_label_song_type',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Record Label (field_record_label_t) */
  $handler->display->display_options['relationships']['field_record_label_t_tid']['id'] = 'field_record_label_t_tid';
  $handler->display->display_options['relationships']['field_record_label_t_tid']['table'] = 'field_data_field_record_label_t';
  $handler->display->display_options['relationships']['field_record_label_t_tid']['field'] = 'field_record_label_t_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_record_label_t_tid';
  $handler->display->display_options['fields']['name']['label'] = 'Label';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy term: Country */
  $handler->display->display_options['fields']['field_country']['id'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['table'] = 'field_data_field_country';
  $handler->display->display_options['fields']['field_country']['field'] = 'field_country';
  $handler->display->display_options['fields']['field_country']['relationship'] = 'field_record_label_t_tid';
  $handler->display->display_options['fields']['field_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_country']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_country']['hide_empty'] = TRUE;
  /* Field: Content: Publisher */
  $handler->display->display_options['fields']['field_publisher']['id'] = 'field_publisher';
  $handler->display->display_options['fields']['field_publisher']['table'] = 'field_data_field_publisher';
  $handler->display->display_options['fields']['field_publisher']['field'] = 'field_publisher';
  $handler->display->display_options['fields']['field_publisher']['label'] = 'Publisher Listed on Media';
  $handler->display->display_options['fields']['field_publisher']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publisher']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_publisher']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_publisher']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_publisher']['delta_offset'] = '0';
  /* Field: Content: Catalog Number Alpha */
  $handler->display->display_options['fields']['field_catalog_number_alpha']['id'] = 'field_catalog_number_alpha';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['table'] = 'field_data_field_catalog_number_alpha';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['field'] = 'field_catalog_number_alpha';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['label'] = 'Catalog Number';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_catalog_number_alpha']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['hide_empty'] = TRUE;
  /* Field: Content: Matrix Number */
  $handler->display->display_options['fields']['field_matrix_number']['id'] = 'field_matrix_number';
  $handler->display->display_options['fields']['field_matrix_number']['table'] = 'field_data_field_matrix_number';
  $handler->display->display_options['fields']['field_matrix_number']['field'] = 'field_matrix_number';
  $handler->display->display_options['fields']['field_matrix_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_matrix_number']['element_wrapper_type'] = 'div';
  /* Field: Content: Label Song Type */
  $handler->display->display_options['fields']['field_label_song_type']['id'] = 'field_label_song_type';
  $handler->display->display_options['fields']['field_label_song_type']['table'] = 'field_data_field_label_song_type';
  $handler->display->display_options['fields']['field_label_song_type']['field'] = 'field_label_song_type';
  $handler->display->display_options['fields']['field_label_song_type']['label'] = 'Genre';
  $handler->display->display_options['fields']['field_label_song_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_label_song_type']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_label_song_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_label_song_type']['delta_offset'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Recording NID',
    ),
  );

  /* Display: Styli section */
  $handler = $view->new_display('panel_pane', 'Styli section', 'panel_pane_5');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_styli' => 'field_styli',
    'field_transfer_equipment' => 'field_transfer_equipment',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Styli */
  $handler->display->display_options['fields']['field_styli']['id'] = 'field_styli';
  $handler->display->display_options['fields']['field_styli']['table'] = 'field_data_field_styli';
  $handler->display->display_options['fields']['field_styli']['field'] = 'field_styli';
  $handler->display->display_options['fields']['field_styli']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_styli']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_styli']['hide_empty'] = TRUE;
  /* Field: Content: Transfer Equipment */
  $handler->display->display_options['fields']['field_transfer_equipment']['id'] = 'field_transfer_equipment';
  $handler->display->display_options['fields']['field_transfer_equipment']['table'] = 'field_data_field_transfer_equipment';
  $handler->display->display_options['fields']['field_transfer_equipment']['field'] = 'field_transfer_equipment';
  $handler->display->display_options['fields']['field_transfer_equipment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_transfer_equipment']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_transfer_equipment']['hide_empty'] = TRUE;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Recording NID',
    ),
  );

  /* Display: Label short */
  $handler = $view->new_display('panel_pane', 'Label short', 'panel_pane_6');
  $handler->display->display_options['display_description'] = 'to use in the upper part of panel';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_record_label' => 'field_record_label',
    'field_matrix_number' => 'field_matrix_number',
    'field_country' => 'field_country',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_record_label']['id'] = 'field_record_label';
  $handler->display->display_options['fields']['field_record_label']['table'] = 'field_data_field_record_label';
  $handler->display->display_options['fields']['field_record_label']['field'] = 'field_record_label';
  $handler->display->display_options['fields']['field_record_label']['label'] = 'Label';
  $handler->display->display_options['fields']['field_record_label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_record_label']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_record_label']['hide_empty'] = TRUE;
  /* Field: Content: Matrix Number */
  $handler->display->display_options['fields']['field_matrix_number']['id'] = 'field_matrix_number';
  $handler->display->display_options['fields']['field_matrix_number']['table'] = 'field_data_field_matrix_number';
  $handler->display->display_options['fields']['field_matrix_number']['field'] = 'field_matrix_number';
  $handler->display->display_options['fields']['field_matrix_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_matrix_number']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_matrix_number']['hide_empty'] = TRUE;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Recording NID',
    ),
  );

  /* Display: Performer short */
  $handler = $view->new_display('panel_pane', 'Performer short', 'panel_pane_7');
  $handler->display->display_options['display_description'] = 'to use in the upper part of panel';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_artist_real_name' => 'field_artist_real_name',
    'field_composer' => 'field_composer',
    'field_accompaniment' => 'field_accompaniment',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Composer */
  $handler->display->display_options['fields']['field_composer']['id'] = 'field_composer';
  $handler->display->display_options['fields']['field_composer']['table'] = 'field_data_field_composer';
  $handler->display->display_options['fields']['field_composer']['field'] = 'field_composer';
  $handler->display->display_options['fields']['field_composer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_composer']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_composer']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_composer']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Accompaniment */
  $handler->display->display_options['fields']['field_accompaniment']['id'] = 'field_accompaniment';
  $handler->display->display_options['fields']['field_accompaniment']['table'] = 'field_data_field_accompaniment';
  $handler->display->display_options['fields']['field_accompaniment']['field'] = 'field_accompaniment';
  $handler->display->display_options['fields']['field_accompaniment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_accompaniment']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_accompaniment']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_accompaniment']['delta_offset'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Recording NID',
    ),
  );
  $export['recording_details'] = $view;

  $view = new view();
  $view->name = 'recording_top_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recording Top Page';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
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
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'recording' => 'recording',
  );

  /* Display: Label Info */
  $handler = $view->new_display('panel_pane', 'Label Info', 'panel_pane_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Record Label (field_record_label_t) */
  $handler->display->display_options['relationships']['field_record_label_t_tid']['id'] = 'field_record_label_t_tid';
  $handler->display->display_options['relationships']['field_record_label_t_tid']['table'] = 'field_data_field_record_label_t';
  $handler->display->display_options['relationships']['field_record_label_t_tid']['field'] = 'field_record_label_t_tid';
  $handler->display->display_options['relationships']['field_record_label_t_tid']['label'] = 'Label from field_record_label_t';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_record_label_t_tid';
  $handler->display->display_options['fields']['name']['label'] = 'Label';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Content: Catalog Number Alpha */
  $handler->display->display_options['fields']['field_catalog_number_alpha']['id'] = 'field_catalog_number_alpha';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['table'] = 'field_data_field_catalog_number_alpha';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['field'] = 'field_catalog_number_alpha';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['label'] = 'Catalog Number';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_catalog_number_alpha']['element_wrapper_type'] = 'span';
  $handler->display->display_options['fields']['field_catalog_number_alpha']['hide_empty'] = TRUE;
  /* Field: Content: Matrix Number */
  $handler->display->display_options['fields']['field_matrix_number']['id'] = 'field_matrix_number';
  $handler->display->display_options['fields']['field_matrix_number']['table'] = 'field_data_field_matrix_number';
  $handler->display->display_options['fields']['field_matrix_number']['field'] = 'field_matrix_number';
  $handler->display->display_options['fields']['field_matrix_number']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_matrix_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_matrix_number']['hide_empty'] = TRUE;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Composer */
  $handler = $view->new_display('panel_pane', 'Composer', 'panel_pane_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_composer' => 'field_composer',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Composer */
  $handler->display->display_options['fields']['field_composer']['id'] = 'field_composer';
  $handler->display->display_options['fields']['field_composer']['table'] = 'field_data_field_composer';
  $handler->display->display_options['fields']['field_composer']['field'] = 'field_composer';
  $handler->display->display_options['fields']['field_composer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_composer']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_composer']['settings'] = array(
    'link' => 1,
  );
  /* Field: Content: Label Song Type */
  $handler->display->display_options['fields']['field_label_song_type']['id'] = 'field_label_song_type';
  $handler->display->display_options['fields']['field_label_song_type']['table'] = 'field_data_field_label_song_type';
  $handler->display->display_options['fields']['field_label_song_type']['field'] = 'field_label_song_type';
  $handler->display->display_options['fields']['field_label_song_type']['label'] = 'Genre';
  $handler->display->display_options['fields']['field_label_song_type']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_label_song_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_label_song_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_label_song_type']['delta_offset'] = '0';
  /* Field: Content: Accompaniment */
  $handler->display->display_options['fields']['field_accompaniment']['id'] = 'field_accompaniment';
  $handler->display->display_options['fields']['field_accompaniment']['table'] = 'field_data_field_accompaniment';
  $handler->display->display_options['fields']['field_accompaniment']['field'] = 'field_accompaniment';
  $handler->display->display_options['fields']['field_accompaniment']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_accompaniment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_accompaniment']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_accompaniment']['delta_offset'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Subject */
  $handler = $view->new_display('panel_pane', 'Subject', 'panel_pane_3');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_composer' => 'field_composer',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Keyword */
  $handler->display->display_options['fields']['field_keyword']['id'] = 'field_keyword';
  $handler->display->display_options['fields']['field_keyword']['table'] = 'field_data_field_keyword';
  $handler->display->display_options['fields']['field_keyword']['field'] = 'field_keyword';
  $handler->display->display_options['fields']['field_keyword']['label'] = 'Subjects';
  $handler->display->display_options['fields']['field_keyword']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_keyword']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_keyword']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_keyword']['delta_offset'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $export['recording_top_page'] = $view;

  return $export;
}
