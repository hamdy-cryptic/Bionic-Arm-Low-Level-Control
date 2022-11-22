//#include <STD_TYPES.h>
//#include <BIT_MATH.h>
//
//#include <RCC_interface.h>
//#include <GPIO_interface.h>
//#include <PWM_interface.h>
//#include <ADC_interface.h>
//#include <USART_interface.h>
//#include <STK_interface.h>
//
//int main(){
//	RCC_voidInitSysClock ();      							//Initialize system clock
//	RCC_voidEnableClock (RCC_AHB1, RCC_GPIOA);  //Initialize GPIOA Clock
//	RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);    //Initialize GPIOB Clock
//	RCC_voidEnableClock (RCC_AHB1, RCC_GPIOC);  //Initialize GPIOA Clock
//	//RCC_voidEnableClock (RCC_APB1, RCC_USART2);  //Initialize USART2 Clock
//	//RCC_voidEnableClock (RCC_APB2, RCC_TIM1);  //Initialize TIM1 Clock
//	//RCC_voidEnableClock (RCC_APB2, RCC_ADC1);  //Initialize ADC1 Clock
//	
//	//GPIO_voidSetPinDirection(GPIOA , PIN2 , GPIO_AF ); //Set pin 2 as AFIO
//	//SET_GPIO_SPEED(GPIOA , PIN2 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	//GPIO_Set_AF(GPIOA,PIN2,7);											 	 //Set Alternative Function to USART
//	
//	//GPIO_voidSetPinDirection(GPIOA , PIN3 , GPIO_AF ); //Set pin 3 as AFIO
//	//SET_GPIO_SPEED(GPIOA , PIN3 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	//GPIO_Set_AF(GPIOA,PIN3,7);												 //Set Alternative Function to USART
//	
//	GPIO_voidSetPinDirection(GPIOA , PIN0 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOA , PIN0 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOA , PIN0 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOA , PIN1 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOA , PIN1 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOA , PIN1 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOA , PIN2 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOA , PIN2 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOA , PIN2 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOA , PIN3 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOA , PIN3 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOA , PIN3 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOA , PIN4 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOA , PIN4 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOA , PIN4 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOA , PIN5 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOA , PIN5 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOA , PIN5 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOA , PIN6 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOA , PIN6 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOA , PIN6 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOA , PIN7 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOA , PIN7 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOA , PIN7 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOA , PIN8 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOA , PIN8 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOA , PIN8 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOA , PIN9 , GPIO_OUTPUT ); //Set pin 9 as AFIO
//	SET_GPIO_SPEED(GPIOA , PIN9 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOA , PIN9 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOA , PIN10 , GPIO_OUTPUT ); //Set pin 10 as AFIO
//	SET_GPIO_SPEED(GPIOA , PIN10 ,GPIO_SPEED_MEDIUM );  		 //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOA , PIN10 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	//GPIO_SET_PU_PD (GPIOA , PIN0 ,GPIO_NO_PU_PD);      		 //Close Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOA , PIN11 , GPIO_OUTPUT ); //Set pin 10 as AFIO
//	SET_GPIO_SPEED(GPIOA , PIN11 ,GPIO_SPEED_MEDIUM );  		 //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOA , PIN11 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOA , PIN12 , GPIO_OUTPUT ); //Set pin 10 as AFIO
//	SET_GPIO_SPEED(GPIOA , PIN12 ,GPIO_SPEED_MEDIUM );  		 //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOA , PIN12 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOA , PIN15 , GPIO_OUTPUT ); //Set pin 10 as AFIO
//	SET_GPIO_SPEED(GPIOA , PIN15 ,GPIO_SPEED_MEDIUM );  		 //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOA , PIN15 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	
//	GPIO_voidSetPinDirection(GPIOB , PIN0 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOB , PIN0 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOB , PIN0 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOB , PIN1 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOB , PIN1 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOB , PIN1 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOB , PIN2 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOB , PIN2 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOB , PIN2 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOB , PIN3 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOB , PIN3 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOB , PIN3 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOB , PIN4 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOB , PIN4 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOB , PIN4 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOB , PIN5 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOB , PIN5 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOB , PIN5 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOB , PIN6 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOB , PIN6 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOB , PIN6 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOB , PIN7 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOB , PIN7 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOB , PIN7 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOB , PIN8 , GPIO_OUTPUT ); //Set pin 8 as AFIO
//	SET_GPIO_SPEED(GPIOB , PIN8 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOB , PIN8 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOB , PIN9 , GPIO_OUTPUT ); //Set pin 9 as AFIO
//	SET_GPIO_SPEED(GPIOB , PIN9 ,GPIO_SPEED_MEDIUM );  //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOB , PIN9 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOB , PIN10 , GPIO_OUTPUT ); //Set pin 10 as AFIO
//	SET_GPIO_SPEED(GPIOB , PIN10 ,GPIO_SPEED_MEDIUM );  		 //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOB , PIN10 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	//GPIO_SET_PU_PD (GPIOA , PIN0 ,GPIO_NO_PU_PD);      		 //Close Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOB , PIN12 , GPIO_OUTPUT ); //Set pin 10 as AFIO
//	SET_GPIO_SPEED(GPIOB , PIN12 ,GPIO_SPEED_MEDIUM );  		 //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOB , PIN12 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOB , PIN13 , GPIO_OUTPUT ); //Set pin 10 as AFIO
//	SET_GPIO_SPEED(GPIOB , PIN13 ,GPIO_SPEED_MEDIUM );  		 //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOB , PIN13 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOB , PIN14 , GPIO_OUTPUT ); //Set pin 10 as AFIO
//	SET_GPIO_SPEED(GPIOB , PIN14 ,GPIO_SPEED_MEDIUM );  		 //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOB , PIN14 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOB , PIN15 , GPIO_OUTPUT ); //Set pin 10 as AFIO
//	SET_GPIO_SPEED(GPIOB , PIN15 ,GPIO_SPEED_MEDIUM );  		 //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOB , PIN15 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOC , PIN13 , GPIO_OUTPUT ); //Set pin 10 as AFIO
//	SET_GPIO_SPEED(GPIOC , PIN13 ,GPIO_SPEED_MEDIUM );  		 //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOC , PIN13 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOC , PIN14 , GPIO_OUTPUT ); //Set pin 10 as AFIO
//	SET_GPIO_SPEED(GPIOC , PIN14 ,GPIO_SPEED_MEDIUM );  		 //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOC , PIN14 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinDirection(GPIOC , PIN15 , GPIO_OUTPUT ); //Set pin 10 as AFIO
//	SET_GPIO_SPEED(GPIOC , PIN15 ,GPIO_SPEED_MEDIUM );  		 //Set pin speed as 25MHz
//	GPIO_SET_PP_OD (GPIOC , PIN15 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	
//	
//	//
//	//MADC_voidInit();		 //Initialize ADC1
//	//USART_Init();					 //Initialize USART(2)
//	//PWM_Init(TIMER1);   //Set TIM1 in PWM Mode
//	
//	
//	//PWM_Pin (PWM_PA8);  //Set Pin 8 as TIM1 AFIO
//	//PWM_Pin (PWM_PA9);  //Set Pin 8 as TIM1 AFIO
//	//volatile u16 pwm=0;
//	while(1){
//		//USART_SENDSTRING((u8*)"Hello\n");
//		//MSTK_void_SysTick_Delay(1000);
//		  //pwm = MADC_u16AnalogSingleRead(ADC_PA0);
//			//PWM_PinWrite(PWM_PA8, pwm, 4096);
//		  //PWM_PinWrite(PWM_PA9, 0, 4096);
//		//if(USART_Receive()=='d'){
//		//GPIO_voidSetPinValue(GPIOC,PIN13,GPIO_LOW);
//		//}
//		//else{
//		//	GPIO_voidSetPinValue(GPIOC,PIN13,GPIO_HIGH);
//	
//
//		GPIO_voidSetPinValue(GPIOA,PIN0,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOA,PIN1,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOA,PIN2,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOA,PIN3,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOA,PIN4,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOA,PIN5,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOA,PIN6,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOA,PIN7,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOA,PIN8,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOA,PIN9,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOA,PIN10,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOA,PIN11,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOA,PIN12,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOA,PIN15,GPIO_HIGH);
//		
//		GPIO_voidSetPinValue(GPIOB,PIN0,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOB,PIN1,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOB,PIN2,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOB,PIN3,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOB,PIN4,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOB,PIN5,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOB,PIN6,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOB,PIN7,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOB,PIN8,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOB,PIN9,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOB,PIN10,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOB,PIN12,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOB,PIN13,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOB,PIN14,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOB,PIN15,GPIO_HIGH);
//		
//		GPIO_voidSetPinValue(GPIOC,PIN13,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOC,PIN14,GPIO_HIGH);
//		GPIO_voidSetPinValue(GPIOC,PIN15,GPIO_HIGH);
//	}
//	}
//


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"



int main(){
RCC_voidInitSysClock();
RCC_voidEnableClock(RCC_AHB1,RCC_GPIOC);
MSTK_void_SysTick_Initialize();
	
GPIO_voidSetPinDirection(GPIOC , PIN13 , GPIO_OUTPUT ); //Set pin 10 as AFIO
SET_GPIO_SPEED(GPIOC , PIN13 ,GPIO_SPEED_HIGH);//Set pin speed as 25MHz
GPIO_SET_PP_OD (GPIOC , PIN13 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
	
	GPIO_voidSetPinValue(GPIOC,13,GPIO_HIGH);
	
	while(1){
		GPIO_voidSetPinValue(GPIOC,13,GPIO_LOW);
		MSTK_void_SysTick_Delay(50);
		GPIO_voidSetPinValue(GPIOC,13,GPIO_HIGH);
		MSTK_void_SysTick_Delay(50);
	}
}

