<?php

/**
 * @file
 * Definition of views_frontera_handler_argument_string.
 */

/**
 * Extends the basic argument handler to implement string arguments
 *
 * @ingroup views_argument_handlers
 */
class views_frontera_handler_argument_string extends views_handler_argument_string {

  function init(&$view, &$options) {
    parent::init($view, $options);
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['show_all'] = array('default' => FALSE, 'bool' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['show_all'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show "All"'),
      '#description' => t('Add the word "All" to the glossary.'),
      '#default_value' => $this->options['show_all'],
      '#fieldset' => 'more',
    );
  }


}
