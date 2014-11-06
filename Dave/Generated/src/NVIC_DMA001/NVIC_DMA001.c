/*******************************************************************************
**  DAVE App Name : NVIC_DMA001       App Version: 1.0.16               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/


/*CODE_BLOCK_BEGIN[NVIC_DMA001.c]*/

/*******************************************************************************
 Copyright (c) 2012, Infineon Technologies AG                                 **
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
**                                                                            **
** PLATFORM : Infineon XMC4XXX Series                                                **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Dec 4, 2012                                           **
**                                                                            **
*******************************************************************************/
/**
 * @file   NVIC_DMA001.c
 * 
 *  
 * @brief  NVIC_DMA001 App
 *
 */
 /*
 * Revision History
 * 18 Jan 2013 v1.0.11 Initial version
 */

/*******************************************************************************
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** PAE        App Developer                                                   **
*******************************************************************************/

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/
/** Inclusion of header file */

#include <DAVE3.h>

  
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
#define DBG002_MESSAGEID_LITERAL
#endif/* End of defintions of dummy Debug Log macros*/                  






/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define APP_GID DBG002_GID_NVIC_DMA001
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                 Private Function Declarations:
*******************************************************************************/
void GPDMA1_0_IRQHandler(void);
void GPDMA0_0_IRQHandler(void);
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

/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/


/*CODE_BLOCK_END*/

void NVIC_DMA001_Init()
{
  /*<<<DD_NVIC_DMA001_API_1>>>*/  

  /* Set Interrupt Priority for NVIC 110 Node DMA Unit 0 */
  NVIC_SetPriority((IRQn_Type)110, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),10U,0U));
  /* Enable Interrupt */
  NVIC_EnableIRQ((IRQn_Type)110);
  /* Reset the DMA1 Unit*/
  RESET001_DeassertReset(PER2_DMA1);
  /* Enable the DMA1 Unit*/
  GPDMA1->DMACFGREG |= (uint32_t)GPDMA1_DMACFGREG_DMA_EN_Msk;
  /* Set Interrupt Priority for NVIC 105 Node DMA Unit 0 */
  NVIC_SetPriority((IRQn_Type)105, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),10U,0U));
  /* Enable Interrupt */
  NVIC_EnableIRQ((IRQn_Type)105); 
    /* Reset the DMA0 Unit*/
  RESET001_DeassertReset(PER2_DMA0);
  /* Enable the DMA0 Unit*/
  GPDMA0->DMACFGREG |= GPDMA0_DMACFGREG_DMA_EN_Msk;
}



void NVIC_DMA001_RegisterCallback
(
  NVIC_DMA001_HandleType* Handle,
  uint8_t ch_index,
  DMACallbackType userFunction,
  uint32_t CbArgs
 )
{
  /*<<<DD_NVIC_DMA001_API_2>>>*/
  DBG002_I(userFunction != NULL);
  Handle->Ch[ch_index].CbListener = userFunction;
  Handle->Ch[ch_index].CbArg = CbArgs;
}




void GPDMA1_0_IRQHandler(void)
{
  uint8_t i = 0U;
  uint8_t ch_index = 0U;
  DMACallbackType UserCallback;
  GPDMA1_GLOBAL_TypeDef* DMARegs = GPDMA1;	
  NVIC_DMA001_HandleType* Handle = &NVIC_DMA001_Handle1;
  uint32_t Reg, IrqActive, Mask;
  uint32_t callbackArg = 0U;
  
  /* read the interrupt status Register */
  IrqActive = DMARegs->STATUSINT;
  /* ERR INTERRUPT	*/
  if(RD_REG(IrqActive,GPDMA1_STATUSINT_ERR_Msk, GPDMA1_STATUSINT_ERR_Pos))
  {
    /* Read the Error Status Register */
    Reg = DMARegs->STATUSERR;
    /* Loop through the channels until we find active interrupt. */
    for(i=0U;i< DMA1_MAX_CHANNELS;i++)
    {
      Mask = ((uint32_t)1U) << i;
	  if(Reg & Mask) 
	  {
	    ch_index = i;
        break;
      }
    }
    // DBG002_ERROR(APP_GID,NVIC_DMA001_ERROR_INT, 0, NULL);
    /* run the listener function */
    if(Handle->Ch[ch_index].CbListener != NULL)
    {
      UserCallback = Handle->Ch[ch_index].CbListener;
      callbackArg = Handle->Ch[ch_index].CbArg;
      UserCallback(DMA_IRQ_ERR, callbackArg);
    }
    /* clear the interrupt */
    DMARegs->CLEARERR = Mask; 
  }
  /* TFR INTERRUPT */
  else if(RD_REG(IrqActive,GPDMA1_STATUSINT_TFR_Msk, GPDMA1_STATUSINT_TFR_Pos))
  {
    /* Read the Transfer Status Register */
    Reg = DMARegs->STATUSTFR;
    /*  Loop through the channels until we find
     *  active interrupt. We start at the highest priority
     * channel and work down to the lowest priority.
     */
    for(i=0U;i< DMA1_MAX_CHANNELS;i++)
    {
      Mask = ((uint32_t)1U) << i;
      if(Reg & Mask) 
      {
        ch_index = i;
        break;
      }
    }
    /* increment the block count */
    Handle->Ch[ch_index].BlockCnt++;
    /* Mask all channel interrupts */
    Reg = ( ((uint32_t)1U) << (ch_index + DMA1_MAX_CHANNELS));
    DMARegs->MASKTFR = Reg;
    DMARegs->MASKBLOCK = Reg;
    DMARegs->MASKSRCTRAN = Reg;
    DMARegs->MASKDSTTRAN = Reg;
    DMARegs->MASKERR = Reg;
	
    // DBG002_INFO(APP_GID,NVIC_DMA001_TFR_INT, 0, NULL);
    /* run the listener function */
    if(Handle->Ch[ch_index].CbListener != NULL)
    {
      UserCallback = Handle->Ch[ch_index].CbListener;
      callbackArg = Handle->Ch[ch_index].CbArg;
      UserCallback(DMA_IRQ_TFR, callbackArg);
    }
    /* reset the source and destination states */
    Handle->Ch[ch_index].SrcState = NVIC_DMA001_IDLE;
    Handle->Ch[ch_index].DstState = NVIC_DMA001_IDLE;
    /* Disable all channel interrupts */
    /* clear any pending block/srcTran/dstTran interrupts */
    DMARegs->CLEARBLOCK = Mask;
    DMARegs->CLEARSRCTRAN = Mask; 
    DMARegs->CLEARDSTTRAN = Mask;
    DMARegs->CLEARTFR = Mask;

  }    
  /* BLOCK INTERRUPT */
  else if(RD_REG(IrqActive,GPDMA1_STATUSINT_BLOCK_Msk, GPDMA1_STATUSINT_BLOCK_Pos)) 
  {
    /* Read the Block Status Register */
    Reg = DMARegs->STATUSBLOCK;
    /* Loop through the channels until we find active interrupt.*/
    for(i=0U;i< DMA1_MAX_CHANNELS;i++)
    {
      Mask = ((uint32_t)1U) << i;
      if(Reg & Mask) 
      {
        ch_index = i;
        break;
      }
    }

    /* increment the block count */
    Handle->Ch[ch_index].BlockCnt++;
    
    // DBG002_INFO(APP_GID,NVIC_DMA001_BLOCK_INT, 0, NULL);
    /* run the listener function */
    if(Handle->Ch[ch_index].CbListener != NULL)
    {
      UserCallback = Handle->Ch[ch_index].CbListener;
      callbackArg = Handle->Ch[ch_index].CbArg;
      UserCallback(DMA_IRQ_BLOCK, callbackArg);
    }
    /* reset the source and destination states */
    Handle->Ch[ch_index].SrcState = NVIC_DMA001_BURST_REGION;
    Handle->Ch[ch_index].DstState = NVIC_DMA001_BURST_REGION;
    /* clear any pending srcTran/dstTran interrupts */
    DMARegs->CLEARSRCTRAN = Mask; 
    DMARegs->CLEARDSTTRAN = Mask;
    /* clear the block interrupt */
    DMARegs->CLEARBLOCK = Mask;
  }	 
  /* SRCTRAN INTERRUPT */
  else if(RD_REG(IrqActive,GPDMA1_STATUSINT_SRCT_Msk, GPDMA1_STATUSINT_SRCT_Pos))
  {
    Reg = DMARegs->STATUSSRCTRAN;
    /* Loop through the channels until we find active interrupt. */
    for(i=0U;i< DMA1_MAX_CHANNELS;i++)
    {
      Mask = ((uint32_t)1U) << i;
      if(Reg & Mask) 
      {
        ch_index = i;
        break;
      }
    }
    
    // DBG002_INFO(APP_GID,NVIC_DMA001_SRCTRAN_INT, 0, NULL);
    
    if(Handle->Ch[ch_index].CbListener != NULL)
    {
      UserCallback = Handle->Ch[ch_index].CbListener;
      callbackArg = Handle->Ch[ch_index].CbArg;
      UserCallback(DMA_IRQ_SRCTRAN, callbackArg);
    }
    /* clear the interrupt */
    DMARegs->CLEARSRCTRAN = Mask;
  }
  /* DSTTRAN INTERRUPT */
  else if(RD_REG(IrqActive,GPDMA1_STATUSINT_DSTT_Msk, GPDMA1_STATUSINT_DSTT_Pos))
  {
    Reg = DMARegs->STATUSDSTTRAN;
    /* Loop through the channels until we find active interrupt */
    for(i=0U;i< DMA1_MAX_CHANNELS;i++)
    {
      Mask = ((uint32_t)1U) << i;
      if(Reg & Mask) 
      {
        ch_index = i;
        break;
      }
    }
    // DBG002_INFO(APP_GID,NVIC_DMA001_DSTTRAN_INT, 0, NULL);
    /* run the listener function */
    if(Handle->Ch[ch_index].CbListener != NULL)
    {
      UserCallback = Handle->Ch[ch_index].CbListener;
      callbackArg = Handle->Ch[ch_index].CbArg;
      UserCallback(DMA_IRQ_DSTTRAN, callbackArg);
    }
    /* clear the interrupt */
    DMARegs->CLEARDSTTRAN = Mask;
  }
  else
  {
    /* If we've reached this point, either the enabling and
     * disabling of DMA interrupts is not being handled
     * properly or this function is being called unnecessarily.
     */
  }
}

void GPDMA0_0_IRQHandler(void)
{
  uint8_t i = 0U;
  uint8_t ch_index = 0U;
  DMACallbackType UserCallback;
  GPDMA0_GLOBAL_TypeDef* DMARegs = GPDMA0;
  NVIC_DMA001_HandleType* Handle = &NVIC_DMA001_Handle2;
  uint32_t Reg, IrqActive, Mask;
  uint32_t callbackArg = 0U;
  
  /* read the interrupt status Register */
  IrqActive = DMARegs->STATUSINT;
  /* ERR INTERRUPT	*/
  if(RD_REG(IrqActive,GPDMA0_STATUSINT_ERR_Msk, GPDMA0_STATUSINT_ERR_Pos))
  {
    /* Read the Error Status Register */
    Reg = DMARegs->STATUSERR;
    /* Loop through the channels until we find active interrupt. */
    for(i=0U;i< DMA0_MAX_CHANNELS;i++) 
    {
      Mask = ((uint32_t)1U) << i;
	  if(Reg & Mask) 
	  {
	    ch_index = i;
        break;
      }
    }
    // DBG002_ERROR(APP_GID,NVIC_DMA001_ERROR_INT, 0, NULL);
    /* run the listener function */
    if(Handle->Ch[ch_index].CbListener != NULL)
    {
      UserCallback = Handle->Ch[ch_index].CbListener;
      callbackArg = Handle->Ch[ch_index].CbArg;
      UserCallback(DMA_IRQ_ERR, callbackArg);
    }
    /* clear the interrupt */
    DMARegs->CLEARERR = Mask;
  }
  /* TFR INTERRUPT */
  else if(RD_REG(IrqActive,GPDMA0_STATUSINT_TFR_Msk, GPDMA0_STATUSINT_TFR_Pos))
  {
    /* Read the Transfer Status Register */
    Reg = DMARegs->STATUSTFR;
    /*  Loop through the channels until we find
     *  active interrupt. We start at the highest priority
     * channel and work down to the lowest priority.
     */
    for(i=0U;i< DMA0_MAX_CHANNELS;i++)
    {
      Mask = ((uint32_t)1U) << i;
      if(Reg & Mask) 
      {
        ch_index = i;
        break;
      }
    }
    /* increment the block count */
    Handle->Ch[ch_index].BlockCnt++;
    /* Mask all channel interrupts */
    Reg = ( ((uint32_t)1U) << (ch_index + DMA0_MAX_CHANNELS));
    DMARegs->MASKTFR      = Reg;
    DMARegs->MASKBLOCK    = Reg;
    DMARegs->MASKSRCTRAN  = Reg;
    DMARegs->MASKDSTTRAN  = Reg;
    DMARegs->MASKERR      = Reg;
    
    // DBG002_INFO(APP_GID,NVIC_DMA001_TFR_INT, 0, NULL);
    /* run the listener function */
    if(Handle->Ch[ch_index].CbListener != NULL)
    {
      UserCallback = Handle->Ch[ch_index].CbListener;
      callbackArg = Handle->Ch[ch_index].CbArg;
      UserCallback(DMA_IRQ_TFR, callbackArg);
    }
    /* reset the source and destination states */
    Handle->Ch[ch_index].SrcState = NVIC_DMA001_IDLE;
    Handle->Ch[ch_index].DstState = NVIC_DMA001_IDLE;
    /* Disable all channel interrupts */
    /* clear any pending block/srcTran/dstTran interrupts */
    DMARegs->CLEARBLOCK   = Mask;
    DMARegs->CLEARSRCTRAN = Mask; 
    DMARegs->CLEARDSTTRAN = Mask;
    DMARegs->CLEARTFR     = Mask;
  }    
  /* BLOCK INTERRUPT */
  else if(RD_REG(IrqActive,GPDMA0_STATUSINT_BLOCK_Msk, GPDMA0_STATUSINT_BLOCK_Pos)) 
  {
    /* Read the Block Status Register */
    Reg = DMARegs->STATUSBLOCK;
    /* Loop through the channels until we find active interrupt.*/
    for(i=0U;i< DMA0_MAX_CHANNELS;i++)
    {
      Mask = ((uint32_t)1U) << i;
      if(Reg & Mask) 
      {
        ch_index = i;
        break;
      }
    }

    /* increment the block count */
    Handle->Ch[ch_index].BlockCnt++;
    // DBG002_INFO(APP_GID,NVIC_DMA001_BLOCK_INT, 0, NULL);
    /* run the listener function */
    if(Handle->Ch[ch_index].CbListener != NULL)
    {
      UserCallback = Handle->Ch[ch_index].CbListener;
      callbackArg = Handle->Ch[ch_index].CbArg;
      UserCallback(DMA_IRQ_BLOCK, callbackArg);
    }
    /* reset the source and destination states */
    Handle->Ch[ch_index].SrcState = NVIC_DMA001_BURST_REGION;
    Handle->Ch[ch_index].DstState = NVIC_DMA001_BURST_REGION;
    /* clear any pending srcTran/dstTran interrupts */
    DMARegs->CLEARSRCTRAN = Mask; 
    DMARegs->CLEARDSTTRAN = Mask;
    /* clear the block interrupt */
    DMARegs->CLEARBLOCK = Mask;
  }	 
  /* SRCTRAN INTERRUPT */
  else if(RD_REG(IrqActive,GPDMA0_STATUSINT_SRCT_Msk, GPDMA0_STATUSINT_SRCT_Pos))
  {
    Reg = DMARegs->STATUSSRCTRAN;
    /* Loop through the channels until we find active interrupt.  */
    for(i=0U;i< DMA0_MAX_CHANNELS;i++)
    {
      Mask = ((uint32_t)1U) << i;
      if(Reg & Mask) 
      {
        ch_index = i;
        break;
      }
    }
    // DBG002_INFO(APP_GID,NVIC_DMA001_SRCTRAN_INT, 0, NULL);
    if(Handle->Ch[ch_index].CbListener != NULL)
    {
      UserCallback = Handle->Ch[ch_index].CbListener;
      callbackArg = Handle->Ch[ch_index].CbArg;
      UserCallback(DMA_IRQ_SRCTRAN, callbackArg);
    }
    /* clear the interrupt */
    DMARegs->CLEARSRCTRAN = Mask;
  }
  /* DSTTRAN INTERRUPT */
  else if(RD_REG(IrqActive,GPDMA0_STATUSINT_DSTT_Msk, GPDMA0_STATUSINT_DSTT_Pos))
  {
    Reg = DMARegs->STATUSDSTTRAN;
    /* Loop through the channels until we find active interrupt */
    for(i=0U;i< DMA0_MAX_CHANNELS;i++)
    {
      Mask = ((uint32_t)1U) << i;
      if(Reg & Mask) 
      {
        ch_index = i;
        break;
      }
    }
    // DBG002_INFO(APP_GID,NVIC_DMA001_DSTTRAN_INT, 0, NULL);
    /* run the listener function */
    if(Handle->Ch[ch_index].CbListener != NULL)
    {
      UserCallback = Handle->Ch[ch_index].CbListener;
      callbackArg = Handle->Ch[ch_index].CbArg;
      UserCallback(DMA_IRQ_DSTTRAN, callbackArg);
    }
    /* clear the interrupt */
    DMARegs->CLEARDSTTRAN = Mask;
  }
  else
  {
    /* If we've reached this point, either the enabling and
     * disabling of DMA interrupts is not being handled
     * properly or this function is being called unnecessarily.
     */
  }
}



