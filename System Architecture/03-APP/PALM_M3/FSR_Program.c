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

#include <math.h>

/************************ Index Equation ***********************/

void fsrInitialize (void)
{
		RCC_voidEnableClock (RCC_APB2, RCC_GPIOA);
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
	voltage = (fsrReading*3300)/4095;
	fsrResistance = (3300-voltage);
  fsrResistance *= 10000/voltage;
	load = INDEX_a*(pow(fsrResistance,INDEX_b));
	return load;
}

/************************ Middle Equation ***********************/

double fsrMiddle_double_Load  (void)
{
	uint32 fsrReading = MADC_u16AnalogSingleRead (FSR_PIN0);
	
	uint32 fsrResistance, voltage;
	double load;
	voltage = (fsrReading*3300)/4095;
	fsrResistance = (3300-voltage);
  fsrResistance *= 10000/voltage;
	load = Middle_a*(pow(fsrResistance,Middle_b));
	return load;
}

/************************ Ring Equation ***********************/

double fsrRing_double_Load  (void)
{
  uint32 fsrReading = MADC_u16AnalogSingleRead (FSR_PIN1);
	
	uint32 fsrResistance, voltage;
	double load;
	voltage = (fsrReading*3300)/4095;
	fsrResistance = (3300-voltage);
  fsrResistance *= 10000/voltage;
	load = Ring_a*(pow(fsrResistance,Ring_b));
	return load;
}

/************************ Pinky Equation ***********************/

double fsrPinky_double_Load  (void)
{
  uint32 fsrReading = MADC_u16AnalogSingleRead (FSR_PIN1);
	
	uint32 fsrResistance, voltage;
	double load;
	voltage = (fsrReading*3300)/4095;
	fsrResistance = (3300-voltage);
  fsrResistance *= 10000/voltage;
	load = Pinky_a*(pow(fsrResistance,Pinky_b));
	return load;
}

/************************ Thumb Equation ***********************/

double fsrThumb_double_Load  (void)
{
  uint32 fsrReading = MADC_u16AnalogSingleRead (FSR_PIN2);
	
	uint32 fsrResistance, voltage;
	double load;
	voltage = (fsrReading*3300)/4095;
	fsrResistance = (3300-voltage);
  fsrResistance *= 10000/voltage;
	load = Thumb_a*(pow(fsrResistance,Thumb_b));
	return load;
}

