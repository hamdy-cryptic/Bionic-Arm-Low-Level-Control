/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 24 MAR 2021                            */
/* Version   : 01                                     */
/******************************************************/

#include "DataTypes_and_BitMath.h"
#include "FSR_Interface.h"
#include "FSR_Configuration.h"
#include "FSR_Private.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "ADC_interface.h"

/************************ Index Equation ***********************/

void fsrInitialize (void)
{
	if (FSR_PORT == 'A')
	{
		RCC_voidEnableClock (RCC_AHB1, RCC_GPIOA);
		GPIO_voidSetPinDirection(GPIOA, FSR_PIN, GPIO_ANALOG);
		SET_GPIO_SPEED(GPIOA, FSR_PIN, GPIO_SPEED);
    GPIO_SET_PU_PD (GPIOA, FSR_PIN, GPIO_NO_PU_PD);     
	}
	else if (FSR_PORT == 'B')
	{
		RCC_voidEnableClock (RCC_AHB1, RCC_GPIOB);
		GPIO_voidSetPinDirection(GPIOB, FSR_PIN, GPIO_ANALOG);
		SET_GPIO_SPEED(GPIOB, FSR_PIN, GPIO_SPEED);
    GPIO_SET_PU_PD (GPIOB, FSR_PIN, GPIO_NO_PU_PD); 
	}
	else if (FSR_PORT == 'C')
	{
		RCC_voidEnableClock (RCC_AHB1, RCC_GPIOC);
		GPIO_voidSetPinDirection(GPIOC, FSR_PIN, GPIO_ANALOG);
		SET_GPIO_SPEED(GPIOC, FSR_PIN, GPIO_SPEED);
    GPIO_SET_PU_PD (GPIOC, FSR_PIN, GPIO_NO_PU_PD); 
	}
	else if (FSR_PORT == 'D')
	{
		RCC_voidEnableClock (RCC_AHB1, RCC_GPIOD);
		GPIO_voidSetPinDirection(GPIOD, FSR_PIN, GPIO_ANALOG);
		SET_GPIO_SPEED(GPIOD, FSR_PIN, GPIO_SPEED);
    GPIO_SET_PU_PD (GPIOD, FSR_PIN, GPIO_NO_PU_PD); 
	}
	else if (FSR_PORT == 'E')
	{
		RCC_voidEnableClock (RCC_AHB1, RCC_GPIOE);
		GPIO_voidSetPinDirection(GPIOE, FSR_PIN, GPIO_ANALOG);
		SET_GPIO_SPEED(GPIOE, FSR_PIN, GPIO_SPEED);
    GPIO_SET_PU_PD (GPIOE, FSR_PIN, GPIO_NO_PU_PD); 
	}
	else if (FSR_PORT == 'F')
	{
		RCC_voidEnableClock (RCC_AHB1, RCC_GPIOF);
		GPIO_voidSetPinDirection(GPIOF, FSR_PIN, GPIO_ANALOG);
		SET_GPIO_SPEED(GPIOF, FSR_PIN, GPIO_SPEED);
    GPIO_SET_PU_PD (GPIOF, FSR_PIN, GPIO_NO_PU_PD); 
	}
	else if (FSR_PORT == 'G')
	{
		RCC_voidEnableClock (RCC_AHB1, RCC_GPIOG);
		GPIO_voidSetPinDirection(GPIOG, FSR_PIN, GPIO_ANALOG);
		SET_GPIO_SPEED(GPIOG, FSR_PIN, GPIO_SPEED);
    GPIO_SET_PU_PD (GPIOG, FSR_PIN, GPIO_NO_PU_PD); 
	}
	else if (FSR_PORT == 'H')
	{
		RCC_voidEnableClock (RCC_AHB1, RCC_GPIOH);
		GPIO_voidSetPinDirection(GPIOH, FSR_PIN, GPIO_ANALOG);
		SET_GPIO_SPEED(GPIOH, FSR_PIN, GPIO_SPEED);
    GPIO_SET_PU_PD (GPIOH, FSR_PIN, GPIO_NO_PU_PD); 
	}
	RCC_voidEnableClock (RCC_APB2, RCC_ADC1);
	MADC_voidInit();
}

double fsrIndex_double_Load  (void)
{
	uint32 fsrReading = MADC_u16AnalogSingleRead (ADC_PA);
	
	uint32 fsrResistance, voltage;
	double load;
	voltage = (fsrReading*5000)/4095;
	fsrResistance = (5000-voltage);
  fsrResistance *= 10000/voltage;
	load = (INDEX_P1*Power(fsrResistance,4)) + (INDEX_P2*Power(fsrResistance,3)) + (INDEX_P3*Power(fsrResistance,2)) + (INDEX_P4*fsrResistance) + (INDEX_P5);
	return load;
}

/************************ Middle Equation ***********************/

/*
double fsrMiddle_double_Load  (uint32 fsrReading)
{
	uint32 fsrResistance, voltage;
	double load;
	voltage = (fsrReading*5000)/1023;
	fsrResistance = (5000-voltage);
  fsrResistance *= 10000/voltage;
	load = (Middle_P1*Power(fsrResistance,4)) + (Middle_P2*Power(fsrResistance,3)) + (Middle_P3*Power(fsrResistance,2)) + (Middle_P4*fsrResistance) + (Middle_P5);
	return load;
}
*/
/************************ Ring Equation ***********************/

/*
double fsrRing_double_Load  (uint32 fsrReading)
{
	uint32 fsrResistance, voltage;
	double load;
	voltage = (fsrReading*5000)/1023;
	fsrResistance = (5000-voltage);
  fsrResistance *= 10000/voltage;
	load = (Ring_P1*Power(fsrResistance,4)) + (Ring_P2*Power(fsrResistance,3)) + (Ring_P3*Power(fsrResistance,2)) + (Ring_P4*fsrResistance) + (Ring_P5);
	return load;
}
*/
/************************ Pinky Equation ***********************/

/*
double fsrPinky_double_Load  (uint32 fsrReading)
{
	uint32 fsrResistance, voltage;
	double load;
	voltage = (fsrReading*5000)/1023;
	fsrResistance = (5000-voltage);
  fsrResistance *= 10000/voltage;
	load = (Pinky_P1*Power(fsrResistance,4)) + (Pinky_P2*Power(fsrResistance,3)) + (Pinky_P3*Power(fsrResistance,2)) + (Pinky_P4*fsrResistance) + (Pinky_P5);
	return load;
}
*/
/************************ Thumb Equation ***********************/

/*
double fsrThumb_double_Load  (uint32 fsrReading)
{
	uint32 fsrResistance, voltage;
	double load;
	voltage = (fsrReading*5000)/1023;
	fsrResistance = (5000-voltage);
  fsrResistance *= 10000/voltage;
	load = (Thumb_P1*Power(fsrResistance,4)) + (Thumb_P2*Power(fsrResistance,3)) + (Thumb_P3*Power(fsrResistance,2)) + (Thumb_P4*fsrResistance) + (Thumb_P5);
	return load;
}
*/
uint32 Power (uint32 x, uint32 y)
{
	uint32 z=x;
	for (uint32 i=1; i<y; i++)
	{
		z=z*x;
	}
	return z;
}
