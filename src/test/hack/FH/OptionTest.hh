<?hh // partial
// This file is in partial mode due to a bug in h2tp:
// https://github.com/facebook/hhvm/issues/7029#issuecomment-216323393

namespace FH;
use PHPUnit_Framework_TestCase;

class OptionTest extends PHPUnit_Framework_TestCase {
    public function testOption(): void {
        $this->assertSame(1, Option::none() ->option(1, F::id()));
        $this->assertSame(2, Option::some(2)->option(1, F::id()));
    }

    public function testOptionL(): void {
        $this->assertSame(1, Option::none() ->optionL(() ==> 1, F::id()));
        $this->assertSame(2, Option::some(2)->optionL(() ==> 1, F::id()));
    }

    public function testMap(): void {
        $this->assertSame(1, Option::none() ->map($x ==> $x + 1)->option(1, F::id()));
        $this->assertSame(3, Option::some(2)->map($x ==> $x + 1)->option(1, F::id()));
    }

    public function testBind(): void {
        $this->assertSame(1, steps {
            $x <- Option::none();
            $y <- Option::none();
            Option::some($x);
        }->option(1, F::id()));
        $this->assertSame(1, steps {
            $x <- Option::none();
            $y <- Option::some($x + 1);
            Option::some($y);
        }->option(1, F::id()));
        $this->assertSame(1, steps {
            $x <- Option::some(2);
            $y <- Option::none();
            Option::some($y);
        }->option(1, F::id()));
        $this->assertSame(3, steps {
            $x <- Option::some(2);
            $y <- Option::some($x + 1);
            Option::some($y);
        }->option(1, F::id()));
    }
}
