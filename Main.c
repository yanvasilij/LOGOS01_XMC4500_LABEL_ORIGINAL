/*
 * Main.c
 *
 *  Created on: 23/lug/2013
 *      Author: manfre
 */


#include <DAVE3.h>			//Declarations from DAVE3 Code Generation (includes SFR declaration)
#include "GPIO.h"


#define teststep 1
#define sectionparamsize 63
#define boardconfigsize 156
#define pinmappingsize 48
#define boardconfigoffset sectionparamsize*8
#define pinmappingoffset boardconfigoffset+boardconfigsize
#define memstep 1
#define readfrommemory 1
//#define dbgvar4ramp 1
#define sectioneightenable 1

typedef VADC_G_TypeDef XMC_VADC_GROUP_t; /**< Type defined the device header file vadc group register structure
                                             type to VADC Group type*/

typedef enum XMC_VADC_CHANNEL_REF

{

  XMC_VADC_CHANNEL_REF_INTREF = 0, /**< Internal VARef */

  XMC_VADC_CHANNEL_REF_ALT_CH0    /**< External voltage available on Channel-0 of the perticular group */

} XMC_VADC_CHANNEL_REF_t;


extern status_t Flash002_EraseSector  ( uint32_t  Address ) __attribute__ ((section (".ram_code")));
extern void FLASH002_Init (void) __attribute__ ((section (".ram_code")));
extern status_t  Flash002_WritePage (uint32_t Address, const uint32_t pBuf[]) __attribute__ ((section (".ram_code")));
void MAIN_CLOCK_HANDLER(void* Temp);
void RefreshDiagnoHandler(void* Temp);
void CalcTarCurr(int secid);
void CalcTarPwm(int secid);
void CalcActPwm(int secid,uint32_t tmpcurr);
void SetActPwm(int secid);
void CalculateTxChecksum(uint8_t len);
uint16_t CalculateRxChecksum(void);
void GetSPIData(char mode);
void SetupPinMapping(void);
void SetupAnalogInputs(void);
void SetupAuxOutput(void);
void SetupCoeff(uint8_t SecId);
uint32_t flashslotsize=FLASH002_PAGE_SIZE/4;
float looptime=100;    //tempo di ciclo in ms
float ma_for_lev=0.725; // coefficiente ma/livelli adc

void XMC_VADC_GROUP_ChannelSetInputReference(const ADCCH001_HandleType* HandlePtr, const XMC_VADC_CHANNEL_REF_t ref);

handle_t TimerId1,TimerId2;
uint8_t sectionrecoverydelaythr=11;
uint8_t sectionrecoverydelay[8];

uint8_t tmpmeasstarted=0;
uint8_t sendflag=0;
uint8_t sectionconf=0xFF;
uint8_t analoginmode[10];
uint8_t analoginmodemem[10];
uint8_t auxvolt;
uint8_t sectionname[8][8];
uint8_t analoginname[10][8];
uint8_t pinmapping[8][6];
uint8_t floating[8];

uint16_t spidatain[16];
uint8_t spidatainenable=0;
uint8_t analoginenable=0;
uint8_t digitalinenable=0;
uint8_t auxreading=0;
uint8_t sectionstatus[8];
uint8_t digitalinstatus[16];


uint32_t dietemp;
uint8_t loopfreq[8];
uint8_t ditheractive[8];
int32_t ditherampl[8];
CAN001_MessageHandleType CanRecMsgObj;
CAN001_MessageHandleType CanExtRecMsgObj;
uint16_t Results[16];
uint32_t pwmtar[8];
uint32_t actpwm[8];
int readfilter=0;
uint32_t avgcurr[8];
uint32_t actualcurr[8];
uint8_t avgcurrindex[8];
float targcurr[8];
float acttargcurr[8];
float inputlevel[8];
uint8_t inoutmap[8][2];
uint8_t currsec=0;
uint16_t ReadData;
uint8_t txbuf[256];
uint8_t rxbuf[256];
uint16_t rxindex=0;
uint16_t txindex=0;
uint16_t txlen=0;
uint16_t txlendiagno=0;
uint8_t adcsecid=0;
uint16_t ADC0_CH0_BUFFER[100];
uint16_t ADC0_CH5_BUFFER[100];
uint16_t ADC0_CH6_BUFFER[100];
uint16_t ADC0_CH4_BUFFER[100];
uint16_t ADC1_CH1_BUFFER[100];
uint16_t ADC1_CH7_BUFFER[100];
uint16_t ADC1_CH8_BUFFER[100];
uint16_t ADC1_CH9_BUFFER[100];
uint8_t adc0_ch0_index=0;
uint8_t startdiagno=0;
uint8_t diagnodem=0;
uint8_t diagnoindex=0;
uint8_t uartmsglen=1;
uint8_t uarttimeout=0;
uint16_t imaxv1[8];
uint16_t imaxv2[8];
uint16_t iminv1[8];
uint16_t iminv2[8];
uint16_t i_0_v1[8];
uint16_t i_100_v1[8];
uint16_t i_100_v1_lev[8];
uint16_t i_0_v2[8];
uint16_t i_100_v2[8];
uint16_t i_100_v2_lev[8];
float maxctrlv1[8];
float minctrlv1[8];
float maxctrlv2[8];
float minctrlv2[8];
uint8_t configsec[8];
float piv1[8];
float piv2[8];

float smoothdownv1[8];
float smoothupv1[8];
float smoothdownv2[8];
float smoothupv2[8];

uint32_t slopeupipointsv1[3][8];
float slopeupipointsv1_lev[3][8];
uint16_t slopeuptpointsv1[4][8];
float slopeupv1[4][8];

uint32_t slopedownipointsv1[3][8];
float slopedownipointsv1_lev[3][8];
uint16_t slopedowntpointsv1[4][8];
float slopedownv1[4][8];

uint32_t slopeupipointsv2[3][8];
float slopeupipointsv2_lev[3][8];
uint16_t slopeuptpointsv2[4][8];
float slopeupv2[4][8];

uint32_t slopedownipointsv2[3][8];
float slopedownipointsv2_lev[3][8];
uint16_t slopedowntpointsv2[4][8];
float slopedownv2[4][8];

uint8_t inc=0;
uint8_t dec=0;
uint16_t sentdata=0;

uint32_t flash_status;
uint32_t* address = FLASH002_SECTOR11_BASE;
uint32_t membuffer[(sectionparamsize*8)+boardconfigsize+pinmappingsize];
uint32_t flashwritingbuffer[FLASH002_PAGE_SIZE/4];


uint16_t NoMappedVal1;
uint16_t G2Ch2Val;
uint16_t G2Ch1Val;
uint16_t G2Ch4Val;
uint16_t G2Ch3Val;
uint16_t G2Ch5Val;

uint16_t G3Ch3Val;
uint16_t G3Ch1Val;
uint16_t G3Ch4Val;
uint16_t G3Ch5Val;
uint16_t G3Ch2Val;
uint16_t NoMappedVal2;

static uint8_t CanDataRx[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
static uint8_t CanDataExtRx[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

uint32_t tmpcurr[8];
static volatile uint8_t newvalue[8];
static volatile bool timertrigger[8];

uint8_t memioconfig=0;
uint8_t memsectionconfig=0;
uint8_t mempinmapping=0;
uint8_t SectionIndex=0;

uint8_t can1DMenable=0;
uint8_t can2DMenable=0;
uint8_t can1DMstatus=1;
uint8_t can2DMstatus=1;
uint8_t analoginDMenable=0;

int32_t diagnocurr=0;
uint8_t stopdiagno=0;
uint8_t ackstartdiagno=0;

#ifdef dbgvar4ramp
uint32_t dbgcnt[32];
#endif

int main(void)
{
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)
	uint32_t i,k;
	uint32_t membaseaddress;
    uint32_t flashpageindex;
    uint32_t flashtotalsize=sectionparamsize*8+boardconfigsize+pinmappingsize;
    uint32_t flashupperindex=flashtotalsize/flashslotsize;

	DAVE_Init();			// Initialization of DAVE Apps
	IO004_Init();

	P2_1_set_mode(INPUT);
	P2_1_set_hwsel(HW1);

	TMPS001_Enable();

	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle0);
	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle1);
	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle2);
	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle3);

	#ifdef sectioneightenable
	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle4);
	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle5);
	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle6);
	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle7);
	#endif

	spidatainenable=1;
	analoginenable=1;
	digitalinenable=1;

	TimerId1 = SYSTM001_CreateTimer(100,SYSTM001_PERIODIC,MAIN_CLOCK_HANDLER,NULL);
	TimerId2 = SYSTM001_CreateTimer(10,SYSTM001_PERIODIC,RefreshDiagnoHandler,NULL);
	SYSTM001_StartTimer(TimerId1);
	SYSTM001_StartTimer(TimerId2);

	for(i=0;i<(sectionparamsize*8)+boardconfigsize+pinmappingsize;i++)
	{
		membuffer[i]=*(address+i);
	}

	sectionconf = *(address+boardconfigoffset);
	for (i = 0; i < 10; i++) {
		analoginmodemem[i] = *(address+boardconfigoffset+1+i);
		if((analoginmodemem[i] & 0x80)!=0)
		{
			analoginmode[i]=analoginmodemem[i] & 0x7F;
			analoginDMenable=i+1;
		}
		else
		{
			analoginmode[i]=analoginmodemem[i];
		}
	}

	auxvolt = *(address+boardconfigoffset+11);


	for (i = 0; i < 8; i++) {
		for (k = 0; k < 8; k++) {
			sectionname[i][k] = *(address+boardconfigoffset+12+(i * 8)+k);
		}
	}

	for (i = 0; i < 10; i++) {
		for (k = 0; k < 8; k++) {
			analoginname[i][k] = *(address+boardconfigoffset+76+(i * 8)+k);
		}
	}

	for(k=0;k<8;k++)
	{
			for(i=0;i<6;i++)
			{
				pinmapping[k][i]=*(address+pinmappingoffset+k*6+i);
			}

			timertrigger[k]=FALSE;
	}

	SetupAuxOutput();
	SetupAnalogInputs();
	SetupPinMapping();

	//Partenza ADC Aux
	ADC002_InitializeQueue(&ADC002_Handle2);
	ADC002_InitializeQueue(&ADC002_Handle3);


	#ifdef readfrommemory
	for(i=0;i<8;i++)
	{
	membaseaddress=sectionparamsize*i;

	loopfreq[i] = *(address+membaseaddress);
	ditherampl[i] = *(address+membaseaddress+1*memstep);
	configsec[i] = *(address+membaseaddress+2*memstep);

	imaxv1[i] = *(address+membaseaddress+3*memstep) * 256 + *(address+membaseaddress+4*memstep);
	iminv1[i] = *(address+membaseaddress+5*memstep) * 256 + *(address+membaseaddress+6*memstep);
	maxctrlv1[i] = *(address+membaseaddress+7*memstep);
	minctrlv1[i] = *(address+membaseaddress+8*memstep);

	i_0_v1[i] = *(address+membaseaddress+9*memstep) * 256 + *(address+membaseaddress+10*memstep);
	i_100_v1[i] = *(address+membaseaddress+11*memstep) * 256 + *(address+membaseaddress+12*memstep);

	slopeupipointsv1[0][i] = *(address+membaseaddress+13*memstep) * 256 + *(address+membaseaddress+14*memstep);
	slopeupipointsv1[1][i] = *(address+membaseaddress+15*memstep) * 256 + *(address+membaseaddress+16*memstep);
	slopeupipointsv1[2][i] = *(address+membaseaddress+17*memstep) * 256 + *(address+membaseaddress+18*memstep);

	slopeuptpointsv1[0][i] = *(address+membaseaddress+19*memstep);
	slopeuptpointsv1[1][i] = *(address+membaseaddress+20*memstep);
	slopeuptpointsv1[2][i] = *(address+membaseaddress+21*memstep);
	slopeuptpointsv1[3][i] = *(address+membaseaddress+22*memstep);

	slopedownipointsv1[0][i] = *(address+membaseaddress+23*memstep) * 256 + *(address+membaseaddress+24*memstep);
	slopedownipointsv1[1][i] = *(address+membaseaddress+25*memstep) * 256 + *(address+membaseaddress+26*memstep);
	slopedownipointsv1[2][i] = *(address+membaseaddress+27*memstep) * 256 + *(address+membaseaddress+28*memstep);

	slopedowntpointsv1[0][i] = *(address+membaseaddress+29*memstep);
	slopedowntpointsv1[1][i] = *(address+membaseaddress+30*memstep);
	slopedowntpointsv1[2][i] = *(address+membaseaddress+31*memstep);
	slopedowntpointsv1[3][i] = *(address+membaseaddress+32*memstep);

	imaxv2[i] = *(address+membaseaddress+33*memstep) * 256 + *(address+membaseaddress+34*memstep);
	iminv2[i] = *(address+membaseaddress+35*memstep) * 256 + *(address+membaseaddress+36*memstep);
	maxctrlv2[i] = *(address+membaseaddress+37*memstep);
	minctrlv2[i] = *(address+membaseaddress+38*memstep);

	i_0_v2[i] = *(address+membaseaddress+39*memstep) * 256 + *(address+membaseaddress+40*memstep);
	i_100_v2[i] = *(address+membaseaddress+41*memstep) * 256 + *(address+membaseaddress+42*memstep);

	slopeupipointsv2[0][i] = *(address+membaseaddress+43*memstep) * 256 + *(address+membaseaddress+44*memstep);
	slopeupipointsv2[1][i] = *(address+membaseaddress+45*memstep) * 256 + *(address+membaseaddress+46*memstep);
	slopeupipointsv2[2][i] = *(address+membaseaddress+47*memstep) * 256 + *(address+membaseaddress+48*memstep);

	slopeuptpointsv2[0][i] = *(address+membaseaddress+49*memstep);
	slopeuptpointsv2[1][i] = *(address+membaseaddress+50*memstep);
	slopeuptpointsv2[2][i] = *(address+membaseaddress+51*memstep);
	slopeuptpointsv2[3][i] = *(address+membaseaddress+52*memstep);

	slopedownipointsv2[0][i] = *(address+membaseaddress+53*memstep) * 256 + *(address+membaseaddress+54*memstep);
	slopedownipointsv2[1][i] = *(address+membaseaddress+55*memstep) * 256 + *(address+membaseaddress+56*memstep);
	slopedownipointsv2[2][i] = *(address+membaseaddress+57*memstep) * 256 + *(address+membaseaddress+58*memstep);

	slopedowntpointsv2[0][i] = *(address+membaseaddress+59*memstep);
	slopedowntpointsv2[1][i] = *(address+membaseaddress+60*memstep);
	slopedowntpointsv2[2][i] = *(address+membaseaddress+61*memstep);
	slopedowntpointsv2[3][i] = *(address+membaseaddress+62*memstep);

	SetupCoeff(i);
	}

    #else

	piv1[0]=5.882;
	//qiv1[0]=500;
	piv2[0]=5.882;
	//qiv2[0]=500;

	piv1[1]=6.122;
	//qiv1[1]=500;
	piv2[1]=6.122;
	//qiv2[1]=500;

	piv1[2]=2.55;
	//qiv1[2]=500;
	piv2[2]=2.55;
	//qiv2[2]=500;

	piv1[3]=2.55;
	//qiv1[3]=500;
	piv2[3]=2.55;
	//qiv2[3]=500;

	piv1[4]=2.55;
	//qiv1[4]=500;
	piv2[4]=2.55;
	//qiv2[4]=500;

	piv1[5]=2.55;
	//qiv1[4]=500;
	piv2[5]=2.55;
	//qiv2[4]=500;


	minctrlv1[0]=1;
	maxctrlv1[0]=99; //35
	minctrlv2[0]=-1;
	maxctrlv2[0]=-99; //-35

	minctrlv1[1]=1;
	maxctrlv1[1]=99;
	minctrlv2[1]=-1;
	maxctrlv2[1]=-99;

	minctrlv1[2]=1;
	maxctrlv1[2]=99;
	minctrlv2[2]=-1;
	maxctrlv2[2]=-99;

	minctrlv1[3]=1;
	maxctrlv1[3]=99;
	minctrlv2[3]=-1;
	maxctrlv2[3]=-99;

	minctrlv1[4]=1;
	maxctrlv1[4]=99;
	minctrlv2[4]=-1;
	maxctrlv2[4]=-99;

	minctrlv1[5]=1;
	maxctrlv1[5]=99;
	minctrlv2[5]=-1;
	maxctrlv2[5]=-99;

	smoothdownv1[0]=500;
	smoothdownv1[1]=500;
	smoothdownv1[2]=500;
	smoothdownv1[3]=500;
	smoothdownv1[4]=500;
	smoothdownv1[5]=500;

	smoothdownv2[0]=500;
	smoothdownv2[1]=500;
	smoothdownv2[2]=500;
	smoothdownv2[3]=500;
	smoothdownv2[4]=500;
	smoothdownv2[5]=500;

	smoothupv1[0]=150; //0.631;//1.277;
	smoothupv1[1]=150;
	smoothupv1[2]=150;
	smoothupv1[3]=150;
	smoothupv1[4]=150;
	smoothupv1[5]=150;

	smoothupv2[0]=150; //1.492;//2.415;
	smoothupv2[1]=150;
	smoothupv2[2]=150;
	smoothupv2[3]=150;
	smoothupv2[4]=150;
	smoothupv2[5]=150;

	/* OLD
	 * slopeupipointsv1[0][0]=690/0.725;
	slopeupipointsv1[1][0]=700/0.725;
	slopeupipointsv1[2][0]=710/0.725;

	slopeupipointsv2[0][0]=770/0.725;
	slopeupipointsv2[1][0]=780/0.725;
	slopeupipointsv2[2][0]=790/0.725;

	slopedownipointsv1[0][0]=710/0.725;
	slopedownipointsv1[1][0]=700/0.725;
	slopedownipointsv1[2][0]=690/0.725;

	slopedownipointsv2[0][0]=790/0.725;
	slopedownipointsv2[1][0]=780/0.725;
	slopedownipointsv2[2][0]=770/0.725;*/

	/*slopeupipointsv1[0][0]=550/0.725;
	slopeupipointsv1[1][0]=650/0.725;
	slopeupipointsv1[2][0]=700/0.725;

	slopeupipointsv2[0][0]=550/0.725;
	slopeupipointsv2[1][0]=650/0.725;
	slopeupipointsv2[2][0]=700/0.725;

	slopedownipointsv1[0][0]=680/0.725;
	slopedownipointsv1[1][0]=600/0.725;
	slopedownipointsv1[2][0]=550/0.725;

	slopedownipointsv2[0][0]=680/0.725;
	slopedownipointsv2[1][0]=600/0.725;
	slopedownipointsv2[2][0]=550/0.725;


	slopeupipointsv1[0][1]=550/0.725;
	slopeupipointsv1[1][1]=650/0.725;
	slopeupipointsv1[2][1]=700/0.725;

	slopeupipointsv2[0][1]=550/0.725;
	slopeupipointsv2[1][1]=650/0.725;
	slopeupipointsv2[2][1]=700/0.725;

	slopedownipointsv1[0][1]=680/0.725;
	slopedownipointsv1[1][1]=600/0.725;
	slopedownipointsv1[2][1]=550/0.725;

	slopedownipointsv2[0][1]=680/0.725;
	slopedownipointsv2[1][1]=600/0.725;
	slopedownipointsv2[2][1]=550/0.725;

	slopeupipointsv1[0][3]=550/0.725;
	slopeupipointsv1[1][3]=650/0.725;
	slopeupipointsv1[2][3]=700/0.725;

	slopeupipointsv2[0][3]=550/0.725;
	slopeupipointsv2[1][3]=650/0.725;
	slopeupipointsv2[2][3]=700/0.725;

	slopedownipointsv1[0][3]=680/0.725;
	slopedownipointsv1[1][3]=600/0.725;
	slopedownipointsv1[2][3]=550/0.725;

	slopedownipointsv2[0][3]=680/0.725;
	slopedownipointsv2[1][3]=600/0.725;
	slopedownipointsv2[2][3]=550/0.725;

	configsec[0]=0x00;
	configsec[1]=0x00;
	configsec[2]=0x00;
	configsec[3]=0x00;
	configsec[4]=0x00;*/

	/* OLD
	 * slopeupv1[0][0]=1; //20;
	slopeupv1[1][0]=1;
	slopeupv1[2][0]=1;
	slopeupv1[3][0]=0.5;

	slopeupv2[0][0]=2; //20;
	slopeupv2[1][0]=2;
	slopeupv2[2][0]=2;
	slopeupv2[3][0]=0.7;

	slopedownv1[0][0]=-20;
	slopedownv1[1][0]=-20;
	slopedownv1[2][0]=-20;
	slopedownv1[3][0]=-20;

	slopedownv2[0][0]=-20;
	slopedownv2[1][0]=-20;
	slopedownv2[2][0]=-20;
	slopedownv2[3][0]=-20;*/

	/*slopeupv1[0][1]=100;
	slopeupv1[1][1]=0.1;
	slopeupv1[2][1]=20;
	slopeupv1[3][1]=20;

	slopeupv2[0][1]=100;
	slopeupv2[1][1]=0.1;
	slopeupv2[2][1]=20;
	slopeupv2[3][1]=20;

	slopedownv1[0][1]=-20;
	slopedownv1[1][1]=-20;
	slopedownv1[2][1]=-0.1;
	slopedownv1[3][1]=-100;

	slopedownv2[0][1]=-20;
	slopedownv2[1][1]=-20;
	slopedownv2[2][1]=-0.1;
	slopedownv2[3][1]=-100;*/

	/* OLD
	 * slopeupv1[0][3]=1;
	slopeupv1[1][3]=1;
	slopeupv1[2][3]=1;
	slopeupv1[3][3]=1;

	slopeupv2[0][3]=1;
	slopeupv2[1][3]=1;
	slopeupv2[2][3]=1;
	slopeupv2[3][3]=1;

	slopedownv1[0][3]=-1;
	slopedownv1[1][3]=-1;
	slopedownv1[2][3]=-1;
	slopedownv1[3][3]=-1;

	slopedownv2[0][3]=-1;
	slopedownv2[1][3]=-1;
	slopedownv2[2][3]=-1;
	slopedownv2[3][3]=-1;*/
    #endif

	//Partenza ADC Correnti 1
    ADC002_InitializeQueue(&ADC002_Handle0);
    //Partenza ADC Correnti 2
	ADC002_InitializeQueue(&ADC002_Handle1);


	while(1)
	{
		if(TMPS001_GetStatus() == TMPS001_READY && tmpmeasstarted==0)
		{
			TMPS001_StartMeasurement();
			tmpmeasstarted=1;
		}
		else if(TMPS001_GetStatus() == TMPS001_READY && tmpmeasstarted==1)
		{
			dietemp=TMPS001_ReadTemp();
			tmpmeasstarted=0;
		}

		if(sendflag==1)
		{
			sentdata=0;
			while(sentdata<txlen)
			{
				sentdata=sentdata+UART001_WriteDataBytes(&UART001_Handle0,&txbuf[sentdata],txlen-sentdata);
			}
			sendflag=0;
		}

		if(memioconfig==0 && memsectionconfig==0 && mempinmapping==0)
		{
			if (auxreading != 0) {
				if (auxreading == 1) {
					GetSPIData(1);
					auxreading++;
				} else if (auxreading >= 3) {
					GetSPIData(2);
					auxreading = 0;
				}
			}

			for (i = 0; i < 8; i++) {
				if (newvalue[i] == 1) {

						CalcTarPwm(i);
						actpwm[i] = pwmtar[i];
						newvalue[i] = 0;
				}
			}
		}
		else
		{
			PWMSP002_SetCompare(&PWMSP002_Handle0,3333,0);
			PWMSP002_SetCompare(&PWMSP002_Handle1,3333,0);
			PWMSP002_SetCompare(&PWMSP002_Handle2,3333,0);
			PWMSP002_SetCompare(&PWMSP002_Handle3,3333,0);
			PWMSP002_SetCompare(&PWMSP002_Handle4,3333,0);
			PWMSP002_SetCompare(&PWMSP002_Handle5,3333,0);
			PWMSP002_SetCompare(&PWMSP002_Handle6,3333,0);
			PWMSP002_SetCompare(&PWMSP002_Handle7,3333,0);

			if(memioconfig==1)
			{
	 		 	membaseaddress=boardconfigoffset;

	 		 	flash_status=Flash002_EraseSector(FLASH002_SECTOR11_BASE);

	 			if(flash_status==DAVEApp_SUCCESS)
	 			{

	 				flashpageindex=0;
	 				do
	 				{
	 					for(i=0;i<flashslotsize;i++)
	 					{
	 						flashwritingbuffer[i]=membuffer[i+flashpageindex*flashslotsize];
	 					}

	 					flash_status=Flash002_WritePage(FLASH002_SECTOR11_BASE+flashpageindex*FLASH002_PAGE_SIZE,flashwritingbuffer);

	 					if(flash_status==DAVEApp_SUCCESS)
		 				{
		 					txbuf[1]=0x01;
		 					flashpageindex++;
		 				}
		 				else
		 				{
		 					txbuf[1]=0x00;
		 				}

	 				}while((flashpageindex<=flashupperindex) && txbuf[1]==0x01);

	 			}
	 			else
	 			{
	 				txbuf[1]=0x00;
	 			}

	 		 	txlen=4;
	 			txbuf[0]=0x05;
		 	 	CalculateTxChecksum(txlen);
		 	 	sendflag=1;

				memioconfig=0;
			}
			if(memsectionconfig==1)
			{
	 		 	membaseaddress=sectionparamsize*SectionIndex;

	 		 	flash_status=Flash002_EraseSector(FLASH002_SECTOR11_BASE);

	 			if(flash_status==DAVEApp_SUCCESS)
	 			{

	 				flashpageindex=0;
	 				do
	 				{
	 					for(i=0;i<flashslotsize;i++)
	 					{
	 						flashwritingbuffer[i]=membuffer[i+flashpageindex*flashslotsize];
	 					}

	 					flash_status=Flash002_WritePage(FLASH002_SECTOR11_BASE+flashpageindex*FLASH002_PAGE_SIZE,flashwritingbuffer);

	 					if(flash_status==DAVEApp_SUCCESS)
		 				{
		 					txbuf[1]=0x01;
		 					flashpageindex++;
		 				}
		 				else
		 				{
		 					txbuf[1]=0x00;
		 				}

	 				}while(flashpageindex<=(((sectionparamsize*8)+boardconfigsize)/flashslotsize) && txbuf[1]==0x01);

	 			}
	 			else
	 			{
	 				txbuf[1]=0x00;
	 			}


	 		 	txlen=4;
	 		 	txbuf[0]=0x07;
	 		 	CalculateTxChecksum(txlen);
	 		 	sendflag=1;

				memsectionconfig=0;
			}
			if(mempinmapping==1)
			{
				membaseaddress=pinmappingoffset;

	 			if(flash_status==DAVEApp_SUCCESS)
	 			{

	 				flashpageindex=0;
	 				do
	 				{
	 					for(i=0;i<flashslotsize;i++)
	 					{
	 						flashwritingbuffer[i]=membuffer[i+flashpageindex*flashslotsize];
	 					}

	 					flash_status=Flash002_WritePage(FLASH002_SECTOR11_BASE+flashpageindex*FLASH002_PAGE_SIZE,flashwritingbuffer);

	 					if(flash_status==DAVEApp_SUCCESS)
		 				{
		 					txbuf[1]=0x01;
		 					flashpageindex++;
		 				}
		 				else
		 				{
		 					txbuf[1]=0x00;
		 				}

	 				}while((flashpageindex<=flashupperindex) && txbuf[1]==0x01);

	 			}
	 			else
	 			{
	 				txbuf[1]=0x00;
	 			}

	 		 	txlen=4;
	 			txbuf[0]=16;
		 	 	CalculateTxChecksum(txlen);
		 	 	sendflag=1;

				mempinmapping=0;
			}

		}
	}
	return 0;
}

void SetupCoeff(uint8_t SecId)
{
	int t;
    float normtime=1000/looptime;
    float DeltaI;
    float DeltaT;


	for(t=0;t<8;t++)
	{
		ditheractive[t]=1;
		pwmtar[t]=3333;

		if((loopfreq[t]!=20) && (loopfreq[t]!=13) && (loopfreq[t]!=10) && (loopfreq[t]!=8) && (loopfreq[t]!=6) && (loopfreq[t]!=5))
		{
			loopfreq[t]=10; // 10=100Hz
			ditherampl[t]=2;
		}
		else
		{
			if(ditherampl[t]<1 || ditherampl[t]>4)
			{
				ditherampl[t]=2;
			}
		}

		newvalue[t]=0;
	}


    if(minctrlv1[SecId]==0)
    {
    	minctrlv1[SecId]=1;
    }

    if(maxctrlv1[SecId]==100)
    {
    	maxctrlv1[SecId]=99;
    }

	maxctrlv2[SecId]=-maxctrlv2[SecId];
	minctrlv2[SecId]=-minctrlv2[SecId];

	if(minctrlv2[SecId]==0)
	{
		minctrlv2[SecId]=-1;
	}

	if(maxctrlv2[SecId]==-100)
	{
		maxctrlv2[SecId]=-99;
	}


	piv1[SecId] = (imaxv1[SecId] - iminv1[SecId])
			/ (maxctrlv1[SecId] - minctrlv1[SecId]);
	piv2[SecId] = (imaxv2[SecId] - iminv2[SecId])
			/ (-(maxctrlv2[SecId] - minctrlv2[SecId]));

	smoothdownv1[SecId]=iminv1[SecId]/minctrlv1[SecId];
	smoothdownv2[SecId]=iminv2[SecId]/-(minctrlv2[SecId]);

	smoothupv1[SecId]=(i_100_v1[SecId]-imaxv1[SecId])/(100-maxctrlv1[SecId]);
	smoothupv2[SecId]=(i_100_v2[SecId]-imaxv2[SecId])/(100+maxctrlv2[SecId]);

	//Normalizzazione in livelli della rampa di salita v1
	slopeupipointsv1_lev[0][SecId]=slopeupipointsv1[0][SecId]/ma_for_lev;
	slopeupipointsv1_lev[1][SecId]=slopeupipointsv1[1][SecId]/ma_for_lev;
	slopeupipointsv1_lev[2][SecId]=slopeupipointsv1[2][SecId]/ma_for_lev;
	i_100_v1_lev[SecId]=i_100_v1[SecId]/ma_for_lev;

	//Rampa Salita V1
    DeltaI=slopeupipointsv1_lev[0][SecId]-0;
    DeltaT=slopeuptpointsv1[0][SecId]-0;
    DeltaT=(DeltaT*normtime)+1;
	slopeupv1[0][SecId]=DeltaI/DeltaT;
	slopeupv1[0][SecId]=slopeupv1[0][SecId];

	DeltaI=slopeupipointsv1_lev[1][SecId]-slopeupipointsv1_lev[0][SecId];
	DeltaT=slopeuptpointsv1[1][SecId]-slopeuptpointsv1[0][SecId];
	DeltaT=(DeltaT*normtime)+1;
	slopeupv1[1][SecId]=DeltaI/DeltaT;
	slopeupv1[1][SecId]=slopeupv1[1][SecId];

	DeltaI=slopeupipointsv1_lev[2][SecId]-slopeupipointsv1_lev[1][SecId];
	DeltaT=slopeuptpointsv1[2][SecId]-slopeuptpointsv1[1][SecId];
	DeltaT=(DeltaT*normtime)+1;
	slopeupv1[2][SecId]=DeltaI/DeltaT;
	slopeupv1[2][SecId]=slopeupv1[2][SecId];

	DeltaI=i_100_v1_lev[SecId]-slopeupipointsv1_lev[2][SecId];
	DeltaT=slopeuptpointsv1[3][SecId]-slopeuptpointsv1[2][SecId];
	DeltaT=(DeltaT*normtime)+1;
	slopeupv1[3][SecId]=DeltaI/DeltaT;
	slopeupv1[3][SecId]=slopeupv1[3][SecId];

	//Normalizzazione in livelli della rampa di discesa v1
	slopedownipointsv1_lev[0][SecId]=slopedownipointsv1[0][SecId]/ma_for_lev;
	slopedownipointsv1_lev[1][SecId]=slopedownipointsv1[1][SecId]/ma_for_lev;
	slopedownipointsv1_lev[2][SecId]=slopedownipointsv1[2][SecId]/ma_for_lev;

	//Rampa Discesa V1
	DeltaI=((float)slopedownipointsv1_lev[0][SecId])-((float)i_100_v1_lev[SecId]);
	DeltaT=((float)slopedowntpointsv1[0][SecId])-0.0;
	DeltaT=(DeltaT*normtime)+1;
	slopedownv1[0][SecId]=DeltaI/DeltaT;

	DeltaI=((float)slopedownipointsv1_lev[1][SecId])-((float)slopedownipointsv1_lev[0][SecId]);
	DeltaT=((float)slopedowntpointsv1[1][SecId])-((float)slopedowntpointsv1[0][SecId]);
	DeltaT=(DeltaT*normtime)+1;
	slopedownv1[1][SecId]=DeltaI/DeltaT;

	DeltaI=((float)slopedownipointsv1_lev[2][SecId])-((float)slopedownipointsv1_lev[1][SecId]);
	DeltaT=((float)slopedowntpointsv1[2][SecId])-((float)slopedowntpointsv1[1][SecId]);
	DeltaT=(DeltaT*normtime)+1;
	slopedownv1[2][SecId]=DeltaI/DeltaT;

	DeltaI=0.0-((float)slopedownipointsv1_lev[2][SecId]);
	DeltaT=((float)slopedowntpointsv1[3][SecId])-((float)slopedowntpointsv1[2][SecId]);
	DeltaT=(DeltaT*normtime)+1;
	slopedownv1[3][SecId]=DeltaI/DeltaT;

	//Normalizzazione in livelli della rampa di salita v2
	slopeupipointsv2_lev[0][SecId]=slopeupipointsv2[0][SecId]/ma_for_lev;
	slopeupipointsv2_lev[1][SecId]=slopeupipointsv2[1][SecId]/ma_for_lev;
	slopeupipointsv2_lev[2][SecId]=slopeupipointsv2[2][SecId]/ma_for_lev;
	i_100_v2_lev[SecId]=i_100_v2[SecId]/ma_for_lev;

	//Rampa Salita V2
    DeltaI=slopeupipointsv2_lev[0][SecId]-0;
    DeltaT=slopeuptpointsv2[0][SecId]-0;
    DeltaT=(DeltaT*normtime)+1;
	slopeupv2[0][SecId]=DeltaI/DeltaT;

	DeltaI=slopeupipointsv2_lev[1][SecId]-slopeupipointsv2_lev[0][SecId];
	DeltaT=slopeuptpointsv2[1][SecId]-slopeuptpointsv2[0][SecId];
	DeltaT=(DeltaT*normtime)+1;
	slopeupv2[1][SecId]=DeltaI/DeltaT;

	DeltaI=slopeupipointsv2_lev[2][SecId]-slopeupipointsv2_lev[1][SecId];
	DeltaT=slopeuptpointsv2[2][SecId]-slopeuptpointsv2[1][SecId];
	DeltaT=(DeltaT*normtime)+1;
	slopeupv2[2][SecId]=DeltaI/DeltaT;

	DeltaI=i_100_v2_lev[SecId]-slopeupipointsv2_lev[2][SecId];
	DeltaT=slopeuptpointsv2[3][SecId]-slopeuptpointsv2[2][SecId];
	DeltaT=(DeltaT*normtime)+1;
	slopeupv2[3][SecId]=DeltaI/DeltaT;

	//Normalizzazione in livelli della rampa di discesa v2
	slopedownipointsv2_lev[0][SecId]=slopedownipointsv2[0][SecId]/ma_for_lev;
	slopedownipointsv2_lev[1][SecId]=slopedownipointsv2[1][SecId]/ma_for_lev;
	slopedownipointsv2_lev[2][SecId]=slopedownipointsv2[2][SecId]/ma_for_lev;

	//Rampa Discesa V2
	DeltaI=((float)slopedownipointsv2_lev[0][SecId])-((float)i_100_v2_lev[SecId]);
	DeltaT=((float)slopedowntpointsv2[0][SecId])-0.0;
	DeltaT=(DeltaT*normtime)+1;
	slopedownv2[0][SecId]=DeltaI/DeltaT;

	DeltaI=((float)slopedownipointsv2_lev[1][SecId])-((float)slopedownipointsv2_lev[0][SecId]);
	DeltaT=((float)slopedowntpointsv2[1][SecId])-((float)slopedowntpointsv2[0][SecId]);
	DeltaT=(DeltaT*normtime)+1;
	slopedownv2[1][SecId]=DeltaI/DeltaT;

	DeltaI=((float)slopedownipointsv2_lev[2][SecId])-((float)slopedownipointsv2_lev[1][SecId]);
	DeltaT=((float)slopedowntpointsv2[2][SecId])-((float)slopedowntpointsv2[1][SecId]);
	DeltaT=(DeltaT*normtime)+1;
	slopedownv2[2][SecId]=DeltaI/DeltaT;

	DeltaI=0.0-((float)slopedownipointsv2_lev[2][SecId]);
	DeltaT=((float)slopedowntpointsv2[3][SecId])-((float)slopedowntpointsv2[2][SecId]);
	DeltaT=(DeltaT*normtime)+1;
	slopedownv2[3][SecId]=DeltaI/DeltaT;
}

void SetupAnalogInputs(void)
{

	//Se modalità 3 (4-20 ma) abilito il mos per la lettura in corrente input 1
	if(analoginmode[0]==3)
	{
		IO004_SetPin(IO004_Handle32);
	}
	else
	{
		IO004_ResetPin(IO004_Handle32);
	}

	//Se modalità 4 (Raziometrico) abilito il reference esterno sul canale 1 per gli altri casi uso il reference interno
	if(analoginmode[0]==4)
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle12,XMC_VADC_CHANNEL_REF_ALT_CH0);
	}
	else
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle12,XMC_VADC_CHANNEL_REF_INTREF);
	}

	//Se modalità 3 (4-20 ma) abilito il mos per la lettura in corrente input 2
	if(analoginmode[1]==3)
	{
		IO004_SetPin(IO004_Handle33);
	}
	else
	{
		IO004_ResetPin(IO004_Handle33);
	}

	//Se modalità 4 (Raziometrico) abilito il reference esterno sul canale 2 per gli altri casi uso il reference interno
	if(analoginmode[1]==4)
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle11,XMC_VADC_CHANNEL_REF_ALT_CH0);
	}
	else
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle11,XMC_VADC_CHANNEL_REF_INTREF);
	}

	//Se modalità 3 (4-20 ma) abilito il mos per la lettura in corrente input 3
	if(analoginmode[2]==3)
	{
		IO004_SetPin(IO004_Handle34);
	}
	else
	{
		IO004_ResetPin(IO004_Handle34);
	}

	//Se modalità 4 (Raziometrico) abilito il reference esterno sul canale 3 per gli altri casi uso il reference interno
	if(analoginmode[2]==4)
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle14,XMC_VADC_CHANNEL_REF_ALT_CH0);
	}
	else
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle14,XMC_VADC_CHANNEL_REF_INTREF);
	}

	//Se modalità 3 (4-20 ma) abilito il mos per la lettura in corrente input 4
	if(analoginmode[3]==3)
	{
		IO004_SetPin(IO004_Handle35);
	}
	else
	{
		IO004_ResetPin(IO004_Handle35);
	}

	//Se modalità 4 (Raziometrico) abilito il reference esterno sul canale 4 per gli altri casi uso il reference interno
	if(analoginmode[3]==4)
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle13,XMC_VADC_CHANNEL_REF_ALT_CH0);
	}
	else
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle13,XMC_VADC_CHANNEL_REF_INTREF);
	}


	//Se modalità 3 (4-20 ma) abilito il mos per la lettura in corrente input 5
	if(analoginmode[4]==3)
	{
		IO004_SetPin(IO004_Handle36);
	}
	else
	{
		IO004_ResetPin(IO004_Handle36);
	}

	//Se modalità 4 (Raziometrico) abilito il reference esterno sul canale 5 per gli altri casi uso il reference interno
	if(analoginmode[4]==4)
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle2,XMC_VADC_CHANNEL_REF_ALT_CH0);
	}
	else
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle2,XMC_VADC_CHANNEL_REF_INTREF);
	}

	//Se modalità 3 (4-20 ma) abilito il mos per la lettura in corrente input 6
	if(analoginmode[5]==3)
	{
		IO004_SetPin(IO004_Handle37);
	}
	else
	{
		IO004_ResetPin(IO004_Handle37);
	}

	//Se modalità 4 (Raziometrico) abilito il reference esterno sul canale 6 per gli altri casi uso il reference interno
	if(analoginmode[5]==4)
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle16,XMC_VADC_CHANNEL_REF_ALT_CH0);
	}
	else
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle16,XMC_VADC_CHANNEL_REF_INTREF);
	}


	//Se modalità 3 (4-20 ma) abilito il mos per la lettura in corrente input 7
	if(analoginmode[6]==3)
	{
		IO004_SetPin(IO004_Handle38);
	}
	else
	{
		IO004_ResetPin(IO004_Handle38);
	}

	//Se modalità 4 (Raziometrico) abilito il reference esterno sul canale 7 per gli altri casi uso il reference interno
	if(analoginmode[6]==4)
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle19,XMC_VADC_CHANNEL_REF_ALT_CH0);
	}
	else
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle19,XMC_VADC_CHANNEL_REF_INTREF);
	}

	//Se modalità 3 (4-20 ma) abilito il mos per la lettura in corrente input 8
	if(analoginmode[7]==3)
	{
		IO004_SetPin(IO004_Handle39);
	}
	else
	{
		IO004_ResetPin(IO004_Handle39);
	}

	//Se modalità 4 (Raziometrico) abilito il reference esterno sul canale 8 per gli altri casi uso il reference interno
	if(analoginmode[7]==4)
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle15,XMC_VADC_CHANNEL_REF_ALT_CH0);
	}
	else
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle15,XMC_VADC_CHANNEL_REF_INTREF);
	}


	//Se modalità 3 (4-20 ma) abilito il mos per la lettura in corrente input 9
	if(analoginmode[8]==3)
	{
		IO004_SetPin(IO004_Handle40);
	}
	else
	{
		IO004_ResetPin(IO004_Handle40);
	}

	//Se modalità 4 (Raziometrico) abilito il reference esterno sul canale 9 per gli altri casi uso il reference interno
	if(analoginmode[8]==4)
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle17,XMC_VADC_CHANNEL_REF_ALT_CH0);
	}
	else
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle17,XMC_VADC_CHANNEL_REF_INTREF);
	}


	//Se modalità 3 (4-20 ma) abilito il mos per la lettura in corrente input 10
	if(analoginmode[9]==3)
	{
		IO004_SetPin(IO004_Handle41);
	}
	else
	{
		IO004_ResetPin(IO004_Handle41);
	}

	//Se modalità 4 (Raziometrico) abilito il reference esterno sul canale 10 per gli altri casi uso il reference interno
	if(analoginmode[9]==4)
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle18,XMC_VADC_CHANNEL_REF_ALT_CH0);
	}
	else
	{
		XMC_VADC_GROUP_ChannelSetInputReference(&ADCCH001_Handle18,XMC_VADC_CHANNEL_REF_INTREF);
	}
}

void SetupAuxOutput(void)
{
	switch(auxvolt & 0x0F)
	{
		case 0: IO004_ResetPin(IO004_Handle42);
				IO004_ResetPin(IO004_Handle43);
				IO004_ResetPin(IO004_Handle44);
				break;

		case 1: IO004_SetPin(IO004_Handle42);
				IO004_ResetPin(IO004_Handle43);
				IO004_ResetPin(IO004_Handle44);
				break;

		case 2: IO004_ResetPin(IO004_Handle42);
				IO004_SetPin(IO004_Handle43);
				IO004_ResetPin(IO004_Handle44);
				break;

		case 3: IO004_ResetPin(IO004_Handle42);
				IO004_ResetPin(IO004_Handle43);
				IO004_SetPin(IO004_Handle44);
				break;
	}

	if((auxvolt & 0x10) !=0)
	{
		can1DMenable=1;
	}

	if((auxvolt & 0x20) !=0)
	{
		can2DMenable=1;
	}
}
/*
 *
 Mappatura Canali in ingresso:

1 -  Valore X CAN 1
2 -  Valore Y CAN 1
3 -  PB1 CAN 1
4 -  PB2 CAN 1
5 -  PB3 CAN 1
6 -  PB4 CAN 1
7 -  PB5 CAN 1
8 -  PB6 CAN 1
9 -  PB7 CAN 1
10 - PB8 CAN 1
11 - ROLLER 1 CAN 1
12 - ROLLER 2 CAN 1
13 - Valore X CAN 2
14 - Valore Y CAN 2
15 - PB1 CAN 2
16 - PB2 CAN 2
17 - PB3 CAN 2
18 - PB4 CAN 2
19 - PB5 CAN 2
20 - PB6 CAN 2
21 - PB7 CAN 2
22 - PB8 CAN 2
23 - ROLLER 1 CAN 2
24 - ROLLER 2 CAN 2
25 - ANALOG IN 0
26 - ANALOG IN 1
27 - ANALOG IN 2
28 - ANALOG IN 3
29 - ANALOG IN 4
30 - ANALOG IN 5
31 - ANALOG IN 6
32 - ANALOG IN 7
33 - ANALOG IN 8
34 - ANALOG IN 9
35 - ROLLER 3 CAN1
36 - PB9 CAN1
37 - PB10 CAN1
38 - ROLLER 3 CAN2
39 - PB9 CAN2
40 - PB10 CAN2
 * */
void SetupPinMapping(void)
 {
	int i, k, s;

	for (i = 0; i < 8; i++) {
		inoutmap[i][0]=0;
		inoutmap[i][1]=0;
	}

	for (k = 0; k < 8; k++) {
		//Gestisco le 2 triple di condizioni per ogni sezione
		for (s = 0; s < 6; s = s + 3) {
			switch (pinmapping[k][0 + s]) {
			//Mappo da CAN 1
			case 0:
				//Caso A+B
				if (pinmapping[k][2 + s] == 0) {
					//Caso Asse X o Y
					if (pinmapping[k][1 + s] == 0
							|| pinmapping[k][1 + s] == 1) {
						inoutmap[k][0] = pinmapping[k][1 + s] + 1;
						inoutmap[k][1] = pinmapping[k][1 + s] + 1;
					}
					//Roller 1
					else if (pinmapping[k][1 + s] == 2) {
						inoutmap[k][0] = 11;
						inoutmap[k][1] = 11;
					}
					//Roller 2
					else if (pinmapping[k][1 + s] == 3) {
						inoutmap[k][0] = 12;
						inoutmap[k][1] = 12;
					}
					//Roller 3
					else if (pinmapping[k][1 + s] == 4) {
						inoutmap[k][0] = 35;
						inoutmap[k][1] = 35;
					}
				}
				//Caso A
				else if (pinmapping[k][2 + s] == 1) {
					//Caso Button 1-8
					if (pinmapping[k][1 + s] >= 5
							&& pinmapping[k][1 + s] <= 12) {
						inoutmap[k][0] = pinmapping[k][1 + s] - 2;
					}
					//Caso Button 9
					else if(pinmapping[k][1 + s] == 13)
					{
						inoutmap[k][0] = 36;
					}
					//Caso Button 10
					else if(pinmapping[k][1 + s] == 14)
					{
						inoutmap[k][0] = 37;
					}
				}
				//Caso B
				else if (pinmapping[k][2 + s] == 2) {
					if (pinmapping[k][1 + s] >= 5
							&& pinmapping[k][1 + s] <= 12) {
						inoutmap[k][1] = pinmapping[k][1 + s] - 2;
					}
					//Caso Button 9
					else if(pinmapping[k][1 + s] == 13)
					{
						inoutmap[k][1] = 36;
					}
					//Caso Button 10
					else if(pinmapping[k][1 + s] == 14)
					{
						inoutmap[k][1] = 37;
					}
				}
				//Caso FLOTTANTE B
				else if (pinmapping[k][2 + s] == 3) {
					if (pinmapping[k][1 + s] >= 5
							&& pinmapping[k][1 + s] <= 12) {
						floating[k] = pinmapping[k + s][1] - 2;
					}
					//Caso Button 9
					else if(pinmapping[k][1 + s] == 13)
					{
						floating[k] = 36;
					}
					//Caso Button 10
					else if(pinmapping[k][1 + s] == 14)
					{
						floating[k] = 37;
					}
				}
				break;
				//Mappo da CAN 2
			case 1: //Caso A+B
				if (pinmapping[k][2 + s] == 0) {
					//Caso Asse X o Y
					if (pinmapping[k][1 + s] == 0
							|| pinmapping[k][1 + s] == 1) {
						inoutmap[k][0] = pinmapping[k][1 + s] + 13;
						inoutmap[k][1] = pinmapping[k][1 + s] + 13;
					}
					//Roller 1
					else if (pinmapping[k][1 + s] == 2) {
						inoutmap[k][0] = 23;
						inoutmap[k][1] = 23;
					}
					//Roller 2
					else if (pinmapping[k][1 + s] == 3) {
						inoutmap[k][0] = 24;
						inoutmap[k][1] = 24;
					}
					//Roller 3
					else if (pinmapping[k][1 + s] == 4) {
						inoutmap[k][0] = 38;
						inoutmap[k][1] = 38;
					}
				}
				//Caso A
				else if (pinmapping[k][2 + s] == 1) {
					if (pinmapping[k][1 + s] >= 5
							&& pinmapping[k][1 + s] <= 12) {
						inoutmap[k][0] = pinmapping[k][1 + s] + 10;
					}
					//Caso Button 9
					else if(pinmapping[k][1 + s] == 13)
					{
						inoutmap[k][0] = 39;
					}
					//Caso Button 10
					else if(pinmapping[k][1 + s] == 14)
					{
						inoutmap[k][0] = 40;
					}
				}
				//Caso B
				else if (pinmapping[k][2 + s] == 2) {
					if (pinmapping[k][1 + s] >= 5
							&& pinmapping[k][1 + s] <= 12) {
						inoutmap[k][1] = pinmapping[k][1 + s] + 10;
					}
					//Caso Button 9
					else if(pinmapping[k][1 + s] == 13)
					{
						inoutmap[k][1] = 39;
					}
					//Caso Button 10
					else if(pinmapping[k][1 + s] == 14)
					{
						inoutmap[k][1] = 40;
					}
				}
				//Caso FLOTTANTE B
				else if (pinmapping[k][2 + s] == 3) {
					if (pinmapping[k][1 + s] >= 5
							&& pinmapping[k][1 + s] <= 12) {
						floating[k] = pinmapping[k][1 + s] + 10;
					}
					//Caso Button 9
					else if(pinmapping[k][1 + s] == 13)
					{
						floating[k] = 39;
					}
					//Caso Button 10
					else if(pinmapping[k][1 + s] == 14)
					{
						floating[k] = 40;
					}
				}
				break;

				//Mappo da ANALOGICA
			case 2:
				//Caso A+B
				if (pinmapping[k][2 + s] == 0) {
					//Caso Asse X o Y
						inoutmap[k][0] = pinmapping[k][1 + s] + 25;
						inoutmap[k][1] = pinmapping[k][1 + s] + 25;
				}
				//Caso A
				else if (pinmapping[k][2 + s] == 1) {
					inoutmap[k][0] = pinmapping[k][1 + s] + 25;
				}
				//Caso B
				else if (pinmapping[k][2 + s] == 2) {
						inoutmap[k][1] = pinmapping[k][1 + s] + 25;
				}
				//Caso FLOTTANTE B
				else if (pinmapping[k][2 + s] == 3) {
						floating[k] = pinmapping[k + s][1] + 25;
				}
				break;

			default:
				break;
			}
		}
	}
}

void RampV1(int secid)
 {
	if (targcurr[secid] - acttargcurr[secid] >= 0) {
		if (acttargcurr[secid] <= slopeupipointsv1_lev[0][secid]) {

			if (targcurr[secid] - acttargcurr[secid] > slopeupv1[0][secid]) {
				acttargcurr[secid] = acttargcurr[secid] + slopeupv1[0][secid];

				#ifdef dbgvar4ramp
   				    IO004_TogglePin(IO004_Handle45);
					dbgcnt[0]++;
				#endif
			} else {
				acttargcurr[secid] = targcurr[secid];

				#ifdef dbgvar4ramp
				dbgcnt[1]++;
				#endif
			}
		} else {
			if (acttargcurr[secid] <= slopeupipointsv1_lev[1][secid]) {
				if (targcurr[secid] - acttargcurr[secid]
						> slopeupv1[1][secid]) {
					acttargcurr[secid] = acttargcurr[secid]	+ slopeupv1[1][secid];

					#ifdef dbgvar4ramp
   				    IO004_TogglePin(IO004_Handle45);
					dbgcnt[2]++;
					#endif

				} else {
					acttargcurr[secid] = targcurr[secid];

					#ifdef dbgvar4ramp
					dbgcnt[3]++;
					#endif
				}
			} else {
				if (acttargcurr[secid] <= slopeupipointsv1_lev[2][secid]) {
					if (targcurr[secid] - acttargcurr[secid]
							> slopeupv1[2][secid]) {
						acttargcurr[secid] = acttargcurr[secid]	+ slopeupv1[2][secid];


						#ifdef dbgvar4ramp
	   				    IO004_TogglePin(IO004_Handle45);
						dbgcnt[4]++;
						#endif

					} else {
						acttargcurr[secid] = targcurr[secid];

						#ifdef dbgvar4ramp
						dbgcnt[5]++;
						#endif
					}

				} else {
					if (targcurr[secid] - acttargcurr[secid]
							> slopeupv1[3][secid]) {
						acttargcurr[secid] = acttargcurr[secid] + slopeupv1[3][secid];

						#ifdef dbgvar4ramp
	   				    IO004_TogglePin(IO004_Handle45);
						dbgcnt[6]++;
						#endif

					} else {

						acttargcurr[secid] = targcurr[secid];

						#ifdef dbgvar4ramp
						IO004_ResetPin(IO004_Handle45);
						dbgcnt[7]++;
						#endif
					}
				}
			}
		}
	} else {
		if (acttargcurr[secid] >= slopedownipointsv1_lev[0][secid]) {
			if (targcurr[secid] - acttargcurr[secid] < slopedownv1[0][secid]) {
				acttargcurr[secid] = acttargcurr[secid] + slopedownv1[0][secid];

				#ifdef dbgvar4ramp
				dbgcnt[8]++;
				#endif
			} else {
				acttargcurr[secid] = targcurr[secid];

				#ifdef dbgvar4ramp
				dbgcnt[9]++;
				#endif
			}
		} else if (acttargcurr[secid] >= slopedownipointsv1_lev[1][secid]) {
			if (targcurr[secid] - acttargcurr[secid] < slopedownv1[1][secid]) {
				acttargcurr[secid] = acttargcurr[secid] + slopedownv1[1][secid];

				#ifdef dbgvar4ramp
				dbgcnt[10]++;
				#endif
			} else {
				acttargcurr[secid] = targcurr[secid];

				#ifdef dbgvar4ramp
				dbgcnt[11]++;
				#endif
			}
		} else if (acttargcurr[secid] >= slopedownipointsv1_lev[2][secid]) {
			if (targcurr[secid] - acttargcurr[secid] < slopedownv1[2][secid]) {
				acttargcurr[secid] = acttargcurr[secid] + slopedownv1[2][secid];

				#ifdef dbgvar4ramp
				dbgcnt[12]++;
				#endif
			} else {
				acttargcurr[secid] = targcurr[secid];

				#ifdef dbgvar4ramp
				dbgcnt[13]++;
				#endif
			}
		} else {
			if (targcurr[secid] - acttargcurr[secid] < slopedownv1[3][secid]) {
				acttargcurr[secid] = acttargcurr[secid] + slopedownv1[3][secid];

				#ifdef dbgvar4ramp
				dbgcnt[14]++;
				#endif
			} else {
				acttargcurr[secid] = targcurr[secid];

				#ifdef dbgvar4ramp
				dbgcnt[15]++;
				#endif
			}
		}
	}
}

void RampV2(int secid)
{
	if(acttargcurr[secid]-targcurr[secid]>=0)
	{
		if(abs(acttargcurr[secid])<=slopeupipointsv2_lev[0][secid])
		{
			if(acttargcurr[secid]-targcurr[secid]>slopeupv2[0][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopeupv2[0][secid];

				#ifdef dbgvar4ramp
				dbgcnt[16]++;
				#endif
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];

				#ifdef dbgvar4ramp
				dbgcnt[17]++;
				#endif
			}
		}
		else if(abs(acttargcurr[secid])<=slopeupipointsv2_lev[1][secid])
		{
			if(acttargcurr[secid]-targcurr[secid]>slopeupv2[1][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopeupv2[1][secid];

				#ifdef dbgvar4ramp
				dbgcnt[18]++;
				#endif
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];

				#ifdef dbgvar4ramp
				dbgcnt[19]++;
				#endif
			}
		}
		else if(abs(acttargcurr[secid])<=slopeupipointsv2_lev[2][secid])
		{
			if(acttargcurr[secid]-targcurr[secid]>slopeupv2[2][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopeupv2[2][secid];

				#ifdef dbgvar4ramp
				dbgcnt[20]++;
				#endif
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];

				#ifdef dbgvar4ramp
				dbgcnt[21]++;
				#endif
			}
		}
		else
		{
			if(acttargcurr[secid]-targcurr[secid]>slopeupv2[3][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopeupv2[3][secid];

				#ifdef dbgvar4ramp
				dbgcnt[22]++;
				#endif
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];

				#ifdef dbgvar4ramp
				dbgcnt[23]++;
				#endif
			}
		}
	}
	else
	{
		if(abs(acttargcurr[secid])>=slopedownipointsv2_lev[0][secid])
		{
			if(acttargcurr[secid]-targcurr[secid]<slopedownv2[0][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopedownv2[0][secid];

				#ifdef dbgvar4ramp
				dbgcnt[24]++;
				#endif
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];

				#ifdef dbgvar4ramp
				dbgcnt[25]++;
				#endif
			}
		}
		else if(abs(acttargcurr[secid])>=slopedownipointsv2_lev[1][secid])
		{
			if(acttargcurr[secid]-targcurr[secid]<slopedownv2[1][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopedownv2[1][secid];

				#ifdef dbgvar4ramp
				dbgcnt[26]++;
				#endif
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];

				#ifdef dbgvar4ramp
				dbgcnt[27]++;
				#endif
			}
		}
		else if(abs(acttargcurr[secid])>=slopedownipointsv2_lev[2][secid])
		{
			if(acttargcurr[secid]-targcurr[secid]<slopedownv2[2][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopedownv2[2][secid];

				#ifdef dbgvar4ramp
				dbgcnt[28]++;
				#endif
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];

				#ifdef dbgvar4ramp
				dbgcnt[29]++;
				#endif
			}
		}
		else
		{
			if(acttargcurr[secid]-targcurr[secid]<slopedownv2[3][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopedownv2[3][secid];

				#ifdef dbgvar4ramp
				dbgcnt[30]++;
				#endif
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];

				#ifdef dbgvar4ramp
				dbgcnt[31]++;
				#endif
			}
		}
	}
}


void CalcTarCurr(int secid)
{
	//Gestione V1
	if(inputlevel[secid]>0 && acttargcurr[secid]>=0)
	{
		if(inputlevel[secid]<=minctrlv1[secid])
		{
			targcurr[secid]=(inputlevel[secid]*smoothdownv1[secid]);
		}
		else if(inputlevel[secid]>minctrlv1[secid] && inputlevel[secid]<maxctrlv1[secid])
		{
			targcurr[secid]=(minctrlv1[secid]*smoothdownv1[secid])+((inputlevel[secid]-minctrlv1[secid])*piv1[secid]);
		}
		else
		{
			targcurr[secid]=(minctrlv1[secid]*smoothdownv1[secid])+((maxctrlv1[secid]-minctrlv1[secid])*piv1[secid])+((inputlevel[secid]-maxctrlv1[secid])*smoothupv1[secid]);
		}

		targcurr[secid]=targcurr[secid]/ma_for_lev;

		if((configsec[secid] & 0x02) == 0x02) //Rampa su V1 abilitata
		{
			RampV1(secid);
		}
		else
		{
			acttargcurr[secid]=targcurr[secid];
		}
	}
	//Gestione V2
	else if(inputlevel[secid]<0 && acttargcurr[secid]<=0)
	{
		if(inputlevel[secid]>=minctrlv2[secid])
		{
			targcurr[secid]=(inputlevel[secid]*smoothdownv2[secid]);
		}
		else if(inputlevel[secid]<minctrlv2[secid] && inputlevel[secid]>=maxctrlv2[secid])
		{
			targcurr[secid]=(minctrlv2[secid]*smoothdownv2[secid])+((inputlevel[secid]-minctrlv2[secid])*piv2[secid]);
		}
		else
		{
			targcurr[secid]=(minctrlv2[secid]*smoothdownv2[secid])+((maxctrlv2[secid]-minctrlv2[secid])*piv2[secid])+((inputlevel[secid]-maxctrlv2[secid])*smoothupv2[secid]);
		}

		targcurr[secid]=targcurr[secid]/ma_for_lev;

		if((configsec[secid] & 0x04) == 0x04) //Rampa su V2 abilitata
		{
			RampV2(secid);
		}
		else
		{
			acttargcurr[secid]=targcurr[secid];
		}

	}
	else
	{
		targcurr[secid]=0;

		if(acttargcurr[secid]>0 && ((configsec[secid] & 0x02)==0x02))
		{
			RampV1(secid);
		}
		else if(acttargcurr[secid]<0 && ((configsec[secid] & 0x04)==0x04))
		{
			RampV2(secid);
		}
		else
		{
			acttargcurr[secid]=targcurr[secid];
		}
	}
}

void CalcTarPwm(int secid)
{
	uint32_t deltacurr;

	if(((configsec[secid] & 0x02)==0x02) || ((configsec[secid] & 0x04)==0x04))
	{
		if(timertrigger[secid]==TRUE)
		{
			CalcTarCurr(secid);
			timertrigger[secid]=FALSE;
		}
	}
	else
	{
		CalcTarCurr(secid);
	}

	if(actualcurr[secid]>abs(acttargcurr[secid]))
	{
		deltacurr=actualcurr[secid]-abs(acttargcurr[secid]);

		if((pwmtar[secid]+(deltacurr/10)+1)<3333)
		{
			pwmtar[secid]=pwmtar[secid]+(deltacurr/10)+1;
		}
		else
		{
			pwmtar[secid]=3333;
		}
	}
	else if(actualcurr[secid]<abs(acttargcurr[secid]))
    {
		deltacurr=abs(acttargcurr[secid])-actualcurr[secid];

		if((signed int)(pwmtar[secid]-(deltacurr/10)-1)>0)
		{
			pwmtar[secid]=pwmtar[secid]-(deltacurr/10)-1;
		}
		else
		{
			pwmtar[secid]=0;
		}
	}
}

void CalcActPwm(int secid,uint32_t tmpcurr)
{
	if(sectionstatus[secid]==0)
	{
		if(avgcurrindex[secid]<loopfreq[secid]-1)
		{
			avgcurr[secid]=avgcurr[secid]+tmpcurr;
			avgcurrindex[secid]++;

			if(ditheractive[secid]==1)
			{
				if(avgcurrindex[secid]<ditherampl[secid])
				{
					actpwm[secid]=3333;
				}
				else
				{
					actpwm[secid]=pwmtar[secid];
				}
			}
		}
		else
		{
			avgcurr[secid]=avgcurr[secid]+tmpcurr;
			actualcurr[secid]=avgcurr[secid]/loopfreq[secid];
			avgcurr[secid]=0;
			avgcurrindex[secid]=0;

			newvalue[secid]=1;
		}

		SetActPwm(secid);
	}
}

void SetActPwm(int secid)
{
	switch(secid)
	{
		case 0: if(acttargcurr[secid]>0)
				{
					IO004_SetPin(IO004_Handle0);
					IO004_ResetPin(IO004_Handle1);
				}
				else if(acttargcurr[secid]<0)
				{
					IO004_ResetPin(IO004_Handle0);
					IO004_SetPin(IO004_Handle1);
				}
				else
				{
					IO004_ResetPin(IO004_Handle0);
					IO004_ResetPin(IO004_Handle1);
				}
				PWMSP002_SetCompare(&PWMSP002_Handle0,actpwm[0],0);
				break;
		case 1:if(acttargcurr[secid]>0)
				{
					IO004_SetPin(IO004_Handle2);
					IO004_ResetPin(IO004_Handle3);
				}
				else if(acttargcurr[secid]<0)
				{
					IO004_ResetPin(IO004_Handle2);
					IO004_SetPin(IO004_Handle3);
				}
				else
				{
					IO004_ResetPin(IO004_Handle2);
					IO004_ResetPin(IO004_Handle3);
				}
				PWMSP002_SetCompare(&PWMSP002_Handle1,actpwm[1],0);
				break;
		case 2:if(acttargcurr[secid]>0)
				{
					IO004_SetPin(IO004_Handle4);
					IO004_ResetPin(IO004_Handle5);
				}
				else if(acttargcurr[secid]<0)
				{
					IO004_ResetPin(IO004_Handle4);
					IO004_SetPin(IO004_Handle5);
				}
				else
				{
					IO004_ResetPin(IO004_Handle4);
					IO004_ResetPin(IO004_Handle5);
				}
				PWMSP002_SetCompare(&PWMSP002_Handle2,actpwm[2],0);
				break;
		case 3:if(acttargcurr[secid]>0)
				{
					IO004_SetPin(IO004_Handle6);
					IO004_ResetPin(IO004_Handle7);
				}
				else if(acttargcurr[secid]<0)
				{
					IO004_ResetPin(IO004_Handle6);
					IO004_SetPin(IO004_Handle7);
				}
				else
				{
					IO004_ResetPin(IO004_Handle6);
					IO004_ResetPin(IO004_Handle7);
				}
				PWMSP002_SetCompare(&PWMSP002_Handle3,actpwm[3],0);
				break;
		case 4:if(acttargcurr[secid]>0)
				{
					IO004_SetPin(IO004_Handle8);
					IO004_ResetPin(IO004_Handle9);
				}
				else if(acttargcurr[secid]<0)
				{
					IO004_ResetPin(IO004_Handle8);
					IO004_SetPin(IO004_Handle9);
				}
				else
				{
					IO004_ResetPin(IO004_Handle8);
					IO004_ResetPin(IO004_Handle9);
				}
				PWMSP002_SetCompare(&PWMSP002_Handle4,actpwm[4],0);
				break;
		case 5:if(acttargcurr[secid]>0)
				{
					IO004_SetPin(IO004_Handle10);
					IO004_ResetPin(IO004_Handle11);
				}
				else if(acttargcurr[secid]<0)
				{
					IO004_ResetPin(IO004_Handle10);
					IO004_SetPin(IO004_Handle11);
				}
				else
				{
					IO004_ResetPin(IO004_Handle10);
					IO004_ResetPin(IO004_Handle11);
				}
				PWMSP002_SetCompare(&PWMSP002_Handle5,actpwm[5],0);
				break;
		case 6:if(acttargcurr[secid]>0)
				{
					IO004_SetPin(IO004_Handle12);
					IO004_ResetPin(IO004_Handle13);
				}
				else if(acttargcurr[secid]<0)
				{
					IO004_ResetPin(IO004_Handle12);
					IO004_SetPin(IO004_Handle13);
				}
				else
				{
					IO004_ResetPin(IO004_Handle12);
					IO004_ResetPin(IO004_Handle13);
				}
				PWMSP002_SetCompare(&PWMSP002_Handle6,actpwm[6],0);
				break;
		case 7:if(acttargcurr[secid]>0)
				{
					IO004_SetPin(IO004_Handle14);
					IO004_ResetPin(IO004_Handle15);
				}
				else if(acttargcurr[secid]<0)
				{
					IO004_ResetPin(IO004_Handle14);
					IO004_SetPin(IO004_Handle15);
				}
				else
				{
					IO004_ResetPin(IO004_Handle14);
					IO004_ResetPin(IO004_Handle15);
				}
				PWMSP002_SetCompare(&PWMSP002_Handle7,actpwm[7],0);
				break;
		default:break;
	}
}

/*
1 -  Valore X CAN 1
2 -  Valore Y CAN 1
3 -  PB1 CAN 1
4 -  PB2 CAN 1
5 -  PB3 CAN 1
6 -  PB4 CAN 1
7 -  PB5 CAN 1
8 -  PB6 CAN 1
9 -  PB7 CAN 1
10 - PB8 CAN 1
36 - PB9 CAN 1
37 - PB10 CAN 1

13 - Valore X CAN 2
14 - Valore Y CAN 2
15 - PB1 CAN 2
16 - PB2 CAN 2
17 - PB3 CAN 2
18 - PB4 CAN 2
19 - PB5 CAN 2
20 - PB6 CAN 2
21 - PB7 CAN 2
22 - PB8 CAN 2
39 - PB9 CAN 2
40 - PB10 CAN 2
*/

void HandleCanMessageBasic(uint8_t Data[8], uint8_t port)
{
	float X_Pos, Y_Pos;
	uint8_t PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10;
	int TmpData;
	int k;

	X_Pos = Data[1] * 4 + (Data[0] / 64);
	Y_Pos = Data[3] * 4 + (Data[2] / 64);

	PB1 = ((Data[5] & 0xC0) >> 6);
	PB2 = ((Data[5] & 0x30) >> 4);
	PB3 = ((Data[5] & 0x0C) >> 2);
	PB4 = (Data[5] & 0x03);
	PB5 = ((Data[6] & 0xC0) >> 6);
	PB6 = ((Data[6] & 0x30) >> 4);
	PB7 = ((Data[6] & 0x0C) >> 2);
	PB8 = (Data[6] & 0x03);
	PB9 = ((Data[7] & 0xC0) >> 6);
	PB10 = ((Data[7] & 0x30) >> 4);

	if(port==1)
	{
		if(can1DMenable==1 && PB10==0)
		{
			X_Pos = 0;
			Y_Pos = 0;
			PB1 = 0;
			PB2 = 0;
			PB3 = 0;
			PB4 = 0;
			PB5 = 0;
			PB6 = 0;
			PB7 = 0;
			PB8 = 0;
			PB9 = 0;
			can1DMstatus=0;
		}
		else
		{
		can1DMstatus=1;
		}
	}

	if(port==2)
	{
		if(can2DMenable==1 && PB10==0)
		{
			X_Pos = 0;
			Y_Pos = 0;
			PB1 = 0;
			PB2 = 0;
			PB3 = 0;
			PB4 = 0;
			PB5 = 0;
			PB6 = 0;
			PB7 = 0;
			PB8 = 0;
			PB9 = 0;
			can2DMstatus=0;
		}
		else
		{
			can2DMstatus=1;
		}
	}


	for (k = 0; k < 8; k++) {
		//Fare il calcolo solo se il k è controllato dal range di ingressi scansionato
		if ((inoutmap[k][0] >= 1 && inoutmap[k][0] <= 10)
				|| (inoutmap[k][1] >= 1 && inoutmap[k][1] <= 10) || (inoutmap[k][0] >= 36 && inoutmap[k][0] <= 37)
				|| (inoutmap[k][1] >= 36 && inoutmap[k][1] <= 37)) {

			if (port == 1) {
				inputlevel[k] = 0;
				switch (inoutmap[k][0]) {
				case (1):
					TmpData = Data[0];
					if (TmpData & 0x04) {
						inputlevel[k] = (X_Pos * 100) / 1000.0;
					}
					break;
				case (2):
					TmpData = Data[2];
					if (TmpData & 0x04) {
						inputlevel[k] = (Y_Pos * 100) / 1000.0;
					}
					break;
				case (3):
					if (PB1) {
						inputlevel[k] = 100;
					}
					break;
				case (4):
					if (PB2) {
						inputlevel[k] = 100;
					}
					break;
				case (5):
					if (PB3) {
						inputlevel[k] = 100;
					}
					break;
				case (6):
					if (PB4) {
						inputlevel[k] = 100;
					}
					break;
				case (7):
					if (PB5) {
						inputlevel[k] = 100;
					}
					break;
				case (8):
					if (PB6) {
						inputlevel[k] = 100;
					}
					break;
				case (9):
					if (PB7) {
						inputlevel[k] = 100;
					}
					break;
				case (10):
					if (PB8) {
						inputlevel[k] = 100;
					}
					break;
				case (36):
					if (PB9) {
						inputlevel[k] = 100;
					}
					break;
				case (37):
					if (PB10) {
						inputlevel[k] = 100;
					}
					break;

				default:
					break;
				}

				switch (inoutmap[k][1]) {
				case (1):
					TmpData = Data[0];
					if (TmpData & 0x10) {
						inputlevel[k] = (-X_Pos * 100) / 1000.0;
					}
					break;
				case (2):
					TmpData = Data[2];
					if (TmpData & 0x10) {
						inputlevel[k] = (-Y_Pos * 100) / 1000.0;
					}
					break;
				case (3):
					if (PB1) {
						inputlevel[k] = -100;
					}
					break;
				case (4):
					if (PB2) {
						inputlevel[k] = -100;
					}
					break;
				case (5):
					if (PB3) {
						inputlevel[k] = -100;
					}
					break;
				case (6):
					if (PB4) {
						inputlevel[k] = -100;
					}
					break;
				case (7):
					if (PB5) {
						inputlevel[k] = -100;
					}
					break;
				case (8):
					if (PB6) {
						inputlevel[k] = -100;
					}
					break;
				case (9):
					if (PB7) {
						inputlevel[k] = -100;
					}
					break;
				case (10):
					if (PB8) {
						inputlevel[k] = -100;
					}
					break;
				case (36):
					if (PB9) {
						inputlevel[k] = -100;
					}
					break;
				case (37):
					if (PB10) {
						inputlevel[k] = -100;
					}
					break;
				}

				//CalcTarCurr(k);
			}
		}
		if ((inoutmap[k][0] >= 13 && inoutmap[k][0] <= 22)
				|| (inoutmap[k][1] >= 13 && inoutmap[k][1] <= 22)
				|| (inoutmap[k][0] >= 39 && inoutmap[k][0] <= 40)
				|| (inoutmap[k][1] >= 39 && inoutmap[k][1] <= 40)) {

			if (port == 2) {
				inputlevel[k] = 0;

				switch (inoutmap[k][0]) {
				case (13):
					TmpData = Data[0];
					if (TmpData & 0x04) {
						inputlevel[k] = (X_Pos * 100) / 1000.0;
					}
					break;
				case (14):
					TmpData = Data[2];
					if (TmpData & 0x04) {
						inputlevel[k] = (Y_Pos * 100) / 1000.0;
					}
					break;
				case (15):
					if (PB1) {
						inputlevel[k] = 100;
					}
					break;
				case (16):
					if (PB2) {
						inputlevel[k] = 100;
					}
					break;
				case (17):
					if (PB3) {
						inputlevel[k] = 100;
					}
					break;
				case (18):
					if (PB4) {
						inputlevel[k] = 100;
					}
					break;
				case (19):
					if (PB5) {
						inputlevel[k] = 100;
					}
					break;
				case (20):
					if (PB6) {
						inputlevel[k] = 100;
					}
					break;
				case (21):
					if (PB7) {
						inputlevel[k] = 100;
					}
					break;
				case (22):
					if (PB8) {
						inputlevel[k] = 100;
					}
					break;
				case (39):
					if (PB9) {
						inputlevel[k] = 100;
					}
					break;
				case (40):
					if (PB10) {
						inputlevel[k] = 100;
					}
					break;

				default:
					break;
				}

				switch (inoutmap[k][1]) {
				case (13):
					TmpData = Data[0];
					if (TmpData & 0x10) {
						inputlevel[k] = (-X_Pos * 100) / 1000.0;
					}
					break;
				case (14):
					TmpData = Data[2];
					if (TmpData & 0x10) {
						inputlevel[k] = (-Y_Pos * 100) / 1000.0;
					}
					break;
				case (15):
					if (PB1) {
						inputlevel[k] = -100;
					}
					break;
				case (16):
					if (PB2) {
						inputlevel[k] = -100;
					}
					break;
				case (17):
					if (PB3) {
						inputlevel[k] = -100;
					}
					break;
				case (18):
					if (PB4) {
						inputlevel[k] = -100;
					}
					break;
				case (19):
					if (PB5) {
						inputlevel[k] = -100;
					}
					break;
				case (20):
					if (PB6) {
						inputlevel[k] = -100;
					}
					break;
				case (21):
					if (PB7) {
						inputlevel[k] = -100;
					}
					break;
				case (22):
					if (PB8) {
						inputlevel[k] = -100;
					}
					break;
				case (39):
					if (PB9) {
						inputlevel[k] = -100;
					}
					break;
				case (40):
					if (PB10) {
						inputlevel[k] = -100;
					}
					break;
				}

				//Fare il calcolo solo se il k è controllato dal range di ingressi scansionato
				//CalcTarCurr(k);
			}
		}

		//Inserisco il controllo del Flottante
		if((floating[k] >= 1 && floating[k] <= 10)
			|| (floating[k] >= 36 && floating[k] <= 37))
		{
			if (port == 1) {
				switch (floating[k]) {
					case (3):
						if (PB1 && inputlevel[k]==-100) {

						}
						break;
					case (4):
						if (PB2 && inputlevel[k]==-100) {

						}
						break;
					case (5):
						if (PB3 && inputlevel[k]==-100) {

						}
						break;
					case (6):
						if (PB4 && inputlevel[k]==-100) {

						}
						break;
					case (7):
						if (PB5 && inputlevel[k]==-100) {

						}
						break;
					case (8):
						if (PB6 && inputlevel[k]==-100) {

						}
						break;
					case (9):
						if (PB7 && inputlevel[k]==-100) {

						}
						break;
					case (10):
						if (PB8 && inputlevel[k]==-100) {

						}
						break;
					case (36):
						if (PB9 && inputlevel[k]==-100) {

						}
						break;
					case (37):
						if (PB10 && inputlevel[k]==-100) {

						}
						break;
					default:
						break;
				}
			}
		}
	}
}

/*
11 -  ROLLER 1 CAN 1
12 -  ROLLER 2 CAN 1
35 - ROLLER 3 CAN1
23 - ROLLER 1 CAN 2
24 - ROLLER 2 CAN 2
38 - ROLLER 3 CAN2
*/

void HandleCanMessageExtended(uint8_t Data[8], uint8_t port) {
	float Z_Pos, W_Pos, V_Pos;
	int TmpData;
	int k;

	Z_Pos = Data[1] * 4 + (Data[0] / 64);
	W_Pos = Data[3] * 4 + (Data[2] / 64);
	V_Pos = Data[5] * 4 + (Data[4] / 64);

	if(can1DMstatus==0 && port==1)
	{
		Z_Pos = 0;
		W_Pos = 0;
		V_Pos = 0;
	}

	if(can2DMstatus==0 && port==2)
	{
		Z_Pos = 0;
		W_Pos = 0;
		V_Pos = 0;
	}

	for (k = 0; k < 8; k++) {
		//Fare il calcolo solo se il k è controllato dal range di ingressi scansionato
		if ((inoutmap[k][0] >= 11 && inoutmap[k][0] <= 12)
				|| (inoutmap[k][1] >= 11 && inoutmap[k][1] <= 12) || (inoutmap[k][0]==35) || (inoutmap[k][1]==35)) {

			if (port == 1) {
				inputlevel[k] = 0;
				switch (inoutmap[k][0]) {

				case (11):
					TmpData = Data[0];
					if (TmpData & 0x04) {
						inputlevel[k] = (-Z_Pos * 100) / 1000.0;
					}
					break;

				case (12):
					TmpData = Data[2];
					if (TmpData & 0x04) {
						inputlevel[k] = (-W_Pos * 100) / 1000.0;
					}
					break;

				case (35):
					TmpData = Data[4];
					if (TmpData & 0x04) {
						inputlevel[k] = (-V_Pos * 100) / 1000.0;
					}
					break;

				default:
					break;
				}

				switch (inoutmap[k][1]) {
				case (11):
					TmpData = Data[0];
					if (TmpData & 0x10) {
						inputlevel[k] = (Z_Pos * 100) / 1000.0;
					}
					break;

				case (12):
					TmpData = Data[2];
					if (TmpData & 0x10) {
						inputlevel[k] = (W_Pos * 100) / 1000.0;
					}
					break;

				case (35):
					TmpData = Data[4];
					if (TmpData & 0x10) {
						inputlevel[k] = (V_Pos * 100) / 1000.0;
					}
					break;

				default:
					break;

				}
				CalcTarCurr(k);
			}
		}
		//Fare il calcolo solo se il k è controllato dal range di ingressi scansionato
		if ((inoutmap[k][0] >= 23 && inoutmap[k][0] <= 24)
				|| (inoutmap[k][1] >= 23 && inoutmap[k][1] <= 24) || (inoutmap[k][0]==38) || (inoutmap[k][1]==38)) {

			if (port == 2) {
				inputlevel[k] = 0;

				switch (inoutmap[k][0]) {

				case (23):
					TmpData = Data[0];
					if (TmpData & 0x04) {
						inputlevel[k] = (-Z_Pos * 100) / 1000.0;
					}
					break;

				case (24):
					TmpData = Data[2];
					if (TmpData & 0x04) {
						inputlevel[k] = (-W_Pos * 100) / 1000.0;
					}
					break;

				case (38):
					TmpData = Data[4];
					if (TmpData & 0x04) {
						inputlevel[k] = (-V_Pos * 100) / 1000.0;
					}
					break;

				default:
					break;
				}

				switch (inoutmap[k][1]) {
				case (23):
					TmpData = Data[0];
					if (TmpData & 0x10) {
						inputlevel[k] = (Z_Pos * 100) / 1000.0;
					}
					break;

				case (24):
					TmpData = Data[2];
					if (TmpData & 0x10) {
						inputlevel[k] = (W_Pos * 100) / 1000.0;
					}
					break;

				case (38):
					TmpData = Data[4];
					if (TmpData & 0x10) {
						inputlevel[k] = (V_Pos * 100) / 1000.0;
					}
					break;

				default:
					break;

				}
				CalcTarCurr(k);
			}
		}
	}

}

void GetSPIData(char mode) {
	static uint8_t Data[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	uint16_t i,k;
	uint8_t Status1 = 0;
	uint8_t Status2 = 0;
    uint16_t DummyData = 0;
    uint16_t DummyRead = 0;

    if (mode == 1) {

		for (i = 0; i <=8 ; i++) {
			EnableStartOfFrame(SPI001_Handle0);
			SPI001_ClearFlag(&SPI001_Handle0, SPI001_RECV_IND_FLAG);
			SPI001_ClearFlag(&SPI001_Handle0, SPI001_ALT_RECV_IND_FLAG);

			DummyData = i;
			/* Send read page command */
			SPI001_WriteData(&SPI001_Handle0, &DummyData, SPI001_STANDARD);

			/*wait for dummy to be received*/
			do {
				Status1 = SPI001_GetFlagStatus(&SPI001_Handle0,
						SPI001_RECV_IND_FLAG);
				Status2 = SPI001_GetFlagStatus(&SPI001_Handle0,
						SPI001_ALT_RECV_IND_FLAG);
			} while (!((Status1 == SPI001_SET) || (Status2 == SPI001_SET)));

			if(i>0)
			{
				SPI001_ReadData(&SPI001_Handle0, &spidatain[i-1]);
			}
			else
			{
				SPI001_ReadData(&SPI001_Handle0, &DummyRead); // dummy read
			}
			/* Enable end of frame */
			EnableEndOfFrame(SPI001_Handle0);

			SPI001_ClearFlag(&SPI001_Handle0, SPI001_RECV_IND_FLAG);
			SPI001_ClearFlag(&SPI001_Handle0, SPI001_ALT_RECV_IND_FLAG);

			for(k=0;k<1000;k++)
			{
				;
			}

		}

		for (i = 0; i < 8; i++) {
			Data[i] = spidatain[i];
		}
		HandleCanMessageBasic(Data,2);
		HandleCanMessageBasic(CanDataRx,1);

	}

	else if (mode == 2) {

		for (i = 8; i <= 16; i++) {
			EnableStartOfFrame(SPI001_Handle0);
			SPI001_ClearFlag(&SPI001_Handle0, SPI001_RECV_IND_FLAG);
			SPI001_ClearFlag(&SPI001_Handle0, SPI001_ALT_RECV_IND_FLAG);

			DummyData = i;
			/* Send read page command */
			SPI001_WriteData(&SPI001_Handle0, &DummyData, SPI001_STANDARD);

			/*wait for dummy to be received*/
			do {
				Status1 = SPI001_GetFlagStatus(&SPI001_Handle0,
						SPI001_RECV_IND_FLAG);
				Status2 = SPI001_GetFlagStatus(&SPI001_Handle0,
						SPI001_ALT_RECV_IND_FLAG);
			} while (!((Status1 == SPI001_SET) || (Status2 == SPI001_SET)));

			if(i>8)
			{
				SPI001_ReadData(&SPI001_Handle0, &spidatain[i-1]);
			}
			else
			{
				SPI001_ReadData(&SPI001_Handle0, &DummyRead); // dummy read
			}
			/* Enable end of frame */
			EnableEndOfFrame(SPI001_Handle0);

			SPI001_ClearFlag(&SPI001_Handle0, SPI001_RECV_IND_FLAG);
			SPI001_ClearFlag(&SPI001_Handle0, SPI001_ALT_RECV_IND_FLAG);

			for(k=0;k<1000;k++)
			{
				;
			}

		}

		for (i = 8; i < 16; i++) {
			Data[i - 8] = spidatain[i];
		}
		HandleCanMessageExtended(Data,2);
		HandleCanMessageExtended(CanDataExtRx,1);
	}

}

void CAN_Basic_RX_Handler()
{

	/* Check receive pending status */
	if(CAN001_GetMOFlagStatus(&CAN001_Handle0,1,RECEIVE_PENDING) == CAN_SET)
	{
		/* Clear flag status */
		CAN001_ClearMOFlagStatus(&CAN001_Handle0,1,RECEIVE_PENDING);

		/* Read the received Message object and stores in variable CanRecMsgObj */
		CAN001_ReadMsgObj(&CAN001_Handle0,&CanRecMsgObj,1);

		CanDataRx[0]=CanRecMsgObj.data[0];
		CanDataRx[1]=CanRecMsgObj.data[1];
		CanDataRx[2]=CanRecMsgObj.data[2];
		CanDataRx[3]=CanRecMsgObj.data[3];
		CanDataRx[4]=CanRecMsgObj.data[4];
		CanDataRx[5]=CanRecMsgObj.data[5];
		CanDataRx[6]=CanRecMsgObj.data[6];
		CanDataRx[7]=CanRecMsgObj.data[7];

	}
	if(CAN001_GetNodeFlagStatus(&CAN001_Handle0,CAN001_ALERT_STATUS) == CAN_SET)
	{
		/* Clear the flag */
		CAN001_ClearNodeFlagStatus(&CAN001_Handle0,CAN001_ALERT_STATUS);
	}
}

void CAN_Extended_RX_Handler()
{
	if(CAN001_GetMOFlagStatus(&CAN001_Handle0,2,RECEIVE_PENDING) == CAN_SET)
	{
		CAN001_ClearMOFlagStatus(&CAN001_Handle0,2,RECEIVE_PENDING);
		CAN001_ReadMsgObj(&CAN001_Handle0,&CanExtRecMsgObj,2);

		CanDataExtRx[0]=CanExtRecMsgObj.data[0];
		CanDataExtRx[1]=CanExtRecMsgObj.data[1];
		CanDataExtRx[2]=CanExtRecMsgObj.data[2];
		CanDataExtRx[3]=CanExtRecMsgObj.data[3];
		CanDataExtRx[4]=CanExtRecMsgObj.data[4];
		CanDataExtRx[5]=CanExtRecMsgObj.data[5];
		CanDataExtRx[6]=CanExtRecMsgObj.data[6];

	}

	if(CAN001_GetNodeFlagStatus(&CAN001_Handle0,CAN001_ALERT_STATUS) == CAN_SET)
	{
		CAN001_ClearNodeFlagStatus(&CAN001_Handle0,CAN001_ALERT_STATUS);
	}
}

uint16_t CalculateRxChecksum(void)
{
	int i;
	uint16_t calccksum=0;

	for(i=0;i<=uartmsglen-2;i++)
	{
		calccksum=calccksum+rxbuf[i];
	}
	return calccksum;
}

void CalculateTxChecksum(uint8_t len)
{
	int i;
	uint16_t calccksum=0;

	for(i=0;i<len-2;i++)
	{
		calccksum=calccksum+txbuf[i];
	}

	txbuf[len-2]=calccksum/256;
	txbuf[len-1]=calccksum%256;

}

void ResetUartIndex(void)
{
	uarttimeout=0;
	rxindex=0;
	uartmsglen=1;
}

/* Fifo standard receive buffer event handler */
void RxUartEventHandler()
{
    uint8_t DataRead;
    uint8_t TmpSecId;
    uint32_t i,k;
    uint32_t membaseaddress;

	if(UART001_GetFlagStatus(&UART001_Handle0,UART001_FIFO_STD_RECV_BUF_FLAG) == UART001_SET)
	{
		/* Read the received data to the buffer */
		DataRead=UART001_ReadDataBytes(&UART001_Handle0,&rxbuf[rxindex],uartmsglen);
		UART001_ClearFlag(&UART001_Handle0,UART001_FIFO_STD_RECV_BUF_FLAG);
		rxindex=rxindex+DataRead;

		uarttimeout=100;

		 if(uartmsglen==1 && sendflag==0)
		 {
			 switch(rxbuf[0]){
			 	 case 1: uartmsglen=3;
			 		 	 break;
			 	 case 3: uartmsglen=2;
			 			 break;
			 	 case 4: uartmsglen=2;
			 			 break;
			 	 case 5: uartmsglen=158;
			 			 break;
			 	 case 6: uartmsglen=3;
			 			 break;
			 	 case 7: uartmsglen=66;
			 			 break;
			 	 case 15:uartmsglen=2;
			 		 	 break;
			 	 case 16:uartmsglen=50;
			 		 	 break;
			 	 default:
			 		 	 break;
			 }

		 }
		 else if(rxindex==uartmsglen+1  && sendflag==0)
		 {
			 if(CalculateRxChecksum()==(rxbuf[uartmsglen-1]*256+rxbuf[uartmsglen]))
			 {
				 switch(rxbuf[0])
				 {
				 	 //Risposta Start Diagno
				 	 case 1:startdiagno=rxbuf[1]+1;
				 	 	 	ackstartdiagno=1;
				 	 	 	ResetUartIndex();
				 	 	 	/*txlen=4;
				 		 	txbuf[0]=0x01;
					 	    txbuf[1]=0x01;
					 	    CalculateTxChecksum(txlen);
					 	    sendflag=1;*/
				 		 	break;
				 	 case 3:startdiagno=0;
				 	 	 	stopdiagno=1;
					 	 	ResetUartIndex();
				 	 	    /*txlen=4;
				 			txbuf[0]=0x03;
					 	 	txbuf[1]=0x01;
					 	 	CalculateTxChecksum(txlen);
					 	 	sendflag=1;*/
				 		 	break;
				 	 case 4:txlen=159;
				 	 	 	txbuf[0]=0x04;
				 	 	 	txbuf[1]=sectionconf;
				 	 	 	for(i=0;i<10;i++)
				 	 	 	{
				 	 	 		txbuf[2+i]=analoginmodemem[i];
				 	 	 	}
				 	 	 	txbuf[12]=auxvolt;
				 	 	 	for(i=0;i<8;i++)
				 	 	 	{
				 	 	 		for(k=0;k<8;k++)
				 	 	 		{
				 	 	 			txbuf[13+(i*8)+k]=sectionname[i][k];
				 	 	 		}
				 	 	 	}

				 	 	 	for(i=0;i<10;i++)
				 	 	 	{
				 	 	 		for(k=0;k<8;k++)
				 	 	 		{
				 	 	 			txbuf[77+(i*8)+k]=analoginname[i][k];
				 	 	 		}
				 	 	 	}
				 	 	 	CalculateTxChecksum(txlen);
				 	 	 	ResetUartIndex();
				 	 	 	sendflag=1;
				 	 	 	break;
				 	 case 5:
				 		 	sectionconf=rxbuf[1];
				 		 	for(i=0;i<10;i++)
				 		 	{
				 		 		analoginmodemem[i]=rxbuf[2+i];

				 		 		if((analoginmodemem[i] & 0x80)!=0)
				 		 		{
				 		 			analoginmode[i]=analoginmodemem[i] & 0x7F;
				 		 			analoginDMenable=i+1;
				 		 		}
				 		 		else
				 		 		{
				 		 			analoginmode[i]=analoginmodemem[i];
				 		 		}
				 		 	}
				 		 	auxvolt=rxbuf[12];
				 		 	for(i=0;i<8;i++)
				 		 	{
				 		 		for(k=0;k<8;k++)
				 		 		{
				 		 			sectionname[i][k]=rxbuf[13+(i*8)+k];
				 		 		}
				 		 	}

				 		 	for(i=0;i<10;i++)
				 		 	{
				 		 		for(k=0;k<8;k++)
				 		 		{
				 		 			analoginname[i][k]=rxbuf[77+(i*8)+k];
				 		 		}
				 		 	}

				 		 	SetupAuxOutput();
				 		 	SetupAnalogInputs();

				 		 	membaseaddress=boardconfigoffset;

				 		 	for(i=0;i<boardconfigsize;i++)
				 		 	{
				 		 		membuffer[membaseaddress+i]=rxbuf[i+1];
				 		 	}

					 	 	ResetUartIndex();
					 	 	memioconfig=1;

					 	 	break;

				 	 case 6:TmpSecId=rxbuf[1];
				 	 	 	txlen=67;
				 	 	 	txbuf[0]=0x06;
				 	 	 	txbuf[1]=TmpSecId;

				 	 	 	txbuf[2]=loopfreq[TmpSecId];
				 	 	 	txbuf[3]=ditherampl[TmpSecId];
				 	 	 	txbuf[4]=configsec[TmpSecId];

				 	 	 	txbuf[5]=imaxv1[TmpSecId]/256;
				 	 	 	txbuf[6]=imaxv1[TmpSecId]%256;
				 	 	 	txbuf[7]=iminv1[TmpSecId]/256;
				 	 	 	txbuf[8]=iminv1[TmpSecId]%256;
				 	 	 	txbuf[9]=maxctrlv1[TmpSecId];
				 	 	 	txbuf[10]=minctrlv1[TmpSecId];

				 	 	 	txbuf[11]=i_0_v1[TmpSecId]/256;
				 	 	 	txbuf[12]=i_0_v1[TmpSecId]%256;
				 	 	 	txbuf[13]=i_100_v1[TmpSecId]/256;
				 	 	 	txbuf[14]=i_100_v1[TmpSecId]%256;

				 	 	 	txbuf[15]=slopeupipointsv1[0][TmpSecId]/256;
				 	 	 	txbuf[16]=slopeupipointsv1[0][TmpSecId]%256;

				 	 	 	txbuf[17]=slopeupipointsv1[1][TmpSecId]/256;
				 	 	 	txbuf[18]=slopeupipointsv1[1][TmpSecId]%256;

				 	 	 	txbuf[19]=slopeupipointsv1[2][TmpSecId]/256;
				 	 	 	txbuf[20]=slopeupipointsv1[2][TmpSecId]%256;

				 	 	 	txbuf[21]=slopeuptpointsv1[0][TmpSecId];
				 	 	 	txbuf[22]=slopeuptpointsv1[1][TmpSecId];
				 	 	 	txbuf[23]=slopeuptpointsv1[2][TmpSecId];
				 	 	 	txbuf[24]=slopeuptpointsv1[3][TmpSecId];

				 	 	 	txbuf[25]=slopedownipointsv1[0][TmpSecId]/256;
				 	 	 	txbuf[26]=slopedownipointsv1[0][TmpSecId]%256;

				 	 	 	txbuf[27]=slopedownipointsv1[1][TmpSecId]/256;
				 	 	 	txbuf[28]=slopedownipointsv1[1][TmpSecId]%256;

				 	 	 	txbuf[29]=slopedownipointsv1[2][TmpSecId]/256;
				 	 	 	txbuf[30]=slopedownipointsv1[2][TmpSecId]%256;

				 	 	 	txbuf[31]=slopedowntpointsv1[0][TmpSecId];
				 	 	 	txbuf[32]=slopedowntpointsv1[1][TmpSecId];
				 	 	 	txbuf[33]=slopedowntpointsv1[2][TmpSecId];
				 	 	 	txbuf[34]=slopedowntpointsv1[3][TmpSecId];

				 	 	 	txbuf[35]=imaxv2[TmpSecId]/256;
				 	 	 	txbuf[36]=imaxv2[TmpSecId]%256;

				 	 	 	txbuf[37]=iminv2[TmpSecId]/256;
				 	 	 	txbuf[38]=iminv2[TmpSecId]%256;

				 	 	 	txbuf[39]=-maxctrlv2[TmpSecId];
				 	 	 	txbuf[40]=-minctrlv2[TmpSecId];

				 	 	 	txbuf[41]=i_0_v2[TmpSecId]/256;
				 	 	 	txbuf[42]=i_0_v2[TmpSecId]%256;
				 	 	 	txbuf[43]=i_100_v2[TmpSecId]/256;
				 	 	 	txbuf[44]=i_100_v2[TmpSecId]%256;

				 	 	 	txbuf[45]=slopeupipointsv2[0][TmpSecId]/256;
				 	 	 	txbuf[46]=slopeupipointsv2[0][TmpSecId]%256;

				 	 	 	txbuf[47]=slopeupipointsv2[1][TmpSecId]/256;
				 	 	 	txbuf[48]=slopeupipointsv2[1][TmpSecId]%256;

				 	 	 	txbuf[49]=slopeupipointsv2[2][TmpSecId]/256;
				 	 	 	txbuf[50]=slopeupipointsv2[2][TmpSecId]%256;

				 	 	 	txbuf[51]=slopeuptpointsv2[0][TmpSecId];
				 	 	 	txbuf[52]=slopeuptpointsv2[1][TmpSecId];
				 	 	 	txbuf[53]=slopeuptpointsv2[2][TmpSecId];
				 	 	 	txbuf[54]=slopeuptpointsv2[3][TmpSecId];

				 	 	 	txbuf[55]=slopedownipointsv2[0][TmpSecId]/256;
				 	 	 	txbuf[56]=slopedownipointsv2[0][TmpSecId]%256;

				 	 	 	txbuf[57]=slopedownipointsv2[1][TmpSecId]/256;
				 	 	 	txbuf[58]=slopedownipointsv2[1][TmpSecId]%256;

				 	 	 	txbuf[59]=slopedownipointsv2[2][TmpSecId]/256;
				 	 	 	txbuf[60]=slopedownipointsv2[2][TmpSecId]%256;

				 	 	 	txbuf[61]=slopedowntpointsv2[0][TmpSecId];
				 	 	 	txbuf[62]=slopedowntpointsv2[1][TmpSecId];
				 	 	 	txbuf[63]=slopedowntpointsv2[2][TmpSecId];
				 	 	 	txbuf[64]=slopedowntpointsv2[3][TmpSecId];

				 	 	 	CalculateTxChecksum(txlen);
				 	 	 	ResetUartIndex();
				 	 	 	sendflag=1;
				 		 	break;

				 	 case 7:TmpSecId=rxbuf[1];
				 	 	    SectionIndex=TmpSecId;

				 	 	 	loopfreq[TmpSecId]=rxbuf[2];
				 	 	 	ditherampl[TmpSecId]=rxbuf[3];
				 	 	 	configsec[TmpSecId]=rxbuf[4];

				 	 	 	imaxv1[TmpSecId]=rxbuf[5]*256+rxbuf[6];
				 		 	iminv1[TmpSecId]=rxbuf[7]*256+rxbuf[8];
				 		 	maxctrlv1[TmpSecId]=rxbuf[9];
				 		 	minctrlv1[TmpSecId]=rxbuf[10];

				 		 	i_0_v1[TmpSecId]=rxbuf[11]*256+rxbuf[12];
				 		 	i_100_v1[TmpSecId]=rxbuf[13]*256+rxbuf[14];

				 		 	slopeupipointsv1[0][TmpSecId]=rxbuf[15]*256+rxbuf[16];
				 		 	slopeupipointsv1[1][TmpSecId]=rxbuf[17]*256+rxbuf[18];
				 		 	slopeupipointsv1[2][TmpSecId]=rxbuf[19]*256+rxbuf[20];

				 		 	slopeuptpointsv1[0][TmpSecId]=rxbuf[21];
				 		 	slopeuptpointsv1[1][TmpSecId]=rxbuf[22];
				 		 	slopeuptpointsv1[2][TmpSecId]=rxbuf[23];
				 		 	slopeuptpointsv1[3][TmpSecId]=rxbuf[24];

				 		 	slopedownipointsv1[0][TmpSecId]=rxbuf[25]*256+rxbuf[26];
				 		 	slopedownipointsv1[1][TmpSecId]=rxbuf[27]*256+rxbuf[28];
				 		 	slopedownipointsv1[2][TmpSecId]=rxbuf[29]*256+rxbuf[30];

				 		 	slopedowntpointsv1[0][TmpSecId]=rxbuf[31];
				 		 	slopedowntpointsv1[1][TmpSecId]=rxbuf[32];
				 		 	slopedowntpointsv1[2][TmpSecId]=rxbuf[33];
				 		 	slopedowntpointsv1[3][TmpSecId]=rxbuf[34];

				 		 	imaxv2[TmpSecId]=rxbuf[35]*256+rxbuf[36];
				 		 	iminv2[TmpSecId]=rxbuf[37]*256+rxbuf[38];
				 		 	maxctrlv2[TmpSecId]=rxbuf[39];
				 		 	minctrlv2[TmpSecId]=rxbuf[40];

				 		 	i_0_v2[TmpSecId]=rxbuf[41]*256+rxbuf[42];
				 		 	i_100_v2[TmpSecId]=rxbuf[43]*256+rxbuf[44];

				 		 	slopeupipointsv2[0][TmpSecId]=rxbuf[45]*256+rxbuf[46];
				 		 	slopeupipointsv2[1][TmpSecId]=rxbuf[47]*256+rxbuf[48];
				 		 	slopeupipointsv2[2][TmpSecId]=rxbuf[49]*256+rxbuf[50];

				 		 	slopeuptpointsv2[0][TmpSecId]=rxbuf[51];
				 		 	slopeuptpointsv2[1][TmpSecId]=rxbuf[52];
				 		 	slopeuptpointsv2[2][TmpSecId]=rxbuf[53];
				 		 	slopeuptpointsv2[3][TmpSecId]=rxbuf[54];

				 		 	slopedownipointsv2[0][TmpSecId]=rxbuf[55]*256+rxbuf[56];
				 		 	slopedownipointsv2[1][TmpSecId]=rxbuf[57]*256+rxbuf[58];
				 		 	slopedownipointsv2[2][TmpSecId]=rxbuf[59]*256+rxbuf[60];

				 		 	slopedowntpointsv2[0][TmpSecId]=rxbuf[61];
				 		 	slopedowntpointsv2[1][TmpSecId]=rxbuf[62];
				 		 	slopedowntpointsv2[2][TmpSecId]=rxbuf[63];
				 		 	slopedowntpointsv2[3][TmpSecId]=rxbuf[64];

				 		 	SetupCoeff(TmpSecId);

				 		 	membaseaddress=sectionparamsize*TmpSecId;

				 		 	for(i=0;i<sectionparamsize;i++)
				 		 	{
				 		 		membuffer[membaseaddress+i]=rxbuf[i+2];
				 		 	}

				 		 	ResetUartIndex();
				 		 	memsectionconfig=1;
				 		    break;
				     //Read Pin Mapping
				 	 case 15:
				 		 	txlen=51;
				 	 	 	txbuf[0]=15;
				 	 	 	for(k=0;k<8;k++)
				 	 	 	{
				 	 	 		for(i=0;i<6;i++)
				 	 	 		{
				 	 	 			txbuf[k*6+i+1]=pinmapping[k][i];
				 	 	 		}
				 	 	 	}
				 	 	 	CalculateTxChecksum(txlen);
				 	 	 	ResetUartIndex();
				 	 	 	sendflag=1;
				 		 	break;
				 	 case 16:
				 		    //Write Pin Mapping
				 		 	for(k=0;k<8;k++)
				 		 	{
				 		 		for(i=0;i<6;i++)
				 		 		{
						 		 	pinmapping[k][i]=rxbuf[k*6+i+1];
				 		 		}
				 		 	}

				 		 	SetupPinMapping();

				 		 	membaseaddress=pinmappingoffset;

				 		 	for(i=0;i<pinmappingsize;i++)
				 		 	{
				 		 		membuffer[membaseaddress+i]=rxbuf[i+1];
				 		 	}

				 		 	flash_status=Flash002_EraseSector(FLASH002_SECTOR11_BASE);

					 	 	ResetUartIndex();
					 	 	mempinmapping=1;
				 			break;
				 	 default:
				 		    ResetUartIndex();
				 		 	break;
				 }
			 }
		 }
	}
}

void ADC0_CH0_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;

	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr[2]=tmpcurr[2]+(uint32_t)ADC0_CH0_BUFFER[k];
	}

	tmpcurr[2]=tmpcurr[2]/400;
	CalcActPwm(2,tmpcurr[2]);

	DMA003_ReloadUserConfiguration(&DMA003_Handle1);
	DMA003_StartTransfer(&DMA003_Handle1);

	//IO004_ResetPin(IO004_Handle45);

}


void ADC0_CH5_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;

	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr[0]=tmpcurr[0]+(uint32_t)ADC0_CH5_BUFFER[k];
	}

	tmpcurr[0]=tmpcurr[0]/400;
	CalcActPwm(0,tmpcurr[0]);


	DMA003_ReloadUserConfiguration(&DMA003_Handle2);
	DMA003_StartTransfer(&DMA003_Handle2);

	//IO004_ResetPin(IO004_Handle45);
}

void ADC0_CH4_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;

	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr[1]=tmpcurr[1]+(uint32_t)ADC0_CH4_BUFFER[k];
	}

	tmpcurr[1]=tmpcurr[1]/400;
	CalcActPwm(1,tmpcurr[1]);

	DMA003_ReloadUserConfiguration(&DMA003_Handle3);
	DMA003_StartTransfer(&DMA003_Handle3);

	//IO004_ResetPin(IO004_Handle45);
}

void ADC0_CH6_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;

	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr[3]=tmpcurr[3]+(uint32_t)ADC0_CH6_BUFFER[k];
	}

	tmpcurr[3]=tmpcurr[3]/400;
	CalcActPwm(3,tmpcurr[3]);

	DMA003_ReloadUserConfiguration(&DMA003_Handle4);
	DMA003_StartTransfer(&DMA003_Handle4);

	//IO004_ResetPin(IO004_Handle45);
}

void ADC1_CH1_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;

	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr[6]=tmpcurr[6]+(uint32_t)ADC1_CH1_BUFFER[k];
	}

	tmpcurr[6]=tmpcurr[6]/400;
	CalcActPwm(6,tmpcurr[6]);

	DMA003_ReloadUserConfiguration(&DMA003_Handle9);
	DMA003_StartTransfer(&DMA003_Handle9);
	//IO004_ResetPin(IO004_Handle45);
}

void ADC1_CH7_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;

	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr[5]=tmpcurr[5]+(uint32_t)ADC1_CH7_BUFFER[k];
	}

	tmpcurr[5]=tmpcurr[5]/400;
	CalcActPwm(5,tmpcurr[5]);

	DMA003_ReloadUserConfiguration(&DMA003_Handle10);
	DMA003_StartTransfer(&DMA003_Handle10);
	//IO004_ResetPin(IO004_Handle45);
}

void ADC1_CH8_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;

	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr[4]=tmpcurr[4]+(uint32_t)ADC1_CH8_BUFFER[k];
	}

	tmpcurr[4]=tmpcurr[4]/400;
	CalcActPwm(4,tmpcurr[4]);

	DMA003_ReloadUserConfiguration(&DMA003_Handle11);
	DMA003_StartTransfer(&DMA003_Handle11);

	//IO004_ResetPin(IO004_Handle45);
}

void ADC1_CH9_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;

	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr[7]=tmpcurr[7]+(uint32_t)ADC1_CH9_BUFFER[k];
	}

	tmpcurr[7]=tmpcurr[7]/400;
	CalcActPwm(7,tmpcurr[7]);

	DMA003_ReloadUserConfiguration(&DMA003_Handle12);
	DMA003_StartTransfer(&DMA003_Handle12);

	//IO004_ResetPin(IO004_Handle45);
}

void SetupDiagnoMsg(void)
{

	if(ackstartdiagno==0)
	{
		if (startdiagno > 0 && startdiagno <= 8) {
			txbuf[0] = 0x02;
			txbuf[1] = startdiagno - 1;

			if (sectionconf & startdiagno) {
				if (diagnocurr < 0 && acttargcurr[startdiagno - 1] <= 0) {
					diagnocurr = actualcurr[startdiagno - 1] * ma_for_lev;
					diagnocurr = -diagnocurr;
				}
				if (diagnocurr >= 0 && acttargcurr[startdiagno - 1] >= 0) {
					diagnocurr = actualcurr[startdiagno - 1] * ma_for_lev;
				}

				txbuf[2] = (diagnocurr >> 8);
				txbuf[3] = (diagnocurr);

				diagnocurr = inputlevel[startdiagno - 1];

				txbuf[4] = (diagnocurr >> 8);
				txbuf[5] = (diagnocurr);
			} else {
				//Stato Ingressi
			}

			txbuf[6] = sectionstatus[startdiagno - 1];
			txlendiagno = 9;
			CalculateTxChecksum(txlendiagno);
		} else if (startdiagno == 10) {
			txbuf[0] = 0x09;
			txbuf[1] = dietemp + 128; //Mettere valore di temperatura;
			txlendiagno = 4;
			CalculateTxChecksum(txlendiagno);
		}
		/*else if(startdiagno==10)
		 {
		 txbuf[0]=0x0A;
		 txbuf[1]=0x00; //Mettere valore di Stato Generale;
		 txlendiagno=4;
		 CalculateTxChecksum(txlendiagno);
		 }*/
		else if (startdiagno > 20 && startdiagno <= 30) {
			txbuf[0] = 0x0B;
			txbuf[1] = startdiagno - 21;

			switch (startdiagno) {
			case 21:
				txbuf[2] = G2Ch1Val / 256; //Valore analogico High-Byte Input 1
				txbuf[3] = G2Ch1Val % 256; //Valore analogico Low-Byte  Input 1
				break;
			case 22:
				txbuf[2] = G2Ch2Val / 256; //Valore analogico High-Byte Input 2
				txbuf[3] = G2Ch2Val % 256; //Valore analogico Low-Byte  Input 2
				break;
			case 23:
				txbuf[2] = G2Ch3Val / 256; //Valore analogico High-Byte Input 3
				txbuf[3] = G2Ch3Val % 256; //Valore analogico Low-Byte  Input 3
				break;
			case 24:
				txbuf[2] = G2Ch4Val / 256; //Valore analogico High-Byte Input 4
				txbuf[3] = G2Ch4Val % 256; //Valore analogico Low-Byte  Input 4
				break;
			case 25:
				txbuf[2] = G2Ch5Val / 256; //Valore analogico High-ByteInput 5
				txbuf[3] = G2Ch5Val % 256; //Valore analogico Low-Byte Input 5
				break;
			case 26:
				txbuf[2] = G3Ch1Val / 256; //Valore analogico High-Byte Input 6
				txbuf[3] = G3Ch1Val % 256; //Valore analogico Low-Byte  Input 6
				break;
			case 27:
				txbuf[2] = G3Ch2Val / 256; //Valore analogico High-Byte Input 7
				txbuf[3] = G3Ch2Val % 256; //Valore analogico Low-Byte  Input 7
				break;
			case 28:
				txbuf[2] = G3Ch3Val / 256; //Valore analogico High-Byte Input 8
				txbuf[3] = G3Ch3Val % 256; //Valore analogico Low-Byte  Input 8
				break;
			case 29:
				txbuf[2] = G3Ch4Val / 256; //Valore analogico High-Byte Input 9
				txbuf[3] = G3Ch4Val % 256; //Valore analogico Low-Byte  Input 9
				break;
			case 30:
				txbuf[2] = G3Ch5Val / 256; //Valore analogico High-ByteInput 10
				txbuf[3] = G3Ch5Val % 256; //Valore analogico Low-Byte Input 10
				break;
			}

			txlendiagno = 6;
			CalculateTxChecksum(txlendiagno);
		}
	}
	else
	{
		ackstartdiagno=0;
		txlendiagno=4;
		txbuf[0]=0x01;
		txbuf[1]=0x01;
		CalculateTxChecksum(txlendiagno);
	}

	if(stopdiagno==1)
	{
		stopdiagno=0;
		txlendiagno=4;
		txbuf[0]=0x03;
		txbuf[1]=0x01;
		CalculateTxChecksum(txlendiagno);
	}

}

void MAIN_CLOCK_HANDLER(void* Temp)
{
	uint8_t DataRead;
	uint8_t DummyDataBuf[32];
	float v1analoginputlevel,v2analoginputlevel,emergencyanaloginputlevel;
	uint8_t	v1valid,v2valid;
	int v1tmppercentage=0,v2tmppercentage=0;
	uint8_t emergencylevel;

	int k=0;

	if(uarttimeout>0)
	{
		uarttimeout--;
		if(uarttimeout==0)
		{
			do{
				DataRead=UART001_ReadDataBytes(&UART001_Handle0,DummyDataBuf,32);
			}while(DataRead>0);

			UART001_ClearFlag(&UART001_Handle0,UART001_FIFO_STD_RECV_BUF_FLAG);
			UART001_ClearFlag(&UART001_Handle0,UART001_FIFO_RECV_BUF_ERR_FLAG);

			rxindex=0;
			uartmsglen=1;
		}
	}

	for(k=0;k<8;k++)
	{
		if(sectionstatus[k]!=0)
		{
			sectionrecoverydelay[k]++;
			if(sectionrecoverydelay[k]>sectionrecoverydelaythr)
			{
				sectionrecoverydelay[k]=0;
				sectionstatus[k]=0;
				switch(k)
				{
				case 0: PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle0);
						break;
				case 1: PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle1);
						break;
				case 2: PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle2);
						break;
				case 3: PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle3);
						break;
				#ifdef sectioneightenable
				case 4: PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle4);
						break;
				case 5: PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle5);
						break;
				case 6: PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle6);
						break;
				case 7: PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle7);
						break;
				#endif

				}
			}
		}

		if((((configsec[k] & 0x02)==0x02) || ((configsec[k] & 0x04)==0x04)))
		{
			if(timertrigger[k]==FALSE)
			{
				timertrigger[k]=TRUE;
			}
		}
	}

	if(spidatainenable==1)
	{
		auxreading++;
	}

	if(analoginenable==1)
	{
		//Leggo le analogiche ausiliarie
		ADCCH001_GetResult(&ADCCH001_Handle10, &NoMappedVal1);
		NoMappedVal1=NoMappedVal1/4;

		ADCCH001_GetResult(&ADCCH001_Handle11, &G2Ch2Val);
		G2Ch2Val=G2Ch2Val/4;
		//Tolgo l'offset in basso delle analogiche gruppo 2  se modalità 0-5V, 0-10V o 4-20mA
		if(analoginmode[1]>0 && analoginmode[1]<4)
		{
			G2Ch2Val=G2Ch2Val-10;
		}

		if(analoginmode[1]==3)
		{
			//Tolgo l'offset dei 4mA
			G2Ch2Val=G2Ch2Val-440;
			if(G2Ch2Val>10000)
			{
				G2Ch2Val=0;
			}
		}

		ADCCH001_GetResult(&ADCCH001_Handle12, &G2Ch1Val);
		G2Ch1Val=G2Ch1Val/4;
		//Tolgo l'offset in basso delle analogiche gruppo 2  se modalità 0-5V, 0-10V o 4-20mA
		if(analoginmode[0]>0 && analoginmode[0]<4)
		{
			G2Ch1Val=G2Ch1Val-10;
		}
		if(analoginmode[0]==3)
		{
			//Tolgo l'offset dei 4mA
			G2Ch1Val=G2Ch1Val-440;
			if(G2Ch1Val>10000)
			{
				G2Ch1Val=0;
			}
		}

		ADCCH001_GetResult(&ADCCH001_Handle13, &G2Ch4Val);
		G2Ch4Val=G2Ch4Val/4;
		//Tolgo l'offset in basso delle analogiche gruppo 2  se modalità 0-5V, 0-10V o 4-20mA
		if(analoginmode[3]>0 && analoginmode[3]<4)
		{
			G2Ch4Val=G2Ch4Val-10;
		}

		if(analoginmode[3]==3)
		{
			//Tolgo l'offset dei 4mA
			G2Ch4Val=G2Ch4Val-440;
			if(G2Ch4Val>10000)
			{
				G2Ch4Val=0;
			}

		}

		ADCCH001_GetResult(&ADCCH001_Handle14, &G2Ch3Val);
		G2Ch3Val=G2Ch3Val/4;
		//Tolgo l'offset in basso delle analogiche gruppo 2  se modalità 0-5V, 0-10V o 4-20mA
		if(analoginmode[2]>0 && analoginmode[2]<4)
		{
			G2Ch3Val=G2Ch3Val-10;
		}

		if(analoginmode[2]==3)
		{
			//Tolgo l'offset dei 4mA
			G2Ch3Val=G2Ch3Val-440;
			if(G2Ch3Val>10000)
			{
				G2Ch3Val=0;
			}

		}

		ADCCH001_GetResult(&ADCCH001_Handle2,  &G2Ch5Val);
		G2Ch5Val=G2Ch5Val/4;
		//Tolgo l'offset in basso delle analogiche gruppo 2 se modalità 0-5V, 0-10V o 4-20mA
		if(analoginmode[4]>0 && analoginmode[4]<4)
		{
			G2Ch5Val=G2Ch5Val-10;
		}

		if(analoginmode[4]==3)
		{
			//Tolgo l'offset dei 4mA
			G2Ch5Val=G2Ch5Val-440;
			if(G2Ch5Val>10000)
			{
				G2Ch5Val=0;
			}
		}

		ADCCH001_GetResult(&ADCCH001_Handle15, &G3Ch3Val);
		G3Ch3Val=G3Ch3Val/4;
		if(analoginmode[7]==3)
		{
			//Tolgo l'offset dei 4mA
			G3Ch3Val=G3Ch3Val-440;
			if(G3Ch3Val>10000)
			{
				G3Ch3Val=0;
			}
		}

		ADCCH001_GetResult(&ADCCH001_Handle16, &G3Ch1Val);
		G3Ch1Val=G3Ch1Val/4;
		if(analoginmode[5]==3)
		{
			//Tolgo l'offset dei 4mA
			G3Ch1Val=G3Ch1Val-440;
			if(G3Ch1Val>10000)
			{
				G3Ch1Val=0;
			}
		}

		ADCCH001_GetResult(&ADCCH001_Handle17, &G3Ch4Val);
		G3Ch4Val=G3Ch4Val/4;
		if(analoginmode[8]==3)
		{
			//Tolgo l'offset dei 4mA
			G3Ch4Val=G3Ch4Val-440;
			if(G3Ch4Val>10000)
			{
				G3Ch4Val=0;
			}

		}

		ADCCH001_GetResult(&ADCCH001_Handle18, &G3Ch5Val);
		G3Ch5Val=G3Ch5Val/4;
		if(analoginmode[9]==3)
		{
			//Tolgo l'offset dei 4mA
			G3Ch5Val=G3Ch5Val-440;
			if(G3Ch5Val>10000)
			{
				G3Ch5Val=0;
			}
		}

		ADCCH001_GetResult(&ADCCH001_Handle19, &G3Ch2Val);
		G3Ch2Val=G3Ch2Val/4;
		if(analoginmode[6]==3)
		{
			//Tolgo l'offset dei 4mA
			G3Ch2Val=G3Ch2Val-440;
			if(G3Ch2Val>10000)
			{
				G3Ch2Val=0;
			}
		}

		ADCCH001_GetResult(&ADCCH001_Handle3, &NoMappedVal2);
		NoMappedVal2=NoMappedVal2/4;

		if(analoginDMenable!=0)
		{
			switch(analoginDMenable)
			{
				case 1:emergencyanaloginputlevel=G2Ch1Val;
					break;
				case 2:emergencyanaloginputlevel=G2Ch2Val;
					break;
				case 3:emergencyanaloginputlevel=G2Ch3Val;
					break;
				case 4:emergencyanaloginputlevel=G2Ch4Val;
					break;
				case 5:emergencyanaloginputlevel=G2Ch5Val;
					break;
				case 6:emergencyanaloginputlevel=G3Ch1Val;
					break;
				case 7:emergencyanaloginputlevel=G3Ch2Val;
					break;
				case 8:emergencyanaloginputlevel=G3Ch3Val;
					break;
				case 9:emergencyanaloginputlevel=G3Ch4Val;
					break;
				case 10:emergencyanaloginputlevel=G3Ch5Val;
					break;
				default:
					break;
			}

			switch (analoginmode[analoginDMenable-1] )
			{
				//0-5V
				case 1:
					emergencylevel=((emergencyanaloginputlevel-900.0)/900.0)*100.0;
					break;

				//0-10V
				case 2:
					emergencylevel=((emergencyanaloginputlevel-1805.0)/1805.0)*100;
					break;

				//4-20mA
				case 3:
					emergencylevel=((emergencyanaloginputlevel-860.0)/860.0)*100.0;
					break;

				//Raziometrico
				case 4:
					emergencylevel=((emergencyanaloginputlevel-2048.0)/2048.0)*100.0;
					break;

				default:
					break;
			}

			if(emergencylevel<25.0)
			{
				emergencylevel=0;
			}
			else if(emergencylevel>75.0)
			{
				emergencylevel=100;
			}

			if(emergencylevel==0)
			{
				G2Ch2Val=0;
				G2Ch1Val=0;
				G2Ch4Val=0;
				G2Ch3Val=0;
				G2Ch5Val=0;

				G3Ch3Val=0;
				G3Ch1Val=0;
				G3Ch4Val=0;
				G3Ch5Val=0;
				G3Ch2Val=0;
			}
		}

		for (k = 0; k < 8; k++) {

			//Fare il calcolo solo se il k è controllato dal range di ingressi scansionato
			if ((inoutmap[k][0] >= 25 && inoutmap[k][0] <= 34)
					|| (inoutmap[k][1] >= 25 && inoutmap[k][1] <= 34)) {

				inputlevel[k] = 0;

				v1valid=0;
				v2valid=0;
				v1analoginputlevel=0;
				v2analoginputlevel=0;

				switch(inoutmap[k][0])
				{
					case 25:v1analoginputlevel=G2Ch1Val;
							v1valid=1;
							break;
					case 26:v1analoginputlevel=G2Ch2Val;
							v1valid=1;
							break;
					case 27:v1analoginputlevel=G2Ch3Val;
							v1valid=1;
							break;
					case 28:v1analoginputlevel=G2Ch4Val;
							v1valid=1;
							break;
					case 29:v1analoginputlevel=G2Ch5Val;
							v1valid=1;
							break;
					case 30:v1analoginputlevel=G3Ch1Val;
							v1valid=1;
							break;
					case 31:v1analoginputlevel=G3Ch2Val;
							v1valid=1;
							break;
					case 32:v1analoginputlevel=G3Ch3Val;
							v1valid=1;
							break;
					case 33:v1analoginputlevel=G3Ch4Val;
							v1valid=1;
							break;
					case 34:v1analoginputlevel=G3Ch5Val;
							v1valid=1;
							break;
					default:
							v1valid=0;
							break;

				}

				switch(inoutmap[k][1])
				{
					case 25:v2analoginputlevel=G2Ch1Val;
							v2valid=1;
							break;
					case 26:v2analoginputlevel=G2Ch2Val;
							v2valid=1;
							break;
					case 27:v2analoginputlevel=G2Ch3Val;
							v2valid=1;
							break;
					case 28:v2analoginputlevel=G2Ch4Val;
							v2valid=1;
							break;
					case 29:v2analoginputlevel=G2Ch5Val;
							v2valid=1;
							break;
					case 30:v2analoginputlevel=G3Ch1Val;
							v2valid=1;
							break;
					case 31:v2analoginputlevel=G3Ch2Val;
							v2valid=1;
							break;
					case 32:v2analoginputlevel=G3Ch3Val;
							v2valid=1;
							break;
					case 33:v2analoginputlevel=G3Ch4Val;
							v2valid=1;
							break;
					case 34:v2analoginputlevel=G3Ch5Val;
							v2valid=1;
							break;
					default:
							v2valid=0;
							break;

				}

				//Caso A+B
				if (inoutmap[k][0] == inoutmap[k][1])
				{
					//Usando l'id dell'analogica, vado a leggere la modalità di ingresso e scalo in percentuale in base a mappatura + caso d'uso
					switch (analoginmode[(inoutmap[k][0] - 25)])
					{
						//0-5V
						case 1:
							inputlevel[k]=((v1analoginputlevel-900.0)/900.0)*100.0;
							break;

						//0-10V
						case 2:
							inputlevel[k]=((v1analoginputlevel-1805.0)/1805.0)*100;
							break;

						//4-20mA
						case 3:
							inputlevel[k]=((v1analoginputlevel-860.0)/860.0)*100.0;
							break;

						//Raziometrico
						case 4:
							inputlevel[k]=((v1analoginputlevel-2048.0)/2048.0)*100.0;
							break;

						default:
							break;
					}

					if(inputlevel[k]>98)
					{
						inputlevel[k]=0;
					}

					if(inputlevel[k]<-98)
					{
						inputlevel[k]=0;
					}

				}
				//Caso solo A - Nessun Pulsante mappato su B
				else{
					if (v1valid==1 && v2valid==0) {

					//Usando l'id dell'analogica, vado a leggere la modalità di ingresso e scalo in percentuale in base a mappatura + caso d'uso
					switch (analoginmode[(inoutmap[k][0] - 25)]) {
						//0-5V
					case 1:
						inputlevel[k] = (v1analoginputlevel / 1800.0)* 100.0;
						break;

						//0-10V
					case 2:
						inputlevel[k] = (v1analoginputlevel / 3610.0) * 100.0;
						break;

						//4-20mA
					case 3:
						inputlevel[k] = (v1analoginputlevel / 1720.0) * 100.0;
						break;

						//Raziometrico
					case 4:
						inputlevel[k] = (v1analoginputlevel / 4095.0) * 100.0;
						break;

					default:
						break;
					}

					if(inputlevel[k]<25.0)
					{
						inputlevel[k]=0;
					}
					else if(inputlevel[k]>75.0)
					{
						inputlevel[k]=100;
					}
				}

				//Caso solo B - Nessun pulsante mappato su A
				else if (v1valid==0 && v2valid==1) {
					switch (analoginmode[(inoutmap[k][1] - 25)]) {
						//0-5V
					case 1:
						inputlevel[k] = -(v2analoginputlevel / 1800.0)* 100.0;
						break;

						//0-10V
					case 2:
						inputlevel[k] = -(v2analoginputlevel / 3610.0) * 100.0;
						break;

						//4-20mA
					case 3:
						inputlevel[k] = -(v2analoginputlevel / 1720.0) * 100.0;
						break;

						//Raziometrico
					case 4:
						inputlevel[k] = -(v2analoginputlevel / 4095.0) * 100.0;
						break;

					default:
						break;
					}

					if(inputlevel[k]>-25.0)
					{
						inputlevel[k]=0;
					}
					else if(inputlevel[k]<-75.0)
					{
						inputlevel[k]=-100;
					}
				}
				else if(v1valid==1 && v2valid==1)
				{
					switch (analoginmode[(inoutmap[k][0] - 25)]) {
						//0-5V
					case 1:
						v1tmppercentage = (v1analoginputlevel / 1800.0)* 100.0;
						break;

						//0-10V
					case 2:
						v1tmppercentage = (v1analoginputlevel / 3610.0) * 100.0;
						break;

						//4-20mA
					case 3:
						v1tmppercentage = (v1analoginputlevel / 1720.0) * 100.0;
						break;

						//Raziometrico
					case 4:
						v1tmppercentage = (v1analoginputlevel / 4095.0) * 100.0;
						break;

					default:
						break;
					}

					if(v1tmppercentage<25.0)
					{
						v1tmppercentage=0;
					}
					else if(v1tmppercentage>75.0)
					{
						v1tmppercentage=100;
					}

					switch (analoginmode[(inoutmap[k][1] - 25)]) {
						//0-5V
					case 1:
						v2tmppercentage = -(v2analoginputlevel / 1800.0)* 100.0;
						break;

						//0-10V
					case 2:
						v2tmppercentage = -(v2analoginputlevel / 3610.0) * 100.0;
						break;

						//4-20mA
					case 3:
						v2tmppercentage = -(v2analoginputlevel / 1720.0) * 100.0;
						break;

						//Raziometrico
					case 4:
						v2tmppercentage = -(v2analoginputlevel / 4095.0) * 100.0;
						break;

					default:
						break;
					}

					if(v2tmppercentage>-25.0)
					{
						v2tmppercentage=0;
					}
					else if(v2tmppercentage<-75.0)
					{
						v2tmppercentage=-100;
					}

					if(v1tmppercentage==100 && v2tmppercentage==0)
					{
						inputlevel[k]=v1tmppercentage;
					}
					else if(v1tmppercentage==0 && v2tmppercentage==-100)
					{
						inputlevel[k]=v2tmppercentage;
					}
					else
					{
						inputlevel[k]=0;
					}
				}

					//Inserire Caso Gestione Flottante
				}

				if(inputlevel[k]>100)
				{
					inputlevel[k]=100;
				}

				if(inputlevel[k]<-100)
				{
					inputlevel[k]=-100;
				}
			}
		}

		// Clear the channel event
		ADCCH001_ClearResultEvtFlag(&ADCCH001_Handle10);
		ADCCH001_ClearResultEvtFlag(&ADCCH001_Handle11);
		ADCCH001_ClearResultEvtFlag(&ADCCH001_Handle12);
		ADCCH001_ClearResultEvtFlag(&ADCCH001_Handle13);
		ADCCH001_ClearResultEvtFlag(&ADCCH001_Handle14);
		ADCCH001_ClearResultEvtFlag(&ADCCH001_Handle2);

		ADCCH001_ClearResultEvtFlag(&ADCCH001_Handle15);
		ADCCH001_ClearResultEvtFlag(&ADCCH001_Handle16);
		ADCCH001_ClearResultEvtFlag(&ADCCH001_Handle17);
		ADCCH001_ClearResultEvtFlag(&ADCCH001_Handle18);
		ADCCH001_ClearResultEvtFlag(&ADCCH001_Handle19);
		ADCCH001_ClearResultEvtFlag(&ADCCH001_Handle3);
	}

	if(digitalinenable==1)
	{
		//Leggo In1 Digitale
		digitalinstatus[0]=IO004_ReadPin(IO004_Handle16);
		//Leggo In2 Digitale
		digitalinstatus[1]=IO004_ReadPin(IO004_Handle17);
		//Leggo In3 Digitale
		digitalinstatus[2]=IO004_ReadPin(IO004_Handle18);
		//Leggo In4 Digitale
		digitalinstatus[3]=IO004_ReadPin(IO004_Handle19);
		//Leggo In5 Digitale
		digitalinstatus[4]=IO004_ReadPin(IO004_Handle20);
		//Leggo In6 Digitale
		digitalinstatus[5]=IO004_ReadPin(IO004_Handle21);
		//Leggo In7 Digitale
		digitalinstatus[6]=IO004_ReadPin(IO004_Handle22);
		//Leggo In8 Digitale
		digitalinstatus[7]=IO004_ReadPin(IO004_Handle23);
		//Leggo In9 Digitale
		digitalinstatus[8]=IO004_ReadPin(IO004_Handle24);
		//Leggo In10 Digitale
		digitalinstatus[9]=IO004_ReadPin(IO004_Handle25);
		//Leggo In11 Digitale
		digitalinstatus[10]=IO004_ReadPin(IO004_Handle26);
		//Leggo In12 Digitale
		digitalinstatus[11]=IO004_ReadPin(IO004_Handle27);
		//Leggo In13 Digitale
		digitalinstatus[12]=IO004_ReadPin(IO004_Handle28);
		//Leggo In14 Digitale
		digitalinstatus[13]=IO004_ReadPin(IO004_Handle29);
		//Leggo In15 Digitale
		digitalinstatus[14]=IO004_ReadPin(IO004_Handle30);
		//Leggo In16 Digitale
		digitalinstatus[15]=IO004_ReadPin(IO004_Handle31);
	}
}

void RefreshDiagnoHandler(void* Temp)
{
	if(startdiagno!=0 || stopdiagno==1)
	{
		if(diagnodem<11)
		{
			diagnodem++;
		}
		else
		{
			if(sendflag==0)
			{
				SetupDiagnoMsg();
				sentdata=0;
				while(sentdata<txlendiagno)
				{
					sentdata=sentdata+UART001_WriteDataBytes(&UART001_Handle0,&txbuf[sentdata],txlendiagno-sentdata);
				}
				diagnodem=0;
			}
		}
	}
}

void LSCURR1_2_Handler(void)
{
	IO004_ResetPin(IO004_Handle0);
	IO004_ResetPin(IO004_Handle1);
	PWMSP002_SetCompare(&PWMSP002_Handle0,3333,0);
	sectionstatus[0]=sectionstatus[0] | 0x02;
	//PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle0);
}

void LSCURR3_4_Handler(void)
{
	IO004_ResetPin(IO004_Handle2);
	IO004_ResetPin(IO004_Handle3);
	PWMSP002_SetCompare(&PWMSP002_Handle1,3333,0);
	sectionstatus[1]=sectionstatus[1] | 0x02;
}

void LSCURR5_6_Handler(void)
{
	IO004_ResetPin(IO004_Handle4);
	IO004_ResetPin(IO004_Handle5);
	PWMSP002_SetCompare(&PWMSP002_Handle2,3333,0);
	sectionstatus[2]=sectionstatus[2] | 0x02;
}

void LSCURR7_8_Handler(void)
{
	IO004_ResetPin(IO004_Handle6);
	IO004_ResetPin(IO004_Handle7);
	PWMSP002_SetCompare(&PWMSP002_Handle3,3333,0);
	sectionstatus[3]=sectionstatus[3] | 0x02;
}

void LSCURR9_10_Handler(void)
{
	IO004_ResetPin(IO004_Handle8);
	IO004_ResetPin(IO004_Handle9);
	PWMSP002_SetCompare(&PWMSP002_Handle4,3333,0);
	sectionstatus[4]=sectionstatus[4] | 0x02;
}

void LSCURR11_12_Handler(void)
{
	IO004_ResetPin(IO004_Handle10);
	IO004_ResetPin(IO004_Handle11);
	PWMSP002_SetCompare(&PWMSP002_Handle5,3333,0);
	sectionstatus[5]=sectionstatus[5] | 0x02;
}

void LSCURR13_14_Handler(void)
{
	IO004_ResetPin(IO004_Handle12);
	IO004_ResetPin(IO004_Handle13);
	PWMSP002_SetCompare(&PWMSP002_Handle6,3333,0);
	sectionstatus[6]=sectionstatus[6] | 0x02;
}

void LSCURR15_16_Handler(void)
{
	IO004_ResetPin(IO004_Handle14);
	IO004_ResetPin(IO004_Handle15);
	PWMSP002_SetCompare(&PWMSP002_Handle7,3333,0);
	sectionstatus[7]=sectionstatus[7] | 0x02;
}

void HSCURR1_2_Handler(void)
{
	uint32_t status;
	IO004_ResetPin(IO004_Handle0);
	IO004_ResetPin(IO004_Handle1);
	PWMSP002_SetCompare(&PWMSP002_Handle0,3333,0);
	sectionstatus[0]=sectionstatus[0] | 0x08;
	//Reads Status Flag
	status = RD_REG(ERU001_Handle0.ERURegs->EXICON[ERU001_Handle0.InputChannel],ERU_EXICON_FL_Msk , ERU_EXICON_FL_Pos);
	if(status) ERU001_ClearFlag(ERU001_Handle0);// Clears the Status Flag
}

void HSCURR3_4_Handler(void)
{
	uint32_t status;
	IO004_ResetPin(IO004_Handle2);
	IO004_ResetPin(IO004_Handle3);
	PWMSP002_SetCompare(&PWMSP002_Handle1,3333,0);
	sectionstatus[1]=sectionstatus[1] | 0x08;
	status = RD_REG(ERU001_Handle1.ERURegs->EXICON[ERU001_Handle1.InputChannel],ERU_EXICON_FL_Msk , ERU_EXICON_FL_Pos);
	if(status) ERU001_ClearFlag(ERU001_Handle1);// Clears the Status Flag
}

void HSCURR5_6_Handler(void)
{
	uint32_t status;
	IO004_ResetPin(IO004_Handle4);
	IO004_ResetPin(IO004_Handle5);
	PWMSP002_SetCompare(&PWMSP002_Handle2,3333,0);
	sectionstatus[2]=sectionstatus[2] | 0x08;
	status = RD_REG(ERU001_Handle2.ERURegs->EXICON[ERU001_Handle2.InputChannel],ERU_EXICON_FL_Msk , ERU_EXICON_FL_Pos);
	if(status) ERU001_ClearFlag(ERU001_Handle2);// Clears the Status Flag
}

void HSCURR7_8_Handler(void)
{
	uint32_t status;
	IO004_ResetPin(IO004_Handle6);
	IO004_ResetPin(IO004_Handle7);
	PWMSP002_SetCompare(&PWMSP002_Handle3,3333,0);
	sectionstatus[3]=sectionstatus[3] | 0x08;
	status = RD_REG(ERU001_Handle3.ERURegs->EXICON[ERU001_Handle3.InputChannel],ERU_EXICON_FL_Msk , ERU_EXICON_FL_Pos);
	if(status) ERU001_ClearFlag(ERU001_Handle3);// Clears the Status Flag
}

void HSCURR9_10_Handler(void)
{
	uint32_t status;
	IO004_ResetPin(IO004_Handle8);
	IO004_ResetPin(IO004_Handle9);
	PWMSP002_SetCompare(&PWMSP002_Handle4,3333,0);
	sectionstatus[4]=sectionstatus[4] | 0x08;
	status = RD_REG(ERU001_Handle4.ERURegs->EXICON[ERU001_Handle4.InputChannel],ERU_EXICON_FL_Msk , ERU_EXICON_FL_Pos);
	if(status) ERU001_ClearFlag(ERU001_Handle4);// Clears the Status Flag
}

void HSCURR11_12_Handler(void)
{
	uint32_t status;
	IO004_ResetPin(IO004_Handle10);
	IO004_ResetPin(IO004_Handle11);
	PWMSP002_SetCompare(&PWMSP002_Handle5,3333,0);
	sectionstatus[5]=sectionstatus[5] | 0x08;
	status = RD_REG(ERU001_Handle5.ERURegs->EXICON[ERU001_Handle5.InputChannel],ERU_EXICON_FL_Msk , ERU_EXICON_FL_Pos);
	if(status) ERU001_ClearFlag(ERU001_Handle5);// Clears the Status Flag
}

void HSCURR13_14_Handler(void)
{
	uint32_t status;
	IO004_ResetPin(IO004_Handle12);
	IO004_ResetPin(IO004_Handle13);
	PWMSP002_SetCompare(&PWMSP002_Handle6,3333,0);
	sectionstatus[6]=sectionstatus[6] | 0x08;
	status = RD_REG(ERU001_Handle6.ERURegs->EXICON[ERU001_Handle6.InputChannel],ERU_EXICON_FL_Msk , ERU_EXICON_FL_Pos);
	if(status) ERU001_ClearFlag(ERU001_Handle6);// Clears the Status Flag
}

void HSCURR15_16_Handler(void)
{
	uint32_t status;
	IO004_ResetPin(IO004_Handle14);
	IO004_ResetPin(IO004_Handle15);
	PWMSP002_SetCompare(&PWMSP002_Handle7,3333,0);
	sectionstatus[7]=sectionstatus[7] | 0x08;
	status = RD_REG(ERU001_Handle7.ERURegs->EXICON[ERU001_Handle7.InputChannel],ERU_EXICON_FL_Msk , ERU_EXICON_FL_Pos);
	if(status) ERU001_ClearFlag(ERU001_Handle7);// Clears the Status Flag
}




void XMC_VADC_GROUP_ChannelSetInputReference(const ADCCH001_HandleType* HandlePtr, const XMC_VADC_CHANNEL_REF_t ref)
{

  VADC_G_TypeDef* GroupPtr = HandlePtr->ADCGrPtr;


  /* reference input selection */
  WR_REG(GroupPtr->CHCTR[HandlePtr->kChannelNo],
              VADC_G_CHCTR_REFSEL_Msk,
              VADC_G_CHCTR_REFSEL_Pos,
              (uint32_t)ref
         );

}


