/*******************************************************************************
**  DAVE App Name : DAVESupport       App Version: 1.0.44               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/


/**************************************************************************//**
 *
 * Copyright (C) 2011 Infineon Technologies AG. All rights reserved.
 *
 * Infineon Technologies AG (Infineon) is supplying this software for use with
 * Infineon's microcontrollers.
 * This file can be freely distributed within development tools that are
 * supporting such microcontrollers.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
********************************************************************************
**                                                                            **
**                                                                            **
** PLATFORM : Infineon <Microcontroller name, step>                           **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** MODIFICATION DATE : Jan 22, 2014                                          **
**                                                                            **
*******************************************************************************/

/**
 * @file  DAVE3.h
 *
 * @brief This file contains all public data structures,enums and function
 *        prototypes
 *
 * Revision History
 * 26 June 2013 v1.0.32 Initial Version.
 * 22 Jan  2014 v1.0.40 C++ macro inserted. 
 *
 */

#ifndef _DAVE3_H_
#define _DAVE3_H_

#ifdef __cplusplus
extern "C" {
#endif

//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void DAVE_Init(void);

void SystemInit_DAVE3(void);
      
//****************************************************************************
// @Project Includes
//****************************************************************************


#include <XMC4500.h>

#include "../../inc/LIBS/types.h"
	
#include "../../inc/DAVESupport/MULTIPLEXER.h"


// #include APP HEADER FILES.
	#include "../../inc/LIBS/LIBS.h" 
	#include "../../inc/DBG001/DBG001.h" 
	#include "../../inc/CLK001/CLK001.h" 
	#include "../../inc/RESET001/RESET001.h" 
	#include "../../inc/CCU8GLOBAL/CCU8GLOBAL.h" 
	#include "../../inc/PWMSP002/PWMSP002.h" 
	#include "../../inc/IO002/IO002.h" 
	#include "../../inc/ADCGLOB001/ADCGLOB001.h" 
	#include "../../inc/ADCGROUP001/ADCGROUP001.h" 
	#include "../../inc/IO001/IO001.h" 
	#include "../../inc/ADCCH001/ADCCH001.h" 
	#include "../../inc/ADC002/ADC002.h" 
	#include "../../inc/UART001/UART001.h" 
	#include "../../inc/CANGLOBAL/CANGLOBAL.h" 
	#include "../../inc/CAN001/CAN001.h" 
	#include "../../inc/ERU001/ERU001.h" 
	#include "../../inc/NVIC_SCU001/NVIC_SCU001.h" 
	#include "../../inc/RTC001/RTC001.h" 
	#include "../../inc/LMM001/LMM001.h" 
	#include "../../inc/GMM001/GMM001.h" 
	#include "../../inc/SLTHA003/SLTHA003.h" 
	#include "../../inc/SYSTM001/SYSTM001.h" 
	#include "../../inc/USBLD001/USBLD001.h" 
	#include "../../inc/USBCORE001/USBCORE001.h" 
	#include "../../inc/USBCDC001/USBCDC001.h" 
	#include "../../inc/USBVC001/USBVC001.h" 
	#include "../../inc/TMPS001/TMPS001.h" 
	#include "../../inc/IO004/IO004.h" 
	#include "../../inc/NVIC002/NVIC002.h" 
	#include "../../inc/NVIC_DMA001/NVIC_DMA001.h" 
	#include "../../inc/DMA003/DMA003.h" 
	#include "../../inc/ERU002/ERU002.h" 
	#include "../../inc/FLASH002/FLASH002.h" 
	#include "../../inc/SPI001/SPI001.h" 
	#include "../../inc/CCU4GLOBAL/CCU4GLOBAL.h" 
	#include "../../inc/CAP001/CAP001.h" 

                         

#ifdef __cplusplus
}
#endif

#endif  /** ifndef _DAVE3_H_ */

