<?hh // strict
namespace FH;

final class Lazy<+T> {
    private T $value;
    private ?(function(): T) $thunk;

    public function __construct((function(): T) $thunk) {
        $this->value = /* UNSAFE_EXPR */ null;
        $this->thunk = $thunk;
    }

    public function force(): T {
        if ($this->thunk !== null) {
            $f = $this->thunk;
            $this->value = call_user_func($f);
            $this->thunk = null;
        }
        return $this->value;
    }
}
