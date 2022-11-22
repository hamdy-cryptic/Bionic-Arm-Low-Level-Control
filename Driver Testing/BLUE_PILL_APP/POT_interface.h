/************************************/
/* Author : Yomna Attia             */
/* Date : 04/06/2021                */
/* version : 01                     */
/************************************/

#ifndef POT_INTERFACE_C
#define POT_INTERFACE_C

#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "ADC_interface.h"

/* Copy_u8Channel OPTIONS:*/
	 #define POT_PA0     ADC_PA0
	 #define POT_PA1     ADC_PA1
	 #define POT_PA2     ADC_PA2
	 #define POT_PA3     ADC_PA3
	 #define POT_PA4     ADC_PA4
	 #define POT_PA5     ADC_PA5
	 #define POT_PA6     ADC_PA6
	 #define POT_PA7     ADC_PA7
	 #define POT_PB0     ADC_PB0
	 #define POT_PB1     ADC_PB1
	 #define POT_PC0     ADC_PC0
	 #define POT_PC1     ADC_PC1
	 #define POT_PC2     ADC_PC2
	 #define POT_PC3     ADC_PC3
	 #define POT_PC4     ADC_PC4
	 #define POT_PC5     ADC_PC5


          /* Copy_u8GPIO_Port*/
		  
#define      POT_GPIOA        GPIOA
#define      POT_GPIOB        GPIOB
#define      POT_GPIOC        GPIOC
#define      POT_GPIOD        GPIOD
#define      POT_GPIOE        GPIOE
#define      POT_GPIOF        GPIOF
#define      POT_GPIOG        GPIOG
#define      POT_GPIOH        GPIOH


         /* Copy_u8PinNum */
		 
#define      POT_PIN0         PIN0 
#define      POT_PIN1         PIN1 
#define      POT_PIN2         PIN2 
#define      POT_PIN3         PIN3 
#define      POT_PIN4         PIN4 
#define      POT_PIN5         PIN5 
#define      POT_PIN6         PIN6 
#define      POT_PIN7         PIN7 
#define      POT_PIN8         PIN8 
#define      POT_PIN9         PIN9 
#define      POT_PIN10        PIN10
#define      POT_PIN11        PIN11
#define      POT_PIN12        PIN12
#define      POT_PIN13        PIN13
#define      POT_PIN14        PIN14
#define      POT_PIN15        PIN15

//this function is used for initialization 
void Pot_VoidInit(u8 Copy_u8GPIO_Port , u8 Copy_u8PinNum );

//this function is used to get the angle of the potentiometer
f32 Pot_f32GetAngle(u8 Copy_u8Channel) ; 


#endif
