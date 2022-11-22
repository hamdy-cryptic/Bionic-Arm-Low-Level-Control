/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 27 December 2020                                 */
/* Version : V01                                            */
/*************************************************************/

#ifndef USART_CONFIG_H
#define USART_CONFIG_H


/*  OPTIONS : 
   USARTx : USART1 , USART2 , USART3 , UART4, UART5, USART6
   Baud Rate : 1200, 2400, 9600, 19200, 38400, 57600, 115200, 230400, 460800, 921600, 2M, 3M
   NO Of Stop Bits: 1 , 0.5 , 2 , 1.5
   Word Length: 8 bits, 9 bits
   Parity control: Disable, Enable Even, Enable ODD
   HW Flow control: CTRL_none , CTRL_CTS  ,   CTRL_RTS  , CTRL_CTS_RTS  */


/* If you want a certain USART, Remove (//) of the comment to active it */
   
  // #define  usart1
   #define  usart2
	// #define  usart3
	 //#define  usart4
	 //#define  usart5
	 //#define  usart6
	 
	 
	 
	 
   /* clock of APB2 for USART1,6 */
  #define   fck2     8000000UL
  /* clock of APB1 for USART2,3,4,5 */
  #define   fck1      8000000UL   
  
  #define   USART_BAUD_RATE            (u32) 9600
  
  #define   USART_OVERSAMPLING      USART_OVERSAMPLING_BY_16
  
  #define   USART_STATUS             USART_ENABLE
  
  #define   USART_WORD_LENGTH        8
  #define   USART_CONTROL_PARITY     PARITY_CONTROL_DISABLE
   
  #define   USART_INTERRUPT         INT_DISABLE
  
  #define   USART_TRANSMITTER       TRANSMITTER_ENABLE
  
  #define   USART_RECEIVER         RECEIVER_ENABLE
  #define   USART_HW_FLOW_CONTROL    USART_NO_CTS_RTS                                         // Not available for UART4, UART5
  #define   USART_STOP_BITS        ONE_STOP_BIT 






#endif
