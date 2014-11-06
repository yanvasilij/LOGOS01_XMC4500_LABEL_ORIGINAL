/*CODE_BLOCK_BEGIN[TMPS001.h]*/

/*******************************************************************************
**                                                                            **
** Copyright (C) 2014 Infineon Technologies AG. All rights reserved.          **
**                                                                            **
** Infineon Technologies AG (Infineon) is supplying this software for use     **
** with Infineon's microcontrollers.                                          **
** This file can be freely distributed within development tools that are      **
** supporting such microcontrollers.                                          **
**                                                                            **
** THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS,        **
** IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES    **
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS      **
** SOFTWARE. INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, **
** INCIDENTAL, OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.           **
**                                                                            **
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
V1.0.4 , 21 Mar 2013, MISRA compliance
V1.0.6 , 20 Jan 2014, Added C++ support and updated the code snippets
                      Coding Guidelines adherence
*******************************************************************************/

/**
 * @file TMPS001.h
 *
 * @brief  Die Temperature Sensor App implementation header file.
 *
 */

#ifndef TMPS001_H_
#define TMPS001_H_

#ifdef __cplusplus
extern "C" {
#endif
/*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/
/* Includes device header file to access the registers */
#include <uc_id.h>

#if (__TARGET_DEVICE__ == XMC45)
#include <XMC4500.h>
#elif (__TARGET_DEVICE__ == XMC44)
#include <XMC4400.h>
#elif ((__TARGET_DEVICE__ == XMC42) || (__TARGET_DEVICE__ == XMC41))
#include <XMC4200.h>
#else
#error "Unsupported XMC family"
#endif

#ifndef TYPES_CONFIG_H_
#include "types.h"
#endif

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/**
 * @ingroup TMPS001_constants
 * @{
 */
/**
 * To calibrate Reference and Bandgap Trim values, the bitfields DTSCON->REFTRIM
 * with the value 4U and DTSCON->BGTRIM with the value 8U have to be updated.
 */
#define TMPS001_CALIBRATION 0x44UL
/**
  * @}
  */
/*******************************************************************************
 *                                ENUMERATIONS                                **
 ******************************************************************************/
/**
 * @ingroup TMPS001_enumerations
 * @{
 */

/**
 * This enumerates the Die Temperature Sensor status
 */
typedef enum TMPS001_SensorStateType{
  /**
   * This is the default state after power on reset
   */
  TMPS001_DISABLE = 0x0U,
  /**
   * This state indicates that the Die Temperature Sensor is turned on
   */
  TMPS001_ENABLE = 0x1U,
  /**
   * This is the state to indicate any failures
   */
  TMPS001_FAIL = 0x2U,
  /**
   * This state indicates that the Die Temperature Sensor is busy
   */
  TMPS001_BUSY = 0x3U,
  /**
    * This state indicates that the Die Temperature Sensor is ready to measure
    */
  TMPS001_READY = 0x4U
}TMPS001_SensorStateType;

/**
 * @}
 */

/******************************************************************************
** FUNCTION PROTOTYPES                                                       **
******************************************************************************/

/**
 * @ingroup TMPS001_apidoc
 * @{
 */
/**
 * This macro enables the Die Temperature Sensor.
 *
 * @return void <BR>
 *
 * <b>Reentrant: NO </b><BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 *
 * #include <DAVE3.h>
 *
 * int main(void)
 *  {
 *    status_t status;
 *
 *    DAVE_Init();
 *
 *    TMPS001_Enable();
 *
 *    while (1) {
 *    }
 *  return 0;
 * }
 * @endcode<BR> </p>
 *
 */
extern void TMPS001_Enable(void);

/**
 * This macro disables the Die Temperature Sensor
 *
 * @return void  <BR>
 *
 * <b>Reentrant: NO </b> <BR>
 *
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 *
 * int main(void)
 *  {
 *    status_t status;
 *
 *    DAVE_Init();
 *
 *    TMPS001_Enable();
 *
 *    // ....
 *
 *    TMPS001_Disable();
 *
 *    while (1) {
 *    }
 *   return 0;
 * }
 * @endcode<BR> </p>
 *
 */
extern void TMPS001_Disable(void);

/**
 * @brief      This function gets the status of the die temperature sensor
 *
 * @return     status_t<BR>
 *             TMPS001_READY    Die Temperature Sensor is in ready state<BR>
 *             TMPS001_BUSY     Die Temperature Sensor Busy<BR>
 *             TMPS001_DISABLE  Die Temperature Sensor not powered on<BR>
 *             TMPS001_FAIL     Failed to read the status<BR>
 *
 *
 * <b>Reentrant: NO </b><BR>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 *
 * #include <DAVE3.h>
 *
 *  int main(void)
 *    {
 *      status_t status;
 *      uint32_t Temp =0;
 *
 *      DAVE_Init();
 *
 *      TMPS001_Enable();
 *
 *      while (1)
 *      {
 *         if(TMPS001_GetStatus() == TMPS001_READY)
 *         {
 *           TMPS001_StartMeasurement();
 *
 *           while (TMPS001_GetStatus() != TMPS001_READY)
 *           {}
 *
 *           Temp = TMPS001_ReadTemp();
 *         }
 *      }
 *     // ....
 *      return 0;
 *   }
 * @endcode<BR> </p>
 *
 */
 status_t  TMPS001_GetStatus(void);
 /**
 * @brief      This function calculates the temperature and returns the value
 *             in celsius.
 *             Note that the temperature returns only a integer value,
 *             as the resolution of  DTS sensor is +/- 6 degree celsius
 *
 * @return     uint32_t(Measured temperature in Celcius)<BR>
 *
 *
 * <b>Reentrant: NO </b><BR>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 *
 * #include <DAVE3.h>
 *
 *  int main(void)
 *    {
 *      status_t status;
 *      uint32_t Temp =0;
 *
 *      DAVE_Init();
 *
 *      TMPS001_Enable();
 *
 *      while (1)
 *      {
 *         if(TMPS001_GetStatus() == TMPS001_READY)
 *         {
 *           TMPS001_StartMeasurement();
 *
 *           while (TMPS001_GetStatus() != TMPS001_READY)
 *           {}
 *
 *           Temp = TMPS001_ReadTemp();
 *         }
 *      }
 *     // ....
 *      return 0;
 *   }
 * @endcode<BR> </p>
 *
 */
 uint32_t  TMPS001_ReadTemp(void) ;
/**
 * @brief      The Die Temperature Sensor (DTS) generates a measurement by
 *             calling TMPS001_StartMeasurement() result that indicates directly
 *             the current temperature.The result of the measurement can be
 *             obtained by calling TMPS001_ReadTemp().
 *
 * @return     status_t<BR>
 *             DAVEApp_SUCCESS if measurement success<BR>
 *             TMPS001_BUSY  Die Temperature Sensor Busy<BR>
 *             TMPS001_FAIL Die Temperature Sensor not powered on<BR>
 *
 *
 * <b>Reentrant: NO </b><BR>
 * <BR><P ALIGN="LEFT"><B>Example:</B>
 * @code
 *
 * #include <DAVE3.h>
 *
 *  int main(void)
 *    {
 *      status_t status;
 *      uint32_t Temp =0;
 *
 *      DAVE_Init();
 *
 *      TMPS001_Enable();
 *
 *      while (1)
 *      {
 *         if(TMPS001_GetStatus() == TMPS001_READY)
 *         {
 *           TMPS001_StartMeasurement();
 *
 *           while (TMPS001_GetStatus() != TMPS001_READY)
 *           {}
 *
 *           Temp = TMPS001_ReadTemp();
 *         }
 *      }
 *     // ....
 *      return 0;
 *   }
 * @endcode<BR> </p>
 *
 */
status_t  TMPS001_StartMeasurement(void);

/* Support for C++ codebase */
#ifdef __cplusplus
}
#endif

#endif /* TMPS001_H_ */
/**
 *@}
 */
/*CODE_BLOCK_END*/
