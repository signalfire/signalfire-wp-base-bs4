<?php

/**
 * Register plugins required for this theme
 */
function sfwpb_register_required_plugins()
{

  $plugins = array(
    [
      'name' => 'Timber',
      'slug' => 'timber-library',
      'required' => true,
    ],
    [
      'name' => 'Advanced Custom Fields',
      'slug' => 'advanced-custom-fields',
      'required' => true
    ]
  );

  $config = array(
    'id' => 'sfwpb',
    'default_path' => '',
    'menu' => 'tgmpa-install-plugins',
    'parent_slug' => 'themes.php',
    'capability' => 'edit_theme_options',
    'has_notices' => true,
    'dismissable' => true,
    'dismiss_msg' => '',
    'is_automatic' => false,
    'message' => '',
  );

  tgmpa($plugins, $config);
}

add_action('tgmpa_register', 'sfwpb_register_required_plugins');
