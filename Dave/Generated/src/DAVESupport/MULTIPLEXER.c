/*******************************************************************************
**  DAVE App Name : DAVESupport       App Version: 1.0.42               
**  This file is generated by DAVE, User modification to this file will be    **
**  overwritten at the next code generation.                                  **
*******************************************************************************/


/*******************************************************************************
 Copyright (c) 2011, Infineon Technologies AG                                 **
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
** PLATFORM : Infineon <Microcontroller name, step>                           **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** MODIFICATION DATE : September 06, 2013                                     **
**                                                                            **
*******************************************************************************/
/**
 * @file  MULTIPLEXER.c
 *
 * @brief This file contains implementation of DAVE Support function which 
 * uses to configure multiplexer register values.
 * 24 July 2013 v1.0.34 Initial Version
 * 06 sep 2013 v1.0.36  UART001 : Mux : One instruction for output pins 
 *                      initialisation.
 *                      CAN001 & CAN002 : Avoid twice reset of the INIT bit in 
 *                      Can001_lNodeInit & DAVE_MUX_Init.
 *                      WR_REGHIB Macro definition has been changed.
 *                       
 *                      
 */

/*******************************************************************************
**                      Include Files                                         **
*******************************************************************************/
#include "../../inc/DAVESupport/DAVE3.h"

/*******************************************************************************
**                 Function declarations                                     **
*******************************************************************************/
/*******************************************************************************
** Syntax           : void DAVE_MUX_Init(void)                                **
**                                                                            **
** Reentrancy       : None                                                    **
**                                                                            **
** Parameters (in)  : void                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This is the Mux configuration                           **
**                                                                            **
*******************************************************************************/
           
void DAVE_MUX_Init(void)
{  
/*
 * CAN peripheral configuration:
 */                           
    //Node1 configuration:    
    WR_REG(CAN_NODE1->NPCR, CAN_NODE_NPCR_RXSEL_Msk, CAN_NODE_NPCR_RXSEL_Pos, RXD_SIGNAL2);
                     
    //Node2 configuration:    
    WR_REG(CAN_NODE2->NPCR, CAN_NODE_NPCR_RXSEL_Msk, CAN_NODE_NPCR_RXSEL_Pos, RXD_SIGNAL2);
                      
    //Message object 0 configuration:
    
    WR_REG(CAN_MO0->MOIPR, CAN_MO_MOIPR_RXINP_Msk, CAN_MO_MOIPR_RXINP_Pos, SRN1);
                                                                                                                                  
    /* Macros which makes the CAN peripheral to exit from the INITIALISATION mode to NORMAL mode */
#ifdef CAN_NODE0_ENABLE
    CAN_Handle0_NODE();
#endif
#ifdef CAN_NODE1_ENABLE    
    CAN_Handle1_NODE();
#endif    
#ifdef CAN_NODE2_ENABLE    
    CAN_Handle2_NODE(); 
#endif             	         
                                                          	         
                                              
      /* Variable to store the CCR_MODE values for various USIC channels */
      uint32_t UsicCcrMode[6] = {0};      
//********* MODULE USIC CONFIGURATIONS *************************	        
        
           
   /* Disable mode before configuring all USIC registers to avoid unintended edges */   
                
    UsicCcrMode[2] |= (uint32_t) RD_REG(USIC1_CH0->CCR, USIC_CH_CCR_MODE_Msk, USIC_CH_CCR_MODE_Pos);   
    WR_REG(USIC1_CH0->CCR, USIC_CH_CCR_MODE_Msk, USIC_CH_CCR_MODE_Pos,0);
                    
    UsicCcrMode[3] |= (uint32_t) RD_REG(USIC1_CH1->CCR, USIC_CH_CCR_MODE_Msk, USIC_CH_CCR_MODE_Pos); 
    WR_REG(USIC1_CH1->CCR, USIC_CH_CCR_MODE_Msk, USIC_CH_CCR_MODE_Pos,0);
         
      
    						
   /*USIC 0 Channel 0 Mux Related SFR/Bitfields Configurations*/ 									  					 				 				 		       				              				  					    					 					   				  					 				 				       				  										 									 					 					  									      					              					  						    					      
       						
   /*USIC 0 Channel 1 Mux Related SFR/Bitfields Configurations*/ 									  					 				 				 		       				              				  					    					 					   				  					 				 				       				  										 									 					 					  									      					              					  						    					      
         						
   /*USIC 1 Channel 0 Mux Related SFR/Bitfields Configurations*/ 						         
 WR_REG(USIC1_CH0->DX0CR, USIC_CH_DX0CR_DSEL_Msk, USIC_CH_DX0CR_DSEL_Pos,2); 
  			  					 				 				 		       				              				  					    					 					   				  					 				 				       				  										 									 					 					  									      					              					  						    					      
                 
   // Data Pointer & Buffer Size for Transmitter Buffer Control  
 WR_REG(USIC1_CH0->TBCTR, USIC_CH_TBCTR_DPTRSIZE_Msk, USIC_CH_TBCTR_DPTRSIZE_Pos,0x01000032);		/*    DPTR = 50,  SIZE = 1 */ 
           
  // Data Pointer & Buffer Size for Receiver Buffer Control  
 WR_REG(USIC1_CH0->RBCTR, USIC_CH_RBCTR_DPTRSIZE_Msk, USIC_CH_RBCTR_DPTRSIZE_Pos,0x01000030);		/*    DPTR = 48,  SIZE = 1 */ 
 						
   /*USIC 1 Channel 1 Mux Related SFR/Bitfields Configurations*/ 						         
 WR_REG(USIC1_CH1->DX0CR, USIC_CH_DX0CR_DSEL_Msk, USIC_CH_DX0CR_DSEL_Pos,2); 
  			  					 				 				 		       				              				  					    					 					   				  					 				 				       				  					    
 //Standard receive buffer event is enabled.                 
 WR_REG(USIC1_CH1->RBCTR, USIC_CH_RBCTR_SRBIEN_Msk, USIC_CH_RBCTR_SRBIEN_Pos,1);  
 					 									 					 					  									      					              					  						    					      
                 
   // Data Pointer & Buffer Size for Transmitter Buffer Control  
 WR_REG(USIC1_CH1->TBCTR, USIC_CH_TBCTR_DPTRSIZE_Msk, USIC_CH_TBCTR_DPTRSIZE_Pos,0x04000020);		/*    DPTR = 32,  SIZE = 4 */ 
         
  // Data Pointer & Buffer Size for Receiver Buffer Control  
 WR_REG(USIC1_CH1->RBCTR, USIC_CH_RBCTR_DPTRSIZE_Msk, USIC_CH_RBCTR_DPTRSIZE_Pos,0x05000000);		/*    DPTR = 0,  SIZE = 5 */ 
   						
   /*USIC 2 Channel 0 Mux Related SFR/Bitfields Configurations*/ 									  					 				 				 		       				              				  					    					 					   				  					 				 				       				  										 									 					 					  									      					              					  						    					      
       						
   /*USIC 2 Channel 1 Mux Related SFR/Bitfields Configurations*/ 									  					 				 				 		       				              				  					    					 					   				  					 				 				       				  										 									 					 					  									      					              					  						    					      
         
  
  /* Enable mode after configuring all USIC registers to avoid unintended edges */  
              
   WR_REG(USIC1_CH0->CCR, USIC_CH_CCR_MODE_Msk, USIC_CH_CCR_MODE_Pos,UsicCcrMode[2]);
                  
   WR_REG(USIC1_CH1->CCR, USIC_CH_CCR_MODE_Msk, USIC_CH_CCR_MODE_Pos,UsicCcrMode[3]);
               	         
                                                         	    
  //********* MODULE DLR CONFIGURATIONS *************************	                        				
  /*DLR Line 0 Mux Related SFR/Bitfields Configurations*/     				  
 WR_REG(DLR->SRSEL0, DLR_SRSEL0_RS0_Msk, DLR_SRSEL0_RS0_Pos,13); 
                    				
  /*DLR Line 1 Mux Related SFR/Bitfields Configurations*/     				  
 WR_REG(DLR->SRSEL0, DLR_SRSEL0_RS1_Msk, DLR_SRSEL0_RS1_Pos,13); 
                    				
  /*DLR Line 2 Mux Related SFR/Bitfields Configurations*/     				  
 WR_REG(DLR->SRSEL0, DLR_SRSEL0_RS2_Msk, DLR_SRSEL0_RS2_Pos,13); 
                    				
  /*DLR Line 3 Mux Related SFR/Bitfields Configurations*/     				  
 WR_REG(DLR->SRSEL0, DLR_SRSEL0_RS3_Msk, DLR_SRSEL0_RS3_Pos,13); 
                    				
  /*DLR Line 4 Mux Related SFR/Bitfields Configurations*/     				                    				
  /*DLR Line 5 Mux Related SFR/Bitfields Configurations*/     				                    				
  /*DLR Line 6 Mux Related SFR/Bitfields Configurations*/     				                    				
  /*DLR Line 7 Mux Related SFR/Bitfields Configurations*/     				             				
  /*DLR Line 8 Mux Related SFR/Bitfields Configurations*/     				  
 WR_REG(DLR->SRSEL1, DLR_SRSEL1_RS8_Msk, DLR_SRSEL1_RS8_Pos,1); 
             				
  /*DLR Line 9 Mux Related SFR/Bitfields Configurations*/     				  
 WR_REG(DLR->SRSEL1, DLR_SRSEL1_RS9_Msk, DLR_SRSEL1_RS9_Pos,1); 
             				
  /*DLR Line 10 Mux Related SFR/Bitfields Configurations*/     				  
 WR_REG(DLR->SRSEL1, DLR_SRSEL1_RS10_Msk, DLR_SRSEL1_RS10_Pos,1); 
             				
  /*DLR Line 11 Mux Related SFR/Bitfields Configurations*/     				  
 WR_REG(DLR->SRSEL1, DLR_SRSEL1_RS11_Msk, DLR_SRSEL1_RS11_Pos,1); 
   	          	         
                                              
        //********* Capture/Compare Unit 4 (CAPCOM4) CONFIGURATIONS ************************* 
                       
    // Configuring CCU43_CC43SRS  =  Service Request Selector

    WR_REG(CCU43_CC43->SRS, CCU4_CC4_SRS_POSR_Msk, CCU4_CC4_SRS_POSR_Pos, CCU_SR1);                	         
                                                          	         
                 	            
  //********* MODULE DMA0 CONFIGURATIONS ************************* 										      					           
  /*DMA 0 Channel 0 Mux Related SFR/Bitfields Configurations*/
 
	         
  WR_REG(GPDMA0_CH0->CFGH, GPDMA0_CH_CFGH_SRC_PER_Msk, GPDMA0_CH_CFGH_SRC_PER_Pos,2);
   					           
  /*DMA 0 Channel 1 Mux Related SFR/Bitfields Configurations*/
 
	         
  WR_REG(GPDMA0_CH1->CFGH, GPDMA0_CH_CFGH_SRC_PER_Msk, GPDMA0_CH_CFGH_SRC_PER_Pos,3);
   					           
  /*DMA 0 Channel 2 Mux Related SFR/Bitfields Configurations*/
 
	      					           
  /*DMA 0 Channel 3 Mux Related SFR/Bitfields Configurations*/
 
	      					           
  /*DMA 0 Channel 4 Mux Related SFR/Bitfields Configurations*/
 
	         
  WR_REG(GPDMA0_CH4->CFGH, GPDMA0_CH_CFGH_SRC_PER_Msk, GPDMA0_CH_CFGH_SRC_PER_Pos,1);
   					           
  /*DMA 0 Channel 5 Mux Related SFR/Bitfields Configurations*/
 
	      					           
  /*DMA 0 Channel 6 Mux Related SFR/Bitfields Configurations*/
 
	      					           
  /*DMA 0 Channel 7 Mux Related SFR/Bitfields Configurations*/
 
	       				  	
	                                                	         
                                              
        //********* Capture/Compare Unit 8 (CAPCOM8) CONFIGURATIONS *************************
                      
            // Configuring CCU80 CC80INS - Input Selector Configuration

    WR_REG(CCU80_CC80->INS, CCU8_CC8_INS_EV2IS_Msk, CCU8_CC8_INS_EV2IS_Pos, CCU8xINyC);                   
                      
            // Configuring CCU80 CC81INS - Input Selector Configuration

    WR_REG(CCU80_CC81->INS, CCU8_CC8_INS_EV2IS_Msk, CCU8_CC8_INS_EV2IS_Pos, CCU8xINyC);                   
                      
            // Configuring CCU80 CC82INS - Input Selector Configuration

    WR_REG(CCU80_CC82->INS, CCU8_CC8_INS_EV2IS_Msk, CCU8_CC8_INS_EV2IS_Pos, CCU8xINyC);                   
                      
            // Configuring CCU80 CC83INS - Input Selector Configuration

    WR_REG(CCU80_CC83->INS, CCU8_CC8_INS_EV2IS_Msk, CCU8_CC8_INS_EV2IS_Pos, CCU8xINyC);                   
                       
            // Configuring CCU80_CC80SRS  =  Service Request Selector

            WR_REG(CCU80_CC80->SRS, CCU8_CC8_SRS_E2SR_Msk, CCU8_CC8_SRS_E2SR_Pos, CCU_SR3);    
                       
            // Configuring CCU80_CC81SRS  =  Service Request Selector

            WR_REG(CCU80_CC81->SRS, CCU8_CC8_SRS_E2SR_Msk, CCU8_CC8_SRS_E2SR_Pos, CCU_SR2);    
                       
            // Configuring CCU80_CC82SRS  =  Service Request Selector

            WR_REG(CCU80_CC82->SRS, CCU8_CC8_SRS_E2SR_Msk, CCU8_CC8_SRS_E2SR_Pos, CCU_SR1);    
                      
            // Configuring CCU81 CC80INS - Input Selector Configuration

    WR_REG(CCU81_CC80->INS, CCU8_CC8_INS_EV2IS_Msk, CCU8_CC8_INS_EV2IS_Pos, CCU8xINyB);                   
                      
            // Configuring CCU81 CC81INS - Input Selector Configuration

    WR_REG(CCU81_CC81->INS, CCU8_CC8_INS_EV2IS_Msk, CCU8_CC8_INS_EV2IS_Pos, CCU8xINyB);                   
                      
            // Configuring CCU81 CC82INS - Input Selector Configuration

    WR_REG(CCU81_CC82->INS, CCU8_CC8_INS_EV2IS_Msk, CCU8_CC8_INS_EV2IS_Pos, CCU8xINyB);                   
                      
            // Configuring CCU81 CC83INS - Input Selector Configuration

    WR_REG(CCU81_CC83->INS, CCU8_CC8_INS_EV2IS_Msk, CCU8_CC8_INS_EV2IS_Pos, CCU8xINyB);                   
                       
            // Configuring CCU81_CC80SRS  =  Service Request Selector

            WR_REG(CCU81_CC80->SRS, CCU8_CC8_SRS_E2SR_Msk, CCU8_CC8_SRS_E2SR_Pos, CCU_SR1);    
                       
            // Configuring CCU81_CC81SRS  =  Service Request Selector

            WR_REG(CCU81_CC81->SRS, CCU8_CC8_SRS_E2SR_Msk, CCU8_CC8_SRS_E2SR_Pos, CCU_SR2);    
                       
            // Configuring CCU81_CC82SRS  =  Service Request Selector

            WR_REG(CCU81_CC82->SRS, CCU8_CC8_SRS_E2SR_Msk, CCU8_CC8_SRS_E2SR_Pos, CCU_SR3);                	         
                                                          	         
                                  
                  /*VADC GROUP0 Mux Related SFR/Bitfields Configurations*/  						                                                   						         						                         						                          						         						                                   						          						          						          						                                    						         
  WR_REG(VADC_G0->ALIAS, VADC_G_ALIAS_ALIAS0_Msk, VADC_G_ALIAS_ALIAS0_Pos,1); 
   						          

					 						         
  WR_REG(VADC_G0->CHCTR[0], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,8); 
    						          						          						          						          						         
  WR_REG(VADC_G0->CHCTR[5], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,15); 
    						         
  WR_REG(VADC_G0->CHCTR[6], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,4); 
    						         
  WR_REG(VADC_G0->CHCTR[7], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,5); 
          
                                                                                                                						                            						                          						                            						                             						                          						                             						                           						                          						                            						                    						                         						                         						         
  WR_REG(VADC_G0->REVNP0, VADC_G_REVNP0_REV4NP_Msk, VADC_G_REVNP0_REV4NP_Pos,4); 
                 						         
  WR_REG(VADC_G0->REVNP0, VADC_G_REVNP0_REV5NP_Msk, VADC_G_REVNP0_REV5NP_Pos,7); 
                 						                          						                          						            
  WR_REG(VADC_G0->REVNP1, VADC_G_REVNP1_REV8NP_Msk, VADC_G_REVNP1_REV8NP_Pos,5); 
                                   						                             						                        						                            						                     						                         						                       						               
  WR_REG(VADC_G0->REVNP1, VADC_G_REVNP1_REV15NP_Msk, VADC_G_REVNP1_REV15NP_Pos,6); 
                         
                  /*VADC GROUP1 Mux Related SFR/Bitfields Configurations*/  						                                                   						         						                         						                          						         						                                   						          						          						          						                                    						         						          

					 						          						          						         
  WR_REG(VADC_G1->CHCTR[2], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,2); 
    						         
  WR_REG(VADC_G1->CHCTR[3], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,1); 
    						         
  WR_REG(VADC_G1->CHCTR[4], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,15); 
    						         
  WR_REG(VADC_G1->CHCTR[5], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,7); 
    						          						         
  WR_REG(VADC_G1->CHCTR[7], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,3); 
          
                                                                                                                						                            						                          						                            						                             						                          						                             						                           						                          						                            						                    						                         						                         						                       						                       						                          						                          						                                         						                             						                        						                            						                     						                         						                       						                               
                  /*VADC GROUP2 Mux Related SFR/Bitfields Configurations*/  						                                                   						         						                         						                          						         						                                   						          						          						          						                                    						         						          

					 						          						          						          						         
  WR_REG(VADC_G2->CHCTR[3], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,7); 
    						         
  WR_REG(VADC_G2->CHCTR[4], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,10); 
    						         
  WR_REG(VADC_G2->CHCTR[5], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,2); 
    						         
  WR_REG(VADC_G2->CHCTR[6], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,3); 
    						         
  WR_REG(VADC_G2->CHCTR[7], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,1); 
          
                                                                                                                						                            						                          						                            						                             						                          						                             						                           						                          						                            						                    						                         						                         						                       						                       						                          						                          						                                         						                             						                        						                            						                     						                         						                       						                               
                  /*VADC GROUP3 Mux Related SFR/Bitfields Configurations*/  						                                                   						         						                         						                          						         						                                   						          						          						          						                                    						         						          

					 						          						          						          						         
  WR_REG(VADC_G3->CHCTR[3], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,4); 
    						         
  WR_REG(VADC_G3->CHCTR[4], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,9); 
    						         
  WR_REG(VADC_G3->CHCTR[5], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,8); 
    						         
  WR_REG(VADC_G3->CHCTR[6], VADC_G_CHCTR_RESREG_Msk, VADC_G_CHCTR_RESREG_Pos,5); 
    						                
                                                                                                                						                            						                          						                            						                             						                          						                             						                           						                          						                            						                    						                         						                         						                       						         
  WR_REG(VADC_G3->REVNP0, VADC_G_REVNP0_REV5NP_Msk, VADC_G_REVNP0_REV5NP_Pos,3); 
                 						                          						                          						            
  WR_REG(VADC_G3->REVNP1, VADC_G_REVNP1_REV8NP_Msk, VADC_G_REVNP1_REV8NP_Pos,1); 
                                   						          
  WR_REG(VADC_G3->REVNP1, VADC_G_REVNP1_REV9NP_Msk, VADC_G_REVNP1_REV9NP_Pos,2); 
                       						                        						                            						                     						                         						                       						                                 
               /*VADC GLOBAL RESULT Mux Related SFR/Bitfields Configurations*/  						                       						                     						                                 
               /*VADC BACKGROUND Source Mux Related SFR/Bitfields Configurations*/  						                  						                						                                                                                      	         
                                     
       /*        SCU Macro definitions     */                                    	         
                                            
/*        ERU0 Macro definitions:         */  

  WR_REG(ERU0->EXISEL, ERU_EXISEL_EXS0A_Msk, ERU_EXISEL_EXS0A_Pos, SIGNAL_ERU_xA2);                /*    ERU0_EXISEL_EXS0A */

  WR_REG(ERU0->EXICON[0], ERU_EXICON_PE_Msk, ERU_EXICON_PE_Pos, SIGNAL_TR1);                            /*    ERU0_EXICON[0]_PE */

  WR_REG(ERU0->EXICON[0], ERU_EXICON_OCS_Msk, ERU_EXICON_OCS_Pos, SIGNAL_TRx2);                        /*    ERU0_EXICON[0]_OCS */

  WR_REG(ERU0->EXISEL, ERU_EXISEL_EXS1B_Msk, ERU_EXISEL_EXS1B_Pos, SIGNAL_ERU_xB2);                /*    ERU0_EXISEL_EXS1B */

  WR_REG(ERU0->EXICON[1], ERU_EXICON_PE_Msk, ERU_EXICON_PE_Pos, SIGNAL_TR1);                            /*    ERU0_EXICON[1]_PE */

  WR_REG(ERU0->EXISEL, ERU_EXISEL_EXS2B_Msk, ERU_EXISEL_EXS2B_Pos, SIGNAL_ERU_xB2);                /*    ERU0_EXISEL_EXS2B */

  WR_REG(ERU0->EXICON[2], ERU_EXICON_PE_Msk, ERU_EXICON_PE_Pos, SIGNAL_TR1);                            /*    ERU0_EXICON[2]_PE */

  WR_REG(ERU0->EXICON[2], ERU_EXICON_OCS_Msk, ERU_EXICON_OCS_Pos, SIGNAL_TRx1);                        /*    ERU0_EXICON[2]_OCS */

  WR_REG(ERU0->EXICON[3], ERU_EXICON_PE_Msk, ERU_EXICON_PE_Pos, SIGNAL_TR1);                            /*    ERU0_EXICON[3]_PE */

  WR_REG(ERU0->EXICON[3], ERU_EXICON_OCS_Msk, ERU_EXICON_OCS_Pos, SIGNAL_TRx3);                        /*    ERU0_EXICON[3]_OCS */  
/*        ERU1 Macro definitions:         */  

  WR_REG(ERU1->EXICON[0], ERU_EXICON_PE_Msk, ERU_EXICON_PE_Pos, SIGNAL_TR1);                            /*    ERU1_EXICON[0]_PE */

  WR_REG(ERU1->EXICON[0], ERU_EXICON_OCS_Msk, ERU_EXICON_OCS_Pos, SIGNAL_TRx1);                        /*    ERU1_EXICON[0]_OCS */

  WR_REG(ERU1->EXICON[1], ERU_EXICON_PE_Msk, ERU_EXICON_PE_Pos, SIGNAL_TR1);                            /*    ERU1_EXICON[1]_PE */

  WR_REG(ERU1->EXICON[1], ERU_EXICON_OCS_Msk, ERU_EXICON_OCS_Pos, SIGNAL_TRx2);                        /*    ERU1_EXICON[1]_OCS */

  WR_REG(ERU1->EXICON[2], ERU_EXICON_PE_Msk, ERU_EXICON_PE_Pos, SIGNAL_TR1);                            /*    ERU1_EXICON[2]_PE */

  WR_REG(ERU1->EXICON[2], ERU_EXICON_OCS_Msk, ERU_EXICON_OCS_Pos, SIGNAL_TRx3);                        /*    ERU1_EXICON[2]_OCS */

  WR_REG(ERU1->EXICON[3], ERU_EXICON_PE_Msk, ERU_EXICON_PE_Pos, SIGNAL_TR1);                            /*    ERU1_EXICON[3]_PE */                	         
                                                          	         
                 	            
  //********* MODULE DMA1 CONFIGURATIONS ************************* 										    					           
  /*DMA 1 Channel 0 Mux Related SFR/Bitfields Configurations*/
 
	         
  WR_REG(GPDMA1_CH0->CFGH, GPDMA1_CH_CFGH_SRC_PER_Msk, GPDMA1_CH_CFGH_SRC_PER_Pos,1);
   					           
  /*DMA 1 Channel 1 Mux Related SFR/Bitfields Configurations*/
 
	      					           
  /*DMA 1 Channel 2 Mux Related SFR/Bitfields Configurations*/
 
	         
  WR_REG(GPDMA1_CH2->CFGH, GPDMA1_CH_CFGH_SRC_PER_Msk, GPDMA1_CH_CFGH_SRC_PER_Pos,2);
   					           
  /*DMA 1 Channel 3 Mux Related SFR/Bitfields Configurations*/
 
	         
  WR_REG(GPDMA1_CH3->CFGH, GPDMA1_CH_CFGH_SRC_PER_Msk, GPDMA1_CH_CFGH_SRC_PER_Pos,3);
    				  	
	                                                	         
                                                          	         
                                          

/*        PORT Macro definitions for IOCR_OE, IOCR_PCR & HWSEL_HW     */                                      
  WR_REG(PORT0->IOCR0, 0xb8U, PORT_IOCR_PC0_PCR_Pos, 0x13U);                /*P0.0 : PORT0_IOCR0_PC0_PCR and PORT0_IOCR0_PC0_OE */					   
					                         
  WR_REG(PORT0->IOCR0, 0xb800U, PORT_IOCR_PC1_PCR_Pos, 0x13U);                /*P0.1 : PORT0_IOCR0_PC1_PCR and PORT0_IOCR0_PC1_OE */					   
					                         
  WR_REG(PORT0->IOCR0, 0xb80000U, PORT_IOCR_PC2_PCR_Pos, 0x13U);                /*P0.2 : PORT0_IOCR0_PC2_PCR and PORT0_IOCR0_PC2_OE */					   
					                         
  WR_REG(PORT0->IOCR0, PORT_IOCR_PC3_OE_Msk, PORT_IOCR_PC3_OE_Pos, PORT_IOCR_OE1);                /*    P0.3 : PORT0_IOCR0_PC3_OE */					   
					                         
  WR_REG(PORT0->IOCR4, PORT_IOCR_PC0_OE_Msk, PORT_IOCR_PC0_OE_Pos, PORT_IOCR_OE1);                /*    P0.4 : PORT0_IOCR4_PC4_OE */					   
					                         
  WR_REG(PORT0->IOCR4, 0xb80000U, PORT_IOCR_PC2_PCR_Pos, 0x13U);                /*P0.6 : PORT0_IOCR4_PC6_PCR and PORT0_IOCR4_PC6_OE */					   
					   
              
  WR_REG(PORT0->HWSEL, PORT0_HWSEL_HW8_Msk, PORT0_HWSEL_HW8_Pos, PORT_HWSEL_SW);                    /*    P0.8 : PORT0_HWSEL_HW8 */                         
  WR_REG(PORT0->IOCR8, PORT_IOCR_PC0_OE_Msk, PORT_IOCR_PC0_OE_Pos, PORT_IOCR_OE1);                /*    P0.8 : PORT0_IOCR8_PC8_OE */					   
					                         
  WR_REG(PORT0->IOCR8, PORT_IOCR_PC1_OE_Msk, PORT_IOCR_PC1_OE_Pos, PORT_IOCR_OE1);                /*    P0.9 : PORT0_IOCR8_PC9_OE */					   
					                         
  WR_REG(PORT0->IOCR8, PORT_IOCR_PC2_OE_Msk, PORT_IOCR_PC2_OE_Pos, PORT_IOCR_OE1);                /*    P0.10 : PORT0_IOCR8_PC10_OE */					   
					                         
  WR_REG(PORT0->IOCR8, 0xb8000000U, PORT_IOCR_PC3_PCR_Pos, 0x13U);                /*P0.11 : PORT0_IOCR8_PC11_PCR and PORT0_IOCR8_PC11_OE */					   
					                         
  WR_REG(PORT0->IOCR12, PORT_IOCR_PC1_OE_Msk, PORT_IOCR_PC1_OE_Pos, PORT_IOCR_OE1);                /*    P0.13 : PORT0_IOCR12_PC13_OE */					   
					                         
  WR_REG(PORT0->IOCR12, PORT_IOCR_PC2_OE_Msk, PORT_IOCR_PC2_OE_Pos, PORT_IOCR_OE1);                /*    P0.14 : PORT0_IOCR12_PC14_OE */					   
					                         
  WR_REG(PORT0->IOCR12, PORT_IOCR_PC3_OE_Msk, PORT_IOCR_PC3_OE_Pos, PORT_IOCR_OE1);                /*    P0.15 : PORT0_IOCR12_PC15_OE */					   
					                         
  WR_REG(PORT1->IOCR4, 0xb8U, PORT_IOCR_PC0_PCR_Pos, 0x14U);                /*P1.4 : PORT1_IOCR4_PC4_PCR and PORT1_IOCR4_PC4_OE */					   
					                         
  WR_REG(PORT1->IOCR4, 0xb800U, PORT_IOCR_PC1_PCR_Pos, 0x14U);                /*P1.5 : PORT1_IOCR4_PC5_PCR and PORT1_IOCR4_PC5_OE */					   
					                         
  WR_REG(PORT1->IOCR4, PORT_IOCR_PC3_OE_Msk, PORT_IOCR_PC3_OE_Pos, PORT_IOCR_OE1);                /*    P1.7 : PORT1_IOCR4_PC7_OE */					   
					                         
  WR_REG(PORT1->IOCR8, PORT_IOCR_PC0_OE_Msk, PORT_IOCR_PC0_OE_Pos, PORT_IOCR_OE1);                /*    P1.8 : PORT1_IOCR8_PC8_OE */					   
					                         
  WR_REG(PORT1->IOCR8, 0xb80000U, PORT_IOCR_PC2_PCR_Pos, 0x13U);                /*P1.10 : PORT1_IOCR8_PC10_PCR and PORT1_IOCR8_PC10_OE */					   
					                         
  WR_REG(PORT1->IOCR8, 0xb8000000U, PORT_IOCR_PC3_PCR_Pos, 0x13U);                /*P1.11 : PORT1_IOCR8_PC11_PCR and PORT1_IOCR8_PC11_OE */					   
					                         
  WR_REG(PORT1->IOCR12, 0xb8U, PORT_IOCR_PC0_PCR_Pos, 0x13U);                /*P1.12 : PORT1_IOCR12_PC12_PCR and PORT1_IOCR12_PC12_OE */					   
					                         
  WR_REG(PORT1->IOCR12, PORT_IOCR_PC2_OE_Msk, PORT_IOCR_PC2_OE_Pos, PORT_IOCR_OE1);                /*    P1.14 : PORT1_IOCR12_PC14_OE */					   
					                         
  WR_REG(PORT1->IOCR12, 0xb8000000U, PORT_IOCR_PC3_PCR_Pos, 0x13U);                /*P1.15 : PORT1_IOCR12_PC15_PCR and PORT1_IOCR12_PC15_OE */					   
					                         
  WR_REG(PORT2->IOCR12, 0xb80000U, PORT_IOCR_PC2_PCR_Pos, 0x12U);                /*P2.14 : PORT2_IOCR12_PC14_PCR and PORT2_IOCR12_PC14_OE */					   
					                         
  WR_REG(PORT3->IOCR0, PORT_IOCR_PC3_OE_Msk, PORT_IOCR_PC3_OE_Pos, PORT_IOCR_OE1);                /*    P3.3 : PORT3_IOCR0_PC3_OE */					   
					                         
  WR_REG(PORT3->IOCR4, PORT_IOCR_PC0_OE_Msk, PORT_IOCR_PC0_OE_Pos, PORT_IOCR_OE1);                /*    P3.4 : PORT3_IOCR4_PC4_OE */					   
					                         
  WR_REG(PORT3->IOCR4, PORT_IOCR_PC1_OE_Msk, PORT_IOCR_PC1_OE_Pos, PORT_IOCR_OE1);                /*    P3.5 : PORT3_IOCR4_PC5_OE */					   
					                         
  WR_REG(PORT3->IOCR4, PORT_IOCR_PC2_OE_Msk, PORT_IOCR_PC2_OE_Pos, PORT_IOCR_OE1);                /*    P3.6 : PORT3_IOCR4_PC6_OE */					   
					                         
  WR_REG(PORT3->IOCR4, PORT_IOCR_PC3_OE_Msk, PORT_IOCR_PC3_OE_Pos, PORT_IOCR_OE1);                /*    P3.7 : PORT3_IOCR4_PC7_OE */					   
					                         
  WR_REG(PORT3->IOCR8, PORT_IOCR_PC0_OE_Msk, PORT_IOCR_PC0_OE_Pos, PORT_IOCR_OE1);                /*    P3.8 : PORT3_IOCR8_PC8_OE */					   
					                         
  WR_REG(PORT3->IOCR8, 0xb800U, PORT_IOCR_PC1_PCR_Pos, 0x12U);                /*P3.9 : PORT3_IOCR8_PC9_PCR and PORT3_IOCR8_PC9_OE */					   
					                         
  WR_REG(PORT3->IOCR8, PORT_IOCR_PC2_OE_Msk, PORT_IOCR_PC2_OE_Pos, PORT_IOCR_OE1);                /*    P3.10 : PORT3_IOCR8_PC10_OE */					   
					                         
  WR_REG(PORT3->IOCR8, PORT_IOCR_PC3_OE_Msk, PORT_IOCR_PC3_OE_Pos, PORT_IOCR_OE1);                /*    P3.11 : PORT3_IOCR8_PC11_OE */					   
					                         
  WR_REG(PORT3->IOCR12, PORT_IOCR_PC0_OE_Msk, PORT_IOCR_PC0_OE_Pos, PORT_IOCR_OE1);                /*    P3.12 : PORT3_IOCR12_PC12_OE */					   
					                         
  WR_REG(PORT3->IOCR12, 0xb80000U, PORT_IOCR_PC2_PCR_Pos, 0x12U);                /*P3.14 : PORT3_IOCR12_PC14_PCR and PORT3_IOCR12_PC14_OE */					   
					                         
  WR_REG(PORT3->IOCR12, 0xb8000000U, PORT_IOCR_PC3_PCR_Pos, 0x12U);                /*P3.15 : PORT3_IOCR12_PC15_PCR and PORT3_IOCR12_PC15_OE */					   
					                         
  WR_REG(PORT4->IOCR0, PORT_IOCR_PC0_OE_Msk, PORT_IOCR_PC0_OE_Pos, PORT_IOCR_OE1);                /*    P4.0 : PORT4_IOCR0_PC0_OE */					   
					                         
  WR_REG(PORT4->IOCR0, PORT_IOCR_PC1_OE_Msk, PORT_IOCR_PC1_OE_Pos, PORT_IOCR_OE1);                /*    P4.1 : PORT4_IOCR0_PC1_OE */					   
					                         
  WR_REG(PORT4->IOCR0, PORT_IOCR_PC3_OE_Msk, PORT_IOCR_PC3_OE_Pos, PORT_IOCR_OE1);                /*    P4.3 : PORT4_IOCR0_PC3_OE */					   
					                         
  WR_REG(PORT4->IOCR4, PORT_IOCR_PC0_OE_Msk, PORT_IOCR_PC0_OE_Pos, PORT_IOCR_OE1);                /*    P4.4 : PORT4_IOCR4_PC4_OE */					   
					                         
  WR_REG(PORT4->IOCR4, PORT_IOCR_PC1_OE_Msk, PORT_IOCR_PC1_OE_Pos, PORT_IOCR_OE1);                /*    P4.5 : PORT4_IOCR4_PC5_OE */					   
					                         
  WR_REG(PORT4->IOCR4, 0xb8000000U, PORT_IOCR_PC3_PCR_Pos, 0x12U);                /*P4.7 : PORT4_IOCR4_PC7_PCR and PORT4_IOCR4_PC7_OE */					   
					                         
  WR_REG(PORT5->IOCR4, PORT_IOCR_PC1_OE_Msk, PORT_IOCR_PC1_OE_Pos, PORT_IOCR_OE1);                /*    P5.5 : PORT5_IOCR4_PC5_OE */					   
					                         
  WR_REG(PORT5->IOCR8, 0xb8U, PORT_IOCR_PC0_PCR_Pos, 0x12U);                /*P5.8 : PORT5_IOCR8_PC8_PCR and PORT5_IOCR8_PC8_OE */					   
					                         
  WR_REG(PORT5->IOCR8, 0xb800U, PORT_IOCR_PC1_PCR_Pos, 0x13U);                /*P5.9 : PORT5_IOCR8_PC9_PCR and PORT5_IOCR8_PC9_OE */					   
					                         
  WR_REG(PORT5->IOCR8, 0xb80000U, PORT_IOCR_PC2_PCR_Pos, 0x13U);                /*P5.10 : PORT5_IOCR8_PC10_PCR and PORT5_IOCR8_PC10_OE */					   
					                         
  WR_REG(PORT5->IOCR8, 0xb8000000U, PORT_IOCR_PC3_PCR_Pos, 0x13U);                /*P5.11 : PORT5_IOCR8_PC11_PCR and PORT5_IOCR8_PC11_OE */					   
					                         
  WR_REG(PORT6->IOCR0, 0xb8U, PORT_IOCR_PC0_PCR_Pos, 0x13U);                /*P6.0 : PORT6_IOCR0_PC0_PCR and PORT6_IOCR0_PC0_OE */					   
					                         
  WR_REG(PORT6->IOCR0, 0xb800U, PORT_IOCR_PC1_PCR_Pos, 0x13U);                /*P6.1 : PORT6_IOCR0_PC1_PCR and PORT6_IOCR0_PC1_OE */					   
					                         
  WR_REG(PORT6->IOCR0, PORT_IOCR_PC2_OE_Msk, PORT_IOCR_PC2_OE_Pos, PORT_IOCR_OE1);                /*    P6.2 : PORT6_IOCR0_PC2_OE */					   
					                         
  WR_REG(PORT6->IOCR0, PORT_IOCR_PC3_OE_Msk, PORT_IOCR_PC3_OE_Pos, PORT_IOCR_OE1);                /*    P6.3 : PORT6_IOCR0_PC3_OE */					   
					                         
  WR_REG(PORT6->IOCR4, PORT_IOCR_PC0_OE_Msk, PORT_IOCR_PC0_OE_Pos, PORT_IOCR_OE1);                /*    P6.4 : PORT6_IOCR4_PC4_OE */					   
					                         
  WR_REG(PORT6->IOCR4, PORT_IOCR_PC1_OE_Msk, PORT_IOCR_PC1_OE_Pos, PORT_IOCR_OE1);                /*    P6.5 : PORT6_IOCR4_PC5_OE */					   
					      
}


/*******************************************************************************
** Syntax           : void DAVE_MUX_PreInit(void)                             **
**                                                                            **
** Reentrancy       : None                                                    **
**                                                                            **
** Parameters (in)  : void                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This is the Mux configuration                           **
**                                                                            **
*******************************************************************************/
 
void DAVE_MUX_PreInit(void)
{                                                        

/*        PORT Macro definitions for IOCR_OE, IOCR_PCR & HWSEL_HW     */                   
}

