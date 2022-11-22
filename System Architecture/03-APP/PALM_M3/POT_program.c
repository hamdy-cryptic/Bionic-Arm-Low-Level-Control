/************************************/
/* Author : Yomna Attia             */
/* Date : 04/06/2021                */
/* version : 01                     */
/************************************/
#include    "STD_TYPES.h"
#include    "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "ADC_interface.h"

#include "POT_interface.h"

   
void Pot_VoidInit(u8 Copy_u8GPIO_Port , u8 Copy_u8PinNum ){
// RCC config 
 RCC_voidEnableClock (RCC_APB2 , RCC_ADC1 );                                                 //enable clock to ADC	
	switch  (Copy_u8GPIO_Port){                                                                //enablw port clock
		case POT_GPIOA: RCC_voidEnableClock (RCC_APB2 , RCC_GPIOA ); break;
		case POT_GPIOB: RCC_voidEnableClock (RCC_APB2 , RCC_GPIOB ); break;
		case POT_GPIOC: RCC_voidEnableClock (RCC_APB2 , RCC_GPIOC ); break;
		case POT_GPIOD: RCC_voidEnableClock (RCC_APB2 , RCC_GPIOD ); break;
		case POT_GPIOE: RCC_voidEnableClock (RCC_APB2 , RCC_GPIOE ); break;
	}
		
//GPIO config 
 GPIO_voidSetPinDirection(Copy_u8GPIO_Port ,  Copy_u8PinNum , GPIO_ANALOG );                // set pin direction :  input/ output/ analog / AF
 SET_GPIO_SPEED( Copy_u8GPIO_Port ,  Copy_u8PinNum, GPIO_SPEED_HIGH);                       //choose speed (Low, Medium , Fast, High)
 GPIO_SET_PU_PD (Copy_u8GPIO_Port ,  Copy_u8PinNum , GPIO_NO_PU_PD  );                    //Use with Input Pin Configuration
//ADC config              	
  MADC_voidInit();                                                                   //initialize ADC in system
}


f32 Pot_f32GetAngle(u8 Copy_u8Channel) 
{
return MADC_u16AnalogSingleRead(Copy_u8Channel)*0.04395604396;  //read the input on analog pin 
}








