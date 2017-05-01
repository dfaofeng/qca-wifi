#!/bin/sh
echo "Enter the destination directory name"
read destination_directory

echo "Enter the flow name"
read flow_name

mkdir $destination_directory
gcc genLPTestFlow_qc98xx.c -o genLPTestFLow_qc98xx.out

./genLPTestFLow_qc98xx.out

mv newLPTestFlow.txt $destination_directory/$flow_name
rm *.out
rm lpFlowRxSweep.txt
#rm lpFlowTxSweep.txt

