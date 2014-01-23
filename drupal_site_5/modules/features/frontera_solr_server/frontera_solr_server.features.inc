<?php
/**
 * @file
 * frontera_solr_server.features.inc
 */


/**
 * Implements hook_default_search_api_server().
 */
function frontera_solr_server_default_search_api_server() {
  $items = array();
  $items['frontera_solr_server'] = entity_import('search_api_server', '{
    "name" : "Solr (dev)",
    "machine_name" : "frontera_solr_server",
    "description" : "Solr server used to index Frontera content.",
    "class" : "search_api_solr_service",
    "options" : {
      "scheme" : "http",
      "host" : "sky.bluespark.com",
      "port" : "8080",
      "path" : "\\/solr\\/fronteradev",
      "http_user" : "bluespark",
      "http_pass" : "oleole512",
      "excerpt" : 1,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "http_method" : "POST",
      "autocorrect_spell" : 1,
      "autocorrect_suggest_words" : 1
    },
    "enabled" : "1"
  }');
  return $items;
}
