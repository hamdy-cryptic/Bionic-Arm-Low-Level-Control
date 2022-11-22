/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 15 DEC 2020                            */
/* Version   : 1                                      */
/******************************************************/

#include "DataTypes_and_BitMath.h"

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H 

/********** Registers *************/
#define SysTick_CTRL  *((volatile uint32*)0xE000E010)   // SysTick Control and Status Register
#define SysTick_LOAD  *((volatile uint32*)0xE000E014)   // SysTick Reload Value Register
#define SysTick_VAL   *((volatile uint32*)0xE000E018)   // SysTick Current Value Register
#define SysTick_CALIB *((volatile uint32*)0xE000E01c)   // SysTick Calibration Value Register

/********* SysTick_CTRL: Control and Status Bits ****************/

#define SysTick_CTRL_ENABLE    		 	 (1u << 0u)         // Enable counter
#define SysTick_CTRL_TICKINT   		   (0u << 1u)         // Counting down will assert SysTick exception request
#define SysTick_CTRL_CLKSOURCE 		   (1u << 2u)         // Use processor clock (AHB)
#define SysTick_CTRL_CLKSOURCE_BY8   (0u << 2u)         // Use processor clock (AHB/8)
#define SysTick_CTRL_COUNTFLAG 		   (1u << 16u)        // Returns 1 if timer is finished

/********* Private Functions ***********/

void SysTick_Handler (void);         					          // Handling function for the SysTick Interrupts 
uint32 Ticks2Millisec (uint32 ticks);					          // t_ms=(ticks/clk_frequency(MHz))*1000
uint32 Millisec2Ticks (uint32 t_ms);					          // ticks=(t_ms*clk_frequency(MHz))/1000
void MSTK_void_SysTick_Delay_Origin (uint32 t);         // The maximum allowed time is 2 seconds 

#endif
