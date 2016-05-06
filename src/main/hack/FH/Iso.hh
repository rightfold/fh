<?hh // strict
namespace FH;

interface Iso<TA, TB> {
    public function a2b(TA $a): TB;
    public function b2a(TB $b): TA;
}
