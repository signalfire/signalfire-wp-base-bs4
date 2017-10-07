<?php

/**
 * Gets the current url of a page
 *
 * @return string
 */
function sfwpb_current_url()
{
  global $wp;
  return home_url(add_query_arg(array(), $wp->request));
}

/**
 * Log message to the error log
 * @param array|object $log
 */
function sfwpb_write_log($log)
{
  if (is_array($log) || is_object($log)) {
    error_log(print_r($log, true));
  } else {
    error_log($log);
  }
}

/**
 * Get arguments for number of posts per page and if results should be paged
 *
 * @param null $args
 * @return array
 */
function sfwpb_args_for_index($args = [])
{
  global $paged;
  if (!isset($paged) || !$paged) {
    $paged = 1;
  }
  return array_merge($args, [
    'posts_per_page' => (int)get_option('posts_per_page'),
    'paged' => $paged
  ]);
}