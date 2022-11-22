/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 11 JAN 2021                            */
/* Version   : 01                                     */
/******************************************************/

#include "DataTypes_and_BitMath.h"

#ifndef BTIMER_CONFIGURATION_H
#define BTIMER_CONFIGURATION_H

#define TIM_CLK      (16*1000*1000)   //Default timer clock is 16 MHz in STM32F4XX series     
#define PSC_VALUE     999             //The prescaller value (0-65535), this value will be added to 1   
#define BTIM6          6              //For specifing the chosen timer in the functions arguments          
#define BTIM7          7              //For specifing the chosen timer in the functions arguments   

/* The time period Formula
  
	Tperiod_or_Update Event(ms) = ((PSE_VALUE+1)*(Ticks+1))*1000/(TIM_CLK(HZ))
	
	Tperiod :the value you give to the timer to count in milliseconds
	PSC_VALUE: the value at which the TIM_CLK from the RCC will be divided by, and it is a 2^16 bit register
	TICKS: the value which will be restored in the (Auto Reload Register) and the timer will cout up to reach it then restart again
	
	Note: the maximum time you can put depends on the prescallar value, if PSC is 65534 then the max time is 268.4 sec, and if 
	      the PSC is equal to 0 then the maximum time is 4.1 ms. 
*/
#endif
