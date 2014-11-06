/*******************************************************************************
**  DAVE App Name : ADC002       App Version: 1.0.26               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/

/*CODE_BLOCK_BEGIN[ADC002_Conf.c]*/

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
**                                                                            **
** PLATFORM : Infineon XMC4000/XMC1000 Series                                 **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : DAVE App Developer                                              **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Oct 31, 2013                                           **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** KM           DAVE App Developer                                            **
*******************************************************************************/
/**
 * @file  ADC002_Conf.c
 * @App Version ADC002 <1.0.26>
 * @brief This file contains App parameter data as per GUI configurations
 * Change History:
 * Date         version      Details
 * 12-Dec-2012   1.0.6    Initial code added for XMC1000
 * 30-Jan-2013   1.0.8    App version changed
 * 24-Apr-2013   1.0.12   Ported to XMC4500 step AB.
 *                        Source Result selection Feature added
 * 10-Jun-2013   1.0.14   1. Integer Parameter updated in manifest to support
 *                           PMSMFOCSL01 app. 
 *                        2. In the Header comment section device name changed
 *                           to XMC1000
 *                        3. Source Result register selection feature disabled
 *                           due to header file update not available.
 * 27-Jun-2013   1.0.16   Source Result register selection feature removed to
 *                        simplify the app.       
 * 10-Sep-2013   1.0.18   1. Arbitration slot enable(ASEN) code is moved to the
 *                        end of ADC002_lInit function. 
 *                        2. Added support for the following devices under 
 *                        XMC1200 and XMC1300 Series XMC1201, XMC1202, XMC1301.
 * 27-Sep-2013   1.0.20   ADC002_InitializeQueue api issue - the queue is not 
 *                        created if interrupt is enabled is fixed.
 * 31-Oct-2013   1.0.22   '10 bit Fast compare mode' is made invisible in GUI for
 *                        standard conversion mode.    
 */
 
#include <DAVE3.h>



ADC002_QueueEntryHandleType ADC002_QueueEntryHandle0[8] = {

  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)5,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)0,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)7,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)6,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
};


ADC002_DynamicDataType ADC002_DynamicHandle0 =
{
  .State = ADC002_UNINITIALIZED
};


const ADC002_HandleType ADC002_Handle0 =
{
  .kGroupNo = (uint8_t)0,
  .kNChannels = (uint8_t)4,
  .kAsenEnable = (uint8_t)ADC002_ARBITRATION_SLOT_ENABLE,
  .kStart = (uint8_t)ADC002_START_CONV_ENABLE,
  .kPriority = (uint8_t)ADC002_PRIORITY0,
  .kStartmode = (uint8_t)ADC002_WAIT_FOR_START,
  .kTriggerMode = (uint8_t)ADC002_NOTRIGGER,
  .kTriggerEn = (uint8_t)0,
  .kGatingMode = (uint8_t)ADC002_GATING_ENABLED_ALWAYS,     
  .kChannelA = (uint8_t)5,
  .kChAHandlerPtr = &ADCCH001_Handle0,
  .kChannelB = (uint8_t)0,
  .kChBHandlerPtr = &ADCCH001_Handle6,
  .kChannelC = (uint8_t)7,
  .kChCHandlerPtr = &ADCCH001_Handle5,
  .kChannelD = (uint8_t)6,
  .kChDHandlerPtr = &ADCCH001_Handle4,
  .kChannelE = (uint8_t)8,
  .kChEHandlerPtr =  NULL,
  .kChannelF = (uint8_t)8,
  .kChFHandlerPtr = NULL,
  .kChannelG = (uint8_t)8,
  .kChGHandlerPtr = NULL,
  .kChannelH = (uint8_t)8,
  .kChHHandlerPtr = NULL,
  .kSyncChPtr= NULL,
  .kSyncChannelA = (uint8_t)8,
  .kSyncChannelB = (uint8_t)8,
  .kSyncChannelC = (uint8_t)8,
  .kSyncChannelD = (uint8_t)8,
  .kSyncChannelE = (uint8_t)8,
  .kSyncChannelF = (uint8_t)8,
  .kSyncChannelG = (uint8_t)8,
  .kSyncChannelH = (uint8_t)8, 
  .kActiveChannels = {(uint8_t)1, 
              (uint8_t)0, 
              (uint8_t)0, 
              (uint8_t)0, 
              (uint8_t)0, 
              (uint8_t)1, 
              (uint8_t)1, 
              (uint8_t)1 },
  .kQueueEntryHandlePtr =  &ADC002_QueueEntryHandle0[0],
  .kGroup_HandlePtr = &ADCGROUP001_Handle0,
  .VADCGlobalPtr= (VADC_GLOBAL_TypeDef*)(void*)VADC,
  .VADCGroupPtr= (VADC_G_TypeDef*)(void*) VADC_G0,
  .DynamicHandlePtr= &ADC002_DynamicHandle0
 };

ADC002_QueueEntryHandleType ADC002_QueueEntryHandle1[8] = {

  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)4,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)6,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)3,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)5,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
};


ADC002_DynamicDataType ADC002_DynamicHandle1 =
{
  .State = ADC002_UNINITIALIZED
};


const ADC002_HandleType ADC002_Handle1 =
{
  .kGroupNo = (uint8_t)3,
  .kNChannels = (uint8_t)4,
  .kAsenEnable = (uint8_t)ADC002_ARBITRATION_SLOT_ENABLE,
  .kStart = (uint8_t)ADC002_START_CONV_ENABLE,
  .kPriority = (uint8_t)ADC002_PRIORITY0,
  .kStartmode = (uint8_t)ADC002_WAIT_FOR_START,
  .kTriggerMode = (uint8_t)ADC002_NOTRIGGER,
  .kTriggerEn = (uint8_t)0,
  .kGatingMode = (uint8_t)ADC002_GATING_ENABLED_ALWAYS,     
  .kChannelA = (uint8_t)4,
  .kChAHandlerPtr = &ADCCH001_Handle1,
  .kChannelB = (uint8_t)6,
  .kChBHandlerPtr = &ADCCH001_Handle8,
  .kChannelC = (uint8_t)3,
  .kChCHandlerPtr = &ADCCH001_Handle9,
  .kChannelD = (uint8_t)5,
  .kChDHandlerPtr = &ADCCH001_Handle7,
  .kChannelE = (uint8_t)8,
  .kChEHandlerPtr =  NULL,
  .kChannelF = (uint8_t)8,
  .kChFHandlerPtr = NULL,
  .kChannelG = (uint8_t)8,
  .kChGHandlerPtr = NULL,
  .kChannelH = (uint8_t)8,
  .kChHHandlerPtr = NULL,
  .kSyncChPtr= NULL,
  .kSyncChannelA = (uint8_t)8,
  .kSyncChannelB = (uint8_t)8,
  .kSyncChannelC = (uint8_t)8,
  .kSyncChannelD = (uint8_t)8,
  .kSyncChannelE = (uint8_t)8,
  .kSyncChannelF = (uint8_t)8,
  .kSyncChannelG = (uint8_t)8,
  .kSyncChannelH = (uint8_t)8, 
  .kActiveChannels = {(uint8_t)0, 
              (uint8_t)0, 
              (uint8_t)0, 
              (uint8_t)1, 
              (uint8_t)1, 
              (uint8_t)1, 
              (uint8_t)1, 
              (uint8_t)0 },
  .kQueueEntryHandlePtr =  &ADC002_QueueEntryHandle1[0],
  .kGroup_HandlePtr = &ADCGROUP001_Handle1,
  .VADCGlobalPtr= (VADC_GLOBAL_TypeDef*)(void*)VADC,
  .VADCGroupPtr= (VADC_G_TypeDef*)(void*) VADC_G3,
  .DynamicHandlePtr= &ADC002_DynamicHandle1
 };

ADC002_QueueEntryHandleType ADC002_QueueEntryHandle2[8] = {

  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)2,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)4,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)6,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)5,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)3,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)7,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
};


ADC002_DynamicDataType ADC002_DynamicHandle2 =
{
  .State = ADC002_UNINITIALIZED
};


const ADC002_HandleType ADC002_Handle2 =
{
  .kGroupNo = (uint8_t)2,
  .kNChannels = (uint8_t)6,
  .kAsenEnable = (uint8_t)ADC002_ARBITRATION_SLOT_ENABLE,
  .kStart = (uint8_t)ADC002_START_CONV_ENABLE,
  .kPriority = (uint8_t)ADC002_PRIORITY0,
  .kStartmode = (uint8_t)ADC002_WAIT_FOR_START,
  .kTriggerMode = (uint8_t)ADC002_NOTRIGGER,
  .kTriggerEn = (uint8_t)0,
  .kGatingMode = (uint8_t)ADC002_GATING_ENABLED_ALWAYS,     
  .kChannelA = (uint8_t)2,
  .kChAHandlerPtr = &ADCCH001_Handle2,
  .kChannelB = (uint8_t)4,
  .kChBHandlerPtr = &ADCCH001_Handle14,
  .kChannelC = (uint8_t)6,
  .kChCHandlerPtr = &ADCCH001_Handle12,
  .kChannelD = (uint8_t)5,
  .kChDHandlerPtr = &ADCCH001_Handle11,
  .kChannelE = (uint8_t)3,
  .kChEHandlerPtr = &ADCCH001_Handle13,
  .kChannelF = (uint8_t)7,
  .kChFHandlerPtr = &ADCCH001_Handle10,
  .kChannelG = (uint8_t)8,
  .kChGHandlerPtr = NULL,
  .kChannelH = (uint8_t)8,
  .kChHHandlerPtr = NULL,
  .kSyncChPtr= NULL,
  .kSyncChannelA = (uint8_t)8,
  .kSyncChannelB = (uint8_t)8,
  .kSyncChannelC = (uint8_t)8,
  .kSyncChannelD = (uint8_t)8,
  .kSyncChannelE = (uint8_t)8,
  .kSyncChannelF = (uint8_t)8,
  .kSyncChannelG = (uint8_t)8,
  .kSyncChannelH = (uint8_t)8, 
  .kActiveChannels = {(uint8_t)0, 
              (uint8_t)0, 
              (uint8_t)1, 
              (uint8_t)1, 
              (uint8_t)1, 
              (uint8_t)1, 
              (uint8_t)1, 
              (uint8_t)1 },
  .kQueueEntryHandlePtr =  &ADC002_QueueEntryHandle2[0],
  .kGroup_HandlePtr = &ADCGROUP001_Handle2,
  .VADCGlobalPtr= (VADC_GLOBAL_TypeDef*)(void*)VADC,
  .VADCGroupPtr= (VADC_G_TypeDef*)(void*) VADC_G2,
  .DynamicHandlePtr= &ADC002_DynamicHandle2
 };

ADC002_QueueEntryHandleType ADC002_QueueEntryHandle3[8] = {

  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)7,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)4,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)2,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)6,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)5,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_ACTIVE,
    .ChannelNumber = (uint8_t)3,  
    .Refill = (uint8_t) ADC002_REFILL_ENABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
  {
    .Active = (uint8_t)ADC002_ENTRY_INACTIVE,
    .ChannelNumber = (uint8_t)8,  
    .Refill = (uint8_t) ADC002_REFILL_DISABLE , 
    .ExternalTrigger = (uint8_t) ADC002_EXT_TRIGGER_DISABLE ,  
    .Interrupt = (uint8_t) ADC002_INTERRUPT_DISABLE , 
  },
};


ADC002_DynamicDataType ADC002_DynamicHandle3 =
{
  .State = ADC002_UNINITIALIZED
};


const ADC002_HandleType ADC002_Handle3 =
{
  .kGroupNo = (uint8_t)1,
  .kNChannels = (uint8_t)6,
  .kAsenEnable = (uint8_t)ADC002_ARBITRATION_SLOT_ENABLE,
  .kStart = (uint8_t)ADC002_START_CONV_ENABLE,
  .kPriority = (uint8_t)ADC002_PRIORITY0,
  .kStartmode = (uint8_t)ADC002_WAIT_FOR_START,
  .kTriggerMode = (uint8_t)ADC002_NOTRIGGER,
  .kTriggerEn = (uint8_t)0,
  .kGatingMode = (uint8_t)ADC002_GATING_ENABLED_ALWAYS,     
  .kChannelA = (uint8_t)7,
  .kChAHandlerPtr = &ADCCH001_Handle3,
  .kChannelB = (uint8_t)4,
  .kChBHandlerPtr = &ADCCH001_Handle15,
  .kChannelC = (uint8_t)2,
  .kChCHandlerPtr = &ADCCH001_Handle18,
  .kChannelD = (uint8_t)6,
  .kChDHandlerPtr = &ADCCH001_Handle16,
  .kChannelE = (uint8_t)5,
  .kChEHandlerPtr = &ADCCH001_Handle19,
  .kChannelF = (uint8_t)3,
  .kChFHandlerPtr = &ADCCH001_Handle17,
  .kChannelG = (uint8_t)8,
  .kChGHandlerPtr = NULL,
  .kChannelH = (uint8_t)8,
  .kChHHandlerPtr = NULL,
  .kSyncChPtr= NULL,
  .kSyncChannelA = (uint8_t)8,
  .kSyncChannelB = (uint8_t)8,
  .kSyncChannelC = (uint8_t)8,
  .kSyncChannelD = (uint8_t)8,
  .kSyncChannelE = (uint8_t)8,
  .kSyncChannelF = (uint8_t)8,
  .kSyncChannelG = (uint8_t)8,
  .kSyncChannelH = (uint8_t)8, 
  .kActiveChannels = {(uint8_t)0, 
              (uint8_t)0, 
              (uint8_t)1, 
              (uint8_t)1, 
              (uint8_t)1, 
              (uint8_t)1, 
              (uint8_t)1, 
              (uint8_t)1 },
  .kQueueEntryHandlePtr =  &ADC002_QueueEntryHandle3[0],
  .kGroup_HandlePtr = &ADCGROUP001_Handle3,
  .VADCGlobalPtr= (VADC_GLOBAL_TypeDef*)(void*)VADC,
  .VADCGroupPtr= (VADC_G_TypeDef*)(void*) VADC_G1,
  .DynamicHandlePtr= &ADC002_DynamicHandle3
 };






