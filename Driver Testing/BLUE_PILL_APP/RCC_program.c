/************************************/
/* Author : Yomna Attia             */
/* Date : 12/12/2020                */
/* version : 01                     */
/************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_interface.h"



void RCC_voidInitSysClock (void)
{
#if     RCC_CLOCK_TYPE  ==  RCC_HSE_CRYSTAL 
        RCC_CR |= 0x00010000; /*Enable HSE with no bypass */
		RCC_CFGR = 0x00000001;
		RCC_CFGR |=   ((PPRE2)<<11);
		RCC_CFGR |=   ((PPRE1)<<8);
		RCC_CFGR |=     ((HPRE)<<4);
	RCC_CR &= ~(1U);     /*Close HSI*/
#elif   RCC_CLOCK_TYPE  ==  RCC_HSE_RC
        RCC_CR |= 0x00040000; /*Enable HSE bypass */
		 RCC_CR |= 0x00010000; /*Enable HSE*/
		RCC_CFGR = 0x00000001;
		RCC_CFGR |=   ((PPRE2)<<11);
		RCC_CFGR |=   ((PPRE1)<<8);
		RCC_CFGR |=     ((HPRE)<<4);
	RCC_CR &= ~(1U);     /*Close HSI*/
#elif   RCC_CLOCK_TYPE  ==  RCC_HSI
        RCC_CR = 0x00000081;  /*Enable HSI + Triming =0 */
		RCC_CFGR = 0x00000000;
		RCC_CFGR |=   ((PPRE2)<<11);
		RCC_CFGR |=   ((PPRE1)<<8);
		RCC_CFGR |=     ((HPRE)<<4);
#elif   RCC_CLOCK_TYPE  ==  RCC_PLL
		RCC_CFGR= 0;
		RCC_CFGR|= ((PLL_MUL)<<18);
		RCC_CFGR|= ((PLL_XTPRE)<<17);
		RCC_CFGR|= ((RCC_ADC_PRE)<<14);

       #if RCC_PLL_INPUT ==  RCC_PLL_HSI
							RCC_CFGR |=   ((PPRE2)<<11);
							RCC_CFGR |=   ((PPRE1)<<8);
							RCC_CFGR |=     ((HPRE)<<4);
							RCC_CFGR&=~ (1<<16);
							FLASH_ACR |= (FLASH_LATENCY<<0);           //Program Flash wait states
	            RCC_CR   =    0x01000081; //Enable HSI , No Bias in trim, and Enable PLL
							while (RCC_CR>>25==0){}         //Wait till PLL is Ready
							RCC_CFGR = 0x00000002;
				
       #elif RCC_PLL_INPUT ==  RCC_PLL_HSE_Crystal
				RCC_CFGR |=   ((PPRE2)<<11);
				RCC_CFGR |=   ((PPRE1)<<8);
				RCC_CFGR |=     ((HPRE)<<4);
				RCC_CFGR|= (1<<16);
				FLASH_ACR |= (FLASH_LATENCY<<0);           //Program Flash wait states
				RCC_CR    =    0x01010000;      //Enable HSE, No Bypass, and Enable PLL
				while (RCC_CR>>25==0){}         //Wait till PLL is Ready
				RCC_CFGR |= 0x00000002;
				RCC_CR &= ~(1U);     /*Close HSI*/
			
	     #elif RCC_PLL_INPUT ==  RCC_PLL_HSE_RC
				RCC_CFGR |=   ((PPRE2)<<11);
				RCC_CFGR |=   ((PPRE1)<<8);
		    RCC_CFGR |=     ((HPRE)<<4);
				RCC_CFGR|= (1<<16);
				FLASH_ACR |= (FLASH_LATENCY<<0);           //Program Flash wait states
				RCC_CR   =    0x01050000;      //Enable HSE , with Bypass, and Enable PLL
				while (RCC_CR>>25==0){}         //Wait till PLL is Ready
				RCC_CFGR = 0x00000002;
				RCC_CR &= ~(1U);     /*Close HSI*/
			
	   #else   
	     #error ("You chosed Wrong RCC_PLL_INPUT ")
	  #endif
#else   
	#error ("You chosed Wrong CLOCK TYPE ")
#endif
}

void RCC_voidEnableClock (u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if ( Copy_u8PerId<= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB1 :      SET_BIT(RCC_AHB1ENR,Copy_u8PerId);  break;
			case RCC_APB1:       SET_BIT(RCC_APB1ENR,Copy_u8PerId);  break;
			case RCC_APB2:       SET_BIT(RCC_APB2ENR,Copy_u8PerId);  break;
			default    :/* Return Error */  break; 
		}
	}
	else 
	{
		/* Return Error */
	}
}
	
void RCC_voidDisableClock (u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if ( Copy_u8PerId<= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB1 :    CLR_BIT(RCC_AHB1ENR,Copy_u8PerId);  break;
			case RCC_APB1:     CLR_BIT(RCC_APB1ENR,Copy_u8PerId);  break;
			case RCC_APB2:     CLR_BIT(RCC_APB2ENR,Copy_u8PerId);  break;
			default    :/* Return Error */  break; 
		}
	}
	else 
	{
		/* Return Error */
	}
}
