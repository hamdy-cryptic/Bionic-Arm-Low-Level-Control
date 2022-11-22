/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 27 December 2020                                 */
/* Version : V01                                            */
/*************************************************************/


#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "STD_TYPES.h"

typedef struct
{
  u8 TX[2000];
  u8 RX[2000];
 
} DATA;


void USART_Init(void);


void USART1_SEND_CHAR(u8 character);
void USART2_SEND_CHAR(u8 character);
void USART3_SEND_CHAR(u8 character);


void USART1_SENDSTRING(u8 *ptr_string);
void USART2_SENDSTRING(u8 *ptr_string);
void USART3_SENDSTRING(u8 *ptr_string);


u8 USART1_Receive (void);
u8 USART2_Receive (void);
u8 USART3_Receive (void);


void USART1_DMA_Receiver_Init(void);
void USART2_DMA_Receiver_Init(void);
void USART3_DMA_Receiver_Init(void);



void USART1_DMA_Transmit_Init(void);
void USART2_DMA_Transmit_Init(void);
void USART3_DMA_Transmit_Init(void);


u8 USART1_DMA_RECEIVE(void);
void USART2_DMA_RECEIVE(u32* recieved[]);
u8 USART3_DMA_RECEIVE(void);

void USART1_DMA_Transmit(u8 *Tx_data[]);
void USART2_DMA_Transmit(u8 *Tx_data[]);
void USART3_DMA_Transmit(u8 *Tx_data[]);

  

        /* USART_STATUS */
#define USART_DISABLE                  0
#define USART_ENABLE                   1

     

      /* USART_WORD_LENGTH */
#define _8_DATA_BITS                     8
#define _9_DATA_BITS                     9

      /* USART_CONTROL_PARITY */
#define PARITY_CONTROL_DISABLE           0
#define EVEN_PARITY                      1
#define ODD_PARITY                       2

     /* USART_INTERRUPT*/
#define INT_DISABLE                      0
#define IDLE_INT_ENABLE                  1
#define RXNE_INT_ENABLE                  2
#define TCE_INT_ENABLE                   3
#define TXE_INT_ENABLE                   4
#define PE_INT_ENABLE                    5

      /* USART_TRANSMITTER */
#define TRANSMITTER_DISABLE              0
#define TRANSMITTER_ENABLE               1

     /* USART_RECEIVER */
#define RECEIVER_DISABLE                 0
#define RECEIVER_ENABLE                  1
 
    /* USART_DMA_TX */
#define   DMAT_DISABLE                   0
#define   DMAT_ENABLE                    1

/* USART_DMA_RX */
#define   DMAR_DISABLE                   0
#define   DMAR_ENABLE                    1


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