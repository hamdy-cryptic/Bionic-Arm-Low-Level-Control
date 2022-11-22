/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 15 DEC 2020                            */
/* Version   : 1                                      */
/******************************************************/

#ifndef STK_CONFIGURATION_H
#define STK_CONFIGURATION_H

#define SYS_CLK        		  72  	/* Setting the sysem clock frequency (0 - 180) MHz */
#define SYS_CLK_SEL         0       /* 1: processor clock (AHB), 0: AHB/8 */
#define DEFAULT_T_UNITS		  1       /* Overflow time units, 0: Microseconds - 1: Milliseconds (Default) */
#define SYS_OVERFLOW   		  1 	    /* Setting the time between two Interrupts */
#define SysTick_Priority    3       /* Seting the SysTick Priority(>0)*/

//Note: the higher the p the least urgency in execution


//Assaf
/* Options: MSTK_SRC_AHB / MSTK_SRC_AHB_8 */
#define MSTK_CLK_SRC     MSTK_SRC_AHB_8

#endif
