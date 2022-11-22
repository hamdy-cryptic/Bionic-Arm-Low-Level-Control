/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 12 February 2020                                 */
/* Version : V01                                             */
/*************************************************************/
#ifndef CRC_PRIVATE_H
#define CRC_PRIVATE_H


                        
 
#define  CRC_ADDRESSE        0x40023000                 // AHB1 bus 


                     /* Registers Addresses */
			
#define   CRC_DR                                *((volatile u32 *)(CRC_ADDRESSE + 0x00))
#define   CRC_IDR                               *((volatile u32 *)(CRC_ADDRESSE + 0x04))
#define   CRC_CR                                *((volatile u32 *)(CRC_ADDRESSE + 0x08))

                     



















#endif
