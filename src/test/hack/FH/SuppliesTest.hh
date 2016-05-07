<?hh // strict
namespace FH;
use ArrayIterator;
use PHPUnit_Framework_TestCase;

class SuppliesTest extends PHPUnit_Framework_TestCase {
    public function testEmpty(): void {
        $x = (object)['value' => 0];
        Supplies::each(Supplies::empty_(), function($_) use($x) {
            return new IO(function() use($x) { ++$x->value; });
        })->unsafePerform();
        $this->assertSame(0, $x->value);
    }

    public function testFromIterator(): void {
        $x = (object)['value' => 0];
        Supplies::each(
            Supplies::fromIterator(new ArrayIterator([1, 2, 3])),
            function($n) use($x) {
                return new IO(function() use($x, $n) { $x->value += $n; });
            }
        )->unsafePerform();
        $this->assertSame(6, $x->value);
    }
}
