<?php get_header(); ?>
    <main class="main--post" role="main">
        <div class="container">
            <div class="row">
                <div class="col-12">
                  <?php
                  $context = Timber::get_context();
                  $context['post'] = Timber::get_post();
                  Timber::render('site/post/full/component.twig', $context);
                  ?>
                </div>
            </div>
        </div>
    </main>
<?php get_footer(); ?>
