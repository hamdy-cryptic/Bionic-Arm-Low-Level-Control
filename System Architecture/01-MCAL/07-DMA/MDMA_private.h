/*********************************************************/
/*Author    : youstina                                   */
/*version   : v02                                        */
/*date      : 25 JAN 2021                                */
/*********************************************************/
#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

#include"STD_TYPES.h"
typedef struct
{
	volatile u32 SCR;
	volatile u32 SNDTR;
	volatile u32 SPAR;
	volatile u32 SM0AR;
	volatile u32 SM1AR;
	volatile u32 SFCR;
}DMA_Stream;

typedef struct
{
	volatile u32 LISR;
	volatile u32 HISR;
	volatile u32 LIFCR;
	volatile u32 HIFCR;
	DMA_Stream Stream[8];
}DMA_t;

#define     DMA1    ((volatile DMA_t*)0x40026000)
#define     DMA2    ((volatile DMA_t*)0x40026400)

/* ENABLE BIN OF DMA stream x configuration register */
#define      EN    0 


/* OPTIONS FOR CIRCULAR MODE : ENABLED , DISABLED */
/* OPTIONS FOR INTERRUPTS */
#define       DISABLED       0
#define       ENABLED        1


/* OPTIONS FOR DIRECT_MODE */
#define      DIRECT_MODE_ENABLED      0
#define      DIRECT_MODE_DISABLED     1

/* MASKS FOR CLEAR INT FLAGS */
#define     Stream0_Mask     (0x3D<<0)
#define     Stream1_Mask     (0x3D<<6)
#define     Stream2_Mask     (0x3D<<16)
#define     Stream3_Mask     (0x3D<<22)
#define     Stream4_Mask     (0x3D<<0)     
#define     Stream5_Mask     (0x3D<<6)
#define     Stream6_Mask     (0x3D<<16)
#define     Stream7_Mask     (0x3D<<22)

/* IN CASE OF PERIRHERAL FLOW CONTROLLER */
#define     PFCTRL       5

/* in case of BURST TRANSFER */
#define     PBURST     21    
#define     MBURST     23   

/* CIRCULAR MODE */
#define      CIRC       8

/* FIFO ERROR INTERRUPT */
#define      FIFO_INT            7
#define      DIR_MODE_DISABLE    2    

/* in case of double buffer mode */
#define       DBM        18            // double buffer mode enable bit 
#define       CT         19            // current target memory , configure which memory begins transfer

#endif
