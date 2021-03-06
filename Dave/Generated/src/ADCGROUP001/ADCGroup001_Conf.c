/*******************************************************************************
**  DAVE App Name : ADCGROUP001       App Version: 1.0.28               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/

/*CODE_BLOCK_BEGIN[ADCGROUP001Conf.c]*/

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
** MAY BE CHANGED BY USER [yes/Yes]: Yes                                      **
**                                                                            **
** MODIFICATION DATE : Jun 09, 2014                                          **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** CM           DAVE App Developer                                            **
*******************************************************************************/

/*
 * Change History:
 * Date       version       Details
 * 01-Jan-2013   1.0.6    Initial code added for XMC1000
 * 29-Jan-2013   1.0.8    Merging with XMC1000 done
 * 09-Apr-2013   1.0.12   Channel selection style is removed and made EMXCSS=1
 *                        always
 * 24-Apr-2013   1.0.14   Ported to XMC4500 step AB 
 * 11-Jun-2013   1.0.16   1.Variable name in manifest is corrected.
 *                        2.In the Header comment section device name changed to
 *                         XMC1000.
 *                        3.copy right year changed to 2013
 * 11-Sep-2013   1.0.20   1. Analog converter control(ANONC) Code sequence
 *                           corrected.
 *                        2. Added support for the following devices under 
 *                        XMC1200 and XMC1300 Series - XMC1201, XMC1202, XMC1301
 * 09-Jun-2014   1.0.28   ADC conversion time calculations are updated for XMC1X 
 *                        devices.
 *                        Order of function call for post calibration function is updated.
 */
 
/**
 * @file  ADCGROUP001_Conf.c
 * @App Version ADCGROUP001 <1.0.28>
 * @brief This file contains App parameter data as per GUI configurations
 */

#include <DAVE3.h>




ADCGROUP001_DynamicDataType ADCGROUP001_DynamicHandle0 =
{
  .State = ADCGROUP001_UNINITIALIZED
};


const ADCGROUP001_HandleType ADCGROUP001_Handle0 =
{
  .kGroupNo = (uint8_t)0,
  .kPostCalibration = (uint8_t)ADCGROUP001_AUTOPOSTCALIBRATION,
  .kArbitrationMode = (uint8_t)ADCGROUP001_RUNSPERMANENTLY,
  .kGrpBoundary0 = (uint16_t)0,  
  .kGrpBoundary1 = (uint16_t)0, 
  .kEMUXCodeScheme = (uint8_t)ADCGROUP001_BINARYCODE, 
  .kEMUXStartSelect = (uint8_t)0,
  .kEMUXMode = (uint8_t)ADCGROUP001_SOFTWARECONTROLMODE,
  .kAnalogConverterCtrl = (uint8_t)ADCGROUP001_ANALOG_CONVERTER_ON,
  .VADCGlobalPtr= (VADC_GLOBAL_TypeDef*)(void*)VADC,
  .VADCGroupPtr= (VADC_G_TypeDef*)(void*) VADC_G0,
  .DynamicHandlePtr= &ADCGROUP001_DynamicHandle0,
  .kConversionModeClass0 = (uint8_t)ADCGROUP001_12BIT,
  .kConversionModeClass1 = (uint8_t)ADCGROUP001_12BIT,
  .kEMUXConversionModeClass0 = (uint8_t)ADCGROUP001_12BIT,
  .kEMUXConversionModeClass1 = (uint8_t)ADCGROUP001_12BIT,
  .kSampleTimeControlClass0 = (uint8_t)0,
  .kSampleTimeControlClass1 = (uint8_t)0,
  .kEMUXSampleTimeControlClass0 = (uint8_t)0,
  .kEMUXSampleTimeControlClass1 = (uint8_t)0  
 };


ADCGROUP001_DynamicDataType ADCGROUP001_DynamicHandle1 =
{
  .State = ADCGROUP001_UNINITIALIZED
};


const ADCGROUP001_HandleType ADCGROUP001_Handle1 =
{
  .kGroupNo = (uint8_t)3,
  .kPostCalibration = (uint8_t)ADCGROUP001_AUTOPOSTCALIBRATION,
  .kArbitrationMode = (uint8_t)ADCGROUP001_RUNSPERMANENTLY,
  .kGrpBoundary0 = (uint16_t)0,  
  .kGrpBoundary1 = (uint16_t)0, 
  .kEMUXCodeScheme = (uint8_t)ADCGROUP001_BINARYCODE, 
  .kEMUXStartSelect = (uint8_t)0,
  .kEMUXMode = (uint8_t)ADCGROUP001_SOFTWARECONTROLMODE,
  .kAnalogConverterCtrl = (uint8_t)ADCGROUP001_ANALOG_CONVERTER_ON,
  .VADCGlobalPtr= (VADC_GLOBAL_TypeDef*)(void*)VADC,
  .VADCGroupPtr= (VADC_G_TypeDef*)(void*) VADC_G3,
  .DynamicHandlePtr= &ADCGROUP001_DynamicHandle1,
  .kConversionModeClass0 = (uint8_t)ADCGROUP001_12BIT,
  .kConversionModeClass1 = (uint8_t)ADCGROUP001_12BIT,
  .kEMUXConversionModeClass0 = (uint8_t)ADCGROUP001_12BIT,
  .kEMUXConversionModeClass1 = (uint8_t)ADCGROUP001_12BIT,
  .kSampleTimeControlClass0 = (uint8_t)0,
  .kSampleTimeControlClass1 = (uint8_t)0,
  .kEMUXSampleTimeControlClass0 = (uint8_t)0,
  .kEMUXSampleTimeControlClass1 = (uint8_t)0  
 };


ADCGROUP001_DynamicDataType ADCGROUP001_DynamicHandle2 =
{
  .State = ADCGROUP001_UNINITIALIZED
};


const ADCGROUP001_HandleType ADCGROUP001_Handle2 =
{
  .kGroupNo = (uint8_t)2,
  .kPostCalibration = (uint8_t)ADCGROUP001_AUTOPOSTCALIBRATION,
  .kArbitrationMode = (uint8_t)ADCGROUP001_RUNSPERMANENTLY,
  .kGrpBoundary0 = (uint16_t)0,  
  .kGrpBoundary1 = (uint16_t)0, 
  .kEMUXCodeScheme = (uint8_t)ADCGROUP001_BINARYCODE, 
  .kEMUXStartSelect = (uint8_t)0,
  .kEMUXMode = (uint8_t)ADCGROUP001_SOFTWARECONTROLMODE,
  .kAnalogConverterCtrl = (uint8_t)ADCGROUP001_ANALOG_CONVERTER_ON,
  .VADCGlobalPtr= (VADC_GLOBAL_TypeDef*)(void*)VADC,
  .VADCGroupPtr= (VADC_G_TypeDef*)(void*) VADC_G2,
  .DynamicHandlePtr= &ADCGROUP001_DynamicHandle2,
  .kConversionModeClass0 = (uint8_t)ADCGROUP001_12BIT,
  .kConversionModeClass1 = (uint8_t)ADCGROUP001_12BIT,
  .kEMUXConversionModeClass0 = (uint8_t)ADCGROUP001_12BIT,
  .kEMUXConversionModeClass1 = (uint8_t)ADCGROUP001_12BIT,
  .kSampleTimeControlClass0 = (uint8_t)24,
  .kSampleTimeControlClass1 = (uint8_t)0,
  .kEMUXSampleTimeControlClass0 = (uint8_t)0,
  .kEMUXSampleTimeControlClass1 = (uint8_t)0  
 };


ADCGROUP001_DynamicDataType ADCGROUP001_DynamicHandle3 =
{
  .State = ADCGROUP001_UNINITIALIZED
};


const ADCGROUP001_HandleType ADCGROUP001_Handle3 =
{
  .kGroupNo = (uint8_t)1,
  .kPostCalibration = (uint8_t)ADCGROUP001_AUTOPOSTCALIBRATION,
  .kArbitrationMode = (uint8_t)ADCGROUP001_RUNSPERMANENTLY,
  .kGrpBoundary0 = (uint16_t)0,  
  .kGrpBoundary1 = (uint16_t)0, 
  .kEMUXCodeScheme = (uint8_t)ADCGROUP001_BINARYCODE, 
  .kEMUXStartSelect = (uint8_t)0,
  .kEMUXMode = (uint8_t)ADCGROUP001_SOFTWARECONTROLMODE,
  .kAnalogConverterCtrl = (uint8_t)ADCGROUP001_ANALOG_CONVERTER_ON,
  .VADCGlobalPtr= (VADC_GLOBAL_TypeDef*)(void*)VADC,
  .VADCGroupPtr= (VADC_G_TypeDef*)(void*) VADC_G1,
  .DynamicHandlePtr= &ADCGROUP001_DynamicHandle3,
  .kConversionModeClass0 = (uint8_t)ADCGROUP001_12BIT,
  .kConversionModeClass1 = (uint8_t)ADCGROUP001_12BIT,
  .kEMUXConversionModeClass0 = (uint8_t)ADCGROUP001_12BIT,
  .kEMUXConversionModeClass1 = (uint8_t)ADCGROUP001_12BIT,
  .kSampleTimeControlClass0 = (uint8_t)24,
  .kSampleTimeControlClass1 = (uint8_t)0,
  .kEMUXSampleTimeControlClass0 = (uint8_t)0,
  .kEMUXSampleTimeControlClass1 = (uint8_t)0  
 };

/*CODE_BLOCK_END*/

