<?hh // strict
namespace FH;
use PHPUnit_Framework_TestCase;

class FTest extends PHPUnit_Framework_TestCase {
    public function testId(): void {
        $this->assertSame(1, call_user_func(F::id(), 1));
    }

    public function testConstant(): void {
        $this->assertSame(1, call_user_func(F::constant(1), 2));
    }
}
