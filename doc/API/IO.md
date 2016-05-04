# Final class `FH\IO<+T>`

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

## Instance methods

<dl>
<dt><code>unsafePerform(): T</code></dt>
<dd>Perform this I/O action, including any effects it may have.</dd>

<dt><code>map&lt;TM>((function(T): TM) $f): IO&lt;TM></code></dt>
<dd>Return an I/O action that performs this I/O action and transforms its result
with the given function.</dd>

<dt><code>bind&lt;TM>((function(T): IO&lt;TM>) $f): IO&lt;TM></code></dt>
<dd>Combine this I/O action with a Kleisli arrow.</dd>
</dl>
