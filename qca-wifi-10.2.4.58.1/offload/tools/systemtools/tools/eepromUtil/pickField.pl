#!/usr/bin/perl -w
use strict;

my $key = "$ARGV[0]";
my $inFile  ="_tmpIn.dat";

open(INFILE, "<$inFile") or die "Cannot open file $inFile:$!\n";

while (<INFILE>) {
    if ($_ =~ /$key/) { print $_;  }
}
close INFILE;

exit 0;

