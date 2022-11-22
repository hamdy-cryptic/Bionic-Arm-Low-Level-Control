/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 27 December 2020                                 */
/* Version : V01                                            */
/*************************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "STD_TYPES.h"



void USART_Init(void);
void  USART_SEND_CHAR(u8 character);
void USART_SENDSTRING(u8 *ptr_string);
u8    USART_Receive (void);


   

        /* USART_STATUS */
#define USART_DISABLE                  0
#define USART_ENABLE                   1

       /* USART_OVERSAMPLING */
#define USART_OVERSAMPLING_BY_16       0
#define USART_OVERSAMPLING_BY_8        1

      /* USART_WORD_LENGTH */
#define _8_DATA_BITS                    8
#define _9_DATA_BITS                    9

      /* USART_CONTROL_PARITY */
#define PARITY_CONTROL_DISABLE          0
#define EVEN_PARITY                     1
#define ODD_PARITY                      2

     /* USART_INTERRUPT*/
#define INT_DISABLE                     0
#define IDLE_INT_ENABLE                 1
#define RXNE_INT_ENABLE                 2
#define TCE_INT_ENABLE                  3
#define TXE_INT_ENABLE                  4
#define PE_INT_ENABLE                   5

      /* USART_TRANSMITTER */
#define TRANSMITTER_DISABLE             0
#define TRANSMITTER_ENABLE              1

     /* USART_RECEIVER */
#define RECEIVER_DISBLE                 0
#define RECEIVER_ENABLE                 1

/* USART_HW_FLOW_CONTROL */
#define  USART_NO_CTS_RTS               0
#define  USART_CTS                      1
#define  USART_RTS                      2
#define  USART_CTS_RTS                  3

     /* USART_STOP_BITS */
#define ONE_STOP_BIT                    0
#define HALF_STOP_BIT                   1
#define TWO_STOP_BIT                    2
#define ONE_AND_HALF_STOP_BIT           3


#endif
