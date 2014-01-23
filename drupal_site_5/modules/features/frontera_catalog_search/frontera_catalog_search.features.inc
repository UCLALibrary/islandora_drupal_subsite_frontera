<?php
/**
 * @file
 * frontera_catalog_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function frontera_catalog_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function frontera_catalog_search_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function frontera_catalog_search_default_search_api_index() {
  $items = array();
  $items['frontera_taxonomy_index'] = entity_import('search_api_index', '{
    "name" : "Frontera Taxonomy Index",
    "machine_name" : "frontera_taxonomy_index",
    "description" : null,
    "server" : "frontera_solr_server",
    "item_type" : "taxonomy_term",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "100",
      "fields" : {
        "tid" : { "type" : "integer" },
        "name" : { "type" : "string" },
        "node_count" : { "type" : "integer" },
        "vocabulary" : { "type" : "integer", "entity_type" : "taxonomy_vocabulary" },
        "search_api_language" : { "type" : "string" },
        "field_label_artists_count" : { "type" : "integer" },
        "field_label_recordings_count" : { "type" : "integer" },
        "field_label_images_count" : { "type" : "integer" },
        "field_label_artist_titles" : { "type" : "list\\u003Ctext\\u003E" },
        "field_label_song_titles" : { "type" : "list\\u003Ctext\\u003E" },
        "field_label_name_fulltext" : { "type" : "text" },
        "field_label_glossary_index" : { "type" : "string" },
        "field_entity_bundle" : { "type" : "string" },
        "field_label_genres" : { "type" : "list\\u003Ctext\\u003E" },
        "field_label_subjects" : { "type" : "list\\u003Ctext\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "label" : "label" } }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "frontera_catalog_search_label_index_fields" : { "status" : 1, "weight" : "0", "settings" : [] },
        "frontera_basic_search_recording_index_fields" : { "status" : 0, "weight" : "0", "settings" : [] },
        "frontera_basic_search_artist_index_fields" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "name" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "name" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "name" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}
