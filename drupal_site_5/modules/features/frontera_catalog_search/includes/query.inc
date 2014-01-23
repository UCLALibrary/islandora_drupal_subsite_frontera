<?php

/**
 * Views query class using a Search API index as the data source.
 */
class FronteraSearchApiViewsQuery extends SearchApiViewsQuery {
  /**
   * Helper function for adding results to a view in the format expected by the
   * view.
   */
  protected function addResults(array $results, $view) {
    $rows = array();
    $missing = array();
    $items = array();

    // First off, we try to gather as much field values as possible without
    // loading any items.
    foreach ($results as $id => $result) {
      if (!empty($this->options['entity_access'])) {
        $entity = entity_load($this->index->item_type, array($id));
        if (!entity_access('view', $this->index->item_type, $entity[$id])) {
          continue;
        }
      }
      $row = array();

      // Include the loaded item for this result row, if present, or the item
      // ID.
      if (!empty($result['entity'])) {
        $row['entity'] = $result['entity'];
      }
      else {
        $row['entity'] = $id;
      }

      $row['_entity_properties']['search_api_relevance'] = $result['score'];
      $row['_entity_properties']['search_api_excerpt'] = empty($result['excerpt']) ? '' : $result['excerpt'];

      // Gather any fields from the search results.
      if (!empty($result['fields'])) {
        $row['_entity_properties'] += $result['fields'];
      }

      // Check whether we need to extract any properties from the result item.
      $missing_fields = array_diff_key($this->fields, $row);
      if ($missing_fields) {
        $missing[$id] = $missing_fields;
        if (is_object($row['entity'])) {
          $items[$id] = $row['entity'];
        }
        else {
          $ids[] = $id;
        }
      }

      // Save the row values for adding them to the Views result afterwards.
      $rows[$id] = (object) $row;
    }

    // Load items of those rows which haven't got all field values, yet.
    if (!empty($ids)) {
      $items += $this->index->loadItems($ids);
      // $items now includes loaded items, and those already passed in the
      // search results.
      foreach ($items as $id => $item) {
        // Extract item properties.
        $wrapper = $this->index->entityWrapper($item, FALSE);
        $rows[$id]->_entity_properties += $this->extractFields($wrapper, $missing[$id]);
        $rows[$id]->entity = $item;
      }
    }

    // Finally, add all rows to the Views result set.
    $view->result = array_values($rows);
  }
}
