/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 12 February 2020                                 */
/* Version : V01                                             */
/*************************************************************/
#ifndef TEMP_INTERFACE_H
#define TEMP_INTERFACE_H
#include "STD_TYPES.h"

void TEMP_SENSOR_Init(void);          //Initialize SMBus Mode and Sensor Pins and Module
f64  TEMP_READ( u64 TEMP_SOURCE, u64 TEMP_UNIT);  //Used to return temperature reading

/***********************For Advanced Users Only***********************************************/
void CRITICAL_GPIO_Config(void);      // Define Pins used by sensor  (The user might not use this function as it is called inside initialization function
u16 READ_RAM_EEPROM(u8 Command);      //Read temperature from RAM of Sensor (Might not used by the user
f64 TEMP_CONVERSION_K_TO_C(f64 Degree_K);
f64   TEMP_CONVERSION_C_TO_F(f64 Degree_C);
f64   TEMP_CONVERSION_K_TO_F(f64 Degree_K);





//This driver obligates the use of I2C2 Pins only:
//PTB10 (SCL) , PTB3 (SDA)


/*
OPTIONS for Command argument:
TEMP_TA , TEMP_TO_1 , TEMP_TO_2
ambient     object1    object2
*/

/*
OPTIONS for TEMP_SOURCE argument:
TEMP_SOURCE_AMBIENT , TEMP_OBJ_IR_SOURCE_1 , TEMP_OBJ_IR_SOURCE_2
*/

/*
OPTIONS for TEMP_UNIT argument:
TEMP_Kelvin , TEMP_Centigrade, TEMP_Fahrenheit
*/


            /*  Temperature units  */
			
#define     TEMP_Kelvin                           0
#define     TEMP_Centigrade                       1
#define     TEMP_Fahrenheit                       2

           /* Temperature   Source  */
		   
#define    TEMP_SOURCE_AMBIENT                    0
#define    TEMP_OBJ_IR_SOURCE_1                   1
#define    TEMP_OBJ_IR_SOURCE_2                   2
	





      



















#endif
