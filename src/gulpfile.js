'use strict';

var gulp = require('gulp');
var sass = require('gulp-sass');
var concat = require('gulp-concat');
var uglify = require('gulp-uglify');
var cssmin = require('gulp-cssmin');
//var foreach = require('gulp-foreach');

gulp.task('sass',function(){
    gulp.src('./sass/style.scss')
        .pipe(sass({outputStyle: 'compressed'}))
        .pipe(gulp.dest('../'));
});

gulp.task('js:vendor', function(){
    gulp.src([
        './node_modules/tether/dist/js/tether.js',
        './node_modules/bootstrap/dist/js/bootstrap.js'
    ])
    .pipe(concat('vendor.js'))
    .pipe(uglify())
    .pipe(gulp.dest('../build/js'))
});

gulp.task('js:site', function(){
    gulp.src([
    ])
    .pipe(concat('site.js'))
    .pipe(uglify())
    .pipe(gulp.dest('../build/js'))
});
