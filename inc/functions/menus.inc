<?php

/**
 * Creates menus for the site
 */
function sfwpb_menus_register()
{
  register_nav_menus(
    array(
      'site-menu' => __('Site'),
    )
  );
}

add_action('init', 'sfwpb_menus_register');
