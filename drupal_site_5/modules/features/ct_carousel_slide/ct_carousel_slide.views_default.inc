<?php
/**
 * @file
 * ct_carousel_slide.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ct_carousel_slide_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'homepage_carousel';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Homepage Carousel';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'flexslider_views_slideshow';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
    'field_carousel_slide_link' => 0,
    'field_carousel_slide_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
    'field_carousel_slide_link' => 0,
    'field_carousel_slide_image' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_carousel_slide_image']['id'] = 'field_carousel_slide_image';
  $handler->display->display_options['fields']['field_carousel_slide_image']['table'] = 'field_data_field_carousel_slide_image';
  $handler->display->display_options['fields']['field_carousel_slide_image']['field'] = 'field_carousel_slide_image';
  $handler->display->display_options['fields']['field_carousel_slide_image']['label'] = '';
  $handler->display->display_options['fields']['field_carousel_slide_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_carousel_slide_image']['alter']['path'] = '[field_carousel_slide_link]';
  $handler->display->display_options['fields']['field_carousel_slide_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_carousel_slide_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_carousel_slide_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_carousel_slide_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_carousel_slide_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_carousel_slide_image']['settings'] = array(
    'image_style' => 'carousel_slide',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_carousel_slide_image']['field_api_classes'] = TRUE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['field_carousel_slide_link']['id'] = 'field_carousel_slide_link';
  $handler->display->display_options['fields']['field_carousel_slide_link']['table'] = 'field_data_field_carousel_slide_link';
  $handler->display->display_options['fields']['field_carousel_slide_link']['field'] = 'field_carousel_slide_link';
  $handler->display->display_options['fields']['field_carousel_slide_link']['label'] = '';
  $handler->display->display_options['fields']['field_carousel_slide_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_carousel_slide_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_carousel_slide_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_carousel_slide_link']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_carousel_slide_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_carousel_slide_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_carousel_slide_link']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_carousel_slide_link]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'carousel_slide' => 'carousel_slide',
  );

  /* Display: Carousel Slides */
  $handler = $view->new_display('panel_pane', 'Carousel Slides', 'homepage_carousel_slides_pane');
  $export['homepage_carousel'] = $view;

  return $export;
}
