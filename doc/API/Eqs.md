# Final class `FH\Eqs`

Equality comparers.

## Static methods

<dl>
<dt><code>make&lt;T>((function(T, T): bool) $eq): Eq&lt;T></code></dt>
<dd>Return an equality comparer from a function.</dd>

<dt><code>contramap&lt;TI, TO>(Eq&lt;TO> $eq, (function(TI): TO) $f): Eq&lt;TI></code></dt>
<dd>Return a new equality comparer that first transforms its input.</dd>

<dt><code>intEq(): Eq&lt;int></code></dt>
<dd><!-- TODO: document --></dd>

<dt><code>stringEq(): Eq&lt;string></code></dt>
<dd><!-- TODO: document --></dd>

<dt><code>arrayEq&lt;T>(Eq&lt;T> $elementEq): Eq&lt;array&lt;T>></code></dt>
<dd><!-- TODO: document --></dd>

<dt><code>vectorEq&lt;T>(Eq&lt;T> $elementEq): Eq&lt;ImmVector&lt;T>></code></dt>
<dd><!-- TODO: document --></dd>
</dl>
