<?hh // strict
namespace FH;
use Iterator;

final class Supplies {
    private function __construct() { }

    public static function empty_<T>(): Supply<T> {
        return IO::pure(Option::none());
    }

    public static function fromIterator<T>(Iterator<T> $it): Supply<T> {
        $rewound = (object)['value' => false];
        return new IO(function() use($it, $rewound) {
            if (!$rewound->value) {
                $it->rewind();
                $rewound->value = true;
            }
            if (!$it->valid()) {
                return Option::none();
            }
            $value = $it->current();
            $it->next();
            return Option::some($value);
        });
    }

    public static function each<T>(Supply<T> $s, (function(T): IO<mixed>) $f): IO<mixed> {
        return new IO(function() use($s, $f) {
            for (;;) {
                $ok = $s->unsafePerform()->option(
                    false,
                    function($x) use($f) {
                        $f($x)->unsafePerform();
                        return true;
                    }
                );
                if (!$ok) {
                    break;
                }
            }
            return null;
        });
    }
}
