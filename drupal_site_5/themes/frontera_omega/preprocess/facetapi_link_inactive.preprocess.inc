<?php
/*
 * Implements template_preprocess_facetapi_link_inactive().
 *
 * Remove the count from Facet links.
 * https://drupal.org/node/1615434
 */
function frontera_omega_preprocess_facetapi_link_inactive(&$variables) {
  unset($variables['count']);
}
