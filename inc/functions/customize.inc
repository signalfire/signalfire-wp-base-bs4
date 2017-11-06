<?php
/**
 * Registers custom sections and controls for modifing theme
 *
 * @param $wp_customize WP_Customizer
 */
function sfwpb_customize_register($wp_customize)
{
  // Register customisations here
}

add_action('customize_register', 'sfwpb_customize_register');
