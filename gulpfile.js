const gulp = require('gulp');
const exec = require('child_process').exec;

const builds = [
    "gcc ./index.c -o ./index",
    "gcc ./source/Relatorios.c -o ./dist/Relatorios",
];


gulp.task('default', async function(){
    builds.forEach((build)=>{
        exec(build, function(stdout, stderr){
            //console.log(stdout);
            //console.log(stderr);
        });
    });
});

