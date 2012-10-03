<?php

/**
 * Implements hook_wysiwyg_editor_settings_alter().
 * Check the css_content WYSIWYG setting for LESS files and replace with 
 * generated CSS files where necessary.
 */
function less_wysiwyg_editor_settings_alter(&$settings, $context) {
  
  $wysiwyg = NULL;
  $stylesheets = array();
  
  // Figure out which WYSIWYG is in use, each has their own list of stylesheets.
  if (isset($settings['content_css'])) {
    $wysiwyg = 'tinymce';
    $stylesheets = explode(',', $settings['content_css']);
  }
  elseif (isset($settings['EditorAreaCSS'])) {
    $wysiwyg = 'fckeditor';
    $stylesheets = explode(',', $settings['EditorAreaCSS']);
  }
  elseif (isset($settings['contentsCss'])) {
    $wysiwyg = 'ckeditor';
    $stylesheets = $settings['contentsCss'];
  }
  
  if (!empty($stylesheets)) {
    
    $styles = array(
      '#items' => array(),
    );
    
    foreach ($stylesheets as $css_file) {
      $styles['#items'][$css_file] = array(
        'data' => trim($css_file, '/'),
      );
    }
    
    $styles = _less_pre_render($styles);

    $stylesheets = array();

    foreach ($styles['#items'] as $file) {
      $stylesheets[] = file_create_url($file['data']);
    }
    
  }
  
  switch ($wysiwyg) {
    case 'tinymce':
      $settings['content_css'] = implode(',', $stylesheets);
      break;
    case 'fckeditor':
      $settings['EditorAreaCSS'] = implode(',', $stylesheets);
      break;
    case 'ckeditor':
      $settings['contentsCss'] = $stylesheets;
      break;
  }
  
}

function less_form_wysiwyg_profile_form_alter(&$form, $form_state, $form_id) {
  $form['css']['css_path']['#description'] .= '<br />' . t('You may enter a path to a LESS file and it will be parsed automatically.');
}
