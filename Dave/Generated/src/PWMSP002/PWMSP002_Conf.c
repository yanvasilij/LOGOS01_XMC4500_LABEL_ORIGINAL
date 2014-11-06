/*******************************************************************************
**  DAVE App Name : PWMSP002       App Version: 1.0.32               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/


/*CODE_BLOCK_BEGIN[PWMSP002Conf.c]*/

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
** PLATFORM : Infineon XMC4000/XMC1000 Series                                 **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : DAVE App Developer                                              **
**                                                                            **
** MAY BE CHANGED BY USER [yes/Yes]: Yes                                      **
**                                                                            **
** MODIFICATION DATE : December 01, 2012                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** KS           DAVE App Developer                                            **
*******************************************************************************/
/**
 * @file  PWMSP002_Conf.c
 * @App Version <1.0.32>
 * @brief This file contains App parameter data as per GUI configurations
 *
 */
/* Revision History
 * 01 Dec 2012   v1.0.16   taken as base version
 */
#include <DAVE3.h>

   





PWMSP002_DynamicHandleType PWMSP002_DynamicHandle0 =
{
.State = PWMSP002_UNINITIALIZED
};

const PWMSP002_HandleType PWMSP002_Handle0 =
{

  .kTimerMode= 0U,
  .CompareMode= CCU8PWMLIB_SYMMETRIC,
  .CountingMode= CCU8PWMLIB_EDGE_ALIGNED,
  
  .kPassiveState0= 0U,
  .kPassiveState1= 1U,
  .kPassiveLevel0= 0U,
  .kPassiveLevel1= 0U,
  

  .kExtStartTrig=  0U, 
  .kExtStopTrig=  0U, 
  .kStartEdge=  CCU8PWMLIB_NOTRIGGER,
  .kStopEdge=  CCU8PWMLIB_NOTRIGGER,  
  .ExtStartConfig=  CCU8PWMLIB_START_TIMER,    
  .ExtStopConfig=  CCU8PWMLIB_CLEAR_STOP_TIMER,  

  .kTrapEnable= 1U,
  .kTrapSync= 1U,
  .kTrapExitControl= 1U,
  .kTrapLevel= 0U,
  
  .kResolution = (float)16.667,
  .kCCUPrescalar= 1U,
  .kTimerConcatenation= 0U,
  .kCompareValue1= 3333U,
  .kCompareValue2 = 0U,
  .kPeriodVal= 3332U,
  
  .kFallingDeadTime = 9U,
  .kRisingDeadTime= 9U,
  .kDeadTimePrescalar= 0U,
  .DeadTimeConf=  CCU8PWMLIB_ENABLE, 
  
  .kDitherSetting= 0U,
  .kDitherCompare = 0U,

  .ShadowTransfer= 1U,
  .ShadowTransferMask=  0x01U,   
  .Start= 1U,
  .StartMask=  0x01U,   
  
  .FirstSlice=  CCU8PWMLIB_SLICE0 ,
  .SecondSlice= CCU8PWMLIB_SLICE0,
  .CC8yKernRegsPtr= (CCU8_GLOBAL_TypeDef*) CCU80_BASE,
  .CC8yRegsPtr= CCU80_CC80,
  .CC8yRegs1Ptr= CCU80_CC80,
  .DynamicHandleType= &PWMSP002_DynamicHandle0,
  .StartControl = 1U,
  .InterruptControl = 0x0U,
  .SetCompareFuncPtr = &CCU8PWMLIB_SetCompareSymmetric,
  .SetDutyFuncPtr = &CCU8PWMLIB_SetDutyEdgeAlignSymmetric,

};  
  



PWMSP002_DynamicHandleType PWMSP002_DynamicHandle1 =
{
.State = PWMSP002_UNINITIALIZED
};

const PWMSP002_HandleType PWMSP002_Handle1 =
{

  .kTimerMode= 0U,
  .CompareMode= CCU8PWMLIB_SYMMETRIC,
  .CountingMode= CCU8PWMLIB_EDGE_ALIGNED,
  
  .kPassiveState0= 0U,
  .kPassiveState1= 1U,
  .kPassiveLevel0= 0U,
  .kPassiveLevel1= 0U,
  

  .kExtStartTrig=  0U, 
  .kExtStopTrig=  0U, 
  .kStartEdge=  CCU8PWMLIB_NOTRIGGER,
  .kStopEdge=  CCU8PWMLIB_NOTRIGGER,  
  .ExtStartConfig=  CCU8PWMLIB_START_TIMER,  
  .ExtStopConfig=  CCU8PWMLIB_STOP_TIMER,  

  .kTrapEnable= 1U,
  .kTrapSync= 1U,
  .kTrapExitControl= 1U,
  .kTrapLevel= 0U,
  
  .kResolution = (float)16.667,
  .kCCUPrescalar= 1U,
  .kTimerConcatenation= 0U,
  .kCompareValue1= 3333U,
  .kCompareValue2 = 0U,
  .kPeriodVal= 3332U,
  
  .kFallingDeadTime = 9U,
  .kRisingDeadTime= 9U,
  .kDeadTimePrescalar= 0U,
  .DeadTimeConf=  CCU8PWMLIB_ENABLE, 
  
  .kDitherSetting= 0U,
  .kDitherCompare = 0U,

  .ShadowTransfer= 1U,
  .ShadowTransferMask=  0x10U,   
  .Start= 1U,
  .StartMask=  0x2U,   
  
  .FirstSlice=  CCU8PWMLIB_SLICE1 ,
  .SecondSlice= CCU8PWMLIB_SLICE1,
  .CC8yKernRegsPtr= (CCU8_GLOBAL_TypeDef*) CCU80_BASE,
  .CC8yRegsPtr= CCU80_CC81,
  .CC8yRegs1Ptr= CCU80_CC81,
  .DynamicHandleType= &PWMSP002_DynamicHandle1,
  .StartControl = 1U,
  .InterruptControl = 0x0U,
  .SetCompareFuncPtr = &CCU8PWMLIB_SetCompareSymmetric,
  .SetDutyFuncPtr = &CCU8PWMLIB_SetDutyEdgeAlignSymmetric,

};  
  



PWMSP002_DynamicHandleType PWMSP002_DynamicHandle2 =
{
.State = PWMSP002_UNINITIALIZED
};

const PWMSP002_HandleType PWMSP002_Handle2 =
{

  .kTimerMode= 0U,
  .CompareMode= CCU8PWMLIB_SYMMETRIC,
  .CountingMode= CCU8PWMLIB_EDGE_ALIGNED,
  
  .kPassiveState0= 0U,
  .kPassiveState1= 1U,
  .kPassiveLevel0= 0U,
  .kPassiveLevel1= 0U,
  

  .kExtStartTrig=  0U, 
  .kExtStopTrig=  0U, 
  .kStartEdge=  CCU8PWMLIB_NOTRIGGER,
  .kStopEdge=  CCU8PWMLIB_NOTRIGGER,  
  .ExtStartConfig=  CCU8PWMLIB_START_TIMER,  
  .ExtStopConfig=  CCU8PWMLIB_STOP_TIMER,  

  .kTrapEnable= 1U,
  .kTrapSync= 1U,
  .kTrapExitControl= 1U,
  .kTrapLevel= 0U,
  
  .kResolution = (float)16.667,
  .kCCUPrescalar= 1U,
  .kTimerConcatenation= 0U,
  .kCompareValue1= 3333U,
  .kCompareValue2 = 0U,
  .kPeriodVal= 3332U,
  
  .kFallingDeadTime = 9U,
  .kRisingDeadTime= 9U,
  .kDeadTimePrescalar= 0U,
  .DeadTimeConf=  CCU8PWMLIB_ENABLE, 
  
  .kDitherSetting= 0U,
  .kDitherCompare = 0U,

  .ShadowTransfer= 1U,
  .ShadowTransferMask=  0x100U,   
  .Start= 1U,
  .StartMask=  0x4U,   
  
  .FirstSlice=  CCU8PWMLIB_SLICE2 ,
  .SecondSlice= CCU8PWMLIB_SLICE2,
  .CC8yKernRegsPtr= (CCU8_GLOBAL_TypeDef*) CCU80_BASE,
  .CC8yRegsPtr= CCU80_CC82,
  .CC8yRegs1Ptr= CCU80_CC82,
  .DynamicHandleType= &PWMSP002_DynamicHandle2,
  .StartControl = 1U,
  .InterruptControl = 0x0U,
  .SetCompareFuncPtr = &CCU8PWMLIB_SetCompareSymmetric,
  .SetDutyFuncPtr = &CCU8PWMLIB_SetDutyEdgeAlignSymmetric,

};  
  



PWMSP002_DynamicHandleType PWMSP002_DynamicHandle3 =
{
.State = PWMSP002_UNINITIALIZED
};

const PWMSP002_HandleType PWMSP002_Handle3 =
{

  .kTimerMode= 0U,
  .CompareMode= CCU8PWMLIB_SYMMETRIC,
  .CountingMode= CCU8PWMLIB_EDGE_ALIGNED,
  
  .kPassiveState0= 0U,
  .kPassiveState1= 1U,
  .kPassiveLevel0= 0U,
  .kPassiveLevel1= 0U,
  

  .kExtStartTrig=  0U, 
  .kExtStopTrig=  0U, 
  .kStartEdge=  CCU8PWMLIB_NOTRIGGER,
  .kStopEdge=  CCU8PWMLIB_NOTRIGGER,  
  .ExtStartConfig=  CCU8PWMLIB_START_TIMER,  
  .ExtStopConfig=  CCU8PWMLIB_STOP_TIMER,  

  .kTrapEnable= 1U,
  .kTrapSync= 1U,
  .kTrapExitControl= 1U,
  .kTrapLevel= 0U,
  
  .kResolution = (float)16.667,
  .kCCUPrescalar= 1U,
  .kTimerConcatenation= 0U,
  .kCompareValue1= 3333U,
  .kCompareValue2 = 0U,
  .kPeriodVal= 3332U,
  
  .kFallingDeadTime = 9U,
  .kRisingDeadTime= 9U,
  .kDeadTimePrescalar= 0U,
  .DeadTimeConf=  CCU8PWMLIB_ENABLE, 
  
  .kDitherSetting= 0U,
  .kDitherCompare = 0U,

  .ShadowTransfer= 1U,
  .ShadowTransferMask=  0x1000U,   
  .Start= 1U,
  .StartMask=  0x8U,   
  
  .FirstSlice=  CCU8PWMLIB_SLICE3 ,
  .SecondSlice= CCU8PWMLIB_SLICE3,
  .CC8yKernRegsPtr= (CCU8_GLOBAL_TypeDef*) CCU80_BASE,
  .CC8yRegsPtr= CCU80_CC83,
  .CC8yRegs1Ptr= CCU80_CC83,
  .DynamicHandleType= &PWMSP002_DynamicHandle3,
  .StartControl = 1U,
  .InterruptControl = 0x0U,
  .SetCompareFuncPtr = &CCU8PWMLIB_SetCompareSymmetric,
  .SetDutyFuncPtr = &CCU8PWMLIB_SetDutyEdgeAlignSymmetric,

};  
  



PWMSP002_DynamicHandleType PWMSP002_DynamicHandle4 =
{
.State = PWMSP002_UNINITIALIZED
};

const PWMSP002_HandleType PWMSP002_Handle4 =
{

  .kTimerMode= 0U,
  .CompareMode= CCU8PWMLIB_SYMMETRIC,
  .CountingMode= CCU8PWMLIB_EDGE_ALIGNED,
  
  .kPassiveState0= 0U,
  .kPassiveState1= 1U,
  .kPassiveLevel0= 0U,
  .kPassiveLevel1= 0U,
  

  .kExtStartTrig=  0U, 
  .kExtStopTrig=  0U, 
  .kStartEdge=  CCU8PWMLIB_NOTRIGGER,
  .kStopEdge=  CCU8PWMLIB_NOTRIGGER,  
  .ExtStartConfig=  CCU8PWMLIB_START_TIMER,  
  .ExtStopConfig=  CCU8PWMLIB_STOP_TIMER,  

  .kTrapEnable= 1U,
  .kTrapSync= 1U,
  .kTrapExitControl= 1U,
  .kTrapLevel= 0U,
  
  .kResolution = (float)16.667,
  .kCCUPrescalar= 1U,
  .kTimerConcatenation= 0U,
  .kCompareValue1= 3333U,
  .kCompareValue2 = 0U,
  .kPeriodVal= 3332U,
  
  .kFallingDeadTime = 9U,
  .kRisingDeadTime= 9U,
  .kDeadTimePrescalar= 0U,
  .DeadTimeConf=  CCU8PWMLIB_ENABLE, 
  
  .kDitherSetting= 0U,
  .kDitherCompare = 0U,

  .ShadowTransfer= 1U,
  .ShadowTransferMask=  0x1000U,   
  .Start= 1U,
  .StartMask=  0x8U,   
  
  .FirstSlice=  CCU8PWMLIB_SLICE3 ,
  .SecondSlice= CCU8PWMLIB_SLICE3,
  .CC8yKernRegsPtr= (CCU8_GLOBAL_TypeDef*) CCU81_BASE,
  .CC8yRegsPtr= CCU81_CC83,
  .CC8yRegs1Ptr= CCU81_CC83,
  .DynamicHandleType= &PWMSP002_DynamicHandle4,
  .StartControl = 1U,
  .InterruptControl = 0x0U,
  .SetCompareFuncPtr = &CCU8PWMLIB_SetCompareSymmetric,
  .SetDutyFuncPtr = &CCU8PWMLIB_SetDutyEdgeAlignSymmetric,

};  
  



PWMSP002_DynamicHandleType PWMSP002_DynamicHandle5 =
{
.State = PWMSP002_UNINITIALIZED
};

const PWMSP002_HandleType PWMSP002_Handle5 =
{

  .kTimerMode= 0U,
  .CompareMode= CCU8PWMLIB_SYMMETRIC,
  .CountingMode= CCU8PWMLIB_EDGE_ALIGNED,
  
  .kPassiveState0= 0U,
  .kPassiveState1= 1U,
  .kPassiveLevel0= 0U,
  .kPassiveLevel1= 0U,
  

  .kExtStartTrig=  0U, 
  .kExtStopTrig=  0U, 
  .kStartEdge=  CCU8PWMLIB_NOTRIGGER,
  .kStopEdge=  CCU8PWMLIB_NOTRIGGER,  
  .ExtStartConfig=  CCU8PWMLIB_START_TIMER,  
  .ExtStopConfig=  CCU8PWMLIB_STOP_TIMER,  

  .kTrapEnable= 1U,
  .kTrapSync= 1U,
  .kTrapExitControl= 1U,
  .kTrapLevel= 0U,
  
  .kResolution = (float)16.667,
  .kCCUPrescalar= 1U,
  .kTimerConcatenation= 0U,
  .kCompareValue1= 3333U,
  .kCompareValue2 = 0U,
  .kPeriodVal= 3332U,
  
  .kFallingDeadTime = 9U,
  .kRisingDeadTime= 9U,
  .kDeadTimePrescalar= 0U,
  .DeadTimeConf=  CCU8PWMLIB_ENABLE, 
  
  .kDitherSetting= 0U,
  .kDitherCompare = 0U,

  .ShadowTransfer= 1U,
  .ShadowTransferMask=  0x100U,   
  .Start= 1U,
  .StartMask=  0x4U,   
  
  .FirstSlice=  CCU8PWMLIB_SLICE2 ,
  .SecondSlice= CCU8PWMLIB_SLICE2,
  .CC8yKernRegsPtr= (CCU8_GLOBAL_TypeDef*) CCU81_BASE,
  .CC8yRegsPtr= CCU81_CC82,
  .CC8yRegs1Ptr= CCU81_CC82,
  .DynamicHandleType= &PWMSP002_DynamicHandle5,
  .StartControl = 1U,
  .InterruptControl = 0x0U,
  .SetCompareFuncPtr = &CCU8PWMLIB_SetCompareSymmetric,
  .SetDutyFuncPtr = &CCU8PWMLIB_SetDutyEdgeAlignSymmetric,

};  
  



PWMSP002_DynamicHandleType PWMSP002_DynamicHandle6 =
{
.State = PWMSP002_UNINITIALIZED
};

const PWMSP002_HandleType PWMSP002_Handle6 =
{

  .kTimerMode= 0U,
  .CompareMode= CCU8PWMLIB_SYMMETRIC,
  .CountingMode= CCU8PWMLIB_EDGE_ALIGNED,
  
  .kPassiveState0= 0U,
  .kPassiveState1= 1U,
  .kPassiveLevel0= 0U,
  .kPassiveLevel1= 0U,
  

  .kExtStartTrig=  0U, 
  .kExtStopTrig=  0U, 
  .kStartEdge=  CCU8PWMLIB_NOTRIGGER,
  .kStopEdge=  CCU8PWMLIB_NOTRIGGER,  
  .ExtStartConfig=  CCU8PWMLIB_START_TIMER,  
  .ExtStopConfig=  CCU8PWMLIB_STOP_TIMER,  

  .kTrapEnable= 1U,
  .kTrapSync= 1U,
  .kTrapExitControl= 1U,
  .kTrapLevel= 0U,
  
  .kResolution = (float)16.667,
  .kCCUPrescalar= 1U,
  .kTimerConcatenation= 0U,
  .kCompareValue1= 3333U,
  .kCompareValue2 = 0U,
  .kPeriodVal= 3332U,
  
  .kFallingDeadTime = 9U,
  .kRisingDeadTime= 9U,
  .kDeadTimePrescalar= 0U,
  .DeadTimeConf=  CCU8PWMLIB_ENABLE, 
  
  .kDitherSetting= 0U,
  .kDitherCompare = 0U,

  .ShadowTransfer= 1U,
  .ShadowTransferMask=  0x10U,   
  .Start= 1U,
  .StartMask=  0x2U,   
  
  .FirstSlice=  CCU8PWMLIB_SLICE1 ,
  .SecondSlice= CCU8PWMLIB_SLICE1,
  .CC8yKernRegsPtr= (CCU8_GLOBAL_TypeDef*) CCU81_BASE,
  .CC8yRegsPtr= CCU81_CC81,
  .CC8yRegs1Ptr= CCU81_CC81,
  .DynamicHandleType= &PWMSP002_DynamicHandle6,
  .StartControl = 1U,
  .InterruptControl = 0x0U,
  .SetCompareFuncPtr = &CCU8PWMLIB_SetCompareSymmetric,
  .SetDutyFuncPtr = &CCU8PWMLIB_SetDutyEdgeAlignSymmetric,

};  
  



PWMSP002_DynamicHandleType PWMSP002_DynamicHandle7 =
{
.State = PWMSP002_UNINITIALIZED
};

const PWMSP002_HandleType PWMSP002_Handle7 =
{

  .kTimerMode= 0U,
  .CompareMode= CCU8PWMLIB_SYMMETRIC,
  .CountingMode= CCU8PWMLIB_EDGE_ALIGNED,
  
  .kPassiveState0= 0U,
  .kPassiveState1= 1U,
  .kPassiveLevel0= 0U,
  .kPassiveLevel1= 0U,
  

  .kExtStartTrig=  0U, 
  .kExtStopTrig=  0U, 
  .kStartEdge=  CCU8PWMLIB_NOTRIGGER,
  .kStopEdge=  CCU8PWMLIB_NOTRIGGER,  
  .ExtStartConfig=  CCU8PWMLIB_START_TIMER,  
  .ExtStopConfig=  CCU8PWMLIB_STOP_TIMER,  

  .kTrapEnable= 1U,
  .kTrapSync= 1U,
  .kTrapExitControl= 1U,
  .kTrapLevel= 0U,
  
  .kResolution = (float)16.667,
  .kCCUPrescalar= 1U,
  .kTimerConcatenation= 0U,
  .kCompareValue1= 3333U,
  .kCompareValue2 = 0U,
  .kPeriodVal= 3332U,
  
  .kFallingDeadTime = 9U,
  .kRisingDeadTime= 9U,
  .kDeadTimePrescalar= 0U,
  .DeadTimeConf=  CCU8PWMLIB_ENABLE, 
  
  .kDitherSetting= 0U,
  .kDitherCompare = 0U,

  .ShadowTransfer= 1U,
  .ShadowTransferMask=  0x01U,   
  .Start= 1U,
  .StartMask=  0x01U,   
  
  .FirstSlice=  CCU8PWMLIB_SLICE0 ,
  .SecondSlice= CCU8PWMLIB_SLICE0,
  .CC8yKernRegsPtr= (CCU8_GLOBAL_TypeDef*) CCU81_BASE,
  .CC8yRegsPtr= CCU81_CC80,
  .CC8yRegs1Ptr= CCU81_CC80,
  .DynamicHandleType= &PWMSP002_DynamicHandle7,
  .StartControl = 1U,
  .InterruptControl = 0x0U,
  .SetCompareFuncPtr = &CCU8PWMLIB_SetCompareSymmetric,
  .SetDutyFuncPtr = &CCU8PWMLIB_SetDutyEdgeAlignSymmetric,

};  
  

/**
 * @}
 */
 
/*CODE_BLOCK_END*/

