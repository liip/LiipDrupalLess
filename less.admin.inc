<?php

/**
 * @file
 * Contains the administration pages for LESS.
 *
 */

function less_settings($form, &$form_state) {

  $form['less_flush'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#value' => 'Click this button regenerate all LESS files once.',
  );

  $form['less_flush']['flush'] = array(
    '#type' => 'submit',
    '#submit' => array('_flush_less'),
    '#value' => 'Flush LESS files',
  );

  $form['less_devel'] = array(
    '#type' => 'checkbox',
    '#title' => t('LESS developer mode'),
    '#description' => t('Enable the developer mode to ensure LESS files are regenerated every page load, regardless of any change done to the LESS file (which may happen when using the @import notation, and changing only the imported file). Note that this setting does not override "Optimize CSS files" if set via <a href="@performance-url">Performance</a>.', array('@performance-url' => url('admin/config/development/performance'))),
    '#default_value' => variable_get('less_devel', FALSE),
  );
  
  $form['#submit'] = array('less_settings_submit');
  
  return system_settings_form($form);
}

function less_settings_submit($form, &$form_state) {
  cache_clear_all('less:devel:', 'cache', TRUE);
  cache_clear_all('less:watch:', 'cache', TRUE);
}

function _flush_less($form, &$form_state) {

  _less_get_dir(TRUE);
  cache_clear_all('less:', 'cache', TRUE);

  drupal_set_message(t('LESS files cache cleared.'), 'status');
}
