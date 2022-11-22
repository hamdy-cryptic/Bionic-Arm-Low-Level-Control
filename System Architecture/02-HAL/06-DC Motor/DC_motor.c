/************************************************************
   Author  :  Omaima                                         
   Date    : 10/5/2021                                         
   Version : V01                                             
*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "PWM_interface.h"

#include "DC_motor.h"




                /************************************  VNH5019 Driver Functions ************************************/


void DC_VNH5019_init(u8 motor)
{ 
	 switch (motor)
	{   
        case M1 : {
			 //Enable Port Clocks:
			 RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
			 RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
			 RCC_voidEnableClock (RCC_AHB1,RCC_GPIOC);
	// VNH5019_M1INA == DC_PA10
		 
			 // Digital output
			 GPIO_voidSetPinDirection(GPIOA , 10 , GPIO_OUTPUT );
			 GPIO_SET_PP_OD (GPIOA , 10, GPIO_OUTPUT_PP); 
			 SET_GPIO_SPEED( GPIOA,10,  GPIO_SPEED_LOW );
			 
	// VNH5019_M1INB == DC_PB5 
		    
			  //Digital output
			 GPIO_voidSetPinDirection(GPIOB , 5 , GPIO_OUTPUT );
			 GPIO_SET_PP_OD (GPIOB , 5, GPIO_OUTPUT_PP); 
			 SET_GPIO_SPEED( GPIOB,5, GPIO_SPEED_LOW );
			 
    // VNH5019_M1EN == DC_PB10
	         
			  //Digital input
			  GPIO_voidSetPinDirection(GPIOB , 10 , GPIO_INPUT );
			  SET_GPIO_SPEED( GPIOB,10, GPIO_SPEED_LOW );
			  GPIO_SET_PU_PD (GPIOB,10,GPIO_PU);
			  
	// VNH5019_M1PWM == DC_PC7 
	    
			   // Digital output pwm
			   GPIO_voidSetPinDirection(GPIOC , 7 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOC , 7, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOC,7, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PC7);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM8);
		       PWM_Init(8);
			   
    // VNH5019_M1CS == DC_PA1
     
				// Analog
                GPIO_voidSetPinDirection(GPIOA , 1 ,GPIO_ANALOG );
				
			break;
		}
		case M2 :
		{
			//Enable Port Clocks:
			 RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
			 RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
			 
			 
	// VNH5019_M2INA == DC_PA8 
		      
			   //Digital output
			   GPIO_voidSetPinDirection(GPIOA , 8, GPIO_OUTPUT );
			   GPIO_SET_PP_OD (GPIOA ,8, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,8,  GPIO_SPEED_LOW );
    
    // VNH5019_M2INB == DC_PA9	
	
			   // Digital output
			   GPIO_voidSetPinDirection(GPIOA , 9, GPIO_OUTPUT );
			   GPIO_SET_PP_OD (GPIOA ,9, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,9,  GPIO_SPEED_LOW );
			   
			   
	 // VNH5019_M2PWM == DC_PB6
	  
			   //Digital output pwm
			   GPIO_voidSetPinDirection(GPIOB , 6 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 6, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,6, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB6);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM4);
		       PWM_Init(4);
			   
    // VNH5019_M2EN == DC_PA6

				// Digital input
				GPIO_voidSetPinDirection(GPIOA , 6 , GPIO_INPUT );
			    SET_GPIO_SPEED( GPIOA,6, GPIO_SPEED_LOW );
				GPIO_SET_PU_PD (GPIOA,6,GPIO_PU); 
				
   // VNH5019_M2CS == DC_PA0
       
				// Analog
				GPIO_voidSetPinDirection(GPIOA , 0 ,GPIO_ANALOG );
				 
			break;
		}
		
        case BOTH:  { 
				//Enable Port Clocks:
			 RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
			 RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
			 RCC_voidEnableClock (RCC_AHB1,RCC_GPIOC);
	// VNH5019_M1INA == DC_PA10
		 
			 // Digital output
			 GPIO_voidSetPinDirection(GPIOA , 10 , GPIO_OUTPUT );
			 GPIO_SET_PP_OD (GPIOA , 10, GPIO_OUTPUT_PP); 
			 SET_GPIO_SPEED( GPIOA,10,  GPIO_SPEED_LOW );
			 
	// VNH5019_M1INB == DC_PB5 
		     
			  //Digital output
			 GPIO_voidSetPinDirection(GPIOB , 5 , GPIO_OUTPUT );
			 GPIO_SET_PP_OD (GPIOB , 5, GPIO_OUTPUT_PP); 
			 SET_GPIO_SPEED( GPIOB,5, GPIO_SPEED_LOW );
			 
    // VNH5019_M1EN == DC_PB10
	           
         
			  //Digital input
			  GPIO_voidSetPinDirection(GPIOB , 10 , GPIO_INPUT );
			  SET_GPIO_SPEED( GPIOB,10, GPIO_SPEED_LOW );
			  GPIO_SET_PU_PD (GPIOB,10,GPIO_PU); 
			  
			  
    // VNH5019_M2INA == DC_PA8 
		      
			   //Digital output
			   GPIO_voidSetPinDirection(GPIOA , 8, GPIO_OUTPUT );
			   GPIO_SET_PP_OD (GPIOA ,8, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,8,  GPIO_SPEED_LOW );
			   
    
    // VNH5019_M2INB == DC_PA9	
		
			   // Digital output
			   GPIO_voidSetPinDirection(GPIOA , 9, GPIO_OUTPUT );
			   GPIO_SET_PP_OD (GPIOA ,9, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,9,  GPIO_SPEED_LOW );
		
    // VNH5019_M1PWM == DC_PC7 
	   
			   // Digital output pwm 
			   GPIO_voidSetPinDirection(GPIOC , 7 , GPIO_AF);
			   SET_GPIO_SPEED( GPIOC,7, GPIO_SPEED_LOW );
			   GPIO_SET_PP_OD (GPIOC , 7, GPIO_OUTPUT_PP); 
			   PWM_Pin (PWM_PC7);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM8);
		       PWM_Init(8);
			   
    // VNH5019_M2PWM == DC_PB6
	  
			   //Digital output pwm
			   GPIO_voidSetPinDirection(GPIOB , 6 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 6, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,6, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB6);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM4);
		       PWM_Init(4);
			   
    // VNH5019_M2EN == DC_PA6
	
				// Digital input
				GPIO_voidSetPinDirection(GPIOA , 6 , GPIO_INPUT );
			    SET_GPIO_SPEED( GPIOA,6, GPIO_SPEED_LOW );
				GPIO_SET_PU_PD (GPIOA,6,GPIO_PU);  
   // VNH5019_M2CS == DC_PA0
       
				// Analog
				GPIO_voidSetPinDirection(GPIOA , 0 ,GPIO_ANALOG );
    
    // VNH5019_M1CS == DC_PA1
      
				// Analog
                GPIO_voidSetPinDirection(GPIOA , 1 ,GPIO_ANALOG );
				break;
		}
		default: break;
	}
}

void DC_VNH5019_SPEED(u8 motor, u32 speed, u32 Period)
{   

    switch(motor)
	{   // VNH5019_M1PWM == DC_PC7 
		case M1 :  PWM_PinWrite(PWM_PC7, speed, Period);
		           break;
	    // VNH5019_M2PWM == DC_PB6
		case M2 :  PWM_PinWrite(PWM_PC7, speed, Period);
                   break;
	    
		default: break;
	}
	
}

void DC_VNH5019_DIRETION(u8 motor ,u8 direction)         // direction : Direction_CW , Direction_CCW  
{   
    if(direction==Direction_CW)
	{
      switch(motor)
	    {  // VNH5019_M1INA == DC_PA10 --> high  &  VNH5019_M1INB == DC_PB5 --> low
		    case M1 :  GPIO_voidSetPinValue(GPIOA , 10 , GPIO_HIGH); 
			           GPIO_voidSetPinValue(GPIOB , 5 , GPIO_LOW);
		           break;
	       // VNH5019_M2INA == DC_PA8 --> high & VNH5019_M2INB == DC_PA9	--> low
		    case M2 :  GPIO_voidSetPinValue(GPIOA , 8 , GPIO_HIGH); 
			           GPIO_voidSetPinValue(GPIOA , 9 , GPIO_LOW);
                   break;
	       
		    default: break;
	    }
    }
	else if(direction== Direction_CCW)
	{  
		switch(motor)
	    {    // VNH5019_M1INA == DC_PA10 --> low  &  VNH5019_M1INB == DC_PB5 --> high
		    case M1 : GPIO_voidSetPinValue(GPIOA , 10 , GPIO_LOW); 
			          GPIO_voidSetPinValue(GPIOB , 5 , GPIO_HIGH); 
		           break;
	         // VNH5019_M2INA == DC_PA8 --> low & VNH5019_M2INB == DC_PA9 --> high
		    case M2 :  GPIO_voidSetPinValue(GPIOA , 8 , GPIO_LOW); 
			           GPIO_voidSetPinValue(GPIOA , 9 , GPIO_HIGH);
                   break;
	        
		    default: break;
	    }
	}
	
}


                    /************************************  L9110  Driver Functions ************************************/

void DC_L9110_MOTOR_init(u8 IA_pin , u8 IB_pin)
{
	// L9110_IA --> PWM
	switch(IA_pin)
	{
		case IB_pin:
			   break;
		case DC_PB1:  
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB , 1 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 1, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,1, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB1);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM3);
		       PWM_Init(3);
		     break;
		
		case DC_PB0 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB , 0 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 0, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,0, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB0);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM3);
		       PWM_Init(3);
		     break;
			 
		case DC_PA7 :
		        RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		        GPIO_voidSetPinDirection(GPIOA, 7 , GPIO_AF);
			    GPIO_SET_PP_OD (GPIOA , 7, GPIO_OUTPUT_PP); 
			    SET_GPIO_SPEED( GPIOA,7, GPIO_SPEED_LOW );
			    PWM_Pin (PWM_PA7);
				//Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM3);
		        PWM_Init(3);
		     break;
		
		case DC_PA6 : 
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 6 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 6, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,6, GPIO_SPEED_LOW );
			   PWM_Pin(PWM_PA6);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM3);
		       PWM_Init(3);		
		     break;
			 			 
		case DC_PA3 :  	
               RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 3 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 3, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,3, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PA3);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM2);
		       PWM_Init(2);		
		     break;
			
		case DC_PB3 :
	           RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 3 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 3, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,3, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB3);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM2);
		       PWM_Init(2);
		     break;
		
	    case DC_PB10 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 10, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 10, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,10, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB10);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM2);
		       PWM_Init(2);
		     break;
			 
		case DC_PB9 :
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 9, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 9, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,9, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB9);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM4);
		       PWM_Init(4);
		     break;
			 
		case DC_PB8 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 8, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 8, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,8, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB8);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM4);
		       PWM_Init(4);
		     break;
			 
		case DC_PB7 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 7, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 7, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,7, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB7);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM4);
		       PWM_Init(4);
		     break;
			 
		case DC_PB6 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 6, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 6, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,6, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB6);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM4);
		       PWM_Init(4);
		     break;
					 
		case DC_PA15 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 15, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 15, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,15, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PA15);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM2);
		       PWM_Init(2);
		     break;
			 
		case DC_PA11 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 11, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 11, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,11, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PA11);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM1);
		       PWM_Init(1);
		     break;
			 
		case DC_PA10 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 10, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 10, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,10, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PA10);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM1);
		       PWM_Init(1);
		     break;
			 
		case DC_PA9 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 9, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 9, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,9, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PA9);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM1);
		       PWM_Init(1);
		     break;
			 
		case DC_PA8 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 8, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 8, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,8, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PA8);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM1);
		       PWM_Init(1);
		     break;
		case DC_PB5 :
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 5, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 5, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,5, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB5);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM3);
		       PWM_Init(3);
			  break;
		case DC_PC6 :
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOC);
		       GPIO_voidSetPinDirection(GPIOC, 6, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOC , 6, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOC,6, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PC6);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM8);
		       PWM_Init(8);
			 break;
		case DC_PC7 :
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOC);
		       GPIO_voidSetPinDirection(GPIOC, 7, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOC , 7, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOC,7, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PC7);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM8);
		       PWM_Init(8);
			 break;
		case DC_PC8 :
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOC);
		       GPIO_voidSetPinDirection(GPIOC, 8, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOC , 8, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOC,8, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PC8);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM8);
		       PWM_Init(8);
			 break;
		case DC_PC9 :
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOC);
		       GPIO_voidSetPinDirection(GPIOC, 9, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOC , 9, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOC,9, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PC9);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM8);
		       PWM_Init(8);
			 break;
			default : break;
			 
	}
	// L9110_IB --> PWM
	switch(IB_pin)
	{
		case IA_pin:
			   break;
		case DC_PB1:  
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB , 1 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 1, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,1, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB1);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM3);
		       PWM_Init(3);
		     break;
		
		case DC_PB0 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB , 0 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 0, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,0, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB0);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM3);
		       PWM_Init(3);
		     break;
			 
		case DC_PA7 :
		        RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		        GPIO_voidSetPinDirection(GPIOA, 7 , GPIO_AF);
			    GPIO_SET_PP_OD (GPIOA , 7, GPIO_OUTPUT_PP); 
			    SET_GPIO_SPEED( GPIOA,7, GPIO_SPEED_LOW );
			    PWM_Pin (PWM_PA7);
				//Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM3);
		        PWM_Init(3);
		     break;
		
		case DC_PA6 : 
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 6 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 6, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,6, GPIO_SPEED_LOW );
			   PWM_Pin(PWM_PA6);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM3);
		       PWM_Init(3);		
		     break;
			 			 
		case DC_PA3 :  	
               RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 3 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 3, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,3, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PA3);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM2);
		       PWM_Init(2);		
		     break;
			
		case DC_PB3 :
	           RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 3 , GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 3, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,3, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB3);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM2);
		       PWM_Init(2);
		     break;
		
	    case DC_PB10 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 10, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 10, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,10, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB10);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM2);
		       PWM_Init(2);
		     break;
			 
		case DC_PB9 :
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 9, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 9, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,9, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB9);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM4);
		       PWM_Init(4);
		     break;
			 
		case DC_PB8 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 8, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 8, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,8, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB8);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM4);
		       PWM_Init(4);
		     break;
			 
		case DC_PB7 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 7, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 7, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,7, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB7);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM4);
		       PWM_Init(4);
		     break;
			 
		case DC_PB6 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 6, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 6, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,6, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB6);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM4);
		       PWM_Init(4);
		     break;
					 
		case DC_PA15 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 15, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 15, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,15, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PA15);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM2);
		       PWM_Init(2);
		     break;
			 
		case DC_PA11 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 11, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 11, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,11, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PA11);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM1);
		       PWM_Init(1);
		     break;
			 
		case DC_PA10 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 10, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 10, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,10, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PA10);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM1);
		       PWM_Init(1);
		     break;
			 
		case DC_PA9 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 9, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 9, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,9, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PA9);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM1);
		       PWM_Init(1);
		     break;
			 
		case DC_PA8 :
		       RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
		       GPIO_voidSetPinDirection(GPIOA, 8, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOA , 8, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOA,8, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PA8);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM1);
		       PWM_Init(1);
		     break;
		case DC_PB5 :
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
		       GPIO_voidSetPinDirection(GPIOB, 5, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOB , 5, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOB,5, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PB5);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB1,RCC_TIM3);
		       PWM_Init(3);
			 break;
		case DC_PC6 :
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOC);
		       GPIO_voidSetPinDirection(GPIOC, 6, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOC , 6, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOC,6, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PC6);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM8);
		       PWM_Init(8);
			 break;
		case DC_PC7 :
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOC);
		       GPIO_voidSetPinDirection(GPIOC, 7, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOC , 7, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOC,7, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PC7);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM8);
		       PWM_Init(8);
			 break;
		case DC_PC8 :
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOC);
		       GPIO_voidSetPinDirection(GPIOC, 8, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOC , 8, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOC,8, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PC8);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM8);
		       PWM_Init(8);
			 break;
		case DC_PC9 :
			   RCC_voidEnableClock(RCC_AHB1,RCC_GPIOC);
		       GPIO_voidSetPinDirection(GPIOC, 9, GPIO_AF);
			   GPIO_SET_PP_OD (GPIOC , 9, GPIO_OUTPUT_PP); 
			   SET_GPIO_SPEED( GPIOC,9, GPIO_SPEED_LOW );
			   PWM_Pin (PWM_PC9);
			   //Set Timer Clock and Initialize Timer
			   RCC_voidEnableClock (RCC_APB2,RCC_TIM8);
		       PWM_Init(8);
			 break;
			default : break;
			 
	}
	    
}


void DC_L9110_MOTOR_SPEED_DIR(u8 IA_pin, u8 IB_pin, u8 direction, u32 speed, u32 Period)
{   

    switch(direction)
		{
							//Set the ground pin acting as reference.   //Set the PWM Value to vary speed
		case Direction_CW   : PWM_PinWrite(IB_pin, 0, 4095); PWM_PinWrite(IA_pin, speed, Period);           break;
		                      
		case Direction_CCW  : PWM_PinWrite(IA_pin, 0, 4095); PWM_PinWrite(IB_pin, speed, Period);           break;
		       
	    default   :  break;
	} 
	
}


