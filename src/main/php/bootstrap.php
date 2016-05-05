<?php
$GLOBALS['HACKLIB_ROOT'] = '/opt/hack/usr/share/hhvm/hack/hacklib/hacklib.php';
function fun($fun) { return $fun; }
function inst_meth($inst, $meth) { return [$inst, $meth]; }
function class_meth($class, $meth) { return [$class, $meth]; }
function meth_caller($class, $meth) {
    return function($self, ...$args) use($meth) {
        return $self->$meth(...$args);
    };
}
require(__DIR__ . '/../../../vendor/autoload.php');
