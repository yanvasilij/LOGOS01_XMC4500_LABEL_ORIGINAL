/*******************************************************************************
**  DAVE App Name : DMA003       App Version: 1.0.18               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/


/*CODE_BLOCK_BEGIN[DMA003_Conf.h]*/
/*******************************************************************************
**									                                          **
** Copyright (C) 2013 Infineon Technologies AG. All rights reserved.          **
**                                                                            **
** Infineon Technologies AG (Infineon) is supplying this software for use     **
** with Infineon's microcontrollers.					                      **
** This file can be freely distributed within development tools that are      **
** supporting such microcontrollers.                                          **
**                                                                            **
** THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS,        **
** IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES    **
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS      **
** SOFTWARE. INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, **
** INCIDENTAL, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.           **
**									                                          **     
********************************************************************************
**                                                                            **
** PLATFORM : Infineon XMC4000 Series                                         **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
********************************************************************************
** VERSION HISTORY:
********************************************************************************
** v1.0.11, 18 Jan 2013: Initial version.
** v1.0.16, 30 Sept 2013: Updated code for compliance with programming
**                        guidelines.
*******************************************************************************/

/**
 * @file   DMA003_Conf.h
 *
 * @brief  Configuration file generated based on UI settings 
 *         of DMA003 App
 *
 */

#ifndef _CONF_DMA003_H_
#define _CONF_DMA003_H_

/* Support for C++ */
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
**                      Include Files                                        **
******************************************************************************/
/*
 * external reference to user-defined
 * event handler: `ADC0_CH0_Conv'
 */ 
extern void ADC0_CH0_Conv(DMA_IRQType irq_type, uint32_t cb_arg);
/*
 * external reference to user-defined
 * event handler: `ADC1_CH7_Conv'
 */ 
extern void ADC1_CH7_Conv(DMA_IRQType irq_type, uint32_t cb_arg);
/*
 * external reference to user-defined
 * event handler: `ADC1_CH8_Conv'
 */ 
extern void ADC1_CH8_Conv(DMA_IRQType irq_type, uint32_t cb_arg);
/*
 * external reference to user-defined
 * event handler: `ADC1_CH9_Conv'
 */ 
extern void ADC1_CH9_Conv(DMA_IRQType irq_type, uint32_t cb_arg);
/*
 * external reference to user-defined
 * event handler: `ADC0_CH5_Conv'
 */ 
extern void ADC0_CH5_Conv(DMA_IRQType irq_type, uint32_t cb_arg);
/*
 * external reference to user-defined
 * event handler: `ADC0_CH4_Conv'
 */ 
extern void ADC0_CH4_Conv(DMA_IRQType irq_type, uint32_t cb_arg);
/*
 * external reference to user-defined
 * event handler: `ADC0_CH6_Conv'
 */ 
extern void ADC0_CH6_Conv(DMA_IRQType irq_type, uint32_t cb_arg);
/*
 * external reference to user-defined
 * event handler: `ADC1_CH1_Conv'
 */ 
extern void ADC1_CH1_Conv(DMA_IRQType irq_type, uint32_t cb_arg); 

/* Number of DMA003 instances. */
#define DMA003_NUM_INSTANCES 8U

/* Declare Handle array. This is used in the initialization function */
extern const DMA003_ChannelHandleType *DMA003_HandleArray[DMA003_NUM_INSTANCES];

/* Mapped DMA Channel BaseAddress for App Instance 1 */ 
#define DMA003_Handle1_CHANNEL  GPDMA1_CH2

/* Mapped DMA Channel BaseAddress for App Instance 10 */ 
#define DMA003_Handle10_CHANNEL  GPDMA0_CH1

/* Mapped DMA Channel BaseAddress for App Instance 11 */ 
#define DMA003_Handle11_CHANNEL  GPDMA0_CH5

/* Mapped DMA Channel BaseAddress for App Instance 12 */ 
#define DMA003_Handle12_CHANNEL  GPDMA0_CH4

/* Mapped DMA Channel BaseAddress for App Instance 2 */ 
#define DMA003_Handle2_CHANNEL  GPDMA1_CH3

/* Mapped DMA Channel BaseAddress for App Instance 3 */ 
#define DMA003_Handle3_CHANNEL  GPDMA1_CH1

/* Mapped DMA Channel BaseAddress for App Instance 4 */ 
#define DMA003_Handle4_CHANNEL  GPDMA1_CH0

/* Mapped DMA Channel BaseAddress for App Instance 9 */ 
#define DMA003_Handle9_CHANNEL  GPDMA0_CH0
 
  
/*****************************************************************************
              DUMMY DEFINTIONS OF DEBUG LOG MACROS
*****************************************************************************/
/*These definitions are included here to avoid compilation errors,
 since the DBG002 app is not part of the project. All the macros are defined
 as empty*/ 
#ifndef _DBG002_H_

#define DBG002_RegisterCallBack(A,B,C)
#define DBG002_I(e) 
#define DBG002_IG(e,g) 
#define DBG002_IH(e,h) 
#define DBG002_IP(e,p) 
#define DBG002_IGH(e,g,h) 
#define DBG002_IGP(e,g,p) 
#define DBG002_IHP(e,h,p) 
#define DBG002_IGHP(e,g,h,p) 
#define DBG002_N(e) 
#define DBG002_NG(e,g) 
#define DBG002_NH(e,h) 
#define DBG002_NP(e,p) 
#define DBG002_NGH(e,g,h) 
#define DBG002_NGP(e,g,p) 
#define DBG002_NHP(e,h,p) 
#define DBG002_NGHP(e,g,h,p) 
#define DBG002_ID(e) 
#define DBG002_IS(e) 
#define DBG002_ISG(e,g) 
#define DBG002_SAFETY_CRITICAL(groupid,messageid,length,value)
#define DBG002_CRITICAL(groupid,messageid,length,value)
#define DBG002_ERROR(groupid,messageid,length,value)
#define DBG002_WARNING(groupid,messageid,length,value)
#define DBG002_INFO(groupid,messageid,length,value)
#define DBG002_TRACE(groupid,messageid,length,value)
#define DBG002_FUNCTION_ENTRY(GID, Status) 
#define DBG002_FUNCTION_EXIT(GID, Status) 

#endif/* End of definitions of dummy Debug Log macros*/

/*******************************************************************************
** STRUCTURES:
*******************************************************************************/

/* Support for C++ */
#ifdef __cplusplus
}
#endif

#endif  /* ifndef _CONF_DMA003_H_*/

/*CODE_BLOCK_END*/
