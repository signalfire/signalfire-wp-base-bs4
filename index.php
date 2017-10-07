<?php get_header(); ?>
    <main class="main--blog" role="main">
        <div class="container">
            <div class="row">
                <div class="col-12 col-sm-9">
                    <?php
                        $context = Timber::get_context();
                        $context['posts'] = new Timber\PostQuery(sfwpb_args_for_index());
                        $context['pagination'] = true;
                        Timber::render('post/list/component.twig', $context);
                    ?>
                </div>
                <div class="col-12 col-sm-3">
                    <div class="sidebar--blog">
                      <?php if ( dynamic_sidebar('sfwpb_blog_sidebar') ) : else : endif; ?>
                    </div>
                </div>
            </div>
        </div>
    </main>
<?php get_footer(); ?>
