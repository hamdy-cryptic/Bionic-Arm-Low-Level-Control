/*************************************************************
   File:        interface data of PWM Driver                 *
   Author:      Hamdy Osama Mohamed                          *
   Version:     V03                                          *
   Date:        22/2/2021                                    *
   Updates:     Added General Purpose Timers as PWM          *
				Added Encoder Feature for supported Timers   *
*************************************************************/


   #ifndef PWM_PRIVATE_H
   #define PWM_PRIVATE_H
   
   
   /*Register Definitions*/
   
   #define TIM1_BASE_ADDRESS    0x40012C00
   #define TIM8_BASE_ADDRESS    0x40013400
							    
   #define TIM2_BASE_ADDRESS    0x40000000
   #define TIM3_BASE_ADDRESS    0x40000400
   #define TIM4_BASE_ADDRESS    0x40000800
   #define TIM5_BASE_ADDRESS    0x40000C00
	 
   #define TIM6_BASE_ADDRESS    0x40001000
   #define TIM7_BASE_ADDRESS    0x40001400
   
   #define TIM9_BASE_ADDRESS    0x40014C00
   #define TIM10_BASE_ADDRESS   0x40015000
   #define TIM11_BASE_ADDRESS   0x40015400
   #define TIM12_BASE_ADDRESS   0x40001800
   #define TIM13_BASE_ADDRESS   0x40001C00
   #define TIM14_BASE_ADDRESS   0x40002000
   
   typedef volatile struct{
		volatile u32 CR1;
		volatile u32 CR2;
		volatile u32 SMCR;
		volatile u32 DIER;
		volatile u32 SR;
		volatile u32 EGR;
		volatile u32 CCMR1;
		volatile u32 CCMR2;
		volatile u32 CCER;
		volatile u32 CNT;
		volatile u32 PSC;
		volatile u32 ARR;
		volatile u32 RCR;
		volatile u32 CCR1;
		volatile u32 CCR2;
		volatile u32 CCR3;
		volatile u32 CCR4;
		volatile u32 BDTR;
		volatile u32 DCR;
		volatile u32 DMAR;
   }Adv_Timer;	   
   
   #define TIM1   ((volatile Adv_Timer*)TIM1_BASE_ADDRESS)
   #define TIM8   ((volatile Adv_Timer*)TIM8_BASE_ADDRESS)
  
   #define TIM2   ((volatile Adv_Timer*)TIM2_BASE_ADDRESS)
   #define TIM3   ((volatile Adv_Timer*)TIM3_BASE_ADDRESS)
   #define TIM4   ((volatile Adv_Timer*)TIM4_BASE_ADDRESS)
   #define TIM5   ((volatile Adv_Timer*)TIM5_BASE_ADDRESS)
		 
	 #define TIM6   ((volatile Adv_Timer*)TIM6_BASE_ADDRESS)
	 #define TIM7   ((volatile Adv_Timer*)TIM7_BASE_ADDRESS)
   
   #define TIM9   ((volatile Adv_Timer*)TIM9_BASE_ADDRESS)
   #define TIM10  ((volatile Adv_Timer*)TIM10_BASE_ADDRESS)
   #define TIM11  ((volatile Adv_Timer*)TIM11_BASE_ADDRESS)
   #define TIM12  ((volatile Adv_Timer*)TIM12_BASE_ADDRESS)
   #define TIM13  ((volatile Adv_Timer*)TIM13_BASE_ADDRESS)   
   #define TIM14  ((volatile Adv_Timer*)TIM14_BASE_ADDRESS)   
		 
	 volatile Adv_Timer* TIM[15]={0,TIM1,TIM2,TIM3,TIM4,TIM5,TIM6,TIM7,TIM8,TIM9,TIM10,TIM11,TIM12,TIM13,TIM14};
	 
   
   
   
   /*Private Macros*/
   
   #define OFF        0
   #define C_MODE1    1
   #define C_MODE2    2
   #define C_MODE3    3
   
   #define PWM_UP     0
   #define PWM_DOWN   1
   
   
   
   
   
   #endif