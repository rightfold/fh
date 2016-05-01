<?hh // strict
namespace FH;

final class IO<+T> {
    public function __construct(private (function(): T) $action) { }

    public function unsafePerform(): T {
        return call_user_func($this->action);
    }

    public function map<TM>((function(T): TM) $f): IO<TM> {
        return new IO(function() use($f) {
            $x = $this->unsafePerform();
            return $f($x);
        });
    }

    public function bind<TM>((function(T): IO<TM>) $f): IO<TM> {
        return new IO(function() use($f) {
            $x = $this->unsafePerform();
            return $f($x)->unsafePerform();
        });
    }
}
