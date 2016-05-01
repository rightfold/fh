<?hh // strict
namespace FH;

interface Eq<T> {
    public function eq(T $a, T $b): bool;
}
