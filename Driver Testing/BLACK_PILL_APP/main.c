#include "RCC_interface.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "Servo_interface.h"
#include "DC_motor.h"

int main(){
	RCC_voidInitSysClock ();   //intialize system clock
	MSTK_void_SysTick_Initialize();
	
	RCC_voidEnableClock(RCC_AHB1, RCC_GPIOC);
	
	GPIO_voidSetPinDirection(GPIOC, 13, GPIO_OUTPUT);
	SET_GPIO_SPEED(GPIOC, 13, GPIO_SPEED_HIGH);
	GPIO_SET_PP_OD(GPIOC, 13, GPIO_OUTPUT_PP);
	
	GPIO_voidSetPinValue(GPIOC,13,GPIO_HIGH);
  
	Servo_VoidInit(SERVO_PB0);
	
	DC_L9110_MOTOR_init(DC_PA9 , DC_PA10);
	
	while(1){
		GPIO_voidSetPinValue(GPIOC,13,GPIO_HIGH);
		Servo_VoidWrite(SERVO_PB0,180);
		MSTK_void_SysTick_Delay(1000);
		GPIO_voidSetPinValue(GPIOC,13,GPIO_LOW);
		Servo_VoidWrite(SERVO_PB0,0);
		MSTK_void_SysTick_Delay(1000);
		//DC_L9110_MOTOR_SPEED_DIR(DC_PA9,DC_PA10,Direction_CW,0,1000);
}
}
