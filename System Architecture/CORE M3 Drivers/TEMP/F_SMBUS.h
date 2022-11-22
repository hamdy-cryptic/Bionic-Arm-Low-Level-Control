#include "STD_TYPES.h"
#include "GPIO_interface.h"

#ifndef F_SMBUS_H
#define F_SMBUS_H

#define   SMBUS_SCL_PORT          GPIOB
#define   SMBUS_SCL_PIN             8
#define   SMBUS_SDA_PORT          GPIOB
#define   SMBUS_SDA_PIN             9





#define SMBUS_SCL_H()   GPIO_voidSetPinValue(SMBUS_SCL_PORT , SMBUS_SCL_PIN , GPIO_HIGH);
#define SMBUS_SCL_L()   GPIO_voidSetPinValue(SMBUS_SCL_PORT , SMBUS_SCL_PIN , GPIO_LOW);
#define SMBUS_SDA_H()   GPIO_voidSetPinValue(SMBUS_SDA_PORT , SMBUS_SDA_PIN , GPIO_HIGH);
#define SMBUS_SDA_L()   GPIO_voidSetPinValue(SMBUS_SDA_PORT , SMBUS_SDA_PIN , GPIO_LOW);
     

void SMBUS_START(void);
void SMBUS_SEND_SLAVE_ADDRESS(u8 byte_data);
//void DELAY_us(u16 N);
u8 SMBUS_S_TO_M_ACK(void);
u8 SMBUS_READ_BYTE(void);
void SMBUS_M_TO_S_ACK(void);
void SMBUS_STOP(void);

#endif
