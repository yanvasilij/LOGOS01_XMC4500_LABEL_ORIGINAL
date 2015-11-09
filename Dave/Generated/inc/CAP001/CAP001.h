/******************************************************************************
 *
 * Copyright (C) 2013 Infineon Technologies AG. All rights reserved.
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
** PLATFORM : Infineon XMC4000/XMC1000 Series                                 **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : Dec 12, 2013                                           **
**                                                                            **
*******************************************************************************/

/**
 * @file CAP001.h

 * @brief  This file contains Macros,local data structures,Enums and
 *         function prototypes for CAP.PER.DUT APP.
 *         
 * Revision History
 * 
 * 12 Feb 2013  v1.0.14    Ported to XMC4200 & XMC1000 devices.
 * 12 Dec 2013  v1.0.20    added c++ support        
 */
/******************************************************************************
**                      Author(s) Identity                                   **
*******************************************************************************
**                                                                           **
** Initials     Name                                                         **
**  KS          App Developer                                                **
** --------------------------------------------------------------------------**

*******************************************************************************/

#ifndef CAP001_H_
#define CAP001_H_

#ifdef __cplusplus
extern "C" {
#endif
/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/

#include <DAVE3.h>


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*****************************************************************************
 *                            Macros                                        **
 *****************************************************************************/

/** Event 0 Mask*/
/*<<<DD_CAP001_MACRCO_1>>>*/
#define CAP001_EVENT_0                       (uint32_t)(0x01)
/** Event 1 Mask*/
/*<<<DD_CAP001_MACRCO_2>>>*/
#define CAP001_EVENT_1                       (uint32_t)(0x02)
/** Edge-aligned mode*/
/*<<<DD_CAP001_MACRCO_3>>>*/
#define CAP001_TIMER_COUNTING_MODE           (uint32_t)(0x00)
/** Timer is set in capture mode*/
/*<<<DD_CAP001_MACRCO_6>>>*/
#define CAP001_CAPTURE_MODE                  (uint32_t)(0x01)
/*<<<DD_CAP001_MACRCO_7>>>*/
/* To clear all the interrupts of CCU4**/
#define CAP001_ALL_CCU4_INTR_CLEAR           (uint32_t)(0x00000F0F)
#define CAP001_PERIOD_CAPTURE_EVENT            (uint32_t)(8)
/* This is the highest prescalar value */
#define CAP001_MAX_PRESCALAR_DIV               (uint32_t)(15)
/* To clear the CCU4 slice */
#define CAP001_SLICE_CLEAR                     (uint32_t)(0x07)
/* This is to configure the timer to clear on the capture channel 0 */
#define CAP001_CLEAR_ON_CAPTURE                (uint32_t)(0x02)
/* This is to configure the timer to clear on every capture.
 * This is required for floating prescalar */
#define CAP001_CLEAR_ON_CAPTURE_FPP              (uint32_t)(0x03)

/*******************************************************************************
**                 Function like macro definitions                            **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/**
 * @ingroup CAP001_publicparam
 * @{
 */

/**
 * This enumerates the edge trigger type
 */
typedef enum CAP001_EdgeType
{
    /**
     * Trigger on rising edge
     */
  CAP001_RISINGEDGE = 1,
  /**
   * Trigger on falling edge
   */
  CAP001_FALLINGEDGE,
}CAP001_EdgeType;

/**
 * This enumerates the CCUx slice used by this APP.
 */

typedef enum CAP001_CCUInUseType
{
/**
  * This is slice 0 of CCU4x module
*/
  CAP001_SLICE0,
/**
  * This is slice 1 of CCU4x module
*/
  CAP001_SLICE1,
/**
  * This is slice 2 of CCU4X module
*/
  CAP001_SLICE2,
/**
  * This is slice 3 of CCU4X module
*/
  CAP001_SLICE3,
}CAP001_CCUInUseType;

/**
 * This enumerates the prescalar mode setting
 */
typedef enum CAP001_PrescalarModeType
{
  /**
   * Prescalar option is not required
   */
  CAP001_NOPRESCALAR,
  /**
   * Normal prescalar that is frequency division by fixed divider.
   */
  CAP001_NORMALPRESCALAR,
  /**
   * Floating prescalar is the dynamic frequency division mode. CCU frequency is
   * scaled down using floating prescalar formula.
   */
  CAP001_FLOATINGPRESCALAR,
  /**
   * In this mode, two timer slices are concatenated to get 32-bit values.
   */
  CAP001_TIMERCONCATENATION
}CAP001_PrescalarModeType;

/**
 * This enumerates the state of the App.
 */
typedef enum CAP001_StateType
{
  /**
   * This is the Default state of an APP after power on reset.
   */
  CAP001_UNINITIALIZED,
  /**
   * This is the INITIALIZED state in which APP is initialized as per selected
   * parameters.
   */
  CAP001_INITIALIZED,
  /**
   * This state indicates that CCU4_CCy or CCU8_CCY slice is started to capture duty
   * cycle and period and is running in capture mode.
   */
  CAP001_RUNNING

}CAP001_StateType;

/**
 * This enumerates the error types which will be returned from function.
 */
typedef enum CAP001_ErrorCodesType
{
  /**
   * This code would be returned when any operation is not possible cause that
   * operation was tried in invalid state
   */
  /**
   * @cond INTERNAL_DOCS
   * @param MODULENAME CAP001
   * @endcond
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING1 CAP001_OPER_NOT_ALLOWED_ERROR
   * @param STRCODESTRING1 Function execution is not allowed in the current state
   * @endcond
   */
  CAP001_OPER_NOT_ALLOWED_ERROR = 1,
  /**
   * This code is returned when parameter passed to API are invalid
   */
   /**
    * @cond INTERNAL_DOCS
    * @param ERRCODESTRING2 CAP001_INVALID_PARAM_ERROR
    * @param STRCODESTRING2 Input parameter is not valid
    * @endcond
    */
  CAP001_INVALID_PARAM_ERROR,
  /**
   * This code is returned when period value is out of range.
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING3 CAP001_OUT_OF_RANGE_ERROR
   * @param STRCODESTRING3 period value is out of range
   * @endcond
   */
  CAP001_OUT_OF_RANGE_ERROR,
  /**
   * This code is returned when duty cycle and period value is not available
   * as app is in START state.
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING4 CAP001_VAL_NOT_AVAILABLE_ERROR
   * @param STRCODESTRING4 duty cycle and period not yet calculated
   * @endcond
   */
  CAP001_VAL_NOT_AVAILABLE_ERROR,

  /** Debug messages start here*/
  /**
   * message ID for function start
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING5 CAP001_FUNCTION_ENTRY
   * @param STRCODESTRING5 Entered Function %s
   * @endcond
   */
  CAP001_FUNCTION_ENTRY,
  /**
   * message ID for function exit
   */
  /**
   * @cond INTERNAL_DOCS
   * @param ERRCODESTRING6 CAP001_FUNCTION_EXIT
   * @param STRCODESTRING6 Exited Function %s
   * @endcond
   */
  CAP001_FUNCTION_EXIT,
}CAP001_ErrorCodesType;

/**
 * This enumerates the event type of this app
 */
typedef enum CAP001_EventNameType
{
  /**
   * Period match interrupt
   */
  CAP001_TIMEOUTEVENT = 0,
  /**
   * Event 0 interrupt
   */
  CAP001_PERIODCAPTUREEVENT = 8,
  /**
   * Event 1 interrupt
   */
  CAP001_DUTYCAPTUREEVENT = 9,
}CAP001_EventNameType;


/**
 * This data structure consists of the capture register value, prescalar value at
 * the time of the capture and full flag status of the capture register.
 */
typedef struct CAP001_CaptureDataType
{
/**
 * This is the value in capture register of period edge.
 */
uint32_t PeriodCaptureValue;
/**
 * This is the prescalar value at the time of period capture event.
 */
uint32_t PeriodPrescalarValue;
/**
 * This is the value in capture register of duty edge.
 */
uint32_t DutyCaptureValue;
/**
 * This is the prescalar value at the time of duty cycle capture event.
 */
uint32_t DutyPrescalarValue;
}CAP001_CaptureDataType;
/**
 * This structure holds the parameters which change at run time.
 */
typedef struct CAP001_DynamicDataType
{
/**
 * This is the duty cycle value of the input digital signal
 */
uint32_t DutyCycle;
/**
 * This is the period of the input digital signal.
 */
uint32_t Period;

CAP001_CaptureDataType* CaptureRegPtr;
/**
 * This is the state of the app.
 */
CAP001_StateType AppState;

}CAP001_DynamicDataType;




/**
 * This structure holds all the static configuration parameters of the Capture
 * duty Cycle and Period APP.
 */
typedef struct CAP001_HandleType
{
/**
 * This decides whether to start the app after initialization
 */      
const uint8_t StartControl;
/**
 * This is the low pass filter configuration for the external signal.
 */
const uint8_t kLpf;
/**
 * This will decide whether to capture values continuously without considering
 * full flag. If continuous capture is enabled then capture register value is
 * overwritten by the new value if it is not already read.
 */
const uint8_t kOverwriteCaptureValue;
/**
 * This parameter value is 0 if
 * period capture is rise-to-rise and duty capture is fall-to-rise OR
 * period capture is fall-to-fall and duty capture is rise-to-fall
 */
const uint8_t kIsDutyFirstPart;
/**
 * This is the Prescalar divider value which will be as per the period range of
 * the input signal.
 */
const uint8_t kPrescalarDiv;
/**
 * This is the CCU clock resolution in nanoseconds.
 */
const float kResolution;
/**
 * This tells whether to capture duty cycle at rising edge or falling edge
 */
const CAP001_EdgeType kCaptureEvtEdgeforDutyCycle;
/**
 * This parameter tells whether capture should be rise to rise or fall to fall for
 * period measurement.
 */
const CAP001_EdgeType kCaptureEvtEdgeforPeriod;
/**
 * This is the CCU clock resolution.
 */
const CAP001_CCUInUseType kFirstSlice;
/**
 * This is the second CCU slice used by this App in case of timer concatenation.
 */
const CAP001_CCUInUseType kSecondSlice;
/**
 * This is the pointer to the dynamic data of the App.
 */
 CAP001_DynamicDataType* const DynamicHandlePtr;
/**
 * This tells the prescalar mode used by the App.
 */
const CAP001_PrescalarModeType kPrescalarMode;
/**
 * This decides whether to enable interrupts at initialization time. This stores the information in a format of 32-bit register (INTE)
 * with a bit-field for each interrupt.
 */
const uint32_t InterruptControl;
/**
 * This is the pointer to the kernel register structure of the selected CCU4 module.
 */
CCU4_GLOBAL_TypeDef* const CCU4xKernRegsPtr;
/**
 * This is the pointer to the slice registers structure of the first ccu4 slice
 */
CCU4_CC4_TypeDef* const CC4ySliceRegs0Ptr;
/**
 * This is the pointer to the slice registers structure of the second ccu4 slice
 */
CCU4_CC4_TypeDef* const CC4ySliceRegs1Ptr;

}CAP001_HandleType;

/**
 * @}
 */

/**
 * @ingroup CAP001_apidoc
 * @{
 */

/** Function prototypes*/

/**
 * @brief This function will reset the App.
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @return  status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful.<BR>
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 *
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status; 
 *    DAVE_Init();
 *    Status = CAP001_Start((CAP001_HandleType*)&CAP001_Handle0);
 *    ...
 *    //Call the deinit function to reset the app to default values.
 *    Status = CAP001_Deinit((CAP001_HandleType*)&CAP001_Handle0);
 * }
 * @endcode
 */

status_t CAP001_Deinit
(
    const CAP001_HandleType* HandlePtr
);

/**
 * @brief This function will read the capture registers. Use this function to read the captured values
 * asynchronously.  
 * This function does not handle events. It just reads the captured values and copies it to the dynamic handle.
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @param [out] CaptureReg Structure of Capture register values<BR>
 *
 * @return  status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CAP001_OPER_NOT_ALLOWED_ERROR: If the function is called when in the
 * CAP001_UNINITIALIZED State.<BR>
 * CAP001_INVALID_PARAM_ERROR: If the CaptureData* is NULL.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 *
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    CAP001_CaptureDataType CapRegPtr =
 *    {
 *      .PeriodCaptureValue= 0,
 *      .DutyCaptureValue=0,
 *      .PeriodPrescalarValue=0,
 *      .DutyPrescalarValue=0
 *    };
 *    status_t Status;
 *    DAVE_Init(); //CAP001_Init() is called within this function.
 *    //Call this function if "Start after initialization" is not checked.
 *    Status = CAP001_Start((CAP001_HandleType*)&CAP001_Handle0);
 *    if (Status == (uint32_t)DAVEApp_SUCCESS)
 *    {
 *      //Call this function to read capture registers asynchronously.
 *      Status = CAP001_GetCapRegs((CAP001_HandleType*)&CAP001_Handle0, &CapRegPtr);
 *    }
 * }
 * @endcode
 */
status_t CAP001_GetCapRegs
(
    const CAP001_HandleType* HandlePtr,
    CAP001_CaptureDataType* CaptureReg
);

/**
 * @brief This function will check if the period capture interrupt is set
 * and if set read the capture registers and update the dynamic handle.
 * This function should be called from the capture interrupt handler
 * to read the capture registers and the prescalar values at the time of the capture.
 * 
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 *
 * @return  status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CAP001_OPER_NOT_ALLOWED_ERROR: If the function is called when in the
 * CAP001_UNINITIALIZED State or if Period capture interrupt is not set.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 *
 * <b>Example:</b> CAP001_Handle0 is a global structure of type CAP001_HandleType defined in
 * CAP001Conf.h file based on UI configurations. CAP001_PeriodCaptureEventHandler is
 * the interrupt handler routine.
 * Below code snippet shows how to use ReadCapturedValues() API from the interrupt routine.
 * @code
 * #include <DAVE3.h>
 * volatile uint32_t Flag = 0;
 * int main(void)
 * {
 *    status_t Status;
 *	  uint32_t Duty;
 *	  uint32_t Period;
 *	  float Freq;
 *	  float DutyPer;
 *    DAVE_Init();
 *    //call this if "event is not enabled during initialization
 *    Status = CAP001_EnableEvent((CAP001_HandleType*)&CAP001_Handle0, CAP001_PERIODCAPTUREEVENT);
 *    //Call this function if "Start after initialization" is not checked.
 *    Status = CAP001_Start((CAP001_HandleType*)&CAP001_Handle0);
 *    //Read the duty cycle and period when capture interrupt occurs.
 *    //Flag is set in the interrupt routine.
 *    while(1)
 *    {
 *      if(Flag == 1)
 *      {
 *        Status = CAP001_GetDutyPeriod((CAP001_HandleType*)&CAP001_Handle0, &Duty, &Period);
 *        Freq = 1000000000/(Period * CAP001_Handle0.kResolution);
 *        DutyPer = Duty * 100/ Period;
 *        if (Status != (uint32_t)DAVEApp_SUCCESS)
 *       {
 *         Status = CAP001_Stop((CAP001_HandleType*)&CAP001_Handle0);
 *         break;
 *       }
 *     }
 *     Flag = 0;
 *   };
 *   return 0;
 * }
 * void CAP001_PeriodCaptureEventHandler(void)
 *	{
 *	  status_t Status;
 *	//Get the capture register value from the interrupt handler.
 *	  Status = CAP001_ReadCapturedValues((CAP001_HandleType*)&CAP001_Handle0);
 *	  if(Status == (uint32_t) DAVEApp_SUCCESS)
 *	  {
 *		Flag = 1;
 *	  }
 *	}
 * @endcode
 */
status_t CAP001_ReadCapturedValues
(
const CAP001_HandleType* HandlePtr
);

/**
 * @brief This function will return duty cycle of the input signal.
 * Duty cycle value is the ON time of the signal. 
 * It is required to call CAP001_ReadCapturedValues API before this API to read the captured values in the dynamic handle. 
 * Both duty cycle and period values are in terms of the resolution of the timer.\n
 * E.G.
 * if Resolution = 50ns \n
 * SignalDuty = 5000 \n
 * SignalPeriod = 10000 \n
 * then ON time is 25000ns \n
 *      Period is 50000ns \n
 * User should find the percentage value from the Duty and period value
 * %Duty = (Duty * 100 )/Period
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @param [out] SignalDuty Duty cycle of the signal<BR>
 *
 * @return  status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CAP001_OPER_NOT_ALLOWED_ERROR: If the function is called when not in the
 * CAP001_RUNNING State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 *
 * @code
 * #include <DAVE3.h>
 * uint32_t Flag = 0;
 * int main(void)
 * {
 *    status_t Status;
 *    uint32_t Duty;
 *    DAVE_Init();
 *    //call this if "event is not enabled during initialization
 *    Status = CAP001_EnableEvent((CAP001_HandleType*)&CAP001_Handle0, CAP001_PERIODCAPTUREEVENT);
 *    //Call this function if "Start after initialization" is not checked.
 *    Status = CAP001_Start((CAP001_HandleType*)&CAP001_Handle0);
 *    //Read the duty cycle when capture interrupt occurs.
 *    //Flag is set in the interrupt routine.
 *     while(1)
 *     {
 *       if(Flag == 1)
 *       {
 *         Status = CAP001_GetDutyCycle((CAP001_HandleType*)&CAP001_Handle0, &Duty);
 *         if (Status != (uint32_t)DAVEApp_SUCCESS)
 *         {
 *           Status = CAP001_Stop((CAP001_HandleType*)&CAP001_Handle0);
 *           break;
 *         }
 *       }
 *       Flag = 0;
 *     };
 *     return 0;
 * }
 * void CAP001_PeriodCaptureEventHandler(void)
 * {
 *  status_t Status;
 *  //Get the capture register value from the interrupt handler.
 *  Status = CAP001_ReadCapturedValues((CAP001_HandleType*)&CAP001_Handle0);
 *  if(Status == (uint32_t) DAVEApp_SUCCESS)
 *  {
 *    Flag = 1;
 *  }
 * }
 * @endcode
 */
status_t CAP001_GetDutyCycle
(
    const CAP001_HandleType* HandlePtr,
    uint32_t* SignalDuty
);

/**
 * @brief This function will return period of the input signal.
 * It is required to call CAP001_ReadCapturedValues API before this API to read the captured values in the dynamic handle.
 * Period value is given in terms of the resolution of the timer.\n
 * E.G.
 * if Resolution = 50ns \n
 * SignalPeriod = 10000 \n
 * then Period is 50000ns
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @param [out] SignalPeriod Period of the input signal<BR>
 *
 * @return  status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CAP001_OPER_NOT_ALLOWED_ERROR: If the function is called when not in the
 * CAP001_RUNNING State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 *
 * @code
 * #include <DAVE3.h>
 * uint32_t Flag = 0;
 * int main(void)
 * {
 *     status_t Status;
 *     uint32_t Period;
 *     DAVE_Init();
 *     //call this if "event is not enabled during initialization
 *     Status = CAP001_EnableEvent((CAP001_HandleType*)&CAP001_Handle0, CAP001_PERIODCAPTUREEVENT);
 *     //Call this function if "Start after initialization" is not checked.
 *     Status = CAP001_Start((CAP001_HandleType*)&CAP001_Handle0);
 *     //Read the period when capture interrupt occurs.
 *     //Flag is set in the interrupt routine.
 *
 *      while(1)
 *      {
 *        if(Flag == 1)
 *        {
 *          Status = CAP001_GetPeriod((CAP001_HandleType*)&CAP001_Handle0, &Period);
 *          if (Status != (uint32_t)DAVEApp_SUCCESS)
 *          {
 *            Status = CAP001_Stop((CAP001_HandleType*)&CAP001_Handle0);
 *            break;
 *          }
 *        }
 *        Flag = 0;
 *      };
 *      return 0;
 *  }
 * void CAP001_PeriodCaptureEventHandler(void)
 * {
 *  status_t Status;
 * //Get the capture register value from the interrupt handler.
 *  Status = CAP001_ReadCapturedValues((CAP001_HandleType*)&CAP001_Handle0);
 *  if(Status == (uint32_t) DAVEApp_SUCCESS)
 *  {
 *    Flag = 1;
 *  }
 * }
 * @endcode
 */
status_t CAP001_GetPeriod
(
    const CAP001_HandleType* HandlePtr,
    uint32_t* SignalPeriod
);

/**
 * @brief This function will return duty cycle and period of the input
 * signal.
 * It is required to call CAP001_ReadCapturedValues API before this API to read the captured values in the dynamic handle.
 * Duty cycle value is the ON time of the signal.
 * Both duty cycle and period values are in terms of the resolution of the timer.\n
 * E.G.
 * if Resolution = 50ns \n
 * SignalDuty = 5000 \n
 * SignalPeriod = 10000 \n
 * then ON time is 25000ns \n
 *      Period is 50000ns \n
 * User should find the percentage value from the Duty and period value
 * %Duty = (Duty * 100 )/Period
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @param [out] SignalDuty Duty cycle of the input signal<BR>
 * @param [out] SignalPeriod Period of the input signal<BR>
 *
 * @return  status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CAP001_OPER_NOT_ALLOWED_ERROR: If the function is called when not in the
 * CAP001_RUNNING State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 *
 * @code
 * #include <DAVE3.h>
 * uint32_t Flag = 0;
 * int main(void)
 * {
 *     status_t Status;
 *     uint32_t Duty;
 *     uint32_t Period;
 *     DAVE_Init();
 *     //call this if "event is not enabled during initialization
 *     Status = CAP001_EnableEvent((CAP001_HandleType*)&CAP001_Handle0, CAP001_PERIODCAPTUREEVENT);
 *     //Call this function if "Start after initialization" is not checked.
 *     Status = CAP001_Start((CAP001_HandleType*)&CAP001_Handle0);
 *     //Read the duty cycle and period when capture interrupt occurs.
 *     //Flag is set in the interrupt routine.
 *
 *      while(1)
 *      {
 *        if(Flag == 1)
 *        {
 *          Status = CAP001_GetDutyPeriod((CAP001_HandleType*)&CAP001_Handle0, &Duty, &Period);
 *          if (Status != (uint32_t)DAVEApp_SUCCESS)
 *          {
 *            Status = CAP001_Stop((CAP001_HandleType*)&CAP001_Handle0);
 *            break;
 *          }
 *        }
 *        Flag = 0;
 *      };
 *      return 0;
 * }
 *
 * void CAP001_PeriodCaptureEventHandler(void)
 *{
 *  status_t Status;
 * //Get the capture register value from the interrupt handler.
 *  Status = CAP001_ReadCapturedValues((CAP001_HandleType*)&CAP001_Handle0);
 *  if(Status == (uint32_t) DAVEApp_SUCCESS)
 *  {
 *    Flag = 1;
 *  }
 *}
 * @endcode
 */
status_t CAP001_GetDutyPeriod
(
    const CAP001_HandleType* HandlePtr,
    uint32_t* SignalDuty,
    uint32_t* SignalPeriod
);

/**
 * @brief This function will read timer status - Running or idle.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @param [out] TimerStatus Timer status<BR>
 *
 * @return  status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CAP001_OPER_NOT_ALLOWED_ERROR: If the function is called when in the
 * CAP001_UNINITIALIZED State.<BR>
 * CAP001_INVALID_PARAM_ERROR: If the status* is not a valid pointer.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 *
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    uint32_t TimerStatus;
 *    DAVE_Init();
 *    //Call this function if "Start after initialization" is not checked.
 *    Status = CAP001_Start((CAP001_HandleType*)&CAP001_Handle0);
 *    Status = CAP001_GetTimerStatus((CAP001_HandleType*)&CAP001_Handle0, &TimerStatus);
 *    if(TimerStatus == 1)
 *    {
 *      //timer is running
 *    }
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t CAP001_GetTimerStatus
(
    const CAP001_HandleType* HandlePtr,
    uint32_t* TimerStatus
);

/**
 * @brief This function initializes the CCU4_CCy or CCU8_CCy slice with the
 * configured parameters to capture the period and duty cycle of input signal.
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * 
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    uint32_t TimerStatus;
 *    DAVE_Init(); //CAP001_Init() is called within tis function
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
void CAP001_Init(void);


/**
 * @brief This function will start this APP which will start the CCU4_CCy or
 * CCU8_CCy slice.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 *
 * @return status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CAP001_OPER_NOT_ALLOWED_ERROR: If the function is called in
 * CAP001_UNINITIALIZED State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * 
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    uint32_t TimerStatus;
 *    DAVE_Init();
 *    //Call this function if "Start after initialization" is not checked.
 *    Status = CAP001_Start((CAP001_HandleType*)&CAP001_Handle0);
 *    while(1);
 *    return 0;
 * }
 * @endcode
 */
status_t CAP001_Start(const CAP001_HandleType* HandlePtr);

/**
 * @brief This function will stop this APP which will stop the CCU4_CCy or
 * CCU8_CCy slice.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 *
 * @return status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CAP001_OPER_NOT_ALLOWED_ERROR: If the function is called in
 * CAP001_RUNNING State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * 
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();
 *    //Call this function if "Start after initialization" is not checked.
 *    Status = CAP001_Start((CAP001_HandleType*)&CAP001_Handle0);
 *    //...
 *    Status = CAP001_Stop((CAP001_HandleType*)&CAP001_Handle0);
 *    return 0;
 * }
 * @endcode
 */
status_t CAP001_Stop(const CAP001_HandleType* HandlePtr);



/**
 * @brief This function will enable the event. This should be called by the user first
 * for interrupt handling.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @param [in] Event Event to be enabled <BR>
 * @return status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CAP001_OPER_NOT_ALLOWED_ERROR: If the function is called in
 * CAP001_UNINITIALIZED State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * 
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();
 *    //call this if "event is not enabled during initialization
 *    Status = CAP001_EnableEvent((CAP001_HandleType*)&CAP001_Handle0, CAP001_PERIODCAPTUREEVENT);
 *    //Call this function if "Start after initialization" is not checked.
 *    Status = CAP001_Start((CAP001_HandleType*)&CAP001_Handle0);
 *    return 0;
 * }
 * @endcode
 */
status_t CAP001_EnableEvent
(
     const CAP001_HandleType * HandlePtr,
     const CAP001_EventNameType Event
);

/**
 * @brief This function will disable the event.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @param [in] Event Event to be disabled <BR>
 * @return status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CAP001_OPER_NOT_ALLOWED_ERROR: If the function is called in
 * CAP001_UNINITIALIZED State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * 
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();
 *    //call this if "event is not enabled during initialization
 *    Status = CAP001_EnableEvent((CAP001_HandleType*)&CAP001_Handle0, CAP001_PERIODCAPTUREEVENT);
 *    //Call this function if "Start after initialization" is not checked.
 *    Status = CAP001_Start((CAP001_HandleType*)&CAP001_Handle0);
 *   //....
 *   Status = CAP001_DisableEvent((CAP001_HandleType*)&CAP001_Handle0, CAP001_PERIODCAPTUREEVENT);
 *    return 0;
 * }
 * @endcode
 */
status_t CAP001_DisableEvent
(
    const CAP001_HandleType * HandlePtr,
    const CAP001_EventNameType Event
);

/**
 * @brief This function will clear the event.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @param [in] Event Event to be cleared <BR>
 * @return status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CAP001_OPER_NOT_ALLOWED_ERROR: If the function is called in
 * CAP001_UNINITIALIZED State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * 
 * @code
 * #include <DAVE3.h>
 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();
 *    //call this if "event is not enabled during initialization
 *    Status = CAP001_EnableEvent((CAP001_HandleType*)&CAP001_Handle0, CAP001_PERIODCAPTUREEVENT);
 *    //Call this function if "Start after initialization" is not checked.
 *    Status = CAP001_Start((CAP001_HandleType*)&CAP001_Handle0);
 *      return 0;
 * }
 *
 * void CAP001_PeriodCaptureEventHandler(void)
 * {
 * status_t Status;
 * //....
 * Status = CAP001_ClearPendingEvent((CAP001_HandleType*)&CAP001_Handle0, CAP001_PERIODCAPTUREEVENT);
 *
 * }
 * @endcode
 */
status_t CAP001_ClearPendingEvent
(
    const CAP001_HandleType * HandlePtr,
    const CAP001_EventNameType Event
);

/**
 * @brief This function will set the event.This should not be called within 
 * interrupt handler as it will result into infinite loop.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @param [in] Event Event to be set <BR>
 * @return status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CAP001_OPER_NOT_ALLOWED_ERROR: If the function is called in
 * CAP001_UNINITIALIZED State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * 
 * @code
 * #include <DAVE3.h>

 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();
 *    //call this if "event is not enabled during initialization
 *    Status = CAP001_EnableEvent((CAP001_HandleType*)&CAP001_Handle0, CAP001_PERIODCAPTUREEVENT);
 *    //Call this function if "Start after initialization" is not checked.
 *    Status = CAP001_Start((CAP001_HandleType*)&CAP001_Handle0);
 *    Status = CAP001_SetPendingEvent((CAP001_HandleType*)&CAP001_Handle0, CAP001_PERIODCAPTUREEVENT);
 *    return 0;
 * }
 * @endcode
 */
status_t CAP001_SetPendingEvent
(
    const CAP001_HandleType * HandlePtr,
    const CAP001_EventNameType Event
);

/**
 * @brief This function will check whether given event is set.
 *
 * @param [in] HandlePtr pointer to the Instance variable<BR>
 * @param [in] Event Event to be set <BR>
 * @param [in] EvtStatus Status of the event whether it is set <BR>
 * @return status_t<BR>
 * DAVEApp_SUCCESS: if the function is successful<BR>
 * CAP001_OPER_NOT_ALLOWED_ERROR: If the function is called in
 * CAP001_UNINITIALIZED State.<BR>
 *
 * <b>Reentrancy:  Yes</b><BR>
 * <b>Sync/Async:  Synchronous</b><BR>
 * @code
 * #include <DAVE3.h>

 * int main(void)
 * {
 *    status_t Status;
 *    DAVE_Init();
 *    //call this if "event is not enabled during initialization
 *    Status = CAP001_EnableEvent((CAP001_HandleType*)&CAP001_Handle0, CAP001_PERIODCAPTUREEVENT);
 *    //Call this function if "Start after initialization" is not checked.
 *    Status = CAP001_Start((CAP001_HandleType*)&CAP001_Handle0);
 *    return 0;
 * }
 *
 * void CAP001_PeriodCaptureEventHandler(void)
 * {
 *  status_t Status;
 *  uint8_t EvtStatus;
 *  Status = CAP001_GetPendingEvent((CAP001_HandleType*)&CAP001_Handle0, CAP001_PERIODCAPTUREEVENT, &EvtStatus);
 *  if(EvtStatus == (uint8_t) SET)
 *  {
 *   //Do something
 *  }
 *  Status = CAP001_ClearPendingEvent((CAP001_HandleType*)&CAP001_Handle0, CAP001_PERIODCAPTUREEVENT);
 * }
 * @endcode
 */
status_t CAP001_GetPendingEvent
(
    const CAP001_HandleType * HandlePtr,
    const CAP001_EventNameType Event,
    uint8_t* EvtStatus
);

#include "CAP001_Conf.h"

/**
 * @}
 */
#ifdef __cplusplus
}
#endif
#endif /* CAP001_H_ */
