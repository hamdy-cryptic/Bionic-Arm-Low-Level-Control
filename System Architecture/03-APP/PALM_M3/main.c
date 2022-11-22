/**********************************************/
/* Author    : Hamdy Osama Mohamed            */
/* File      : Main Program of the PALM MCU   */
/* Date      : 9/7/2021                       */
/* Version   :   V01                          */
/**********************************************/

/************** Including Custom Made Libraries ***************/
#include "RCC_interface.h"
#include "STK_interface.h"
#include "AFIO_interface.h"

#include "DC_motor.h"
#include "POT_interface.h"
#include "Servo_interface.h"
#include "PID_interface.h"
#include "FSR_Interface.h"
#include "HIMU_interface.h"
#include "F_MLX90614.h"
#include "F_SMBUS.h"
#include "USART_interface.h"

#include "APP_Palm_Functions.h"


/********** Definitions of Needed Variables *******************/

//Define Finger Motors
#define INDEX_MOTOR      DC_PA9, DC_PA8
#define MIDDLE_MOTOR     DC_PA11, DC_PA10
#define RING_MOTOR       DC_PB1, DC_PB0
#define PINKY_MOTOR      DC_PB5, DC_PB4//DC_PA6, DC_PA7

//Define Knuckle Potentiometers
#define INDEX_POT        POT_PA4
#define MIDDLE_POT       POT_PA1
#define RING_POT         POT_PA0
#define PINKY_POT        POT_PA7

//Define Thumb and Wrist Servo Motors
#define THUMB_MOTOR      SERVO_PB3
#define WRIST1_MOTOR		 SERVO_PB8
#define WRIST2_MOTOR     SERVO_PB9

//Define PID Parameters
#define INDEX_KP    10
#define INDEX_KI    0.1
#define INDEX_KD    0.1

#define MIDDLE_KP    10
#define MIDDLE_KI    0.1
#define MIDDLE_KD    0.1

#define RING_KP    10
#define RING_KI    0.1
#define RING_KD    0.1

#define PINKY_KP    10
#define PINKY_KI    0.1
#define PINKY_KD    0.1

//Define Knuckle range of motion
#define INDEX_MIN     38
#define INDEX_MAX     106

#define MIDDLE_MIN     16
#define MIDDLE_MAX     93

#define RING_MIN     144
#define RING_MAX     175

#define PINKY_MIN     14
#define PINKY_MAX     85

//Define Temp Sensor Pins
#define TEMP_PORT   GPIOB
#define TEMP_SDA    11
#define TEMP_SCL    10

//Initialize MUX DATA
#define MUX_PORT     GPIOB
#define MUX_PIN1     13
#define MUX_PIN2     14
#define MUX_PIN3     15

//Initialize PID Instances
PID_t Index_PID;
PID_t Middle_PID;
PID_t Ring_PID;
PID_t Pinky_PID;

//Initialize Structure of stored IMU Readings
MPU6050_t MPU6050;

//Define the transmitted array (FSR Values, temp sensor, and IMU Readings
u8 volatile Transmit_Array [10] = {0};

#define START_TRANS   Transmit_Array [0]
#define FSR1          Transmit_Array [1]
#define FSR2          Transmit_Array [2]
#define FSR3          Transmit_Array [3]
#define FSR4          Transmit_Array [4]
#define FSR5          Transmit_Array [5]
#define TEMP          Transmit_Array [6]
#define IMU_X         Transmit_Array [7]
#define IMU_Y         Transmit_Array [8]
#define IMU_Z         Transmit_Array [9]

//Define the recieved array of Desired Motor Positions (4 DC, 3 Servos)
u8 volatile Recieved_Array [8] = {0};

#define START_REC     Recieved_Array [0]
#define WRIST1_POS    Recieved_Array [1]
#define WRIST2_POS    Recieved_Array [2]
#define THUMB_POS     Recieved_Array [3]
#define INDEX_POS     Recieved_Array [4]
#define MIDDLE_POS    Recieved_Array [5]
#define RING_POS      Recieved_Array [6]
#define PINKY_POS     Recieved_Array [7]

/**************** Main Function *****************/
int main(){
	/************* Initialize System Peripherals and Clock*************/
	Palm_Initialize();
	USART2_DMA_RECEIVE(&Recieved_Array, 8);  //Set UART DMA Reciever to selected recieve array
	START_TRANS = 254;                       //Set the start byte to ensure syncronization
	USART2_DMA_Transmit(&Transmit_Array, 9); //Set the USART to transmit selected array
	
	while(1){
		
		Palm_MUX_RESET(MUX_PORT, MUX_PIN1, MUX_PIN2, MUX_PIN3);     // Reset MUX Pins
		FSR1 = fsrIndex_double_Load();                              // Read Index FSR
		FSR2 = fsrRing_double_Load();                               // Read Ring FSR
		FSR3 = fsrThumb_double_Load();                              // Read Thumb FSR
		Palm_MUX_SET(MUX_PORT, MUX_PIN1, MUX_PIN2, MUX_PIN3);       // Set MUX Pins
		FSR4 = fsrMiddle_double_Load();                             // Read Middle FSR
		FSR5 = fsrPinky_double_Load();                              // Read Pinky FSR
	
	  TEMP = MLX90614_READ( MLX90614_RAM |OBJECT_TEMP) ;          // Read Object Temperature
	  // Read IMU Orientation XYZ and store them 
//		MPU6050_Read_All( &MPU6050);
//		IMU_X = MPU6050.KalmanAngleX;
//		IMU_Y = MPU6050.KalmanAngleY;
//		IMU_Z = MPU6050.KalmanAngleZ;
	
	//PID Control here
		Palm_MUX_SET(MUX_PORT, MUX_PIN1, MUX_PIN2, MUX_PIN3);       // Set MUX Pins
		 Palm_Move_Index(Sync_Recieved_Data(INDEX_INFO));
		 Palm_Move_Middle(Sync_Recieved_Data(MIDDLE_INFO));
		 Palm_Move_Ring(Sync_Recieved_Data(RING_INFO));
		 Palm_Move_Pinky(Sync_Recieved_Data(PINKY_INFO));

		 Servo_VoidWrite(THUMB_MOTOR, Sync_Recieved_Data(THUMB_INFO));
		 Servo_VoidWrite(WRIST1_MOTOR, Sync_Recieved_Data(WRIST1_INFO));
		 Servo_VoidWrite(WRIST2_MOTOR, Sync_Recieved_Data(WRIST2_INFO));
		 
		 
	}
}


void Palm_Initialize(){
	//Initialize System Clock of 72	MHz and SYSTICK Timer (us)
	RCC_voidInitSysClock();  
  MSTK_void_SysTick_Initialize();	
	
	//Remap Palm Pins as set by the PCB Fabrication Layout
	Palm_Pin_Remap();
	
	//Initalize DC Motors
	DC_L9110_MOTOR_init(INDEX_MOTOR);
	DC_L9110_MOTOR_init(MIDDLE_MOTOR);
	DC_L9110_MOTOR_init(RING_MOTOR);
	DC_L9110_MOTOR_init(PINKY_MOTOR);
	
	//Initialize Potentiometers
	Pot_VoidInit(GPIOA,INDEX_POT);
	Pot_VoidInit(GPIOA,MIDDLE_POT);
	Pot_VoidInit(GPIOA,RING_POT);
	Pot_VoidInit(GPIOA,PINKY_POT);
	
	//Initialize Servo Motors
	Servo_VoidInit(THUMB_MOTOR);
	Servo_VoidInit(WRIST1_MOTOR);
	Servo_VoidInit(WRIST2_MOTOR);
	
	//Initialize MUX Pins to control Analog MUX 4053
	Palm_MUX_Init(MUX_PORT,MUX_PIN1,MUX_PIN2,MUX_PIN3);
	
	//Initialize PID Controllers
	PID_Init(&Index_PID,INDEX_KP, INDEX_KI, INDEX_KD, INDEX_MIN, INDEX_MAX, INDEX_POT);
	PID_Init(&Middle_PID,MIDDLE_KP, MIDDLE_KI, MIDDLE_KD, MIDDLE_MIN, MIDDLE_MAX, MIDDLE_POT);
	PID_Init(&Ring_PID,RING_KP, RING_KI, RING_KD, RING_MIN, RING_MAX, RING_POT);
	PID_Init(&Pinky_PID,PINKY_KP, PINKY_KI, PINKY_KD, PINKY_MIN, PINKY_MAX, PINKY_POT);
	
	//Initialize fsr Module (Check FSR CONFIG for more data)
	fsrInitialize();
	
	//Initialize Temperature Sensor (Check SMBUS.h for more data)
	MLX90614_Init (TEMP_PORT, TEMP_SCL,TEMP_SDA);
	
	//Initialize UART (Check configuration for more details)
	USART_Init();
	USART2_DMA_Receiver_Init();
	USART2_DMA_Transmit_Init();
	
	//Initialize IMU Sensor (Check config file for pins
//	HIMU_VoidPreInit ();
//	HIMU_VoidInit ();
}

void Palm_Pin_Remap(){
	//Enable AFIO Clock
	RCC_voidEnableClock(RCC_APB2,RCC_AFIO);
	//Set Timer3 into Partial Remap Mode  (10)
	AFIO_TIM3_MAP(2);
	//Set Timer2 into Partial Remap Mode (01)
  AFIO_TIM2_MAP(1);
}


void Palm_MUX_Init(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2, u8 Copy_u8Pin3){
	//Initialize GPIO Clock
	switch (Copy_u8Port){
		case GPIOA: RCC_voidEnableClock(RCC_APB2, RCC_GPIOA); break;
		case GPIOB: RCC_voidEnableClock(RCC_APB2, RCC_GPIOB); break;
		case GPIOC: RCC_voidEnableClock(RCC_APB2, RCC_GPIOC); break;
		default : break;
	}
	
	//Initialize Pins (OUTPUT, PUSH-PULL, AND HIGH SPEED)
	GPIO_voidSetPinDirection(Copy_u8Port,Copy_u8Pin2, GPIO_OUTPUT);
	GPIO_SET_PP_OD(Copy_u8Port, Copy_u8Pin2, GPIO_OUTPUT_PP);
	SET_GPIO_SPEED(Copy_u8Port, Copy_u8Pin2, GPIO_SPEED_HIGH);
	
	GPIO_voidSetPinDirection(Copy_u8Port,Copy_u8Pin1, GPIO_OUTPUT);
	GPIO_SET_PP_OD(Copy_u8Port, Copy_u8Pin1, GPIO_OUTPUT_PP);
	SET_GPIO_SPEED(Copy_u8Port, Copy_u8Pin1, GPIO_SPEED_HIGH);
	
	GPIO_voidSetPinDirection(Copy_u8Port,Copy_u8Pin3, GPIO_OUTPUT);
	GPIO_SET_PP_OD(Copy_u8Port, Copy_u8Pin3, GPIO_OUTPUT_PP);
	SET_GPIO_SPEED(Copy_u8Port, Copy_u8Pin3, GPIO_SPEED_HIGH);
	
	//Set all pins to zero
	Palm_MUX_RESET( Copy_u8Port, Copy_u8Pin1, Copy_u8Pin2, Copy_u8Pin3);
}

 void Palm_MUX_RESET(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2, u8 Copy_u8Pin3){
	 //Set all pins to zero	
	 GPIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin2, GPIO_LOW);
	 GPIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin3, GPIO_LOW);
	 GPIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin1, GPIO_LOW);
	 //Wait 2 micro seconds to make sure effect took place on MUX IC
	 MSTK_void_SysTick_Delay(2);
 }
 
  void Palm_MUX_SET(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2, u8 Copy_u8Pin3){
	 	//Set all pins to ONE
		GPIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin2, GPIO_HIGH);
	  GPIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin3, GPIO_HIGH);
	  GPIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin1, GPIO_HIGH);
    	 //Wait 2 micro seconds to make sure effect took place on MUX IC
		MSTK_void_SysTick_Delay(2); 
	}

	
	void Palm_Move_Index(u8 desired_pos){
		if (desired_pos > INDEX_MAX){
			desired_pos = INDEX_MAX;
		}
		else if (desired_pos < INDEX_MIN){
			desired_pos = INDEX_MIN;
		}
		volatile s32 motor_control = PID_s32ControlOutput(&Index_PID, desired_pos);
		if (motor_control > 256 ){
			motor_control = 255;
			DC_L9110_MOTOR_SPEED_DIR(INDEX_MOTOR, Direction_CW, motor_control, 255);
		}
		else if (motor_control < 0){
			motor_control = motor_control*(-1);
			if (motor_control > 256 ){
				motor_control = 255;
				DC_L9110_MOTOR_SPEED_DIR(INDEX_MOTOR, Direction_CCW, motor_control, 255);
		}
			DC_L9110_MOTOR_SPEED_DIR(INDEX_MOTOR, Direction_CCW, motor_control, 255);
		}
		DC_L9110_MOTOR_SPEED_DIR(INDEX_MOTOR, Direction_CW, motor_control, 255);
	}
	
	
	
  void Palm_Move_Middle(u8 desired_pos){
		if (desired_pos > MIDDLE_MAX){
			desired_pos = MIDDLE_MAX;
		}
		else if (desired_pos < MIDDLE_MIN){
			desired_pos = MIDDLE_MIN;
		}
		volatile s32 motor_control = PID_s32ControlOutput(&Middle_PID, desired_pos);
		if (motor_control > 256 ){
			motor_control = 255;
			DC_L9110_MOTOR_SPEED_DIR(MIDDLE_MOTOR, Direction_CW, motor_control, 255);
		}
		else if (motor_control < 0){
			motor_control = motor_control*(-1);
			if (motor_control > 256 ){
				motor_control = 255;
				DC_L9110_MOTOR_SPEED_DIR(MIDDLE_MOTOR, Direction_CCW, motor_control, 255);
		}
			DC_L9110_MOTOR_SPEED_DIR(MIDDLE_MOTOR, Direction_CCW, motor_control, 255);
		}
		DC_L9110_MOTOR_SPEED_DIR(MIDDLE_MOTOR, Direction_CW, motor_control, 255);
	}
	
	
	
  void Palm_Move_Ring(u8 desired_pos){
		if (desired_pos > RING_MAX){
			desired_pos = RING_MAX;
		}
		else if (desired_pos < RING_MIN){
			desired_pos = RING_MIN;
		}
		volatile s32 motor_control = PID_s32ControlOutput(&Ring_PID, desired_pos);
		if (motor_control > 256 ){
			motor_control = 255;
			DC_L9110_MOTOR_SPEED_DIR(RING_MOTOR, Direction_CW, motor_control, 255);
		}
		else if (motor_control < 0){
			motor_control = motor_control*(-1);
			if (motor_control > 256 ){
				motor_control = 255;
				DC_L9110_MOTOR_SPEED_DIR(RING_MOTOR, Direction_CCW, motor_control, 255);
		}
			DC_L9110_MOTOR_SPEED_DIR(RING_MOTOR, Direction_CCW, motor_control, 255);
		}
		DC_L9110_MOTOR_SPEED_DIR(RING_MOTOR, Direction_CW, motor_control, 255);
	}
	
	
	
  void Palm_Move_Pinky(u8 desired_pos){
		if (desired_pos > PINKY_MAX){
			desired_pos = PINKY_MAX;
		}
		else if (desired_pos < PINKY_MIN){
			desired_pos = PINKY_MIN;
		}
		volatile s32 motor_control = PID_s32ControlOutput(&Pinky_PID, desired_pos);
		if (motor_control > 256 ){
			motor_control = 255;
			DC_L9110_MOTOR_SPEED_DIR(PINKY_MOTOR, Direction_CW, motor_control, 255);
		}
		else if (motor_control < 0){
			motor_control = motor_control*(-1);
			if (motor_control > 256 ){
				motor_control = 255;
				DC_L9110_MOTOR_SPEED_DIR(PINKY_MOTOR, Direction_CCW, motor_control, 255);
		}
			DC_L9110_MOTOR_SPEED_DIR(PINKY_MOTOR, Direction_CCW, motor_control, 255);
		}
		DC_L9110_MOTOR_SPEED_DIR(PINKY_MOTOR, Direction_CW, motor_control, 255);
	}
	
	
	u8 Sync_Recieved_Data(u8 POS_Info){
		u8 volatile index = 0;
		for(u8 i=0;i<8;i++){
			if (Recieved_Array[i]==254){
				index = i;
			}
		}
		switch (POS_Info){
			case WRIST1_INFO: {
				if ((index+1)<8)
				  return Recieved_Array[index+1];
       	else
						return Recieved_Array[index-7];
				break;
			}
			case WRIST2_INFO: {
				if ((index+2)<8)
				  return Recieved_Array[index+2];
       	else
						return Recieved_Array[index-6];
				break;
			}
			case THUMB_INFO: {
				if ((index+3)<8)
				  return Recieved_Array[index+3];
       	else
						return Recieved_Array[index-5];
				break;
			}
			case INDEX_INFO: {
				if ((index+4)<8)
				  return Recieved_Array[index+4];
       	else
						return Recieved_Array[index-4];
				break;
			}
			case MIDDLE_INFO: {
				if ((index+5)<8)
				  return Recieved_Array[index+5];
       	else
						return Recieved_Array[index-3];
				break;
			}
			case RING_INFO: {
				if ((index+6)<8)
				  return Recieved_Array[index+6];
       	else
						return Recieved_Array[index-2];
				break;
			}
			case PINKY_INFO: {
				if ((index+7)<8)
				  return Recieved_Array[index+7];
       	else
						return Recieved_Array[index-1];
				break;
			}
		}
		
		
	}
