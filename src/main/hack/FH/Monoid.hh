<?hh // strict
namespace FH;

interface Monoid<T> extends Semigroup<T> {
    public function appendId(): T;
}
