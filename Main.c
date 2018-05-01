/*
 * Main.c
 *
 *  Created on: 23/lug/2013
 *      Author: manfre
 *      !
 */


#include <DAVE3.h>			//Declarations from DAVE3 Code Generation (includes SFR declaration)
#include "GPIO.h"


#define teststep 1
#define sectionparamsize 63
#define boardconfigsize 156
#define pinmappingsize 48
#define checksumsize 1
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
void CalcTarPwm(int secid);
void CalcActPwm(int secid,uint32_t tmpcurr);
void SetActPwm(int secid);

void GetSPIData(char mode);
void SetupAnalogInputs(void);
void SetupAuxOutput(void);
void SetupCoeff(uint8_t SecId);
uint32_t flashslotsize=FLASH002_PAGE_SIZE/4;
float looptime=100;    //tempo di ciclo in ms
float ma_for_lev=0.725; // coefficiente ma/livelli adc
uint32_t flashchecksum=0;

void XMC_VADC_GROUP_ChannelSetInputReference(const ADCCH001_HandleType* HandlePtr, const XMC_VADC_CHANNEL_REF_t ref);

handle_t TimerId1,TimerId2;
uint8_t sectionrecoverydelaythr=11;
uint8_t sectionrecoverydelay[8];

uint8_t tmpmeasstarted=0;
uint8_t sectionconf=0xFF;
uint8_t analoginmode[10];
uint8_t analoginmodemem[10];
uint8_t auxvolt;

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

float piv1[8];
float piv2[8];

uint8_t inc=0;
uint8_t dec=0;
uint16_t sentdata=0;

uint32_t flash_status;

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

uint8_t SectionIndex=0;

uint8_t can1DMenable=0;
uint8_t can2DMenable=0;
uint8_t can1DMstatus=1;
uint8_t can2DMstatus=1;

int32_t diagnocurr=0;
uint8_t stopdiagno=0;
uint8_t ackstartdiagno=0;

#ifdef dbgvar4ramp
uint32_t dbgcnt[32];
#endif

int main(void)
{
    //	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)
    uint32_t i;

    DAVE_Init();			// Initialization of DAVE Apps
    IO004_Init();			// Setup Specific I/O

    P2_1_set_mode(INPUT);   // Setup Specific I/O
    P2_1_set_hwsel(HW1);    // Setup Specific I/O

    TMPS001_Enable();       // Enable Die temperature sensor

    PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle0); //Reset trap flag of PWM
    PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle1); //Reset trap flag of PWM
    PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle2); //Reset trap flag of PWM
    PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle3); //Reset trap flag of PWM

    PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle4); //Reset trap flag of PWM
    PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle5); //Reset trap flag of PWM
    PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle6); //Reset trap flag of PWM
    PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle7); //Reset trap flag of PWM


    TimerId1 = SYSTM001_CreateTimer(100,SYSTM001_PERIODIC,MAIN_CLOCK_HANDLER,NULL);  //Setup supervision operations clock, rate 100ms
    SYSTM001_StartTimer(TimerId1);

    SetupAuxOutput();    //Setup Aux Volt output value + CAN PORT 1 and 2 enable, to be refactored
    SetupAnalogInputs(); //Setup Analong input range

    //Start ADC Aux, used for Analog Inputs
    ADC002_InitializeQueue(&ADC002_Handle2);
    ADC002_InitializeQueue(&ADC002_Handle3);

    //Start ADC Current Feedback 1
    ADC002_InitializeQueue(&ADC002_Handle0);
    //Start ADC Current Feedback 2
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

	/* FIXME: Which ai and ao value should be pass to user application? */
	float ai[8];
	float ao[8];
	for (u8 i=0; i<8; i++)
	    ai[i] = (float)avgcurr[i];
	/* user application pollig*/
	poll_user_app(ai, ao);
    }
    return 0;
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
    else
    {
	can1DMenable=0;
    }

    if((auxvolt & 0x20) !=0)
    {
	can2DMenable=1;
    }
    else
    {
	can2DMenable=0;
    }
}




void CalcTarPwm(int secid)
{
    uint32_t deltacurr;

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


//Callback to handle basic J1939 message
void HandleCanMessageBasic(uint8_t Data[8], uint8_t port)
{

}

//Callback to handle extended J1939 message
void HandleCanMessageExtended(uint8_t Data[8], uint8_t port)
{

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


void Uart_Error_Handler()
{
    if(UART001_GetFlagStatus(&UART001_Handle0,UART001_FIFO_TRANSMIT_BUF_ERR_FLAG)==UART001_SET)
    {
	USIC_FlushTxFIFO(UART001_Handle0.UartRegs);
	UART001_ClearFlag(&UART001_Handle0,UART001_FIFO_TRANSMIT_BUF_ERR_FLAG);
    }
    else if(UART001_GetFlagStatus(&UART001_Handle0,UART001_FIFO_RECV_BUF_ERR_FLAG)==UART001_SET)
    {
	USIC_FlushRxFIFO(UART001_Handle0.UartRegs);
	UART001_ClearFlag(&UART001_Handle0,UART001_FIFO_STD_RECV_BUF_FLAG);
	UART001_ClearFlag(&UART001_Handle0,UART001_FIFO_RECV_BUF_ERR_FLAG);
	rxindex=0;
	uartmsglen=1;
    }
}

/* Fifo standard receive buffer event handler */
void RxUartEventHandler()
{
    uint8_t DataRead;

    if(UART001_GetFlagStatus(&UART001_Handle0,UART001_FIFO_STD_RECV_BUF_FLAG) == UART001_SET)
    {
	/* Read the received data to the buffer */
	DataRead=UART001_ReadDataBytes(&UART001_Handle0,&rxbuf[rxindex],uartmsglen);
	UART001_ClearFlag(&UART001_Handle0,UART001_FIFO_STD_RECV_BUF_FLAG);
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


void MAIN_CLOCK_HANDLER(void* Temp)
{
    uint8_t DataRead;
    uint8_t DummyDataBuf[32];

    int k=0;

    if(uarttimeout>0)
    {
	uarttimeout--;
	if(uarttimeout==0)
	{
	    USIC_FlushRxFIFO(UART001_Handle0.UartRegs);

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


	for (k = 0; k < 8; k++) {
	    switch (analoginmode[k]) {
		//0-5V
		case 1:
		    //inputlevel[k] = (v1analoginputlevel / 1800.0) * 100.0;
		    break;

		    //0-10V
		case 2:
		    //inputlevel[k] = (v1analoginputlevel / 3610.0) * 100.0;
		    break;

		    //4-20mA
		case 3:
		    //inputlevel[k] = (v1analoginputlevel / 1720.0) * 100.0;
		    break;

		    //Raziometrico
		case 4:
		    // inputlevel[k] = (v1analoginputlevel / 4095.0) * 100.0;
		    break;

		default:
		    break;
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

void UARTSendingExample()
{
    sentdata=sentdata+UART001_WriteDataBytes(&UART001_Handle0,&txbuf[sentdata],txlendiagno-sentdata);
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


