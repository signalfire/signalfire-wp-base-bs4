<?php get_header(); ?>
    <main class="main--page" role="main">
        <div class="container">
            <div class="row">
                <div class="col">
                    <?php
                    $context = Timber::get_context();
                    $context['post'] = Timber::get_post();
                    Timber::render('site/page/component.twig', $context);
                    ?>                
                </div>
            </div>
        </div>
    </main>
<?php get_footer(); ?>
