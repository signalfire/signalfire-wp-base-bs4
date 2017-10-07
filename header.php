<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name='viewport' content='width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no' />
        <title><?php wp_title('');?></title>
        <link rel="stylesheet" href="<?php bloginfo('stylesheet_url'); ?>">
        <link rel="shortcut icon" type="image/x-icon" href="<?php bloginfo('template_url');?>/assets/img/favicon.ico">
        <?php wp_head();?>
    </head>
    <body>
        <?php Timber::render('bootstrap/navbar/component.twig', [
            'url' => sfwpb_current_url(),
            'menu' => new TimberMenu('main-menu')
        ]); ?>