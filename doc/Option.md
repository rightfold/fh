# `FH\Option<+T>`

Optional values. Use this instead of `?T` when you need `Option<Option<T>>`,
`Option<?T>`, or `?mixed`.

## Static methods

<dl>
<dt><code>none(): Option&lt;T></code></dt>
<dd>Return the empty option.</dd>

<dt><code>some(T $x): Option&lt;T></code></dt>
<dd>Return an option with the given value. The nullness of the given value is
not considered; this function always returns a non-empty option.</dd>
</dl>

## Instance methods

<dl>
<dt><code>option&lt;TR>(TR $onNone, (function(T): TR) $onSome): TR</code></dt>
<dd><!-- TODO: documentation --></dd>

<dt><code>optionL&lt;TR>((function(): TR) $onNone, (function(T): TR) $onSome): TR</code></dt>
<dd><!-- TODO: documentation --></dd>

<dt><code>map&lt;TM>((function(T): TM) $f): Option&lt;TM></code></dt>
<dd><!-- TODO: documentation --></dd>

<dt><code>bind&lt;TM>((function(T): Option&lt;TM>) $f): Option&lt;TM></code></dt>
<dd><!-- TODO: documentation --></dd>
</dl>
