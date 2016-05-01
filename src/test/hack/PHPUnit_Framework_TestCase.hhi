<?hh // decl

abstract class PHPUnit_Framework_TestCase {
    public final function assertSame<T>(T $a, T $b): void;
    public final function assertTrue(bool $x): void;
}
