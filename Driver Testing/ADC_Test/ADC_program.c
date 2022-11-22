/********************************************************
   File:        Program File of ADC Driver              *
   Author:      Hamdy Osama Mohamed                     *
   Version:     V01                                     *
   Date:        6/12/2020                               *
   Updates:     ----                                    *
********************************************************/
   
   #include    <STD_TYPES.h>
   #include    <BIT_MATH.h>
   
   #include    <ADC_interface.h>
   #include    <ADC_private.h>
   #include    <ADC_config.h>
   
   
   
   void  MADC_voidInit(void){
   //Setting ADC Clock Prescaler
   #if ADC_PRESCALER==2 
	   ADC_CCR &= ~(0x00030000);   //PRESCALER BITS (0,0)
   
   #elif ADC_PRESCALER==4 
	   ADC_CCR &= ~(0x00020000);   //PRESCALER BITS (0,x)
	   ADC_CCR |=  (0x00010000);   //PRESCALER BITS (0,1)
   
   #elif ADC_PRESCALER==6 
	   ADC_CCR |=  (0x00020000);   //PRESCALER BITS (1,x)
	   ADC_CCR &= ~(0x00010000);   //PRESCALER BITS (1,0)
   
   #elif ADC_PRESCALER==8 
	   ADC_CCR |=  (0x00030000);   //PRESCALER BITS (1,1)
   
   #else
		#Error ("Wrong ADC Clock Prescaler Configuration ")
	#endif
   
   
   
   //Setting ADC1 Resolution
   #if ADC_RESOLUTION==12
	   ADC1_CR1 &= ~(0x03000000);   //RESOLUTION BITS of ADC1 (0,0)
   
   #elif ADC_RESOLUTION==10
	   ADC1_CR1 &= ~(0x02000000);   //RESOLUTION BITS of ADC1 (0,x)
	   ADC1_CR1 |=  (0x01000000);   //RESOLUTION BITS of ADC1 (0,1)
   
   #elif ADC_RESOLUTION==8
	   ADC1_CR1 |=  (0x02000000);   //RESOLUTION BITS of ADC1 (1,x)
	   ADC1_CR1 &= ~(0x01000000);   //RESOLUTION BITS of ADC1 (1,0)
   
   #elif ADC_RESOLUTION==6
	   ADC1_CR1 |=  (0x03000000);   //RESOLUTION BITS of ADC1 (1,1)
   
   #else
		#Error ("Wrong ADC1 Resolution Configuration ")
	#endif
   
   
   
   //Setting ADC1 Sample Time (Cycles)
   #if ADC_SAMPLING_CYCLES==3
	   ADC1_SMPR1 &= ~(0x07FFFFFF); //SMP BITS OF CHNLS 10 -> 18 are (0,0,0)
	   ADC1_SMPR2 &= ~(0x3FFFFFFF); //SMP BITS OF CHNLS 0 -> 9 are (0,0,0)
   
   #elif ADC_SAMPLING_CYCLES==15
	   for(u8 i=0;i<9;i++){       //SMP BITS OF CHNLS 10 -> 18 are (0,0,1)
	   ADC1_SMPR1 &= (~(0x6)<<(i*3)); 
       ADC1_SMPR1 |= ((0x1)<<(i*3)); 
	   }
	   for(u8 i=0;i<10;i++){       //SMP BITS OF CHNLS 0 -> 9 are (0,0,1)
	   ADC1_SMPR2 &= (~(0x6)<<(i*3)); 
       ADC1_SMPR2 |= ((0x1)<<(i*3)); 
	   }
    
   #elif ADC_SAMPLING_CYCLES==28
	   for(u8 i=0;i<9;i++){       //SMP BITS OF CHNLS 10 -> 18 are (0,1,0)
	   ADC1_SMPR1 &= (~(0x5)<<(i*3)); 
       ADC1_SMPR1 |= ((0x2)<<(i*3)); 
	   }
	   for(u8 i=0;i<10;i++){       //SMP BITS OF CHNLS 0 -> 9 are (0,1,0)
	   ADC1_SMPR2 &= (~(0x5)<<(i*3)); 
       ADC1_SMPR2 |= ((0x2)<<(i*3)); 
	   }
   
   #elif ADC_SAMPLING_CYCLES==56
	   for(u8 i=0;i<9;i++){       //SMP BITS OF CHNLS 10 -> 18 are (0,1,1)
	   ADC1_SMPR1 &= (~(0x4)<<(i*3)); 
       ADC1_SMPR1 |= ((0x3)<<(i*3)); 
	   }
	   for(u8 i=0;i<10;i++){       //SMP BITS OF CHNLS 0 -> 9 are (0,1,1)
	   ADC1_SMPR2 &= (~(0x4)<<(i*3)); 
       ADC1_SMPR2 |= ((0x3)<<(i*3)); 
	   }
   
   #elif ADC_SAMPLING_CYCLES==84
	   for(u8 i=0;i<9;i++){       //SMP BITS OF CHNLS 10 -> 18 are (1,0,0)
	   ADC1_SMPR1 &= (~(0x3)<<(i*3)); 
       ADC1_SMPR1 |= ((0x4)<<(i*3)); 
	   }
	   for(u8 i=0;i<10;i++){       //SMP BITS OF CHNLS 0 -> 9 are (1,0,0)
	   ADC1_SMPR2 &= (~(0x3)<<(i*3)); 
       ADC1_SMPR2 |= ((0x4)<<(i*3)); 
	   }
   
   #elif ADC_SAMPLING_CYCLES==112
	   for(u8 i=0;i<9;i++){       //SMP BITS OF CHNLS 10 -> 18 are (1,0,1)
	   ADC1_SMPR1 &= (~(0x2)<<(i*3)); 
       ADC1_SMPR1 |= ((0x5)<<(i*3)); 
	   }
	   for(u8 i=0;i<10;i++){       //SMP BITS OF CHNLS 0 -> 9 are (1,0,1)
	   ADC1_SMPR2 &= (~(0x2)<<(i*3)); 
       ADC1_SMPR2 |= ((0x5)<<(i*3)); 
	   }
    
   #elif ADC_SAMPLING_CYCLES==144
	   for(u8 i=0;i<9;i++){       //SMP BITS OF CHNLS 10 -> 18 are (1,1,0)
	   ADC1_SMPR1 &= (~(0x1)<<(i*3)); 
       ADC1_SMPR1 |= ((0x6)<<(i*3)); 
	   }
	   for(u8 i=0;i<10;i++){       //SMP BITS OF CHNLS 0 -> 9 are (1,1,0)
	   ADC1_SMPR2 &= (~(0x1)<<(i*3)); 
       ADC1_SMPR2 |= ((0x6)<<(i*3)); 
	   }
   
   #elif ADC_SAMPLING_CYCLES==480
	   ADC1_SMPR1 |= (0x07FFFFFF); //SMP BITS OF CHNLS 10 -> 18 are (1,1,1)
	   ADC1_SMPR2 |= (0x3FFFFFFF); //SMP BITS OF CHNLS 0 -> 9 are (1,1,1)
      
   #else
		#Error ("Wrong ADC1 Sampling Time Configuration ")
	#endif
   
   
   //Setting ADC1 Data Allignment
   #if ADC_DATA_ALIGN==RIGHT
	   ADC1_CR2 &= ~(0x00000800);  //Align Bit = 0
   
   #elif ADC_DATA_ALIGN==LEFT
	   ADC1_CR2 |= {0x00000800);  //Align Bit = 1
   
   #else
		#Error ("Wrong ADC1 Data Alignment Configuration ")
	#endif
   
   
   //Setting ADC1 Interrupts
   //Overrun Interrupt
   #if ADC_OVERRUN_INTERRUPT==1     
	   ADC1_CR1 |=  (0x04000000);    //OVRIE BIT = 1
   
   #elif ADC_OVERRUN_INTERRUPT==0     
	   ADC1_CR1 &= ~(0x04000000);    //OVRIE BIT = 0
   
   #else
		#Error ("Wrong ADC1 Overrun Interrupt Configuration ")
	#endif
   
   //Injected/Regular Conversion End Interrupt
   #if ADC_INTERRUPTS==1
	   ADC1_CR1 |=  (0x000000A0);   //JEOCIE= EOCIE= 1
   
   #elif ADC_INTERRUPTS==0
	   ADC1_CR1 &= ~(0x000000A0);   //JEOCIE= EOCIE= 0
   
   #else
		#Error ("Wrong ADC1 EOC Interrupt Configuration ")
	#endif
   
   //Setting ADC1 Watchdog
   #if ADC_WATCHDOG_ENABLE ==1    //Enable regular/injected watchdogs
	   ADC1_CR1 |=  (0x00C00000);  //AWDEN= JAWDEN= 1
	   ADC1_CR1 |=  (0x00000040);  //AWDIE= 1
	   ADC1_CR1 &= ~(0x00000200);  //AWDSGL= 0 (Enabled on all channels)
   
   #elif ADC_WATCHDOG_ENABLE ==0   //Disable regular/injected watchdogs
	   ADC1_CR1 &= ~(0x00C00000);  //AWDEN= JAWDEN= 0
	   ADC1_CR1 &= ~(0x00000040);  //AWDIE= 0
   
   #else
		#Error ("Wrong ADC1 AWD Configuration ")
	#endif
   
   //Setting EOC Selection
   #if EOC_SELECTION==1
	   ADC1_CR2 |=  (0x00000400); //EOCS= 1
   
   #elif EOC_SELECTION==0
	   ADC1_CR2 &= ~(0x00000400); //EOCS= 0
   
   #else
		#Error ("Wrong ADC1 EOC Configuration ")
	#endif
   
   
   
   //Setting External Trigger Enable (Regular + Injected)
   #if EXTERNAL_TRIGGER==OFF
	   ADC1_CR2 &= ~(0x30300000);  //EXTEN= JEXTEN= (0,0)
   
   #elif EXTERNAL_TRIGGER==RISING_EDGE
	   ADC1_CR2 &= ~(0x20200000);  //EXTEN= JEXTEN= (0,x)
	   ADC1_CR2 &= ~(0x10100000);  //EXTEN= JEXTEN= (0,1)
   
   #elif EXTERNAL_TRIGGER==FALLING_EDGE
	   ADC1_CR2 &= ~(0x10100000);  //EXTEN= JEXTEN= (x,0)
	   ADC1_CR2 &= ~(0x20200000);  //EXTEN= JEXTEN= (1,0)
   
   #elif EXTERNAL_TRIGGER==RISING_FALLING_EDGE
	   ADC1_CR2 &= ~(0x30300000);  //EXTEN= JEXTEN= (1,1)
   
   #else
		#Error ("Wrong ADC1 External Trigger Configuration ")
	#endif
   
   
   //DMA MODE
   #if DMA_MODE==1
	   ADC1_CR2 |=  (0x00000300);  //DDS= DMA= 1
   
   #elif DMA_MODE==0
	   ADC1_CR2 &= ~(0x00000100); //DMA= 0
   
   #else
		#Error ("Wrong DMA Configuration ")
	#endif
	

   //Discontnuous Mode
   #if DISC_MODE ==1  //Enable DISC MODE (REGULAR/INJECTED)
	   ADC1_CR1 |=  (0x00001800);  //JDISCEN= DISCEN= 1
	   if (DISC_CHANNELS<9 && DISC_CHANNELS>0){
		   ADC1_CR1 &= ~(0x0000E000);     //Reset DISCNUM
		   ADC1_CR1 |= ((DISC_CHANNELS-1)<<13); //Set DISCNUM
	   }   
   
   #elif DISC_MODE ==0 //Disable DISC MODE (Regular/Injected)
       ADC1_CR1 &= ~(0x00001800);  //JDISCEN= DISCEN= 0
   
   #else
		#Error ("Wrong DISC Configuration ")
	#endif
	
	
	
	//Automatic Injection Mode
	#if AUTO_J_CONVERSION==1 // Enable Auto-Injection
	   ADC1_CR1 |=  (0x00000400); //JAUTO= 1
	
	#elif AUTO_J_CONVERSION==0 // Disable Auto-Injection
	   ADC1_CR1 &= ~(0x00000400); //JAUTO= 0
	#else
		#Error ("Wrong Automatic Injection Configuration ")
	#endif
	
	
	//Scan Mode
	#if SCAN_MODE == 1 //Enable Scan Mode
	   ADC1_CR1 |=   (0x00000100);   //SCAN= 1
	   if (SCANNED_CHANNELS<17 && SCANNED_CHANNELS>0){
	   ADC1_SQR1 &= ~(0x00F00000);   //Reset Scanned Channels #
	   ADC1_SQR1 |= ((SCANNED_CHANNELS-1)<<20); //Set Scanned Channels #
	   }
	#elif SCAN_MODE == 0 //Disable Scan Mode
	   ADC1_CR1 &= ~(0x00000100);   //SCAN= 0
	#else
		#Error ("Wrong Scan Mode Configuration ")
	#endif  
	   
	//Initializing Single Mode (Default) and Cutting ADC Power
	ADC1_CR2 &= ~(0x00000003);   //ADON= CONT= 0
   }
   
   
   
u16   MADC_u16AnalogSingleRead(u8 Copy_u8Channel){
	
	// Set scanned channels to 1
	ADC1_SQR1 &= ~(0x00F00000);   
	// Set the selected channel in Sequence
	ADC1_SQR3 &= ~(0x0000001F); //Reset Sequence
	ADC1_SQR3 |= (Copy_u8Channel & (0x0000000F)); //Set Channel number in 1st sequence
	// Set Cont = 0
	ADC1_CR2 &= ~(0x00000002);   // CONT= 0
	// ADC is Powered ON
	ADC1_CR2 |= (0x00000001);   // ADON= 1
	// Start Regular Conversion
	ADC1_CR2 |= (0x40000000);   //SWSTART = 1
	// Wait till conversion is finished
	while(GET_BIT(ADC1_SR,1)!=1){ //Do Nothing till EOC is SET by hardware
		
	}
	// Clear //(EOC), Start Flag
	CLR_BIT(ADC1_SR,4); //Clear STRT
	CLR_BIT(ADC1_SR,2); //Clear EOC
	// ADC is Powered OFF
	CLR_BIT(ADC1_CR2,0); //ADON= 0
	//Return Converted Value
	return ADC1_DR;
}






   