/*CODE_BLOCK_BEGIN[DMA003.c]*/

/*******************************************************************************
 Copyright (c) 2013, Infineon Technologies AG                                 **
 All rights reserved.                                                         **
                                                                              **
 Redistribution and use in source and binary forms, with or without           **
 modification,are permitted provided that the following conditions are met:   **
                                                                              **
 *Redistributions of source code must retain the above copyright notice,      **
 this list of conditions and the following disclaimer.                        **
 *Redistributions in binary form must reproduce the above copyright notice,   **
 this list of conditions and the following disclaimer in the documentation    **
 and/or other materials provided with the distribution.                       **
 *Neither the name of the copyright holders nor the names of its contributors **
 may be used to endorse or promote products derived from this software without**
 specific prior written permission.                                           **
                                                                              **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **
 POSSIBILITY OF SUCH DAMAGE.                                                  **
                                                                              **
 To improve the quality of the software, users are encouraged to share        **
 modifications, enhancements or bug fixes with Infineon Technologies AG       **
 dave@infineon.com).                                                          **
                                                                              **
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
** v1.0.12, 11 Feb 2013: Channel priority bug fix.
** v1.0.14, 13 Feb 2013: Misra update.
** v1.0.16, 30 Sept 2013: Updated code for compliance with programming
**                        guidelines.
*******************************************************************************/
/**
 * @file   DMA003.c
 *
 * @brief  Standard DMA Application
 *
 */

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/
/** Inclusion of the main App header file */
#include "../../inc/DMA003/DMA003.h"

/* Include file to access the constants and App HandleArray variables */
#ifdef DAVE_CE
# include "../../inc/DMA003/DMA003_Conf.h"
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define APP_GID DBG002_GID_DMA003

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                 Private Function Declarations:
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                 Function like macro definitions                            **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/* Check if a DMA channel is busy. Return status. */
static status_t DMA003_lCheckChannelBusy(const DMA003_ChannelHandleType* Handle) {
  GPDMA0_GLOBAL_TypeDef* DMARegs = Handle->DMARegs;
  uint8_t Channel = Handle->ChannelID;
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  /* <<<DD_DMA003_PRIVATE_API_1>>> */
  if((DMARegs->CHENREG) & ((uint32_t)0x01U << Channel)) {
      Status = (status_t)DMA_EBUSY;
  }
  return Status;
}

/* Local function to Enable Channel Enable Register */
static status_t DMA003_lStartTransfer(const DMA003_ChannelHandleType* Handle) {
  GPDMA0_GLOBAL_TypeDef* DMARegs = Handle->DMARegs;
  uint8_t Channel = Handle->ChannelID;
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  
  /* <<<DD_DMA003_PRIVATE_API_2>>> */
  Status = DMA003_lCheckChannelBusy(Handle);
    
  if(Status == (uint32_t)DAVEApp_SUCCESS) {
    /* UnMask  channel interrupts based on UI Settings */
    if(Handle->TfrEventEn) {
	  DMARegs->MASKTFR   = DMA_CH_NUM(Channel);
	}
	if(Handle->BlockEventEn) {
	  DMARegs->MASKBLOCK = DMA_CH_NUM(Channel);
	}
	if(Handle->ErrorEventEn) {
	  DMARegs->MASKERR   = DMA_CH_NUM(Channel);
	}
	if(Handle->SrcTranEventEn) {
	  DMARegs->MASKSRCTRAN = DMA_CH_NUM(Channel);
	}
	if(Handle->DstTranEventEn) {
	  DMARegs->MASKDSTTRAN   = DMA_CH_NUM(Channel);
	}
  }
  /* Enable the channel */
  DMARegs->CHENREG = DMA_CH_NUM(Channel);
  
  return Status;
}

/* Check DMA configuration parameters. */
static status_t DMA003_lCheckConfigParameters(const DMA003_ChannelConfigType* ChConfig) {
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  
  if(ChConfig->TransferFlow > DMA_PRF2MEM_DMA) {
    Status = (status_t)DMA_EINVAL;
  }
  if(ChConfig->ChPriority > DMA_PRIORITY_7) {
    Status = (status_t)DMA_EINVAL;
  }
  if(ChConfig->SrcTrWidth > DMA_TRANS_WIDTH_256) {
    Status = (status_t)DMA_EINVAL;
  }
  if(ChConfig->DstTrWidth > DMA_TRANS_WIDTH_256) {
    Status = (status_t)DMA_EINVAL;
  }
  if(ChConfig->SrcMSize > DMA_MSIZE_256) {
    Status = (status_t)DMA_EINVAL;
  }
  if(ChConfig->DstMSize > DMA_MSIZE_256) {
    Status = (status_t)DMA_EINVAL;
  }
  if(ChConfig->SrcInc > DMA_ADDR_NOCHANGE) {
    Status = (status_t)DMA_EINVAL;
  }
  if(ChConfig->DstInc > DMA_ADDR_NOCHANGE) {
    Status = (status_t)DMA_EINVAL;
  }
  
  return Status;
}

/*
 * Local helper function to configure the following:
 * 1. Set source and destination addresses.
 * 2. Set channel configuration parameters.
 * 3. Set block size for DMA transfer.
 * 4. Polarity configuration.
 * 5. Enable hardware handshaking (if required).
 * 6. Enable channel enable at initialization (if required).
 */
static void DMA003_lInit(const DMA003_ChannelHandleType* Handle) {
  GPDMA0_CH_TypeDef* DMAChRegs = Handle->DMAChRegs;

  /* <<<DD_DMA003_API_1>>> */

  /* <<<DD_DMA003_API_1_1>>> */
  /* Set the Source and destination addresses */
  DMAChRegs->SAR = (uint32_t) Handle->ChConfig.SrcAddress;
  DMAChRegs->DAR = (uint32_t) Handle->ChConfig.DstAddress;
  DMAChRegs->LLP = (uint32_t)0x00000000;
  
  /* Set the Channel Configuration Parameters */
  DMAChRegs->CTLL  = (DMA_CTLL_DST_WIDTH(Handle->ChConfig.DstTrWidth)\
                  | DMA_CTLL_SRC_WIDTH(Handle->ChConfig.SrcTrWidth)\
                  | DMA_CTLL_DST_INC(Handle->ChConfig.DstInc)\
                  | DMA_CTLL_SRC_INC(Handle->ChConfig.SrcInc)\
                  | DMA_CTLL_DST_MSIZE(Handle->ChConfig.DstMSize)\
                  | DMA_CTLL_SRC_MSIZE(Handle->ChConfig.SrcMSize)\
                  | DMA_CTLL_FC(Handle->ChConfig.TransferFlow)\
                  | DMA_CTLL_INT_EN);
 

  /* Set the block size for the DMA transfer */
  DMAChRegs->CTLH = ((uint32_t)GPDMA0_CH_CTLH_BLOCK_TS_Msk & Handle->ChConfig.BlockSize);
  
  /* Set the channel configuration */

  /* Polarity should be Active High */
  DMAChRegs->CFGL &= ~(DMA_CFGL_CH_PRIOR_Msk);
  DMAChRegs->CFGL |= ((DMA_CFGL_CH_PRIOR(Handle->ChConfig.ChPriority)) & DMA_CFGL_CH_PRIOR_Msk);
 
  /* Hardware handshaking register bits enabled */
  if (Handle->HWHandshakeEnabled) { 
    if(Handle->ChConfig.TransferFlow == DMA_PRF2MEM_DMA) {
	  DMA_CFGL_SET_HS_SRC(DMAChRegs->CFGL);
    } else {
	  DMA_CFGL_SET_HS_DST(DMAChRegs->CFGL);
    }
  }
 
  /* Check if channel enabling at initialization is enabled */
  /* <<<DD_DMA003_API_1_3>>> */
  if (Handle->ChannelEnabled) {
    DMA003_lStartTransfer(Handle);
  }
}

/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/
/*
 * Function to initialize the DMA channel parameters based on 
 * user configuration.
 */
void DMA003_Init(void) {
  uint32_t i;
  
  for (i = 0U; i < DMA003_NUM_INSTANCES; i++) {
    /* Initialize DMA003 handle. */
    DMA003_lInit(DMA003_HandleArray[i]);
    
    /*
     * Invoke DMA003_SetListener() and register
     * user-defined callback if required.
     */
    if (DMA003_HandleArray[i]->Cb_Fun != NULL) {
      DMA003_SetListener(DMA003_HandleArray[i], DMA003_HandleArray[i]->Cb_Fun, 0U);
    }
    
    /* Enable DLR settings if applicable. */
    if ((DMA003_HandleArray[i]->Dlr_Enable != 0U) &&
    	(DMA003_HandleArray[i]->HWHandshakeEnabled == 1U)) {
      DLR->LNEN |= DMA003_HandleArray[i]->Dlr_Enable;
    }
  }
}

/*
 * Function to reset channel parameters to default values. 
 */
void DMA003_DeInitChannel(const DMA003_ChannelHandleType* Handle) {
  GPDMA0_CH_TypeDef* DMAChRegs = Handle->DMAChRegs;
  
  /* <<<DD_DMA003_API_2>>> */
  DMAChRegs->SAR   = 0x00000000UL;
  DMAChRegs->DAR   = 0x00000000UL;
  DMAChRegs->CTLL  = 0x00304801UL;
  DMAChRegs->CTLH  = 0x00000002UL;
  DMAChRegs->CFGL  = 0x00000E40UL;
  DMAChRegs->CFGH  = 0x00000004UL;
  DMAChRegs->LLP   = 0x00000000UL;
}

/*
 * Function to Get the DMA Channel parameters at run time. 
 */
status_t  DMA003_GetChannelTransferParams(const DMA003_ChannelHandleType* Handle,
                                          DMA003_ChannelConfigType* ChConfig) {
  GPDMA0_CH_TypeDef* DMAChRegs = Handle->DMAChRegs;
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  /* <<<DD_DMA003_API_3>>> */

  if (ChConfig != NULL) {
    /*Copy the Channel configuration to the Channel Structure */
    ChConfig->SrcAddress = DMAChRegs->SAR;
    
    ChConfig->DstAddress = DMAChRegs->DAR;
    
    ChConfig->DstTrWidth = (DMA_TransferWidthType)RD_REG(DMAChRegs->CTLL,\
        GPDMA0_CH_CTLL_DST_TR_WIDTH_Msk, GPDMA0_CH_CTLL_DST_TR_WIDTH_Pos);                       
    
    ChConfig->SrcTrWidth = (DMA_TransferWidthType)RD_REG(DMAChRegs->CTLL,\
        GPDMA0_CH_CTLL_SRC_TR_WIDTH_Msk, GPDMA0_CH_CTLL_SRC_TR_WIDTH_Pos);
    
    ChConfig->DstInc = (DMA_AddrIncType)RD_REG(DMAChRegs->CTLL,\
        GPDMA0_CH_CTLL_DINC_Msk, GPDMA0_CH_CTLL_DINC_Pos);                      
                          
    ChConfig->SrcInc = (DMA_AddrIncType)RD_REG(DMAChRegs->CTLL,\
        GPDMA0_CH_CTLL_SINC_Msk, GPDMA0_CH_CTLL_SINC_Pos);
    
    ChConfig->DstMSize = (DMA_BurstTransLenType)RD_REG(DMAChRegs->CTLL,\
        GPDMA0_CH_CTLL_DEST_MSIZE_Msk, GPDMA0_CH_CTLL_DEST_MSIZE_Pos);
    
    ChConfig->SrcMSize = (DMA_BurstTransLenType)RD_REG(DMAChRegs->CTLL,\
        GPDMA0_CH_CTLL_SRC_MSIZE_Msk, GPDMA0_CH_CTLL_SRC_MSIZE_Pos);
   
    ChConfig->TransferFlow = (DMA_TransferFlowType)RD_REG(DMAChRegs->CTLL,\
        GPDMA0_CH_CTLL_TT_FC_Msk, GPDMA0_CH_CTLL_TT_FC_Pos);  
          
    ChConfig->BlockSize = RD_REG(DMAChRegs->CTLH,\
        (uint32_t)GPDMA0_CH_CTLH_BLOCK_TS_Msk, GPDMA0_CH_CTLH_BLOCK_TS_Pos);
        
    ChConfig->ChPriority = (DMA_ChPriorityType)RD_REG(DMAChRegs->CFGL,\
    					   GPDMA0_CH_CFGL_CH_PRIOR_Msk, GPDMA0_CH_CFGL_CH_PRIOR_Pos);
  } else {
    Status = (status_t)DMA_EINVAL;
  }

  return Status;
}

/*
 * This function allows runtime configuration of channel configuration
 * parameters to be changed. 
 */ 
status_t  DMA003_SetChannelTransferParams(const DMA003_ChannelHandleType* Handle,
                                          const DMA003_ChannelConfigType* ChConfig) {
  GPDMA0_CH_TypeDef* DMAChRegs = Handle->DMAChRegs;
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  uint32_t Reg;
  /* <<<DD_DMA003_API_4>>> */
  /* Check for valid not busy  */
  Status = DMA003_lCheckChannelBusy(Handle);
  /* Check for proper range */
  if(Status == (uint32_t)DAVEApp_SUCCESS) {  
    Status = DMA003_lCheckConfigParameters(ChConfig);
  }

  if (Status == (uint32_t)DAVEApp_SUCCESS) { 
    /* Set the Source and destination addresses */
    DMAChRegs->SAR = (uint32_t)ChConfig->SrcAddress;
    DMAChRegs->DAR = (uint32_t)ChConfig->DstAddress;
    
    /* Set the Channel Configuration Parameters */
    Reg = (DMA_CTLL_DST_WIDTH(ChConfig->DstTrWidth)\
                 | DMA_CTLL_SRC_WIDTH(ChConfig->SrcTrWidth)\
                 | DMA_CTLL_DST_INC(ChConfig->DstInc)\
                 | DMA_CTLL_SRC_INC(ChConfig->SrcInc)\
                 | DMA_CTLL_DST_MSIZE(ChConfig->DstMSize)\
                 | DMA_CTLL_SRC_MSIZE(ChConfig->SrcMSize)\
                 | DMA_CTLL_FC(ChConfig->TransferFlow)\
                 | DMA_CTLL_INT_EN);
                 
    DMAChRegs->CTLL = Reg;
    /* Set the block size for the DMA transfer */
    DMAChRegs->CTLH = ( (uint32_t)GPDMA0_CH_CTLH_BLOCK_TS_Msk & ChConfig->BlockSize);
    
    DMAChRegs->CFGL &= ~(DMA_CFGL_CH_PRIOR_Msk);
    DMAChRegs->CFGL |=((DMA_CFGL_CH_PRIOR(ChConfig->ChPriority)) & DMA_CFGL_CH_PRIOR_Msk);
  }

  return Status;
}

/*
 * This function is used to set the Source address
 * for the GPDMA transfer.
 */
inline void DMA003_SetSourceAddress(const DMA003_ChannelHandleType *handle,
								    uint32_t address) {
  handle->DMAChRegs->SAR = address;
}

/*
 * This function is used to set the Destination address
 * for the GPDMA transfer.
 */
inline void DMA003_SetDestinationAddress(const DMA003_ChannelHandleType *handle,
								         uint32_t address) {
  handle->DMAChRegs->DAR = address;
}

/*
 * Function to register user defined callback.   
 */
void DMA003_SetListener(const DMA003_ChannelHandleType* Handle,
                        DMACallbackType userFunction,
                        uint32_t CbArgs) {
  /* <<<DD_DMA003_API_5>>> */
  if (userFunction !=NULL) {
      NVIC_DMA001_RegisterCallback(Handle->NVICDMA_Handle,
			Handle->ChannelID, userFunction, CbArgs);    
  }
}

/*
 * This function starts the DMA transfer for the requested channel.   
 */
status_t DMA003_StartTransfer(const DMA003_ChannelHandleType* Handle) {
  status_t Status = (uint32_t)DAVEApp_SUCCESS;
  /* <<<DD_DMA003_API_6>>> */
  Status = DMA003_lStartTransfer(Handle);

  return Status;
}

/*
 * This function is for software triggered DMA transfer.   
 */
void  DMA003_TriggerSWTransfer(const DMA003_ChannelHandleType* Handle,
                               DMA_SWRequestType Request) {
  GPDMA0_GLOBAL_TypeDef* DMARegs = Handle->DMARegs;
  uint8_t Channel = Handle->ChannelID;
  
  /* <<<DD_DMA003_API_7>>> */
  if (Request == DMA_SRC_BURST) {
	 DMARegs->REQSRCREG    = DMA_CH_NUM(Channel);
	 DMARegs->SGLREQSRCREG = DMA_CH_NUM(Channel);
  } else if (Request == DMA_SRC_SINGLE) {
 	 DMARegs->SGLREQSRCREG = DMA_CH_NUM(Channel);
  } else if (Request == DMA_DST_BURST) {
	 DMARegs->REQDSTREG    = DMA_CH_NUM(Channel);
	 DMARegs->SGLREQDSTREG = DMA_CH_NUM(Channel);
  } else if (Request == DMA_DST_SINGLE) {
	 DMARegs->SGLREQDSTREG = DMA_CH_NUM(Channel);  
  } else {
	  /* no code*/
  }
}

/*
 * Utility function to reload user configuration for DMA channel.   
 */
void DMA003_ReloadUserConfiguration(const DMA003_ChannelHandleType* Handle) {  
  /* <<<DD_DMA003_API_8>>> */
  DMA003_lInit(Handle);
}

/*CODE_BLOCK_END*/

