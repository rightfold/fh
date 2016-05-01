<?hh // strict
namespace FH;

final class Option<+T> {
    private function __construct(private bool $present, private T $value) { }

    public static function none(): Option<T> {
        return new Option(false, /* UNSAFE_EXPR */ null);
    }

    public static function some(T $x): Option<T> {
        return new Option(true, $x);
    }

    public function map<TM>((function(T): TM) $f): Option<TM> {
        if ($this->present) {
            return Option::some($f($this->value));
        } else {
            return Option::none();
        }
    }

    public function bind<TM>((function(T): Option<TM>) $f): Option<TM> {
        if ($this->present) {
            return $f($this->value);
        } else {
            return Option::none();
        }
    }
}
