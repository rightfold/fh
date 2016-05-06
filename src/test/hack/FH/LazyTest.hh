<?hh // strict
namespace FH;
use PHPUnit_Framework_TestCase;

class LazyTest_Ref<T> {
    public function __construct(public T $value) { }
}

class LazyTest extends PHPUnit_Framework_TestCase {
    public function testLazy(): void {
        $x = new LazyTest_Ref(0);
        $l = new Lazy(function() use($x) { $x->value += 1; return 42; });
        $this->assertSame($x->value, 0);
        $this->assertSame($l->force(), 42);
        $this->assertSame($x->value, 1);
        $this->assertSame($l->force(), 42);
        $this->assertSame($x->value, 1);
    }
}
