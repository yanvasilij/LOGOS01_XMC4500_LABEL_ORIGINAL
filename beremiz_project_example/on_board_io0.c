/**********************************************************************************
			Generated code for input/outputs elaboration
**********************************************************************************/
#include <string.h>
#include <iec_std_lib.h>
#include <plc_abi.h>
/**********************************************************************************
			Location pointers
**********************************************************************************/
//analog inputs
float *__QD0_0_0;
float *__QD0_0_1;
float *__QD0_0_2;
float *__QD0_0_3;
float *__QD0_0_4;
float *__QD0_0_5;
float *__QD0_0_6;
float *__QD0_0_7;
float *__QD0_0_8;
float *__QD0_0_9;
//joystick 1 position
float * __QD0_1_0;
float * __QD0_1_1;
float * __QD0_1_2;
float * __QD0_1_3;
float * __QD0_1_4;
//PBx_PB1
float * __QD0_2_0;
float * __QD0_2_1;
float * __QD0_2_2;
float * __QD0_2_3;
float * __QD0_2_4;
float * __QD0_2_5;
float * __QD0_2_6;
float * __QD0_2_7;
float * __QD0_2_8;
float * __QD0_2_9;
//joystick 2 position
float * __QD0_3_0;
float * __QD0_3_1;
float * __QD0_3_2;
float * __QD0_3_3;
float * __QD0_3_4;
//PBx_PB2
float * __QD0_4_0;
float * __QD0_4_1;
float * __QD0_4_2;
float * __QD0_4_3;
float * __QD0_4_4;
float * __QD0_4_5;
float * __QD0_4_6;
float * __QD0_4_7;
float * __QD0_4_8;
float * __QD0_4_9;
//Analog outputs
float * __QD0_5_0;
float * __QD0_5_1;
float * __QD0_5_2;
float * __QD0_5_3;
float * __QD0_5_4;
float * __QD0_5_5;
float * __QD0_5_6;
float * __QD0_5_7;
//configuration structure
/**********************************************************************************
			Location pointers init function
**********************************************************************************/
void on_board_io_init (plc_variables_t * variables, plc_configuration_t * configuration )
{
	//analog inputs
	__QD0_0_0 = &variables->inputlevel[0];
	__QD0_0_1 = &variables->inputlevel[1];
	__QD0_0_2 = &variables->inputlevel[2];
	__QD0_0_3 = &variables->inputlevel[3];
	__QD0_0_4 = &variables->inputlevel[4];
	__QD0_0_5 = &variables->inputlevel[5];
	__QD0_0_6 = &variables->inputlevel[6];
	__QD0_0_7 = &variables->inputlevel[7];
	__QD0_0_8 = &variables->inputlevel[8];
	__QD0_0_9 = &variables->inputlevel[9];
	//joystick 1 position
	//position for CAN1
	__QD0_1_0 = variables->can1.X_Pos;
	__QD0_1_1 = variables->can1.Y_Pos;
	__QD0_1_2 = variables->can1.Z_Pos;
	__QD0_1_3 = variables->can1.W_Pos;
	__QD0_1_4 = variables->can1.V_Pos;
	__QD0_2_0 = variables->can1.pb1;
	__QD0_2_1 = variables->can1.pb2;
	__QD0_2_2 = variables->can1.pb3;
	__QD0_2_3 = variables->can1.pb4;
	__QD0_2_4 = variables->can1.pb5;
	__QD0_2_5 = variables->can1.pb6;
	__QD0_2_6 = variables->can1.pb7;
	__QD0_2_7 = variables->can1.pb8;
	__QD0_2_8 = variables->can1.pb9;
	__QD0_2_9 = variables->can1.pb10;
	//position for CAN2
	__QD0_3_0 = variables->can2.X_Pos;
	__QD0_3_1 = variables->can2.Y_Pos;
	__QD0_3_2 = variables->can2.Z_Pos;
	__QD0_3_3 = variables->can2.W_Pos;
	__QD0_3_4 = variables->can2.V_Pos;
	__QD0_4_0 = variables->can2.pb1;
	__QD0_4_1 = variables->can2.pb2;
	__QD0_4_2 = variables->can2.pb3;
	__QD0_4_3 = variables->can2.pb4;
	__QD0_4_4 = variables->can2.pb5;
	__QD0_4_5 = variables->can2.pb6;
	__QD0_4_6 = variables->can2.pb7;
	__QD0_4_7 = variables->can2.pb8;
	__QD0_4_8 = variables->can2.pb9;
	__QD0_4_9 = variables->can2.pb10;
	//analog outputs
	__QD0_5_0 = &variables->targcurr[0];
	__QD0_5_1 = &variables->targcurr[1];
	__QD0_5_2 = &variables->targcurr[2];
	__QD0_5_3 = &variables->targcurr[3];
	__QD0_5_4 = &variables->targcurr[4];
	__QD0_5_5 = &variables->targcurr[5];
	__QD0_5_6 = &variables->targcurr[6];
	__QD0_5_7 = &variables->targcurr[7];
	//Configuration 
	//analog inputs mode
	configuration->analoginmode[0] = 1;
	configuration->analoginmode[1] = 0;
	configuration->analoginmode[2] = 0;
	configuration->analoginmode[3] = 0;
	configuration->analoginmode[4] = 0;
	configuration->analoginmode[5] = 0;
	configuration->analoginmode[6] = 0;
	configuration->analoginmode[7] = 0;
	configuration->analoginmode[8] = 0;
	configuration->analoginmode[9] = 4;
	//pwm settings
	configuration->loopfreq[0] = 13;
	configuration->ditherampl[0] = 2;
	configuration->ditheractive[0] = 1;
	configuration->loopfreq[1] = 13;
	configuration->ditherampl[1] = 4;
	configuration->ditheractive[1] = 0;
	configuration->loopfreq[2] = 13;
	configuration->ditherampl[2] = 4;
	configuration->ditheractive[2] = 1;
	configuration->loopfreq[3] = 13;
	configuration->ditherampl[3] = 4;
	configuration->ditheractive[3] = 1;
	configuration->loopfreq[4] = 13;
	configuration->ditherampl[4] = 4;
	configuration->ditheractive[4] = 1;
	configuration->loopfreq[5] = 13;
	configuration->ditherampl[5] = 4;
	configuration->ditheractive[5] = 1;
	configuration->loopfreq[6] = 13;
	configuration->ditherampl[6] = 4;
	configuration->ditheractive[6] = 1;
	configuration->loopfreq[7] = 13;
	configuration->ditherampl[7] = 4;
	configuration->ditheractive[7] = 1;
	//section configuration 
	*configuration->sectionconf = 0;
	*configuration->sectionconf |= (0<<0);
	*configuration->sectionconf |= (1<<1);
	*configuration->sectionconf |= (0<<2);
	*configuration->sectionconf |= (0<<3);
	*configuration->sectionconf |= (0<<4);
	*configuration->sectionconf |= (0<<5);
	*configuration->sectionconf |= (0<<6);
	*configuration->sectionconf |= (0<<7);
	//Auxiliary Voltage Output
	*configuration->auxvolt = 1;
	//CAN output enable
	*configuration->can1DMenable = 1;
	*configuration->can2DMenable = 1;
}
/**********************************************************************************
			Publish and retrive
**********************************************************************************/
int __init_0(int argc,char **argv)
{
  return 0;
}

void __cleanup_0(void)
{

}

void __retrieve_0(void)
{

}

void __publish_0(void)
{


}

