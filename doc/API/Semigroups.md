# `FH\Semigroups`

## Static methods

<dl>
<dt><code>make&lt;((function(T, T): T) $append): Semigroup&lt;T></code></dt>
<dd>Return a semigroup from an associative binary function.</dd>

<dt><code>intAdd(): Semigroup&lt;int></code></dt>
<dd>(<code>int</code>, <code>+</code>)</dd>

<dt><code>intMul(): Semigroup&lt;int></code></dt>
<dd>(<code>int</code>, <code>*</code>)</dd>

<dt><code>stringConcat(): Semigroup&lt;string></code></dt>
<dd>(<code>string</code>, <code>.</code>)</dd>

<dt><code>vectorConcat&lt;T>(): Semigroup&lt;ImmVector&lt;T>></code></dt>
<dd>(<code>ImmVector&lt;T></code>, vector concatenation)</dd>
</dl>
