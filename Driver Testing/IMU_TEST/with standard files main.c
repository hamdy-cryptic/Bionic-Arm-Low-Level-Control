#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
//#include "NVIC_interface.h"
//#include "EXTI_interface.h"
//#include "SYSCFG_interface.h"
#include "DMA_interface.h"
#include "MI2C_interface.h"
#include "HIMU_interface.h"
#include <stdio.h>

//#include "HIMU_program2KALMAN.c"

MPU6050_t MPU6050;


	volatile u32 rollF;
volatile double pitchF;
volatile double yawF;
 volatile double temperatureF;
int main(void)
{
  
	RCC_voidInitSysClock ();
  RCC_voidEnableClock ( RCC_APB2 , 4 ); // enable peripheral clock
	GPIO_voidSetPinDirection(GPIOC , 13 , GPIO_OUTPUT );
	HIMU_VoidPreInit ();
  HIMU_VoidInit ();
	
// MI2C_voidReInit();
	
while (1)
  {
    //HIMU_VoidInit ();
   	MPU6050_Read_All( &MPU6050);
	  rollF = MPU6050.KalmanAngleX;
    pitchF = MPU6050.KalmanAngleY;
    yawF = MPU6050.KalmanAngleZ;
	  temperatureF = MPU6050.Temperature;
	 /* if(pitchF>10){
    GPIO_voidSetPinValue(GPIOC , 13 , GPIO_HIGH);
		MSTK_voidSetBusyWait(10);
	//	MSTK_void_SysTick_Delay (3000);  
		GPIO_voidSetPinValue(GPIOC , 13 , GPIO_LOW);
    MSTK_voidSetBusyWait(10);
		//		MSTK_void_SysTick_Delay (3000);  
		}*/
	}
  
}