#!/usr/bin/perl -w

use strict;

my $WORK_DIR = "../../../../../../..";
my $EXE = "";

if ($#ARGV == 0 && $ARGV[0] =~ /linux/i)
{
    $EXE = "Linux/genParmTemplate.out";
}
elsif ($ARGV[0] =~ /darwin/i)
{
    my $DARWIN_GENPARMTEMPLATE = "../../../../art2_peregrine/src/art2/art2_MacOs/Build";
    
    if ($#ARGV == 1 && $ARGV[1] =~ /debug/i)
    {
        $EXE = "$DARWIN_GENPARMTEMPLATE/Debug/genParmTemplate";
    }
    else
    {
        $EXE = "$DARWIN_GENPARMTEMPLATE/Release/genParmTemplate";
    }
}
elsif ($ARGV[0] =~ /win/i && $ARGV[1] =~ /debug/i)
{
    $EXE = "Debug/genParmTemplate.exe";
}
else
{
    $EXE = "Release/genParmTemplate.exe";
}


system("$EXE $WORK_DIR/include/systemtools/common/cmdTxParms.h");
system("$EXE $WORK_DIR/include/systemtools/common/cmdRxParms.h");
system("$EXE $WORK_DIR/include/systemtools/common/cmdCalParms.h");

system("$EXE $WORK_DIR/include/systemtools/common/cmdCalDoneParms.h");
system("$EXE $WORK_DIR/include/systemtools/common/rspGenericParms.h");
system("$EXE $WORK_DIR/include/systemtools/common/submitReportParms.h");
system("$EXE $WORK_DIR/include/systemtools/common/cmdPmParms.h");
system("$EXE $WORK_DIR/include/systemtools/common/cmdSetRegParms.h");
system("$EXE $WORK_DIR/include/systemtools/common/cmdNartGenericCmdParms.h");
system("$EXE $WORK_DIR/include/systemtools/common/cmdNartGenericRspParms.h");
system("$EXE $WORK_DIR/include/systemtools/common/cmdTxStatus.h");
system("$EXE $WORK_DIR/include/systemtools/common/cmdRxStatus.h");
