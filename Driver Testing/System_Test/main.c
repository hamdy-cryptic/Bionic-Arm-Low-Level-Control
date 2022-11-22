//
///* Includes */
//#include "NVIC_interface.h"
//#include <RCC_interface.h>
//#include <GPIO_interface.h>
////#include "SysTick.h"
////#include "gpio.h"
////#include "exti.h"
////#include "memcpy.h"
//#include "MDMA_interface.h"
//#include <ADC_interface.h>
//#include <ADC_private.h>
//
//
//#define BUFFER_SIZE     ((u16) 500)
// static u32 srcBuffer[BUFFER_SIZE];
// static u32 dstBuffer[BUFFER_SIZE];
// static u32 analog_value=0;
//  
//int main(void)
//{
//	RCC_voidEnableClock(RCC_APB2,RCC_ADC1);
//	RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
//	
//	GPIO_voidSetPinDirection(GPIOA , 0 , GPIO_ANALOG );
//	SET_GPIO_SPEED(GPIOA , 0 , GPIO_SPEED_LOW );
//	GPIO_SET_PU_PD (GPIOA , 0 ,GPIO_NO_PU_PD);
//	
//	MADC_voidInit();
//	MADC_u16AnalogSingleRead(0);
//	
//  /* Initialize source buffer */
//  for (int idx = 0; idx < BUFFER_SIZE; idx++)
//  {
//    srcBuffer[idx] = idx * idx;
//  }
//DMA_SetConfig(2 ,0 , PERIPHERAL_TO_MEMORY , WORD, WORD ,DISACTIVATED , DISACTIVATED);
//DMA_VoidSelectChannel(0 , 0 );
////  ReturnStatus_Type returnResults = RETURN_STATUS_NOT_OK;
////MDMA_voidChannelInit();
////DMA_StartTransfer(srcBuffer , dstBuffer , BUFFER_SIZE);
///*in case of memory to memory source address is in peripheral address register  */
//while(1){
//	MADC_u16AnalogSingleRead(0);
//DMA_VoidSetAddress( 0, ADC1_DR , &analog_value , 1 );
//DMA_VoidDMAEnable(0);
//}
//}
//


//#include "STD_TYPES.h"
//#include "BIT_MATH.h"
//#include "RCC_interface.h"
//#include "GPIO_interface.h"
//#include "USART_interface.h"
//#include <STK_interface.h>
//#include "MI2C_interface.h"
//#include "MI2C_private.h"
//#include "MDMA_interface.h"
//#include "STRING_COMPARE.h"
//
//
//volatile static u8 x=0;
//
//int main (void)
//{
//	
//	 RCC_voidInitSysClock ();
//	 RCC_voidEnableClock (RCC_AHB1, RCC_GPIOA);
//	 RCC_voidEnableClock (RCC_APB2, RCC_USART1);
//	 //RCC_voidEnableClock (RCC_APB1, RCC_USART2);
//	 GPIO_voidSetPinDirection( GPIOA , 9 , GPIO_AF );
//	 SET_GPIO_SPEED( GPIOA , 9 ,GPIO_SPEED_LOW ); 
//	 GPIO_SET_PP_OD (GPIOA , 9, GPIO_OUTPUT_PP);
//	 GPIO_Set_AF(GPIOA , 9 , 7 );
//	
//	GPIO_voidSetPinDirection( GPIOA , 10 , GPIO_AF );
//	 SET_GPIO_SPEED( GPIOA , 10 ,GPIO_SPEED_LOW ); 
//	 GPIO_SET_PP_OD (GPIOA , 10 , GPIO_OUTPUT_PP);
//	 GPIO_Set_AF(GPIOA , 10 , 7 );
//	 
//	
//	GPIO_voidSetPinDirection( GPIOA , 5 , GPIO_OUTPUT );
//	 SET_GPIO_SPEED( GPIOA , 5 ,GPIO_SPEED_LOW ); 
//	 GPIO_SET_PP_OD (GPIOA , 5, GPIO_OUTPUT_PP);
//	
//	 USART_Init();
//	 USART_SENDSTRING((u8*)"READY\n");
//	//GPIO_voidSetPinValue(GPIOA,5,GPIO_HIGH);
//	while(1)
//	{
//		USART_SENDSTRING((u8*)"6.5\n");
//		MSTK_void_SysTick_Delay(1000);
//    //x=USART_Receive();		
//		//if(x =='H')
//		//	GPIO_voidSetPinValue(GPIOA,5,GPIO_HIGH);
//		//else if (x =='L')
//		//	GPIO_voidSetPinValue(GPIOA,5,GPIO_LOW);
//		
//	}
//	
//}
//

//#include "STD_TYPES.h"
//#include "BIT_MATH.h"
//#include "RCC_interface.h"
//#include "GPIO_interface.h"
//#include "USART_interface.h"
//#include <STK_interface.h>
//#include "MI2C_interface.h"
//#include "MI2C_private.h"
//#include "MDMA_interface.h"
//
//
///*******I2C TEST***********/
//
//
//
//
//void CRITICAL_GPIO_Config(void)
//{
//	/*Enable System Clock*/
//RCC_voidInitSysClock();
//  /* Enable port A and C clocks */
//RCC_voidEnableClock ( RCC_AHB1 , RCC_GPIOA);
//RCC_voidEnableClock ( RCC_AHB1 , RCC_GPIOC);
// 
// 
// /* Select Alternate function mode */
// /************** GPIO_PIN : SELECT PIN ********************/
//GPIO_voidSetPinDirection(GPIOA ,  8 , GPIO_AF );
//GPIO_voidSetPinDirection(GPIOC ,  9 , GPIO_AF );
//
//
//
//  /* Select output type open drain */
//GPIO_SET_PP_OD (GPIOA , 8 , GPIO_OUTPUT_OD );
//GPIO_SET_PP_OD (GPIOC, 9, GPIO_OUTPUT_OD); 
//
//
//  /* Select output speed very high */
//SET_GPIO_SPEED( GPIOA , 8 ,GPIO_SPEED_HIGH );
//SET_GPIO_SPEED( GPIOC , 9 ,GPIO_SPEED_HIGH );
//
//
//  /* Select pull-up */
//GPIO_SET_PU_PD (GPIOA , 8, GPIO_PU);
//GPIO_SET_PU_PD (GPIOC , 9, GPIO_PU);
//
//
//  /* Select AF4 (I2C) */
//GPIO_Set_AF(GPIOA , 8 , 4 );
//GPIO_Set_AF(GPIOC , 9 , 4 );
//}
//
//volatile u32 RECIEVER[20] ; 
////u32 TRANSMITTER[20] ;
///* define the sensor address & reg address */
//
//#define      SENSOR_ADDRESS     0b1101000  
//#define          WHO_AM_I_REG           0x75  
//#define          WHO_AM_I_REG_VAL           0b1101000
//
// 
//
//int main ()
//{
//CRITICAL_GPIO_Config();	
//
///* preparing i2c */
//MI2C_voidInit( I2C3 );
//MI2C_voidEnableDmaRequest(I2C3);
//MI2C_voidDmaLastTransfer(I2C3);
//
////DMA_1 , STREAM_2 (I2C3_RX)
//DMA_SetConfig( 1 , STREAM_2 , PERIPHERAL_TO_MEMORY , BYTE , BYTE , ACTIVATED , DEACTIVATED);
////MDMA_voidChannelInit();
//// CHANNEL_3
//DMA_VoidSelectChannel( STREAM_2 , CHANNEL3 );
//
////DMA_VoidSetAddress( STREAM_2 , &(I2C_3->DR) , &RECIEVER[0] , 1 );
//DMA_VoidInerruptEnable( STREAM_2 , TCIE );
//
///* I2C MASTER RECIEVER */
//
///* WRITE THE SENSOR ADDRESS IN DR */ 
//MI2C_voidMasterTransmitter_7bit(I2C3 , SENSOR_ADDRESS);
//
///* SPECIFY THE REGISTER ADDRESS TO READ */
//MI2C_voidSendRegisterAddress(I2C3 , ONE_BYTE  , WHO_AM_I_REG);
//
///* READ THE WHO_AM_I_REG VALUE */
//MI2C_voidMasterRead_7bit(I2C3 , SENSOR_ADDRESS );
//
//
///* ENABLE DMA TO START RECIEVING */
//DMA_VoidSetAddress( STREAM_2 , &(I2C_3->DR) , &RECIEVER[0] , 1 );
//DMA_VoidDMAEnable( STREAM_2 );
////DMA_StartTransfer(&(I2C_3->DR),&RECIEVER[0],1);
///*HERE THE INTERFACE IS READY TO TRANSFER DATA SO CLEAR THE FLAG */
////RECIEVER[0]=I2C_3->DR;
//MI2C_voidGetReady(I2C3 );
//MI2C_voidI2c_3_MasterRecieverFinishing();
//
//while( WHO_AM_I_REG_VAL != RECIEVER[0]){} //Do nothing if the value read is not as the expected 
//  
//  
//  
///*stop i2c when the dma transfe complete flag is on */
////MDMA_VidSetCallBack_I2C3_RX( MI2C_voidI2c_3_MasterRecieverFinishing());
//
//
//MSTK_void_SysTick_Delay(1000);
////delay (1000);// let it recieve the data 
//while(1){
//	
//}
//}
//

/*Elbow Motor Drivers Testing*/

//#include "STD_TYPES.h"
//#include "BIT_MATH.h"
//
//#include "RCC_interface.h"
//#include "GPIO_interface.h"
//#include "PWM_interface.h"
//#include "ADC_interface.h"
//
//
//
//int main(){
//	RCC_voidInitSysClock();                     //Initialize system clock from RCC Config file
//	
//	RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);    //Enable clock for PortA
//	RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);    //Enable clock for PortB
//	RCC_voidEnableClock(RCC_AHB1,RCC_GPIOC);    //Enable clock for PortC
//	
//	RCC_voidEnableClock(RCC_APB2,RCC_ADC1);     //Enable ADC1 Module Clock
//	MADC_voidInit();                            //Initialize ADC1 Module from ADC Config file
//	
//	RCC_voidEnableClock(RCC_APB2,RCC_TIM8);     //Enable TIM8 Module Clock
//	PWM_Init(TIMER8);                           //Initialize Timer 8 from PWM Config file
//	RCC_voidEnableClock(RCC_APB1,RCC_TIM4);     //Enable TIM4 Module Clock
//	PWM_Init(TIMER4);                           //Initialize Timer 4 from PWM Config file
//	
//	//Initializing M1_IN_A
//	GPIO_voidSetPinDirection(GPIOA , PIN10 , GPIO_OUTPUT);
//  SET_GPIO_SPEED(GPIOA , PIN10 , GPIO_SPEED_MEDIUM);    
//	GPIO_SET_PP_OD (GPIOA , PIN10 , GPIO_OUTPUT_PP);  
//	
//	//Initializing M1_IN_B
//	GPIO_voidSetPinDirection(GPIOB , PIN5 , GPIO_OUTPUT);
//  SET_GPIO_SPEED(GPIOB , PIN5 , GPIO_SPEED_MEDIUM);    
//	GPIO_SET_PP_OD (GPIOB , PIN5 , GPIO_OUTPUT_PP); 
//
//	//Initializing M2_IN_A
//	GPIO_voidSetPinDirection(GPIOA , PIN8 , GPIO_OUTPUT);
//  SET_GPIO_SPEED(GPIOA , PIN8 , GPIO_SPEED_MEDIUM);    
//	GPIO_SET_PP_OD (GPIOA , PIN8 , GPIO_OUTPUT_PP);  
//	
//	//Initializing M2_IN_B
//	GPIO_voidSetPinDirection(GPIOA , PIN9 , GPIO_OUTPUT);
//  SET_GPIO_SPEED(GPIOA , PIN9 , GPIO_SPEED_MEDIUM);    
//	GPIO_SET_PP_OD (GPIOA , PIN9 , GPIO_OUTPUT_PP);
//	
//	//Initializing M1_PWM
//	GPIO_voidSetPinDirection(GPIOC , PIN7 , GPIO_AF);
//  SET_GPIO_SPEED(GPIOC , PIN7 , GPIO_SPEED_MEDIUM);    
//	GPIO_SET_PP_OD (GPIOC , PIN7 , GPIO_OUTPUT_PP);
//	PWM_Pin(PWM_PC7);
//	
//	//Initializing M2_PWM
//	GPIO_voidSetPinDirection(GPIOB , PIN6 , GPIO_AF);
//  SET_GPIO_SPEED(GPIOB , PIN6 , GPIO_SPEED_MEDIUM);    
//	GPIO_SET_PP_OD (GPIOB , PIN6 , GPIO_OUTPUT_PP);
//	PWM_Pin(PWM_PB6);
//	
//	//Initializing Potentiometer Pin (A5 in arduino)
//	GPIO_voidSetPinDirection(GPIOC , PIN0 , GPIO_ANALOG);
//  SET_GPIO_SPEED(GPIOC , PIN0 , GPIO_SPEED_MEDIUM);    
//	GPIO_SET_PU_PD (GPIOC , PIN0 , GPIO_NO_PU_PD);
//	
//	u16 Pot_value=0;
//	
//	while (1){
//		Pot_value = MADC_u16AnalogSingleRead(ADC_PC0);  //Reading potentiometer
//		if (Pot_value <2048){
//			GPIO_voidSetPinValue(GPIOA , PIN10, GPIO_HIGH);
//			GPIO_voidSetPinValue(GPIOB , PIN5, GPIO_LOW);
//			PWM_PinWrite(PWM_PC7,2*(2047-Pot_value),4096);
//			
//			GPIO_voidSetPinValue(GPIOA , PIN8, GPIO_HIGH);
//			GPIO_voidSetPinValue(GPIOA , PIN9, GPIO_LOW);
//			PWM_PinWrite(PWM_PB6,2*(2047-Pot_value),4096);
//		}
//		else{
//			GPIO_voidSetPinValue(GPIOA , PIN10, GPIO_LOW);
//			GPIO_voidSetPinValue(GPIOB , PIN5, GPIO_HIGH);
//			PWM_PinWrite(PWM_PC7,2*(Pot_value-2048),4096);
//
//			GPIO_voidSetPinValue(GPIOA , PIN8, GPIO_LOW);
//			GPIO_voidSetPinValue(GPIOA , PIN9, GPIO_HIGH);
//			PWM_PinWrite(PWM_PB6,2*(Pot_value-2048),4096);
//		}
//	}
//}
//

////ENCODER Testing
//
//#include "STD_TYPES.h"
//#include "BIT_MATH.h"
//
//#include "RCC_interface.h"
//#include "GPIO_interface.h"
//#include "NVIC_interface.h"
//#include "PWM_interface.h"
//#include "ADC_interface.h"
//
//
//int main(){
//	RCC_voidInitSysClock();
//	
//	//MNVIC_voidEnableInterrupt(TIM1_UPDATE);
//	
//	RCC_voidEnableClock(RCC_APB2,RCC_TIM1);
//	RCC_voidEnableClock(RCC_APB1,RCC_TIM3);
//	RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
//	
//	GPIO_voidSetPinDirection(GPIOA,PIN8,GPIO_AF);
//	SET_GPIO_SPEED(GPIOA,PIN8,GPIO_SPEED_HIGH);
//	GPIO_SET_PU_PD(GPIOA,PIN8,GPIO_NO_PU_PD);
//	PWM_Pin(PWM_PA8);
//	
//	GPIO_voidSetPinDirection(GPIOA,PIN9,GPIO_AF);
//	SET_GPIO_SPEED(GPIOA,PIN9,GPIO_SPEED_HIGH);
//	GPIO_SET_PU_PD(GPIOA,PIN9,GPIO_NO_PU_PD);
//	PWM_Pin(PWM_PA9);
//	
//	GPIO_voidSetPinDirection(GPIOA,PIN5,GPIO_OUTPUT);
//	SET_GPIO_SPEED(GPIOA,PIN5,GPIO_SPEED_HIGH);
//	GPIO_SET_PP_OD(GPIOA,PIN5,GPIO_OUTPUT_PP);
//	
//	ENC_Mode(TIMER1,65535);
//	TRIG_Mode(TIMER3, 4, 0);
//	
//	GPIO_voidSetPinValue(GPIOA,PIN5,GPIO_LOW);
//	volatile u8 Direction = 5;
//	volatile u16 Position = 0;
//	while(1){
//		Direction = ENC_GetDir(TIMER1);
//		Position  = ENC_GetCNT(TIMER1);
//	}
//}
//

//Clock Verification using STK Driver and RCC
//#include "STD_TYPES.h"
//#include "BIT_MATH.h"
//
//#include "RCC_interface.h"
//#include "GPIO_interface.h"
//#include "STK_interface.h"
//
//
//
//int main(){
//RCC_voidInitSysClock();
//RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
//MSTK_void_SysTick_Initialize();
//	
//GPIO_voidSetPinDirection(GPIOA , PIN5 , GPIO_OUTPUT ); //Set pin 10 as AFIO
//SET_GPIO_SPEED(GPIOA , PIN5 ,GPIO_SPEED_HIGH);//Set pin speed as 25MHz
//GPIO_SET_PP_OD (GPIOA , PIN5 , GPIO_OUTPUT_PP);    //Set Pin as Push-Pull mode
//	
//	GPIO_voidSetPinValue(GPIOC,13,GPIO_LOW);
//	
//	while(1){
//		GPIO_voidSetPinValue(GPIOA,5,GPIO_HIGH);
//		MSTK_void_SysTick_Delay(50);
//		GPIO_voidSetPinValue(GPIOA,5,GPIO_LOW);
//		MSTK_void_SysTick_Delay(50);
//	}
//}




//     HAL LAYER TESTING
//Encoder Driver HAL Layer Testing

//#include "RCC_interface.h"
//#include "ENCODER_interface.h"
//
//int main(){
//	RCC_voidInitSysClock();
//	encoder_t volatile myEncoder;
//	ENCODER_Define(&myEncoder, ENC_PINS_1);
//	ENCODER_Init(&myEncoder);
//	s32 volatile rotations=0;
//	s32 volatile direction=0;
//	s32 volatile position=0;
//	s32 volatile speed=0;
//	
//	while(1){
//		//rotations=ENCODER_Rotations(&myEncoder);
//	  //direction=ENCODER_CurrentDirection(&myEncoder);
//    //position=ENCODER_CurrentPosition(&myEncoder);
//    speed=ENCODER_CurrentSpeed(&myEncoder);
//	}
//}


////Temp Sensor Test

//#include "STD_TYPES.h"
//#include "BIT_MATH.h"
//
//#include "RCC_interface.h"
//
//#include "Temp_interface.h"
//
//
//
//int main (void)
//{
//		RCC_voidInitSysClock();
//    TEMP_SENSOR_Init();
//	  f64 volatile temp_reading_ambient = 0;
//	  f64 volatile temp_reading_source1 = 0;
//	  f64 volatile temp_reading_source2 = 0;
//		
//	while(1)
//	{
//		temp_reading_ambient= TEMP_READ( TEMP_SOURCE_AMBIENT, TEMP_Centigrade); 
//    temp_reading_source1= TEMP_READ( TEMP_OBJ_IR_SOURCE_1, TEMP_Centigrade); 
//    temp_reading_source2= TEMP_READ( TEMP_OBJ_IR_SOURCE_2, TEMP_Centigrade);		
//		
//	}
//	
//}


////IMU Testing

#include "RCC_interface.h"
#include "HIMU_interface.h"

int main(){
	RCC_voidInitSysClock();
	HIMU_VoidSetUp();
	volatile u16 my_yaw=0;
	
	while(1){
		HIMU_VoidReading();
		my_yaw=HIMU_U16GetYaw();
	}
}

