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
** v0.0.11, 18 Jan 2013,  Initial version.
** v0.0.16, 30 Sept 2013, Updated code for compliance with programming
**                        guidelines.  
*******************************************************************************/

/**
 * @file DMA003.h
 *
 * @brief  Header file for Standard DMA App.
 *
 */

#ifndef DMA003_H_
#define DMA003_H_

/* Support for C++ */
#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
**                      Include Files                                        **
******************************************************************************/

/*
 * This file understands your microcontroller
 * device and defines various other helper
 * macros which are used in the later part
 * of the code. Please see below for an example.
 * __TARGET_DEVICE__ is a macro defined by
 * uc_id.h
 */
#include <uc_id.h>

/*
 * Conditional includes for various
 * XMC devices.
 */
#if (__TARGET_DEVICE__ == XMC45)
# include <XMC4500.h>
#elif (__TARGET_DEVICE__ == XMC44)
# include <XMC4400.h>
#elif (__TARGET_DEVICE__ == XMC42) || (__TARGET_DEVICE__ == XMC41)
# include <XMC4200.h>
#else
# error "Unsupported XMC family"
#endif

/* Include header file for the NVIC DMA App. */ 
#include "../../inc/NVIC_DMA001/NVIC_DMA001.h"

/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/

/******************************************************************************
**                      Global Type Definitions                              **
******************************************************************************/
 
/**
 * @ingroup DMA003_enumerations
 * @{
 */
/**
 * @brief This data type describes the possible status values returned
 *  by functions.
 */
typedef enum DMA003_StatusType {
  /**
   * Indicates Flag is not set
   */
  /**
   *@cond INTERNAL_DOCS
   *@param MODULENAME DMA003
   *@endcond
  */

  /**
   * Function Entry
   */
  /**
   *@cond INTERNAL_DOCS
   *@param ERRCODESTRING1 DMA003_FUN_ENTRY
   *@param STRCODESTRING1 Entered function \%s
   *@endcond 
  */
  DMA003_FUN_ENTRY,
  /**
   *  Function Exit
   */
  /**
   *@cond INTERNAL_DOCS
   *@param ERRCODESTRING2 DMA003_FUN_EXIT
   *@param STRCODESTRING2 Exited function \%s
   *@endcond 
  */
  DMA003_FUN_EXIT
} DMA003_StatusType;

/**
 * @}
 */
 
/**
  * @ingroup DMA003_datastructures
  * @{
  */

/**
 * @brief Channel Configuration Data structure.
 * Channel configuration related parameters are stored in this
 * structure.
 */

typedef struct DMA003_ChannelConfigType {
  /** Source Address  */
  uint32_t SrcAddress;              
  /** Destination address */
  uint32_t DstAddress;              
  /** Block size of a transfer */
  uint32_t BlockSize;                
  /** Transfer flow device  */
  DMA_TransferFlowType TransferFlow;
   /** Channel Priority */
  DMA_ChPriorityType ChPriority;   
   /** Source Transfer width */
  DMA_TransferWidthType SrcTrWidth;
  /** Destination Transfer width */
  DMA_TransferWidthType DstTrWidth;  
   /** Source burst transfer length */
  DMA_BurstTransLenType SrcMSize;  
   /** Destination burst transfer length*/
  DMA_BurstTransLenType DstMSize;  
   /** Source address increment type */
  DMA_AddrIncType SrcInc;          
  /** Dest address increment type */
  DMA_AddrIncType DstInc;           
} DMA003_ChannelConfigType;

/**
 * @brief Application Handle Data structure.
 * Stores the mapped DMAUnit & Channel.
 */
typedef struct DMA003_ChannelHandleType {
  /** Channel Configuration parameters  */ 
  DMA003_ChannelConfigType ChConfig;  
   /** Base Address of mapped DMA Unit */
  GPDMA0_CH_TypeDef* DMAChRegs;
  GPDMA0_GLOBAL_TypeDef* DMARegs;
  /*Mapped NVIC_DMA001 App Handle */
  NVIC_DMA001_HandleType* NVICDMA_Handle;
   /** Channel allocated by Dave3  */
  uint8_t ChannelID;                
  /** DMA Unit ID  */
  uint8_t DMAUnit;                   
  /** Channel Enabled by default */
  bool  ChannelEnabled;              
  /** Source Transfer width */  
  bool  HWHandshakeEnabled;
  /** Enable source transaction event */
  bool SrcTranEventEn;
  /** Enable destination transaction event */
  bool DstTranEventEn;
  /** Enable error event */
  bool ErrorEventEn;
  /** Enable block event */
  bool BlockEventEn;
  /** Enable transfer complete event */
  bool TfrEventEn;
  /** DMA user call back function */
  DMACallbackType Cb_Fun;
  /** DMA's DLR line enable configuration. */
  uint32_t Dlr_Enable;
} DMA003_ChannelHandleType;

/**
 * @}
 */
 
/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Extern Variables                                      **
*******************************************************************************/

/**
 * @ingroup DMA003_apidoc
 * @{
 */

/*******************************************************************************
** FUNCTION PROTOTYPES                                                        **
*******************************************************************************/



/**
 * @brief  Function to initialize all DMA channel registers consumed by  
 *         DMA003 App. The function takes a void function and initalizes 
 *  	   channel registers based on the UI configuration of App instances.
 *
 *
 * @param[in]: None 
 *
 * @return     None
 *
 * <b>Reentrant: NO </b><BR>
 *
  * @code
 *  #include <DAVE3.h>
 *
 *  int main(void)
 *  {
 *     DAVE3_Init();
 *  }
 * @endcode<BR> </p>
 */
void  DMA003_Init(void);

/**
 * @brief   Function to reset channel parameters to default values.
 *          The funciton restores the channel register configuration
 *          to reset value. 
 *
 *
 * @param[in]  Handle to DMA channel
 *
 * @return     status <BR>
 *             DAVEApp_SUCCESS  : for success.<BR>
 *             DMA_EBUSY 		: in case Channel is currently in use.<BR>
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>DMA003_Handle0</b></I> is a global structure of type
 * DMA003_ChannelHandleType configured in DMA003_conf.c file based on App UI
 *  configuration & resource.
 *  mapping.
 * @code
 *  #include <DAVE3.h>
 *  int main(void)
 *  {
 *    DAVE_Init();
 *    ...
 *    ...
 *    // Finally call Deinit function to reset the DMA channel to
 *    // default values.
 *    DMA003_DeInitChannel(&DMA003_Handle0);
 *  }
 * @endcode<BR> </p>
 */
void  DMA003_DeInitChannel(const DMA003_ChannelHandleType* Handle);

/**
 * @brief  Function to get the DMA Channel parameters at run time.
 *
 *
 * @param[in]  	  App Handle
 * @param[in/out] Pointer to Channel configuration structure.
 *
 * @return     status <BR>
 * DAVEApp_SUCCESS : for success.<BR>
 * DMA_EBUSY       : in case Channel is currently in use.<BR>
 * DMA_ECHRNG      : channel No out of range.<BR>
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>DMA003_Handle0</b></I> is a global structure of type
 *  DMA003_ChannelHandleType configured in DMA003_conf.c file based on App UI
 *  configuration & resource.
 *  mapping.
 * @code
 *  #include <DAVE3.h>
 *  int main(void)
 *  {
 *     DAVE_Init();
 *     uint32_t BlkSize = 0;
 *     DMA003_ChannelConfigType ChConfig;
 *     status_t Status = DAVEApp_SUCCESS;
 *     Status = DMA003_GetChannelTransferParams(&DMA003_Handle0,&ChConfig);
 *     if ( Status == DAVEApp_SUCCESS)
 *     {
 *       // Copy block size
 *       BlkSize = ChConfig.BlockSize;
 *     }
 *  }
 * @endcode<BR> </p>
 *
 */
status_t  DMA003_GetChannelTransferParams 
( 
  const  DMA003_ChannelHandleType* Handle,
  DMA003_ChannelConfigType* ChConfig
);

/**
 * @brief   This function sets configuration parameters for the DMA
 * 			DMA Channel consumed by the App. 
 *
 *
 *
 * @param[in]  Handle to DMA channel.
 * @param[in]  Pointer to Channel configuration structure.
 * 
 * @return     status <BR>
 * DAVEApp_SUCCESS : for success.<BR>
 * DMA_EBUSY       : in case Channel is currently in use.<BR>
 * DMA_ECHRNG      : channel Number out of range.<BR>
 * DMA_EINVAL      : if an attempt is made to set 
 *			         a configuration parameter value outside the 
 *			         legal range.<BR>
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>DMA003_Handle0</b></I> is a global structure of type
 *  DMA003_ChannelHandleType configured in DMA003_conf.c file based on App UI
 *  configuration & resource.
 *  mapping.
 * @code
 *  #include <DAVE3.h>
 *  int main(void)
 *  {
 *     uint32_t BlkSize = 0;
 *     DAVE_Init();
 *     status_t Status = DAVEApp_SUCCESS;
 *
 *     DMA003_ChannelConfigType ChConfig;
 *
 *     ChConfig.BlockSize  = 0x10;
 *     ChConfig.SrcTrWidth = DMA_TRANS_WIDTH_32;
 *     ChConfig.DstTrWidth = DMA_TRANS_WIDTH_32;
 *     ChConfig.SrcMSize   = DMA_MSIZE_64;
 *     ChConfig.DstMSize   = DMA_MSIZE_64;
 *
 *     Status = DMA003_SetChannelTransferParams(&DMA003_Handle0,&ChConfig);
 *     if ( Status == DAVEApp_SUCCESS)
 *     {
 *       // Copy block size
 *       BlkSize = ChConfig.BlockSize
 *     }
 *  }
 * @endcode<BR> </p>
 *
 */
status_t  DMA003_SetChannelTransferParams 
( 
  const DMA003_ChannelHandleType* Handle,
  const DMA003_ChannelConfigType* ChConfig
);

/**
 * @brief   This function is used to set up a listener function which will be
 * 			called from the interrupt handler.A listener must be setup before
 *			calling the StartTransfer function .
 *              
 *
 *
 * @param[in]  Handle Channel handle
 * @param[in]  Callback function pointer
 * @param[in]  Callback function argument
 *
 * @return     None
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>DMA003_Handle0</b></I> is a global structure of type
 *  DMA003_ChannelHandleType configured in DMA003_conf.c file based on App UI
 *  configuration & resource.
 *  mapping.
 * @code
 *  #include <DAVE3.h>
 *  void CbListener(DMA_IRQType IRQType,uint32_t CbArg);
 *
 *  int main(void)
 *  {
 *     DAVE_Init();
 *     status_t Status = DAVEApp_SUCCESS;
 *     DMACallbackType CbListener;
 *     DMA003_ChannelConfigType ChConfig;
 *
 *     Status = DMA003_SetChannelTransferParams(&DMA003_Handle0,&ChConfig);
 *     if ( Status == DAVEApp_SUCCESS)
 *     {
 *       // Set the Application callback function to handle DMA events.
 *       DMA003_SetListener(&DMA003_Handle0,
 *                          CbListener,
 *                          0x1200);
 *     }
 *  }
 * @endcode<BR> </p>
 *
 */

void DMA003_SetListener(
	const DMA003_ChannelHandleType* Handle,
	DMACallbackType userFunction,
	uint32_t CbArgs);
	
/**
 * @brief   This function is used to set the Source address for the GPDMA transfer.
 *
 *
 *
 * @param[in]  Handle Channel handle
 * @param[in]  Source address
 *
 * @return     None
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>DMA003_Handle0</b></I> is a global structure of type
 *  DMA003_ChannelHandleType configured in DMA003_conf.c file based on App UI
 *  configuration & resource.
 *  mapping.
 * @code
 *  #include <DAVE3.h>
 *
 *  int main(void) {
 *     DAVE_Init();
 *     status_t Status = DAVEApp_SUCCESS;
 *
 *     DMA003_SetSourceAddress(&DMA003_Handle0, (uint32_t)&(UART001_Handle0.UartRegs->TBUF));
 *     DMA003_StartTransfer(&DMA003_Handle0);
 *     while (1) {
 *       // nothing here.
 *     }
 *  }
 * @endcode<BR> </p>
 *
 */

void DMA003_SetSourceAddress(const DMA003_ChannelHandleType *handle, uint32_t address);

/**
 * @brief   This function is used to set the Destination address for the GPDMA transfer.
 *
 *
 *
 * @param[in]  Handle Channel handle
 * @param[in]  Destination address
 *
 * @return     None
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>DMA003_Handle0</b></I> is a global structure of type
 *  DMA003_ChannelHandleType configured in DMA003_conf.c file based on App UI
 *  configuration & resource.
 *  mapping.
 * @code
 *  #include <DAVE3.h>
 *
 *  #define ASIZE 5
 *  uint8_t c[ASIZE] = {4, 5, 6, 7, 8}, d[ASIZE];
 *
 *  int main(void) {
 *     DAVE_Init();
 *     status_t Status = DAVEApp_SUCCESS;
 *
 *     // set source address.
 *     DMA003_SetSourceAddress(&DMA003_Handle0, (uint32_t)c);
 *     // set destination address.
 *     DMA003_SetDestinationAddress(&DMA003_Handle0, (uint32_t)d);
 *     DMA003_StartTransfer(&DMA003_Handle0);
 *     while (1) {
 *       // nothing here.
 *     }
 *  }
 * @endcode<BR> </p>
 *
 */

void DMA003_SetDestinationAddress(const DMA003_ChannelHandleType *handle, uint32_t address);

/**
 * @brief    This function starts the DMA transfer for the requested channel.
 *
 *
 * @param[in]  Handle to DMA channel.
 * 
 * @return     status<BR> 
 *             DAVEApp_SUCCESS for success.<BR>
 *             DMA_EBUSY in case Channel is currently in use.<BR>
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>DMA003_Handle0</b></I> is a global structure of type
 *  DMA003_ChannelHandleType configured in DMA003_conf.c file based on App UI
 *  configuration & resource.
 *  mapping.
 * @code
 *  #include <DAVE3.h>
 *  void CbListener(DMA_IRQType IRQType,uint32_t CbArg);
 *
 *  int main(void)
 *  {
 *     DAVE_Init();
 *     status_t Status = DAVEApp_SUCCESS;
 *     DMACallbackType CbListener;
 *     DMA003_ChannelConfigType ChConfig;
 *
 *     Status = DMA003_SetChannelTransferParams(&DMA003_Handle0,&ChConfig);
 *     if ( Status == DAVEApp_SUCCESS)
 *     {
 *       // Set the Application callback function to handle DMA events.
 *       DMA003_SetListener(&DMA003_Handle0,
 *                          CbListener,
 *                          0x1200);
 *        // Start the Channel transfer.
 *        Status = DMA003_StartTransfer(&DMA003_Handle0);
 *        if ( Status == DMA_EBUSY)
 *         {
 *           // DMA channel is currently busy
 *         }
 *     }
 *  }
 * @endcode<BR> </p>
 *
 */
status_t DMA003_StartTransfer(const DMA003_ChannelHandleType* Handle);

/**
 * @brief    This function starts a software triggered DMA transfer.
 *
 *
 * @param[in]  Handle to DMA channel.
 * @param[in]  Type of Software Handshaking.
 * 
 * @return     none<BR> 
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>DMA003_Handle0</b></I> is a global structure of type
 *  DMA003_ChannelHandleType configured in DMA003_conf.c file based on App UI
 *  configuration & resource.
 *  mapping.
 * @code
 *  #include <DAVE3.h>
 *
 *  void CbListener(DMA_IRQType IRQType,uint32_t CbArg);
 *
 *  int main(void)
 *  {
 *     DAVE_Init();
 *     status_t Status = DAVEApp_SUCCESS;
 *     DMACallbackType CbListener;
 *     DMA003_ChannelConfigType ChConfig;
 *
 *
 *     // Set the Application callback function to handle DMA events.
 *     DMA003_SetListener(&DMA003_Handle0,
 *                          CbListener,
 *                          0x1200);
 *     // Start the Channel transfer.
 *     Status = DMA003_StartTransfer(&DMA003_Handle0);
 *     if ( Status == DMA_EBUSY)
 *     {
 *        // DMA channel is currently busy
 *     }
 *     // Trigger Software Burst Transfer
 *     DMA003_TriggerSWTransfer(&DMA003_Handle0,DMA_SRC_BURST);
 *     //.....
 *  }
 * @endcode<BR> </p>
 *
 */
void  DMA003_TriggerSWTransfer(const DMA003_ChannelHandleType* Handle,DMA_SWRequestType Request);
/**
 * @brief    This function reloads the channel with the user configuration
 * 			 settings. (App GUI settings)
 *
 *
 * @param[in]  Handle to DMA channel.
 *
 * @return     None<BR>
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * <BR><I><b>DMA003_Handle0</b></I> is a global structure of type
 *  DMA003_ChannelHandleType configured in DMA003_conf.c file based on App UI
 *  configuration & resource.
 *  mapping.
 * @code
 *  #include <DAVE3.h>
 *  void CbListener(DMA_IRQType IRQType,uint32_t CbArg);
 *  bool bTranferComplete = FALSE;
 *  int main(void)
 *  {
 *     DAVE_Init();
 *     status_t Status = DAVEApp_SUCCESS;
 *     DMACallbackType CbListener;
 *     // Start the Channel transfer.
 *     Status = DMA003_StartTransfer(&DMA003_Handle0);
 *     // Wait for the Transfer complete interrupt.
 *     while(!bTranferComplete);
 *     // Reload channel user configuration.
 *     DMA003_ReloadUserConfiguration(&DMA003_Handle0);
 *     // Start the Channel transfer.
 *     Status = DMA003_StartTransfer(&DMA003_Handle0);
 *  }
 *
 *
 *  CbListener(DMA_IRQType IRQType,uint32_t CbArg)
 *  {
 *    if(IRQType == DMA_IRQ_TFR)
 *    bTranferComplete = TRUE;
 *  }
 *
 * @endcode<BR> </p>
 *
 */
void DMA003_ReloadUserConfiguration(const DMA003_ChannelHandleType* Handle);
/**
 *@}
 */

/*******************************************************************************
** STRUCTURES:
*******************************************************************************/

#ifdef DAVE_CE
# include "DMA003_Extern.h"
#endif

/* Support for C++ */
#ifdef __cplusplus
}
#endif

#endif /* DMA003_H_ */

/*CODE_BLOCK_END*/