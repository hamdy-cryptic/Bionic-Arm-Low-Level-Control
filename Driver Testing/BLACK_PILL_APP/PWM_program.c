/*************************************************************
   File:        program logic of PWM Driver                  *
   Author:      Hamdy Osama Mohamed                          *
   Version:     V03                                          *
   Date:        22/2/2021                                    *
   Updates:     Added General Purpose Timers as PWM          *
				Added Encoder Feature for supported Timers   *
*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
				 
#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"
				 
#include "GPIO_interface.h"


void PWM_Init(u8 Timer){
	//Check Input Timer
	if(Timer < 15){
		//Set Configuration Properties
		//Set PWM CLOCK
		TIM[Timer] -> CR1 = 0;   //Reset register
		switch (PWM_CLK){        //Check config parameter
			case 1  : TIM[Timer] -> CR1 |= (0<<8);break;
			case 2  : TIM[Timer] -> CR1 |= (1<<8);break;
			case 4  : TIM[Timer] -> CR1 |= (2<<8);break;
			default : break;
		}
		/*****************************/
		if (PWM_PRELOAD<2){ 				               //Check preload config
			TIM[Timer] -> CR1 |= (PWM_PRELOAD<<7);   //set preload config
		}
		else{
			//ERROR
		}
		/******************************/
		switch (PWM_CENTER_ALIGN){			//Check Center Align Mode config
			case OFF     : TIM[Timer] -> CR1 |= (0<<5);break;
			case C_MODE1 : TIM[Timer] -> CR1 |= (1<<5);break;
			case C_MODE2 : TIM[Timer] -> CR1 |= (2<<5);break;
			case C_MODE3 : TIM[Timer] -> CR1 |= (3<<5);break;
			default      : break;
		}
		/******************************/
		if (PWM_COUNT_DIRECTION<2){ 		                   //Check direction config
			TIM[Timer] -> CR1 |= (PWM_COUNT_DIRECTION<<4);   //set direction config
		}
		else{
			//ERROR
		}
		/******************************/
		if (PWM_ONE_PULSE<2){ 		                    //Check one pulse mode config
			TIM[Timer] -> CR1 |= (PWM_ONE_PULSE<<3);   //set one pulse mode config
		}
		else{
			//ERROR
		}
		/******************************/
		TIM[Timer] -> CR2 = 0;   //Reset register
		/******************************/
		TIM[Timer] -> SMCR = 0;  //Reset register
		/******************************/
		TIM[Timer] -> DIER = 0;  //Reset register
		if (PWM_INTERRUPT_ENABLE<2 && PWM_DMA_ENABLE<2){     //Check DMA/INTERRUPT config
			TIM[Timer] -> DIER |= (PWM_DMA_ENABLE<<8);         //set DMA config
			TIM[Timer] -> DIER |= (PWM_INTERRUPT_ENABLE<<0);   //set INTERRUPT config
		}
		else{
			//ERROR
		}
		/******************************/
		TIM[Timer] -> CCMR1 = 0;  //Reset CH1/CH2 register
		TIM[Timer] -> CCMR2 = 0;  //Reset CH3/CH4 register
		switch (PWM_OUTPUT_CHANNELS){
			case 1: {
				if(PWM_PRELOAD == 1){
				TIM[Timer] -> CCMR1 |= (1<<3); //Set Preload on duty cycle on CH1
				}
				if (PWM_MODE == 2){
					TIM[Timer] -> CCMR1 |= (7<<4); //Set CH1 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM[Timer] -> CCMR1 |= (6<<4); //Set CH1 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			case 2: {
				if(PWM_PRELOAD == 1){
				TIM[Timer] -> CCMR1 |= (1<<3);      //Set Preload on duty cycle on CH1
				TIM[Timer] -> CCMR1 |= (1<<11);     //Set Preload on duty cycle on CH2
				}
				if (PWM_MODE == 2){
					TIM[Timer] -> CCMR1 |= (7<<4);  //Set CH1 on PWM Mode 2
					TIM[Timer] -> CCMR1 |= (7<<12); //Set CH2 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM[Timer] -> CCMR1 |= (6<<4);  //Set CH1 on PWM Mode 1
					TIM[Timer] -> CCMR1 |= (6<<12); //Set CH2 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			case 3: {
				if(PWM_PRELOAD == 1){
				TIM[Timer] -> CCMR1 |= (1<<3);      //Set Preload on duty cycle on CH1
				TIM[Timer] -> CCMR1 |= (1<<11);     //Set Preload on duty cycle on CH2
				TIM[Timer] -> CCMR2 |= (1<<3);      //Set Preload on duty cycle on CH3
				}
				if (PWM_MODE == 2){
					TIM[Timer] -> CCMR1 |= (7<<4);  //Set CH1 on PWM Mode 2
					TIM[Timer] -> CCMR1 |= (7<<12); //Set CH2 on PWM Mode 2
					TIM[Timer] -> CCMR2 |= (7<<4);  //Set CH3 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM[Timer] -> CCMR1 |= (6<<4);  //Set CH1 on PWM Mode 1
					TIM[Timer] -> CCMR1 |= (6<<12); //Set CH2 on PWM Mode 1
					TIM[Timer] -> CCMR2 |= (6<<4);  //Set CH3 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			case 4: {
				if(PWM_PRELOAD == 1){
				TIM[Timer] -> CCMR1 |= (1<<3);      //Set Preload on duty cycle on CH1
				TIM[Timer] -> CCMR1 |= (1<<11);     //Set Preload on duty cycle on CH2
				TIM[Timer] -> CCMR2 |= (1<<3);      //Set Preload on duty cycle on CH3
				TIM[Timer] -> CCMR2 |= (1<<11);     //Set Preload on duty cycle on CH4
				}
				if (PWM_MODE == 2){
					TIM[Timer] -> CCMR1 |= (7<<4);  //Set CH1 on PWM Mode 2
					TIM[Timer] -> CCMR1 |= (7<<12); //Set CH2 on PWM Mode 2
					TIM[Timer] -> CCMR2 |= (7<<4);  //Set CH3 on PWM Mode 2
					TIM[Timer] -> CCMR2 |= (7<<12); //Set CH4 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM[Timer] -> CCMR1 |= (6<<4);  //Set CH1 on PWM Mode 1
					TIM[Timer] -> CCMR1 |= (6<<12); //Set CH2 on PWM Mode 1
					TIM[Timer] -> CCMR2 |= (6<<4);  //Set CH3 on PWM Mode 1
					TIM[Timer] -> CCMR2 |= (6<<12); //Set CH4 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			default: break;
		}
		/******************************/
		TIM[Timer] -> CCER = 0; //Reset Channel Enable Register
		if (PWM_POLARITY<1){
			//Set Polarity as configured for all channels
			TIM[Timer] -> CCER |=((1<<13)|(1<<11)|(1<<9)|(1<<7)|(1<<5)|(1<<3)|(1<<1));
		}
		//Enabling Channels and Complementary is done as needed in Write Function
		/******************************/
		if (PWM_PRESCALER<65536){   		//Check Prescaler Config
			TIM[Timer] -> PSC = PWM_PRESCALER; 	//Set Prescaler configured
		}
		/******************************/
		//Reset Other Driver Registers
		TIM[Timer] -> CNT  = 0;
		TIM[Timer] -> ARR  = 0;
		TIM[Timer] -> RCR  = 0;
		TIM[Timer] -> CCR1 = 0;
		TIM[Timer] -> CCR2 = 0;
		TIM[Timer] -> CCR3 = 0;
		TIM[Timer] -> CCR4 = 0;
		TIM[Timer] -> DCR  = 0;
		TIM[Timer] -> DMAR = 0;
		TIM[Timer] -> BDTR = 0;
		//Enable main output for all channels
		TIM[Timer] -> BDTR |= (1<<15);
	}
}




void PWM_PinWrite(u8 Pin, u32 DutyCycle, u32 Period){
	switch (Pin){ //Check Pin used as PWM if supported
		case PWM_PA8 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM1 -> CCR1 = DutyCycle;    //Set Duty cycle in compare register
				TIM1 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM1 -> CCER |=(1<<0);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM1 -> CCER |= (1<<2);  //Enable complementary output for CH1 (CH1N)
				}
				TIM1 -> CR1  |=(1<<0);     //Enable timer 1
			}
			else{
				TIM1 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PA9 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM1 -> CCR2 = DutyCycle;    //Set Duty cycle in compare register
				TIM1 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM1 -> CCER |=(1<<4);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM1 -> CCER |= (1<<6);  //Enable complementary output for CH1 (CH1N)
				}
				TIM1 -> CR1  |=(1<<0);     //Enable timer 1
			}
			else{
				TIM1 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PA10 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM1 -> CCR3 = DutyCycle;    //Set Duty cycle in compare register
				TIM1 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM1 -> CCER |=(1<<8);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM1 -> CCER |= (1<<10);  //Enable complementary output for CH1 (CH1N)
				}
				TIM1 -> CR1  |=(1<<0);     //Enable timer 1
			}
			else{
				TIM1 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PA11 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM1 -> CCR4 = DutyCycle;    //Set Duty cycle in compare register
				TIM1 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM1 -> CCER |=(1<<12);		 //Enable Timer output at CH1
				TIM1 -> CR1  |=(1<<0);     //Enable timer 1
			}
			else{
				TIM1 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH1 
			}
			break;
		}
		case PWM_PC6 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM8 -> CCR1 = DutyCycle;    //Set Duty cycle in compare register
				TIM8 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM8 -> CCER |=(1<<0);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM8 -> CCER |= (1<<2);  //Enable complementary output for CH1 (CH1N)
				}
				TIM8 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM8 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PC7 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM8 -> CCR2 = DutyCycle;    //Set Duty cycle in compare register
				TIM8 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM8 -> CCER |=(1<<4);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM8 -> CCER |= (1<<6);  //Enable complementary output for CH1 (CH1N)
				}
				TIM8 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM8 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PC8 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM8 -> CCR3 = DutyCycle;    //Set Duty cycle in compare register
				TIM8 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM8 -> CCER |=(1<<8);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM8 -> CCER |= (1<<10);  //Enable complementary output for CH1 (CH1N)
				}
				TIM8 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM8 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PC9 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM8 -> CCR4 = DutyCycle;    //Set Duty cycle in compare register
				TIM8 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM8 -> CCER |=(1<<12);		 //Enable Timer output at CH1
				TIM8 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM8 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH1 
			}
			break;
		}
		case PWM_PA15 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM2 -> CCR1 = DutyCycle;    //Set Duty cycle in compare register
				TIM2 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM2 -> CCER |=(1<<0);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM2 -> CCER |= (1<<2);  //Enable complementary output for CH1 (CH1N)
				}
				TIM2 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM2 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PB3 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM2 -> CCR2 = DutyCycle;    //Set Duty cycle in compare register
				TIM2 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM2 -> CCER |=(1<<4);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM2 -> CCER |= (1<<6);  //Enable complementary output for CH1 (CH1N)
				}
				TIM2 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM2 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PB10 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM2 -> CCR3 = DutyCycle;    //Set Duty cycle in compare register
				TIM2 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM2 -> CCER |=(1<<8);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM2 -> CCER |= (1<<10);  //Enable complementary output for CH1 (CH1N)
				}
				TIM2 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM2 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PA3 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM2 -> CCR4 = DutyCycle;    //Set Duty cycle in compare register
				TIM2 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM2 -> CCER |=(1<<12);		 //Enable Timer output at CH1
				TIM2 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM2 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH1 
			}
			break;
		}
		case PWM_PB6 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM4 -> CCR1 = DutyCycle;    //Set Duty cycle in compare register
				TIM4 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM4 -> CCER |=(1<<0);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM4 -> CCER |= (1<<2);  //Enable complementary output for CH1 (CH1N)
				}
				TIM4 -> CR1  |=(1<<0);     //Enable timer 1
			}
			else{
				TIM4 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PB7 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM4 -> CCR2 = DutyCycle;    //Set Duty cycle in compare register
				TIM4 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM4 -> CCER |=(1<<4);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM4 -> CCER |= (1<<6);  //Enable complementary output for CH1 (CH1N)
				}
				TIM4 -> CR1  |=(1<<0);     //Enable timer 1
			}
			else{
				TIM4 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PB8 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM4 -> CCR3 = DutyCycle;    //Set Duty cycle in compare register
				TIM4 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM4 -> CCER |=(1<<8);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM1 -> CCER |= (1<<10);  //Enable complementary output for CH1 (CH1N)
				}
				TIM4 -> CR1  |=(1<<0);     //Enable timer 1
			}
			else{
				TIM4 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PB9 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM4 -> CCR4 = DutyCycle;    //Set Duty cycle in compare register
				TIM4 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM4 -> CCER |=(1<<12);		 //Enable Timer output at CH1
				TIM4 -> CR1  |=(1<<0);     //Enable timer 1
			}
			else{
				TIM4 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH1 
			}
			break;
		}
		case PWM_PA6 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM3 -> CCR1 = DutyCycle;    //Set Duty cycle in compare register
				TIM3 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM3 -> CCER |=(1<<0);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM3 -> CCER |= (1<<2);  //Enable complementary output for CH1 (CH1N)
				}
				TIM3 -> CR1  |=(1<<0);     //Enable timer 3
			}
			else{
				TIM3 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PA7 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM3 -> CCR2 = DutyCycle;    //Set Duty cycle in compare register
				TIM3 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM3 -> CCER |=(1<<4);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM3 -> CCER |= (1<<6);  //Enable complementary output for CH1 (CH1N)
				}
				TIM3 -> CR1  |=(1<<0);     //Enable timer 3
			}
			else{
				TIM3 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PB5 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM3 -> CCR2 = DutyCycle;    //Set Duty cycle in compare register
				TIM3 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM3 -> CCER |=(1<<4);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM3 -> CCER |= (1<<6);  //Enable complementary output for CH1 (CH1N)
				}
				TIM3 -> CR1  |=(1<<0);     //Enable timer 3
			}
			else{
				TIM3 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PB0 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM3 -> CCR3 = DutyCycle;    //Set Duty cycle in compare register
				TIM3 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM3 -> CCER |=(1<<8);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM3 -> CCER |= (1<<10);  //Enable complementary output for CH1 (CH1N)
				}
				TIM3 -> CR1  |=(1<<0);     //Enable timer 1
			}
			else{
				TIM3 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PB1 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM3 -> CCR4 = DutyCycle;    //Set Duty cycle in compare register
				TIM3 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM3 -> CCER |=(1<<12);		 //Enable Timer output at CH1
				TIM3 -> CR1  |=(1<<0);     //Enable timer 1
			}
			else{
				TIM3 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH1 
			}
			break;
		}
		default: break;
	}
	
}




void PWM_PinStop(u8 Pin){
	switch (Pin){ //Check Pin used as PWM if supported
		case PWM_PA8 : {
			TIM1 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			break;
		}
		case PWM_PA9 : {
			TIM1 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH2 and CH2N
			break;
		}
		case PWM_PA10 : {
			TIM1 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH3 and CH3N
			break;
		}
		case PWM_PA11 : {
			TIM1 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH4
			break;
		}
		case PWM_PC6 : {
			TIM8 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			break;
		}
		case PWM_PC7 : {
			TIM8 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH2 and CH2N
			break;
		}
		case PWM_PC8 : {
			TIM8 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH3 and CH3N
			break;
		}
		case PWM_PC9 : {
			TIM8 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH4 
			break;
		}
		case PWM_PA15 : {
			TIM2 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			break;
		}
		case PWM_PB3 : {
			TIM2 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH2 and CH2N
			break;
		}
		case PWM_PB10 : {
			TIM2 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH3 and CH3N
			break;
		}
		case PWM_PA3 : {
			TIM2 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH4 
			break;
		}
		case PWM_PB6 : {
			TIM4 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			break;
		}
		case PWM_PB7 : {
			TIM4 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH2 and CH2N
			break;
		}
		case PWM_PB8 : {
			TIM4 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH3 and CH3N
			break;
		}
		case PWM_PB9 : {
			TIM4 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH4
			break;
		}
		case PWM_PA6 : {
			TIM3 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			break;
		}
		case PWM_PA7 : {
			TIM3 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH2 and CH2N
			break;
		}
		case PWM_PB5 : {
			TIM3 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH2 and CH2N
			break;
		}
		case PWM_PB0 : {
			TIM3 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH3 and CH3N
			break;
		}
		case PWM_PB1 : {
			TIM3 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH4
			break;
		}
		default: break;
}
}



void PWM_Pin (u8 Pin){
	switch (Pin){ //Check Pin used as PWM if supported
		case PWM_PA8 : {
			GPIO_Set_AF(GPIOA , PIN8 , 1 );    //Set pin 8 as alternative function for timer 1
			break;
		}
		case PWM_PA9 : {
			GPIO_Set_AF(GPIOA , PIN9 , 1 );    //Set pin 9 as alternative function for timer 1
			break;
		}
		case PWM_PA10 : {
			GPIO_Set_AF(GPIOA , PIN10 , 1 );    //Set pin 10 as alternative function for timer 1
			break;
		}
		case PWM_PA11 : {
			GPIO_Set_AF(GPIOA , PIN11 , 1 );    //Set pin 11 as alternative function for timer 1
			break;
		}
		case PWM_PC6 : {
			GPIO_Set_AF(GPIOC , PIN6 , 3 );    //Set pin 6 as alternative function for timer 8
			break;
		}
		case PWM_PC7 : {
			GPIO_Set_AF(GPIOC , PIN7 , 3 );    //Set pin 7 as alternative function for timer 8
			break;
		}
		case PWM_PC8 : {
			GPIO_Set_AF(GPIOC , PIN8 , 3 );    //Set pin 8 as alternative function for timer 8
			break;
		}
		case PWM_PC9 : {
			GPIO_Set_AF(GPIOC , PIN9 , 3 );    //Set pin 9 as alternative function for timer 8
			break;
		}
		case PWM_PA15 : {
			GPIO_Set_AF(GPIOA , PIN15 , 1 );    //Set pin 6 as alternative function for timer 2
			break;
		}
		case PWM_PB3 : {
			GPIO_Set_AF(GPIOB , PIN3 , 1 );    //Set pin 7 as alternative function for timer 2
			break;
		}
		case PWM_PB10 : {
			GPIO_Set_AF(GPIOB , PIN10 , 1 );    //Set pin 8 as alternative function for timer 2
			break;
		}
		case PWM_PA3 : {
			GPIO_Set_AF(GPIOA , PIN3 , 1 );    //Set pin 9 as alternative function for timer 2
			break;
		}
		case PWM_PB6 : {
			GPIO_Set_AF(GPIOB , PIN6 , 2 );    //Set pin 8 as alternative function for timer 4
			break;
		}
		case PWM_PB7 : {
			GPIO_Set_AF(GPIOB , PIN7 , 2 );    //Set pin 9 as alternative function for timer 4
			break;
		}
		case PWM_PB8 : {
			GPIO_Set_AF(GPIOB , PIN8 , 2 );    //Set pin 10 as alternative function for timer 4
			break;
		}
		case PWM_PB9 : {
			GPIO_Set_AF(GPIOB , PIN9 , 2 );    //Set pin 11 as alternative function for timer 4
			break;
		}
		case PWM_PA6 : {
			GPIO_Set_AF(GPIOA , PIN6 , 2 );    //Set pin 8 as alternative function for timer 4
			break;
		}
		case PWM_PA7 : {
			GPIO_Set_AF(GPIOA , PIN7 , 2 );    //Set pin 9 as alternative function for timer 4
			break;
		}
		case PWM_PB5 : {
			GPIO_Set_AF(GPIOB , PIN5 , 2 );    //Set pin 10 as alternative function for timer 4
			break;
		}
		case PWM_PB0 : {
			GPIO_Set_AF(GPIOB , PIN0 , 2 );    //Set pin 10 as alternative function for timer 4
			break;
		}
		case PWM_PB1 : {
			GPIO_Set_AF(GPIOB , PIN1 , 2 );    //Set pin 11 as alternative function for timer 4
			break;
		}
		default: break;
}
}

void PWM_StopTimer(u8 Timer){
	if (Timer<15){                 //Check for input timer
		TIM[Timer] ->CR1 &=~(1<<0);  //Disable Timer
	}
	else{
		//Error
	}
}

void PWM_ResumeTimer(u8 Timer){
		if (Timer<15){                 //Check for input timer
		TIM[Timer] ->CR1 |=(1<<0);  //Enable Timer
	}
	else{
		//Error
	}
}

void ENC_Mode(u8 Timer, u16 Period){
	if(Timer<15){
		//Reset Registers not used
    TIM[Timer] -> PSC  = 0;
		TIM[Timer] -> CNT  = 0;
		TIM[Timer] -> RCR  = 0;
		TIM[Timer] -> CCR3 = 0;
		TIM[Timer] -> CCR4 = 0;
		TIM[Timer] -> DCR  = 0;
		TIM[Timer] -> DMAR = 0;
		TIM[Timer] -> BDTR = 0;
	  
		TIM[Timer] ->CCER = 0;       //Close all timer channels for configuring
		
		TIM[Timer] -> CR1 = 0;   //Reset register
		switch (PWM_CLK){        //Check config parameter
			case 1  : TIM[Timer] -> CR1 |= (0<<8);break;
			case 2  : TIM[Timer] -> CR1 |= (1<<8);break;
			case 4  : TIM[Timer] -> CR1 |= (2<<8);break;
			default : break;
		}
		/*****************************/
		if (PWM_PRELOAD<2){ 				               //Check preload config
			TIM[Timer] -> CR1 |= (PWM_PRELOAD<<7);   //set preload config
		}
		else{
			//ERROR
		}
		TIM[Timer] -> CR1 |= (0<<5); //Edge Mode only (not center alligned
		/******************************/
		TIM[Timer] -> CR2 = 0;   //Reset register
		TIM[Timer] -> CR2 |= (3<<4);  //Set TRGO at compare (each pulse causes a slave trigger)
		/******************************/
		TIM[Timer] -> SMCR = 0;  //Reset register
		/******************************/
		TIM[Timer] -> DIER = 0;  //Reset register
		if (ENC_INTERRUPT_ENABLE<2 && ENC_DMA_ENABLE<2){ 		                    //Check DMA/INTERRUPT config
			TIM[Timer] -> DIER |= (ENC_DMA_ENABLE<<8);   //set DMA config
			TIM[Timer] -> DIER |= (ENC_INTERRUPT_ENABLE<<0);   //set INTERRUPT config
		}
		else{
			//ERROR
		}
		/******************************/
		TIM[Timer] -> CCMR1 = 0;  //Reset CH1/CH2 register
		TIM[Timer] -> CCMR2 = 0;  //Reset CH3/CH4 register
		
		TIM[Timer] ->SMCR |= (ENC_MODE<<0); //Set encoder mode as configured
		
		TIM[Timer] ->CCMR1 |= (ENC_FILTER<<4);  //Set configured filter value for CH1
		TIM[Timer] ->CCMR1 |= (ENC_FILTER<<12); //Set configured filter value for CH2
		
		TIM[Timer] ->CCMR1 |=(ENC_PRESCALER<<2);  //Set configured encoder prescaler on CH1
		TIM[Timer] ->CCMR1 |=(ENC_PRESCALER<<10); //Set configured encoder prescaler on CH2
		
		TIM[Timer] ->CCMR1 |=  (1<<0);            //Set CH1 as TI1
		TIM[Timer] ->CCMR1 |=  (1<<8);            //Set CH2 as TI2

		if (PWM_POLARITY<1){
			//Set Polarity as configured for all channels
			TIM[Timer] -> CCER |=((1<<5)|(1<<1)); //Same Polarity configuration as PWM Driver but for CH1 and CH2 only
		}
		TIM[Timer] -> ARR  = Period;           //Set the timer max counting value. (Can be used by programmer to indicate revolutions.)
		TIM[Timer] -> CCR1 = Period;
		TIM[Timer] -> CCR2 = Period;
		//Enable Input Channels (CH1, CH2)
		TIM[Timer] -> CCER |= (1<<0) | (1<<4);
		//Enable Timer
		TIM[Timer] -> CR1 |= (1<<0);
}
  else{
			//Error
	}		
}


u8 ENC_GetDir(u8 Timer){
	if (Timer<15){
		return (((TIM[Timer]->CR1)>>4)&1);  //Return Direction of counter
	}
	else{
		return -1;  //Error State
	}
}

u16 ENC_GetCNT(u8 Timer){
		if (Timer<15){
		return (TIM[Timer]->CNT);  //Return Direction of counter
	}
	else{
		return -1;  //Error State
	}
}

u16 ENC_GetCCR1(u8 Timer){
	if (Timer<15){
		return (TIM[Timer]->CCR1);  //Return Capture-Compare value of channel 1
	}
	else{
		return -1;  //Error State
	}
}

void TRIG_Mode(u8 Timer, u8 TrigType, u8 TrigSrc){
if(Timer<15){
		//Reset Registers not used
        TIM[Timer] -> PSC  = 0;
		TIM[Timer] -> CNT  = 0;
		TIM[Timer] -> RCR  = 0;
		TIM[Timer] -> CCR1 = 0;
		TIM[Timer] -> CCR3 = 0;
		TIM[Timer] -> CCR4 = 0;
	    TIM[Timer] -> CCR2 = 0;
	    TIM[Timer] -> CCMR2= 0;
		TIM[Timer] -> DCR  = 0;
		TIM[Timer] -> DMAR = 0;
		TIM[Timer] -> BDTR = 0;
	  
		TIM[Timer] ->CCER = 0;       //Close all timer channels for configuring
		
		TIM[Timer] -> CR1 = 0;   //Reset register
		switch (PWM_CLK){        //Check config parameter
			case 1  : TIM[Timer] -> CR1 |= (0<<8);break;
			case 2  : TIM[Timer] -> CR1 |= (1<<8);break;
			case 4  : TIM[Timer] -> CR1 |= (2<<8);break;
			default : break;
		}
		/*****************************/
		if (PWM_PRELOAD<2){ 				               //Check preload config
			TIM[Timer] -> CR1 |= (PWM_PRELOAD<<7);   //set preload config
		}
		else{
			//ERROR
		}
		TIM[Timer] -> CR1 |= (0<<5); //Edge Mode only (not center alligned
		/******************************/
		TIM[Timer] -> CR2 = 0;   //Reset register
		/******************************/
		TIM[Timer] -> SMCR = 0;  //Reset register
		TIM[Timer] -> SMCR |= (TrigSrc<<4); //Set Trigger Selection Source
		TIM[Timer] -> SMCR |= (TrigType<<0);//Set Trigger Type
		/******************************/
		TIM[Timer] -> DIER = 0;  //Reset register
		if (PWM_INTERRUPT_ENABLE<2 && PWM_DMA_ENABLE<2){ 		                    //Check DMA/INTERRUPT config
			TIM[Timer] -> DIER |= (PWM_DMA_ENABLE<<8);   //set DMA config
			TIM[Timer] -> DIER |= (PWM_INTERRUPT_ENABLE<<0);   //set INTERRUPT config
		}
		else{
			//ERROR
		}
		/******************************/
		TIM[Timer] -> CCMR1 = 0; //Reset Register
		TIM[Timer] -> CCMR1 |= (3<<0); //Channel 1 as input connected to trigger
		/******************************/
		if (PWM_POLARITY<1){
			//Set Polarity as configured for all channels
			TIM[Timer] -> CCER |=((1<<5)|(1<<1)); //Same Polarity configuration as PWM Driver but for CH1 and CH2 only
		}
		TIM[Timer] -> CCER |= (1<<0); //Enable Channel 1
		TIM[Timer] -> ARR  = 65535;           //Set the timer max counting value. (Can be used by programmer to indicate revolutions.)
		//Enable Timer
		TIM[Timer] -> CR1 |= (1<<0);
}
  else{
			//Error
	}		
}


void ENC_ClearFlag(u8 Timer){
TIM[Timer] -> SR &=~(1<<0);        //Clear interrupt flag from timer registers (NVIC is automatically cleared when interrupt is serviced
}






