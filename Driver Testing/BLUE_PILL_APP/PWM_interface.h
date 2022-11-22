/*************************************************************
   File:        interface data of PWM Driver                 *
   Author:      Hamdy Osama Mohamed                          *
   Version:     V04                                          *
   Date:        22/2/2021                                    *
   Updates:     Added General Purpose Timers as PWM          *
				Added Encoder Feature for supported Timers   *
				Added Trigger Mode Feature                   *
*************************************************************/

   #ifndef PWM_INTERFACE_H
   #define PWM_INTERFACE_H
   /*
			Functions Provided by the Driver 
		1- PWM_Init    -> Used to initialize configuration properties for the given Timer in PWM Mode
		2- PWM_Pin     -> Used to set selected pin as PWM pin (alternative function)
		3- PWM_PinWrite-> Used to set Duty Cycle and Period of PWM Signal (Raw Data for Registers)
        4- PWM_PinStop -> Used to stop the PWM signal from being created on selected pin
		
		5- ENC_Mode   -> Use timer initialization in encoder mode
		6- ENC_GetDir -> Get the direction of the encoder rotation (0/1)
		7- ENC_GetPos -> Get the current position of the encoder
		
		8- PWM_StopTimer -> Disables Timer to reduce power consumption
		9- TRIG_Mode   -> Use timer initialization in Triggered mode
   */
	 #include "STD_TYPES.h"
   
   void PWM_Init(u8 Timer); 								//Used to initialize configuration properties for the given Timer
   void PWM_PinWrite(u8 Pin, u32 DutyCycle, u32 Period);	//Used to set Duty Cycle (Check Range Below) and Period of PWM Signal
   void PWM_PinStop(u8 Pin);								//Used to stop the PWM signal from being created on selected pin
   void PWM_StopTimer(u8 Timer);                            //Disables Timer to reduce power consumption
   void PWM_ResumeTimer(u8 Timer);                          //Used to re-enable timer after being stopped -> can work with all timer configurations not only pwm
   
   void ENC_Mode(u8 Timer, u16 Period);                     //Use timer initialization in encoder mode
   void TRIG_Mode(u8 Timer, u8 TrigType, u8 TrigSrc);       //Use timer in triggered mode (useful in time calculation)
   u8 ENC_GetDir(u8 Timer);                                 //Get the direction of the encoder rotation (0/1)
   u16 ENC_GetCNT(u8 Timer);                                //Get the current position of the encoder
   u16 ENC_GetCCR1(u8 Timer);                               //used to retrieve the compare channel 1 register value.
   void ENC_ClearFlag(u8 Timer);                            //used to clear update set flags in timer register
   
   
   /*Note about Period of PWM Signal:
	 This value is sensitive as it is greatly dependent on the responsiveness of the system being driven, it is greatly advisable to stick 
	 to given value unless you wish to optimize your system and test better values.
   */
   
   //Macros used in the PWM Function Arguments:
   
   /*Values for "Timer"*/
   //Advanced Timers
   #define TIMER1      1
   #define TIMER8      8
   
   #define TIMER2      2
   #define TIMER3      3
   #define TIMER4      4
   #define TIMER5      5
   
   #define TIMER9      9
   #define TIMER10     10
   #define TIMER11     11
   #define TIMER12     12
   #define TIMER13     13
   #define TIMER14     14
   
   /*Pins available for each timer (PWM)*/
   //Timer 1
   #define PWM_PA8    4    //(Timer 1 Channel 1)
   #define PWM_PA9    5    //(Timer 1 Channel 2)
   #define PWM_PA10   10   //(Timer 1 Channel 3)
   #define PWM_PA11   11   //(Timer 1 Channel 4)
   //Timer 8
   #define PWM_PC6    6    //(Timer 8 Channel 1)
   #define PWM_PC7    7    //(Timer 8 Channel 2)
   #define PWM_PC8    8	   //(Timer 8 Channel 3)
   #define PWM_PC9    9    //(Timer 8 Channel 4)
   //Timer 2
   #define PWM_PA15   15   //(Timer 2 Channel 1)
   #define PWM_PB3    33   //(Timer 2 Channel 2)
   #define PWM_PB10   101  //(Timer 2 Channel 3)
   #define PWM_PA3    3    //(Timer 2 Channel 4)
	 //Timer 3
   #define PWM_PA6   255   //(Timer 3 Channel 1)
   #define PWM_PA7   254   //(Timer 3 Channel 2)
   #define PWM_PB0    0    //(Timer 3 Channel 3)
   #define PWM_PB1    1    //(Timer 3 Channel 4)	 
   #define PWM_PB5    55   //(Timer 3 Channel 2) 
	 //Timer 4
   #define PWM_PB6    66   //(Timer 4 Channel 1)
   #define PWM_PB7    77   //(Timer 4 Channel 2)
   #define PWM_PB8    88   //(Timer 4 Channel 3)
   #define PWM_PB9    99   //(Timer 4 Channel 4)
   
   
   /*Duty Cycle Possible Value*/
   // From 0 to 65535   (0 is like GPIO LOW) (65535 is like GPIO HIGH)
   
   /*Period Possible Value*/
   // From 0 to 65535 -> (Timing is relative to bus clock and configured 
   // prescaler. 
   
   /*These values are temporary until driver gets refined in future versions
     to directly get duty cycle percentage and period in milliseconds
   */
	 
	 /*TrigSrc -> a number that defines the source that triggers the timer (Check DataSheet)*/
	 /*TrigType -> a number that defines the trigger type of the slave timer. Check Datasheet for slave options definition*/
	 /*TrigType Options: */
	  #define   PWM_RESET        4
		#define		PWM_GATE         5
		#define		PWM_TRIGGER      6
	
   
   #endif