
#include <stdio.h>

#define FIELD_LEN 16
#define NAME_LEN  50
#define CMD_LEN   128

#define  SWEEP_RX_FLOW

typedef struct rxSweepFlow {
//    unsigned int  chan;
    unsigned char bw[FIELD_LEN];
    unsigned char rate[FIELD_LEN];
    unsigned char preamble[FIELD_LEN];
    unsigned char packetFormat[FIELD_LEN];
    float         rxSweepStart;
    float         rxSweepEnd;
    float         rxSweepStep;
    float         rxSensPerceptage;
} RX_SWEEP_FLOW;
    
unsigned int  Sweep2GRxChains[] = {
#include "rxSweep2GChain.ch"
};

unsigned int  Sweep5GRxChains[] = {
#include "rxSweep5GHT20Chain.ch"
};

unsigned int  Sweep5GHT40RxChains[] = {
#include "rxSweep5GHT40Chain.ch"
};

unsigned int  Sweep2GRxChannels[] = {
#include "rxSweep2GChans.chn"
};

unsigned int  Sweep5GRxChannels[] = {
#include "rxSweep5GHT20Chans.chn"
};

unsigned int  Sweep5GHT40RxChannels[] = {
#include "rxSweep5GHT40Chans.chn"
};

unsigned int  Sweep5GVHT20RxChannels[] = {
#include "rxSweep5GHT20Chans.chn"
};

unsigned int  Sweep5GVHT40RxChannels[] = {
#include "rxSweep5GHT40Chans.chn"
};

unsigned int  Sweep5GVHT80RxChannels[] = {
#include "rxSweep5GVHT80Chans.chn"
};

RX_SWEEP_FLOW Sweep2GRX[] = {
#include "rxSweep2G.cfg"
};

RX_SWEEP_FLOW Sweep5GRX[] = {
#include "rxSweep5GHT20.cfg"
};

RX_SWEEP_FLOW Sweep5GHT40RX[] = {
#include "rxSweep5GHT40.cfg"
};

RX_SWEEP_FLOW Sweep5GVHT20RX[] = {
#include "rxSweep5GVHT20.cfg"
};

RX_SWEEP_FLOW Sweep5GVHT40RX[] = {
#include "rxSweep5GVHT40.cfg"
};

RX_SWEEP_FLOW Sweep5GVHT80RX[] = {
#include "rxSweep5GVHT80.cfg"
};


static int loopRxSweep(FILE *fp, unsigned int rxChain, unsigned int chan, float sensPer, float start, 
                       float end, float step, char* bw, char* rate, char* preamble, char* packetFormat);
static void sweepRxChannels(
    FILE *fp,
    int loopRxChanCount,
    int loopRxRateCount,
    int loopRxChainCount,
    unsigned int *sweepRxChan,
    RX_SWEEP_FLOW *sweepRx,
    unsigned int *sweepRxChain);

#define SWEEP_TX_FLOW

#define POWER_LOWER_LIMIT  -1.50
#define POWER_HIGHER_LIMIT  1.50
#define RANGE_LEN           3

#define TX_NONE       0x00000000
#define TX_EVM        0x00000001
#define TX_POWER      0x00000002
#define TX_MASK       0x00000004
#define TX_SWEEP_EVM  0x00000008
#define HT40_2GCHAN_START 2422
#define HT40_2GCHAN_END   2462
#define CHAN2G_START  2412
#define CHAN2G_END    2484
#define CHAN5G_START  4910
#define CHAN5G_END    5910

unsigned int  Sweep2GTxChains[] = {
#include "txSweep2GChain.ch"
};

unsigned int  Sweep5GTxChains[] = {
#include "txSweep5GHT20Chain.ch"
};

unsigned int  Sweep5GHT40TxChains[] = {
#include "txSweep5GHT40Chain.ch"
};

unsigned int  Sweep5GVHT80TxChains[] = {
#include "txSweep5GHT40Chain.ch"
};

unsigned int  Sweep2GTxChannels[] = {
#include "txSweep2GChans.chn"
};

unsigned int  Sweep5GTxChannels[] = {
#include "txSweep5GHT20Chans.chn"
};

unsigned int  Sweep5GHT40TxChannels[] = {
#include "txSweep5GHT40Chans.chn"
};
    
unsigned int  Sweep5GVHT20TxChannels[] = {
#include "txSweep5GVHT20Chans.chn"
};

unsigned int  Sweep5GVHT40TxChannels[] = {
#include "txSweep5GVHT40Chans.chn"
};

unsigned int  Sweep5GVHT80TxChannels[] = {
#include "txSweep5GVHT80Chans.chn"
};

typedef struct PowerRange {
    double     startPower;
    double     endPower;
    double     step;
} POWER_RANGE;

typedef struct EVMLimits {
    double     lowerLimit;
    double     upperLimit;
} EVM_LIMITS;

typedef struct txSweepFlow {
    unsigned char  rate[FIELD_LEN];
    unsigned char  bw[FIELD_LEN];
    unsigned char  preamble[FIELD_LEN];
    unsigned char  packetFormat[FIELD_LEN];
    POWER_RANGE    powerRange;
    EVM_LIMITS     evmLimits;
    unsigned int   sweepFlag;
} TX_SWEEP_FLOW;

TX_SWEEP_FLOW Sweep2GTX[] = {
#include "txSweep2G.cfg"
};


TX_SWEEP_FLOW Sweep5GTX[] = {
#include "txSweep5GHT20.cfg"
};

TX_SWEEP_FLOW Sweep5GHT40TX[] = {
#include "txSweep5GHT40.cfg"
};

TX_SWEEP_FLOW Sweep5GVHT20TX[] = {
#include "txSweep5GVHT20.cfg"
};

TX_SWEEP_FLOW Sweep5GVHT40TX[] = {
#include "txSweep5GVHT40.cfg"
};

TX_SWEEP_FLOW Sweep5GVHT80TX[] = {
#include "txSweep5GVHT80.cfg"
};


TX_SWEEP_FLOW *sweepTx;
unsigned int  *sweepChannels;

static void verifyPower(FILE *fp, unsigned int txChain, unsigned int chan, char* bw, char* rate, char* preamble, float pwr, char* packetFormat);
static void verifyEvm(FILE *fp, unsigned int txChain, unsigned int chan, char *bw, char* rate, char* preamble,
                      float lowerLimit, float upperLimit, float pwr, char* packetFormat);
static void verifyMask(FILE *fp, unsigned int txChain, unsigned int chan, char* bw, char* rate, char* preamble, float pwr, char* packetFormat);
static void sweepEvm(FILE *fp, unsigned int txChain, unsigned int chan, char* bw, char* rate, char* preamble, 
                     float startPower, float endPower, float step, char* packetFormat);
static int is2GChannel(unsigned int channel);
static void sweepTxChannels(
    FILE *fp,
    int loopTxChanCount, 
    int loopTxRateCount, 
    int loopTxChainCount, 
    unsigned int *sweepTxChan, 
    TX_SWEEP_FLOW *sweepTX,
    unsigned int *sweepTxChain);

int main(void)
{

    FILE *fp;
#if defined(INCLUDE_CAL)
    char headerFile[NAME_LEN]  = "lpFlowHeaderwCal_qc98xx.txt";
#else
    char headerFile[NAME_LEN]  = "lpFlowHeader_qc98xx.txt";
#endif
    char tailFile[NAME_LEN]    = "lpFlowTail_qc98xx.txt";
    char rxSweepFile[NAME_LEN] = "lpFlowRxSweep.txt";
    char txSweepFile[NAME_LEN] = "lpFlowTxSweep.txt";
    char lpTestFlowFile[NAME_LEN] = "newLPTestFlow.txt";
    char rxSweep2GFile[NAME_LEN] = "rxSweep2G.cfg";
    char rxSweep2GChansFile[NAME_LEN] = "rxSweep2GChans.chn"; 
    char rxSweep2GChainFile[NAME_LEN] = "rxSweep2GChain.ch";
    char rxSweep5GHT20File[NAME_LEN] = "rxSweep5GHT20.cfg";
    char rxSweep5GHT20ChansFile[NAME_LEN] = "rxSweep5GHT20Chans.chn";
    char rxSweep5GHT20ChainFile[NAME_LEN] = "rxSweep5GHT20Chain.ch";    
    char rxSweep5GHT40File[NAME_LEN] = "rxSweep5GHT40.cfg";
    char rxSweep5GHT40ChansFile[NAME_LEN] = "rxSweep5GHT40Chans.chn";    
    char rxSweep5GHT40ChainFile[NAME_LEN] = "rxSweep5GHT40Chain.ch";
    char txSweep2GFile[NAME_LEN] = "txSweep2G.cfg";
    char txSweep2GChansFile[NAME_LEN] = "txSweep2GChans.chn";
    char txSweep2GChainFile[NAME_LEN] = "txSweep2GChain.ch";      
    char txSweep5GHT20File[NAME_LEN] = "txSweep5GHT20.cfg";
    char txSweep5GHT20ChansFile[NAME_LEN] = "txSweep5GHT20Chans.chn";
    char txSweep5GHT20ChainFile[NAME_LEN] = "txSweep5GHT20Chain.ch";      
    char txSweep5GHT40File[NAME_LEN] = "txSweep5GHT40.cfg";
    char txSweep5GHT40ChansFile[NAME_LEN] = "txSweep5GHT40Chans.chn";
    char txSweep5GHT40ChainFile[NAME_LEN] = "txSweep5GHT40Chain.ch";      
    int i, j, k, index=0;
    int loopRxChainCount;
    int loopTxChainCount;
    int loopRxChanCount; 
    int loopTxChanCount;
    int loopRxRateCount; 
    int loopTxRateCount;
    int tx=1;
    int rx=1;
    int ht20=1;
    int ht40=1;
    int g=1;
    int a=1;
    float pwr;
    char cmdStr[CMD_LEN];
    FILE *fStream;
    char lineBuf[222], *pLine;
    char tmp[8][NAME_LEN];

#if defined(SWEEP_TX_FLOW)
    if (NULL == (fp = fopen(txSweepFile, "w"))) {
        printf("Error: open file %s\n", txSweepFile);
        return(-1);
    }

    loopTxChanCount = sizeof(Sweep2GTxChannels) / sizeof(int);
    loopTxRateCount = sizeof(Sweep2GTX) / sizeof(TX_SWEEP_FLOW); 
    loopTxChainCount = sizeof(Sweep2GTxChains) / sizeof(int);
    printf("Loop TX sweep 2G channels %d chain %d rates %d ...\n", loopTxChanCount, loopTxChainCount, loopTxRateCount);
    sweepTxChannels(fp, loopTxChanCount, loopTxRateCount, loopTxChainCount, Sweep2GTxChannels, Sweep2GTX, Sweep2GTxChains);

    loopTxChanCount = sizeof(Sweep5GTxChannels) / sizeof(int);
    loopTxRateCount = sizeof(Sweep5GTX) / sizeof(TX_SWEEP_FLOW); 
    loopTxChainCount = sizeof(Sweep5GTxChains) / sizeof(int);
    printf("Loop TX sweep 5G channels %d rates %d ...\n", loopTxChanCount, loopTxRateCount, loopTxChainCount);
    sweepTxChannels(fp, loopTxChanCount, loopTxRateCount, loopTxChainCount, Sweep5GTxChannels, Sweep5GTX, Sweep5GTxChains); 

    loopTxChanCount = sizeof(Sweep5GHT40TxChannels) / sizeof(int);
    loopTxRateCount = sizeof(Sweep5GHT40TX) / sizeof(TX_SWEEP_FLOW); 
    loopTxChainCount = sizeof(Sweep5GHT40TxChains) / sizeof(int);
    printf("Loop TX sweep 5G HT40 channels %d rates %d ...\n", loopTxChanCount, loopTxRateCount, loopTxChainCount);
    sweepTxChannels(fp, loopTxChanCount, loopTxRateCount, loopTxChainCount, Sweep5GHT40TxChannels, Sweep5GHT40TX, Sweep5GHT40TxChains); 

    loopTxChanCount = sizeof(Sweep5GVHT20TxChannels) / sizeof(int);
    loopTxRateCount = sizeof(Sweep5GVHT20TX) / sizeof(TX_SWEEP_FLOW); 
    loopTxChainCount = sizeof(Sweep5GTxChains) / sizeof(int);
    printf("Loop TX sweep 5G VHT20 channels %d rates %d ...\n", loopTxChanCount, loopTxRateCount, loopTxChainCount);
    sweepTxChannels(fp, loopTxChanCount, loopTxRateCount, loopTxChainCount, Sweep5GVHT20TxChannels, Sweep5GVHT20TX, Sweep5GTxChains); 

    loopTxChanCount = sizeof(Sweep5GVHT40TxChannels) / sizeof(int);
    loopTxRateCount = sizeof(Sweep5GVHT40TX) / sizeof(TX_SWEEP_FLOW); 
    loopTxChainCount = sizeof(Sweep5GHT40TxChains) / sizeof(int);
    printf("Loop TX sweep 5G HT40 channels %d rates %d ...\n", loopTxChanCount, loopTxRateCount, loopTxChainCount);
    sweepTxChannels(fp, loopTxChanCount, loopTxRateCount, loopTxChainCount, Sweep5GVHT40TxChannels, Sweep5GVHT40TX, Sweep5GHT40TxChains); 

    loopTxChanCount = sizeof(Sweep5GVHT80TxChannels) / sizeof(int);
    loopTxRateCount = sizeof(Sweep5GVHT80TX) / sizeof(TX_SWEEP_FLOW); 
    loopTxChainCount = sizeof(Sweep5GVHT80TxChains) / sizeof(int);
    printf("Loop TX sweep 5G HT40 channels %d rates %d ...\n", loopTxChanCount, loopTxRateCount, loopTxChainCount);
    sweepTxChannels(fp, loopTxChanCount, loopTxRateCount, loopTxChainCount, Sweep5GVHT80TxChannels, Sweep5GVHT80TX, Sweep5GVHT80TxChains); 

    fclose(fp);
#endif

#if defined(SWEEP_RX_FLOW)
    if (NULL == (fp = fopen(rxSweepFile, "w"))) {
        printf("Error: open file %s\n", rxSweepFile);
        return(-1);
    }

    loopRxChanCount = sizeof(Sweep2GRxChannels) / sizeof(int);
    loopRxRateCount = sizeof(Sweep2GRX) / sizeof(RX_SWEEP_FLOW); 
    loopRxChainCount = sizeof(Sweep2GRxChains) / sizeof(int);
    printf("Loop RX sweep 2G chan %d rate %d ...\n", loopRxChanCount, loopRxRateCount, loopRxChainCount);
    sweepRxChannels(fp, loopRxChanCount, loopRxRateCount, loopRxChainCount, Sweep2GRxChannels, Sweep2GRX, Sweep2GRxChains);

    loopRxChanCount = sizeof(Sweep5GRxChannels) / sizeof(int);
    loopRxRateCount = sizeof(Sweep5GRX) / sizeof(RX_SWEEP_FLOW); 
    loopRxChainCount = sizeof(Sweep5GRxChains) / sizeof(int);
    printf("Loop RX sweep 5G chan %d rate %d ...\n", loopRxChanCount, loopRxRateCount, loopRxChainCount);
    sweepRxChannels(fp, loopRxChanCount, loopRxRateCount, loopRxChainCount, Sweep5GRxChannels, Sweep5GRX, Sweep5GRxChains);

    loopRxChanCount = sizeof(Sweep5GHT40RxChannels) / sizeof(int);
    loopRxRateCount = sizeof(Sweep5GHT40RX) / sizeof(RX_SWEEP_FLOW); 
    loopRxChainCount = sizeof(Sweep5GHT40RxChains) / sizeof(int);
    printf("Loop RX sweep 5G HT40 chan %d rate %d ...\n", loopRxChanCount, loopRxRateCount, loopRxChainCount);
    sweepRxChannels(fp, loopRxChanCount, loopRxRateCount, loopRxChainCount, Sweep5GHT40RxChannels, Sweep5GHT40RX, Sweep5GHT40RxChains);

    loopRxChanCount = sizeof(Sweep5GVHT20RxChannels) / sizeof(int);
    loopRxRateCount = sizeof(Sweep5GRX) / sizeof(RX_SWEEP_FLOW); 
    loopRxChainCount = sizeof(Sweep5GRxChains) / sizeof(int);
    printf("Loop RX sweep 5G VHT20 chan %d rate %d ...\n", loopRxChanCount, loopRxRateCount, loopRxChainCount);
    sweepRxChannels(fp, loopRxChanCount, loopRxRateCount, loopRxChainCount, Sweep5GVHT20RxChannels, Sweep5GVHT20RX, Sweep5GRxChains);

    loopRxChanCount = sizeof(Sweep5GVHT40RxChannels) / sizeof(int);
    loopRxRateCount = sizeof(Sweep5GVHT40RX) / sizeof(RX_SWEEP_FLOW); 
    loopRxChainCount = sizeof(Sweep5GRxChains) / sizeof(int);
    printf("Loop RX sweep 5G HT40 chan %d rate %d ...\n", loopRxChanCount, loopRxRateCount, loopRxChainCount);
    sweepRxChannels(fp, loopRxChanCount, loopRxRateCount, loopRxChainCount, Sweep5GHT40RxChannels, Sweep5GVHT40RX, Sweep5GRxChains);

    loopRxChanCount = sizeof(Sweep5GVHT80RxChannels) / sizeof(int);
    loopRxRateCount = sizeof(Sweep5GVHT80RX) / sizeof(RX_SWEEP_FLOW); 
    loopRxChainCount = sizeof(Sweep5GRxChains) / sizeof(int);
    printf("Loop RX sweep 5G HT40 chan %d rate %d ...\n", loopRxChanCount, loopRxRateCount, loopRxChainCount);
    sweepRxChannels(fp, loopRxChanCount, loopRxRateCount, loopRxChainCount, Sweep5GVHT80RxChannels, Sweep5GVHT80RX, Sweep5GRxChains);

    fclose(fp);
#endif

    sprintf(cmdStr, "cat %s %s %s %s > %s", headerFile, txSweepFile, rxSweepFile, tailFile, lpTestFlowFile);

    printf("%s\n", cmdStr);
    system(cmdStr);

    return(0);
}


static void sweepRxChannels(
    FILE *fp,
    int loopRxChanCount,
    int loopRxRateCount,
    int loopRxChainCount,
    unsigned int *sweepRxChan,
    RX_SWEEP_FLOW *sweepRx,
    unsigned int *sweepRxChain)
{
    int i, j, jj;
    for (i=0;i<loopRxChanCount;i++) {
        for (j=0;j<loopRxRateCount;j++) {
            for (jj=0;jj<loopRxChainCount;jj++) {
                // exclude some 2G HT40 channels
                if (!strcmp(sweepRx[j].bw, "HT40") && is2GChannel(sweepRxChan[i])) {
                    if ((sweepRxChan[i] < HT40_2GCHAN_START) || 
                        (sweepRxChan[i] > HT40_2GCHAN_END) ) {
                        //printf("skip HT40 2G chan %d\n", sweepRxChan[i]);
                        continue;
                    }
                }
                // no CCK in 5G
                if (!is2GChannel(sweepRxChan[i])) {
                    if (!strcmp(sweepRx[j].rate, "DSSS-1") || 
                        !strcmp(sweepRx[j].rate, "DSSS-2") ||
                        !strcmp(sweepRx[j].rate, "CCK-5_5") ||
                        !strcmp(sweepRx[j].rate, "CCK-11") ) {
                        printf("skip rate %s for chan %d\n", sweepRx[j].rate, sweepRxChan[i]);
                        continue;
                    }
                }  

                loopRxSweep(fp, sweepRxChain[jj], sweepRxChan[i], sweepRx[j].rxSensPerceptage, sweepRx[j].rxSweepStart,
                            sweepRx[j].rxSweepEnd, sweepRx[j].rxSweepStep, sweepRx[j].bw, sweepRx[j].rate, 
                            sweepRx[j].preamble, sweepRx[j].packetFormat);
            }
        }
    }
    return;
}

static void sweepTxChannels(
    FILE *fp,
    int loopTxChanCount, 
    int loopTxRateCount, 
    int loopTxChainCount, 
    unsigned int *sweepTxChan, 
    TX_SWEEP_FLOW *sweepTX,
    unsigned int *sweepTxChain)
{
    int i, j, k, jj;
    float pwr;

    for (i=0;i<loopTxChanCount;i++) {
        for (j=0;j<loopTxRateCount;j++) {
            for (jj=0;jj<loopTxChainCount;jj++) {
                // exclude some 2G HT40 channels
                if (!strcmp(sweepTX[j].bw, "HT40") && is2GChannel(sweepTxChan[i])) {
                    if ((sweepTxChan[i] < HT40_2GCHAN_START) || 
                        (sweepTxChan[i] > HT40_2GCHAN_END) ) {
                        //printf("skip HT40 2G chan %d\n", sweepTxChan[i]);
                        continue;
                    }
                }
                // no CCK in 5G
                if (!is2GChannel(sweepTxChan[i])) {
                    if (!strcmp(sweepTX[j].rate, "DSSS-1") || 
                        !strcmp(sweepTX[j].rate, "DSSS-2") ||
                        !strcmp(sweepTX[j].rate, "CCK-5_5") ||
                        !strcmp(sweepTX[j].rate, "CCK-11") ) {
                        printf("skip rate %s for chan %d\n", sweepTX[j].rate, sweepTxChan[i]);
                        continue;
                    }
                }  

                if (TX_SWEEP_EVM & sweepTX[j].sweepFlag) {
                    //sweepEvm(fp, sweepTxChain[jj], sweepTxChan[i], sweepTX[j].bw, sweepTX[j].rate, sweepTX[j].preamble,
                    //         sweepTX[j].powerRange.startPower, sweepTX[j].powerRange.endPower,
                    //         sweepTX[j].powerRange.step, sweepTX[j].packetFormat);
                }
                else {
                    for (k=0, pwr=sweepTX[j].powerRange.startPower; pwr<=sweepTX[j].powerRange.endPower; k++,pwr+= sweepTX[j].powerRange.step) {
                        if (TX_EVM & sweepTX[j].sweepFlag) { 
                            //verifyEvm(fp, sweepTxChain[jj], sweepTxChan[i], sweepTX[j].bw, sweepTX[j].rate,
                            //          sweepTX[j].preamble, sweepTX[j].evmLimits.lowerLimit, 
                            //          sweepTX[j].evmLimits.upperLimit, pwr, sweepTX[j].packetFormat);
                        }
                        if (TX_MASK & sweepTX[j].sweepFlag) { 
                            //verifyMask(fp, sweepTxChain[jj], sweepTxChan[i], sweepTX[j].bw, sweepTX[j].rate,
                            //           sweepTX[j].preamble, pwr, sweepTX[j].packetFormat);
                        }
                        if (TX_POWER & sweepTX[j].sweepFlag) { 
                            verifyPower(fp, sweepTxChain[jj], sweepTxChan[i], sweepTX[j].bw, sweepTX[j].rate,
                                        sweepTX[j].preamble, pwr, sweepTX[j].packetFormat);
                        }
                    }
                }
            }
        }
    }
    return;
}

static int is2GChannel(unsigned int channel)
{
    if ((channel >= CHAN2G_START) && (channel <= CHAN2G_END)) 
        return(1);
    else
        return(0); 
}

static int loopRxSweep(FILE *fp, unsigned int rxChain, unsigned int chan, float sensPer, float start, 
                       float end, float step, char* bw, char* rate, char* preamble, char* packetFormat)
{
    fprintf(fp,"	RX_SWEEP_PER\n");
    fprintf(fp,"		#Input Parameters:\n");
    fprintf(fp,"		>ARRAY_HANDLING_METHOD [Integer]  = 1 \n");
    fprintf(fp,"		>BSS_FREQ_MHZ_PRIMARY [Integer]  = %d \n", chan);
    fprintf(fp,"		>BSS_FREQ_MHZ_SECONDARY [Integer]  = 0 \n");
    fprintf(fp,"		>CH_FREQ_MHZ [Integer]  = %d \n", chan);
    fprintf(fp,"		>CH_FREQ_MHZ_PRIMARY_20MHz [Integer]  = 0 \n");
    fprintf(fp,"		>FRAME_COUNT [Integer]  = 0 \n");
    fprintf(fp,"		>NUM_STREAM_11AC [Integer]  = 1 \n");
    fprintf(fp,"		>PROMISCUOUS_MODE [Integer]  = 0 \n");
    fprintf(fp,"		>RX1 [Integer]  = %d \n", rxChain % 2);
    fprintf(fp,"		>RX2 [Integer]  = %d \n", (rxChain / 2) % 2);
    fprintf(fp,"		>RX3 [Integer]  = %d \n", (rxChain / 4) % 2);
    fprintf(fp,"		>RX4 [Integer]  = %d \n", (rxChain / 8) % 2);
    fprintf(fp,"		>RX_IQ_CAL [Integer]  = 0 \n");
    fprintf(fp,"		>SPIKE_REMOVAL [Integer]  = 1 \n");
    fprintf(fp,"		>STOP_AT_PER_PERCENTAGE [Integer]  = 0 \n");
    fprintf(fp,"		>CABLE_LOSS_DB_1 [Double]  = 0.00 \n");
    fprintf(fp,"		>CABLE_LOSS_DB_2 [Double]  = 0.00 \n");
    fprintf(fp,"		>CABLE_LOSS_DB_3 [Double]  = 0.00 \n");
    fprintf(fp,"		>CABLE_LOSS_DB_4 [Double]  = 0.00 \n");
    fprintf(fp,"		>SENS_PER_PERCENTAGE [Double]  = %8.2f \n", sensPer);
    fprintf(fp,"		>START_POWER_LEVEL_DBM [Double]  = %8.2f \n", start);
    fprintf(fp,"		>STOP_POWER_LEVEL_DBM [Double]  = %8.2f \n", end);
    fprintf(fp,"		>SWEEP_STEP_DB [Double]  = %8.2f \n", step);
    fprintf(fp,"		>BSS_BANDWIDTH [String]  = %s \n", bw);
    fprintf(fp,"		>CH_BANDWIDTH [String]  = C%s \n", bw);
    fprintf(fp,"		>DATA_RATE [String]  = %s \n", rate);
    fprintf(fp,"		>PACKET_FORMAT [String]  = %s \n", packetFormat);
    fprintf(fp,"		>PREAMBLE [String]  = %s \n", preamble);
    fprintf(fp,"		>WAVEFORM_NAME [String]  =  \n");
    fprintf(fp,"		#Return Values:\n");
    fprintf(fp,"		<CH_FREQ_MHZ_PRIMARY_40MHz [Integer]  = <,>\n");
    fprintf(fp,"		<CH_FREQ_MHZ_PRIMARY_80MHz [Integer]  = <,>\n");
    fprintf(fp,"		<NUMBER_OF_POWER_LEVELS [Integer]  = <,>\n");
    fprintf(fp,"		<SENS_POWER_LEVEL_DBM [Double]  = <,>\n");
    fprintf(fp,"		<PER_VALUES [ArrayDouble]  = <,>\n");
    fprintf(fp,"		<POWER_LEVELS [ArrayDouble]  = <,>\n");
    fprintf(fp,"		<RSSI [ArrayDouble]  = <,>\n");
    fprintf(fp,"		<ERROR_MESSAGE [String]  = <,>\n");
    fprintf(fp,"		<WAVEFORM_NAME [String]  = <,>\n");
    return(0);
}


static void verifyPower(FILE *fp, unsigned int txChain, unsigned int chan, char* bw, char* rate, char* preamble, float pwr, char* packetFormat)
{
    unsigned int txVSAConnection[4][4] = {{1,2,3,4}, {2,1,3,4}, {3,1,2,4}, {4,1,2,3}};
    int arrayIndex;
    if (txChain % 2 + (txChain / 2) % 2 + (txChain / 4) % 2 + (txChain / 8) % 2 != 1) {
        arrayIndex = 0;
    }
    else {
        arrayIndex = txChain % 2 * 1 + (txChain / 2) % 2 * 2 + (txChain / 4) % 2 * 3 + (txChain / 8) % 2 *4 - 1;
    }
    fprintf(fp,"	TX_VERIFY_POWER\n");
    fprintf(fp,"		#Input Parameters:\n");
    fprintf(fp,"		>BSS_FREQ_MHZ_PRIMARY [Integer]  = %d \n", chan);
    fprintf(fp,"		>BSS_FREQ_MHZ_SECONDARY [Integer]  = 0 \n");
    fprintf(fp,"		>CH_FREQ_MHZ [Integer]  = %d \n", chan);
    fprintf(fp,"		>CH_FREQ_MHZ_PRIMARY_20MHz [Integer]  = 0 \n");
    fprintf(fp,"		>NUM_STREAM_11AC [Integer]  = 1 \n");
    fprintf(fp,"		>TX1 [Integer]  = %d \n", txChain % 2);
    fprintf(fp,"		>TX2 [Integer]  = %d \n", (txChain / 2) % 2);
    fprintf(fp,"		>TX3 [Integer]  = %d \n", (txChain / 4) % 2);
    fprintf(fp,"		>TX4 [Integer]  = %d \n", (txChain / 8) % 2);
    fprintf(fp,"		>CABLE_LOSS_DB_1 [Double]  = 0.00 \n");
    fprintf(fp,"		>CABLE_LOSS_DB_2 [Double]  = 0.00 \n");
    fprintf(fp,"		>CABLE_LOSS_DB_3 [Double]  = 0.00 \n");
    fprintf(fp,"		>CABLE_LOSS_DB_4 [Double]  = 0.00 \n");
    fprintf(fp,"		>SAMPLING_TIME_US [Double]  = 0.00 \n");
    fprintf(fp,"		>TX_POWER_DBM [Double]  = %-10.4f \n", pwr);
    fprintf(fp,"		>BSS_BANDWIDTH [String]  = %s \n", bw);
    fprintf(fp,"		>CH_BANDWIDTH [String]  = C%s \n", bw);
    fprintf(fp,"		>DATA_RATE [String]  = %s \n", rate);
    fprintf(fp,"		>PACKET_FORMAT [String]  = %s \n", packetFormat);
    fprintf(fp,"		>PREAMBLE [String]  = %s \n",preamble);
    fprintf(fp,"		#Return Values:\n");
    fprintf(fp,"		<CH_FREQ_MHZ_PRIMARY_40MHz [Integer]  = <,>\n");
    fprintf(fp,"		<CH_FREQ_MHZ_PRIMARY_80MHz [Integer]  = <,>\n");
    fprintf(fp,"		<CABLE_LOSS_DB_1 [Double]  = <,>\n");
    fprintf(fp,"		<CABLE_LOSS_DB_2 [Double]  = <,>\n");
    fprintf(fp,"		<CABLE_LOSS_DB_3 [Double]  = <,>\n");
    fprintf(fp,"		<CABLE_LOSS_DB_4 [Double]  = <,>\n");
    fprintf(fp,"		<POWER_AVERAGE_DBM [Double]  = <,>\n");
    fprintf(fp,"		<POWER_AVERAGE_MAX_DBM [Double]  = <,>\n");
    fprintf(fp,"		<POWER_AVERAGE_MIN_DBM [Double]  = <,>\n");
    fprintf(fp,"		<POWER_PEAK_DBM [Double]  = <,>\n");
    fprintf(fp,"		<POWER_PEAK_MAX_DBM [Double]  = <,>\n");
    fprintf(fp,"		<POWER_PEAK_MIN_DBM [Double]  = <,>\n");
    fprintf(fp,"		<TX_POWER_DBM [Double]  = <,>\n");
    fprintf(fp,"		<ERROR_MESSAGE [String]  = <,>\n");

    return;
}

static void verifyMask(FILE *fp, unsigned int txChain, unsigned int chan, char* bw, char* rate, char* preamble, float pwr, char* packetFormat)
{
    unsigned int txVSAConnection[4][4] = {{1,2,3,4}, {2,1,3,4}, {3,1,2,4}, {4,1,2,3}};
    int arrayIndex;
    if (txChain % 2 + (txChain / 2) % 2 + (txChain / 4) % 2 + (txChain / 8) % 2 != 1) {
        arrayIndex = 0;
    }
    else {
        arrayIndex = txChain % 2 * 1 + (txChain / 2) % 2 * 2 + (txChain / 4) % 2 * 3 + (txChain / 8) % 2 *4 - 1;
    }
    fprintf(fp,"	TX_VERIFY_MASK\n");
    fprintf(fp,"		#Input Parameters:\n");
    fprintf(fp,"		>BSS_FREQ_MHZ_PRIMARY [Integer]  = %d \n", chan);
    fprintf(fp,"		>BSS_FREQ_MHZ_SECONDARY [Integer]  = 0 \n");
    fprintf(fp,"		>CH_FREQ_MHZ [Integer]  = %d \n", chan);
    fprintf(fp,"		>CH_FREQ_MHZ_PRIMARY_20MHz [Integer]  = 0 \n");
    fprintf(fp,"		>NUM_STREAM_11AC [Integer]  = 1 \n");
    fprintf(fp,"		>TX1 [Integer]  = %d \n", txChain % 2);
    fprintf(fp,"		>TX2 [Integer]  = %d \n", (txChain / 2) % 2);
    fprintf(fp,"		>TX3 [Integer]  = %d \n", (txChain / 4) % 2);
    fprintf(fp,"		>TX4 [Integer]  = %d \n", (txChain / 8) % 2);
    fprintf(fp,"		>CABLE_LOSS_DB_1 [Double]  = 0.00 \n");
    fprintf(fp,"		>CABLE_LOSS_DB_2 [Double]  = 0.00 \n");
    fprintf(fp,"		>CABLE_LOSS_DB_3 [Double]  = 0.00 \n");
    fprintf(fp,"		>CABLE_LOSS_DB_4 [Double]  = 0.00 \n");
    fprintf(fp,"		>OBW_PERCENTAGE [Double]  = 99.00 \n");
    fprintf(fp,"		>SAMPLING_TIME_US [Double]  = 0.00 \n");
    fprintf(fp,"		>TX_POWER_DBM [Double]  = %-10.4f \n", pwr);
    fprintf(fp,"		>BSS_BANDWIDTH [String]  = %s \n", bw);
    fprintf(fp,"		>CH_BANDWIDTH [String]  = C%s \n", bw);
    fprintf(fp,"		>DATA_RATE [String]  = %s \n", rate);
    fprintf(fp,"		>MASK_TEMPLATE [String]  =  \n");
    fprintf(fp,"		>PACKET_FORMAT [String]  = %s \n", packetFormat);
    fprintf(fp,"		>PREAMBLE [String]  = %s \n", preamble);
    fprintf(fp,"		#Return Values:\n");
    fprintf(fp,"		<CH_FREQ_MHZ_PRIMARY_40MHz [Integer]  = <,>\n");
    fprintf(fp,"		<CH_FREQ_MHZ_PRIMARY_80MHz [Integer]  = <,>\n");
    fprintf(fp,"		<CABLE_LOSS_DB_1 [Double]  = <,>\n");
    fprintf(fp,"		<CABLE_LOSS_DB_2 [Double]  = <,>\n");
    fprintf(fp,"		<CABLE_LOSS_DB_3 [Double]  = <,>\n");
    fprintf(fp,"		<CABLE_LOSS_DB_4 [Double]  = <,>\n");
    fprintf(fp,"		<FREQ_AT_MARGIN_LOWER_1 [Double]  = <,>\n");
    fprintf(fp,"		<FREQ_AT_MARGIN_LOWER_2 [Double]  = <,>\n");
    fprintf(fp,"		<FREQ_AT_MARGIN_LOWER_3 [Double]  = <,>\n");
    fprintf(fp,"		<FREQ_AT_MARGIN_LOWER_4 [Double]  = <,>\n");
    fprintf(fp,"		<FREQ_AT_MARGIN_LOWER_5 [Double]  = <,>\n");
    fprintf(fp,"		<FREQ_AT_MARGIN_UPPER_1 [Double]  = <,>\n");
    fprintf(fp,"		<FREQ_AT_MARGIN_UPPER_2 [Double]  = <,>\n");
    fprintf(fp,"		<FREQ_AT_MARGIN_UPPER_3 [Double]  = <,>\n");
    fprintf(fp,"		<FREQ_AT_MARGIN_UPPER_4 [Double]  = <,>\n");
    fprintf(fp,"		<FREQ_AT_MARGIN_UPPER_5 [Double]  = <,>\n");
    fprintf(fp,"		<MARGIN_DB_LOWER_1 [Double]  = <,>\n");
    fprintf(fp,"		<MARGIN_DB_LOWER_2 [Double]  = <,>\n");
    fprintf(fp,"		<MARGIN_DB_LOWER_3 [Double]  = <,>\n");
    fprintf(fp,"		<MARGIN_DB_LOWER_4 [Double]  = <,>\n");
    fprintf(fp,"		<MARGIN_DB_LOWER_5 [Double]  = <,>\n");
    fprintf(fp,"		<MARGIN_DB_UPPER_1 [Double]  = <,>\n");
    fprintf(fp,"		<MARGIN_DB_UPPER_2 [Double]  = <,>\n");
    fprintf(fp,"		<MARGIN_DB_UPPER_3 [Double]  = <,>\n");
    fprintf(fp,"		<MARGIN_DB_UPPER_4 [Double]  = <,>\n");
    fprintf(fp,"		<MARGIN_DB_UPPER_5 [Double]  = <,>\n");
    fprintf(fp,"		<OBW_FREQ_START_MHZ [Double]  = <,>\n");
    fprintf(fp,"		<OBW_FREQ_STOP_MHZ [Double]  = <,>\n");
    fprintf(fp,"		<OBW_MHZ [Double]  = <,>\n");
    fprintf(fp,"		<POWER_AVERAGE_DBM [Double]  = <,>\n");
    fprintf(fp,"		<TX_POWER_DBM [Double]  = <,>\n");
    fprintf(fp,"		<VIOLATION_PERCENT [Double]  = <,>\n");
    fprintf(fp,"		<SPECTRUM_RAW_DATA_X [ArrayDouble]  = <,>\n");
    fprintf(fp,"		<SPECTRUM_RAW_DATA_Y [ArrayDouble]  = <,>\n");
    fprintf(fp,"		<ERROR_MESSAGE [String]  = <,>\n");

    return;
}

static void verifyEvm(FILE *fp, unsigned int txChain, unsigned int chan, char *bw, char* rate, char* preamble,
                      float lowerLimit, float upperLimit, float pwr, char* packetFormat)
{
    unsigned char txAnalysisOrder[4][12] = {"-1,-1,-1,-1", "1,2,3,4", "1,2,3,4", "1,2,3,4"};
    unsigned int txVSAConnection[4][4] = {{1,2,3,4}, {2,1,3,4}, {3,1,2,4}, {4,1,2,3}};	
    int arrayIndex;
    if (txChain % 2 + (txChain / 2) % 2 + (txChain / 4) % 2 + (txChain / 8) % 2 != 1) {
        arrayIndex = 0;
    }
    else {
        arrayIndex = txChain % 2 * 1 + (txChain / 2) % 2 * 2 + (txChain / 4) % 2 * 3 + (txChain / 8) % 2 *4 - 1;
    }
    fprintf(fp, "	TX_VERIFY_EVM ALWAYS_RUN\n");
    fprintf(fp, "		#Input Parameters:\n");
    fprintf(fp, "		>BSS_FREQ_MHZ_PRIMARY [Integer]  = %d \n", chan);
    fprintf(fp, "		>BSS_FREQ_MHZ_SECONDARY [Integer]  = 0 \n");
    fprintf(fp, "		>CH_FREQ_MHZ [Integer]  = %d \n", chan);
    fprintf(fp, "		>CH_FREQ_MHZ_PRIMARY_20MHz [Integer]  = 0 \n");
    fprintf(fp, "		>NUM_STREAM_11AC [Integer]  = 1 \n");
    fprintf(fp, "		>TX1 [Integer]  = %d \n", txChain % 2);
    fprintf(fp, "		>TX2 [Integer]  = %d \n", (txChain / 2) % 2);
    fprintf(fp, "		>TX3 [Integer]  = %d \n", (txChain / 4) % 2);
    fprintf(fp, "		>TX4 [Integer]  = %d \n", (txChain / 8) % 2);
    fprintf(fp, "		>CABLE_LOSS_DB_1 [Double]  = 0.00 \n");
    fprintf(fp, "		>CABLE_LOSS_DB_2 [Double]  = 0.00 \n");
    fprintf(fp, "		>CABLE_LOSS_DB_3 [Double]  = 0.00 \n");
    fprintf(fp, "		>CABLE_LOSS_DB_4 [Double]  = 0.00 \n");
    fprintf(fp, "		>SAMPLING_TIME_US [Double]  = 0.00 \n");
    fprintf(fp, "		>TX_POWER_DBM [Double]  = %-10.4f \n", pwr);
    fprintf(fp, "		>BSS_BANDWIDTH [String]  = %s \n", bw);
    fprintf(fp, "		>CH_BANDWIDTH [String]  = C%s \n", bw);
    fprintf(fp, "		>DATA_RATE [String]  = %s \n", rate);
    fprintf(fp, "		>PACKET_FORMAT [String]  = %s \n", packetFormat);
    fprintf(fp, "		>PREAMBLE [String]  = %s \n", preamble);
    fprintf(fp, "		#Return Values:\n");
    fprintf(fp, "		<CH_FREQ_MHZ_PRIMARY_40MHz [Integer]  = <,>\n");
    fprintf(fp, "		<CH_FREQ_MHZ_PRIMARY_80MHz [Integer]  = <,>\n");
    fprintf(fp, "		<SPATIAL_STREAM [Integer]  = <,>\n");
    fprintf(fp, "		<AMP_ERR_DB [Double]  = <,>\n");
    fprintf(fp, "		<AMP_ERR_DB_1 [Double]  = <,>\n");
    fprintf(fp, "		<AMP_ERR_DB_2 [Double]  = <,>\n");
    fprintf(fp, "		<AMP_ERR_DB_3 [Double]  = <,>\n");
    fprintf(fp, "		<AMP_ERR_DB_4 [Double]  = <,>\n");
    fprintf(fp, "		<CABLE_LOSS_DB_1 [Double]  = <,>\n");
    fprintf(fp, "		<CABLE_LOSS_DB_2 [Double]  = <,>\n");
    fprintf(fp, "		<CABLE_LOSS_DB_3 [Double]  = <,>\n");
    fprintf(fp, "		<CABLE_LOSS_DB_4 [Double]  = <,>\n");
    fprintf(fp, "		<DATA_RATE [Double]  = <,>\n");
    fprintf(fp,"		<EVM_AVG_1 [Double]  = <%-6.2f,%-6.2f>\n", lowerLimit, upperLimit);
    fprintf(fp,"		<EVM_AVG_2 [Double]  = <%-6.2f,%-6.2f>\n", lowerLimit, upperLimit);
    fprintf(fp,"		<EVM_AVG_3 [Double]  = <%-6.2f,%-6.2f>\n", lowerLimit, upperLimit);
    fprintf(fp,"		<EVM_AVG_4 [Double]  = <%-6.2f,%-6.2f>\n", lowerLimit, upperLimit);
    fprintf(fp,"		<EVM_AVG_DB [Double]  = <%-6.2f,%-6.2f>\n", lowerLimit, upperLimit);
    fprintf(fp, "		<EVM_MAX_1 [Double]  = <,>\n");
    fprintf(fp, "		<EVM_MAX_2 [Double]  = <,>\n");
    fprintf(fp, "		<EVM_MAX_3 [Double]  = <,>\n");
    fprintf(fp, "		<EVM_MAX_4 [Double]  = <,>\n");
    fprintf(fp, "		<EVM_MIN_1 [Double]  = <,>\n");
    fprintf(fp, "		<EVM_MIN_2 [Double]  = <,>\n");
    fprintf(fp, "		<EVM_MIN_3 [Double]  = <,>\n");
    fprintf(fp, "		<EVM_MIN_4 [Double]  = <,>\n");
    fprintf(fp, "		<EVM_PK_DB [Double]  = <,>\n");
    fprintf(fp, "		<FREQ_ERROR_AVG [Double]  = <,>\n");
    fprintf(fp, "		<FREQ_ERROR_MAX [Double]  = <-20.00,20.00>\n");
    fprintf(fp, "		<FREQ_ERROR_MIN [Double]  = <,>\n");
    fprintf(fp, "		<PHASE_ERR [Double]  = <,>\n");
    fprintf(fp, "		<PHASE_ERR_1 [Double]  = <,>\n");
    fprintf(fp, "		<PHASE_ERR_2 [Double]  = <,>\n");
    fprintf(fp, "		<PHASE_ERR_3 [Double]  = <,>\n");
    fprintf(fp, "		<PHASE_ERR_4 [Double]  = <,>\n");
    fprintf(fp, "		<PHASE_NOISE_RMS_ALL [Double]  = <,>\n");
    fprintf(fp,"		<POWER_AVG_1 [Double]  = <%-5.2f,%-5.2f>\n", (pwr + POWER_LOWER_LIMIT), (pwr + POWER_HIGHER_LIMIT));
    fprintf(fp,"		<POWER_AVG_2 [Double]  = <%-5.2f,%-5.2f>\n", (pwr + POWER_LOWER_LIMIT), (pwr + POWER_HIGHER_LIMIT));
    fprintf(fp,"		<POWER_AVG_3 [Double]  = <%-5.2f,%-5.2f>\n", (pwr + POWER_LOWER_LIMIT), (pwr + POWER_HIGHER_LIMIT));
    fprintf(fp,"		<POWER_AVG_4 [Double]  = <%-5.2f,%-5.2f>\n", (pwr + POWER_LOWER_LIMIT), (pwr + POWER_HIGHER_LIMIT));
    fprintf(fp,"		<POWER_AVG_DBM [Double]  = <%-5.2f,%-5.2f>\n", (pwr + POWER_LOWER_LIMIT), (pwr + POWER_HIGHER_LIMIT));
    fprintf(fp, "		<POWER_MAX_1 [Double]  = <,>\n");
    fprintf(fp, "		<POWER_MAX_2 [Double]  = <,>\n");
    fprintf(fp, "		<POWER_MAX_3 [Double]  = <,>\n");
    fprintf(fp, "		<POWER_MAX_4 [Double]  = <,>\n");
    fprintf(fp, "		<POWER_MIN_1 [Double]  = <,>\n");
    fprintf(fp, "		<POWER_MIN_2 [Double]  = <,>\n");
    fprintf(fp, "		<POWER_MIN_3 [Double]  = <,>\n");
    fprintf(fp, "		<POWER_MIN_4 [Double]  = <,>\n");
    fprintf(fp, "		<SYMBOL_CLK_ERR [Double]  = <,>\n");
    fprintf(fp, "		<TX_POWER_DBM [Double]  = <,>\n");
    fprintf(fp, "		<ERROR_MESSAGE [String]  = <,>\n");
    return;
}

static void sweepEvm(FILE *fp, unsigned int txChain, unsigned int chan, char* bw, char* rate, char* preamble, 
                     float startPower, float endPower, float step, char* packetFormat)
{
    float pwr;
    unsigned char txAnalysisOrder[4][12] = {"-1,-1,-1,-1", "1,2,3,4", "1,2,3,4", "1,2,3,4"};
    unsigned int txVSAConnection[4][4] = {{1,2,3,4}, {2,1,3,4}, {3,1,2,4}, {4,1,2,3}};
    int arrayIndex;
    if (txChain % 2 + (txChain / 2) % 2 + (txChain / 4) % 2 + (txChain / 8) % 2 != 1) {
        arrayIndex = 0;
    }
    else {
        arrayIndex = txChain % 2 * 1 + (txChain / 2) % 2 * 2 + (txChain / 4) % 2 * 3 + (txChain / 8) % 2 *4 - 1;
    }
    fprintf(fp,"	TX_EVM_VS_LEVELS\n");
    fprintf(fp,"		#Input Parameters:\n");
    fprintf(fp,"		>ARRAY_HANDLING_METHOD [Integer]  = 1 \n");
    fprintf(fp,"		>BSS_FREQ_MHZ_PRIMARY [Integer]  = %d \n", chan);
    fprintf(fp,"		>BSS_FREQ_MHZ_SECONDARY [Integer]  = 0 \n");
    fprintf(fp,"		>CH_FREQ_MHZ [Integer]  = %d \n", chan);
    fprintf(fp,"		>CH_FREQ_MHZ_PRIMARY_20MHz [Integer]  = 0 \n");
    fprintf(fp,"		>NUM_STREAM_11AC [Integer]  = 1 \n");
    fprintf(fp,"		>TX1 [Integer]  = %d \n", txChain % 2);
    fprintf(fp,"		>TX2 [Integer]  = %d \n", (txChain / 2) % 2);
    fprintf(fp,"		>TX3 [Integer]  = %d \n", (txChain / 4) % 2);
    fprintf(fp,"		>TX4 [Integer]  = %d \n", (txChain / 8) % 2);
    fprintf(fp,"		>CABLE_LOSS_DB_1 [Double]  = 0.00 \n");
    fprintf(fp,"		>CABLE_LOSS_DB_2 [Double]  = 0.00 \n");
    fprintf(fp,"		>CABLE_LOSS_DB_3 [Double]  = 0.00 \n");
    fprintf(fp,"		>CABLE_LOSS_DB_4 [Double]  = 0.00 \n");
    fprintf(fp,"		>SAMPLING_TIME_US [Double]  = 0.00 \n");
    fprintf(fp,"		>BSS_BANDWIDTH [String]  = %s \n", bw);
    fprintf(fp,"		>CH_BANDWIDTH [String]  = C%s \n", bw);
    fprintf(fp,"		>DATA_RATE [String]  = %s \n", rate);
    fprintf(fp,"		>PACKET_FORMAT [String]  = %s \n", packetFormat);
    fprintf(fp,"		>PREAMBLE [String]  = %s \n", preamble);
    fprintf(fp,"		>TX_POWER_LEVELS_DBM [String]  = ");
    for (pwr=startPower;pwr<=endPower;pwr +=step) {
        fprintf(fp," %-10.4f ", pwr);
    }
    fprintf(fp,"		\n");
    fprintf(fp,"		#Return Values:\n");
    fprintf(fp,"		<CH_FREQ_MHZ_PRIMARY_40MHz [Integer]  = <,>\n");
    fprintf(fp,"		<CH_FREQ_MHZ_PRIMARY_80MHz [Integer]  = <,>\n");
    fprintf(fp,"		<NUMBER_OF_POWER_LEVELS [Integer]  = <,>\n");
    fprintf(fp,"		<SPATIAL_STREAM [Integer]  = <,>\n");
    fprintf(fp,"		<DATA_RATE [Double]  = <,>\n");
    fprintf(fp,"		<EVM_VALUES_AVG_DB [ArrayDouble]  = <,>\n");
    fprintf(fp,"		<POWER_LEVELS_AVG_DBM [ArrayDouble]  = <,>\n");
    fprintf(fp,"		<POWER_LEVELS_DBM_1 [ArrayDouble]  = <,>\n");
    fprintf(fp,"		<POWER_LEVELS_DBM_2 [ArrayDouble]  = <,>\n");
    fprintf(fp,"		<POWER_LEVELS_DBM_3 [ArrayDouble]  = <,>\n");
    fprintf(fp,"		<POWER_LEVELS_DBM_4 [ArrayDouble]  = <,>\n");
    fprintf(fp,"		<ERROR_MESSAGE [String]  = <,>\n");
    return;
}

