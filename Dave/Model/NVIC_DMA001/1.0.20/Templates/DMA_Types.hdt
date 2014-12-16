/**************************************************************************//**
 *
 * Copyright (C) 2012 Infineon Technologies AG. All rights reserved.
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
** PLATFORM : Infineon XMC4XXX Series                                                **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR : $Author                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/Yes]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Feb 11, 2013                                           **
**                                                                            **
*******************************************************************************/
/**
 * @file DMA_Types.h
 *
 * @brief  File which defines the DMA enum types shared by        different DMA Apps.
 *
 */
/*
 * Revision History
 * 18 Jan 2013 v1.0.11 Initial version
 * 11 Feb 2013 V1.0.12 Channel priority bug fix
 */

#ifndef DMA_TYPES_H_
#define DMA_TYPES_H_

#ifdef  __cplusplus
extern "C"
{
#endif

/*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define DMA_MAX_CHANNELS    8UL

#define DMA_GET_STATUS(ErrorCode)  (-ErrorCode)
/* Macro to convert to Synopsys representation*/
#define DMA_CH_NUM(ch) (uint32_t)((uint32_t)(1UL << (DMA_MAX_CHANNELS + ch)) | (uint32_t)(1UL << ch))

#define DMA_CTLL_DST_WIDTH(n)   ((uint32_t)(n)<<1)    /* bytes per element*/
#define DMA_CTLL_SRC_WIDTH(n)   ((uint32_t)(n)<<4)	  /* bytes per element*/
#define DMA_CTLL_DST_INC(n)     ((uint32_t)(n)<<7)    /* DAR update/not */
#define DMA_CTLL_SRC_INC(n)     ((uint32_t)(n)<<9)    /* SAR update/not */
#define DMA_CTLL_DST_MSIZE(n)   ((uint32_t)(n)<<11)   /* burst, #elements*/
#define DMA_CTLL_SRC_MSIZE(n)   ((uint32_t)(n)<<14)	  /* burst, #elements*/
#define DMA_CTLL_FC(n)          ((uint32_t)(n)<< 20)  /* flow control */
#define DMA_CTLL_DMS(n)         ((uint32_t)(n)<< 23)  /* dst master select */
#define DMA_CTLL_SMS(n)         ((uint32_t)(n)<< 25)  /* src master select */
#define DMA_CFGL_CH_PRIOR(n)    ((uint32_t)(n)<<5)    /* Channel Priority */
#define DMA_CTLL_LLP_D_EN       ((uint32_t)1UL << 27)   /* dest block chain */
#define DMA_CTLL_LLP_S_EN       ((uint32_t)1UL << 28)   /* src block chain */
#define DMA_CTLL_INT_EN         ((uint32_t)1UL << 0)    /* irqs enabled? */
#define DMA_CTLL_S_GATH_EN      ((uint32_t)1UL << 17)   /* src gather */
#define DMA_CTLL_D_SCAT_EN      ((uint32_t)1UL << 18)   /* dst scatter*/
#define DMA_CFGL_SET_HS_SRC(reg) (reg) &= (uint32_t)~(1UL<<11)   /* src hw handshaking */
#define DMA_CFGL_SET_HS_DST(reg) (reg) &= (uint32_t)~(1UL<<10)   /* dst hw handshaking */
#define DMA_CFGL_CH_PRIOR_Pos        ((uint32_t)0x5UL)   /*!<  CFGL: CH_PRIOR Position    */
#define DMA_CFGL_CH_PRIOR_Msk        ((uint32_t)0x07UL << DMA_CFGL_CH_PRIOR_Pos)              /*!<  CFGL: CH_PRIOR Mask        */


 
 /* Bitfields in SGR */
#define DMA_SGR_SGI(x)          (uint32_t)((uint32_t)(x) << 0)
#define DMA_SGR_SGC(x)          (uint32_t)((uint32_t)(x) << 20)

/* Bitfields in DSR */
#define DMA_DSR_DSI(x)          (uint32_t)((uint32_t)(x) << 0)
#define DMA_DSR_DSC(x)          (uint32_t)((uint32_t)(x) << 20)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/**
 * @ingroup DMA_publicparam
 * @{
 */

 
/**
 * @brief   Datatype to select the DMA IRQ Type.
 *
 */

typedef enum DMA_IRQType
{
  DMA_IRQ_NONE       = 0x00,     /** no interrupts*/
  DMA_IRQ_TFR        = 0x01,     /** transfer complete*/
  DMA_IRQ_BLOCK      = 0x02,     /** block transfer complete*/
  DMA_IRQ_SRCTRAN    = 0x04,     /** source transaction complete*/
  DMA_IRQ_DSTTRAN    = 0x08,     /** destination transaction complete*/
  DMA_IRQ_ERR        = 0x10,     /** error*/
  DMA_IRQ_ALL        = 0x1f      /** all interrupts*/
}DMA_IRQType; 
 
/**
 * @brief   DMA UserListener Callback function prototype
 */
typedef void (*DMACallbackType)(DMA_IRQType IRQType, uint32_t CbArg);
 
/**
 * @brief   This data type is used in Std and Advanced DMA Apps
 *          as function return codes
 */
typedef enum DMA_StatusType
{
  DMA_EPERM    = 1 , /** operation not permitted */
  DMA_EIO      = 5 , /** I/O error */
  DMA_ENXIO    = 6 , /** no such device or address */
  DMA_ENOMEM   = 12, /** out of memory */  
  DMA_EACCES   = 13, /** permission denied */
  DMA_EBUSY    = 16, /** device or resource busy */
  DMA_ENODEV   = 19, /** no such device */
  DMA_EINVAL   = 22, /** invalid argument */
  DMA_ENOSPC   = 28, /** no space left on device */
  DMA_ENOSYS   = 38, /** function not implemented/supported */
  DMA_ECHRNG   = 44, /** channel number out of range */
  DMA_ENODATA  = 61, /** no data available */  
  DMA_ETIME    = 62, /** timer expired */
  DMA_EPROTO   = 71, /** protocol error */
  DMA_FUN_ENTRY = 90,/** Function enter log */
  DMA_FUN_EXIT = 91  /** Function exit log */
}DMA_StatusType; 
 
/**
 * @brief   This data type is used for selecting the transfer flow device
 *          (memory or peripheral device) and for setting the flow control
 *          device for the DMA transfer.
 *          This data type relates directly to the following DMA Controller
 *          register(s) / bit field(s): (x = channel number)
 *          - CTLx.TT_FC
 */
typedef enum DMA_TransferFlowType
{
  DMA_MEM2MEM_DMA    = 0x0, /** mem to mem - DMAC   flow ctlr */
  DMA_MEM2PRF_DMA    = 0x1, /** mem to prf - DMAC   flow ctlr */
  DMA_PRF2MEM_DMA    = 0x2, /** prf to mem - DMAC   flow ctlr */
  DMA_PRF2MEM_PRF    = 0x4, /** prf to mem - periph flow ctlr */
  DMA_MEM2PRF_PRF    = 0x6  /** mem to prf - periph flow ctlr */
}DMA_TransferFlowType;

/**
 * @brief  This data type is used for selecting the priority level of a DMA
 *         channel.
 *         This data type relates directly to the following DMA Controller
 *         register(s)/bit field(s): (x = channel number)
 *         - CFGx.CH_PRIOR
 */
typedef enum DMA_ChPriorityType
{
  DMA_PRIORITY_0 = 0x0,
  DMA_PRIORITY_1 = 0x1,
  DMA_PRIORITY_2 = 0x2,
  DMA_PRIORITY_3 = 0x3,
  DMA_PRIORITY_4 = 0x4,
  DMA_PRIORITY_5 = 0x5,
  DMA_PRIORITY_6 = 0x6,
  DMA_PRIORITY_7 = 0x7
}DMA_ChPriorityType;

/**
 * @brief  This data type is used for selecting the transfer width for the
 *         source and/or destination on a DMA channel. 
 *         This data type relates directly to the following DMA Controller
 *         register(s) / bit field(s): (x = channel number)
 *         - CTLx.SRC_TR_WIDTH, CTLx.DST_TR_WIDTH
 */
typedef enum DMA_TransferWidthType
{
  DMA_TRANS_WIDTH_8   = 0x0,
  DMA_TRANS_WIDTH_16  = 0x1,
  DMA_TRANS_WIDTH_32  = 0x2,
  DMA_TRANS_WIDTH_64  = 0x3,
  DMA_TRANS_WIDTH_128 = 0x4,
  DMA_TRANS_WIDTH_256 = 0x5
}DMA_TransferWidthType;

/**
 * @brief   This data type is used for selecting the address increment
 *          type for the source and/or destination on a DMA channel.
 *          This data type relates directly to the following DMA Controller
 *          register(s) / bit-field(s): (x = channel number)
 *          - CTLx.SINC, CTLx.DINC
 */
typedef enum DMA_AddrIncType {
  DMA_ADDR_INCREMENT = 0x0,
  DMA_ADDR_DECREMENT = 0x1,
  DMA_ADDR_NOCHANGE  = 0x2
}DMA_AddrIncType;
 
/**
 * @brief  This data type is used for selecting the burst transfer length
 *         on the source and/or destination of a DMA channel.
 *          This data type relates directly to the following DMA Controller
 *         register(s) / bit field(s): (x = channel number)
 *         - CTLx.SRC_MSIZE, CTLx.DEST_MSIZE
 */
typedef enum DMA_BurstTransLenType {
  DMA_MSIZE_1   = 0x0,
  DMA_MSIZE_4   = 0x1,
  DMA_MSIZE_8   = 0x2,
  DMA_MSIZE_16  = 0x3,
  DMA_MSIZE_32  = 0x4,
  DMA_MSIZE_64  = 0x5,
  DMA_MSIZE_128 = 0x6,
  DMA_MSIZE_256 = 0x7
}DMA_BurstTransLenType;



/**
 * @brief This data structure is used for selecting the
 * transfer type for a specified DMA channel when using
 * the specified driver API functions.
 *
 */
typedef enum DMA_TransferType
{
  DMA_SINGLE_BLOCK  = 0x1, /** single block or last multi-block */
                          /**  no write back                   */
  DMA_MULTIBLOCK_RELOAD_DAR  = 0x2, /** multi-block auto-reload DAR      */
                                    /**  contiguous SAR no write back    */
  DMA_MULTIBLOCK_RELOAD_SAR  = 0x3, /** multi-block auto reload SAR      */
                                    /**  contiguous DAR no write back    */
  DMA_MULTIBLOCK_RELOAD_SAR_DAR  = 0x4, /** multi-block auto-reload SAR DAR  */
                                    /**  no write back                   */
  DMA_LAST_MULTIBLOCK  = 0x5,       /** single block or last multi-block */
                                    /**  with write back                 */
  DMA_LLIST_DAR_CONT_SAR  = 0x6,    /** multi-block linked list DAR      */
                                    /**  contiguous SAR with write back  */
  DMA_LLIST_DAR_RELOAD_SAR  = 0x7,  /** multi-block linked list DAR auto */
                                    /**  reload SAR  with write back     */
  DMA_LLIST_SAR_CONT_DAR  = 0x8,    /** multi-block linked list SAR      */
                                    /**  contiguous DAR with write back  */
  DMA_LLIST_SAR_RELOAD_DAR  = 0x9,  /** multi-block linked list SAR auto */
                                    /**  reload DAR with write back      */
  DMA_LLIST_SAR_DAR = 0xa           /** multi-block linked list SAR DAR  */
                                    /**  with write back  */
}DMA_TransferType;

/**
 * @brief This data structure is used to select the source or the
 *  destination for a specific DMA channel when using SW Handshaking Trigger
 */
typedef enum DMA_SWRequestType {
  DMA_SRC_BURST  = 0x0,
  DMA_SRC_SINGLE = 0x1,
  DMA_DST_BURST  = 0x2,
  DMA_DST_SINGLE = 0x3  
}DMA_SWRequestType;

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

#ifdef  __cplusplus
}
#endif

#endif /* DMA_TYPES_H_ */
