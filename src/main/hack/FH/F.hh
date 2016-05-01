<?hh // strict
namespace FH;

final class F {
    private function __construct() { }

    public static function id<T>(): (function(T): T) {
        return function($x) { return $x; };
    }

    public static function constant<TI, TO>(TO $x): (function(TI): TO) {
        return function($a) use($x) { return $x; };
    }
}
