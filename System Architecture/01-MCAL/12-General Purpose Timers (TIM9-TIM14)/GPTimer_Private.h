/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 11 JAN 2021                            */
/* Version   : 01                                     */
/******************************************************/

#include "DataTypes_and_BitMath.h"

#ifndef GPTIMER_PRIVATE_H
#define GPTIMER_PRIVATE_H

				/********** Registers *************/

#define GPTIM9_BASE_ADDRESS    0x40014000
#define GPTIM10_BASE_ADDRESS   0x40014400
#define GPTIM11_BASE_ADDRESS   0x40014800
#define GPTIM12_BASE_ADDRESS   0x40001800
#define GPTIM13_BASE_ADDRESS   0x40001C00
#define GPTIM14_BASE_ADDRESS   0x40002000

typedef struct 
{
	  volatile uint32 CR1;			/* TIM control register 1,              Address offset: 0x00 */
		volatile uint32 CR2;      /* TIM control register 2,              Address offset: 0x04 */
		volatile uint32 SMCR;     /* TIM slave mode control register,     Address offset: 0x08 */
		volatile uint32 DIER;     /* TIM DMA/interrupt enable register,   Address offset: 0x0C */
		volatile uint32 SR;       /* TIM status register,                 Address offset: 0x10 */
		volatile uint32 EGR;      /* TIM event generation register,       Address offset: 0x14 */
		volatile uint32 CCMR1;    /* TIM capture/compare mode register 1, Address offset: 0x18 */
		volatile uint32 CCMR2;    /* TIM capture/compare mode register 2, Address offset: 0x1C */
		volatile uint32 CCER;     /* TIM capture/compare enable register, Address offset: 0x20 */
		volatile uint32 CNT;      /* TIM counter register,                Address offset: 0x24 */
		volatile uint32 PSC;      /* TIM prescaler,                       Address offset: 0x28 */
		volatile uint32 ARR;      /* TIM auto-reload register,            Address offset: 0x2C */
		volatile uint32 RCR;      /* TIM repetition counter register,     Address offset: 0x30 */
		volatile uint32 CCR1;     /* TIM capture/compare register 1,      Address offset: 0x34 */
		volatile uint32 CCR2;     /* TIM capture/compare register 2,      Address offset: 0x38 */
		volatile uint32 CCR3;     /* TIM capture/compare register 3,      Address offset: 0x3C */
		volatile uint32 CCR4;     /* TIM capture/compare register 4,      Address offset: 0x40 */
		volatile uint32 BDTR;     /* TIM break and dead-time register,    Address offset: 0x44 */
		volatile uint32 DCR;      /* TIM DMA control register,            Address offset: 0x48 */
		volatile uint32 DMAR;     /* TIM DMA address for full transfer,   Address offset: 0x4C */
	  volatile uint32 OR;       /* TIM option register,                 Address offset: 0x50 */
		
}	GP_Timer;

#define GP_TIM9    ((volatile GP_Timer*)GPTIM9_BASE_ADDRESS)
#define GP_TIM10   ((volatile GP_Timer*)GPTIM10_BASE_ADDRESS)
#define GP_TIM11	 ((volatile GP_Timer*)GPTIM11_BASE_ADDRESS)			
#define GP_TIM12   ((volatile GP_Timer*)GPTIM12_BASE_ADDRESS)
#define GP_TIM13   ((volatile GP_Timer*)GPTIM13_BASE_ADDRESS)
#define GP_TIM14   ((volatile GP_Timer*)GPTIM14_BASE_ADDRESS)

			/********* Private Functions ***********/

#endif
