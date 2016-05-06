<?hh // strict
namespace FH;

final class Eqs_Make<T> implements Eq<T> {
    public function __construct(private (function(T, T): bool) $eq) { }

    public function eq(T $a, T $b): bool {
        return call_user_func($this->eq, $a, $b);
    }
}

final class Eqs {
    private function __construct() { }

    public static function make<T>((function(T, T): bool) $eq): Eq<T> {
        return new Eqs_Make($eq);
    }

    public static function contramap<TI, TO>(Eq<TO> $eq, (function(TI): TO) $f): Eq<TI> {
        return self::make(function($a, $b) use($eq, $f) {
            return $eq->eq($f($a), $f($b));
        });
    }

    public static function intEq(): Eq<int> {
        return self::make(($a, $b) ==> $a === $b);
    }

    public static function stringEq(): Eq<string> {
        return self::make(($a, $b) ==> $a === $b);
    }

    public static function vectorEq<T>(Eq<T> $elementEq): Eq<ImmVector<T>> {
        return self::make(function($a, $b) use($elementEq) {
            if ($a->count() !== $b->count()) {
                return false;
            }
            $n = $a->count();
            for ($i = 0; $i < $n; ++$i) {
                if (!$elementEq->eq($a[$i], $b[$i])) {
                    return false;
                }
            }
            return true;
        });
    }
}
