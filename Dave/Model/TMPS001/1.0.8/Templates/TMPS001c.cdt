
/*CODE_BLOCK_BEGIN[TMPS001.c]*/

/*******************************************************************************
 Copyright (c) 2014, Infineon Technologies AG                                 **
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
** NOTE     : Any changes made to this file will be overwritten during Code   **
**            generation                                                      **
**                                                                            **
*******************************************************************************/
/* ********************* Version History **************************************/
/* ***************************************************************************
V1.0.0 , 02 Aug 2012, Initial Version
V1.0.4 , 21 Mar 2013, Coding Guidelines compliance
V1.0.6 , 20 Jan 2014, Reference trim Calibration and Bandgap trim Calibration are
                      added in TMPS001_StartMeasurement() api.
                      Coding Guidelines adherence
*******************************************************************************/

/**
 * @file   TMPS001.c
 *
 * @brief  This file contains implementations of all functions of
 *         Die Temperature Sensor TMPS001 App
 *
 */
/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/

#include "../../inc/TMPS001/TMPS001.h"

/*******************************************************************************
**                      Public Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/**Used to check the bit is set to one or not*/
#define TMPS001_SET   0x1UL
/**Used to check the bit is set to zero or not*/
#define TMPS001_RESET 0x0UL
/*******************************************************************************
**                      Public Function Definitions                           **
*******************************************************************************/
/**
 * @ingroup TMPS001_funcdefines
 * @{
 */

/**
 * This Function disables the Die Temperature Sensor
 */
inline void TMPS001_Disable(void)
{
   /*Disabling the DTS*/
   SCU_GENERAL->DTSCON |= TMPS001_SET;
}

/**
 * This Function enables the Die Temperature Sensor
 */
inline void TMPS001_Enable(void)
{
   /*Enabling the DTS*/
   SCU_GENERAL->DTSCON &= ~TMPS001_SET;
}

/**
 * This Function starts the measurement of the Die by setting the DTSCON->START
 * bit. But before starting, the sensor state has to be checked.If the sensor is
 * Powered and in IDLE state then only measurement will start.
 */
status_t  TMPS001_StartMeasurement(void) 
{
  TMPS001_SensorStateType Result;
  Result = TMPS001_FAIL;
  /* <<<DD_TMPS001_API_2>>> */
  /*Checking whether DTS is turned on or not*/
  if (TMPS001_SET == (((uint32_t)SCU_GENERAL->DTSCON & \
                       (uint32_t)SCU_GENERAL_DTSCON_PWD_Msk) >>\
                        (uint32_t)SCU_GENERAL_DTSCON_PWD_Pos))
  {
	 Result = TMPS001_DISABLE;
  }
  /*Checking whether DTS is busy in measurement or not*/
  else if (TMPS001_SET == (((uint32_t)SCU_GENERAL->DTSSTAT & \
                            (uint32_t)SCU_GENERAL_DTSSTAT_BUSY_Msk) >> \
                             (uint32_t)SCU_GENERAL_DTSSTAT_BUSY_Pos))
  {
     Result = TMPS001_BUSY;
  }
  else
  {
	 /*calibration of Reference and Bandgap Trim values*/
	 SCU_GENERAL->DTSCON |= ((uint32_t)TMPS001_CALIBRATION << \
			                 (uint32_t)SCU_GENERAL_DTSCON_REFTRIM_Pos);

	 /*wait until DTS is finished measuring temperature*/
     while(((uint32_t)SCU_GENERAL->DTSSTAT & \
    		 (uint32_t)SCU_GENERAL_DTSSTAT_RDY_Msk) == TMPS001_RESET)
     {  }

     /* Enabling to start the measurement.*/
     SET_BIT(SCU_GENERAL->DTSCON, TMPS001_SET);
  }
  return (status_t)Result;
}

/**
 * This Function returns the state of the sensor.
 */
status_t  TMPS001_GetStatus(void)
{
  TMPS001_SensorStateType Result;
  /* <<<DD_TMPS001_API_3>>> */
  /*Checking whether DTS is turned on or not*/
  if (TMPS001_SET == (((uint32_t)SCU_GENERAL->DTSCON & \
		               (uint32_t)SCU_GENERAL_DTSCON_PWD_Msk) >> \
	                    (uint32_t)SCU_GENERAL_DTSCON_PWD_Pos))
  {
	 Result = TMPS001_DISABLE ;
  }
  /*Checking whether DTS is busy in measurement or not*/
  else if (TMPS001_SET == (((uint32_t)SCU_GENERAL->DTSSTAT & \
		                    (uint32_t)SCU_GENERAL_DTSSTAT_BUSY_Msk) >>\
		                     (uint32_t)SCU_GENERAL_DTSSTAT_BUSY_Pos))
  {
     Result = TMPS001_BUSY;
  }
  /*Checking whether DTS is finished the current measurement or not*/
  else if (TMPS001_SET == (((uint32_t)SCU_GENERAL->DTSSTAT & \
		                    (uint32_t)SCU_GENERAL_DTSSTAT_RDY_Msk) >>\
		                     (uint32_t)SCU_GENERAL_DTSSTAT_RDY_Pos))
  {
     Result = TMPS001_READY ;
  }
  /*Checking for failure cases*/
  else
  {
	 Result = TMPS001_FAIL ;
  }
  return (status_t)Result ;
}

/**
 * This Function will read the measured temperature of the Die from  DTSSTAT
 * register and returns the value by converting into Degrees celsius.
 */
uint32_t  TMPS001_ReadTemp (void) 
{
   uint32_t Temp;
   uint32_t lbusy_flag;
   uint32_t lpwr_flag;
   /*Initialise the value*/
   Temp = 0U;
   lbusy_flag = (((uint32_t)SCU_GENERAL->DTSSTAT & \
		     (uint32_t)SCU_GENERAL_DTSSTAT_BUSY_Msk) >> \
		      (uint32_t)SCU_GENERAL_DTSSTAT_BUSY_Pos);
   lpwr_flag	= (((uint32_t)SCU_GENERAL->DTSCON & \
		    (uint32_t)SCU_GENERAL_DTSCON_PWD_Msk) >> \
	         (uint32_t)SCU_GENERAL_DTSCON_PWD_Pos);
   /*Checking whether DTS measurement is finished or not*/
   if ((TMPS001_RESET == lpwr_flag) && (TMPS001_RESET == lbusy_flag))
    {
        Temp  = ((uint32_t)SCU_GENERAL->DTSSTAT & \
        		                      (uint32_t)SCU_GENERAL_DTSSTAT_RESULT_Msk);
        /*Checking whether measurement is proper or not*/
        if(Temp != TMPS001_RESET)
        {
        /*This is the relation specified in the data sheet to represent the
           measured value in degrees celsius*/
            Temp  = ((Temp - 605U)*100U)/ 205U ;
        }
    }
   return Temp;
}

/**
 * @}
 */

/*CODE_BLOCK_END*/
