#!/usr/bin/env perl
use strict;
use warnings;

sub convert {
    my $text = shift;
    $text =~ s/^.|.$//g;
    my @stmts = split /;/, $text;
    pop @stmts;
    my $prefix = '';
    my $suffix = '';
    my $n = 0;
    foreach my $stmt (@stmts) {
        my $var = '$fhAnonBind';
        if ($stmt =~ /^\s*(\$[a-zA-Z_][a-zA-Z_0-9]*)\s*<-(.*)$/) {
            $var = $1;
            $stmt = $2;
        }
        $prefix .= $stmt;
        if ($n < @stmts - 1) {
            $prefix .= '->bind(function(' . $var . ') { return ';
            $suffix .= '; })';
        }
        ++$n;
    }
    $prefix . $suffix;
}

my $text = do { local $/; <STDIN> };

$text =~ s/steps\s*({([^{}]|(?R))*})/convert($1)/ge;

print $text;
