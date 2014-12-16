/*******************************************************************************
**  DAVE App Name : NVIC002       App Version: 1.0.28               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/


/*CODE_BLOCK_BEGIN[NVIC002_Conf.c]*/
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
**                                                                            **
** PLATFORM : Infineon XMC4000/XMC1000 Series   		            	      **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** MAY BE CHANGED BY USER [yes/no]: Yes                                       **
**                                                                            **
** MODIFICATION DATE : July 17, 2014                                          **
*******************************************************************************/
/*******************************************************************************
**                       Author(s) Identity                                   **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** SNR          App Developer                                                 **
*******************************************************************************/
/**
 * @file   NVIC002_Conf.c
 *
 * @App    Version NVIC002 <1.0.28>
 * 
 * @brief  Configuration file generated based on UI settings 
 *         of NVIC002 App
 *
 */
/* Revision History	
 * 18 Feb 2013 	 v1.0.12   Conditional Codes are added to support both 
 * 	                       XMC4000/XMC1000 devices.
 * 18 Oct 2013   v1.0.20   Updated as per coding guidelines	     
 * 17 Jul 2014   v1.0.28   End of line is corrected                  
 */

/*******************************************************************************
 ** INCLUDE FILES                                                             **
 ******************************************************************************/
#include "../../inc/NVIC002/NVIC002.h"
/**
 * @ingroup NVIC002_publicparam
 * @{
 */

   
const NVIC002_HandleType NVIC002_Handle0 = {
   /* Mapped NVIC Node */
  .NodeID      = 77 , 
  /* Node Interrupt Priority */
  .Priority    = 61,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node77 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle1 = {
   /* Mapped NVIC Node */
  .NodeID      = 76 , 
  /* Node Interrupt Priority */
  .Priority    = 61,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node76 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle10 = {
   /* Mapped NVIC Node */
  .NodeID      = 15 , 
  /* Node Interrupt Priority */
  .Priority    = 63,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node15 */
  .InterruptEnable = 0
};
   
const NVIC002_HandleType NVIC002_Handle11 = {
   /* Mapped NVIC Node */
  .NodeID      = 17 , 
  /* Node Interrupt Priority */
  .Priority    = 63,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node17 */
  .InterruptEnable = 0
};
   
const NVIC002_HandleType NVIC002_Handle12 = {
   /* Mapped NVIC Node */
  .NodeID      = 14 , 
  /* Node Interrupt Priority */
  .Priority    = 63,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node14 */
  .InterruptEnable = 0
};
   
const NVIC002_HandleType NVIC002_Handle13 = {
   /* Mapped NVIC Node */
  .NodeID      = 57 , 
  /* Node Interrupt Priority */
  .Priority    = 63,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node57 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle14 = {
   /* Mapped NVIC Node */
  .NodeID      = 63 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node63 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle15 = {
   /* Mapped NVIC Node */
  .NodeID      = 62 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node62 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle16 = {
   /* Mapped NVIC Node */
  .NodeID      = 61 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node61 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle17 = {
   /* Mapped NVIC Node */
  .NodeID      = 60 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node60 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle18 = {
   /* Mapped NVIC Node */
  .NodeID      = 64 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node64 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle19 = {
   /* Mapped NVIC Node */
  .NodeID      = 67 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node67 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle2 = {
   /* Mapped NVIC Node */
  .NodeID      = 90 , 
  /* Node Interrupt Priority */
  .Priority    = 63,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node90 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle20 = {
   /* Mapped NVIC Node */
  .NodeID      = 66 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node66 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle21 = {
   /* Mapped NVIC Node */
  .NodeID      = 65 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node65 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle22 = {
   /* Mapped NVIC Node */
  .NodeID      = 5 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node5 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle23 = {
   /* Mapped NVIC Node */
  .NodeID      = 8 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node8 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle24 = {
   /* Mapped NVIC Node */
  .NodeID      = 4 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node4 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle25 = {
   /* Mapped NVIC Node */
  .NodeID      = 3 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node3 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle26 = {
   /* Mapped NVIC Node */
  .NodeID      = 7 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node7 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle27 = {
   /* Mapped NVIC Node */
  .NodeID      = 6 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node6 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle28 = {
   /* Mapped NVIC Node */
  .NodeID      = 1 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node1 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle29 = {
   /* Mapped NVIC Node */
  .NodeID      = 2 , 
  /* Node Interrupt Priority */
  .Priority    = 60,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node2 */
  .InterruptEnable = 1
};
   
const NVIC002_HandleType NVIC002_Handle30 = {
   /* Mapped NVIC Node */
  .NodeID      = 108 , 
  /* Node Interrupt Priority */
  .Priority    = 63,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node108 */
  .InterruptEnable = 0
};
   
const NVIC002_HandleType NVIC002_Handle31 = {
   /* Mapped NVIC Node */
  .NodeID      = 69 , 
  /* Node Interrupt Priority */
  .Priority    = 63,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node69 */
  .InterruptEnable = 0
};
   
const NVIC002_HandleType NVIC002_Handle4 = {
   /* Mapped NVIC Node */
  .NodeID      = 16 , 
  /* Node Interrupt Priority */
  .Priority    = 63,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node16 */
  .InterruptEnable = 0
};
   
const NVIC002_HandleType NVIC002_Handle5 = {
   /* Mapped NVIC Node */
  .NodeID      = 32 , 
  /* Node Interrupt Priority */
  .Priority    = 63,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node32 */
  .InterruptEnable = 0
};
   
const NVIC002_HandleType NVIC002_Handle7 = {
   /* Mapped NVIC Node */
  .NodeID      = 33 , 
  /* Node Interrupt Priority */
  .Priority    = 63,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node33 */
  .InterruptEnable = 0
};
   
const NVIC002_HandleType NVIC002_Handle8 = {
   /* Mapped NVIC Node */
  .NodeID      = 30 , 
  /* Node Interrupt Priority */
  .Priority    = 63,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node30 */
  .InterruptEnable = 0
};
   
const NVIC002_HandleType NVIC002_Handle9 = {
   /* Mapped NVIC Node */
  .NodeID      = 31 , 
  /* Node Interrupt Priority */
  .Priority    = 63,  
  /* Node Interrupt SubPriority */
  .SubPriority = 0,
  /* Interrupt enable for Node31 */
  .InterruptEnable = 0
}; 
const NVIC002_HandleType * NVIC002_HandleArray[NVIC002_NUM_INSTANCES] =
{
   &NVIC002_Handle0, 
   &NVIC002_Handle1, 
   &NVIC002_Handle10, 
   &NVIC002_Handle11, 
   &NVIC002_Handle12, 
   &NVIC002_Handle13, 
   &NVIC002_Handle14, 
   &NVIC002_Handle15, 
   &NVIC002_Handle16, 
   &NVIC002_Handle17, 
   &NVIC002_Handle18, 
   &NVIC002_Handle19, 
   &NVIC002_Handle2, 
   &NVIC002_Handle20, 
   &NVIC002_Handle21, 
   &NVIC002_Handle22, 
   &NVIC002_Handle23, 
   &NVIC002_Handle24, 
   &NVIC002_Handle25, 
   &NVIC002_Handle26, 
   &NVIC002_Handle27, 
   &NVIC002_Handle28, 
   &NVIC002_Handle29, 
   &NVIC002_Handle30, 
   &NVIC002_Handle31, 
   &NVIC002_Handle4, 
   &NVIC002_Handle5, 
   &NVIC002_Handle7, 
   &NVIC002_Handle8, 
   &NVIC002_Handle9 

};
/**
 * @}
 */

/*CODE_BLOCK_END*/
