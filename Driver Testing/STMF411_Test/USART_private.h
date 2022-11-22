/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 27 December 2020                                 */
/* Version : V01                                            */
/*************************************************************/

#ifndef  USART_PRIVATE_H
#define  USART_PRIVATE_H
#include <STD_TYPES.h>


typedef struct{

	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;

}USART_Registers;

#define USART1 (  ( volatile USART_Registers* ) 0x40011000 )          // APB2 Bus

#define USART2 (  ( volatile USART_Registers* ) 0x40004400 )          // APB1 Bus

#define USART3 (  ( volatile USART_Registers* ) 0x40004800 )         // APB1 Bus

#define USART4 (  ( volatile USART_Registers* ) 0x40004C00 )        // APB1 Bus

#define USART5 (  ( volatile USART_Registers* ) 0x40005000 )       // APB1 Bus

#define USART6 (  ( volatile USART_Registers* ) 0x40011400 )       // APB2 Bus

#endif
