/************************************************************
   Author  :  Omaima                                         
   Date    : 6/6/2021                                         
   Version : V01                                             
*************************************************************/
#ifndef  SMBUS_INTERFACE_H
#define  SMBUS_INTERFACE_H


#include "STD_TYPES.h"

void SMBUS_init(); //initiate configurations of smbus
void SMBUS_START();
void SMBUS_SEND_SLAVE_ADDRESS(u8 ADDRESS , u8 RD_WR_bit);
void SMBUS_SEND_DATA(u8 *COMMAND);
u8 SMBUS_READ_DATA(u16* data);
void SMBUS_CHECK_READ_DATA();
void SMBUS_STOP();
u8 SMBUS_CRC8(u8 Data);




/************************* Options *******************/

#define SMBUS_I2C_HOST           1
#define SMBUS_I2C_DEVICE         0

#define SMBUS_I2C_DUTY_2         0
#define SMBUS_I2C_DUTY_16_9      1

#define SMBUS_I2C_ACK_ENABLED    0
#define SMBUS_I2C_ACK_DISABLED   1

#define SMBUS_I2C_ACK_ADDRESS_7_BIT   0
#define SMBUS_I2C_ACK_ADDRESS_10_BIT  1

#define SMBUS_I2C_ALERT_LOW           0
#define SMBUS_I2C_ALERT_HIGH          1

#define   WR_BIT            0x00
#define   RD_BIT            0x01

#endif
