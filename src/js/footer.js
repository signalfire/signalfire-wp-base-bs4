(function ($) {
    $(document).ready(function () {
        $(window).resize(function(){
            resizeFooter($);
        });
        resizeFooter($);
    });
})(jQuery);