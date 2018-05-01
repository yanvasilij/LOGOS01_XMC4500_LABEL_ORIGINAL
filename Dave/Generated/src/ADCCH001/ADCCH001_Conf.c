/*******************************************************************************
**  DAVE App Name : ADCCH001       App Version: 1.0.30               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/

/*CODE_BLOCK_BEGIN[ADCCH001_Conf.c]*/
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
** MODIFICATION DATE :  15 Nov 2013                                           **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** PM           DAVE App Developer                                            **
*******************************************************************************/

/**
 * @file ADCCH001_Conf.c
 *
 * @brief This file contains the configuration parameters for all instances of the
 * ADCCH001 App
 *
 * Change History:
 * Date       version       Details
 * 12-Dec-2012   1.0.6    Initial code added for XMC1000
 * 30-Jan-2013   1.0.8    App version changed
 * 24-Apr-2013   1.0.14   Ported to XMC4500 step AB and
 *                        Source Result selection Feature added   
 * 27-Jun-2013   1.0.16   Boundary flag feature supported. 
 *                        In the Header comment section device name changed to
 *                        XMC1000.
 * 29-Aug-2013   1.0.18   Workaround for the boundaryflag registers is removed
 *                        since the registers are available in the header file. 
 * 10-Sep-2013   1.0.20   Added support for the following devices under XMC1200
 *                        and XMC1300 Series XMC1201, XMC1202, XMC1301 
 * 27-Sep-2013   1.0.22   1. ADCCH001_GetEmux api is implemented.
 *                        2. ADCCH001_GetFastResult api is implemented.
 *                        3. Gain Configuration is supported for XMC12/13 Devices. 
 * 29-Oct-2013   1.0.24   1. Reference input name in GUI, Varef is changed to
 *                           Vssc for XMC1200/1300 series devices.
 *                        2. Gain configuration code corrected. 
 * 15-Nov-2013   1.0.26   Document updated.
 */

#include <DAVE3.h>
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle0 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle0 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G0,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle0 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)1,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)15,
  .kEndResultRegNo = (uint8_t)15,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)5,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle1 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle1 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G3,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle1 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)1,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)9,
  .kEndResultRegNo = (uint8_t)9,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)4,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle10 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle10 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G2,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle10 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)0,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)1,
  .kEndResultRegNo = (uint8_t)1,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)7,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle11 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle11 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G2,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle11 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)0,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)2,
  .kEndResultRegNo = (uint8_t)2,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)5,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle12 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle12 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G2,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle12 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)0,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)3,
  .kEndResultRegNo = (uint8_t)3,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)6,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle13 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle13 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G2,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle13 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)0,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)7,
  .kEndResultRegNo = (uint8_t)7,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)3,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle14 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle14 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G2,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle14 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)0,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)10,
  .kEndResultRegNo = (uint8_t)10,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)4,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle15 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle15 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G1,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle15 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)0,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)15,
  .kEndResultRegNo = (uint8_t)15,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)4,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle16 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle16 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G1,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle16 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)0,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)0,
  .kEndResultRegNo = (uint8_t)0,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)6,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle17 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle17 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G1,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle17 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)0,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)1,
  .kEndResultRegNo = (uint8_t)1,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)3,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle18 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle18 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G1,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle18 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)0,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)2,
  .kEndResultRegNo = (uint8_t)2,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)2,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle19 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle19 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G1,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle19 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)0,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)7,
  .kEndResultRegNo = (uint8_t)7,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)5,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle2 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle2 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G2,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle2 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)0,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)0,
  .kEndResultRegNo = (uint8_t)0,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)2,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle3 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle3 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G1,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle3 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)0,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)3,
  .kEndResultRegNo = (uint8_t)3,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)7,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle4 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle4 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G0,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle4 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)1,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)4,
  .kEndResultRegNo = (uint8_t)4,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)6,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle5 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle5 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G0,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle5 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)1,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)5,
  .kEndResultRegNo = (uint8_t)5,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)7,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle6 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle6 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G0,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle6 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)1,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)8,
  .kEndResultRegNo = (uint8_t)8,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)0,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle7 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle7 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G3,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle7 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)1,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)8,
  .kEndResultRegNo = (uint8_t)8,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)5,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle8 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle8 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G3,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle8 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)1,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)5,
  .kEndResultRegNo = (uint8_t)5,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)6,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
      
ADCCH001_DynamicHandleType ADCCH001_DynamicHandle9 = 
{
  .Result = (uint16_t)0,
  .FastCompResult = (uint8_t)0,
  .State = ADCCH001_UNINITIALIZED,
};

const ADCCH001_HandleType ADCCH001_Handle9 = 
{
  .ADCGrPtr = (VADC_G_TypeDef*)(void*)VADC_G3,
  .DynamicHandlePtr = &ADCCH001_DynamicHandle9 ,
  .kPrioChannel = (uint8_t)1,
  .kIpClassSel = (uint8_t)ADCCH001_GROUP0,
  .kBoundarySel = (uint8_t)0x4,
  .kChEvtmode = (uint8_t)ADCCH001_DISABLE, // if device is xmc45/44/42 
  .kRefInput = (uint8_t)0,   
  .kResultControl = (uint8_t)0,
  .kDataModification = (uint8_t)0x3 ,
  .kWaitForRead= (uint8_t)1,
  .kFIFOEnable = (uint8_t)0,
  .kResultEvtEnable= (uint8_t)1,  
  .kBoundaryFlagEnable = (uint8_t)0,
  .kStartResultRegNo = (uint8_t)4,
  .kEndResultRegNo = (uint8_t)4,
  .kExtMuxControl = (uint8_t)0,
  .kChannelNo = (uint8_t)3,
  .kCompareMode = (uint8_t)0,
  .kResultCompVal = (uint16_t)0,
};

 
