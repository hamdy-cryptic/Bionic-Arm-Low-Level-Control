/*********************************************************/
/*Author    : youstina                                   */
/*version   : v03*                                        */
/*date      : 20 FEB 2021                                */
/*********************************************************/

#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

#include "STD_TYPES.h"
typedef struct{

	volatile u32 CCR       ;//0x000
	volatile u32 CNDTR     ;//0x004
	volatile u32 CPAR      ;//0x008
	volatile u32 CMAR      ;//0x00C
	volatile u32 RESERVED  ;//0x010

}DMACHANNEL;

typedef struct{

	volatile u32 ISR  ;//0x000
	volatile u32 IFCR ;//0x004
	DMACHANNEL CHANNEL[7];//0x008

}DMA_t;

#define DMA1  ( ( volatile DMA_t * ) 0x40020000 )
#define DMA2  ( ( volatile DMA_t * ) 0x40020400 )
#endif