/* usb_pm.c - contians functions for using rhode and schwarz usb power meter */
/* Copyright (c) 2003 Atheros Communications, Inc., All Rights Reserved */


#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "usb_pm.h"
#include "windows.h"


char ErrBuff[1000];




/* METHOD ********************************************************************/
/**
    Report Error
    Retrieve the error text for an error and display it
*
@precondition  
@postcondition   
@side_effects  
*
@param      iErr
              Error number for which to display the text
*
@return         
@exception  
******************************************************************************/


void PrintError(long iErr)
{
  long iLen = NrpGetErrorText(iErr,(char*)0, 0);
  char* Text= new char[iLen+1];
  NrpGetErrorText(iErr,Text, iLen+1);
  printf ("Error: <%s>\n",Text);
  delete[] Text;
}

/* METHOD ********************************************************************/
/**
    ShowBinBuffer
    Show the contents of a binary buffer
*
@precondition  
@postcondition   
@side_effects  
*
@param      buf
              Pointer to the buffer
            i_wCount
              Size of the buffer in bytes
*
@return         
@exception  
******************************************************************************/

void ShowBinBuffer(unsigned char *buf, long i_wCount)
{
  for (int i=0; i<i_wCount; i+=16)
  {
    for (int k=0;k<16 && k+i<i_wCount; k++)
    {
      if (k==8)
        printf ("  ");  
      printf ("%02x  ", buf[i+k]);
    }
    printf ("\n");
  
  }

}

/* METHOD ********************************************************************/
/**
    ReadDeviceResult
    Read return type information and retrieve and display data
    accordingly

*
@precondition  
@postcondition   
@side_effects  
*
@param      
            
*
@return         
@exception  
******************************************************************************/

void ReadDeviceResult(int print_data)
{
  long  l1,l2,l3;
  float f1,f2,f3;
  int   fcount,i;
  long  count;

  float          *ResultArray = 0;
  long           *IndexArray  = 0;
  char           *buf         = 0;
  unsigned char  *BinBuf      = 0;

  long bd,gn,pn;

  do
  {
      NrpGetData(&bd,&gn,&pn);
	  if (bd >0) {
		if(print_data)
		printf("grp:%2ld,par%2ld ",gn,pn);
	  }
    switch(bd)
    {
             case DATA_FLOATARRAY:
        
        fcount = NrpGetFloatArray(NULL,0,0);
        ResultArray = new float[fcount];
        IndexArray = new long[fcount];
        NrpGetFloatArray(ResultArray,IndexArray,fcount);
		if(print_data) 
			printf("\r\n");
        for (i=0; i<fcount; i++){
			if(print_data) 
			printf("%d\t  %e \r\n",IndexArray[i],ResultArray[i]);
        }
        delete[] ResultArray;
        delete[] IndexArray;
                
        break;

             case DATA_BINARYBLOCK:

        count = NrpGetBinaryResult(NULL,0);
		if(print_data) {
			printf ("Binary block %d bytes\n",count); 
		}
        BinBuf = new unsigned char[count];
        NrpGetBinaryResult(BinBuf,count);
        if(print_data) {
			ShowBinBuffer(BinBuf,count);  
		}
        delete[] BinBuf;
        
        break;

             case DATA_STRING:
        count = NrpGetStringResult(NULL,0);
        buf = new char [count+1];
        NrpGetStringResult(buf,count);   
        buf[count] = 0;
        printf("s: '%s'\r\n", buf);
        delete[] buf;
      
        break;

       case DATA_FLOATPARAM:
       case DATA_FLOATRESULT:
       case DATA_FLOATLIMIT:

         NrpGetFloatResult(&f1, &f2, &f3);
		 if(print_data) {
			printf("f1,2,3: %e; %e; %e\r\n",f1,f2,f3);
		 }
         break;

       case DATA_LONGPARAM:
		   if(print_data) {
			NrpGetLongResult(&l1, &l2, &l3);
		
			printf("l1,2,3: %ld; %ld; %ld\r\n",l1,l2,l3);
		}
        break;

             case DATA_BITFIELDPARAM:
        NrpGetBitfieldResult(&l1, &l2, &l3);
		if(print_data) {
			printf("bf1,2,3: %ld; %ld; %ld\r\n",l1,l2,l3);
        }
		break;

       default:
		if(print_data) {
			printf("\r\n");
		}
         break;
     }

  } while (bd != -1);
}



/* METHOD ********************************************************************/
/**
    main
    Program entry
*
@precondition  
@postcondition   
@side_effects  
*
@param      argc
              ignored
            argv
*             ignored

@return         
@exception  <x>: <comment>
******************************************************************************/
int reset_nrp (void)
{
	long devNumber;
	long aliveState;
	long error;
	NrpOpenDriver(); //Establish Connection to USB-Driver
  
	devNumber = NrpGetNrOfDevices();
	// check if there is at least one sensor present
	// if so, select first sensor as default sensor
	if (devNumber < 0)
	{
		printf ("Cannot open NRP_Z11 USB Power Meter\n");
		printf ("\nHit any key to continue\n");
		getch();
		return -1;
	}

	// select device to work with
	NrpSelectDevice(0);

	// If bootloader is active in this device, start application firmware
	aliveState = NrpIsAlive();

	if(aliveState == 2)
	{
		NrpStartApplicationMode();
		printf ("Âpplication started\n");
	} 

    // Discard all messages
    NrpEmptyAllBuffers();
    NrpSendCommand ("*rst",1000);
	ReadDeviceResult(0);
	error = NrpGetLastError();
	if (error > 0) {
		PrintError(error);
		return 0;
	} else
		return 1;
}

float aquire_data()
{
	float f1,f2,f3;
	int jj = 0;

	NrpEmptyAllBuffers();
	NrpSendCommand("init:imm",1000);   
	    
    while((NrpDataAvailable() < 1) && (jj<100)){
        Sleep(10);
		jj++;
	}
   
	if (jj == 100) {
		return(-120.);
	}

	NrpGetFloatResult(&f1, &f2, &f3);
	return 10*log10f(fabsf(f1*1000));
}


/*
int main(int argc, char* argv[])
{
	float result;
	reset_nrp(); //only call this once
	result = aquire_data();
	printf("result: %e\r\n",result);
	NrpCloseDriver(); 
	return 0;
}
*/



