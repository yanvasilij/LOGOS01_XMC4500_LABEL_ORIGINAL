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
** PLATFORM : Infineon XMC4XXX                                               **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Jan 18, 2013                                          **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** PAE        App Developer                                                   **
*******************************************************************************/

/**
 * @file NVIC_DMA001.h
 *
 * @brief  Header file for NVIC_DMA001 App.
 *
 */
/*
 * Revision History
 * 18 Jan 2013 v1.0.11 Initial version
 */

#ifndef NVIC_DMA001_H_
#define NVIC_DMA001_H_

#ifdef  __cplusplus
extern "C"
{
#endif

/******************************************************************************
**                      Include Files                                        **
******************************************************************************/

#include <DAVE3.h>
#ifndef DMA_TYPES_H_
#include "../../inc/NVIC_DMA001/DMA_Types.h"
#endif
/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/

/******************************************************************************
**                      Global Type Definitions                              **
******************************************************************************/
#define DMA0_MAX_CHANNELS 8U
#define DMA1_MAX_CHANNELS 4U

/**
 * @ingroup NVIC_DMA001_publicparam
 * @{
 */

/**
 * @brief This data type describes the possible status values returned
 *  by functions.
 */
typedef enum NVIC_DMA001_StatusType
{
  /**
   * @cond INTERNAL_DOCS
  * @param MODULENAME NVIC_DMA001
  * @endcond
  */
  /**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING1 NVIC_DMA001_INVALID_PARAM
  * @param STRCODESTRING1 Invalid parameter
  * @endcond
  */    
  /**
   * Invalid parameter
   */
  NVIC_DMA001_INVALID_PARAM = 1,
  /**
   * error interrupt
   */
  /**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING2 NVIC_DMA001_ERROR_INT
  * @param STRCODESTRING2 DMA Error Interrupt
  * @endcond
  */
  NVIC_DMA001_ERROR_INT,
  /**
    * Block interrupt
    */
  /**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING3 NVIC_DMA001_BLOCK_INT
  * @param STRCODESTRING3 DMA Block Interrupt
  * @endcond
  */
  NVIC_DMA001_BLOCK_INT, 
  /**
   * Transfer Complete Interrupt
   */
  /**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING4 NVIC_DMA001_TFR_INT
  * @param STRCODESTRING4 DMA Transfer Complete Interrupt
  * @endcond
  */
  NVIC_DMA001_TFR_INT,
  /**
   * Source transaction interrupt
   */
  /**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING5 NVIC_DMA001_SRCTRAN_INT
  * @param STRCODESTRING5 DMA Source Transaction  Interrupt
  * @endcond
  */
  NVIC_DMA001_SRCTRAN_INT,
  /**
   *  Destination transaction interrupt
   */
  /**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING6 NVIC_DMA001_DSTTRAN_INT
  * @param STRCODESTRING6 DMA Destination Transaction  Interrupt
  * @endcond
  */
  NVIC_DMA001_DSTTRAN_INT,
  /**
   * Function Entry
   */
  /**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING7 NVIC_DMA001_FUN_ENTRY
  * @param STRCODESTRING7 Entered function \%s
  * @endcond
  *
  */
  NVIC_DMA001_FUN_ENTRY,
  /**
   *  Function Exit
   */
  /**
  * @cond INTERNAL_DOCS
  * @param ERRCODESTRING8 NVIC_DMA001_FUN_EXIT
  * @param STRCODESTRING8 Exited function \%s
  * @endcond
  */
  NVIC_DMA001_FUN_EXIT
}NVIC_DMA001_StatusType;


/**
 * @brief This data structure is used for selecting the
 * transfer type for a specified DMA channel when using
 * the specified driver API functions.
 *
 */
typedef enum NVIC_DMA001_ChStateType{
  NVIC_DMA001_IDLE          = 0x0,
  NVIC_DMA001_SINGLE_REGION = 0x1,
  NVIC_DMA001_BURST_REGION  = 0x2
}NVIC_DMA001_ChStateType;

/**
 * @brief Data structure which has the Channel Configuration options.
 * The channel selection and address configurations are done using
 * this structure.
 */

typedef struct
{
  uint8_t ch_num;                  /* channel number */
  NVIC_DMA001_ChStateType SrcState;    /* DMA source state*/
  NVIC_DMA001_ChStateType DstState;    /* DMA destination state*/
  uint32_t BlockCnt;      /* count of completed blocks*/
  DMACallbackType CbListener; /* listener functon for IRQ handler*/
  uint32_t CbArg;
}NVIC_DMA001_ChInstanceType;

typedef struct{
  NVIC_DMA001_ChInstanceType Ch[DMA_MAX_CHANNELS];
  GPDMA0_GLOBAL_TypeDef* DMARegs;	    /**  Pointer to DMA Unit */
}NVIC_DMA001_HandleType;

 
/**
 * @}
 */
/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/


/*******************************************************************************
**                      Extern Variables                                      **
*******************************************************************************/


/*******************************************************************************
** FUNCTION PROTOTYPES                                                        **
*******************************************************************************/

/**
 * @ingroup NVIC_DMA001_apidoc
 * @{
 */

/**
 * @brief      Function to initialize the DMA0 Interrupt Node based on
 * 			   user configuration.
 *
 *
 * @param[in]  None
 *
 * @return     None
 *
 * <b>Reentrant: NO </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 *  #include <DAVE3.h>
 *  void CbListener(DMA_IRQType IRQType,uint32_t CbArg);
 *  int main(void)
 *  {
 *    DMACallbackType CbListener;
 *    DAVE_Init(); // NVIC_DMA001_Init() is called within DAVE_Init()
 *    // .....
 *    return 0;
 *  }
 *
 * @endcode<BR> </p>
 *
 */
void  NVIC_DMA001_Init(void);

/**
 * @brief      Function to register user defined callback function which
 * 			   will be called from Interrupt Handler.Top level DMA Apps
 * 			   can use this function,to get notified for Channel specific
 * 			   DMA Events.
 *
 *
 * @param[in]  App handle
 * @param[in]  DMA Channel Index
 * @param[in]  Callback function pointer
 * @param[in]  Callback function argument
 *
 * @return     none
 *
 * <b>Reentrant: NO </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 * @code
 *  #include <DAVE3.h>
 *
 *  void CbListener(DMA_IRQType IRQType,uint32_t CbArg)
 *  {//  Implementation
 *  };
 *  int main(void)
 *  {
 *
 *    DAVE_Init(); // NVIC_DMA001_Init() is called within DAVE_Init()
 *    // Example usage of API
 *    NVIC_DMA001_RegisterCallback(&NVIC_DMA001_Handle0,1,CbListener,0);
 *    // .....
 *    return 0;
 *  }
 *
 * @endcode<BR> </p>
 */


void NVIC_DMA001_RegisterCallback(NVIC_DMA001_HandleType* Handle,
  uint8_t ch_index,
  DMACallbackType userFunction,
  uint32_t CbArgs);

/**
 *@}
 */

#include "NVIC_DMA001_Conf.h"

#ifdef  __cplusplus
}
#endif

#endif /* NVIC_DMA001_H_ */
