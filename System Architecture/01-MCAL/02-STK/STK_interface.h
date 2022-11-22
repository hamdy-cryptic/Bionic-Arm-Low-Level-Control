/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 15 DEC 2020                            */
/* Version   : 1                                      */
/******************************************************/

#include "DataTypes_and_BitMath.h"
#include "STD_TYPES.h"

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

// The used Functions in the driver //

void MSTK_void_SysTick_Initialize (void);            	/* The initializing function for the SysTick timer */
void MSTK_void_SysTick_Delay (uint32 t);             	/* A delay function that holds the programs for t seconds */

uint32 MSTK_uint32_SysTick_ElapsedTime (void);       	/* Returns the elapsed time since the initialization of the SysTick timer */
//Can be used after the pause and resume functions are used
void MSTK_void_SysTick_TimePause (void);             	/* Pausing the Systick time until its enabled again by the resume function */
void MSTK_void_SysTick_TimeResume (void);            	/* Resuming the SysTick timer by enabling the 0 bit */


//Assaf
void MSTK_voidInit(void);
void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
u32  MSTK_u32GetElapsedTime(void);
#endif
