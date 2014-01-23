<?php

/**
 * Base sort handler for Frontera.
 *
 * @see: https://drupal.org/node/357079
 * @see: http://tanc.me/blog/2011/how-create-custom-views-handler
 *
 * @ingroup views_sort_handlers
 */
class views_frontera_handler_sort extends views_handler_sort {

  /**
   * Method unused atm. Its definition is required (else it will try to execute
   * the add_orderby method)
   */
  function query() {
    //i.e.: on the rand handler the "rand" method is added to the orderby
    //$this->query->add_orderby('rand');
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['frontera_pattern'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['frontera_pattern'] = array(
      '#type' => 'textfield',
      '#title' => t('Pattern'),
      '#description' => t('Add a sort by pattern. The pattern must be a numeric string that describe the order (i.e. 0 for the 1st enable bundle, 1 for the 2nd, and so on)'),
      '#default_value' => $this->options['frontera_pattern'],
    );
  }
}