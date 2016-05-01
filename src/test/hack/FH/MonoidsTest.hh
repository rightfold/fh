<?hh // strict
namespace FH;
use PHPUnit_Framework_TestCase;

class MonoidsTest extends PHPUnit_Framework_TestCase {
    public function testConcat(): void {
        $this->assertSame(7,         Monoids::concat(Monoids::intAdd(),       [1, 2, 4]));
        $this->assertSame(8,         Monoids::concat(Monoids::intMul(),       [1, 2, 4]));
        $this->assertSame('abc',     Monoids::concat(Monoids::stringConcat(), ['a', 'b', 'c']));
        $this->assertSame([1, 2, 3], Monoids::concat(Monoids::arrayConcat(),  [[1], [2, 3]]));
        $this->assertSame(
            ImmVector{1, 2, 3}->toArray(),
            Monoids::concat(Monoids::vectorConcat(), [ImmVector{1}, ImmVector{2, 3}])->toArray()
        );
    }
}
