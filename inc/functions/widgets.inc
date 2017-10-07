<?php

/**
 * Register widgets
 */
function sfwbp_widgets_init()
{
  register_sidebar(
    array(
      'name' => 'Blog Sidebar',
      'id' => 'sfwpb_blog_sidebar',
      'before_widget' => '<div class="sidebar--widget %2$s">',
      'after_widget' => '</div>',
    )
  );
}

add_action( 'widgets_init', 'sfwbp_widgets_init' );
