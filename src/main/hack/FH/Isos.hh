<?hh // strict
namespace FH;

final class Isos_Make<TA, TB> implements Iso<TA, TB> {
    public function __construct(
        private (function(TA): TB) $a2b,
        private (function(TB): TA) $b2a
    ) { }

    public function a2b(TA $a): TB {
        return call_user_func($this->a2b, $a);
    }

    public function b2a(TB $b): TA {
        return call_user_func($this->b2a, $b);
    }
}

final class Isos {
    private function __construct() { }

    public static function make<TA, TB>(
        (function(TA): TB) $a2b,
        (function(TB): TA) $b2a
    ): Iso<TA, TB> {
        return new Isos_Make($a2b, $b2a);
    }

    public static function swap<TA, TB>(Iso<TA, TB> $i): Iso<TB, TA> {
        return self::make(inst_meth($i, 'b2a'), inst_meth($i, 'a2b'));
    }

    public static function guaranteedSuccess<T>(): Iso<Awkward<Uninhabited, T>, T> {
        return self::make(
            function($a) { return $a->awkward($u ==> $u->absurd(), F::id()); },
            function($b) { return Awkward::ok($b); }
        );
    }
}
