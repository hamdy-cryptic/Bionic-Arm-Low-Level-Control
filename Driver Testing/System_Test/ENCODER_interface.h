/******************************************************************/
/* File    : Encoder Interface File  to use the driver features   */
/* Date    : 2/4/2021                                             */
/* Version : V01                                                  */
/* Updates : ---                                                  */
/* Author  : Hamdy Osama                                          */
/******************************************************************/


#ifndef ENCODER_INTERFACE_H
#define ENCODER_INTERFACE_H
#include "STD_TYPES.h"
#include "ENCODER_private.h"

void ENCODER_Define (encoder_t *name, u8 PinSet);//Used to map a pin set to a defined encoder type variable
void ENCODER_Init(encoder_t *encoder);           //Used to initialize the encoder pins (as described below)
u32 ENCODER_CurrentPosition(encoder_t *encoder); //Return the current position (in degrees)
u32 ENCODER_CurrentSpeed(encoder_t *encoder);    //Return the current speed of the encoder (in rpm)
s32 ENCODER_Rotations(encoder_t *encoder);       //Return the number of rotations (from initial homing) (+ve is one direction, -ve is opposite direction)
u8 ENCODER_CurrentDirection(encoder_t *encoder); //Return the current direction of the encoder shaft rotation

/*Steps to use the driver:
	1- Define a variable of the type encoder_t that represents your own encoder instance. Check the following example for illustration
	2- Initialize the encoder pins using ENCODER_Init with your encoder instance as a parameter
	3- Start using the functions stated above as intended.
*/

/*Defining a vaiable of type encoder_t example:
	Using pins set #1 
	encoder_t myEncoder;
	ENCODER_Define(myEncoder,ENC_PINS_1);
*/

/*Sets of pins that are supported for running multiple encoders simultaneously

		Set Name             Channel 1 pin              Channel 2 pin
		ENC_PINS_1                PA8                        PA9
		ENC_PINS_2                PC6                        PC7
		ENC_PINS_3                PA15                       PB3

*/

#define ENC_PINS_1    1      //{PWM_PA8,PWM_PA9,PWM_PB6}
#define ENC_PINS_2    8      //{PWM_PC6,PWM_PC7,PWM_PB6}
#define ENC_PINS_3    2      //{PWM_PA15,PWM_PB3,PWM_PA6}

#endif
