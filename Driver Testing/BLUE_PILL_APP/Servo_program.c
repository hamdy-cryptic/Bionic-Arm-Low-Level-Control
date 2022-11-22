/*************************************************************
   File:         data of Servo Driver               *
   Author:      Yomna Abdelhameed                            *
   Version:     V01                                          *
   Date:        06/4/2021                                    *
*************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "PWM_interface.h"

#include "Servo_interface.h"
#include "Servo_config.h"

void Servo_VoidInit(u8 Copy_u8Pin){
switch(Copy_u8Pin)
	{
		
		case SERVO_PB1:  
			   RCC_voidEnableClock(RCC_APB2,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB , 1 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 1, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,1, GPIO_SPEED_LOW );
			   //PWM_Pin (PWM_PB1);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM3);
		       PWM_Init(3);
		     break;
		
		case SERVO_PB0 :
		       RCC_voidEnableClock(RCC_APB2,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB , 0 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 0, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,0, GPIO_SPEED_LOW );
			   //PWM_Pin (PWM_PB0);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM3);
		       PWM_Init(3);
		     break;
			 
		case SERVO_PA7 :
		        RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
		        GPIO_voidSetPinDirection(GPIOA, 7 , GPIO_AF);
			    GPIO_SET_PP_OD (GPIOA , 7, GPIO_OUTPUT_PP); 
			    SET_GPIO_SPEED( GPIOA,7, GPIO_SPEED_LOW );
			   // PWM_Pin (PWM_PA7);
				//Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM3);
		        PWM_Init(3);
		     break;
		
		case SERVO_PA6 : 
			   RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 6 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 6, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,6, GPIO_SPEED_LOW );
			   //PWM_Pin(PWM_PA6);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM3);
		       PWM_Init(3);		
		     break;
			 			 
		case SERVO_PA3 :  	
               RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 3 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 3, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,3, GPIO_SPEED_LOW );
			   //PWM_Pin (PWM_PA3);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM2);
		       PWM_Init(2);		
		     break;
			
		case SERVO_PB3 :
	           RCC_voidEnableClock(RCC_APB2,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 3 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 3, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,3, GPIO_SPEED_LOW );
			  // PWM_Pin (PWM_PB3);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM2);
		       PWM_Init(2);
		     break;
		
	    case SERVO_PB10 :
		       RCC_voidEnableClock(RCC_APB2,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 10, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 10, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,10, GPIO_SPEED_LOW );
			   //PWM_Pin (PWM_PB10);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM2);
		       PWM_Init(2);
		     break;
			 
		case SERVO_PB9 :
			   RCC_voidEnableClock(RCC_APB2,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 9, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 9, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,9, GPIO_SPEED_LOW );
			  // PWM_Pin (PWM_PB9);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM4);
		       PWM_Init(4);
		     break;
			 
		case SERVO_PB8 :
		       RCC_voidEnableClock(RCC_APB2,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 8, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 8, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,8, GPIO_SPEED_LOW );
			  // PWM_Pin (PWM_PB8);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM4);
		       PWM_Init(4);
		     break;
			 
		case SERVO_PB7 :
		       RCC_voidEnableClock(RCC_APB2,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 7, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 7, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,7, GPIO_SPEED_LOW );
			  // PWM_Pin (PWM_PB7);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM4);
		       PWM_Init(4);
		     break;
			 
		case SERVO_PB6 :
		       RCC_voidEnableClock(RCC_APB2,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 6, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 6, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,6, GPIO_SPEED_LOW );
			  // PWM_Pin (PWM_PB6);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM4);
		       PWM_Init(4);
		     break;
					 
		case SERVO_PA15 :
		       RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 15, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 15, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,15, GPIO_SPEED_LOW );
			  // PWM_Pin (PWM_PA15);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM2);
		       PWM_Init(2);
		     break;
			 
		case SERVO_PA11 :
		       RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 11, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 11, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,11, GPIO_SPEED_LOW );
			   //PWM_Pin (PWM_PA11);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM1);
		       PWM_Init(1);
		     break;
			 
		case SERVO_PA10 :
		       RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 10, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 10, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,10, GPIO_SPEED_LOW );
			  // PWM_Pin (PWM_PA10);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM1);
		       PWM_Init(1);
		     break;
			 
		case SERVO_PA9 :
		       RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 9, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 9, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,9, GPIO_SPEED_LOW );
			  // PWM_Pin (PWM_PA9);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM1);
		       PWM_Init(1);
		     break;
			 
		case SERVO_PA8 :
		       RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 8, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 8, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,8, GPIO_SPEED_LOW );
			  // PWM_Pin (PWM_PA8);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM1);
		       PWM_Init(1);
		     break;
		case SERVO_PB5 :
			   RCC_voidEnableClock(RCC_APB2,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 5, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 5, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,5, GPIO_SPEED_LOW );
			   //PWM_Pin (PWM_PB5);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM3);
		       PWM_Init(3);
			 break;
		case SERVO_PC6 :
			   RCC_voidEnableClock(RCC_APB2,RCC_GPIOC);
		       GPIO_voidSetPinDirection(GPIOC, 6, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOC , 6, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOC,6, GPIO_SPEED_LOW );
			  // PWM_Pin (PWM_PC6);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM8);
		       PWM_Init(8);
			 break;
		case SERVO_PC7 :
			   RCC_voidEnableClock(RCC_APB2,RCC_GPIOC);
		       GPIO_voidSetPinDirection(GPIOC, 7, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOC , 7, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOC,7, GPIO_SPEED_LOW );
			 //  PWM_Pin (PWM_PC7);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM8);
		       PWM_Init(8);
			 break;
		case SERVO_PC8 :
			   RCC_voidEnableClock(RCC_APB2,RCC_GPIOC);
		       GPIO_voidSetPinDirection(GPIOC, 8, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOC , 8, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOC,8, GPIO_SPEED_LOW );
			  // PWM_Pin (PWM_PC8);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM8);
		       PWM_Init(8);
			 break;
		case SERVO_PC9 :
			   RCC_voidEnableClock(RCC_APB2,RCC_GPIOC);
		       GPIO_voidSetPinDirection(GPIOC, 9, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOC , 9, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOC,9, GPIO_SPEED_LOW );
			  // PWM_Pin (PWM_PC9);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM8);
		       PWM_Init(8);
			 break;
			default : break;
			 
	}
}


void Servo_VoidWrite(u8 Copy_u8Pin,u8 position){
	u32 Period=0;
	u32 DutyCycle = 0;
	switch (Copy_u8Pin){
		case SERVO_PA8|SERVO_PA9|SERVO_PA10|SERVO_PA11|SERVO_PC6|SERVO_PC7|SERVO_PC8|SERVO_PC9:
			Period = (20*1000)*(SERVO_TIM_CLOCK_APB2);
			DutyCycle = (Period/20)+((position/180)*(Period/5));
			PWM_PinWrite( Copy_u8Pin,  DutyCycle, Period);
			break;
		default:
			Period = (20*1000)*(SERVO_TIM_CLOCK_APB1);
			DutyCycle = (Period/20)+((position/180.0)*(Period/5));
			PWM_PinWrite( Copy_u8Pin,  DutyCycle, Period);
			break;
	}
}

