<?php

class views_frontera_plugin_query extends efq_views_plugin_query {

  /**
   * Executes the query and fills the associated view object with according
   * values.
   */
  function execute(&$view) {
    $query = $view->build_info['efq_query'];
    $count_query = $view->build_info['count_query'];
    $args = $view->build_info['query_args'];

    $query->addMetaData('view', $view);
    $count_query->addMetaData('view', $view);

    // Add the query tags.
    if (!empty($this->options['query_tags'])) {
      foreach ($this->options['query_tags'] as $tag) {
        $query->addTag($tag);
        $count_query->addTag($tag);
      }
    }

    $start = microtime(true);

    // if we are using the pager, calculate the total number of results
    if ($this->pager->use_pager()) {
      try {
        $this->pager->total_items = $count_query->execute();

        if (!empty($this->pager->options['offset'])) {
          $this->pager->total_items -= $this->pager->options['offset'];
        }

        $this->pager->update_page_info();
      }
      catch (Exception $e) {
        if (!empty($view->simpletest)) {
          throw($e);
        }
        // Show the full exception message in Views admin.
        if (!empty($view->live_preview)) {
          drupal_set_message($e->getMessage(), 'error');
        }
        else {
          vpr('Exception in @human_name[@view_name]: @message', array('@human_name' => $view->human_name, '@view_name' => $view->name, '@message' => $e->getMessage()));
        }
        return;
      }
    }

    // Let the pager set limit and offset.
    $this->pager->pre_execute($query, $args);

    if (!empty($this->limit) || !empty($this->offset)) {
      // We can't have an offset without a limit, so provide a very large limit instead.
      $limit  = intval(!empty($this->limit) ? $this->limit : 999999);
      $offset = intval(!empty($this->offset) ? $this->offset : 0);
      $query->range($offset, $limit);
    }

    $view->result = array();

    try {
      // We want to use the Fronteras' sort functionality
      //if (isset($view->style_plugin->options['pattern'])) { // this if was from the style just in case we need it
      if (isset($views->sort['frontera_sort']) && $view->sort['frontera_sort']->options['frontera_pattern']) {
        // get and convert the pattern string to array
        //$pattern = $view->style_plugin->options['pattern'];
        $pattern = $view->sort['frontera_sort']->options['frontera_pattern'];
        $pattern = str_split($pattern);

        $final_results = array();
        $query_temp = clone $query;

        if (isset($query->entityConditions['bundle'])) {
          foreach ($query->entityConditions['bundle']['value'] as $key => $bundle) {
            $query_temp->entityConditions['bundle']['value'] = array( $bundle );

            $results = $query_temp->execute();

            foreach ($results as $entity_type => $ids) {
              // This is later used for field rendering
              foreach (entity_load($entity_type, array_keys($ids)) as $entity_id => $entity) {
                $entity->entity_id = $entity_id;
                $entity->entity_type = $entity_type;
                $final_results[$bundle][] = $entity;
              }
            }
          }

          foreach ($pattern as $bundle_key) {
            if (isset($query->entityConditions['bundle']['value'][$bundle_key])) {
              $res_key = $query->entityConditions['bundle']['value'][$bundle_key];
              
              if (isset($final_results[$res_key]) && count($final_results[$res_key])) {
                $view->result[] = array_pop($final_results[$res_key]);
              }
            }
          }
        }
      }
      else {
        // Use the default EFQ code
        $results = $query->execute();

        //kpr($results);

        foreach ($results as $entity_type => $ids) {
          // This is later used for field rendering
          foreach (entity_load($entity_type, array_keys($ids)) as $entity_id => $entity) {
            $entity->entity_id = $entity_id;
            $entity->entity_type = $entity_type;
            $view->result[] = $entity;
          }
        }
      }


      $this->pager->post_execute($view->result);
      if ($this->pager->use_pager()) {
        $view->total_rows = $this->pager->get_total_items();
      }
    }
    catch (Exception $e) {
      // Show the full exception message in Views admin.
      if (!empty($view->live_preview)) {
        drupal_set_message($e->getMessage(), 'error');
      }
      else {
        vpr('Exception in @human_name[@view_name]: @message', array('@human_name' => $view->human_name, '@view_name' => $view->name, '@message' => $e->getMessage()));
      }
      return;
    }

    $view->execute_time = microtime(true) - $start;
  }

}
