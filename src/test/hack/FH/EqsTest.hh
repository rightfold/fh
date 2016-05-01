<?hh // strict
namespace FH;
use PHPUnit_Framework_TestCase;

class EqsTest extends PHPUnit_Framework_TestCase {
    public function testEq(): void {
        $this->assertTrue (Eqs::intEq()->eq(1, 1));
        $this->assertFalse(Eqs::intEq()->eq(1, 2));

        $this->assertTrue (Eqs::stringEq()->eq('1', '1'));
        $this->assertFalse(Eqs::stringEq()->eq('1', '2'));

        $this->assertTrue (Eqs::arrayEq(Eqs::intEq())->eq([1, 2, 3], [1, 2, 3]));
        $this->assertFalse(Eqs::arrayEq(Eqs::intEq())->eq([1, 2, 3], [2, 3, 4]));

        $this->assertTrue (Eqs::vectorEq(Eqs::intEq())->eq(ImmVector{1, 2, 3}, ImmVector{1, 2, 3}));
        $this->assertFalse(Eqs::vectorEq(Eqs::intEq())->eq(ImmVector{1, 2, 3}, ImmVector{2, 3, 4}));
    }
}
