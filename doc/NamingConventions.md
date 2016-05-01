# Naming conventions

Throughout Functional Hack, the following naming conventions are used:

## Lazy parameters

Names of functions with lazy parameters are suffixed with `L` ("lazy"), and
functions that take constants directly are not. For example:

    final class Option<+T> {
        public function option<TR>(TR $onNone, (function(T): TR) $onSome): TR { ... }
        public function optionL<TR>((function(): TR) $onNone, (function(T): TR) $onSome): TR { ... }
    }

These functions exist so you can prevent the unnecessary evaluation of
resource-heavy computations.
