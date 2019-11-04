<?php get_header(); ?>
    <main class="main--front-page" role="main">
        <div class="container">
            <div class="row">
                <div class="col-12">
                    <?php Timber::render('bootstrap/carousel/component.twig', [
                        'id' => 'carousel1',
                        'images' => [
                            ['url' => 'https://placeimg.com/1000/480/any?id=1', 'caption' => 'test1'],
                            ['url' => 'https://placeimg.com/1000/480/any?id=2', 'caption' => 'test2'],
                            ['url' => 'https://placeimg.com/1000/480/any?id=3', 'caption' => 'test3'],
                        ]
                    ]); ?>
                </div>
            </div>
        </div>
    </main>
<?php get_footer(); ?>
