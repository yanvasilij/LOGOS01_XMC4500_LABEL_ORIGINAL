/*******************************************************************************
**  DAVE App Name : NVIC002       App Version: 1.0.28               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/



/*CODE_BLOCK_BEGIN[NVIC002_Conf.h]*/
/**************************************************************************//**
 *
 * Copyright (C) 2014 Infineon Technologies AG. All rights reserved.
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
** PLATFORM : Infineon XMC4000/XMC1000 Series   			                  **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Jul 17, 2014                                           **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** SNR          App Developer                                                 **
*******************************************************************************/

/**
 * @file   NVIC002_Conf.h
 *
 * @App    Version NVIC002 <1.0.28>
 *
 * @brief  Configuration file generated based on UI settings 
 *         of NVIC002 App
 *
 */
/* Revision History	
 * 18  Feb 2013   v1.0.12 
 * 08  Oct 2013   v1.0.20 Updated as per coding guidelines
 * 17 Jul 2014   v1.0.28   End of line is corrected
 */
#ifndef _NVIC002_CONF_H_
#define _NVIC002_CONF_H_

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
@Defines
****************************************************************************/
#define DEBUG_APP false
  
/* User defined function mapped to IRQ_Hdlr_77 */
#define CAN_Basic_RX_Handler    IRQ_Hdlr_77 

/* User defined function mapped to IRQ_Hdlr_76 */
#define CAN_Extended_RX_Handler    IRQ_Hdlr_76 

/* User defined function mapped to IRQ_Hdlr_63 */
#define LSCURR1_2_Handler    IRQ_Hdlr_63 

/* User defined function mapped to IRQ_Hdlr_62 */
#define LSCURR3_4_Handler    IRQ_Hdlr_62 

/* User defined function mapped to IRQ_Hdlr_61 */
#define LSCURR5_6_Handler    IRQ_Hdlr_61 

/* User defined function mapped to IRQ_Hdlr_60 */
#define LSCURR7_8_Handler    IRQ_Hdlr_60 

/* User defined function mapped to IRQ_Hdlr_64 */
#define LSCURR9_10_Handler    IRQ_Hdlr_64 

/* User defined function mapped to IRQ_Hdlr_67 */
#define LSCURR11_12_Handler    IRQ_Hdlr_67 

/* User defined function mapped to IRQ_Hdlr_91 */
#define RxUartEventHandler    IRQ_Hdlr_91 

/* User defined function mapped to IRQ_Hdlr_66 */
#define LSCURR13_14_Handler    IRQ_Hdlr_66 

/* User defined function mapped to IRQ_Hdlr_65 */
#define LSCURR15_16_Handler    IRQ_Hdlr_65 

/* User defined function mapped to IRQ_Hdlr_5 */
#define HSCURR1_2_Handler    IRQ_Hdlr_5 

/* User defined function mapped to IRQ_Hdlr_8 */
#define HSCURR3_4_Handler    IRQ_Hdlr_8 

/* User defined function mapped to IRQ_Hdlr_4 */
#define HSCURR5_6_Handler    IRQ_Hdlr_4 

/* User defined function mapped to IRQ_Hdlr_3 */
#define HSCURR7_8_Handler    IRQ_Hdlr_3 

/* User defined function mapped to IRQ_Hdlr_7 */
#define HSCURR9_10_Handler    IRQ_Hdlr_7 

/* User defined function mapped to IRQ_Hdlr_6 */
#define HSCURR11_12_Handler    IRQ_Hdlr_6 

/* User defined function mapped to IRQ_Hdlr_1 */
#define HSCURR13_14_Handler    IRQ_Hdlr_1 

/* User defined function mapped to IRQ_Hdlr_2 */
#define HSCURR15_16_Handler    IRQ_Hdlr_2 

/* User defined function mapped to IRQ_Hdlr_90 */
#define Uart_Error_Handler    IRQ_Hdlr_90 


/**
 * @ingroup NVIC002_constants
 * @{
 */
#define NVIC002_NUM_INSTANCES 30U
/**
  * @}
  */
#ifdef __cplusplus
}
#endif

#endif  /* ifndef _NVIC002_CONF_H_ */
/*CODE_BLOCK_END*/