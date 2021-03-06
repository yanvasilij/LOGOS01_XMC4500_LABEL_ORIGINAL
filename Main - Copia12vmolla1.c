/*
 * Main.c
 *
 *  Created on: 23/lug/2013
 *      Author: manfre
 */

/*
 *
 Mappatura Canali in ingresso:

 1 - Valore Y CAN
 2 - Valore X CAN
 3 - PB1 CAN
 4 - PB2 CAN
 5 - PB3 CAN
 6 - PB4 CAN
 7 - PB5 CAN
 8 - ROLLER 1 CAN
 9 - ROLLER 2 CAN
 * */
#include <DAVE3.h>			//Declarations from DAVE3 Code Generation (includes SFR declaration)
#include "GPIO.h"

#define teststep 1

void CalcTarCurr(int secid);
void CalcTarPwm(int secid);
void CalcActPwm(int secid,uint32_t tmpcurr);
void SetActPwm(int secid);
void CalculateTxChecksum(uint8_t len);
uint16_t CalculateRxChecksum(void);

uint32_t Buffer[FLASH002_PAGE_SIZE/4];

uint8_t sendflag=0;
uint8_t sectionconf=0xFF;
uint8_t analoginmode[10];
uint8_t auxvolt;
uint8_t sectionname[8][8];
uint8_t analoginname[10][8];


uint8_t sectionstatus[8];

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
uint8_t inoutmap[8];
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
uint16_t maxctrlv1[8];
uint16_t minctrlv1[8];
uint16_t maxctrlv2[8];
uint16_t minctrlv2[8];
uint8_t configsec[8];
float piv1[8];
int16_t qiv1[8];
float piv2[8];
int16_t qiv2[8];

uint32_t slopeupipointsv1[3][8];
uint16_t slopeuptpointsv1[4][8];
float slopeupv1[4][8];

uint32_t slopedownipointsv1[3][8];
uint16_t slopedowntpointsv1[4][8];
float slopedownv1[4][8];

uint32_t slopeupipointsv2[3][8];
uint16_t slopeuptpointsv2[4][8];
float slopeupv2[4][8];

uint32_t slopedownipointsv2[3][8];
uint16_t slopedowntpointsv2[4][8];
float slopedownv2[4][8];

uint8_t inc=0;
uint8_t dec=0;
uint16_t sentdata=0;


int main(void)
{
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)
	int i;

	DAVE_Init();			// Initialization of DAVE Apps
	IO004_Init();

	P2_1_set_mode(INPUT);
	P2_1_set_hwsel(HW1);

	for(i=0;i<8;i++)
	{
		pwmtar[i]=3333;
		loopfreq[i]=10; // 10=100Hz
	}

	ditheractive[0]=1;
	//ditheractive[1]=1;
	ditheractive[2]=1;
	ditheractive[3]=1;

	ditherampl[0]=2;
	ditherampl[1]=2;
	ditherampl[2]=2;
	ditherampl[3]=2;

	piv1[0]=5;
	qiv1[0]=450;
	piv2[0]=5;
	qiv2[0]=450;

	piv1[1]=5;
	qiv1[1]=450;
	piv2[1]=5;
	qiv2[1]=450;

	piv1[2]=5;
	qiv1[2]=450;
	piv2[2]=5;
	qiv2[2]=450;

	piv1[3]=5;
	qiv1[3]=450;
	piv2[3]=5;
	qiv2[3]=450;

	piv1[4]=5;
	qiv1[4]=450;
	piv2[4]=5;
	qiv2[4]=450;

	slopeupipointsv1[0][1]=400/0.725;
	slopeupipointsv1[1][1]=550/0.725;
	slopeupipointsv1[2][1]=700/0.725;

	slopeupipointsv2[0][1]=400/0.725;
	slopeupipointsv2[1][1]=550/0.725;
	slopeupipointsv2[2][1]=700/0.725;

	slopedownipointsv1[0][1]=700/0.725;
	slopedownipointsv1[1][1]=550/0.725;
	slopedownipointsv1[2][1]=400/0.725;

	slopedownipointsv2[0][1]=700/0.725;
	slopedownipointsv2[1][1]=550/0.725;
	slopedownipointsv2[2][1]=400/0.725;

	slopeupipointsv1[0][3]=510/0.725;
	slopeupipointsv1[1][3]=610/0.725;
	slopeupipointsv1[2][3]=700/0.725;

	slopeupipointsv2[0][3]=510/0.725;
	slopeupipointsv2[1][3]=610/0.725;
	slopeupipointsv2[2][3]=700/0.725;

	slopedownipointsv1[0][3]=600/0.725;
	slopedownipointsv1[1][3]=500/0.725;
	slopedownipointsv1[2][3]=350/0.725;

	slopedownipointsv2[0][3]=600/0.725;
	slopedownipointsv2[1][3]=500/0.725;
	slopedownipointsv2[2][3]=350/0.725;

	configsec[1]=0x00;
	configsec[3]=0x00;

	slopeupv1[0][1]=10;
	slopeupv1[1][1]=2;
	slopeupv1[2][1]=2;
	slopeupv1[3][1]=10;

	slopeupv2[0][1]=10;
	slopeupv2[1][1]=2;
	slopeupv2[2][1]=2;
	slopeupv2[3][1]=10;

	slopedownv1[0][1]=-10;
	slopedownv1[1][1]=-2;
	slopedownv1[2][1]=-2;
	slopedownv1[3][1]=-10;

	slopedownv2[0][1]=-10;
	slopedownv2[1][1]=-2;
	slopedownv2[2][1]=-2;
	slopedownv2[3][1]=-10;

	slopeupv1[0][3]=30;
	slopeupv1[1][3]=1;
	slopeupv1[2][3]=10;
	slopeupv1[3][3]=20;

	slopeupv2[0][3]=30;
	slopeupv2[1][3]=1;
	slopeupv2[2][3]=10;
	slopeupv2[3][3]=20;

	slopedownv1[0][3]=-50;
	slopedownv1[1][3]=-30;
	slopedownv1[2][3]=-1;
	slopedownv1[3][3]=-30;

	slopedownv2[0][3]=-50;
	slopedownv2[1][3]=-30;
	slopedownv2[2][3]=-1;
	slopedownv2[3][3]=-30;

	inoutmap[0]=8;
	inoutmap[1]=1;
	inoutmap[2]=2;
	inoutmap[3]=9;

	inoutmap[4]=4;

	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle0);
	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle1);
	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle2);
	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle3);
	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle4);
	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle5);
	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle6);
	PWMSP002_ResetTrapFlag((PWMSP002_HandleType*)&PWMSP002_Handle7);

	PWMSP003_Start(&PWMSP003_Handle0);
	ADC002_InitializeQueue(&ADC002_Handle0);
	ADC002_InitializeQueue(&ADC002_Handle1);

	//WriteData2Flash();

	while(1)
	{
		if(sendflag==1)
		{
			sentdata=0;
			while(sentdata<txlen)
			{
				sentdata=sentdata+UART001_WriteDataBytes(&UART001_Handle0,&txbuf[sentdata],txlen-sentdata);
			}
			sendflag=0;
		}
	}
	return 0;
}

void RampV1(int secid)
{
	if(targcurr[secid]-acttargcurr[secid]>=0)
	{
		if(acttargcurr[secid]<=slopeupipointsv1[0][secid])
		{
			if(targcurr[secid]-acttargcurr[secid]>slopeupv1[0][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]+slopeupv1[0][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
		else if(acttargcurr[secid]<=slopeupipointsv1[1][secid])
		{
			if(targcurr[secid]-acttargcurr[secid]>slopeupv1[1][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]+slopeupv1[1][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
		else if(acttargcurr[secid]<=slopeupipointsv1[2][secid])
		{
			if(targcurr[secid]-acttargcurr[secid]>slopeupv1[2][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]+slopeupv1[2][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
		else
		{
			if(targcurr[secid]-acttargcurr[secid]>slopeupv1[3][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]+slopeupv1[3][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
	}
	else
	{
		if(acttargcurr[secid]>=slopedownipointsv1[0][secid])
		{
			if(targcurr[secid]-acttargcurr[secid]<slopedownv1[0][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]+slopedownv1[0][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
		else if(acttargcurr[secid]>=slopedownipointsv1[1][secid])
		{
			if(targcurr[secid]-acttargcurr[secid]<slopedownv1[1][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]+slopedownv1[1][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
		else if(acttargcurr[secid]>=slopedownipointsv1[2][secid])
		{
			if(targcurr[secid]-acttargcurr[secid]<slopedownv1[2][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]+slopedownv1[2][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
		else
		{
			if(targcurr[secid]-acttargcurr[secid]<slopedownv1[3][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]+slopedownv1[3][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
	}
}

void RampV2(int secid)
{
	if(acttargcurr[secid]-targcurr[secid]>=0)
	{
		if(abs(acttargcurr[secid])<=slopeupipointsv2[0][secid])
		{
			if(acttargcurr[secid]-targcurr[secid]>slopeupv2[0][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopeupv2[0][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
		else if(abs(acttargcurr[secid])<=slopeupipointsv2[1][secid])
		{
			if(acttargcurr[secid]-targcurr[secid]>slopeupv2[1][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopeupv2[1][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
		else if(abs(acttargcurr[secid])<=slopeupipointsv2[2][secid])
		{
			if(acttargcurr[secid]-targcurr[secid]>slopeupv2[2][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopeupv2[2][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
		else
		{
			if(acttargcurr[secid]-targcurr[secid]>slopeupv2[3][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopeupv2[3][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
	}
	else
	{
		if(abs(acttargcurr[secid])>=slopedownipointsv2[0][secid])
		{
			if(acttargcurr[secid]-targcurr[secid]<slopedownv2[0][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopedownv2[0][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
		else if(abs(acttargcurr[secid])>=slopedownipointsv2[1][secid])
		{
			if(acttargcurr[secid]-targcurr[secid]<slopedownv2[1][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopedownv2[1][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
		else if(abs(acttargcurr[secid])>=slopedownipointsv2[2][secid])
		{
			if(acttargcurr[secid]-targcurr[secid]<slopedownv2[2][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopedownv2[2][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
		else
		{
			if(acttargcurr[secid]-targcurr[secid]<slopedownv2[3][secid])
			{
				acttargcurr[secid]=acttargcurr[secid]-slopedownv2[3][secid];
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
	}
}

void CalcTarCurr(int secid)
{
	//Gestione V1
	if(inputlevel[secid]>0)
	{
		if(inputlevel[secid]<=minctrlv1[secid])
		{
			targcurr[secid]=0;
			acttargcurr[secid]=targcurr[secid];
		}
		else
		{
			targcurr[secid]=(inputlevel[secid]*piv1[secid])+qiv1[secid];
			targcurr[secid]=targcurr[secid]/0.725;

			if(configsec[secid] & 0x02) //Rampa su V1 abilitata
			{
				RampV1(secid);
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
	}
	//Gestione V2
	else if(inputlevel[secid]<0)
	{
		if(inputlevel[secid]>=-minctrlv2[secid])
		{
			targcurr[secid]=0;
			acttargcurr[secid]=targcurr[secid];
		}
		else
		{
			targcurr[secid]=(inputlevel[secid]*piv2[secid])-qiv2[secid];
			targcurr[secid]=targcurr[secid]/0.725;

			if(configsec[secid] & 0x04) //Rampa su V2 abilitata
			{
				RampV2(secid);
			}
			else
			{
				acttargcurr[secid]=targcurr[secid];
			}
		}
	}
	else
	{
		targcurr[secid]=0;
		acttargcurr[secid]=targcurr[secid];
		/*
		if(acttargcurr[secid]>0)
		{
			RampV1(secid);
		}
		else
		{
			RampV2(secid);
		}*/
	}
}

void CalcTarPwm(int secid)
{
	uint32_t deltacurr;

	CalcTarCurr(secid);

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

		if((pwmtar[secid]-(deltacurr/10)-1)>0)
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

			CalcTarPwm(secid);
			actpwm[secid]=pwmtar[secid];
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

void CAN_Basic_RX_Handler()
{
	uint8_t Data[8] = {0xAA,0x23,0x22,0xA5,0xBC,0xFF,0x45,0xAF};
	uint16_t X_Pos,Y_Pos;
	uint8_t PB1,PB2,PB3,PB4,PB5;
	int TmpData;
	int k;

	/* Check receive pending status */
	if(CAN001_GetMOFlagStatus(&CAN001_Handle0,1,RECEIVE_PENDING) == CAN_SET)
	{
		/* Clear flag status */
		CAN001_ClearMOFlagStatus(&CAN001_Handle0,1,RECEIVE_PENDING);
		/* Read the received Message object and stores in variable CanRecMsgObj */
		CAN001_ReadMsgObj(&CAN001_Handle0,&CanRecMsgObj,1);

		Data[0]=CanRecMsgObj.data[0];
		Data[1]=CanRecMsgObj.data[1];
		Data[2]=CanRecMsgObj.data[2];
		Data[3]=CanRecMsgObj.data[3];
		Data[4]=CanRecMsgObj.data[4];
		Data[5]=CanRecMsgObj.data[5];
		Data[6]=CanRecMsgObj.data[6];
		Data[7]=CanRecMsgObj.data[7];

		X_Pos=Data[1]*4+(Data[0]/64);
		Y_Pos=Data[3]*4+(Data[2]/64);

		PB1=((Data[5]&0xC0)>>6); //BIANCO
		PB2=((Data[5]&0x30)>>4); //VERDE
		PB3=((Data[5]&0x0C)>>2); //ROSSO
		PB4=(Data[5]&0x03);		 //Azzurro Basso
		PB5=((Data[6]&0xC0)>>6); //Azzurro Alto

		for(k=0;k<8;k++)
		{
			switch(inoutmap[k])
			{
				case(1):TmpData=Data[2];
						if(TmpData & 0x01)
						{
							inputlevel[k]=0;
						}
						else if(TmpData & 0x04)
						{
							inputlevel[k]=Y_Pos*100/1024;
						}
						else if(TmpData & 0x10)
						{
							inputlevel[k]=-Y_Pos*100/1024;
						}
						CalcTarCurr(k);
						break;

				case(2):TmpData=Data[0];
						if(TmpData & 0x01)
						{
							inputlevel[k]=0;
						}
						else if(TmpData & 0x04)
						{
							inputlevel[k]=X_Pos*100/1024;
						}
						else if(TmpData & 0x10)
						{
							inputlevel[k]=-X_Pos*100/1024;
						}

						CalcTarCurr(k);
						break;
				case(3):if(PB1)
						{

						}
						break;
				case(4):if(PB4)
						{
							inputlevel[k]=100;
						}
						else if(PB2)
						{
							inputlevel[k]=-100;
						}
						else
						{
							inputlevel[k]=0;
						}

						CalcTarCurr(k);
						break;
				case(5):
						break;
				case(6):
						break;
				case(7):
						break;
				default:
						break;
			}
		}
	}
	if(CAN001_GetNodeFlagStatus(&CAN001_Handle0,CAN001_ALERT_STATUS) == CAN_SET)
	{
		/* Clear the flag */
		CAN001_ClearNodeFlagStatus(&CAN001_Handle0,CAN001_ALERT_STATUS);
	}
}

void CAN_Extended_RX_Handler()
{
	uint8_t Data[8] = {0xAA,0x23,0x22,0xA5,0xBC,0xFF,0x45,0xAF};
	uint16_t Z_Pos,W_Pos;
	int TmpData;
	int k;

	if(CAN001_GetMOFlagStatus(&CAN001_Handle0,2,RECEIVE_PENDING) == CAN_SET)
	{
		CAN001_ClearMOFlagStatus(&CAN001_Handle0,2,RECEIVE_PENDING);
		CAN001_ReadMsgObj(&CAN001_Handle0,&CanExtRecMsgObj,2);

		Data[0]=CanExtRecMsgObj.data[0];
		Data[1]=CanExtRecMsgObj.data[1];
		Data[2]=CanExtRecMsgObj.data[2];
		Data[3]=CanExtRecMsgObj.data[3];
		Data[4]=CanExtRecMsgObj.data[4];
		Data[5]=CanExtRecMsgObj.data[5];
		Data[6]=CanExtRecMsgObj.data[6];

		Z_Pos=Data[1]*4+(Data[0]/64);
		W_Pos=Data[3]*4+(Data[2]/64);

		for(k=0;k<8;k++)
		{
			switch(inoutmap[k])
			{
				case(8):TmpData=Data[0];
						if(TmpData & 0x01)
						{
							inputlevel[k]=0;
						}
						else if(TmpData & 0x04)
						{
							inputlevel[k]=Z_Pos*100/1024;
						}
						else if(TmpData & 0x10)
						{
							inputlevel[k]=-Z_Pos*100/1024;
						}
						CalcTarCurr(k);
						break;

				case(9):TmpData=Data[2];
						if(TmpData & 0x01)
						{
							inputlevel[k]=0;
						}
						else if(TmpData & 0x04)
						{
							inputlevel[k]=W_Pos*100/1024;
						}
						else if(TmpData & 0x10)
						{
							inputlevel[k]=-W_Pos*100/1024;
						}

						CalcTarCurr(k);
						break;
			}
		}
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

	for(i=0;i<=len-2;i++)
	{
		calccksum=calccksum+txbuf[i];
	}

	txbuf[len-2]=calccksum/256;
	txbuf[len-1]=calccksum%256;

}

/* Fifo standard receive buffer event handler */
void RxUartEventHandler()
{
    uint8_t DataRead;
    uint8_t TmpSecId;
    uint8_t i,k;

	if(UART001_GetFlagStatus(&UART001_Handle0,UART001_FIFO_STD_RECV_BUF_FLAG) == UART001_SET)
	{
		/* Read the received data to the buffer */
		DataRead=UART001_ReadDataBytes(&UART001_Handle0,&rxbuf[rxindex],uartmsglen);
		uarttimeout=2;

		 if(uartmsglen==1 && rxindex==0)
		 {
			 switch(rxbuf[0]){
			 	 case 1: uartmsglen=2;
			 		 	 break;
			 	 case 3: uartmsglen=2;
			 			 break;
			 	 case 4: uartmsglen=2;
			 			 break;
			 	 case 5: uartmsglen=158;
			 			 break;
			 	 case 6: uartmsglen=3;
			 			 break;
			 	 case 7: uartmsglen=58;
			 			 break;
			 	 default:
			 		 	 break;
			 }

		 }
		 else if(rxindex==uartmsglen)
		 {
			 if(CalculateRxChecksum()==(rxbuf[uartmsglen-1]*256+rxbuf[uartmsglen]))
			 {
				 switch(rxbuf[0])
				 {
				 	 //Risposta Start Diagno
				 	 case 1:startdiagno=1;
				 		 	txlen=4;
				 		 	txbuf[0]=0x01;
					 	    txbuf[1]=0x01;
					 	    CalculateTxChecksum(txlen);
					 	    sendflag=1;
					 	    //UART001_WriteDataBytes(&UART001_Handle0,&txbuf[0],txlen);
				 		 	break;
				 	 case 3:startdiagno=0;
				 	 	    txlen=4;
				 			txbuf[0]=0x03;
					 	 	txbuf[1]=0x01;
					 	 	CalculateTxChecksum(txlen);
					 	 	sendflag=1;
					 	 	//UART001_WriteDataBytes(&UART001_Handle0,&txbuf[0],txlen);
				 		 	break;
				 	 case 4:txlen=159;
				 	 	 	txbuf[0]=0x04;
				 	 	 	txbuf[1]=sectionconf;
				 	 	 	for(i=0;i<10;i++)
				 	 	 	{
				 	 	 		txbuf[2+i]=analoginmode[i];
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
				 	 	 	sendflag=1;
				 	 	 	/*sentdata=0;
				 	 	 	while(sentdata<txlen)
				 	 	 	{
				 	 	 		sentdata=sentdata+UART001_WriteDataBytes(&UART001_Handle0,&txbuf[sentdata],txlen-sentdata);
				 	 	 	}*/
				 	 	 	break;
				 	 case 5:
				 		 	sectionconf=rxbuf[1];
				 		 	for(i=0;i<10;i++)
				 		 	{
				 		 		analoginmode[i]=rxbuf[2+i];
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

				 		 	txlen=4;
				 			txbuf[0]=0x05;
					 	 	txbuf[1]=0x01;
					 	 	CalculateTxChecksum(txlen);
					 	 	sendflag=1;
				 		 	break;

				 	 case 6:TmpSecId=rxbuf[1];
				 	 	 	txlen=59;
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

				 	 	 	txbuf[11]=slopeupipointsv1[0][TmpSecId]/256;
				 	 	 	txbuf[12]=slopeupipointsv1[0][TmpSecId]%256;

				 	 	 	txbuf[13]=slopeupipointsv1[1][TmpSecId]/256;
				 	 	 	txbuf[14]=slopeupipointsv1[1][TmpSecId]%256;

				 	 	 	txbuf[15]=slopeupipointsv1[2][TmpSecId]/256;
				 	 	 	txbuf[16]=slopeupipointsv1[2][TmpSecId]%256;

				 	 	 	txbuf[17]=slopeuptpointsv1[0][TmpSecId];
				 	 	 	txbuf[18]=slopeuptpointsv1[1][TmpSecId];
				 	 	 	txbuf[19]=slopeuptpointsv1[2][TmpSecId];
				 	 	 	txbuf[20]=slopeuptpointsv1[3][TmpSecId];

				 	 	 	txbuf[21]=slopedownipointsv1[0][TmpSecId]/256;
				 	 	 	txbuf[22]=slopedownipointsv1[0][TmpSecId]%256;

				 	 	 	txbuf[23]=slopedownipointsv1[1][TmpSecId]/256;
				 	 	 	txbuf[24]=slopedownipointsv1[1][TmpSecId]%256;

				 	 	 	txbuf[25]=slopedownipointsv1[2][TmpSecId]/256;
				 	 	 	txbuf[26]=slopedownipointsv1[2][TmpSecId]%256;

				 	 	 	txbuf[27]=slopedowntpointsv1[0][TmpSecId];
				 	 	 	txbuf[28]=slopedowntpointsv1[1][TmpSecId];
				 	 	 	txbuf[29]=slopedowntpointsv1[2][TmpSecId];
				 	 	 	txbuf[30]=slopedowntpointsv1[3][TmpSecId];

				 	 	 	txbuf[31]=imaxv2[TmpSecId]/256;
				 	 	 	txbuf[32]=imaxv2[TmpSecId]%256;

				 	 	 	txbuf[33]=iminv2[TmpSecId]/256;
				 	 	 	txbuf[34]=iminv2[TmpSecId]%256;

				 	 	 	txbuf[35]=maxctrlv2[TmpSecId];
				 	 	 	txbuf[36]=minctrlv2[TmpSecId];

				 	 	 	txbuf[37]=slopeupipointsv2[0][TmpSecId]/256;
				 	 	 	txbuf[38]=slopeupipointsv2[0][TmpSecId]%256;

				 	 	 	txbuf[39]=slopeupipointsv2[1][TmpSecId]/256;
				 	 	 	txbuf[40]=slopeupipointsv2[1][TmpSecId]%256;

				 	 	 	txbuf[41]=slopeupipointsv2[2][TmpSecId]/256;
				 	 	 	txbuf[42]=slopeupipointsv2[2][TmpSecId]%256;

				 	 	 	txbuf[43]=slopeuptpointsv2[0][TmpSecId];
				 	 	 	txbuf[44]=slopeuptpointsv2[1][TmpSecId];
				 	 	 	txbuf[45]=slopeuptpointsv2[2][TmpSecId];
				 	 	 	txbuf[46]=slopeuptpointsv2[3][TmpSecId];

				 	 	 	txbuf[47]=slopedownipointsv2[0][TmpSecId]/256;
				 	 	 	txbuf[48]=slopedownipointsv2[0][TmpSecId]%256;

				 	 	 	txbuf[49]=slopedownipointsv2[1][TmpSecId]/256;
				 	 	 	txbuf[50]=slopedownipointsv2[1][TmpSecId]%256;

				 	 	 	txbuf[51]=slopedownipointsv2[2][TmpSecId]/256;
				 	 	 	txbuf[52]=slopedownipointsv2[2][TmpSecId]%256;

				 	 	 	txbuf[53]=slopedowntpointsv2[0][TmpSecId];
				 	 	 	txbuf[54]=slopedowntpointsv2[1][TmpSecId];
				 	 	 	txbuf[55]=slopedowntpointsv2[2][TmpSecId];
				 	 	 	txbuf[56]=slopedowntpointsv2[3][TmpSecId];

				 	 	 	CalculateTxChecksum(txlen);
				 	 	 	sendflag=1;
				 	 	 	/*sentdata=0;
				 	 	 	while(sentdata<txlen)
				 	 	 	{
				 	 	 		sentdata=sentdata+UART001_WriteDataBytes(&UART001_Handle0,&txbuf[sentdata],txlen-sentdata);
				 	 	 	}*/
				 		 	break;

				 	 case 7:TmpSecId=rxbuf[1];

				 	 	 	loopfreq[TmpSecId]=rxbuf[2];
				 	 	 	ditherampl[TmpSecId]=rxbuf[3];
				 	 	 	configsec[TmpSecId]=rxbuf[4];

				 	 	 	imaxv1[TmpSecId]=rxbuf[5]*256+rxbuf[6];
				 		 	iminv1[TmpSecId]=rxbuf[7]*256+rxbuf[8];
				 		 	maxctrlv1[TmpSecId]=rxbuf[9];
				 		 	minctrlv1[TmpSecId]=rxbuf[10];

				 		 	slopeupipointsv1[0][TmpSecId]=rxbuf[11]*256+rxbuf[12];
				 		 	slopeupipointsv1[1][TmpSecId]=rxbuf[13]*256+rxbuf[14];
				 		 	slopeupipointsv1[2][TmpSecId]=rxbuf[15]*256+rxbuf[16];

				 		 	slopeuptpointsv1[0][TmpSecId]=rxbuf[17];
				 		 	slopeuptpointsv1[1][TmpSecId]=rxbuf[18];
				 		 	slopeuptpointsv1[2][TmpSecId]=rxbuf[19];
				 		 	slopeuptpointsv1[3][TmpSecId]=rxbuf[20];

				 		 	slopedownipointsv1[0][TmpSecId]=rxbuf[21]*256+rxbuf[22];
				 		 	slopedownipointsv1[1][TmpSecId]=rxbuf[23]*256+rxbuf[24];
				 		 	slopedownipointsv1[2][TmpSecId]=rxbuf[25]*256+rxbuf[26];

				 		 	slopedowntpointsv1[0][TmpSecId]=rxbuf[27];
				 		 	slopedowntpointsv1[1][TmpSecId]=rxbuf[28];
				 		 	slopedowntpointsv1[2][TmpSecId]=rxbuf[29];
				 		 	slopedowntpointsv1[3][TmpSecId]=rxbuf[30];

				 		 	imaxv2[TmpSecId]=rxbuf[31]*256+rxbuf[32];
				 		 	iminv2[TmpSecId]=rxbuf[33]*256+rxbuf[34];
				 		 	maxctrlv2[TmpSecId]=rxbuf[35];
				 		 	minctrlv2[TmpSecId]=rxbuf[36];

				 		 	slopeupipointsv2[0][TmpSecId]=rxbuf[37]*256+rxbuf[38];
				 		 	slopeupipointsv2[1][TmpSecId]=rxbuf[39]*256+rxbuf[40];
				 		 	slopeupipointsv2[2][TmpSecId]=rxbuf[41]*256+rxbuf[42];

				 		 	slopeuptpointsv2[0][TmpSecId]=rxbuf[43];
				 		 	slopeuptpointsv2[1][TmpSecId]=rxbuf[44];
				 		 	slopeuptpointsv2[2][TmpSecId]=rxbuf[45];
				 		 	slopeuptpointsv2[3][TmpSecId]=rxbuf[46];

				 		 	slopedownipointsv2[0][TmpSecId]=rxbuf[47]*256+rxbuf[48];
				 		 	slopedownipointsv2[1][TmpSecId]=rxbuf[49]*256+rxbuf[50];
				 		 	slopedownipointsv2[2][TmpSecId]=rxbuf[51]*256+rxbuf[52];

				 		 	slopedowntpointsv2[0][TmpSecId]=rxbuf[53];
				 		 	slopedowntpointsv2[1][TmpSecId]=rxbuf[54];
				 		 	slopedowntpointsv2[2][TmpSecId]=rxbuf[55];
				 		 	slopedowntpointsv2[3][TmpSecId]=rxbuf[56];

				 		 	piv1[TmpSecId]=(imaxv1[TmpSecId]-iminv1[TmpSecId])/(maxctrlv1[TmpSecId]-minctrlv1[TmpSecId]);
				 		 	piv2[TmpSecId]=(imaxv2[TmpSecId]-iminv2[TmpSecId])/(maxctrlv2[TmpSecId]-minctrlv2[TmpSecId]);
				 		 	qiv1[TmpSecId]=-piv1[TmpSecId]*minctrlv1[TmpSecId];
				 		 	qiv2[TmpSecId]=-piv2[TmpSecId]*minctrlv2[TmpSecId];

				 		 	txlen=4;
				 		 	txbuf[0]=0x07;
				 		 	txbuf[1]=0x01;
				 		 	CalculateTxChecksum(txlen);
				 		 	sendflag=1;
				 		 	//UART001_WriteDataBytes(&UART001_Handle0,&txbuf[0],txlen);
				 		    break;
				 	 default:
				 		 	break;
				 }
			 }
		 }
		 rxindex=rxindex+DataRead;
		UART001_ClearFlag(&UART001_Handle0,UART001_FIFO_STD_RECV_BUF_FLAG);
	}
	else
	{
		UART001_ClearFlag(&UART001_Handle0,UART001_FIFO_STD_RECV_BUF_FLAG);
	}
}

void ADC0_CH0_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;
	uint32_t tmpcurr=0;

	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr=tmpcurr+(uint32_t)ADC0_CH0_BUFFER[k];
	}

	tmpcurr=tmpcurr/400;

	CalcActPwm(2,tmpcurr);


	DMA003_ReloadUserConfiguration(&DMA003_Handle1);
	DMA003_StartTransfer(&DMA003_Handle1);

	//IO004_ResetPin(IO004_Handle45);

}


void ADC0_CH5_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;
	uint32_t tmpcurr=0;

	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr=tmpcurr+(uint32_t)ADC0_CH5_BUFFER[k];
	}

	tmpcurr=tmpcurr/400;

	CalcActPwm(0,tmpcurr);

	DMA003_ReloadUserConfiguration(&DMA003_Handle2);
	DMA003_StartTransfer(&DMA003_Handle2);

	//IO004_ResetPin(IO004_Handle45);
}

void ADC0_CH4_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;
	uint32_t tmpcurr=0;

	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr=tmpcurr+(uint32_t)ADC0_CH4_BUFFER[k];
	}

	tmpcurr=tmpcurr/400;

	CalcActPwm(1,tmpcurr);

	DMA003_ReloadUserConfiguration(&DMA003_Handle3);
	DMA003_StartTransfer(&DMA003_Handle3);

	//IO004_ResetPin(IO004_Handle45);
}

void ADC0_CH6_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;
	uint32_t tmpcurr=0;
	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr=tmpcurr+(uint32_t)ADC0_CH6_BUFFER[k];
	}

	tmpcurr=tmpcurr/400;

	CalcActPwm(3,tmpcurr);

	DMA003_ReloadUserConfiguration(&DMA003_Handle4);
	DMA003_StartTransfer(&DMA003_Handle4);

	//IO004_ResetPin(IO004_Handle45);
}

void ADC1_CH1_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;
	uint32_t tmpcurr=0;

	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr=tmpcurr+(uint32_t)ADC1_CH1_BUFFER[k];
	}

	tmpcurr=tmpcurr/400;

	CalcActPwm(6,tmpcurr);

	DMA003_ReloadUserConfiguration(&DMA003_Handle9);
	DMA003_StartTransfer(&DMA003_Handle9);

	//IO004_ResetPin(IO004_Handle45);

}

void ADC1_CH7_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;
	uint32_t tmpcurr=0;

	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr=tmpcurr+(uint32_t)ADC1_CH7_BUFFER[k];
	}

	tmpcurr=tmpcurr/400;

	CalcActPwm(5,tmpcurr);

	DMA003_ReloadUserConfiguration(&DMA003_Handle10);
	DMA003_StartTransfer(&DMA003_Handle10);

	//IO004_ResetPin(IO004_Handle45);
}

void ADC1_CH8_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;
	uint32_t tmpcurr=0;

	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr=tmpcurr+(uint32_t)ADC1_CH8_BUFFER[k];
	}

	tmpcurr=tmpcurr/400;

	CalcActPwm(4,tmpcurr);

	DMA003_ReloadUserConfiguration(&DMA003_Handle11);
	DMA003_StartTransfer(&DMA003_Handle11);

	//IO004_ResetPin(IO004_Handle45);
}

void ADC1_CH9_Conv(DMA_IRQType IRQType,uint32_t CbArg)
{
	uint8_t k;
	uint32_t tmpcurr=0;

	//IO004_SetPin(IO004_Handle45);

	for(k=0;k<100;k++)
	{
		tmpcurr=tmpcurr+(uint32_t)ADC1_CH9_BUFFER[k];
	}

	tmpcurr=tmpcurr/400;

	CalcActPwm(7,tmpcurr);

	DMA003_ReloadUserConfiguration(&DMA003_Handle12);
	DMA003_StartTransfer(&DMA003_Handle12);

	//IO004_ResetPin(IO004_Handle45);
}

void SetupDiagnoMsg(void)
{
	int32_t diagnocurr;

	if(diagnoindex>=0 && diagnoindex<=7)
	{
		txbuf[0]=0x02;
		txbuf[1]=diagnoindex;

		if(sectionconf & (1 << diagnoindex))
		{
			diagnocurr=actualcurr[diagnoindex]*0.725;
			if(acttargcurr[diagnoindex]<0)
			{
				diagnocurr=-diagnocurr;
			}
			txbuf[2]=diagnocurr/256;
			txbuf[3]=diagnocurr%256;
		}
		else
		{
			//Stato Ingressi
		}

		txbuf[4]=sectionstatus[diagnoindex];
		txlendiagno=7;
		CalculateTxChecksum(txlendiagno);
	}
	else if(diagnoindex==8)
	{
		txbuf[0]=0x09;
		txbuf[1]=0x80; //Mettere valore di temperatura;
		txlendiagno=4;
		CalculateTxChecksum(txlendiagno);
	}
	else if(diagnoindex==9)
	{
		txbuf[0]=0x0A;
		txbuf[1]=0x00; //Mettere valore di Stato Generale;
		txlendiagno=4;
		CalculateTxChecksum(txlendiagno);
	}
	else if(diagnoindex>=10 && diagnoindex<=11)
	{
		txbuf[0]=0x0B;
		if(diagnoindex==10)
		{
			txbuf[1]=0x00;

			txbuf[2]=0x01; //Valore analogico High-Byte Input 1
			txbuf[3]=0x00; //Valore analogico Low-Byte  Input 1

			txbuf[4]=0x01; //Valore analogico High-Byte Input 2
			txbuf[5]=0x00; //Valore analogico Low-Byte  Input 2

			txbuf[6]=0x01; //Valore analogico High-Byte Input 3
			txbuf[7]=0x00; //Valore analogico Low-Byte  Input 3

			txbuf[8]=0x01; //Valore analogico High-Byte Input 4
			txbuf[9]=0x00; //Valore analogico Low-Byte  Input 4

			txbuf[10]=0x01; //Valore analogico High-ByteInput 5
			txbuf[11]=0x00; //Valore analogico Low-Byte Input 5

		}
		else if(diagnoindex==11)
		{
			txbuf[1]=0x01;

			txbuf[2]=0x01; //Valore analogico High-Byte Input 6
			txbuf[3]=0x00; //Valore analogico Low-Byte  Input 6

			txbuf[4]=0x01; //Valore analogico High-Byte Input 7
			txbuf[5]=0x00; //Valore analogico Low-Byte  Input 7

			txbuf[6]=0x01; //Valore analogico High-Byte Input 8
			txbuf[7]=0x00; //Valore analogico Low-Byte  Input 8

			txbuf[8]=0x01; //Valore analogico High-Byte Input 9
			txbuf[9]=0x00; //Valore analogico Low-Byte  Input 9

			txbuf[10]=0x01; //Valore analogico High-ByteInput 10
			txbuf[11]=0x00; //Valore analogico Low-Byte Input 10
		}

		txlendiagno=14;
		CalculateTxChecksum(txlendiagno);
	}
}

void MAIN_CLOCK_HANDLER(void)
{
	if(uarttimeout>0)
	{
		uarttimeout--;
		if(uarttimeout==0)
		{
			rxindex=0;
			uartmsglen=1;
		}
	}
	if(startdiagno==1)
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
				UART001_WriteDataBytes(&UART001_Handle0,&txbuf[0],txlendiagno);
				diagnodem=0;
				if(diagnoindex<12)
				{
					diagnoindex++;
				}
				else
				{
					diagnoindex=0;
				}
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
