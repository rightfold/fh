<?hh // strict
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
}
