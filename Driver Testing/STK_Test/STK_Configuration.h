/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 15 DEC 2020                            */
/* Version   : 1                                      */
/******************************************************/

#ifndef STK_CONFIG_H
#define STK_CONFIG_H

#define SYS_CLK        		180   	/* Setting the sysem clock frequency (0 - 180) MHz */
#define SYS_CLK_SEL         1       /* 1: processor clock (AHB), 0: AHB/8 */
#define DEFAULT_T_UNITS		0       /* Overflow time units, 1: Microseconds - 0: Milliseconds (Default) */
#define SYS_OVERFLOW   		1 	    /* Setting the time between two Interrupts */
#define SysTick_Priority    3       /* Seting the SysTick Priority(>0)*/

//Note: the higher the p the least urgency in execution

#endif
