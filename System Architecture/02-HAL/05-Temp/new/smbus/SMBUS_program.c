/************************************************************
   Author  :  Omaima                                         
   Date    : 6/6/2021                                         
   Version : V01                                             
*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "SMBUS_interface.h"
#include "SMBUS_config.h"
#include "SMBUS_private.h"



u32 flags=0;
u32 TIME_OUT=0;


void SMBUS_init()
{
	
	#ifdef   SMBUS_I2C1         // SMBA1 --> PB5
	      
		   // SCL1 --> PB6
		 GPIO_voidSetPinDirection(GPIOB , 6, GPIO_AF  );
		 GPIO_Set_AF(GPIOB , 6, 9 );
		 SET_GPIO_SPEED( GPIOB , 6 ,GPIO_SPEED_HIGH );
		 GPIO_SET_PP_OD (GPIOB , 6, GPIO_OUTPUT_OD);
		 GPIO_SET_PU_PD (GPIOB , 6, GPIO_NO_PU_PD);
		 
		   // SDA1 --> PB7
		 GPIO_voidSetPinDirection(GPIOB , 7, GPIO_AF  );
		  GPIO_Set_AF(GPIOB , 7, 9 );
		 SET_GPIO_SPEED( GPIOB , 7 ,GPIO_SPEED_HIGH );
		 GPIO_SET_PP_OD (GPIOB , 7, GPIO_OUTPUT_OD);
		 GPIO_SET_PU_PD (GPIOB , 7, GPIO_NO_PU_PD);
		 
		 
		 // Reset the i2c
		    SET_BIT( SMBUS_I2C_1 -> SMB_CR1 , 15 );
		    CLR_BIT( SMBUS_I2C_1 -> SMB_CR1 , 15);
		 // Set clock 
		      SMBUS_I2C_1 -> SMB_CR2 &=~ (0b111111);
			  SMBUS_I2C_1 -> SMB_CR2 |= (SMBUS_I2C_CLK/1000000);  
         // PE bit must be 0 
		    CLR_BIT( SMBUS_I2C_1 -> SMB_CR1 , 0 );
		//  clear CCR register
			SMBUS_I2C_1 -> SMB_CCR &=~ 0xFFFF;
		// CCR=(Tr(scl)+Tw(sclH))/Tpclk1     from tables: Tr(scl)=1000 ns  & Tw(sclH)=4000 ns --> CCR=5000 ns/Tpclk1  note: Tpclk1 = 1/(SMBUS_I2C_CLK) 
		    if(SMBUS_I2C_SPEED <=100000){
			  u8  CCR_value=5*(SMBUS_I2C_CLK/1000000);
				if(CCR_value<0x04)
				{
					CCR_value=0x04;
				}
				SMBUS_I2C_1 -> SMB_CCR |= CCR_value;
				SMBUS_I2C_1 -> SMB_TRISE |= (SMBUS_I2C_CLK/1000000)+1;
			}
		     
		     
		 #if  SMBUS_I2C_TYPE == SMBUS_I2C_HOST 
	      
		   CLR_BIT( SMBUS_I2C_1 -> SMB_CR1 , 0 );
		   SET_BIT( SMBUS_I2C_1 -> SMB_CR1 , 1 );
		   CLR_BIT( SMBUS_I2C_1 -> SMB_CR1 , 2 );
		   SET_BIT( SMBUS_I2C_1 -> SMB_CR1 , 3 );
		   
		 #elif  SMBUS_I2C_TYPE == SMBUS_I2C_DEVICE
		 
	        CLR_BIT( SMBUS_I2C_1 -> SMB_CR1 , 0 );
		      SET_BIT( SMBUS_I2C_1 -> SMB_CR1 , 1 );
		      CLR_BIT( SMBUS_I2C_1 -> SMB_CR1 , 2 );
			   CLR_BIT( SMBUS_I2C_1 -> SMB_CR1 , 3 );
			 
	     #endif
		 
		 #if     SMBUS_I2C_DUTY== SMBUS_I2C_DUTY_2
		 
		     CLR_BIT( SMBUS_I2C_1 -> SMB_CCR , 14 );
			 
		#elif    SMBUS_I2C_DUTY== SMBUS_I2C_DUTY_16_9  
		    
			 SET_BIT( SMBUS_I2C_1 -> SMB_CCR , 14 );
		#endif
		#if    SMBUS_I2C_ACK  == SMBUS_I2C_ACK_ENABLED
		       SET_BIT( SMBUS_I2C_1 -> SMB_CR1 , 10 );
		#elif  SMBUS_I2C_ACK  == SMBUS_I2C_ACK_DISABLED
		       CLR_BIT( SMBUS_I2C_1 -> SMB_CR1 , 10 );
		#endif
		
		
		
		 #if   SMBUS_I2C_ACK_ADDRESS == SMBUS_I2C_ACK_ADDRESS_7_BIT 
		     /*** 7-bit slave address_clear_bit_15 , 
			      Bit 14 Should always be kept at 1 by software , 
				  Bits 13:10 Reserved, must be kept at reset value.    ***/
				  
		          SMBUS_I2C_1 -> SMB_OAR1 |= (0x4000 | SMBUS_I2C_OWN_ADD_1);        
				  
		 #elif  SMBUS_I2C_ACK_ADDRESS == SMBUS_I2C_ACK_ADDRESS_10_BIT 
		     /*** 10-bit slave address_set_bit_15 , 
			      Bit 14 Should always be kept at 1 by software , 
				  Bits 13:10 Reserved, must be kept at reset value.    ***/
				  
		          SMBUS_I2C_1 -> SMB_OAR1 |= (0xC000| SMBUS_I2C_OWN_ADD_1) ;            
		 #endif
		 #if    SMBUS_I2C_ALERT == SMBUS_I2C_ALERT_LOW
		         CLR_BIT( SMBUS_I2C_1 -> SMB_SR1 , 15 );
		 #elif  SMBUS_I2C_ALERT == SMBUS_I2C_ALERT_HIGH
		         SET_BIT( SMBUS_I2C_1 -> SMB_SR1 , 15 );
		 #endif
		 SET_BIT( SMBUS_I2C_1 -> SMB_CR1 , 0 );
		 // for MLX90614
		GPIO_voidSetPinValue( GPIOB, 6 , GPIO_LOW);  
		MSTK_void_SysTick_Delay (6);
		GPIO_voidSetPinValue( GPIOB, 6 , GPIO_HIGH);  
	#endif
	
	#ifdef  SMBUS_I2C2         // SMBA2 --> PB12
	      
		  // SCL2 --> PB10		   
		 GPIO_voidSetPinDirection(GPIOB , 10, GPIO_AF  );
		 GPIO_Set_AF(GPIOB , 10, 9 );
		 SET_GPIO_SPEED( GPIOB , 10 ,GPIO_SPEED_HIGH );
		 GPIO_SET_PP_OD (GPIOB , 10, GPIO_OUTPUT_OD);
		 GPIO_SET_PU_PD (GPIOB , 10, GPIO_NO_PU_PD);
		 
		    // SDA2 --> PB3
		 GPIO_voidSetPinDirection(GPIOB ,3, GPIO_AF  );
		 GPIO_Set_AF(GPIOB , 3, 9 );
		 SET_GPIO_SPEED( GPIOB , 3 ,GPIO_SPEED_HIGH );
		 GPIO_SET_PP_OD (GPIOB , 3, GPIO_OUTPUT_OD);
		 GPIO_SET_PU_PD (GPIOB , 3, GPIO_NO_PU_PD);
		 // Reset the i2c
		    SET_BIT( SMBUS_I2C_2 -> SMB_CR1 , 15 );
		    CLR_BIT( SMBUS_I2C_2 -> SMB_CR1 , 15);
		 // Set clock 
		      SMBUS_I2C_2 -> SMB_CR2 &=~ (0b111111);
			  SMBUS_I2C_2 -> SMB_CR2 |= (SMBUS_I2C_CLK/1000000);  
         // PE bit must be 0 
		    CLR_BIT( SMBUS_I2C_2 -> SMB_CR1 , 0 );
		//  clear CCR register
			SMBUS_I2C_2 -> SMB_CCR &=~ 0xFFFF;
		// CCR=(Tr(scl)+Tw(sclH))/Tpclk1     from tables: Tr(scl)=1000 ns  & Tw(sclH)=4000 ns --> CCR=5000 ns/Tpclk1  note: Tpclk1 = 1/(SMBUS_I2C_CLK) 
		    if(SMBUS_I2C_SPEED <=100000){
			   u8 CCR_value=5*(SMBUS_I2C_CLK/1000000);
				if(CCR_value<0x04)
				{
					CCR_value=0x04;
				}
				SMBUS_I2C_2 -> SMB_CCR |= CCR_value;
				SMBUS_I2C_2 -> SMB_TRISE |= (SMBUS_I2C_CLK/1000000)+1;
			}
		     
		 
		 #if  SMBUS_I2C_TYPE == SMBUS_I2C_HOST 
	      
		    CLR_BIT( SMBUS_I2C_2 -> SMB_CR1 , 0 );
		    SET_BIT( SMBUS_I2C_2 -> SMB_CR1 , 1 );
		    CLR_BIT( SMBUS_I2C_2 -> SMB_CR1 , 2 );
		    SET_BIT( SMBUS_I2C_2 -> SMB_CR1 , 3 );
		   
		 #elif  SMBUS_I2C_TYPE == SMBUS_I2C_DEVICE
		 
	        CLR_BIT( SMBUS_I2C_2 -> SMB_CR1 , 0 );
		    SET_BIT( SMBUS_I2C_2 -> SMB_CR1 , 1 );
		    CLR_BIT( SMBUS_I2C_2 -> SMB_CR1 , 2 );
			CLR_BIT( SMBUS_I2C_2 -> SMB_CR1 , 3 );
			
	    #endif
		 #if     SMBUS_I2C_DUTY== SMBUS_I2C_DUTY_2
		 
		     CLR_BIT( SMBUS_I2C_2 -> SMB_CCR , 14 );
			 
		#elif    SMBUS_I2C_DUTY== SMBUS_I2C_DUTY_16_9  
		    
			 SET_BIT( SMBUS_I2C_2 -> SMB_CCR , 14 );
		#endif
		#if    SMBUS_I2C_ACK  == SMBUS_I2C_ACK_ENABLED
		       SET_BIT( SMBUS_I2C_2 -> SMB_CR1 , 10 );
		#elif  SMBUS_I2C_ACK  == SMBUS_I2C_ACK_DISABLED
		       CLR_BIT( SMBUS_I2C_2 -> SMB_CR1 , 10 );
		#endif
		 #if   SMBUS_I2C_ACK_ADDRESS == SMBUS_I2C_ACK_ADDRESS_7_BIT 
		     /*** 7-bit slave address_clear_bit_15 , 
			      Bit 14 Should always be kept at 1 by software , 
				  Bits 13:10 Reserved, must be kept at reset value.    ***/
				  
		          SMBUS_I2C_2 -> SMB_OAR1 |= (0x4000| SMBUS_I2C_OWN_ADD_1) ;        
				  
		 #elif  SMBUS_I2C_ACK_ADDRESS == SMBUS_I2C_ACK_ADDRESS_10_BIT 
		     /*** 10-bit slave address_set_bit_15 , 
			      Bit 14 Should always be kept at 1 by software , 
				  Bits 13:10 Reserved, must be kept at reset value.    ***/
				  
		          SMBUS_I2C_2 -> SMB_OAR1 |= (0xC000| SMBUS_I2C_OWN_ADD_1) ;            
		 #endif
		  #if    SMBUS_I2C_ALERT == SMBUS_I2C_ALERT_LOW
		         CLR_BIT( SMBUS_I2C_2 -> SMB_SR1 , 15 );
		 #elif  SMBUS_I2C_ALERT == SMBUS_I2C_ALERT_HIGH
		         SET_BIT( SMBUS_I2C_2 -> SMB_SR1 , 15 );
		 #endif
		 SET_BIT( SMBUS_I2C_2 -> SMB_CR1 , 0 );
		 // for MLX90614
		GPIO_voidSetPinValue( GPIOB, 10 , GPIO_LOW);  
		MSTK_void_SysTick_Delay (6);
		GPIO_voidSetPinValue( GPIOB, 10 , GPIO_HIGH);  
	#endif		 
	
		   
	#ifdef  SMBUS_I2C3                         // SMBA3 --> PA9
	      
		   // SCL3 --> PA8
		 GPIO_voidSetPinDirection(GPIOA , 8, GPIO_AF  );
		 GPIO_Set_AF(GPIOA ,8, 9 );
		 SET_GPIO_SPEED( GPIOA , 8 ,GPIO_SPEED_HIGH );
		 GPIO_SET_PP_OD (GPIOA , 8, GPIO_OUTPUT_OD);
		 GPIO_SET_PU_PD (GPIOA , 8, GPIO_NO_PU_PD);
		 
		   // SDA3 --> PB4
		 GPIO_voidSetPinDirection(GPIOB , 4, GPIO_AF  );
		 GPIO_Set_AF(GPIOB , 4, 9 );
		 SET_GPIO_SPEED( GPIOB , 4 ,GPIO_SPEED_HIGH );
		 GPIO_SET_PP_OD (GPIOB , 4, GPIO_OUTPUT_OD);
		 GPIO_SET_PU_PD (GPIOB , 4, GPIO_NO_PU_PD);
		 
		 // Reset the i2c
		    SET_BIT( SMBUS_I2C_3 -> SMB_CR1 , 15 );
		    CLR_BIT( SMBUS_I2C_3 -> SMB_CR1 , 15);
		 // Set clock 
		      SMBUS_I2C_3 -> SMB_CR2 &=~ (0b111111);
			  SMBUS_I2C_3 -> SMB_CR2 |= (SMBUS_I2C_CLK/1000000);  
         // PE bit must be 0 
		    CLR_BIT( SMBUS_I2C_3 -> SMB_CR1 , 0 );
		//  clear CCR register
			SMBUS_I2C_3 -> SMB_CCR &=~ 0xFFFF;
		// CCR=(Tr(scl)+Tw(sclH))/Tpclk1     from tables: Tr(scl)=1000 ns  & Tw(sclH)=4000 ns --> CCR=5000 ns/Tpclk1  note: Tpclk1 = 1/(SMBUS_I2C_CLK) 
		    if(SMBUS_I2C_SPEED <=100000){
			   u8 CCR_value=5*(SMBUS_I2C_CLK/1000000);
				if(CCR_value<0x04)
				{
					CCR_value=0x04;
				}
				SMBUS_I2C_3 -> SMB_CCR |= CCR_value;
				SMBUS_I2C_3 -> SMB_TRISE |= (SMBUS_I2C_CLK/1000000)+1;
			}
		     
		 
		 #if  SMBUS_I2C_TYPE == SMBUS_I2C_HOST 
	      
		    CLR_BIT( SMBUS_I2C_3 -> SMB_CR1 , 0 );
		    SET_BIT( SMBUS_I2C_3 -> SMB_CR1 , 1 );
		    CLR_BIT( SMBUS_I2C_3 -> SMB_CR1 , 2 );
		    SET_BIT( SMBUS_I2C_3 -> SMB_CR1 , 3 );
		   
		 #elif  SMBUS_I2C_TYPE == SMBUS_I2C_DEVICE
		 
	        CLR_BIT( SMBUS_I2C_3 -> SMB_CR1 , 0 );
		    SET_BIT( SMBUS_I2C_3 -> SMB_CR1 , 1 );
		    CLR_BIT( SMBUS_I2C_3 -> SMB_CR1 , 2 );
			CLR_BIT( SMBUS_I2C_3 -> SMB_CR1 , 3 );
			 
		#endif
		#if     SMBUS_I2C_DUTY== SMBUS_I2C_DUTY_2
		 
		     CLR_BIT( SMBUS_I2C_3 -> SMB_CCR , 14 );
			 
		#elif    SMBUS_I2C_DUTY== SMBUS_I2C_DUTY_16_9  
		    
			 SET_BIT( SMBUS_I2C_3 -> SMB_CCR , 14 );
		#endif
		#if    SMBUS_I2C_ACK  == SMBUS_I2C_ACK_ENABLED
		       SET_BIT( SMBUS_I2C_3 -> SMB_CR1 , 10 );
		#elif  SMBUS_I2C_ACK  == SMBUS_I2C_ACK_DISABLED
		       CLR_BIT( SMBUS_I2C_3 -> SMB_CR1 , 10 );
		#endif
		
		 #if   SMBUS_I2C_ACK_ADDRESS == SMBUS_I2C_ACK_ADDRESS_7_BIT 
		     /*** 7-bit slave address_clear_bit_15 , 
			      Bit 14 Should always be kept at 1 by software , 
				  Bits 13:10 Reserved, must be kept at reset value.    ***/
				  
		          SMBUS_I2C_3 -> SMB_OAR1 |= (0x4000 | SMBUS_I2C_OWN_ADD_1) ;        
				  
		 #elif  SMBUS_I2C_ACK_ADDRESS == SMBUS_I2C_ACK_ADDRESS_10_BIT 
		     /*** 10-bit slave address_set_bit_15 , 
			      Bit 14 Should always be kept at 1 by software , 
				  Bits 13:10 Reserved, must be kept at reset value.    ***/
				  
		          SMBUS_I2C_3 -> SMB_OAR1 |= (0xC000| SMBUS_I2C_OWN_ADD_1) ;            
		 #endif
		  #if    SMBUS_I2C_ALERT == SMBUS_I2C_ALERT_LOW
		         CLR_BIT( SMBUS_I2C_3 -> SMB_SR1 , 15 );
		 #elif  SMBUS_I2C_ALERT == SMBUS_I2C_ALERT_HIGH
		         SET_BIT( SMBUS_I2C_3 -> SMB_SR1 , 15 );
		 #endif
		 SET_BIT( SMBUS_I2C_3 -> SMB_CR1 , 0 );
		 // for MLX90614
		GPIO_voidSetPinValue( GPIOA, 8 , GPIO_LOW);  
		MSTK_void_SysTick_Delay (6);
		GPIO_voidSetPinValue( GPIOA, 8 , GPIO_HIGH);  
		
	#endif
}

void SMBUS_START()
{  
	#ifdef   SMBUS_I2C1    
	  SET_BIT( SMBUS_I2C_1 -> SMB_CR1 , 8 );
	  /*** Check on start bit flag , Master mode & smbus busy or not ***/
	  flags = SMBUS_I2C_1 ->SMB_SR1 | SMBUS_I2C_1 ->SMB_SR2 ;   
	  TIME_OUT= SMBUS_I2C_DELAY;
	  while (!(flags& 0x00030001)&& TIME_OUT) --TIME_OUT;     // SB ,MSL,Busy
	  if(TIME_OUT==0) {return;} 
    #endif
    #ifdef   SMBUS_I2C2
	  SET_BIT( SMBUS_I2C_2 -> SMB_CR1 , 8 );
	  /*** Check on start bit flag , Master mode & smbus busy or not ***/
	  flags = SMBUS_I2C_2 ->SMB_SR1 | SMBUS_I2C_2 ->SMB_SR2 ;   
	  TIME_OUT= SMBUS_I2C_DELAY;
	  while (!(flags& 0x00030001)&& TIME_OUT) --TIME_OUT;     // SB ,MSL,Busy
	  if(TIME_OUT==0) {return;} 
    #endif
    #ifdef   SMBUS_I2C3
	  SET_BIT( SMBUS_I2C_3 -> SMB_CR1 , 8 );
	  /*** Check on start bit flag , Master mode & smbus busy or not ***/
	  flags = SMBUS_I2C_3 ->SMB_SR1 | SMBUS_I2C_3 ->SMB_SR2 ;   
	  TIME_OUT= SMBUS_I2C_DELAY;
	  while (!(flags& 0x00030001)&& TIME_OUT) --TIME_OUT;     // SB ,MSL,Busy
	  if(TIME_OUT==0) {return;} 
    #endif	
}

void SMBUS_STOP()
{
	#ifdef   SMBUS_I2C1    
	  SET_BIT( SMBUS_I2C_1 -> SMB_CR1 , 9 );
    #endif
    #ifdef   SMBUS_I2C2
	  SET_BIT( SMBUS_I2C_2 -> SMB_CR1 , 9 );
    #endif
    #ifdef   SMBUS_I2C3
	  SET_BIT( SMBUS_I2C_3 -> SMB_CR1 , 9 );
    #endif	
}
void SMBUS_SEND_SLAVE_ADDRESS(u8 ADDRESS, u8 RD_WR_bit)
{    
   
	#ifdef   SMBUS_I2C1
      if(RD_WR_bit==WR_BIT) 
	  {   
	  ADDRESS = CLR_BIT( SMBUS_I2C_1 -> SMB_OAR1 , 0 );   //Clear ADDR0 
	  SMBUS_I2C_1 -> SMB_DR = ADDRESS;    // send slave address 
	 /***Check data transmitter ,  ADDR received ,.... ***/
	    flags = SMBUS_I2C_1 ->SMB_SR1 | SMBUS_I2C_1 ->SMB_SR2 ;  
	    TIME_OUT= SMBUS_I2C_DELAY;
	    while (!(flags&0x00070082)&& TIME_OUT) --TIME_OUT;     // ADDR,TXE,MSL,BUSY,TRA 
	    if(TIME_OUT==0) {return;}
		}
	  else if(RD_WR_bit==RD_BIT)
	  { 
	  ADDRESS = SET_BIT( SMBUS_I2C_1 -> SMB_OAR1 , 0 );   // Set ADDR0
	  SMBUS_I2C_1 -> SMB_DR = ADDRESS;
	  flags = SMBUS_I2C_1 ->SMB_SR1 | SMBUS_I2C_1 ->SMB_SR2 ;   
	  TIME_OUT= SMBUS_I2C_DELAY;
	  while (!(flags&0x00030002)&& TIME_OUT) --TIME_OUT;     // ADDR ,MSL,Busy
	  if(TIME_OUT==0) {return;}
	  flags = SMBUS_I2C_1 ->SMB_SR1 | SMBUS_I2C_1 ->SMB_SR2 ;   
	  TIME_OUT= SMBUS_I2C_DELAY;
	  while (!(flags&0x00030040)&& TIME_OUT) --TIME_OUT;     // RXNE ,MSL,Busy
	  if(TIME_OUT==0) {return;}	  
	  }
    #endif
    #ifdef   SMBUS_I2C2
	   if(RD_WR_bit==WR_BIT) 
	  {   
	  ADDRESS = CLR_BIT( SMBUS_I2C_2 -> SMB_OAR1 , 0 );   //Clear ADDR0 
	  SMBUS_I2C_2 -> SMB_DR = ADDRESS;    // send slave address 
	 /***Check data transmitter ,  ADDR received ,.... ***/
	    flags = SMBUS_I2C_2 ->SMB_SR1 | SMBUS_I2C_2 ->SMB_SR2 ;  
	    TIME_OUT= SMBUS_I2C_DELAY;
	    while (!(flags&0x00070082)&& TIME_OUT) --TIME_OUT;     // ADDR,TXE,MSL,BUSY,TRA 
	    if(TIME_OUT==0) {return;}
		}
	  else if(RD_WR_bit==RD_BIT)
	  { 
	  ADDRESS = SET_BIT( SMBUS_I2C_2 -> SMB_OAR1 , 0 );   // Set ADDR0
	  SMBUS_I2C_2 -> SMB_DR = ADDRESS;
	  flags = SMBUS_I2C_2 ->SMB_SR1 | SMBUS_I2C_2 ->SMB_SR2 ;   
	  TIME_OUT= SMBUS_I2C_DELAY;
	  while (!(flags&0x00030002)&& TIME_OUT) --TIME_OUT;     // ADDR ,MSL,Busy
	  if(TIME_OUT==0) {return;}
	  flags = SMBUS_I2C_2 ->SMB_SR1 | SMBUS_I2C_2 ->SMB_SR2 ;   
	  TIME_OUT= SMBUS_I2C_DELAY;
	  while (!(flags&0x00030040)&& TIME_OUT) --TIME_OUT;     // RXNE ,MSL,Busy
	  if(TIME_OUT==0) {return;}	  
	  }
    #endif
    #ifdef   SMBUS_I2C3
	   if(RD_WR_bit==WR_BIT) 
	  {   
	  ADDRESS = CLR_BIT( SMBUS_I2C_3 -> SMB_OAR1 , 0 );   //Clear ADDR0 
	  SMBUS_I2C_3 -> SMB_DR = ADDRESS;    // send slave address 
	 /***Check data transmitter ,  ADDR received ,.... ***/
	    flags = SMBUS_I2C_3 ->SMB_SR1 | SMBUS_I2C_3 ->SMB_SR2 ;  
	    TIME_OUT= SMBUS_I2C_DELAY;
	    while (!(flags&0x00070082)&& TIME_OUT) --TIME_OUT;     // ADDR,TXE,MSL,BUSY,TRA 
	    if(TIME_OUT==0) {return;}
		}
	  else if(RD_WR_bit==RD_BIT)
	  { 
	  ADDRESS = SET_BIT( SMBUS_I2C_3 -> SMB_OAR1 , 0 );   // Set ADDR0
	  SMBUS_I2C_3 -> SMB_DR = ADDRESS;
	  flags = SMBUS_I2C_3 ->SMB_SR1 | SMBUS_I2C_3 ->SMB_SR2 ;   
	  TIME_OUT= SMBUS_I2C_DELAY;
	  while (!(flags&0x00030002)&& TIME_OUT) --TIME_OUT;     // ADDR ,MSL,Busy
	  if(TIME_OUT==0) {return;}
	  flags = SMBUS_I2C_3 ->SMB_SR1 | SMBUS_I2C_3 ->SMB_SR2 ;   
	  TIME_OUT= SMBUS_I2C_DELAY;
	  while (!(flags&0x00030040)&& TIME_OUT) --TIME_OUT;     // RXNE ,MSL,Busy
	  if(TIME_OUT==0) {return;}	  
	  }
    #endif	
}
void SMBUS_SEND_DATA(u8 COMMAND)
{    u32 flags=0;
	   u32 TIME_OUT=0;
	#ifdef   SMBUS_I2C1    
	   SET_BIT( SMBUS_I2C_1 -> SMB_CR1 , 0 );   //enble PE
	   SMBUS_I2C_1 -> SMB_DR = COMMAND;
	   
	    flags = SMBUS_I2C_1 ->SMB_SR1 | SMBUS_I2C_1 ->SMB_SR2 ;
	    TIME_OUT= SMBUS_I2C_DELAY;
	    while (!(flags&0x00070084)&& TIME_OUT) --TIME_OUT;     // BTF, TXE,MSL,BUSY,TRA
	    if(TIME_OUT==0) {return;}
    #endif
    #ifdef   SMBUS_I2C2
	     SET_BIT( SMBUS_I2C_2 -> SMB_CR1 , 0 );   //enble PE
	     SMBUS_I2C_2 -> SMB_DR = COMMAND;
	   
	     flags = SMBUS_I2C_2 ->SMB_SR1 | SMBUS_I2C_2 ->SMB_SR2 ;
	     TIME_OUT= SMBUS_I2C_DELAY;
	     while (!(flags&0x00070084)&& TIME_OUT) --TIME_OUT;     // BTF, TXE,MSL,BUSY,TRA
	     if(TIME_OUT==0) {return;}
    #endif
    #ifdef   SMBUS_I2C3
	    SET_BIT( SMBUS_I2C_3 -> SMB_CR1 , 0 );   //enble PE
	    SMBUS_I2C_3 -> SMB_DR = COMMAND;
	   
	    flags = SMBUS_I2C_3 ->SMB_SR1 | SMBUS_I2C_3 ->SMB_SR2 ;
	    TIME_OUT= SMBUS_I2C_DELAY;
	    while (!(flags&0x00070084)&& TIME_OUT) --TIME_OUT;     // BTF, TXE,MSL,BUSY,TRA
	    if(TIME_OUT==0) {return;}
    #endif	
}
u8 SMBUS_READ_DATA()
{
	#ifdef   SMBUS_I2C1    
	  return SMBUS_I2C_1 -> SMB_DR;
    #endif
    #ifdef   SMBUS_I2C2
	  return SMBUS_I2C_2 -> SMB_DR;
    #endif
    #ifdef   SMBUS_I2C3
	  return SMBUS_I2C_3 -> SMB_DR;
    #endif	
}

void SMBUS_CHECK_READ_DATA()
{
	
	#ifdef   SMBUS_I2C1    
	  
	  flags = SMBUS_I2C_1 ->SMB_SR1 | SMBUS_I2C_1 ->SMB_SR2 ;   
	  TIME_OUT= SMBUS_I2C_DELAY;
	  while (!(flags&0x00030040)&& TIME_OUT) --TIME_OUT;     // RXNE ,MSL,Busy
	  if(TIME_OUT==0) {return;}
    #endif
    #ifdef   SMBUS_I2C2
	  
	  flags = SMBUS_I2C_2 ->SMB_SR1 | SMBUS_I2C_2 ->SMB_SR2 ;   
	  TIME_OUT= SMBUS_I2C_DELAY;
	  while (!(flags&0x00030040)&& TIME_OUT) --TIME_OUT;     // RXNE ,MSL,Busy
	  if(TIME_OUT==0) {return;}
    #endif
    #ifdef   SMBUS_I2C3
	  
	  flags = SMBUS_I2C_3 ->SMB_SR1 | SMBUS_I2C_3 ->SMB_SR2 ;   
	  TIME_OUT= SMBUS_I2C_DELAY;
	  while (!(flags&0x00030040)&& TIME_OUT) --TIME_OUT;     // RXNE ,MSL,Busy
	  if(TIME_OUT==0) {return;}
    #endif	
	 
}

 u8 SMBUS_CRC8(u8 Data)
 {
	 u8 crc=0;
	 u8 _crc;
	 crc^= Data;
	 for(u8 i=0 ; i<8 ; ++i )
	 {
		 if(crc&0x80)
		 {
			 _crc=(crc<<1) ;
			 _crc^=0x07;
		 }
		 else 
		 {
			 _crc=crc<<1;
		 }
		 return _crc;
	 }
 }

