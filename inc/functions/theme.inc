<?php

require_once get_template_directory() . '/inc/vendor/scssphp/scss.inc.php';

/**
 * Create image sizes
 */
function sfwpb_image_sizes()
{
  add_image_size( 'letterbox', 1200, 400, true );
}

/**
 * Add support for various theme bits
 */
function sfwpb_theme_setup()
{
    add_theme_support( 'html5', array( 'comment-list', 'comment-form', 'search-form' ) );
    add_theme_support( 'post-thumbnails' );
    sfwpb_image_sizes();
}

add_action( 'after_setup_theme', 'sfwpb_theme_setup' );
add_filter( 'wp_calculate_image_srcset_meta', '__return_null' );
