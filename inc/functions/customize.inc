<?php

require_once get_template_directory() . '/inc/vendor/scssphp/scss.inc.php';

/**
 * Setup customization for bootstrap
 *
 * @param $wp_customize
 */
function sfwpb_customize_bootstrap_section($wp_customize)
{
  // Sections
  $wp_customize->add_section('sfwpb_bootstrap_section', [
    'title' => __('Bootstrap Customisation'),
    'description' => __('Add bootstrap customisation'),
    'priority' => 160,
  ]);

  $wp_customize->add_setting('sfwpb_bootstrap_variables', [
    'default' => '',
    'transport' => 'postMessage',
    'type' => 'theme_mod'
  ]);

  $wp_customize->add_setting('sfwpb_bootstrap_variables_copy', [
    'default' => '',
    'transport' => 'postMessage',
    'type' => 'theme_mod'
  ]);

  $wp_customize->add_control(new WP_Customize_Control(
    $wp_customize,
    'sfwpb_bootstrap_variables_control',
    [
      'type' => 'textarea',
      'label' => __('Sass Variables', 'sfwpb'),
      'section' => 'sfwpb_bootstrap_section',
      'settings' => 'sfwpb_bootstrap_variables',
      'priority' => 10
    ]
  ));

}

/**
 * Registers custom sections and controls for modifing theme
 *
 * @param $wp_customize WP_Customizer
 */
function sfwpb_customize_register($wp_customize)
{
  sfwpb_customize_bootstrap_section($wp_customize);
}

function sfwpb_regenerate_sass_variables()
{
  # Get the variables added
  if ($variables = get_theme_mod('sfwpb_bootstrap_variables', NULL)) {
    # Variables got, so write them to the variables file
    if (file_put_contents(get_template_directory() . '/src/sass/settings/_variables.scss', $variables)) {
      # Get the source of the main stylesheet
      $source = file_get_contents(get_template_directory() . '/src/sass/style.scss');
      # Create compiler
      $scss = new Leafo\ScssPhp\Compiler();
      $scss->setImportPaths(get_template_directory() . '/src/sass');
      try {
        # Attempt to compile sass with new variables
        $output = $scss->compile($source);
        # Save the output to style.css file
        file_put_contents(get_template_directory() . '/style.css', $output);
      } catch (Exception $ex) {
        sfwpb_write_log($ex);
      }
    }
  }
}


function sfwpb_save_after_customize($manager)
{
  # Check if the bootstrap_variables theme mod has been set
  if ($variables = get_theme_mod('sfwpb_bootstrap_variables', NULL)) {
    # It has so check a hashed version of it against a hashed version of the copy to check they arent the same
    if (md5($variables) !== md5(get_theme_mod('sfwpb_bootstrap_variables_copy', NULL))) {
      # They arent so cause the sass regeneration
      sfwpb_regenerate_sass_variables();
      set_theme_mod('sfwpb_bootstrap_variables_copy', $variables);
    }
  }
}

add_action('customize_register', 'sfwpb_customize_register');
add_action('customize_save_after', 'sfwpb_save_after_customize');