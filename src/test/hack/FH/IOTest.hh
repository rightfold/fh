<?hh // strict
namespace FH;
use PHPUnit_Framework_TestCase;

class IOTest extends PHPUnit_Framework_TestCase {
    public function testPure(): void {
        $this->assertSame(1, IO::pure(1)->unsafePerform());
    }

    public function testMap(): void {
        $called = (object)['value' => 0];
        $io = new IO(function() use($called) {
            $called->value += 1;
            return 1;
        });
        $this->assertSame(2, $io->map($x ==> $x + 1)->unsafePerform());
        $this->assertSame(1, $called->value);
    }

    public function testBind(): void {
        $called = (object)['value' => 0];
        $io1 = new IO(function() use($called) {
            $called->value += 1;
            return 1;
        });
        $io2 = function($x) use($called) {
            return new IO(function() use($x, $called) {
                $called->value += 1;
                return $x + 1;
            });
        };
        $this->assertSame(2, $io1->bind($io2)->unsafePerform());
        $this->assertSame(2, $called->value);
    }
}
