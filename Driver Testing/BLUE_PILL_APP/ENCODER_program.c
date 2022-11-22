/******************************************************************/
/* File    : Encoder Program File with driver logic               */
/*               (USER MODIFICATION IS BANNED)                    */
/* Date    : 2/4/2021                                             */
/* Version : V01                                                  */
/* Updates : ---                                                  */
/* Author  : Hamdy Osama                                          */
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "GPIO_interface.h"
#include "PWM_interface.h"

#include "ENCODER_private.h"
#include "ENCODER_config.h"
#include "ENCODER_interface.h"

volatile s32 Tim1_overflow = 0;
volatile s32 Tim2_overflow = 0;
volatile s32 Tim8_overflow = 0;
volatile s32 Tim4_overflow = 0;

u32 ENCODER_CurrentPosition(encoder_t *encoder){
	switch (encoder->pins_set){                 //Check which encoder is called
		
	case ENC_PINS_1:           //Get value in counter register and add it to overflow counter to identify total degrees from initial position
	encoder->position = ((Tim1_overflow<<16)+ENC_GetCNT(TIMER1))*(360/(ENCODER_EPR));break;
	
	case ENC_PINS_2:
	encoder->position = ((Tim8_overflow<<16)+ENC_GetCNT(TIMER8))*(360/(ENCODER_EPR));break;
	
	case ENC_PINS_3:
	encoder->position = ((Tim2_overflow<<16)+ENC_GetCNT(TIMER2))*(360/(ENCODER_EPR));break;
	
	case ENC_PINS_4:
	encoder->position = ((Tim2_overflow<<16)+ENC_GetCNT(TIMER2))*(360/(ENCODER_EPR));break;
	}
	encoder->revolutions = encoder->position/360.0;      //compute # of revolutions
	encoder->position = encoder->position - 360*encoder->revolutions;  //Limit position from 0 to 359 degrees
	return encoder->position; //Return encoder position
}



u8 ENCODER_CurrentDirection(encoder_t *encoder){
	switch (encoder->pins_set){       //Check which encoder is called
		
	case ENC_PINS_1:
	encoder->direction = ENC_GetDir(TIMER1);break;  //Get direction from timer register
	
	case ENC_PINS_2:
	encoder->direction = ENC_GetDir(TIMER8);break;
	
	case ENC_PINS_3:
	encoder->direction = ENC_GetDir(TIMER2);break;
	
	case ENC_PINS_4:
	encoder->direction = ENC_GetDir(TIMER2);break;
	}
	return encoder->direction;    //Return direction

}


float ENCODER_CurrentSpeed(encoder_t *encoder){
	switch (encoder->pins_set){            //Check which encoder is called
		
	case ENC_PINS_1: 
	encoder->speed = ENC_GetCCR1(TIMER4);break;      //Get Capture value from interfacing timer register
	
	case ENC_PINS_2:
	encoder->speed = ENC_GetCCR1(TIMER4);break;
	
	case ENC_PINS_3:
	encoder->speed = ENC_GetCCR1(TIMER3);break;
	
	case ENC_PINS_4:
	encoder->speed = ENC_GetCCR1(TIMER1);break;
	}
	encoder->speed = ((ENC_TIM_CLK*1000000)/((ENCODER_EPR/2)*(encoder ->speed)))*60 ; //Equate speed based on system frequency  RPM
	return encoder->speed;
}

s32 ENCODER_Rotations(encoder_t *encoder){
	switch (encoder->pins_set){                 //Check which encoder is called
		
	case ENC_PINS_1:           //Get value in counter register and add it to overflow counter to identify total degrees from initial position
	encoder->position = ((Tim1_overflow<<16)+ENC_GetCNT(TIMER1))*(360/(ENCODER_EPR));break;
	
	case ENC_PINS_2:
	encoder->position = ((Tim8_overflow<<16)+ENC_GetCNT(TIMER8))*(360/(ENCODER_EPR));break;
	
	case ENC_PINS_3:
	encoder->position = ((Tim2_overflow<<16)+ENC_GetCNT(TIMER2))*(360/(ENCODER_EPR));break;
	
	case ENC_PINS_4:
	encoder->position = ((Tim2_overflow<<16)+ENC_GetCNT(TIMER2))*(360/(ENCODER_EPR));break;
	}
	encoder->revolutions = encoder->position/360;      //compute # of revolutions
	encoder->position = encoder->position - 360*encoder->revolutions;  //Limit position from 0 to 359 degrees
	return encoder->revolutions; //Return encoder revolutions
}



void ENCODER_Init(encoder_t *encoder){
	
	switch (encoder->pins_set){                                      //Check which encoder is initialized
		case ENC_PINS_1:
			RCC_voidEnableClock(RCC_APB2,RCC_TIM1);                 //Enable Encoder Timer Counter Clock
			RCC_voidEnableClock(RCC_APB1,RCC_TIM4);                 //Enable Encoder Timer Interfacing Clock
			RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);                //Enable Encoder Pins GPIO Port Clock
			
			GPIO_voidSetPinDirection(GPIOA,PIN8,GPIO_INPUT);           //Configure Pin GPIO Mode     CH1
			SET_GPIO_SPEED(GPIOA,PIN8,GPIO_SPEED_HIGH);             //Configure Pin Speed (Max)
			GPIO_SET_PU_PD(GPIOA,PIN8,GPIO_NO_PU_PD);               //Configure pin pull mode
			
			
			GPIO_voidSetPinDirection(GPIOA,PIN9,GPIO_INPUT);           //Configure Pin GPIO Mode     CH2
			SET_GPIO_SPEED(GPIOA,PIN9,GPIO_SPEED_HIGH);             //Configure Pin Speed (Max)
			GPIO_SET_PU_PD(GPIOA,PIN9,GPIO_NO_PU_PD);               //Configure pin pull mode
			
			
			MNVIC_voidEnableInterrupt(TIM1_UP_TIM10);                 //Enable timer interrupts
			
			ENC_Mode(TIMER1,65535);                                 //Set timer in encoder mode with maximum counter ticks
			TRIG_Mode(TIMER4, PWM_RESET, 0);                        //Set interfacing timer to be triggered by counter timer capture flag
	
			break;
			
		case ENC_PINS_2:
			RCC_voidEnableClock(RCC_APB2,RCC_TIM8);
			RCC_voidEnableClock(RCC_APB1,RCC_TIM4);
			RCC_voidEnableClock(RCC_APB2,RCC_GPIOC);
			
			GPIO_voidSetPinDirection(GPIOC,PIN6,GPIO_INPUT);
			SET_GPIO_SPEED(GPIOC,PIN6,GPIO_SPEED_HIGH);
			GPIO_SET_PU_PD(GPIOC,PIN6,GPIO_NO_PU_PD);
			
			GPIO_voidSetPinDirection(GPIOC,PIN7,GPIO_INPUT);
			SET_GPIO_SPEED(GPIOC,PIN7,GPIO_SPEED_HIGH);
			GPIO_SET_PU_PD(GPIOC,PIN7,GPIO_NO_PU_PD);
			
			MNVIC_voidEnableInterrupt(TIM8_UP_TIM13);
			
			ENC_Mode(TIMER8,65535);
			TRIG_Mode(TIMER4, PWM_RESET, 3);
	
			break;
			
		case ENC_PINS_3:
			RCC_voidEnableClock(RCC_APB1,RCC_TIM2);
			RCC_voidEnableClock(RCC_APB1,RCC_TIM3);
			RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
			RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
			
			GPIO_voidSetPinDirection(GPIOA,PIN15,GPIO_INPUT);
			SET_GPIO_SPEED(GPIOA,PIN15,GPIO_SPEED_HIGH);
			GPIO_SET_PU_PD(GPIOA,PIN15,GPIO_NO_PU_PD);
		
			
			GPIO_voidSetPinDirection(GPIOB,PIN3,GPIO_INPUT);
			SET_GPIO_SPEED(GPIOB,PIN3,GPIO_SPEED_HIGH);
			GPIO_SET_PU_PD(GPIOB,PIN3,GPIO_NO_PU_PD);
			
			
			MNVIC_voidEnableInterrupt(NVIC_TIM2);
			
			ENC_Mode(TIMER2,65535);
			TRIG_Mode(TIMER3, PWM_RESET, 1);
	
			break;

case ENC_PINS_4:
			RCC_voidEnableClock(RCC_APB2,RCC_TIM1);
			RCC_voidEnableClock(RCC_APB1,RCC_TIM2);
			RCC_voidEnableClock(RCC_APB2,RCC_GPIOA);
			
			GPIO_voidSetPinDirection(GPIOA,PIN0,GPIO_INPUT);
			SET_GPIO_SPEED(GPIOA,PIN0,GPIO_SPEED_HIGH);
			GPIO_SET_PU_PD(GPIOA,PIN0,GPIO_NO_PU_PD);
			
			GPIO_voidSetPinDirection(GPIOA,PIN1,GPIO_INPUT);
			SET_GPIO_SPEED(GPIOA,PIN1,GPIO_SPEED_HIGH);
			GPIO_SET_PU_PD(GPIOA,PIN1,GPIO_NO_PU_PD);
			
			MNVIC_voidEnableInterrupt(NVIC_TIM2);
			
			ENC_Mode(TIMER2,65535);
			TRIG_Mode(TIMER1, PWM_RESET, 1);
	
			break;
	
	
	}
}

void ENCODER_Define (encoder_t *name, u8 PinSet){
	name->pins_set = PinSet;
	ENCODER_Init(name);
}



void TIM1_UP_TIM10_IRQHandler(){
	 if (ENC_GetCNT(TIMER1)==0)   //Check counter overflow or underflow
		Tim1_overflow++;         //Increment overflow variable
	else                         //else
		Tim1_overflow--;         //decrement overflow variable
	ENC_ClearFlag(TIMER1);
}


void TIM2_IRQHandler(){
	if (ENC_GetCNT(TIMER2)==0)
		Tim2_overflow++;
	else
		Tim2_overflow--;
	ENC_ClearFlag(TIMER2);
}

void TIM8_UP_TIM13_IRQHandler(){
	if (ENC_GetCNT(TIMER8)==0)
		Tim8_overflow++;
	else
		Tim8_overflow--;
	ENC_ClearFlag(TIMER8);
}

void TIM4_IRQHandler(){
	if (ENC_GetCNT(TIMER4)==0)
		Tim4_overflow++;
	else
		Tim4_overflow--;
	ENC_ClearFlag(TIMER4);
}