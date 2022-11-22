/*************************************************************
   File:         data of Servo Driver               *
   Author:      Yomna Abdelhameed                            *
   Version:     V01                                          *
   Date:        06/4/2021                                    *
*************************************************************/

#ifndef Servo_interface_h
#define Servo_interface_h

#include "STD_TYPES.h"
#include "PWM_interface.h"

   
   /*Pins available for Copy_u8Pin*/
 
   #define  SERVO_PA8      PWM_PA8    
   #define  SERVO_PA9      PWM_PA9    
   #define  SERVO_PA10     PWM_PA10   
   #define  SERVO_PA11     PWM_PA11   
		          
   #define  SERVO_PC6      PWM_PC6    
   #define  SERVO_PC7      PWM_PC7    
   #define  SERVO_PC8      PWM_PC8    
   #define  SERVO_PC9      PWM_PC9    
		          
   #define  SERVO_PA15     PWM_PA15   
   #define  SERVO_PB3      PWM_PB3    
   #define  SERVO_PB10     PWM_PB10   
   #define  SERVO_PA3      PWM_PA3    
		         
   #define  SERVO_PA6      PWM_PA6   
   #define  SERVO_PA7      PWM_PA7   
   #define  SERVO_PB0      PWM_PB0    
   #define  SERVO_PB1      PWM_PB1
   #define  SERVO_PB4      PWM_PB4 	 
   #define  SERVO_PB5      PWM_PB5   
		          
   #define  SERVO_PB6      PWM_PB6    
   #define  SERVO_PB7      PWM_PB7    
   #define  SERVO_PB8      PWM_PB8    
   #define  SERVO_PB9      PWM_PB9    
 
 
 
/*
#functions                                                                                                                    
Servo_Init: to enable clock to the chosen time and initialize it and the pin              
Servo_Write: generates pwm in the chosen pin to make the servo get the desired position  
*/
void Servo_VoidInit(u8 Copy_u8Pin);
void Servo_VoidWrite(u8 Copy_u8Pin,u8 position); //Position ranges from 0 to 180 (desired servo angle)

#endif