/* ==========================================================================
 * $File: //dwh/usb_iip/dev/software/otg/linux/drivers/dwc_otg_adp.h $
 * $Revision: #5 $
 * $Date: 2010/11/29 $
 * $Change: 1636033 $
 *
 * Synopsys HS OTG Linux Software Driver and documentation (hereinafter,
 * "Software") is an Unsupported proprietary work of Synopsys, Inc. unless
 * otherwise expressly agreed to in writing between Synopsys and you.
 *
 * The Software IS NOT an item of Licensed Software or Licensed Product under
 * any End User Software License Agreement or Agreement for Licensed Product
 * with Synopsys or any supplement thereto. You are permitted to use and
 * redistribute this Software in source and binary forms, with or without
 * modification, provided that redistributions of source code must retain this
 * notice. You may not view, use, disclose, copy or distribute this file or
 * any information contained herein except pursuant to this license grant from
 * Synopsys. If you do not agree with this notice, including the disclaimer
 * below, then you are not authorized to use the Software.
 *
 * THIS SOFTWARE IS BEING DISTRIBUTED BY SYNOPSYS SOLELY ON AN "AS IS" BASIS
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE HEREBY DISCLAIMED. IN NO EVENT SHALL SYNOPSYS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 * ========================================================================== */
/* THIS FILE IS PROVIDED BY DAVE.
 * THIS FILE IS GENERATED.
 */

/*******************************************************************************
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
** PLATFORM : Infineon XMC4000 Series                                         **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR : App Developer                                                     **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Apr 8, 2012                                            **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials    Name                                                           **
** ---------------------------------------------------------------------------**
** CM          App Developer                                                  **
*******************************************************************************/

#ifndef __DWC_OTG_ADP_H__
#define __DWC_OTG_ADP_H__
#ifdef __cplusplus
extern "C"{
#endif
/**
 * @file
 *
 * This file contains the Attach Detect Protocol interfaces and defines
 * (functions) and structures for Linux.
 *
 */

#define DWC_OTG_ADP_UNATTACHED	0
#define DWC_OTG_ADP_ATTACHED	1
#define DWC_OTG_ADP_UNKOWN	2

typedef struct dwc_otg_adp {
	uint32_t initial_probe;
	int32_t probe_timer_values[2];
	uint32_t probe_enabled;
	uint32_t sense_enabled;
	dwc_timer_t *sense_timer;
	uint32_t sense_timer_started;
	dwc_timer_t *vbuson_timer;
	uint32_t vbuson_timer_started;
	uint32_t attached;
} dwc_otg_adp_t;

/**
 * Attach Detect Protocol functions
 */

extern void dwc_otg_adp_write_reg(dwc_otg_core_if_t * core_if, uint32_t value);
extern uint32_t dwc_otg_adp_read_reg(dwc_otg_core_if_t * core_if);
extern uint32_t dwc_otg_adp_probe_start(dwc_otg_core_if_t * core_if);
extern uint32_t dwc_otg_adp_sense_start(dwc_otg_core_if_t * core_if);
extern uint32_t dwc_otg_adp_probe_stop(dwc_otg_core_if_t * core_if);
extern uint32_t dwc_otg_adp_sense_stop(dwc_otg_core_if_t * core_if);
extern void dwc_otg_adp_start(dwc_otg_core_if_t * core_if);
extern void dwc_otg_adp_init(dwc_otg_core_if_t * core_if);
extern void dwc_otg_adp_remove(dwc_otg_core_if_t * core_if);
extern int32_t dwc_otg_adp_handle_intr(dwc_otg_core_if_t * core_if);
extern int32_t dwc_otg_adp_handle_srp_intr(dwc_otg_core_if_t * core_if);
#ifdef __cplusplus
}
#endif
#endif //__DWC_OTG_ADP_H__
