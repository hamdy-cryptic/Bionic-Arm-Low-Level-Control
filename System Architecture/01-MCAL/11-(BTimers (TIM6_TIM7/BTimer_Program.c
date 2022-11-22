/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 11 JAN 2021                            */
/* Version   : 01                                     */
/******************************************************/

#include "DataTypes_and_BitMath.h"
#include "BTimer_Interface.h"
#include "BTimer_Configuration.h"
#include "BTimer_Private.h"

#include "RCC_interface.h"

static void(* ptr_interr)(void);              /* Global pointer that stores the enterrupt function address*/


				/************** Timer 6_Handler Function ****************/

void TIM6_DAC_IRQHandler(void)
{
	ptr_interr ();
}

			/************** Timer 7_Handler Function ****************/

void TIM7_IRQHandler(void)
{
	ptr_interr ();
}


				/************** The Single Timer Function ****************/


void MBTimer_void_STimer (uint32 TIM_NUM, uint32 time_ms, void (*interr_funct_name)(void))
{
	uint32 ticks = ((time_ms/1000)*TIM_CLK)/(PSC_VALUE+1);
	ptr_interr = interr_funct_name;             /* The function adress is saved in the global pointer ptr_interr that will be called in the handler */
	
	if (TIM_NUM==6)
	{
		BTimer_TIM6_CR1 =0;                        //Reset control register 1
		RCC_voidEnableClock (RCC_APB1,4);          //Enable clock to the timer
		BTimer_TIM6_ARR = ticks - 1;               //Setting the auto reload register
		BTimer_TIM6_PSC = PSC_VALUE;               //Setting the prescaller value
		BTimer_TIM6_DIER |= 0x01;                  //Update interrupt enabled
		SET_BIT(BTimer_TIM6_CR1,4);                //One-pulse mode is enabled
		BTimer_TIM6_CR1 |= 0x01;                   //Enable counting
	}
else
	{
		BTimer_TIM7_CR1 =0;                        //Reset control register 1
		RCC_voidEnableClock (RCC_APB1,5);          //Enable clock to the timer
		BTimer_TIM7_ARR = ticks - 1;               //Setting the auto reload register
		BTimer_TIM7_PSC = PSC_VALUE;               //Setting the prescaller value
		BTimer_TIM7_DIER |= 0x01;                  //Update interrupt enabled
		SET_BIT(BTimer_TIM7_CR1,4);                //One-pulse mode is enabled
		BTimer_TIM7_CR1 |= 0x01;                   //Enable counting
  }	
}

				/************** The Periodic Timer Function ****************/


void MBTimer_void_PTimer (uint32 TIM_NUM, uint32 time_ms, void (*interr_funct_name)(void))
{
	uint32 ticks = ((time_ms/1000)*TIM_CLK)/(PSC_VALUE+1);
	ptr_interr = interr_funct_name;             /* The function adress is saved in the global pointer ptr_interr that will be called in the handler */
	
	if (TIM_NUM==6)
	{
		BTimer_TIM6_CR1 =0;                        //Reset control register 1
		RCC_voidEnableClock (RCC_APB1,4);          //Enable clock to the timer
		BTimer_TIM6_ARR = ticks - 1;               //Setting the auto reload register
		BTimer_TIM6_PSC = PSC_VALUE;               //Setting the prescaller value
		BTimer_TIM6_DIER |= 0x01;                  //Update interrupt enabled
		BTimer_TIM6_CR1 |= 0x01;                   //Enable counting
	}
else
	{
		BTimer_TIM7_CR1 =0;                        //Reset control register 1
		RCC_voidEnableClock (RCC_APB1,5);          //Enable clock to the timer
		BTimer_TIM7_ARR = ticks - 1;               //Setting the auto reload register
		BTimer_TIM7_PSC = PSC_VALUE;               //Setting the prescaller value
		BTimer_TIM7_DIER |= 0x01;                  //Update interrupt enabled
		BTimer_TIM7_CR1 |= 0x01;                   //Enable counting
  }	
}
