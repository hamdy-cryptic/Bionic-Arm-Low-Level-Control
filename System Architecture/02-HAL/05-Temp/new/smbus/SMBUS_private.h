/************************************************************
   Author  :  Omaima                                         
   Date    : 6/6/2021                                         
   Version : V01                                             
*************************************************************/
#ifndef  SMBUS_PRIVATE_H
#define  SMBUS_PRIVATE_H

#include "STD_TYPES.h"

typedef struct
{
	volatile u32 SMB_CR1;
	volatile u32 SMB_CR2;
	volatile u32 SMB_OAR1;
	volatile u32 SMB_OAR2;
	volatile u32 SMB_DR;
	volatile u32 SMB_SR1;
	volatile u32 SMB_SR2;
	volatile u32 SMB_CCR;
	volatile u32 SMB_TRISE;
	volatile u32 SMB_FLTR;
}SMBUS_I2C_t;


#define      SMBUS_I2C_1    ((volatile SMBUS_I2C_t*)0x40005400)
#define      SMBUS_I2C_2    ((volatile SMBUS_I2C_t*)0x40005800)
#define      SMBUS_I2C_3    ((volatile SMBUS_I2C_t*)0x40005C00)

#endif

