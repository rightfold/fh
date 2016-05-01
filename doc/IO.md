# FH\IO&lt;+T>

Functions that create, combine, and unsafely execute I/O actions.

## Constructor

<dl>
<dt><code>__construct((function(): T) $action)</code></dt>
<dd>Construct an I/O action which when performed executes the given (potentially
effectful) procedure.</dd>
</dl>

## Static methods

<dl>
<dt><code>pure(T $x): IO&lt;T></code></dt>
<dd>Return an I/O action that has no effects and returns the given value.</dd>
</dl>
