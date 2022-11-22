/************************************/
/* Author : Yomna Attia             */
/* Date : 12/12/2020                */
/* version : 01                     */
/************************************/
/*Gards           */

#ifndef RCC_config_h
#define RCC_config_h

/*This File is used to configure the Blue Pill for the following Speeds:
				Processor Speed : 72MHz
				AHB  Speed      : 72MHz
				APB2 Speed      : 72MHz
				APB1 Speed      : 36MHz

*/
/*clock type _________________ */
/* options : RCC_HSE_CRYSTAL 
             RCC_HSE_RC
			 RCC_HSI
			 RCC_PLL       */
			 
#define RCC_CLOCK_TYPE   RCC_PLL
/* prescalers /*

PPRE2: APB high-speed prescaler (APB2)
Set and cleared by software to control APB high-speed clock division factor.
Caution: The software has to set these bits correctly not to exceed 90 MHz on this domain. 
The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after 
PPRE2 write.
0xx: AHB clock not divided
4: AHB clock divided by 2
5: AHB clock divided by 4
6: AHB clock divided by 8
7: AHB clock divided by 16      */

#define PPRE2 0

/*
PPRE1: APB Low speed prescaler (APB1)
Set and cleared by software to control APB low-speed clock division factor.
Caution: The software has to set these bits correctly not to exceed 45 MHz on this domain. 
The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after 
PPRE1 write.
0xx: AHB clock not divided
4: AHB clock divided by 2
5: AHB clock divided by 4
6: AHB clock divided by 8
7: AHB clock divided by 16
Bits 9:8 Reserved, must be kept at reset value.    */ 

#define PPRE1 4

/* HPRE: AHB prescaler
Set and cleared by software to control AHB clock division factor.
Caution: The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after 
HPRE write.
Caution: The AHB clock frequency must be at least 25 MHz when the Ethernet is used.
0xxx: system clock not divided
8: system clock divided by 2
9: system clock divided by 4
10: system clock divided by 8
11: system clock divided by 16
12: system clock divided by 64
13: system clock divided by 128
14: system clock divided by 256
15: system clock divided by 512
   */
 #define HPRE 0

/*PLL-------------------------- */
/*
These bits are written by software to define the PLL multiplication factor. These bits can be
written only when PLL is disabled.
Caution: The PLL output frequency must not exceed 72 MHz.
0000: PLL input clock x 2
0001: PLL input clock x 3
0010: PLL input clock x 4
0011: PLL input clock x 5
0100: PLL input clock x 6
0101: PLL input clock x 7
0110: PLL input clock x 8
0111: PLL input clock x 9
1000: PLL input clock x 10
1001: PLL input clock x 11
1010: PLL input clock x 12
1011: PLL input clock x 13
1100: PLL input clock x 14
1101: PLL input clock x 15
1110: PLL input clock x 16
1111: PLL input clock x 16
*/
#define PLL_MUL      7


/*
PLLR[2:0]: Main PLL division factor for I2Ss, SAIs, SYSTEM and SPDIF-Rx clocks
0 -> HSE Not Divided (Default)
1 -> HSE Divided by 2
*/
#define PLL_XTPRE      0 

/*
Set and cleared by software to select the frequency of the clock to the ADCs.
00: PCLK2 divided by 2   (Default)
01: PCLK2 divided by 4
10: PCLK2 divided by 6
11: PCLK2 divided by 8
*/
#define RCC_ADC_PRE   0


/*   select only if you have PLL as input clock source  
options : RCC_PLL_HSI
             RCC_PLL_HSE_Crystal
			 RCC_PLL_HSE_RC
			        */
#if RCC_CLOCK_TYPE == RCC_PLL					
#define RCC_PLL_INPUT RCC_PLL_HSE_Crystal
#define FLASH_LATENCY      2
#endif 

/*----------------------------------------------------------------------------------------------------------------*/





#endif
