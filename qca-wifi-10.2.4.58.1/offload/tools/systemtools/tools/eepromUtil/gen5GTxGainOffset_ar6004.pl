#!perl -w
#
# Usage: perl gen5GTxGainOffset.pl <boarddata.bin> <sweepresult.csv>
#
# xiaojuny@qca.qualcomm.com
# Atheros Communications Inc
# Aug 26, 2011

use strict;

my $bd_file; #board data txt file
my $bd_file_bin; # board data bin file
my $sr_file; #sweep result csv file
my @channel;
my @chain;
my @txpwr_t10;
my @tx_gain;

my @txGainTable;
my $maxTxGainTblEntry;
my @pcdac;
my $maxPcdacEntry;
my $indexTxGainTbl = 0;

my @tierTable;
my $maxTierTblEntry;
my @ob;
my $maxObEntry;
my $indexTierTbl = 0;

my @deltaTxGainOverFreq;
my $maxDeltaTxGainOverFreqEntry;
my $indexDeltaTxGainOverFreq = 0;
my @fields;
my $field;
my $i = 0;
my $j = 0;
my @indexObChanged;
my $indexObChanged;
my $scalar;
my $pos = 0;
my $txGainTblScheme=1;

# Step 1: Scan the ARGS
if (scalar(@ARGV) == 2) {
    $bd_file_bin = $ARGV[0];
    $sr_file = $ARGV[1];
} else {
    print "Usage: perl gen5GTxGainOffset.pl <boarddata.bin> <sweepresult.csv>\n";
    exit;
}

$bd_file = $bd_file_bin;
$bd_file =~ s/.bin/.txt/g; 

system("./Linux/eepromBin2Txt_ar6004.out eeprom_2_1.tpl $bd_file_bin $bd_file")==0 || die ("Could not convert $bd_file_bin to $bd_file.");
open(BD, "< $bd_file") || die ("Could not open: $bd_file\n");
open(SR, "< $sr_file") || die ("Could not open: $sr_file\n");

while (<BD>) {
    chop($_);
    if ($_ =~ /^txGainEntryLegHT20_A/)  { 
        @fields = split(/0x/, $_);
        $fields[1] =~ s/\s$//;
        $txGainTable[$indexTxGainTbl] = sprintf hex $fields[1];
        $pcdac[$indexTxGainTbl] = ($txGainTable[$indexTxGainTbl] & 0xff000000) >> 24;
        #printf("index= %02d, txGainTable = 0x%08x, pcdac=0x%02x\n", $indexTxGainTbl, $txGainTable[$indexTxGainTbl], $pcdac[$indexTxGainTbl]);
        $indexTxGainTbl++;
    }
    if ($_ =~ /^tierTbl5G_HT20_A/)  { 
        @fields = split(/0x/, $_);
        $fields[1] =~ s/\s$//;
        $tierTable[$indexTierTbl] = sprintf hex $fields[1];
        $ob[$indexTierTbl] = ($tierTable[$indexTierTbl] & 0xf0) >> 4;
        if ($ob[$indexTierTbl] != $ob[$indexTierTbl-1]) {
            $scalar = @indexObChanged;
            $indexObChanged[$scalar] = $indexTierTbl-1;
        }
        #printf("index= %02d, tierTable = 0x%02x, ob=0x%02x\n", $indexTierTbl, $tierTable[$indexTierTbl], $ob[$indexTierTbl]);
        $indexTierTbl++;
    }
    if ($_ =~ /^deltaTxGainOverFreq5G_A/)  { 
        @fields = split(/\s+/, $_);
        foreach $field (@fields)  {
            if ($i != 0) {
                $deltaTxGainOverFreq[$indexDeltaTxGainOverFreq][$i] = sprintf $field;
                #printf("index= %02d, i=%02d, deltaTxGainOverFreq = %d\n", $indexDeltaTxGainOverFreq, $i, $deltaTxGainOverFreq[$indexDeltaTxGainOverFreq][$i]);
            }
            $i++;
        }
        $i = 0;
        $indexDeltaTxGainOverFreq++;
    }
    if ($_ =~ /^txGainTblScheme/)  { 
        @fields = split(/\s+/, $_);
        $txGainTblScheme = sprintf $fields[1];
    }
}
$maxTxGainTblEntry = $maxPcdacEntry = $indexTxGainTbl;
$maxTierTblEntry = $maxObEntry = $indexTierTbl;
$maxDeltaTxGainOverFreqEntry = $indexDeltaTxGainOverFreq;
$i = 0;
$indexDeltaTxGainOverFreq = 0;
$indexTierTbl = 0;
$indexTxGainTbl = 0;
#print (@indexObChanged, "\n");

$scalar = @indexObChanged;

while (<SR>) {
    chop($_);
    #printf("1----%s\n", $_);
    @fields = split(/,/, $_); #Channel,RateIndex,Rate,Chain,Gain,pwr_t10,Power,ThermCal
    #printf("fields: %s, %s\n", $fields[3], $fields[4]);
    if (!($fields[3] =~/[^0]+/)) {  # Just get Chain 0 data
        foreach $indexObChanged (@indexObChanged)  {
            if($fields[4] == $pcdac[$indexObChanged]) {
                $channel[2*$i] = $fields[0];
                $txpwr_t10[2*$i] = $fields[5];
                $tx_gain[2*$i] = $fields[4];
                do {
                    $_ = <SR>;
                    chop($_);
                    @fields = split(/,/, $_); 
                    if (!($fields[3] =~/[^0]+/)) {
                       $channel[2*$i+1] = $fields[0];
                       $txpwr_t10[2*$i+1] = $fields[5];
                       $tx_gain[2*$i+1] = $fields[4];
                       #printf("channel: %d, %d\n", $channel[2*$i], $channel[2*$i+1]);
                       #printf("txpwr_t10: %d, %d\n", $txpwr_t10[2*$i], $txpwr_t10[2*$i+1]);
                       #printf("tx_gain: %d, %d\n", $tx_gain[2*$i], $tx_gain[2*$i+1]);
                       $i++;
                       
                    }
                } until (!($fields[3] =~/[^0]+/))
            }
       }
    }
}
#printf("i=%d\n", $i);
#my $freqNumber = $i/$scalar;
for ($i--; $i>=0; $i--) {
    if ($channel[2*$i+1] == $channel[2*$i]) {
        $indexDeltaTxGainOverFreq = (($channel[2*$i]+50)-5500)/100 + 5;
        my $ob_curr = $ob[$indexObChanged[$i%$scalar]];
        $deltaTxGainOverFreq[$indexDeltaTxGainOverFreq][$ob_curr] = ($txpwr_t10[2*$i]-$txpwr_t10[2*$i+1]+5*($tx_gain[2*$i+1]-$tx_gain[2*$i]))/5;
        #printf("Final: %d, %d, %f\n", $indexDeltaTxGainOverFreq, $ob_curr, $deltaTxGainOverFreq[$indexDeltaTxGainOverFreq][$ob_curr]);
    }

}

for ($i = 0; $i < $maxDeltaTxGainOverFreqEntry; $i++) {
    for ($j = $scalar - 1; $j > 0; $j--) {
        $deltaTxGainOverFreq[$i][$j-1]+=$deltaTxGainOverFreq[$i][$j];
    }
}

close(BD);
close(SR);

open(BD, "< $bd_file") || die ("Could not open: $bd_file\n");
my @str=<BD>;
close(BD);
my $str;
my $substr;
#print @str;
$j=0;
my $strLength=0;

foreach $str(@str) {
    if ($str =~ /^deltaTxGainOverFreq5G_A/) { 
        for ($i=0; $i<$scalar;$i++) {
            @fields = split(/\s/, $str);
            my $fieldsLength = length $fields[$i+1];
            if ($txGainTblScheme) {
                substr($str,$i+28+$strLength,$fieldsLength) = sprintf("%d",$fields[$i+1]+$deltaTxGainOverFreq[$j][$i]);
                $strLength += length (sprintf("%d",$fields[$i+1]+$deltaTxGainOverFreq[$j][$i]));
            } else {
                substr($str,$i+28+$strLength,$fieldsLength) = sprintf("%d",$deltaTxGainOverFreq[$j][$i]);
                $strLength += length (sprintf("%d",$deltaTxGainOverFreq[$j][$i]));
            }
            #printf("\n%s, %d, %d, %d\n", substr($str,$i+28,$strLength), $strLength, $fields[$i+1], $deltaTxGainOverFreq[$j][$i]);
        }
        $j++;
        $strLength = 0;
        printf("\n%s", $str);        
    }
}
#print @str;

open(NEWBD, "+> new_$bd_file") || die ("Could not open: new_$bd_file\n");

print NEWBD @str;

close(NEWBD);

system("./Linux/eepromTxt2Bin_ar6004.out eeprom_2_1.tpl new_$bd_file new_$bd_file_bin")==0 || die ("Could not convert new_$bd_file to new_$bd_file_bin.");

exit;
