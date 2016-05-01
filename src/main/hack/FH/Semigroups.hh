<?hh // strict
namespace FH;

final class Semigroups {
    private function __construct() { }

    public static function make<T>((function(T, T): T) $append): Semigroup<T> {
        return new Monoids_Make($append, /* UNSAFE_EXPR */ null);
    }

    public static function intAdd(): Semigroup<int> {
        return Monoids::intAdd();
    }

    public static function intMul(): Semigroup<int> {
        return Monoids::intMul();
    }
}
