<?php
/**
 * @file
 * frontera_basic_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function frontera_basic_search_ctools_plugin_api() {
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
function frontera_basic_search_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_autocomplete_search().
 */
function frontera_basic_search_default_search_api_autocomplete_search() {
  $items = array();
  $items['search_api_views_catalog_songs_solr'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_catalog_songs_solr",
    "name" : "Catalog Songs Solr",
    "index_id" : "frontera_basic_index",
    "type" : "search_api_views",
    "enabled" : "0",
    "options" : {
      "result count" : true,
      "fields" : [],
      "results" : 0,
      "custom" : { "display" : "default" }
    }
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function frontera_basic_search_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : null,
    "item_type" : "node",
    "options" : {
      "cron_limit" : "50",
      "data_alter_callbacks" : { "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] } },
      "processors" : {
        "search_api_case_ignore" : { "status" : 1, "weight" : "0", "settings" : { "strings" : 0 } },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\nh2 = 3\\nh3 = 2\\nstrong = 2\\nb = 2\\nem = 1.5\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : { "spaces" : "[^\\\\p{L}\\\\p{N}]", "ignorable" : "[-]" }
        }
      },
      "fields" : {
        "type" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "promote" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "comment_count" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "body:value" : { "type" : "text" }
      }
    },
    "enabled" : "0",
    "read_only" : "0"
  }');
  $items['frontera_basic_index'] = entity_import('search_api_index', '{
    "name" : "Frontera basic index",
    "machine_name" : "frontera_basic_index",
    "description" : "Frontera basic search index for all node types.",
    "server" : "frontera_solr_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "type" : { "type" : "string" },
        "title" : { "type" : "string" },
        "field_alternative_names" : { "type" : "list\\u003Ctext\\u003E" },
        "field_biography" : { "type" : "text" },
        "field_accompaniment" : { "type" : "list\\u003Ctext\\u003E" },
        "field_artist_on_label" : { "type" : "text" },
        "field_artist_real_name" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_cat_number_sort" : { "type" : "text" },
        "field_catalog_number_alpha" : { "type" : "string" },
        "field_composer" : { "type" : "integer", "entity_type" : "node" },
        "field_condition" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_holding" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_keyword" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_label_song_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_matrix_number" : { "type" : "text" },
        "field_matrix_number_computed" : { "type" : "text" },
        "field_notes" : { "type" : "text" },
        "field_record_label_t" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_recording_location" : { "type" : "text" },
        "field_side" : { "type" : "string" },
        "field_styli" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_time" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "field_title_fulltext" : { "type" : "text" },
        "field_recording_album_fulltext" : { "type" : "text" },
        "field_recording_artist_name_fulltext" : { "type" : "list\\u003Ctext\\u003E" },
        "field_recording_label_fulltext" : { "type" : "text" },
        "field_recording_title_fulltext" : { "type" : "text" },
        "field_recording_genre" : { "type" : "list\\u003Ctext\\u003E" },
        "field_recording_subject" : { "type" : "list\\u003Ctext\\u003E" },
        "field_recording_artist_name_string" : { "type" : "string" },
        "field_recording_label_string" : { "type" : "string" },
        "field_recording_composer_string" : { "type" : "string" },
        "field_recording_glossary_index" : { "type" : "string" },
        "field_entity_bundle" : { "type" : "string" },
        "field_artist_composed_count" : { "type" : "integer" },
        "field_artist_recordings_count" : { "type" : "integer" },
        "field_artist_images_count" : { "type" : "integer" },
        "field_artist_song_titles" : { "type" : "list\\u003Ctext\\u003E" },
        "field_artist_artist_name" : { "type" : "text" },
        "field_artist_glossary_index" : { "type" : "string" },
        "field_artist_labels" : { "type" : "list\\u003Ctext\\u003E" },
        "field_artist_label_tids" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_artist_genres" : { "type" : "list\\u003Ctext\\u003E" },
        "field_artist_subjects" : { "type" : "list\\u003Ctext\\u003E" },
        "body:value" : { "type" : "text" },
        "body:summary" : { "type" : "text" },
        "field_artist_real_name:title" : { "type" : "list\\u003Ctext\\u003E" },
        "field_artist_real_name:field_alternative_names" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_artist_real_name:field_biography" : { "type" : "list\\u003Ctext\\u003E" },
        "field_keyword:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_keyword:description" : { "type" : "list\\u003Ctext\\u003E" },
        "field_record_label_t:tid" : { "type" : "integer" },
        "field_record_label_t:name" : { "type" : "text" },
        "field_record_label_t:description" : { "type" : "text" },
        "field_record_label_t:field_country" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_styli:name" : { "type" : "text" },
        "field_styli:description" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "blog" : "blog",
              "container" : "container",
              "name" : "name",
              "promotional" : "promotional",
              "recording" : "recording"
            }
          }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "frontera_basic_search_artist_index_fields" : { "status" : 1, "weight" : "0", "settings" : [] },
        "frontera_catalog_search_label_index_fields" : { "status" : 0, "weight" : "0", "settings" : [] },
        "frontera_basic_search_recording_index_fields" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true },
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
            "fields" : { "title" : true },
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
