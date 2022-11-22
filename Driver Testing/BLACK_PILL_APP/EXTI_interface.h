/*********************************************************/
/*Author     : youstina                                  */
/*version    : v01                                       */
/*date       : 9 DEC 2020                                */
/*********************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
#include <STD_TYPES.h>


/* Line & mode */
void MEXTI_voidInit (void);                   										//Initialize Configuration File
void MEXTI_voidEnableEXTI (u8 Copy_u8Line);   										//Enable Line other than Config
void MEXTI_voidDisableEXTI (u8 Copy_u8Line);  										//Disable Line 
void MEXTI_voidSwTrigger (u8 Copy_u8Line);    										//Used to try interrupt with software trigger instead of external interrupt
void MEXTI_voidSetSignalLatch (u8 Copy_u8Line , u8 Copy_u8Mode);	/*Set Mode to cause interrupt*/
void MEXTI_voidSetCallBack (void (*ptr)(void));                 	//Set Interrupt Function to make when external interrupt occur

//The driver has 16 lines of external interrupt that can be used from GPIO Pins
/*Modes of Signal Latch*/
#define  RISING     1
#define  FALLING    2
#define  ON_CHANGE  3
#endif