#!/usr/bin/perl -w
use strict;

my $key = "$ARGV[0]";
my $newLine = "$ARGV[1]";
printf "$newLine\n";


my $inFile  ="_tmpIn.dat";
my $outFile ="_tmpOut.dat";

open(OUTFILE, ">$outFile") or die "Cannot open file $outFile:$!\n";
open(INFILE, "<$inFile") or die "Cannot open file $inFile:$!\n";

while (<INFILE>) {
    if ($_ =~ /$key/) { $_=~ s/$key.+/$newLine/g; print OUTFILE $_;  }
    else { print OUTFILE $_;}
}
close INFILE;
close OUTFILE;

exit 0;

