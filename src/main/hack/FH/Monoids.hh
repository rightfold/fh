<?hh // strict
namespace FH;

final class Monoids_Make<T> implements Monoid<T> {
    public function __construct(
        private (function(T, T): T) $append,
        private T $appendId
    ) { }

    public function append(T $a, T $b): T {
        return call_user_func($this->append, $a, $b);
    }

    public function appendId(): T {
        return $this->appendId;
    }
}

final class Monoids {
    private function __construct() { }

    public static function make<T>((function(T, T): T) $append, T $appendId): Monoid<T> {
        return new Monoids_Make($append, $appendId);
    }

    public static function concat<T>(Monoid<T> $m, Traversable<T> $xs): T {
        $r = $m->appendId();
        foreach ($xs as $x) {
            $r = $m->append($r, $x);
        }
        return $r;
    }

    public static function boolAnd(): Monoid<bool> {
        return self::make(($a, $b) ==> $a && $b, true);
    }

    public static function boolOr(): Monoid<bool> {
        return self::make(($a, $b) ==> $a || $b, false);
    }

    public static function intAdd(): Monoid<int> {
        return self::make(($a, $b) ==> $a + $b, 0);
    }

    public static function intMul(): Monoid<int> {
        return self::make(($a, $b) ==> $a * $b, 1);
    }

    public static function stringConcat(): Monoid<string> {
        return self::make(($a, $b) ==> $a . $b, '');
    }

    public static function vectorConcat<T>(): Monoid<ImmVector<T>> {
        return self::make(($a, $b) ==> $a->concat($b), ImmVector{});
    }
}
