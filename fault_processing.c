#include <DAVE3.h>

void SystemCoreSetup(void) 
{ 
uint32_t temp; 

NVIC_SetPriorityGrouping(1U); 

/* relocate vector table */ 
__disable_irq(); 

//#if !defined(__TASKING__)
//SCB->VTOR = (uint32_t)(&__Vectors);
//#endif

__DSB(); 
__enable_irq(); 

//#if ((__FPU_PRESENT == 1) && (__FPU_USED == 1))
//SCB->CPACR |= ((3UL < 10*2)="" |="" set="" cp10="" full="" access="" */="">
//(3UL < 11*2)="" );="" set="" cp11="" full="" access="" */="">
//#endif
/* Set flash wait states */ 
temp = FLASH0->FCON; 
temp &= ~FLASH_FCON_WSPFLASH_Msk; 
//temp |= PMU_FLASH_WS;
FLASH0->FCON = temp; 

/* Disable memory management fault */ 
SCB->SHCSR &= ~SCB_SHCSR_MEMFAULTENA_Msk; 

/* Disable bus fault */ 
SCB->SHCSR &= ~SCB_SHCSR_BUSFAULTENA_Msk; 

/* Disable usage fault */ 
SCB->SHCSR &= ~SCB_SHCSR_USGFAULTENA_Msk; } 

volatile uint32_t stacked_r0; 
volatile uint32_t stacked_r1; 
volatile uint32_t stacked_r2; 
volatile uint32_t stacked_r3; 
volatile uint32_t stacked_r12; 
volatile uint32_t stacked_lr; 
volatile uint32_t stacked_pc; 
volatile uint32_t stacked_psr; 
volatile uint32_t _CFSR; 
volatile uint32_t _HFSR; 
volatile uint32_t _DFSR; 
volatile uint32_t _AFSR; 
volatile uint32_t _BFAR; 
volatile uint32_t _MMAR; 

/** 
* This is called from the HardFault_Handler with a pointer the Fault stack 
* as the parameter. We can then read the values from the stack and place them 
* into local variables for ease of reading. 
* We then read the various Fault Status and Address Registers to help decode 
* cause of the fault. 
* The function ends with a BKPT instruction to force control back into the debugger 
* Original code from http://www.support.code-red-tech.com/CodeRedWiki/DebugHardFault 
*/ 
#if defined(__GNUC__) 
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#endif 
__attribute__((naked)) void __HardFault_Handler(uint32_t args[]) { 

// Configurable Fault Status Register 
// Consists of MMSR, BFSR and UFSR 
_CFSR = SCB->CFSR; 

// Hard Fault Status Register 
_HFSR = SCB->HFSR; 

// Debug Fault Status Register 
_DFSR = SCB->DFSR; 

// Auxiliary Fault Status Register 
_AFSR = SCB->AFSR; 

// Read the Fault Address Registers. These may not contain valid values. 
// Check BFARVALID/MMARVALID to see if they are valid values 
// MemManage Fault Address Register 
_MMAR = SCB->MMFAR; 

// Bus Fault Address Register 
_BFAR = SCB->BFAR; 

stacked_r0 = ((uint32_t)args[0]); 
stacked_r1 = ((uint32_t)args[1]); 
stacked_r2 = ((uint32_t)args[2]); 
stacked_r3 = ((uint32_t)args[3]); 
stacked_r12 = ((uint32_t)args[4]); 
stacked_lr = ((uint32_t)args[5]); 
stacked_pc = ((uint32_t)args[6]); 
stacked_psr = ((uint32_t)args[7]); 

__asm("BKPT 0\n") ; // Break into the debugger 

} 
