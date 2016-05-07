<?hh // strict
namespace FH;
use PHPUnit_Framework_TestCase;

class LazyTest extends PHPUnit_Framework_TestCase {
    public function testLazy(): void {
        $x = (object)['value' => 0];
        $l = new Lazy(function() use($x) { $x->value += 1; return 42; });
        $this->assertSame($x->value, 0);
        $this->assertSame($l->force(), 42);
        $this->assertSame($x->value, 1);
        $this->assertSame($l->force(), 42);
        $this->assertSame($x->value, 1);
    }
}
