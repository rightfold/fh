<?hh // strict
namespace FH;
use PHPUnit_Framework_TestCase;

class MonoidsTest extends PHPUnit_Framework_TestCase {
    public function testConcat(): void {
        $this->assertSame(6, Monoids::concat(Monoids::intAdd(), [1, 2, 3]));
    }
}
