<?php get_header(); ?>
    <main class="main--page" role="main">
        <div class="container">
            <div class="row">
                <div class="col-2"></div>
                <div class="col-10">
                  <?php
                  $context = Timber::get_context();
                  $context['post'] = Timber::get_post();
                  Timber::render('page/component.twig', $context);
                  ?>
                </div>
            </div>
        </div>
    </main>
<?php get_footer(); ?>