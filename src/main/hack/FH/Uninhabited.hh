<?hh // strict
namespace FH;

final class Uninhabited {
    private function __construct() { }

    public function absurd<T>(): T {
        assert(false);
    }
}
