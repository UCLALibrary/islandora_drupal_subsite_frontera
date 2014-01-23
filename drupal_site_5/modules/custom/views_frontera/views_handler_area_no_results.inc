<?php

class views_handler_area_no_results extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();

    $options['alert_message'] = array('default' => '' );
    $options['message_type'] = array('default' => '');
    $options['class'] = array('default' => '');

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['alert_message'] = array(
      '#type' => 'textfield',
      '#title' => t('Alert Message'),
      '#default_value' => isset($this->options['alert_message']) ? $this->options['alert_message'] : '',
      '#description' => t('String used to display an alert message. You can use "Replacement patterns" below and the @searchedterm token.'),
    );

    // Show a list of available message type
    $form['message_type'] = array(
      '#type' => 'select',
      '#title' => t('Message Type'),
      '#default_value' => $this->options['message_type'],
      '#description' => t('The view to insert into this area.'),
      '#options' => array(
        '' => t('-Select-'),
        'drupal_alert' => t('Drupal Set Message style'),
        'div' => t('Div'),
        'span' => t('Span')
      ),
    );

    $form['class'] = array(
      '#type' => 'textfield',
      '#title' => t('Class'),
      '#default_value' => isset($this->options['class']) ? $this->options['class'] : '',
      '#description' => t('Add a class into the HTML elements from the Message Type.'),
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

  function render($empty = FALSE) {
    if (!empty($this->options['alert_message'])) {
      // identify searched terms
      $searchedterm_a = array();
      foreach ($this->view->exposed_raw_input as $key => $value) {
        if (!empty($value))
          $searchedterm_a[] = $key . ':' . $value;
      }

      // make a string of searched terms
      $searchedterm = implode(' & ', $searchedterm_a);

      $alert_message = check_plain($this->options['alert_message']);

      if (!empty($searchedterm)) {
        // replace the @total token
        if (strpos($alert_message, '@searchedterm') !== false) {
          $alert_message = str_replace('@searchedterm', $searchedterm, $alert_message);
        }
      }
      else {
        return '';
      }

      // replace standard tokens
      $alert_message = $this->view->style_plugin->tokenize_value($alert_message, 0);

      // add a class if any
      $class = isset($this->options['message_type']) ? ' class="' . $this->options['message_type'] . '" ' : '';

      // construct results
      switch ($this->options['message_type']) {
        case 'div':
          return '<div'.$class.'>' . t($alert_message) . '</div>';
        case 'span':
          return '<span'.$class.'>' . t($alert_message) . '</span>';
        default:
          drupal_set_message(t($alert_message), 'error', FALSE);

          // if view is ajaxified, force a status message div
          if ($this->view->use_ajax) {
            if ($alert_message = theme('status_messages')) {
              return '<div class="views-messages">' . $alert_message . '</div>';
            }
          }
      }
    }
    else {
      return '';
    }
  }
}