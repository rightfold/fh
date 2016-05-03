# Final class `FH\Awkward<+TError, +TOk>`

Potentially erroneous values. Use this instead of exceptions. Also called
`Either` or `\/` in other libraries.

## Static methods

<dl>
<dt><code>error(TError): Awkward&lt;TError, TOk></code></dt>
<dd>Return an erroneous value.</dd>

<dt><code>ok(TOk): Awkward&lt;TError, TOk></code></dt>
<dd>Return a non-erroneous value.</dd>
</dl>

## Instance methods

<dl>
<dt><code>awkward&lt;TR>((function(TError): TR) $onError, (function(TOk): TR) $onSome): TR</code></dt>
<dd><!-- TODO: documentation --></dd>

<dt><code>map&lt;TM>((function(T): TM) $f): Awkward&lt;TError, TM></code></dt>
<dd><!-- TODO: documentation --></dd>
</dl>
