<?php

class views_handler_area_string_link extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();

    $options['string'] = array('default' => '' );
    $options['url'] = array('default' => '' );
    $options['hide_if_total_smaller_than_pager'] = array('default' => FALSE, 'bool' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['string'] = array(
      '#type' => 'textfield',
      '#title' => t('String'),
      '#default_value' => isset($this->options['string']) ? $this->options['string'] : '',
      '#description' => t('String used as link text. You can use "Replacement patterns" below and the @total token.'),
    );

    $form['url'] = array(
      '#type' => 'textfield',
      '#title' => t('Full URL'),
      '#default_value' => isset($this->options['url']) ? $this->options['url'] : '',
      '#description' => t('The base URL with its arguments (i.e. key1=val1&key2=val2...) used to generate the link. You can use "Replacement patterns" below. '),
    );

    $form['hide_if_total_smaller_than_pager'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide if @total < max pager'),
      '#default_value' => $this->options['hide_if_total_smaller_than_pager'],
    );


    // Get a list of the available fields and arguments for token replacement.
    $options = array();
    foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
      $options[t('Fields')]["[$field]"] = $handler->ui_name();
    }

    $count = 0; // This lets us prepare the key as we want it printed.
    foreach ($this->view->display_handler->get_handlers('argument') as $arg => $handler) {
      $options[t('Arguments')]['%' . ++$count] = t('@argument title', array('@argument' => $handler->ui_name()));
      $options[t('Arguments')]['!' . $count] = t('@argument input', array('@argument' => $handler->ui_name()));
    }

    if (!empty($options)) {
      $output = '<p>' . t('The following tokens are available. If you would like to have the characters \'[\' and \']\' please use the html entity codes \'%5B\' or  \'%5D\' or they will get replaced with empty space.' . '</p>');
      foreach (array_keys($options) as $type) {
        if (!empty($options[$type])) {
          $items = array();
          foreach ($options[$type] as $key => $value) {
            $items[] = $key . ' == ' . check_plain($value);
          }
          $output .= theme('item_list',
            array(
              'items' => $items,
              'type' => $type
            ));
        }
      }
      $form['token_help'] = array(
        '#type' => 'fieldset',
        '#title' => t('Replacement patterns'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        '#value' => $output,
        '#id' => 'edit-options-token-help',
        '#dependency' => array(
          'edit-options-tokenize' => array(1),
        ),
        '#prefix' => '<div>',
        '#suffix' => '</div>',
      );
    }
  }

  function options_submit(&$form, &$form_state) {
    parent::options_submit($form, $form_state);
  }

  function render($empty = FALSE) {
    global $base_url;
    $total = $this->view->total_rows;

    if (empty($this->options['string']) || empty($this->options['url'])) {
      return "You must specify a string and its link!";
    }

    if ($this->options['hide_if_total_smaller_than_pager']) {
      if (!isset($this->view->query->limit) || $total < $this->view->query->limit) { 
        return '';
      }
    }

    // replace the @total token
    if (strpos($this->options['string'], '@total') !== false) {
      $string = str_replace('@total', $total, $this->options['string']);
    }
    else {
      $string = $this->options['string'];
    }

    // replace other standard tokens
    $tokenized_string = $this->view->style_plugin->tokenize_value($string, 0);
    $tokenized_url = $this->view->style_plugin->tokenize_value($this->options['url'], 0);
    // add optional path
    $parsed_url = drupal_parse_url($tokenized_url);
    return l($tokenized_string, $parsed_url['path'], array('query' => $parsed_url['query'], 'absolute' => TRUE));
  }

}
