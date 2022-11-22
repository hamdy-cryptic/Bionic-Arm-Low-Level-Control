/*#include "RCC_interface.h"

#include "DC_motor.h"
#include "STK_interface.h"
#include "PID_interface.h"
#include "POT_interface.h"

int main(){
	RCC_voidInitSysClock();
	MSTK_void_SysTick_Initialize();
	
	Pot_VoidInit(POT_GPIOA, POT_PA7);
	PID_t pinky_pid;
	PID_Init(&pinky_pid,0.51,0.0001,0.01,0,90,POT_PA7);
  u32 volatile x=0;	
	//DC_L9110_MOTOR_init(DC_PA9,DC_PA8);
	//DC_L9110_MOTOR_init(DC_PA11, DC_PA10);
	
	while(1){
		x=Pot_f32GetAngle(POT_PA7);
		PID_s32ControlOutput(&pinky_pid,90);
		//DC_L9110_MOTOR_SPEED_DIR(DC_PA9, DC_PA8, Direction_CCW, 255,255); 
		//MSTK_void_SysTick_Delay(800);
	  //DC_L9110_MOTOR_SPEED_DIR(DC_PA9, DC_PA8, Direction_CCW, 0,255); 		
		//while (1){}
		//MSTK_void_SysTick_Delay(800);
	}
}
	
*/

/*
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SMBUS_interface.h"
#include "STK_interface.h"
#include "MLX90614.h"


int main()
{
RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
RCC_voidEnableClock(RCC_APB1,RCC_I2C1);

SMBUS_init();
f32 volatile T_A=0 ; 
f32 volatile T_OB1=0 ; 
f32 volatile T_OB2=0;
while(1)
{
//  T_A=MLX90614_READ_TEMPERATURE( MLX90614_TA ,MLX90614_Centigrade);
 T_OB1=MLX90614_READ_TEMPERATURE( MLX90614_TO_1 ,MLX90614_Centigrade);
 // T_OB2=MLX90614_READ_TEMPERATURE( MLX90614_TO_2 ,MLX90614_Centigrade);
}
return 0;
}
*/


#include "RCC_interface.h"
#include "STK_interface.h"
#include "Servo_interface.h"
#include "FSR_Interface.h"
#include "GPIO_interface.h"
#include "POT_interface.h"
#include "USART_interface.h"
#include "DC_motor.h"
#include "ENCODER_interface.h"


int main(){
	RCC_voidInitSysClock();
	MSTK_void_SysTick_Initialize();
	//Servo_VoidInit(SERVO_PB9);
	//Servo_VoidInit(SERVO_PB8);
	DC_L9110_MOTOR_init(DC_PB8, DC_PB9);
	encoder_t elbow_encoder;
	
	ENCODER_Define(&elbow_encoder, ENC_PINS_4);
	volatile int position = 0;
	volatile float speed = 0;
	volatile signed int rotations = 0;
	volatile int direction = 0;
	
	GPIO_voidSetPinDirection(GPIOB,7,GPIO_OUTPUT);
	SET_GPIO_SPEED(GPIOB,7,GPIO_SPEED_LOW);
	GPIO_SET_PP_OD(GPIOB,7,GPIO_OUTPUT_PP);
	
	GPIO_voidSetPinDirection(GPIOB,6,GPIO_OUTPUT);
	SET_GPIO_SPEED(GPIOB,6,GPIO_SPEED_LOW);
	GPIO_SET_PP_OD(GPIOB,6,GPIO_OUTPUT_PP);
	
	GPIO_voidSetPinDirection(GPIOB,5,GPIO_OUTPUT);
	SET_GPIO_SPEED(GPIOB,5,GPIO_SPEED_LOW);
	GPIO_SET_PP_OD(GPIOB,5,GPIO_OUTPUT_PP);
	
	GPIO_voidSetPinValue(GPIOB,7,GPIO_HIGH);
	GPIO_voidSetPinValue(GPIOB,6,GPIO_LOW);
	GPIO_voidSetPinValue(GPIOB,5,GPIO_LOW);
	
	
	
	//USART_Init();
	//USART2_DMA_Receiver_Init();
	//u8 volatile recieve_test[10]={0};
	
	//USART2_DMA_RECEIVE(&recieve_test);
	while(1){
	PWM_PinWrite(PWM_PB8, 255, 255);
		
	GPIO_voidSetPinValue(GPIOB,5,GPIO_HIGH);
	GPIO_voidSetPinValue(GPIOB,6,GPIO_LOW);
		
	 position = ENCODER_CurrentPosition(&elbow_encoder);
	 speed = ENCODER_CurrentSpeed(&elbow_encoder);
	 rotations = ENCODER_Rotations(&elbow_encoder);
	 direction = ENCODER_CurrentDirection(&elbow_encoder);	
	//MSTK_void_SysTick_Delay(1000);
	//MSTK_void_SysTick_Delay(1000);
		
	//GPIO_voidSetPinValue(GPIOB,5 ,GPIO_LOW);
	//GPIO_voidSetPinValue(GPIOB,6,GPIO_HIGH);
	//MSTK_void_SysTick_Delay(1000);
	//MSTK_void_SysTick_Delay(1000);
	}
	
/*	Pot_VoidInit(POT_GPIOA, POT_PA4);  //INDEX
	Pot_VoidInit(POT_GPIOA, POT_PA1);  //MIDDLE
	Pot_VoidInit(POT_GPIOA, POT_PA0);  //RING
	
	volatile int index_reading=0;
	volatile int middle_reading=0;
	volatile int ring_reading=0;
	
	while(1){
		index_reading = Pot_f32GetAngle(POT_PA4);
		middle_reading = Pot_f32GetAngle(POT_PA1);
		ring_reading = Pot_f32GetAngle(POT_PA0);
	}
	*/
	
	
	/*GPIO_voidSetPinDirection(GPIOA, 9, GPIO_OUTPUT);
	GPIO_SET_PP_OD(GPIOA, 9, GPIO_OUTPUT_PP);
	
	GPIO_voidSetPinValue(GPIOA, 9, GPIO_HIGH);*/
	
	//fsrInitialize();
	//volatile int x=0;
	//while(1){
		//x= fsrMiddle_double_Load();
		
	//}

	
	
	
	
}