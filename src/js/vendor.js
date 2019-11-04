// Require JQuery to variable
var jquery = require("jquery");

// Add to $ and jQuery on window
window.$ = window.jQuery = jquery;

// This line will include everything in bootstrap JS
require('../node_modules/bootstrap/dist/js/bootstrap');

// If you don't want this, comment above and include only as required below
//require('../node_modules/bootstrap/js/dist/alert');
//require('../node_modules/bootstrap/js/dist/button');
//require('../node_modules/bootstrap/js/dist/carousel');
//require('../node_modules/bootstrap/js/dist/collapse');
//require('../node_modules/bootstrap/js/dist/dropdown');
//require('../node_modules/bootstrap/js/dist/modal');
//require('../node_modules/bootstrap/js/dist/popover');
//require('../node_modules/bootstrap/js/dist/scrollspy');
//require('../node_modules/bootstrap/js/dist/tab');
//require('../node_modules/bootstrap/js/dist/toast');
//require('../node_modules/bootstrap/js/dist/tooltip');
//require('../node_modules/bootstrap/js/dist/util');