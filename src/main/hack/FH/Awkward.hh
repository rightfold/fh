<?hh // strict
namespace FH;

final class Awkward<+TError, +TOk> {
    private function __construct(
        private bool $isOk,
        private TError $error,
        private TOk $ok
    ) { }

    public static function error(TError $error): Awkward<TError, TOk> {
        return new Awkward(false, $error, /* UNSAFE_EXPR */ null);
    }

    public static function ok(TOk $ok): Awkward<TError, TOk> {
        return new Awkward(true, /* UNSAFE_EXPR */ null, $ok);
    }

    public function awkward<TR>((function(TError): TR) $onError, (function(TOk): TR) $onOk): TR {
        if ($this->isOk) {
            return $onOk($this->ok);
        } else {
            return $onError($this->error);
        }
    }

    public function map<TM>((function(TOk): TM) $f): Awkward<TError, TM> {
        if ($this->isOk) {
            return Awkward::ok($f($this->ok));
        } else {
            return Awkward::error($this->error);
        }
    }
}
