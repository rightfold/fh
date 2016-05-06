<?hh // strict
namespace FH;
use PHPUnit_Framework_TestCase;

class MonoidsTest extends PHPUnit_Framework_TestCase {
    public function testConcat(): void {
        $this->assertSame(true,      Monoids::concat(Monoids::boolAnd(),      []));
        $this->assertSame(false,     Monoids::concat(Monoids::boolAnd(),      [false, true]));
        $this->assertSame(true,      Monoids::concat(Monoids::boolAnd(),      [true, true]));
        $this->assertSame(false,     Monoids::concat(Monoids::boolOr(),       []));
        $this->assertSame(true,      Monoids::concat(Monoids::boolOr(),       [false, true]));
        $this->assertSame(true,      Monoids::concat(Monoids::boolOr(),       [true, true]));
        $this->assertSame(7,         Monoids::concat(Monoids::intAdd(),       [1, 2, 4]));
        $this->assertSame(8,         Monoids::concat(Monoids::intMul(),       [1, 2, 4]));
        $this->assertSame('abc',     Monoids::concat(Monoids::stringConcat(), ['a', 'b', 'c']));
        $this->assertSame(
            ImmVector{1, 2, 3}->toArray(),
            Monoids::concat(Monoids::vectorConcat(), [ImmVector{1}, ImmVector{2, 3}])->toArray()
        );
    }
}
