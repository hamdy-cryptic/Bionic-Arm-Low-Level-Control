/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 11 JAN 2021                            */
/* Version   : 01                                     */
/******************************************************/

#include "DataTypes_and_BitMath.h"

#ifndef BTIMER_PRIVATE_H
#define BTIMER_PRIVATE_H

/********** Registers *************/

#define BTimer_TIM6_Base  0x40001000                                     //TIM6 base address
#define BTimer_TIM6_CR1   *((volatile uint32*)BTimer_TIM6_Base+0x00)     //TIM6 control register 1
#define BTimer_TIM6_CR2   *((volatile uint32*)BTimer_TIM6_Base+0x04)	   //TIM6 control register 2
#define BTimer_TIM6_DIER  *((volatile uint32*)BTimer_TIM6_Base+0x0C)     //TIM6 DMA/Interrupt enable register
#define BTimer_TIM6_SR    *((volatile uint32*)BTimer_TIM6_Base+0x10)     //TIM6 status register
#define BTimer_TIM6_EGR   *((volatile uint32*)BTimer_TIM6_Base+0x14)     //TIM6 event generation register	
#define BTimer_TIM6_CNT   *((volatile uint32*)BTimer_TIM6_Base+0x24)     //TIM6 counter register
#define BTimer_TIM6_PSC   *((volatile uint32*)BTimer_TIM6_Base+0x28)     //TIM6 prescaler register
#define BTimer_TIM6_ARR   *((volatile uint32*)BTimer_TIM6_Base+0x2C)     //TIM6 auto reload register	

#define BTimer_TIM7_Base  0x40001400                                     //TIM7 base address
#define BTimer_TIM7_CR1   *((volatile uint32*)BTimer_TIM6_Base+0x00)     //TIM7 control register 1
#define BTimer_TIM7_CR2   *((volatile uint32*)BTimer_TIM6_Base+0x04)	   //TIM7 control register 2
#define BTimer_TIM7_DIER  *((volatile uint32*)BTimer_TIM6_Base+0x0C)     //TIM7 DMA/Interrupt enable register
#define BTimer_TIM7_SR    *((volatile uint32*)BTimer_TIM6_Base+0x10)     //TIM7 status register
#define BTimer_TIM7_EGR   *((volatile uint32*)BTimer_TIM6_Base+0x14)     //TIM7 event generation register	
#define BTimer_TIM7_CNT   *((volatile uint32*)BTimer_TIM6_Base+0x24)     //TIM7 counter register
#define BTimer_TIM7_PSC   *((volatile uint32*)BTimer_TIM6_Base+0x28)     //TIM7 prescaler register
#define BTimer_TIM7_ARR   *((volatile uint32*)BTimer_TIM6_Base+0x2C)     //TIM7 auto reload register	
	
#define RCC_AHB1ENR        *((volatile u32*)0x40023830);
	
/********* Private Functions ***********/

void TIM6_DAC_IRQHandler(void);                         //Handler for TIM6 interrupts
void TIM7_IRQHandler(void);                             //Handler for TIM7 interrupts
uint32 Ticks2Millisec (uint32 ticks);					          // t_ms=(ticks/TIMclk_frequency(MHz))*1000
uint32 Millisec2Ticks (uint32 t_ms);					          // ticks=(t_ms*TIMclk_frequency(MHz))/1000

#endif
