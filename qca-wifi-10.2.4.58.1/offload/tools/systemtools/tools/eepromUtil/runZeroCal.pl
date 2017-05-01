#!/usr/bin/perl

use Cwd;

my $directory = cwd;
my $command  = "Linux/zeroCal.out ";
my $option = $ARGV[0];

my $curCmd;
my @dataFile;
my @csvFile;

if ($option eq "")
{
   $option = "all";
}

if (!($option eq "1" || $option eq "2" || $option eq "3" || $option eq "all"))
{
   print "Usage: Linux/zeroCal <1|2|3|all>\n";
   print "where: 1 = retrieve CAL and FE delta data from golden bin files\n";
   print "       2 = average CAL and FE FE delta data\n";
   print "       3 = generate the new Golden for this design\n";
   print "       all = run all three steps\n";
   exit;
}


if ($option eq "1" || $option eq "all")
{
   unlink("_tmpFEAvg.bin");
   unlink("_tmpFEAvg.txt");

   $curCmd = $command;
   $curCmd .= "1";

   @dataFile  = <zeroCalData/*.bin>;

   foreach $file (@dataFile)
   {
      !system "$curCmd $file" or die "ERROR in retrieveFEDeltas\n";
   }

   print "Retrieved all CAL and FE delta data ...\n";
}

if ($option eq "2" || $option eq "all")
{
   $curCmd = $command;
   $curCmd .= "2";

   !system "$curCmd " or die "ERROR in readFEDeltas\n";

   print "Averaged CAL and FE data ... \n";
}

if ($option eq "3" || $option eq "all")
{
   $curCmd = $command;
   $curCmd .= "3";

#   @dataFile  = <zeroCalData/*.bin>;

   @dataFile  = <zeroCal_GGoldenfile/zerocal_GGolden.bin>;
   foreach $file (@dataFile)
   {
      !system "$curCmd $file" or die "ERROR in createBrdGldBin\n";
      last;
   }

   print "Created the new board golden CAL ...\n";
}

print "SUCCESSFUL\n";
