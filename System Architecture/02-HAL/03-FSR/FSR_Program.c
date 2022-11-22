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
		RCC_voidEnableClock (RCC_AHB1, RCC_GPIOA);
		GPIO_voidSetPinDirection(GPIOA, FSR_PIN0, GPIO_ANALOG);
		SET_GPIO_SPEED(GPIOA, FSR_PIN0, GPIO_SPEED);
    GPIO_SET_PU_PD (GPIOA, FSR_PIN0, GPIO_NO_PU_PD);
    GPIO_voidSetPinDirection(GPIOA, FSR_PIN1, GPIO_ANALOG);
		SET_GPIO_SPEED(GPIOA, FSR_PIN1, GPIO_SPEED);
    GPIO_SET_PU_PD (GPIOA, FSR_PIN1, GPIO_NO_PU_PD);
    GPIO_voidSetPinDirection(GPIOA, FSR_PIN2, GPIO_ANALOG);
		SET_GPIO_SPEED(GPIOA, FSR_PIN2, GPIO_SPEED);
    GPIO_SET_PU_PD (GPIOA, FSR_PIN2, GPIO_NO_PU_PD);   		
		
	RCC_voidEnableClock (RCC_APB2, RCC_ADC1);
	MADC_voidInit();
}

/************************ Index Equation ***********************/

double fsrIndex_double_Load  (void)
{
	uint32 fsrReading = MADC_u16AnalogSingleRead (FSR_PIN0);
	
	uint32 fsrResistance, voltage;
	double load;
	voltage = (fsrReading*5000)/4095;
	fsrResistance = (3300-voltage);
  fsrResistance *= 10000/voltage;
	load = INDEX_a*(Power(fsrResistance,INDEX_b))
	return load;
}

/************************ Middle Equation ***********************/

double fsrMiddle_double_Load  (void)
{
	uint32 fsrReading = MADC_u16AnalogSingleRead (FSR_PIN0);
	
	uint32 fsrResistance, voltage;
	double load;
	voltage = (fsrReading*5000)/4095;
	fsrResistance = (3300-voltage);
  fsrResistance *= 10000/voltage;
	load = Middle_a*(Power(fsrResistance,Middle_b))
	return load;
}

/************************ Ring Equation ***********************/

double fsrRing_double_Load  (void)
{
  uint32 fsrReading = MADC_u16AnalogSingleRead (FSR_PIN1);
	
	uint32 fsrResistance, voltage;
	double load;
	voltage = (fsrReading*5000)/4095;
	fsrResistance = (3300-voltage);
  fsrResistance *= 10000/voltage;
	load = Ring_a*(Power(fsrResistance,Ring_b))
	return load;
}

/************************ Pinky Equation ***********************/

double fsrPinky_double_Load  (void)
{
  uint32 fsrReading = MADC_u16AnalogSingleRead (FSR_PIN1);
	
	uint32 fsrResistance, voltage;
	double load;
	voltage = (fsrReading*5000)/4095;
	fsrResistance = (3300-voltage);
  fsrResistance *= 10000/voltage;
	load = Pinky_a*(Power(fsrResistance,Pinky_b))
	return load;
}

/************************ Thumb Equation ***********************/

double fsrRing_double_Load  (void)
{
  uint32 fsrReading = MADC_u16AnalogSingleRead (FSR_PIN2);
	
	uint32 fsrResistance, voltage;
	double load;
	voltage = (fsrReading*5000)/4095;
	fsrResistance = (3300-voltage);
  fsrResistance *= 10000/voltage;
	load = Thumb_a*(Power(fsrResistance,Thumb_b))
	return load;
}

uint32 Power (uint32 x, uint32 y)
{
	uint32 z=x;
	for (uint32 i=1; i<y; i++)
	{
		z=z*x;
	}
	return z;
}
