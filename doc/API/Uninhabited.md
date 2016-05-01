# `FH\Uninhabited`

Type with no inhabitants. Called `Uninhabited` instead of the more well-known
`Void` because Hack prohibits classes to be called `Void`.

## Instance methods

<dl>
<dt><code>absurd&lt;T>(): T</code></dt>
<dd>Use this function where a value of some type other than
<code>Uninhabited</code> is required. This function can never be called.</dd>
</dl>
