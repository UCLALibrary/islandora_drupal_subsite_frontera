<?php
/**
 * @file
 * ct_label.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ct_label_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'comment_label';
  $view->description = 'views that gather comments used in Recordings Panel';
  $view->tag = 'default';
  $view->base_table = 'comment';
  $view->human_name = 'Comment Label';
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
  $handler->display->display_options['fields']['comment_body']['alter']['html'] = TRUE;
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
  $export['comment_label'] = $view;

  $view = new view();
  $view->name = 'image_gallery_label_taxonomy';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Image Gallery Label (Taxonomy)';
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
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'label' => 'label',
  );
  /* Filter criterion: Field: Images (field_images:fid) */
  $handler->display->display_options['filters']['field_images_fid']['id'] = 'field_images_fid';
  $handler->display->display_options['filters']['field_images_fid']['table'] = 'field_data_field_images';
  $handler->display->display_options['filters']['field_images_fid']['field'] = 'field_images_fid';
  $handler->display->display_options['filters']['field_images_fid']['operator'] = 'not empty';

  /* Display: Label (taxonomy): images tab */
  $handler = $view->new_display('panel_pane', 'Label (taxonomy): images tab', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Taxonomy term: Term ID',
    ),
  );
  $export['image_gallery_label_taxonomy'] = $view;

  $view = new view();
  $view->name = 'label_artists_taxonomy';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Label Artists (Taxonomy)';
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
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Frontera: String with link */
  $handler->display->display_options['footer']['frontera_string_link']['id'] = 'frontera_string_link';
  $handler->display->display_options['footer']['frontera_string_link']['table'] = 'frontera';
  $handler->display->display_options['footer']['frontera_string_link']['field'] = 'frontera_string_link';
  $handler->display->display_options['footer']['frontera_string_link']['string'] = 'See all artists >>';
  $handler->display->display_options['footer']['frontera_string_link']['url'] = 'artists?f[0]=field_artist_label_tids:[tid]';
  /* Relationship: Referenced from field_artist_real_name */
  $handler->display->display_options['relationships']['reverse_field_artist_real_name_node']['id'] = 'reverse_field_artist_real_name_node';
  $handler->display->display_options['relationships']['reverse_field_artist_real_name_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_artist_real_name_node']['field'] = 'reverse_field_artist_real_name_node';
  $handler->display->display_options['relationships']['reverse_field_artist_real_name_node']['ui_name'] = 'Referenced from field_artist_real_name';
  $handler->display->display_options['relationships']['reverse_field_artist_real_name_node']['label'] = 'Referenced from field_artist_real_name';
  /* Relationship: Referenced from field_composer */
  $handler->display->display_options['relationships']['reverse_field_composer_node']['id'] = 'reverse_field_composer_node';
  $handler->display->display_options['relationships']['reverse_field_composer_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_composer_node']['field'] = 'reverse_field_composer_node';
  $handler->display->display_options['relationships']['reverse_field_composer_node']['ui_name'] = 'Referenced from field_composer';
  $handler->display->display_options['relationships']['reverse_field_composer_node']['label'] = 'Referenced from field_composer';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Artist Real Name */
  $handler->display->display_options['fields']['field_artist_real_name']['id'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['table'] = 'field_data_field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['field'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['group_type'] = 'count';
  $handler->display->display_options['fields']['field_artist_real_name']['label'] = '';
  $handler->display->display_options['fields']['field_artist_real_name']['element_label_colon'] = FALSE;
  /* Field: Content: Composer */
  $handler->display->display_options['fields']['field_composer']['id'] = 'field_composer';
  $handler->display->display_options['fields']['field_composer']['table'] = 'field_data_field_composer';
  $handler->display->display_options['fields']['field_composer']['field'] = 'field_composer';
  $handler->display->display_options['fields']['field_composer']['label'] = '';
  $handler->display->display_options['fields']['field_composer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_composer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_composer']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_composer']['group_column'] = 'entity_id';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
  );
  /* Filter criterion: Content: Record Label (field_record_label_t) */
  $handler->display->display_options['filters']['field_record_label_t_tid_1']['id'] = 'field_record_label_t_tid_1';
  $handler->display->display_options['filters']['field_record_label_t_tid_1']['table'] = 'field_data_field_record_label_t';
  $handler->display->display_options['filters']['field_record_label_t_tid_1']['field'] = 'field_record_label_t_tid';
  $handler->display->display_options['filters']['field_record_label_t_tid_1']['relationship'] = 'reverse_field_composer_node';
  $handler->display->display_options['filters']['field_record_label_t_tid_1']['value'] = array(
    0 => '17',
  );
  $handler->display->display_options['filters']['field_record_label_t_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_record_label_t_tid_1']['vocabulary'] = 'label';
  /* Filter criterion: Content: Record Label (field_record_label_t) */
  $handler->display->display_options['filters']['field_record_label_t_tid']['id'] = 'field_record_label_t_tid';
  $handler->display->display_options['filters']['field_record_label_t_tid']['table'] = 'field_data_field_record_label_t';
  $handler->display->display_options['filters']['field_record_label_t_tid']['field'] = 'field_record_label_t_tid';
  $handler->display->display_options['filters']['field_record_label_t_tid']['relationship'] = 'reverse_field_artist_real_name_node';
  $handler->display->display_options['filters']['field_record_label_t_tid']['value'] = array(
    0 => '17',
  );
  $handler->display->display_options['filters']['field_record_label_t_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_record_label_t_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_record_label_t_tid']['vocabulary'] = 'label';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 2;

  /* Display: Artists on Label */
  $handler = $view->new_display('panel_pane', 'Artists on Label', 'labels_artists_taxonomy_pane');
  $handler->display->display_options['display_description'] = 'lists of Artist names related to a given Label';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['argument_input'] = array(
    'field_record_label_t_tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Record Label (field_record_label_t)',
    ),
    'field_record_label_t_tid_1' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Record Label (field_record_label_t)',
    ),
  );
  $export['label_artists_taxonomy'] = $view;

  $view = new view();
  $view->name = 'label_recordings_taxonomy';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Label Recordings (Taxonomy)';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_artist_real_name' => 'field_artist_real_name',
  );
  /* Footer: Frontera: String with link */
  $handler->display->display_options['footer']['frontera_string_link']['id'] = 'frontera_string_link';
  $handler->display->display_options['footer']['frontera_string_link']['table'] = 'frontera';
  $handler->display->display_options['footer']['frontera_string_link']['field'] = 'frontera_string_link';
  $handler->display->display_options['footer']['frontera_string_link']['string'] = 'See all @total recordings >>';
  $handler->display->display_options['footer']['frontera_string_link']['url'] = 'songs?label=%1';
  /* Relationship: Content: Record Label (field_record_label_t) */
  $handler->display->display_options['relationships']['field_record_label_t_tid']['id'] = 'field_record_label_t_tid';
  $handler->display->display_options['relationships']['field_record_label_t_tid']['table'] = 'field_data_field_record_label_t';
  $handler->display->display_options['relationships']['field_record_label_t_tid']['field'] = 'field_record_label_t_tid';
  $handler->display->display_options['relationships']['field_record_label_t_tid']['label'] = 'Label from field_record_label_t';
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'field_record_label_t_tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_record_label_t_tid';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Artist Real Name */
  $handler->display->display_options['fields']['field_artist_real_name']['id'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['table'] = 'field_data_field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['field'] = 'field_artist_real_name';
  $handler->display->display_options['fields']['field_artist_real_name']['label'] = 'by';
  $handler->display->display_options['fields']['field_artist_real_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_artist_real_name']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_artist_real_name']['delta_offset'] = '0';
  /* Contextual filter: Content: Record Label (field_record_label_t) */
  $handler->display->display_options['arguments']['field_record_label_t_tid']['id'] = 'field_record_label_t_tid';
  $handler->display->display_options['arguments']['field_record_label_t_tid']['table'] = 'field_data_field_record_label_t';
  $handler->display->display_options['arguments']['field_record_label_t_tid']['field'] = 'field_record_label_t_tid';
  $handler->display->display_options['arguments']['field_record_label_t_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_record_label_t_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_record_label_t_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_record_label_t_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_record_label_t_tid']['summary_options']['items_per_page'] = '25';
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

  /* Display: lists of Recording related of a Label */
  $handler = $view->new_display('panel_pane', 'lists of Recording related of a Label', 'panel_pane_1');
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Frontera: String with link */
  $handler->display->display_options['footer']['frontera_string_link']['id'] = 'frontera_string_link';
  $handler->display->display_options['footer']['frontera_string_link']['table'] = 'frontera';
  $handler->display->display_options['footer']['frontera_string_link']['field'] = 'frontera_string_link';
  $handler->display->display_options['footer']['frontera_string_link']['string'] = 'See all @total recordings >>';
  $handler->display->display_options['footer']['frontera_string_link']['url'] = 'songs?f[]=field_record_label_t:[tid]';
  $handler->display->display_options['argument_input'] = array(
    'field_record_label_t_tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Record Label (field_record_label_t)',
    ),
  );
  $export['label_recordings_taxonomy'] = $view;

  $view = new view();
  $view->name = 'more_like_this__label';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_frontera_taxonomy_index';
  $view->human_name = 'More Like This - Label';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'More Like This - Label';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'search_api_index_frontera_taxonomy_index';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_entity'] = 1;
  /* Contextual filter: Search: More like this */
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['id'] = 'search_api_views_more_like_this';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['table'] = 'search_api_index_frontera_taxonomy_index';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['field'] = 'search_api_views_more_like_this';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['search_api_views_more_like_this']['fields'] = array(
    'field_label_artist_titles' => 'field_label_artist_titles',
    'field_label_song_titles' => 'field_label_song_titles',
  );
  /* Filter criterion: Indexed Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vocabulary']['id'] = 'vocabulary';
  $handler->display->display_options['filters']['vocabulary']['table'] = 'search_api_index_frontera_taxonomy_index';
  $handler->display->display_options['filters']['vocabulary']['field'] = 'vocabulary';
  $handler->display->display_options['filters']['vocabulary']['value'] = '10';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['more_like_this__label'] = $view;

  return $export;
}
