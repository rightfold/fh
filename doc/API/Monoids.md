# `FH\Monoids`

## Static methods

<dl>
<dt><code>make&lt;((function(T, T): T) $append, T $appendId): Monoid&lt;T></code></dt>
<dd>Return a monoid from an associative binary function and an identity value.</dd>

<dt><code>concat&lt;T>(Monoid&lt;T> $m, Traversable&lt;T> $xs): T</code></dt>
<dd><!-- TODO --></dd>

<dt><code>intAdd(): Monoid&lt;int></code></dt>
<dd>(<code>int</code>, <code>+</code>, <code>0</code>)</dd>

<dt><code>intMul(): Monoid&lt;int></code></dt>
<dd>(<code>int</code>, <code>*</code>, <code>1</code>)</dd>

<dt><code>stringConcat(): Monoid&lt;string></code></dt>
<dd>(<code>string</code>, <code>.</code>, <code>''</code>)</dd>

<dt><code>vectorConcat&lt;T>(): Monoid&lt;ImmVector&lt;T>></code></dt>
<dd>(<code>ImmVector&lt;T></code>, vector concatenation, <code>ImmVector{}</code>)</dd>
</dl>
