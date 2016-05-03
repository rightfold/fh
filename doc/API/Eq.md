# Interface `FH\Eq<T>`

Interface for equality comparers.

## Laws

<dl>
<dt>Reflexivity</dt>
<dd><code>eq($a, $a)</code></dd>

<dt>Symmetry</dt>
<dd><code>eq($a, $b)</code> = <code>eq($b, $a)</code></dd>

<dt>Transitivity</dt>
<dd><code>eq($a, $b)</code> ∧ <code>eq($b, $c)</code> → <code>eq($a, $c)</code></dd>
</dl>

## Instance methods

<dl>
<dt><code>eq(T $a, T $b): bool</code></dt>
<dd>Return whether two values are equal.</dd>
</dl>
