/************************************************************
   Author  :  Omaima                                         
   Date    : 10/5/2021                                         
   Version : V01                                             
*************************************************************/

#include "STD_TYPES.h"


 /************************************  VNH5019 Driver Functions ************************************/
 
																														
			// motor options : M1 , M2 , BOTH
 void DC_VNH5019_init(u8 motor);  
      // speed -> Duty cycle  
 void DC_VNH5019_SPEED(u8 motor, u32 speed, u32 Period); 
     // direction : Direction_CW  , Direction_CCW
 void DC_VNH5019_DIRETION(u8 motor ,u8 direction);      



/************************************  L9110  Driver Functions ************************************/

 
/*** (AIA_pin || AIB_pin || BIA_pin || BIB_pin)  pins : DC_PB1 , DC_PB0 , DC_PA7 , DC_PA6 , DC_PA3 , DC_PB3 , DC_PB10 , DC_PB9 , DC_PB8 , DC_PB7 , DC_PB6 , DC_PA15 , DC_PA11 , DC_PA10  , DC_PA9 , DC_PA8
* NOTE: if you choose a pin for one parameter, don't repeat it with another parameter ****/


void DC_L9110_MOTOR_init(u8 IA_pin , u8 IB_pin);    // to intialize motor : GPIOs , PWMs  configurations (CAN BE USED TWICE FOR DUAL MODULE)

/*** we used IA & IB pins as pwm to control speed and direction ****/
         // speed  -> Duty cycle    ,  Period -> period of pwm signal
void DC_L9110_MOTOR_SPEED_DIR(u8 IA_pin, u8 IB_pin, u8 direction, u32 speed, u32 Period);  // to control the speed of MOTOR using pwm and determine direction

	  
       // direction options  : Direction_CW  , Direction_CCW
	   //Speed and period arguments are made as in pwm driver 

 
 
 
 
// motor options for vnh5019 driver
 
#define M1                        0
#define M2                        1
#define BOTH                      2

// DC motor Direction 

#define Direction_CW              0
#define Direction_CCW             1

// L9110_PINS 

#define DC_PB1                       PWM_PB1
#define DC_PB0                       PWM_PB0
#define DC_PA7                       PWM_PA7
#define DC_PA6                       PWM_PA6
#define DC_PA3                       PWM_PA3
#define DC_PB3                       PWM_PB3
#define DC_PB10                      PWM_PB10
#define DC_PB9                       PWM_PB9
#define DC_PB8                       PWM_PB8
#define DC_PB7                       PWM_PB7
#define DC_PB6                       PWM_PB6
#define DC_PA15                      PWM_PA15
#define DC_PA11                      PWM_PA11
#define DC_PA10                      PWM_PA10
#define DC_PA9                       PWM_PA9
#define DC_PA8                       PWM_PA8
#define DC_PB5                       PWM_PB5
#define DC_PC6                       PWM_PC6
#define DC_PC7                       PWM_PC7
#define DC_PC8                       PWM_PC8
#define DC_PC9                       PWM_PC9