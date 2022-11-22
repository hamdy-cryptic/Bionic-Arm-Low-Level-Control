/*********************************************************/
/*Author    : youstina                                   */
/*version   : v02                                        */
/*date      : 17 FEB 2021                                */
/*********************************************************/
#ifndef MI2C_INTERFACE_H
#define MI2C_INTERFACE_H

#include "STD_TYPES.h"



/* OPTIONS FOR Copy_u8I2C : I2C1 , I2C2 , I2C3 */
void MI2C_voidInit(u8 Copy_u8I2C );/* SET CONFIGS BEFORE USING I2C */


/* options for Copy_u8SMBusType */
#define     SMBus_Device     0
#define     SMBus_Host       1

//void MI2C_voidSMbus_Mode(u8 Copy_u8SMBusType);



void MI2C_voidEnableDmaRequest(u8 Copy_u8I2C);/* TO TRANSFER DATA WITH DMA */


void MI2C_voidDmaLastTransfer(u8 Copy_u8I2C); /*  used in MASTER RECIEVER mode to permit the generation of a NACK on the last received data */


/* OPTIONS FOR Copy_u8Int : BUFFER_INT , EVENT_INT , ERROR_INT */
void MI2C_voidInterruptEnable( u8 Copy_u8I2C , u8 Copy_u8Int); /* ENABLE INTERRUPTS */
void MI2C_voidInterruptDisable( u8 Copy_u8I2C , u8 Copy_u8Int); /* DISABLE INTERRUPTS */

void MI2C_voidSlaveAddressSetting1(u8 Copy_u8I2C); // IDENTIFY THE OWN_ADDRESS_1

void MI2C_voidEnableDualAdd(u8 Copy_u8I2C );// ENABLE DUAL_ADDRESS_MODE SO 2 SLAVES CAN TRANSFER


/* OPTIONS FOR Copy_u8SlaveAddress : FROM 0x00 TO 0xFF */
void MI2C_voidSlaveTransmitter(u8 Copy_u8I2C );


void MI2C_voidSlaveReciver(u8 Copy_u8I2C  );


void MI2C_voidSlaveTransmitterFinishing(u8 Copy_u8I2C);


void MI2C_voidSlaveRecieverFinishing(u8 Copy_u8I2C);



/* OPTIONS FOR Copy_u16SlaveAddress : 0x0000 to 0x03FF (SENSOR ADDRESS AS IN DATASHEET )*/
void MI2C_voidMasterTransmitter_7bit(u8 Copy_u8I2C , u16 Copy_u16SlaveAddress);
void MI2C_voidMasterTransmitter_10bit(u8 Copy_u8I2C , u16 Copy_u16SlaveAddress);


/* OPTIONS FOR Copy_u8NumberOfData : ONE_BYTE , MORE_THAN_ONE_BYTE */
/* OPTIONS FOR Copy_u8RegAddress : 0x00 to 0xFF */
void MI2C_voidSendRegisterAddress(u8 Copy_u8I2C , u8 Copy_u8NumberOfData ,u8 Copy_u8RegAddress);


void MI2C_voidMasterTransmitterSpecial_7bit(u8 Copy_u8I2C , u8 Copy_u8SlaveAddress, u8 *ARRAY_DATA);
void MI2C_voidMasterRead_7bit(u8 Copy_u8I2C , u16 Copy_u16SlaveAddress );
void MI2C_voidMasterRead_10bit(u8 Copy_u8I2C , u16 Copy_u16SlaveAddress );





void MI2C_voidI2c1_MasterTransmitterFinishing(void);
void MI2C_voidI2c2_MasterTransmitterFinishing(void);
void MI2C_voidI2c3_MasterTransmitterFinishing(void);


void MI2C_voidGetReady(u8 Copy_u8I2C ); // AFTER PREPARING TRANSFER INTERFACES 


void MI2C_voidI2c1_MasterRecieverFinishing(void);
void MI2C_voidI2c2_MasterRecieverFinishing(void);
void MI2C_voidI2c3_MasterRecieverFinishing(void);
void MI2C_Busy(void);

#endif
