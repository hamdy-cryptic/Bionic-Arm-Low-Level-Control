/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 11 JAN 2021                            */
/* Version   : 01                                     */
/******************************************************/

#include "DataTypes_and_BitMath.h"

#ifndef GPTIMER_CONFIGURATION_H
#define GPTIMER_CONFIGURATION_H

#define GPTIM             	 9       /*The timer you`re working on: 
9/12 (Up to 2 independent channels) _ 10/11/13/14 (1 independent channel)*/

#define GPTIM_CLK_DIVISION   00
/*
This bit-field indicates the division ratio between the timer clock (CK_INT) frequency and
sampling clock used by the digital filters (TIx),
00: tDTS = tCK_INT
01: tDTS = 2 × tCK_INT
10: tDTS = 4 × tCK_INT
11: Reserved
*/

#define GPTIM_ARR           65535   //Auto reload register value is set to maximum

/************************** Input Capture Mode ***************************/

#define GPTIM_FILTER        0000
/*
0000: No filter, sampling is done at fDTS1000: fSAMPLING=fDTS/8, N=6
0001: fSAMPLING=fCK_INT, N=21001: fSAMPLING=fDTS/8, N=8
0010: fSAMPLING=fCK_INT, N=41010: fSAMPLING=fDTS/16, N=5
0011: fSAMPLING=fCK_INT, N=8 1011: fSAMPLING=fDTS/16, N=6
0100: fSAMPLING=fDTS/2, N=61100: fSAMPLING=fDTS/16, N=8
0101: fSAMPLING=fDTS/2, N=81101: fSAMPLING=fDTS/32, N=5
0110: fSAMPLING=fDTS/4, N=61110: fSAMPLING=fDTS/32, N=6
0111: fSAMPLING=fDTS/4, N=81111: fSAMPLING=fDTS/32, N=8
*/

#define GPTIM_INPUTPSC      00
/*
00: no prescaler, capture is done each time an edge is detected on the capture input
01: capture is done once every 2 events
10: capture is done once every 4 events
11: capture is done once every 8 events
*/
#define GPTIM_CH             1        //Which channel the timer is operating on, 1 or 2 for (TIM9,TIM12) 
																			//1: CHANNEL 1        2:CHANNEL 2  
#define GPTIM_CC1S           01       //capture compare 1 channel selection
/*
This bitfield defines the direction of the channel (input/output) as well as the used input.
00: CC1 channel is configured as output
01: CC1 channel is configured as input, IC1 is mapped on TI1
10: CC1 channel is configured as input, IC1 is mapped on TI2
11: CC1 channel is configured as input, IC1 is mapped on TRC. This mode is working only if
an internal trigger input is selected through TS bit (TIMx_SMCR register)
Note: The CC1S bits are writable only when the channel is OFF (CC1E = 0 in TIMx_CCER).
*/
#define GPTIM_CC2S           01       //capture compare 2 channel selection
/*
This bitfield defines the direction of the channel (input/output) as well as the used input.
00: CC2 channel is configured as output
01: CC2 channel is configured as input, IC2 is mapped on TI2
10: CC2 channel is configured as input, IC2 is mapped on TI1
11: CC2 channel is configured as input, IC2 is mapped on TRC. This mode works only if an
internal trigger input is selected through the TS bit (TIMx_SMCR register)
Note: The CC2S bits are writable only when the channel is OFF (CC2E = 0 in TIMx_CCER).
*/

#define PSC_VALUE           999        //The prescaller value (0-65535), this value will be added to 1

#define TIM_CLK      (16*1000*1000)   //Default timer clock is 16 MHz in STM32F4XX series

#define GPTIM_EDGE_SELEC    0          //1: Falling Edge        0: Rising Edge   

/****************** Setting The pins Alternate functions for the Timers ******************/

/*
	TIM9: 	void GPIO_Set_AF(GPIOA,2,3); CHANNEL 1
					void GPIO_Set_AF(GPIOA,3,3); CHANNEL 2
	
	TIM12:	void GPIO_Set_AF(GPIOB,14,9); CHANNEL 1
					void GPIO_Set_AF(GPIOB,15,9); CHANNEL 2
	
	TIM10:	void GPIO_Set_AF(GPIOB,8,3); CHANNEL 1
	
	TIM11:	void GPIO_Set_AF(GPIOB,9,3); CHANNEL 1
	
	TIM13:	void GPIO_Set_AF(GPIOA,6,9); CHANNEL 1
	
	TIM13:	void GPIO_Set_AF(GPIOA,7,9); CHANNEL 1
*/

#endif
