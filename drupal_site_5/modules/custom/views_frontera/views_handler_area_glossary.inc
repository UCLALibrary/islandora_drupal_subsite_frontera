<?php

class views_handler_area_glossary extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();

    $options['letter_range'] = array('default' => FALSE, 'bool' => TRUE);
    $options['show_count'] = array('default' => FALSE, 'bool' => TRUE);
    $options['show_all'] = array('default' => TRUE, 'bool' => TRUE);
    $options['all_path'] = array('default' => '');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['letter_range'] = array(
      '#type' => 'checkbox',
      '#title' => t('Letter range'),
      '#description' => t('If selected, uses a simple range of letters to show the glossary instead of the real results of the views.'),
      '#default_value' => $this->options['letter_range'],
    );

    $form['show_count'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show count'),
      '#description' => t('Add the count of the nodes for each letter of the glossary.'),
      '#default_value' => $this->options['show_count'],
    );

    $form['show_all'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show "All" word'),
      '#description' => t(''),
      '#default_value' => $this->options['show_all'],
    );

    $form['all_path'] = array(
      '#type' => 'textfield',
      '#title' => t('All Path'),
      '#default_value' => isset($this->options['all_path']) ? $this->options['all_path'] : '',
      '#description' => t('Specify a path for the "All" word if not using a display with it\'s own path (i.e. on blocks)'),
      '#field_prefix' => '<span dir="ltr">' . url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
      '#field_suffix' => '</span>&lrm;',
    );
  }

  function options_submit(&$form, &$form_state) {
    parent::options_submit($form, $form_state);
  }

  function render($empty = FALSE) {
    global $base_url;
    $letters = array();

    if (!isset($this->view->display[$this->view->current_display]->handler->options['path']) && empty($this->options['all_path'])) {
      drupal_set_message(t("The glossary cannot be shown if the path is empty"), 'error', FALSE);
      return '';
    }
    elseif (!empty($this->options['all_path'])) {
      $view_path = $base_url . '/' . $this->options['all_path'];
    }
    else {
      $view_path = $base_url . '/' . $this->view->display[$this->view->current_display]->handler->options['path'];
    }

    $attributes = array( 'class' => 'alpha-page' );

    // Add the "All" link
    if ($this->options['show_all']) {
      $output[] = l('All', $view_path . '/all', $attributes);
    }

    // Add a more simple range of letters. This speeds up the process but this
    // doesn't do checks on the letter's results.
    if (isset($this->options['letter_range']) && $this->options['letter_range']) {
      $letters = range('A', 'Z');
      foreach ($letters as $letter) {
        $output[] = l($letter, $view_path . '/' . $letter, $attributes);
      }
    }
    else {
      // $mtime = microtime();
      // $mtime = explode(" ",$mtime); 
      // $mtime = $mtime[1] + $mtime[0]; 
      // $starttime = $mtime; 

      // Alternative version: do a direct query
      $node_types = array();
      $vocs = array();

      foreach ($this->view->query->where as $where) {
        foreach ($where['conditions'] as $condition) {
          if ($this->view->base_table == 'node' &&
              isset($condition['field']) && $condition['field'] == 'node.type') {
            $node_types = $condition['value'];
          }

          if ($this->view->base_table == 'taxonomy_term_data' &&
            isset($condition['field']) && $condition['field'] == 'taxonomy_vocabulary.machine_name') {
              $vid = db_query("SELECT vid FROM {taxonomy_vocabulary} WHERE machine_name = :vname",
                array(':vname' => $condition['value'][0]))->fetchField();
              $vocs[] = $vid;
          }
        }
      }

      $results = array();

      if (!empty($node_types)) {
        $result = db_query("SELECT title from {node} WHERE status = '1' AND type IN (:node_types)", array(':node_types' => implode(',', $node_types)));
        $results = $result->fetchAll();
      }
      else if (!empty($vocs)) {
        $result = db_query("SELECT name from {taxonomy_term_data} WHERE vid IN (:vocs)", array(':vocs' => $vocs));
        $results = $result->fetchAll();
      }

      if (!empty($results)) {
        // Creates a Letter->Count array from the views result.
        foreach ($results as $data) {
          if (isset($data->title[0])) {
            $t = strtoupper($data->title[0]);
          }
          if (isset($data->name[0])) {
            $t = strtoupper($data->name[0]);
          }

          if (isset($t)) {
            $letters[$t] = isset($letters[$t]) ? intval($letters[$t]) + 1 : 1;
          }
        }

        ksort($letters);
      }

      // $mtime = microtime(); 
      // $mtime = explode(" ",$mtime); 
      // $mtime = $mtime[1] + $mtime[0]; 
      // $endtime = $mtime; 
      // $totaltime = ($endtime - $starttime); 
      // echo "This page was created in ".$totaltime." seconds"; 

/*      // Notes: Creates the glossary using only letters who have results
      // checking them in the original (cloned) view. This is done for each
      // call, so it can be slowly against the simple letter range.
      // -----------------------------------------------------------------------

      // get a cloned version of the view and set the current display
      $view = views_get_view($this->view->name);
      $view->set_display($this->view->current_display);

      // disable pagination, we need all rows
      $pager = $view->display_handler->get_option('pager');
      $pager['type'] = 'none';
      $view->display_handler->set_option('pager', $pager);

      $view->execute();

      if (count($view->result) == 0 || count($this->view->result) == 0)  {
        return '';
      }

      // Creates a Letter->Count array from the views result.
      foreach ($view->result as $result) {
        if (isset($result->node_title)) {
          $title = $result->node_title;
        }
        elseif (isset($result->taxonomy_term_data_name)) {
          $title = $result->taxonomy_term_data_name;
        }

        if (isset($title[0])) {
          $t = strtoupper($title[0]);
          $letters[$t] = isset($letters[$t]) ? intval($letters[$t]) + 1 : 1;
        }
      }

      ksort($letters);*/

      foreach ($letters as $letter => $count) {
        $args = (isset($this->view->args[0]) && $letter == $this->view->args[0]) ? array('attributes' => array('class' => 'active-link')) : array();

        $output[] = l($letter, $view_path . '/' . $letter, $args) . ($this->options['show_count'] ? " ($count)" : '');
      }
    }

    return "<div class='alpha-pager'>" . implode(' | ', $output ) . "</div>";
  }

}
