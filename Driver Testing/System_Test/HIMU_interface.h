/*********************************************************/
/*Author    : youstina                                   */
/*version   : v01                                        */
/*date      : 21 MAR 2021                                */
/*********************************************************/

#ifndef HIMU_INTERFACE_H
#define HIMU_INTERFACE_H


#include "STD_TYPES.h"

//SDA is connected to: PC9   //PB4 in Black Pill
//SCL is connected to: PA8
// pin AD0 is logic low
#define SENSOR_ADDRESS      0b1101000




#define         ACC_SENSITIVITY           (0xFFFF/(1<<(2+AFS_SEL)))
#define         GYR_SENSITIVITY          (0xFFFF/(500*(1<<GFS_SEL)))


void HIMU_VoidSetUp(void);

void HIMU_VoidReading(void);

u16 HIMU_U16GetYaw(void);

u16 HIMU_U16GetPitch(void);

u16 HIMU_U16GetRoll(void);
/*
void HIMU_VoidPreInit (void); // to set configuration related to i2c , dma and gpio & check for right connnection

void HIMU_VoidConfig(u8 *Copy_u8Array );

void HIMU_VoidInit (void);

void HIMU_VoidGetAcc_XResult();

void HIMU_VoidGetAcc_YResult();

void HIMU_VoidGetAcc_ZResult();

void HIMU_VoidGetGyro_XResult();

void HIMU_VoidGetGyro_YResult();

void HIMU_VoidGetGyro_ZResult();
void HIMU_VoidGetTemp_Result();

*/





#endif












