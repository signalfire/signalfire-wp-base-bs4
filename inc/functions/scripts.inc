<?php

/**
 * Enqueue scripts and styles
 */
function sfwpb_enqueue_scripts_styles()
{
  if (!is_admin()) {
    if (file_exists(get_template_directory() . '/build/js/vendor.js')) {
      wp_enqueue_script('vendor-js', get_bloginfo('template_directory') . '/build/js/vendor.js');
    }

    if (file_exists(get_template_directory() . '/build/js/site.js')) {
      wp_enqueue_script('site-js', get_bloginfo('template_directory') . '/build/js/site.js', ['vendor-js']);
    }

    wp_enqueue_style('style', get_stylesheet_uri());

    if (file_exists(get_template_directory() . '/build/css/vendor.css')) {
      wp_enqueue_style('vendor-css', get_bloginfo('template_directory') . '/build/css/vendor.css');
    }
  
    wp_deregister_script('jquery');

  }
}

add_action( 'wp_enqueue_scripts', 'sfwpb_enqueue_scripts_styles' );
