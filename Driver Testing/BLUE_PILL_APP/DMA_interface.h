/*********************************************************/
/*Author    : youstina                                   */
/*version   : v03*                                        */
/*date      : 20 FEB 2021                                */
/*********************************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

#include "STD_TYPES.h"

void   MDMA_voidChannelInit(void);
void DMA_SetConfig(u8 Copy_u8Dma , u8 Copy_u8CHANNEL , u8 Copy_u8DataDirection , u8 Copy_u8MemDataSize , u8 Copy_u8PerDataSize , u8 Copy_u8MemInc , u8 Copy_u8PerInc);
void MDMA_VoidDMADisable( u8 Copy_u8Dma , u8 Copy_u8CHANNEL );
void DMA_VoidInerruptEnable(u8 Copy_u8Dma , u8 Copy_u8CHANNEL , u8 Copy_u8INTSource );
void DMA_VoidSetAddress(u8 Copy_u8Dma ,u8 Copy_u8CHANNEL , u32 * Copy_pu32PeripheralAddress , u32 * Copy_pu32MemoryAddress , u16 Copy_u16BlockLength );
void DMA_VoidClearFlag(u8 Copy_u8Dma ,u8 Copy_u8CHANNEL , u8 Copy_u8Flag );
void DMA_VoidDMAEnable(u8 Copy_u8Dma , u8 Copy_u8CHANNEL );
u8 DMA_u8GetFlag(u8 Copy_u8Dma ,u8 Copy_u8CHANNEL , u8 Copy_u8Flag );
void DMA_VoidConfigPriority(u8 Copy_u8Dma ,u8 Copy_u8CHANNEL, u8 Copy_u8PeriorityLevel);
void DMA_VoidSetCircularMode(u8 Copy_u8Dma ,u8 Copy_u8CHANNEL);
void MDMA_VidSetCallBack_I2C2_RX( void ( *Ptr ) ( void ) );
void DMA1_I2C2_RX_IRQHandler(void);
void MDMA_VidSetCallBack_I2C2_TX( void ( *Ptr ) ( void ) );
void DMA1_I2C2_TX_IRQHandler(void);


//DMA Flags
#define GIF   0
#define TCIF  1
#define HTIF  2
#define TEIF  3

//DMA CHANNELS
#define CHANNEL1  0
#define CHANNEL2  1
#define CHANNEL3  2
#define CHANNEL4  3
#define CHANNEL5  4
#define CHANNEL6  5
#define CHANNEL7  6

/* INTSource */
#define TCIE  1
#define HTIE  2
#define TEIE  3

//DMA Configuration MEMORY_TO_MEMORY
//Direction
#define        MEMORY_TO_MEMORY           0
#define      PERIPHERAL_TO_MEMORY         1 
#define      MEMORY_TO_PERIPHERAL         2 

//Circular MODE
#define   DISABLED           0
#define   ENABLED            1

/* OPTIONS OF PerInc &MemInc */
/* OPTIONS FOR MEMORY & PERIPHERAL INCREAMENT MODE */
#define       DEACTIVATED                  0       /* address pointer is fixed */
#define       ACTIVATED                    1        /* address pointer is incremented after each data transfer */


/* OPTIONS OF WORD & PERIPHERAL DATA SIZE */
#define BYTE       0
#define HALF_WORD  1
#define WORD       2

/* CONFIGURE THE STREAM PRIORITY */
/* OPTIONS OF PriorityLevel */
#define    LOW              0
#define    MEDIUM           1
#define    HIGH             2
#define    VERY_HIGH        3

#endif
