/************************************************************
   Author  :  Omaima                                         
   Date    : 6/6/2021                                         
   Version : V01                                             
*************************************************************/
#ifndef MLX90614_H
#define MLX90614_H

#include "STD_TYPES.h"



f32  MLX90614_READ_TEMPERATURE( u8 SOURCE, u8 UNIT);

/***-----------------------------------------------------------***/
f32 MLX90614_READ(u8 ambient_or_object);
f32 MLX90614_CONVERSION_K_TO_C(f32 Degree_K);
f32 MLX90614_CONVERSION_C_TO_F(f32 Degree_C);
f32 MLX90614_CONVERSION_K_TO_F(f32 Degree_K);




/*********************** Options ************************/


#define   MLX90614_ADD      0x5A
#define   WR_BIT            0x00
#define   RD_BIT            0x01


#define    MLX90614_RAM_ACCESS              0x00
#define    MLX90614_EEPROM_ACCESS           0x20

#define    MLX90614_TA                      0x06  
#define    MLX90614_TO_1                    0x07 
#define    MLX90614_TO_2                    0x08


#define     MLX90614_TO_MAX                 0x20
#define     MLX90614_TO_MIN                 0x21



            /*  Temperature units  */
			
#define     MLX90614_Kelvin                           0
#define     MLX90614_Centigrade                       1
#define     MLX90614_Fahrenheit                       2

           /* Temperature   Source  */
		   
#define    MLX90614_SOURCE_AMBIENT                    0
#define    MLX90614_OBJ_IR_SOURCE_1                   1
#define    MLX90614_OBJ_IR_SOURCE_2                   2

#endif