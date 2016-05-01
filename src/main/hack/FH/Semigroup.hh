<?hh // strict
namespace FH;

interface Semigroup<T> {
    public function append(T $a, T $b): T;
}
