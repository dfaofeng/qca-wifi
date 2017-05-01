#!/usr/bin/perl

use Cwd;

my $directory = cwd;
my $command   = "Linux/calProc.out ";
my $option = $ARGV[0];

my $curCmd;
my @dataFile;
my @csvFile;

if ($option eq "")
{
   $option = "all";
}

if (!($option eq "0" || $option eq "1" || $option eq "all"))
{
   print "Usage: perl runCal.pl\n";
   exit;
}

if ($option eq "1" || $option eq "all")
{
   $curCmd = $command;

   @dataFile  = <calData/*.bin>;

   foreach $file (@dataFile)
   {
      !system "$curCmd $file" or die "ERROR in procCalData\n";
   }
}

print "SUCCESSFUL\n";
