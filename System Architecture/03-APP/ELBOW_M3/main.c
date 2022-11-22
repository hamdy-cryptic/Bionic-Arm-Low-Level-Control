/**********************************************/
/* Author    : Hamdy Osama Mohamed            */
/* File      : Main Program of the PALM MCU   */
/* Date      : 9/7/2021                       */
/* Version   :   V01                          */
/**********************************************/

/************** Including Custom Made Libraries ***************/
#include "RCC_interface.h"
#include "STK_interface.h"
//#include "DMA_interface.h"

#include "DC_motor.h"
#include "ENCODER_interface.h"
#include "Servo_interface.h"
#include "PID_interface.h"
#include "USART_interface.h"

#include "APP_Elbow_Functions.h"


/********** Definitions of Needed Variables *******************/

//Define DC Motor Encoder
#define ENCODER_PINS      ENC_PINS_4               //ch1: PA0   ch2: PA1


//Initialize Encoder Instance
encoder_t Elbow_Encoder;

//Define DC Motor Driver Pins
#define ELBOW_MOTOR     M1

//Define Thumb and Wrist Servo Motors
#define THUMB_MOTOR           SERVO_PB7
#define INDEX_MOTOR	  	      SERVO_PB8
#define MIDDLE_MOTOR          SERVO_PB9
#define RING_MOTOR            SERVO_PB0
#define PINKY_MOTOR           SERVO_PA6
#define ELBOW_TURN_MOTOR      SERVO_PA7

//Define the Motor States Array (holds the position of 14 motors of the bionic arm
u8 volatile Motor_States[14] = {0};

#define THUMB_SERVO1    Motor_States[0]
#define THUMB_SERVO2    Motor_States[1]
#define WRIST_SERVO1    Motor_States[2]
#define WRIST_SERVO2    Motor_States[3]
#define INDEX_SERVO     Motor_States[4]
#define MIDDLE_SERVO    Motor_States[5]
#define RING_SERVO      Motor_States[6]
#define PINKY_SERVO     Motor_States[7]
#define ELBOW_SERVO     Motor_States[8]
#define ELBOW_DC        Motor_States[9]
#define INDEX_DC        Motor_States[10]
#define MIDDLE_DC       Motor_States[11]
#define RING_DC         Motor_States[12]
#define PINKY_DC        Motor_States[13]


//Define the transmitted array to palm board(Desired Position of 7 motors)
u8 volatile Transmit_Array [8] = {0};

#define START_TRANS   Transmit_Array [0]
#define WRIST1_POS    Transmit_Array [1]
#define WRIST2_POS    Transmit_Array [2]
#define THUMB_POS     Transmit_Array [3]
#define INDEX_POS     Transmit_Array [4]
#define MIDDLE_POS    Transmit_Array [5]
#define RING_POS      Transmit_Array [6]
#define PINKY_POS     Transmit_Array [7]

//Define the recieved array of Desired Bionic Arm Pose (14 emg + 6 complementary)
u8 volatile Recieved_Array_EMG = 0;
u8 volatile Recieved_Array_Comp = 0;

#define REST                    0
#define CLOSE                   1
#define POINTING                2
#define VICTORY                 3
#define WAVE_OUT                4
#define WAVE_IN                 5
#define OKAY                    6
#define THUMBS_UP               7
#define WRIST_UP                8 
#define WRIST_DOWN              9
#define EXTENSION              10
#define TWIRSTED_EXTENSION     11
#define FLEXION                12
#define TWISTED_FLEXION        13

//Define the recieved array containing Palm Sensor Readings
u8 volatile Recieved_Array_Palm [10] = {0};

#define START_REC Recieved_Array_Palm [0]
#define FSR1      Recieved_Array_Palm [1]
#define FSR2      Recieved_Array_Palm [2]
#define FSR3      Recieved_Array_Palm [3]
#define FSR4      Recieved_Array_Palm [4]
#define FSR5      Recieved_Array_Palm [5]
#define TEMP      Recieved_Array_Palm [6]
#define IMU_X     Recieved_Array_Palm [7]
#define IMU_Y     Recieved_Array_Palm [8]
#define IMU_Z     Recieved_Array_Palm [9]



/**************** Main Function *****************/
int main(){
	/************* Initialize System Peripherals and Clock*************/
	Elbow_Initialize();
	USART3_DMA_RECEIVE(&Recieved_Array_EMG,1);
	USART1_DMA_RECEIVE(&Recieved_Array_Comp,1);
	USART2_DMA_RECEIVE(&Recieved_Array_Palm,10); 
	
	START_TRANS = 254;                       //Set the starting byte of transmission to ensure syncronyzation
	USART2_DMA_Transmit(&Transmit_Array, 8); //Set the USART to transmit selected array
	
	
	while(1){
		
		Elbow_Map_Motion(Recieved_Array_EMG);         // Map motor States based on EMG sent data
		
		// Write Servo Data 
		Servo_VoidWrite(RING_MOTOR,RING_SERVO);
		Servo_VoidWrite(MIDDLE_MOTOR,MIDDLE_SERVO);
		Servo_VoidWrite(INDEX_MOTOR,INDEX_SERVO);
		Servo_VoidWrite(THUMB_MOTOR,THUMB_SERVO1);
		Servo_VoidWrite(PINKY_MOTOR,PINKY_SERVO);
		Servo_VoidWrite(ELBOW_TURN_MOTOR,ELBOW_SERVO);		
		
	}
}


void Elbow_Initialize(){
	//Initialize System Clock of 72	MHz and SYSTICK Timer (us)
	RCC_voidInitSysClock();  
  MSTK_void_SysTick_Initialize();	
	
	//Initalize DC Motors
	DC_VNH5019_init(ELBOW_MOTOR);
	
	//Initialize Servo Motors
	Servo_VoidInit(THUMB_MOTOR);
	Servo_VoidInit(INDEX_MOTOR);
	Servo_VoidInit(MIDDLE_MOTOR);
	Servo_VoidInit(RING_MOTOR );
	Servo_VoidInit(PINKY_MOTOR);
	Servo_VoidInit(ELBOW_TURN_MOTOR);
	
	//Initialize Encoder
	ENCODER_Define(&Elbow_Encoder, ENCODER_PINS);
	
	//Initialize UART (Check configuration for more details)
	USART_Init();
	USART1_DMA_Receiver_Init();
  USART2_DMA_Receiver_Init();
  USART3_DMA_Receiver_Init();
	
	USART2_DMA_Transmit_Init();
}


void Elbow_Map_Motion(u8 pose){
	pose-=48;
	switch (pose){
		case REST: THUMB_SERVO1 = 0;
			         THUMB_SERVO2 = 0;
		           WRIST_SERVO1 = 90;
		           WRIST_SERVO2 = 88;
		           INDEX_SERVO  = 0;
		           MIDDLE_SERVO = 0;
		           RING_SERVO   = 0;
		           PINKY_SERVO  = 0;
		           ELBOW_SERVO  = 0;
		           ELBOW_DC     = 0;  
		           INDEX_DC     = 0;
		           MIDDLE_DC    = 0;
		           RING_DC      = 0;
		           PINKY_DC     = 0;
		break;
		
		case CLOSE: THUMB_SERVO1 = 100;
			          THUMB_SERVO2 = 0;
		            WRIST_SERVO1 = 90;
		            WRIST_SERVO2 = 88;
		            INDEX_SERVO  = 180;
		            MIDDLE_SERVO = 180;
		            RING_SERVO   = 180;
		            PINKY_SERVO  = 110;
		            ELBOW_SERVO  = 0;
		            ELBOW_DC     = 0;  
		            INDEX_DC     = 90;
		            MIDDLE_DC    = 90;
		            RING_DC      = 90;
		            PINKY_DC     = 90;
		break;
		
		case POINTING: THUMB_SERVO1 = 100;
			          THUMB_SERVO2 = 0;
		            WRIST_SERVO1 = 90;
		            WRIST_SERVO2 = 88;
		            INDEX_SERVO  = 0;
		            MIDDLE_SERVO = 180;
		            RING_SERVO   = 180;
		            PINKY_SERVO  = 110;
		            ELBOW_SERVO  = 0;
		            ELBOW_DC     = 0;  
		            INDEX_DC     = 0;
		            MIDDLE_DC    = 90;
		            RING_DC      = 90;
		            PINKY_DC     = 90;
		break;
		
		case VICTORY: THUMB_SERVO1 = 100;
			          THUMB_SERVO2 = 0;
		            WRIST_SERVO1 = 90;
		            WRIST_SERVO2 = 88;
		            INDEX_SERVO  = 0;
		            MIDDLE_SERVO = 0;
		            RING_SERVO   = 180;
		            PINKY_SERVO  = 110;
		            ELBOW_SERVO  = 0;
		            ELBOW_DC     = 0;  
		            INDEX_DC     = 0;
		            MIDDLE_DC    = 0;
		            RING_DC      = 90;
		            PINKY_DC     = 90;
		break;
		
		case WAVE_OUT: THUMB_SERVO1 = 0;
			          THUMB_SERVO2 = 0;
		            WRIST_SERVO1 = 50;
		            WRIST_SERVO2 = 88;
		            INDEX_SERVO  = 0;
		            MIDDLE_SERVO = 0;
		            RING_SERVO   = 0;
		            PINKY_SERVO  = 0;
		            ELBOW_SERVO  = 0;
		            ELBOW_DC     = 0;  
		            INDEX_DC     = 0;
		            MIDDLE_DC    = 0;
		            RING_DC      = 0;
		            PINKY_DC     = 0;
		break;
		
		case WAVE_IN: THUMB_SERVO1 = 0;
			          THUMB_SERVO2 = 0;
		            WRIST_SERVO1 = 130;
		            WRIST_SERVO2 = 88;
		            INDEX_SERVO  = 0;
		            MIDDLE_SERVO = 0;
		            RING_SERVO   = 0;
		            PINKY_SERVO  = 0;
		            ELBOW_SERVO  = 0;
		            ELBOW_DC     = 0;  
		            INDEX_DC     = 0;
		            MIDDLE_DC    = 0;
		            RING_DC      = 0;
		            PINKY_DC     = 0;
		break;
		
		case OKAY: THUMB_SERVO1 = 100;
			          THUMB_SERVO2 = 0;
		            WRIST_SERVO1 = 90;
		            WRIST_SERVO2 = 88;
		            INDEX_SERVO  = 180;
		            MIDDLE_SERVO = 0;
		            RING_SERVO   = 0;
		            PINKY_SERVO  = 0;
		            ELBOW_SERVO  = 0;
		            ELBOW_DC     = 0;  
		            INDEX_DC     = 90;
		            MIDDLE_DC    = 0;
		            RING_DC      = 0;
		            PINKY_DC     = 0;
		break;
		
		case THUMBS_UP: THUMB_SERVO1 = 0;
			          THUMB_SERVO2 = 0;
		            WRIST_SERVO1 = 90;
		            WRIST_SERVO2 = 88;
		            INDEX_SERVO  = 180;
		            MIDDLE_SERVO = 180;
		            RING_SERVO   = 180;
		            PINKY_SERVO  = 110;
		            ELBOW_SERVO  = 0;
		            ELBOW_DC     = 0;  
		            INDEX_DC     = 90;
		            MIDDLE_DC    = 90;
		            RING_DC      = 90;
		            PINKY_DC     = 90;
		break;
		
		case WRIST_UP: THUMB_SERVO1 = 0;
			          THUMB_SERVO2 = 0;
		            WRIST_SERVO1 = 90;
		            WRIST_SERVO2 = 97;
		            INDEX_SERVO  = 0;
		            MIDDLE_SERVO = 0;
		            RING_SERVO   = 0;
		            PINKY_SERVO  = 0;
		            ELBOW_SERVO  = 0;
		            ELBOW_DC     = 0;  
		            INDEX_DC     = 0;
		            MIDDLE_DC    = 0;
		            RING_DC      = 0;
		            PINKY_DC     = 0;
		break;
		
		case WRIST_DOWN: THUMB_SERVO1 = 0;
			          THUMB_SERVO2 = 0;
		            WRIST_SERVO1 = 90;
		            WRIST_SERVO2 = 80;
		            INDEX_SERVO  = 0;
		            MIDDLE_SERVO = 0;
		            RING_SERVO   = 0;
		            PINKY_SERVO  = 0;
		            ELBOW_SERVO  = 0;
		            ELBOW_DC     = 0;  
		            INDEX_DC     = 0;
		            MIDDLE_DC    = 0;
		            RING_DC      = 0;
		            PINKY_DC     = 0;
		break;
		
		case EXTENSION: THUMB_SERVO1 = 0;
			          THUMB_SERVO2 = 0;
		            WRIST_SERVO1 = 90;
		            WRIST_SERVO2 = 88;
		            INDEX_SERVO  = 0;
		            MIDDLE_SERVO = 0;
		            RING_SERVO   = 0;
		            PINKY_SERVO  = 0;
		            ELBOW_SERVO  = 0;
		            ELBOW_DC     = 90;  
		            INDEX_DC     = 0;
		            MIDDLE_DC    = 0;
		            RING_DC      = 0;
		            PINKY_DC     = 0;
		break;
		
		case TWIRSTED_EXTENSION: THUMB_SERVO1 = 0;
			          THUMB_SERVO2 = 0;
		            WRIST_SERVO1 = 90;
		            WRIST_SERVO2 = 88;
		            INDEX_SERVO  = 0;
		            MIDDLE_SERVO = 0;
		            RING_SERVO   = 0;
		            PINKY_SERVO  = 0;
		            ELBOW_SERVO  = 180;
		            ELBOW_DC     = 90;  
		            INDEX_DC     = 0;
		            MIDDLE_DC    = 0;
		            RING_DC      = 0;
		            PINKY_DC     = 0;
		break;
		
		case FLEXION: THUMB_SERVO1 = 0;
			          THUMB_SERVO2 = 0;
		            WRIST_SERVO1 = 90;
		            WRIST_SERVO2 = 88;
		            INDEX_SERVO  = 0;
		            MIDDLE_SERVO = 0;
		            RING_SERVO   = 0;
		            PINKY_SERVO  = 0;
		            ELBOW_SERVO  = 0;
		            ELBOW_DC     = 0;  
		            INDEX_DC     = 0;
		            MIDDLE_DC    = 0;
		            RING_DC      = 0;
		            PINKY_DC     = 0;
		break;
		
		case TWISTED_FLEXION: THUMB_SERVO1 = 0;
			          THUMB_SERVO2 = 0;
		            WRIST_SERVO1 = 90;
		            WRIST_SERVO2 = 88;
		            INDEX_SERVO  = 0;
		            MIDDLE_SERVO = 0;
		            RING_SERVO   = 0;
		            PINKY_SERVO  = 0;
		            ELBOW_SERVO  = 180;
		            ELBOW_DC     = 0;  
		            INDEX_DC     = 0;
		            MIDDLE_DC    = 0;
		            RING_DC      = 0;
		            PINKY_DC     = 0;
		break;
	}
	
	WRIST1_POS = WRIST_SERVO1;
  WRIST2_POS = WRIST_SERVO2;
	THUMB_POS  = THUMB_SERVO2;
	INDEX_POS  = INDEX_DC;
  MIDDLE_POS = MIDDLE_DC;
  RING_POS   = RING_DC;
  PINKY_POS  = PINKY_DC;
	
}