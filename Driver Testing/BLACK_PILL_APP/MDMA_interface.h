/*********************************************************/
/*Author    : youstina                                   */
/*version   : v03*                                        */
/*date      : 20 FEB 2021                                */
/*********************************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

#include "STD_TYPES.h"


void MDMA_voidChannelInit(void);
void DMA_StartTransfer(u32* Copy_pu32PeripheralAddress, u32* Copy_pu32MemoryAddress, u16 Copy_u16BlockLength);
/*in case of memory to memory source address is in peripheral address register  */

/* ***********SET THE CONFIGURATION IN RUN TIME **********/

/* OPTIONS FOR Copy_u8Stream IS FROM STREAM_0 TO STREAM_7 */
#define          STREAM_0                 0
#define          STREAM_1                 1
#define          STREAM_2                 2
#define          STREAM_3                 3
#define          STREAM_4                 4
#define          STREAM_5                 5
#define          STREAM_6                 6
#define          STREAM_7                 7



/* OPTIONS FOR DATA TRANSFER DIRECTION */
#define      PERIPHERAL_TO_MEMORY         0 
#define      MEMORY_TO_PERIPHERAL         1 
#define      MEMORY_TO_MEMORY             2

/* OPTIONS OF WORD & PERIPHERAL DATA SIZE */
/* NOTE : IN DIRECT MODE MUST BE THE SAME SIZE */
#define   BYTE                  0
#define   HALF_WORD             1
#define   WORD                  2

/* OPTIONS OF PerInc &MemInc */
/* OPTIONS FOR MEMORY & PERIPHERAL INCREAMENT MODE */
#define       DEACTIVATED                  0       /* address pointer is fixed */
#define       ACTIVATED                    1        /* address pointer is incremented after each data transfer */


void DMA_SetConfig(u8 Copy_u8Dma , u8 Copy_u8Stream , u8 Copy_u8DataDirection , u8 Copy_u8MemDataSize , u8 Copy_u8PerDataSize , u8 Copy_u8MemInc , u8 Copy_u8PerInc);
void DMA_VoidSetAddress(u8 Copy_u8Dma , u8 Copy_u8Stream , u32 * Copy_pu32PeripheralAddress , u32 * Copy_pu32MemoryAddress , u16 Copy_u16BlockLength );/*in case of memory to memory source address is in peripheral address register  */


/* CONFIGURATIONS NOT NEED TO BE SET IN ALL CASES : OPTIONAL */

/* SELECT THE CHANNEL : not used in case of memory to memory */
/* OPTIONS FOR CHANNEL_ID  */ 
#define     CHANNEL0           0
#define     CHANNEL1           1
#define     CHANNEL2           2
#define     CHANNEL3           3
#define     CHANNEL4           4
#define     CHANNEL5           5
#define     CHANNEL6           6
#define     CHANNEL7           7
void DMA_VoidSelectChannel(u8 Copy_u8Dma ,u8 Copy_u8Stream , u8 Copy_u8Channel );

/* INTSource */
#define  TCIE       4
#define  HTIE       3
#define  TEIE       2
#define  DMEIE      1
void DMA_VoidInerruptEnable(u8 Copy_u8Dma , u8 Copy_u8Stream , u8 Copy_u8INTSource );

void DMA_VoidClearFlag(u8 Copy_u8Dma , u8 Copy_u8Stream , u8 Copy_u8Flag );


/* FLAGS */
#define    FEIF         0 
#define    DMEIF        2
#define    TEIF         3
#define    HTIF         4
#define    TCIF         5
u8 DMA_u8GetFlag(u8 Copy_u8Dma , u8 Copy_u8Stream , u8 Copy_u8Flag );
void DMA_VoidDMAEnable(u8 Copy_u8Dma , u8 Copy_u8Stream );
void MDMA_VoidDMADisable( u8 Copy_u8Dma , u8 Copy_u8Stream );
void MDMA_VidSetCallBackStream0Channel1( void ( *Ptr ) ( void ) );

/* SET PEREPHERAL AS THE FLOW CONTROLLER */
/* in case of use: the value written into the DMA_SxNDTR has no effect on the DMA transfer */
void DMA_VoidPeripheralFlowController(u8 Copy_u8Dma ,u8 Copy_u8Stream); // in case we want the peripheral to set the number of data to be transfered

/* CONFIGURE THE STREAM PRIORITY */
/* OPTIONS OF PriorityLevel */
#define    LOW              0
#define    MEDIUM           1
#define    HIGH             2
#define    VERY_HIGH        3
void DMA_VoidConfigPriority(u8 Copy_u8Dma ,u8 Copy_u8Stream, u8 Copy_u8PeriorityLevel);

/* NOT USED IN DIRECT MODE */
void DMA_VoidEnableFifoInt(u8 Copy_u8Dma ,u8 Copy_u8Stream);/* ENABLE FIFO ERROR INTTERUPT */
//void DMA_U8GetFifoStatus(u8 Copy_u8Stream);/* READ FIFO STATUS */

/* CONFIGURE MEMORY & PEREPHERAL BURST TRANSFER */
/* NOT USED IN DIRECT MODE */
/* FOR Copy_u8PerBurst & Copy_u8MemBurst */
#define    SINGLE_TRANSFER                 0
#define    FOUR_BEATS                      1
#define    EIGHT_BEATS                     2
#define    SIXTEEN_BEATS                   3
void DMA_VoidConfigBurstTransfer(u8 Copy_u8Dma ,u8 Copy_u8Stream , u8 Copy_u8PerBurst, u8 Copy_u8MemBurst); 

/* ***OPTIONAL****CIRCULAR MODE : NOT USED IN CASE OF MEMORY_TO_MEMORY OR IN CASE OF PEREPHERAL FLOW CONTROLLER */
void DMA_VoidSetCircularMode(u8 Copy_u8Dma ,u8 Copy_u8Stream);

/* options for fifo threshold */
#define    QUARTER_THRESHOLD             0
#define    HALF_THRESHOLD                1 
#define    THREE_QUARTERS_THRESHOLD      2 
#define    FULL_THRESHOLD                3
void DMA_VoidSelectFifoThreshold(u8 Copy_u8Dma ,u8 Copy_u8Stream , u8 Copy_u8Threshold); /* SELECT FIFO THRESHOLD */

/* IN CASE OF DOUBLE BUFFER MODE */
/* OPTIONS FOR Copy_u8CurrentTarget TO SPECIFY WHICH MEMORY BEGIN TRANSFER */
#define     MEMORY_0              0
#define     MEMORY_1              1
void DMA_VoidSetDoubleBufferMODE(u8 Copy_u8Dma ,u8 Copy_u8Stream,u8 Copy_u8CurrentTarget , u32 * Copy_pu32PeripheralAddress , u32 * Copy_pu32Memory0Address ,u32 * Copy_pu32Memory1Address , u16 Copy_u16BlockLength);
void MDMA_VidSetCallBack_I2C3_RX( void ( *Ptr ) ( void ) );
void DMA1_I2C3_RX_IRQHandler(void);
void MDMA_VidSetCallBack_I2C3_TX( void ( *Ptr ) ( void ) );
void DMA1_I2C3_TX_IRQHandler(void);

void MDMA_VidSetCallBack_I2C2_RX( void ( *Ptr ) ( void ) );
void DMA1_I2C2_RX_IRQHandler(void);
void MDMA_VidSetCallBack_I2C2_TX( void ( *Ptr ) ( void ) );
void DMA1_I2C2_TX_IRQHandler(void);

#endif
