<?hh // strict
namespace FH;

final class Awkward<TError, +TOk> {
    private function __construct(
        private bool $isOk,
        private mixed $value
    ) { }

    public static function error(TError $error): Awkward<TError, TOk> {
        return new Awkward(false, $error);
    }

    public static function ok(TOk $ok): Awkward<TError, TOk> {
        return new Awkward(true, $ok);
    }

    public function awkward<TR>((function(TError): TR) $onError, (function(TOk): TR) $onOk): TR {
        if ($this->isOk) {
            return $onOk(/* UNSAFE_EXPR */ $this->value);
        } else {
            return $onError(/* UNSAFE_EXPR */ $this->value);
        }
    }

    public function map<TM>((function(TOk): TM) $f): Awkward<TError, TM> {
        if ($this->isOk) {
            return Awkward::ok($f(/* UNSAFE_EXPR */ $this->value));
        } else {
            return Awkward::error(/* UNSAFE_EXPR */ $this->value);
        }
    }

    public function bind<TOk2>((function(TOk): Awkward<TError, TOk2>) $f): Awkward<TError, TOk2> {
        if ($this->isOk) {
            return $f(/* UNSAFE_EXPR */ $this->value);
        } else {
            return Awkward::error(/* UNSAFE_EXPR */ $this->value);
        }
    }
}
