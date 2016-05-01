<?hh // strict
namespace FH;
use PHPUnit_Framework_TestCase;

class AwkwardTest extends PHPUnit_Framework_TestCase {
    public function testAwkward(): void {
        $this->assertSame(2, Awkward::error(1)->awkward($x ==> $x + 1, $x ==> $x + 2));
        $this->assertSame(3, Awkward::ok(1)   ->awkward($x ==> $x + 1, $x ==> $x + 2));
    }

    public function testMap(): void {
        $this->assertSame(2, Awkward::error(1)->map($x ==> $x + 1)->awkward($x ==> $x + 1, $x ==> $x + 2));
        $this->assertSame(4, Awkward::ok(1)   ->map($x ==> $x + 1)->awkward($x ==> $x + 1, $x ==> $x + 2));
    }
}
