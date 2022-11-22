/*************************************************************
   File:        user configuration of PWM Driver             *
   Author:      Hamdy Osama Mohamed                          *
   Version:     V03                                          *
   Date:        22/2/2021                                    *
   Updates:     Added General Purpose Timers as PWM          *
				Added Encoder Feature for supported Timers   *
*************************************************************/


   #ifndef PWM_CONFIG_H
   #define PWM_CONFIG_H
   
   /*This Configuration file uses advanced timers as PWM Generators 
     only and does not allow any other function for the timer...\
	 further features can be added later as needed to operate the 
	 timers in future versions.*/
	 
	 /*Features not present in this version include (Priority to add is descending):
	 DMA
	 (Input)Capture/Compare
	 Slave, Master Mode
	 */
	 
	 /*The Initialization Function automatically sets timers to output PWM Mode*/
	 
	 /*Configurablie Options in this Driver Include:
	 1- Clock Division       			: T_bus/T_clock       (1,2,4) 
	 2- Auto Preload         			: Enable/Disable       (1,0)
	 3- Center-aligned Mode  			: Modes of Counting (Check Macros)
	 4- Couting Direction    			: UP or DOWN        (Check Macros)
	 5- One Pulse Mode       			: Enable/Disable       (1,0)
	 6- Interrupt, DMA Enable			: Enable/Disable       (1,0)
	 7- Output Channels used 			:                     (1,2,3,4)
	 8- PWM Mode             			: Mode 1 or Mode 2      (1,2)
	 9- Output Polarity      			: Active High/Low       (1,0)
	 10- PWM Complementary Channels     : Enable/Disable        (1/0)
	 11- PWM Prescaler                  : Set Value < 65536   (0-65535)
	 
	 12- Encoder Mode             : Mode1 or 2 or 3      (1/2/3)
	 13- Encoder Filter           :Check values below
	 14- Encoder Prescaler        :Check values below
	 15- Interrupt (ENC)	      	: Enable/Disable       (1,0)
	 */
	 
	 /*1- Clock Division: Set the ratio of timer clock from bus(dead) clock 
	      OPTIONS: (Filter clock = PWM_CLK * Timer Clock)
		   1     -> Not multiplied   (Default)
		   2     -> Multiplied by 2
		   4     -> Multiplied by 4
	 */
	 
	 #define PWM_CLK      1
	 
	 /*2- Auto Preload: Set new time period and Duty Cycle only when timer restarts counting
	      OPTIONS:
		  1     -> Enabled    (Default)
		  0     -> Disabled
		  NOTE: be careful when disabling this feature as it might cause logical 
		  errors between software and hardware integration
		*/
	 
	 #define PWM_PRELOAD    1
	 
	 /*3- Center-aligned Mode: Make Counter up counting then down counting repetitively
   	   Disabled/ or enabled with interrupt flags setting in different modes
	   OPTIONS:
	    OFF       -> Disabled  (Default)
		C_MODE1   -> Enabled (Interrupt in cout down only)
		C_MODE2   -> Enabled (Interrupt in count up only)
		C_MODE3   -> Enabled (Interrupt in both up and down count)
		*/
	 
	 #define PWM_CENTER_ALIGN   OFF
	 
	 /*4- Couting Direction: Set timer to count UP or DOWN
	      OPTIONS: 
		  PWM_UP      -> Counter starts from 0 and counts till period value
				      	 then creates overflow interrupt    (Default)
		  PWM_DOWN    -> Counter starts from period value then decrements 
						 till it raches 0 and then create underflow interrupt
	 */
	 
	  #define PWM_COUNT_DIRECTION     PWM_UP
	  
	  /*5- One Pulse Mode: Stop Counter at update event (when interrupt occur)
		OPTIONS:
		 1    -> Enable One Pulse Mode
		 0    -> Disable One Pulse Mode (Default)
	  */
	  
	  #define PWM_ONE_PULSE       0
	  
	  /*6- Interrupt, DMA Enable:  Enable features on Update
	       OPTIONS:
		     1    ->  Enabled
			 0    ->  Disabled   (Default)
	  */
	  
	  #define PWM_INTERRUPT_ENABLE     0
		#define PWM_DMA_ENABLE           0
	  
	  /*7- Output Channels used: The number of output channels controlled
	       by the timer. 
		   OPTIONS:
		    1    -> Default
			2
			3
			4    -> All channels
			*/
   
	   #define PWM_OUTPUT_CHANNELS     4
	   
	   /*8- PWM Mode: Can be in 2 modes, mode1 has default state as high
	        Mode2 has default state as Low. AFTER Duty Cycle, changes the default state
			OPTIONS:
			1 -> Mode 1  (Default)
			2 -> Mode 2 
			*/
			
		#define PWM_MODE                1
		
		/*9- Output Polarity: Set active as High or Low for timer channels
		     OTPIONS:
			  1 -> Active HIGH (Rising Edge trigger in Encoder Mode)(Default)
			  0 -> Active LOW  (Falling Edge trigger in Encoder Mode)
		*/
		
		#define PWM_POLARITY            1
		
		/*10- PWM Complementary Channels: Activate/Deactivate channels that inverts
		      and mirrors the settings of PWM Channels
			  OPTIONS:
			  1 -> Activate complementary channels
			  0 -> Deactivate complementary channels  (Default)
		*/
		
		#define PWM_COMPLEMENTARY       0
		
		
		/*11- PWM Prescaler: Set the value of timer clock prescaler, the final clock follows the following:
				Bus__Clock/ (Prescaler value + 1)
			  OPTIONS:
			  Any decimal value from 0 to 65535
			  Default Value = 0
		*/
		
		#define PWM_PRESCALER          49
		
		
		
		
		
		
		
		//Extra Encoder Configurations
		
		/*12- Encoder Mode: Select which encoder input pin is used for positioning and which for direction, or both
		      Mode 1: TI2 is used for counter position, TI1 is used for direction 
					Mode 2: TI1 is used for counter position, TI2 is used for direction 
					Mode 3: Both mode 1, mode 2 are active 
					OPTIONS:
									for Encoder Mode 1     ->  1   (default)
									for Encoder Mode 2     ->  2
									for Encoder Mode 3     ->  3
		*/
		
		#define ENC_MODE     1
		
		
	  /*13- Encoder Filter: Select the required number of detected edges (N)(Events) needed to change the state of the input
													This acts as a digital filter 
													Note: fCK_INT is timer clock
																fDTS is digital clock that is configured in PWM_CLK
	  	OPTIONS:
	  					0: No filter, sampling is done at fDTS   (default)
							1: fSAMPLING=fCK_INT, N=2
							2: fSAMPLING=fCK_INT, N=4
							3: fSAMPLING=fCK_INT, N=8
							4: fSAMPLING=fDTS/2, N=6
							5: fSAMPLING=fDTS/2, N=8
							6: fSAMPLING=fDTS/4, N=6
							7: fSAMPLING=fDTS/4, N=8
							8: fSAMPLING=fDTS/8, N=6
							9: fSAMPLING=fDTS/8, N=8
							10: fSAMPLING=fDTS/16, N=5
							11: fSAMPLING=fDTS/16, N=6
							12: fSAMPLING=fDTS/16, N=8
							13: fSAMPLING=fDTS/32, N=5
							14: fSAMPLING=fDTS/32, N=6
							15: fSAMPLING=fDTS/32, N=8
		*/
		
		#define ENC_FILTER     0
		
		
		/*14- Encoder Prescaler: Select the number of detected edges needed to make timer capture
	OPTIONS:
					0: no prescaler, capture is done each time an edge is detected on the capture input (default)
          1: capture is done once every 2 events
          2: capture is done once every 4 events
          3: capture is done once every 8 events
		*/
		
		#define ENC_PRESCALER     0
		
		/*15- Interrupt, DMA Enable:  Enable features on Update
	       OPTIONS:
		   1    ->  Enabled
			 0    ->  Disabled   (Default)
	  */
	  
	  #define ENC_INTERRUPT_ENABLE     1
		#define ENC_DMA_ENABLE           0
		
   
   #endif