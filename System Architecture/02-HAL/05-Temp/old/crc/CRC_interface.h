/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 12 February 2020                                 */
/* Version : V01                                             */
/*************************************************************/

#ifndef CRC_INTERFACE_H
#define CRC_INTERFACE_H

#include "STD_TYPES.h"

#define    CRC_POLYNOMIAL                  0x4C11DB7
#define    CRC_DR_RESET                    0xFFFFFFFF
#define    CRC_CR_RESET                    0x00000000
#define    CRC_IDR_RESET                   0x00
#define    CRC8_poly                        7

void CRC_INIT(void);                 // Enable CRC 
void CRC_DEINIT(void);               // Disable CRC
void CRC_RESET(void);                // Reset DR only 
u32 CRC_READ_DATA(u32 CRC_DATA);  
u32 GET_CRC_DR(void);
void CRC_SET_IDR(u8 CRC_ID_DATA);
u8 CRC_GET_IDR(void);
u32 CRC_HW_32(u32 *Data , u32 size);
u32 CRC_HW_16(u16 *Data , u32 size);
u32 CRC_HW_32(u32 *Data , u32 size);
u8 CRC_SW_8(u8 Data , u8 size , u8 polynomial);

 
#endif
