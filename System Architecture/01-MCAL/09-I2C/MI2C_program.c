/*********************************************************/
/*Author    : youstina                                   */
/*version   : v05                                        */
/*date      : 12 MAY 2021                                */
/*********************************************************/
                 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MI2C_interface.h"
#include "MI2C_private.h"
#include "MI2C_config.h"
#include "STK_interface.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "DMA_interface.h"


#define  GPIOB_BASE_ADDRESS  0x40010C00
#define   GPIOB_CRL                                  *((u32 *)(GPIOB_BASE_ADDRESS + 0x00))

void MI2C_Busy(void){
I2C_1->CR1 &=~ ((0b1)<< (0)); // disable the peripheral to set the configurtion

//GPIO_voidSetPinDirection(GPIOB , 7 , GPIO_OUTPUT );
//GPIO_voidSetPinDirection(GPIOB , 6 , GPIO_OUTPUT );
GPIOB_CRL &=~((0xC)<<(6*4));          //Reset Pin Configs (Push pull)
GPIOB_CRL |= ((0x4)<<(6*4));          //Set Pin Configs (open drain)
GPIOB_CRL &=~((0xC)<<(7*4));          //Reset Pin Configs (Push pull)
GPIOB_CRL |= ((0x4)<<(7*4));          //Set Pin Configs (open drain)
	//GPIO_SET_PP_OD (GPIOB , 6, GPIO_OUTPUT_OD);
//GPIO_SET_PP_OD (GPIOB , 7, GPIO_OUTPUT_OD);
GPIO_voidSetPinValue(GPIOB , 6 , GPIO_HIGH);
GPIO_voidSetPinValue(GPIOB , 7 , GPIO_HIGH);


	// SDA, SCL general purpose output, open drain, high level

//check SDA, SCL high level

GPIO_voidSetPinValue(GPIOB , 7 , GPIO_LOW); //SDA output, open drain, low level

//SDA check SDA low level


GPIO_voidSetPinValue(GPIOB , 6 , GPIO_LOW); //SCL output, open drain, low level

//SCL check SCL low level


GPIO_voidSetPinValue(GPIOB , 6 , GPIO_HIGH); //SCL output, open drain, HIGH level

//SCL check SCL HIGH leve


GPIO_voidSetPinValue(GPIOB , 7 , GPIO_HIGH);//SDA output, open drain, HIGH level

//SDA check SCL HIGH leve

GPIO_voidSetPinDirection(GPIOB , 6 , GPIO_AF_OD );
GPIO_voidSetPinDirection(GPIOB , 7 , GPIO_AF_OD );// SDA, SCL ALTERNATIVE FUNCTION, open drain

I2C_1->CR1 |= ((0b1)<< (15)); // SWRST  set

I2C_1->CR1 &=~ ((0b1)<< (15)); // SWRST  clear

I2C_1->CR1 &=~ ((0b1)<< (0)); //enable peripheral
}


void MI2C_voidInit(u8 Copy_u8I2C )
{
	switch(Copy_u8I2C)
    {
        case 0 :
		    RCC_voidEnableClock ( RCC_APB1 , 21 ); // enable peripheral clock
			I2C_1->CR1 &=~ ((0b1)<< (0)); // disable the peripheral to set the configurtion
				I2C_1->CR1 &=~ ((0b1)<< (15));
			//I2C_1->CR1 &=~ ((0b1)<< (1)); // I2C mode 
		    I2C_1->CR2 &=~ ((0b111111)<< (0));   I2C_1->CR2 |= (FREQ); // frequency seection 
			I2C_1->CCR &=~ ((0b1)<< (15));       I2C_1->CCR |= ((MODE)<< (15)); // select the master mode 
		    I2C_1->CCR &=~((0b1)<< (14));        I2C_1->CCR |=((DUTY)<< (14)); // duty cycle 	
		    I2C_1->CR1 &=~ ((0b1)<< (7));        I2C_1->CR1 |= ((CLOCK_STRETCHING)<< (7)); // CLOCK_STRETCHING ENABLED OR NOT AS IN CONFIG FILE  
		    I2C_1->CR1 &=~ ((0b1)<< (6));        I2C_1->CR1 |= ((GENERAL_CALL)<< (6)); // GENERAL CALL ENABLE OR NOT
			I2C_1->CCR &=~ ((0xFFF)<< (0));      I2C_1->CCR |= ((CLK)<< (0)); // clock control configurtion 
			I2C_1->TRISE &=~ ((0b111111)<< (0)); I2C_1->TRISE |= ((RISE_TIME)<< (0)); // set rise time 
			I2C_1->CR1 |= ((0b1)<< (0)); // enable the peripheral to start 
	    break ;		
				
		case 1 :
		    RCC_voidEnableClock ( RCC_APB1 , 22 ); // enable peripheral clock
            I2C_2->CR1 &=~ ((0b1)<< (0)); // disable the peripheral to set the configurtion
			I2C_2->CR1 &=~ ((0b1)<< (1)); // I2C mode 
		    I2C_2->CR2 &=~ ((0b111111)<< (0));   I2C_2->CR2 |= (FREQ); // frequency seection 
			I2C_2->CCR &=~ ((0b1)<< (15));       I2C_2->CCR |= ((MODE)<< (15)); // select the master mode 
		    I2C_2->CCR &=~((0b1)<< (14));        I2C_2->CCR |=((DUTY)<< (14)); // duty cycle 	
		    I2C_2->CR1 &=~ ((0b1)<< (7));        I2C_2->CR1 |= ((CLOCK_STRETCHING)<< (7)); // CLOCK_STRETCHING ENABLED OR NOT AS IN CONFIG FILE  
		    I2C_2->CR1 &=~ ((0b1)<< (6));        I2C_2->CR1 |= ((GENERAL_CALL)<< (6)); // GENERAL CALL ENABLE OR NOT
			I2C_2->CCR &=~ ((0xFFF)<< (0));      I2C_2->CCR |= ((CLK)<< (0)); // clock control configurtion 
			I2C_2->TRISE &=~ ((0b111111)<< (0)); I2C_2->TRISE |= ((RISE_TIME)<< (0)); // set rise time 
			I2C_2->CR1 |= ((0b1)<< (0)); // enable the peripheral to start 
	    break ;
		
		case 2 :
		    RCC_voidEnableClock ( RCC_APB1 , 23 ); // enable peripheral clock 
            I2C_3->CR1 &=~ ((0b1)<< (0)); // disable the peripheral to set the configurtion
			I2C_3->CR1 &=~ ((0b1)<< (1)); // I2C mode 
		    I2C_3->CR2 &=~ ((0b111111)<< (0));   I2C_3->CR2 |= (FREQ); // frequency seection 
			I2C_3->CCR &=~ ((0b1)<< (15));       I2C_3->CCR |= ((MODE)<< (15)); // select the master mode 
		    I2C_3->CCR &=~((0b1)<< (14));        I2C_3->CCR |=((DUTY)<< (14)); // duty cycle 	
		    I2C_3->CR1 &=~ ((0b1)<< (7));        I2C_3->CR1 |= ((CLOCK_STRETCHING)<< (7)); // CLOCK_STRETCHING ENABLED OR NOT AS IN CONFIG FILE  
		    I2C_3->CR1 &=~ ((0b1)<< (6));        I2C_3->CR1 |= ((GENERAL_CALL)<< (6)); // GENERAL CALL ENABLE OR NOT
			I2C_3->CCR &=~ ((0xFFF)<< (0));      I2C_3->CCR |= ((CLK)<< (0)); // clock control configurtion 
			I2C_3->TRISE &=~ ((0b111111)<< (0)); I2C_3->TRISE |= ((RISE_TIME)<< (0)); // set rise time 
			I2C_3->CR1 |= ((0b1)<< (0)); // enable the peripheral to start 
	    break ;	
	}
}

				

void MI2C_voidSMbus_Request(void)
{
		
    RCC_voidEnableClock ( RCC_APB1 , 22 ); // enable peripheral clock
	I2C_2->CR1 &=~ ((0b1)<< (0)); // disable the peripheral to set the configurtion
	I2C_2->CR1 |= ((0b1)<< (1)); // SMBUS mode 

    I2C_2->CR2 &=~ ((0b111111)<< (0));   I2C_2->CR2 |= (FREQ_REQ); // frequency seection 
	I2C_2->CR1 &=~ ((0b1)<< (3));        I2C_2->CR1 |= ((SMBTYPE)<< (3)); // select the SM_TYPE mode 	
    I2C_2->CR1 &=~ ((0b1)<< (7));        I2C_2->CR1 |= ((CLOCK_STRETCHING)<< (7)); // CLOCK_STRETCHING ENABLED OR NOT AS IN CONFIG FILE  
	I2C_2->CCR &=~ ((0xFFF)<< (0));      I2C_2->CCR |= ((CCR_REQ)<< (0)); // clock control configurtion 
	I2C_2->TRISE &=~ ((0b111111)<< (0)); I2C_2->TRISE |= ((RISE_TIME_SM)<< (0)); // set rise time 
	I2C_2->CR1 |= ((0b1)<< (0)); // enable the peripheral to start 

}


void MI2C_voidSMbus_Mode(u8 Copy_u8I2C )
{
	switch(Copy_u8I2C)
    {
        case I2C1 :
		    RCC_voidEnableClock ( RCC_APB1 , 21 ); // enable peripheral clock
			I2C_1->CR1 &=~ ((0b1)<< (0)); // disable the peripheral to set the configurtion
			I2C_1->CR1 |= ((0b1)<< (1)); // SMBUS mode 
 
		    I2C_1->CR2 &=~ ((0b111111)<< (0));   I2C_1->CR2 |= (FREQ); // frequency selection 
			I2C_1->CR1 &=~ ((0b1)<< (3));        I2C_1->CR1 |= ((SMBTYPE)<< (3)); // select the SM_TYPE mode 
			I2C_1->CR1 &=~ ((0b1)<< (5));        I2C_1->CR1 |= ((ENPEC)<< (5)); // PEC CONFIG 
			I2C_1->CR1 &=~ ((0b1)<< (12));       I2C_1->CR1 |= ((PEC)<< (12)); // PEC TRANSFER 
			I2C_1->CR1 &=~ ((0b1)<< (4));        I2C_1->CR1 |= ((ENARP)<< (4)); // ARP enable
			I2C_1->CR1 &=~ ((0b1)<< (13));       I2C_1->CR1 |= ((ALERT)<< (13)); // SMbus ALERT 
		    I2C_1->CR1 &=~ ((0b1)<< (7));        I2C_1->CR1 |= ((CLOCK_STRETCHING)<< (7)); // CLOCK_STRETCHING ENABLED OR NOT AS IN CONFIG FILE  
		    I2C_1->CR1 &=~ ((0b1)<< (6));        I2C_1->CR1 |= ((GENERAL_CALL)<< (6)); // GENERAL CALL ENABLE OR NOT
			I2C_1->CCR &=~ ((0xFFF)<< (0));      I2C_1->CCR |= ((CLK_SM)<< (0)); // clock control configurtion 
			I2C_1->TRISE &=~ ((0b111111)<< (0)); I2C_1->TRISE |= ((RISE_TIME_SM)<< (0)); // set rise time 
			I2C_1->CR1 |= ((0b1)<< (0)); // enable the peripheral to start 
	    break ;		
				
		case I2C2 :
		    RCC_voidEnableClock ( RCC_APB1 , 22 ); // enable peripheral clock
			I2C_2->CR1 &=~ ((0b1)<< (0)); // disable the peripheral to set the configurtion
			I2C_2->CR1 |= ((0b1)<< (1)); // SMBUS mode 
 
		    I2C_2->CR2 &=~ ((0b111111)<< (0));   I2C_2->CR2 |= (FREQ); // frequency seection 
			I2C_2->CR1 &=~ ((0b1)<< (3));        I2C_2->CR1 |= ((SMBTYPE)<< (3)); // select the SM_TYPE mode 
			I2C_2->CR1 &=~ ((0b1)<< (5));        I2C_2->CR1 |= ((ENPEC)<< (5)); // PEC CONFIG 
			I2C_2->CR1 &=~ ((0b1)<< (12));       I2C_2->CR1 |= ((PEC)<< (12)); // PEC TRANSFER 
			I2C_2->CR1 &=~ ((0b1)<< (4));        I2C_2->CR1 |= ((ENARP)<< (4)); // ARP enable
			I2C_2->CR1 &=~ ((0b1)<< (13));       I2C_2->CR1 |= ((ALERT)<< (13)); // SMbus ALERT 
		    I2C_2->CR1 &=~ ((0b1)<< (7));        I2C_2->CR1 |= ((CLOCK_STRETCHING)<< (7)); // CLOCK_STRETCHING ENABLED OR NOT AS IN CONFIG FILE  
		    I2C_2->CR1 &=~ ((0b1)<< (6));        I2C_2->CR1 |= ((GENERAL_CALL)<< (6)); // GENERAL CALL ENABLE OR NOT
			I2C_2->CCR &=~ ((0xFFF)<< (0));      I2C_2->CCR |= ((CLK_SM)<< (0)); // clock control configurtion 
			I2C_2->TRISE &=~ ((0b111111)<< (0)); I2C_2->TRISE |= ((RISE_TIME_SM)<< (0)); // set rise time 
			I2C_2->CR1 |= ((0b1)<< (0)); // enable the peripheral to start 
	    break ;
		
		case I2C3 :
		    RCC_voidEnableClock ( RCC_APB1 , 23 ); // enable peripheral clock 
			I2C_3->CR1 &=~ ((0b1)<< (0)); // disable the peripheral to set the configurtion
			I2C_3->CR1 |= ((0b1)<< (1)); // SMBUS mode 
 
		    I2C_3->CR2 &=~ ((0b111111)<< (0));   I2C_3->CR2 |= (FREQ); // frequency seection 
			I2C_3->CR1 &=~ ((0b1)<< (3));        I2C_3->CR1 |= ((SMBTYPE)<< (3)); // select the SM_TYPE mode 
			I2C_3->CR1 &=~ ((0b1)<< (5));        I2C_3->CR1 |= ((ENPEC)<< (5)); // PEC CONFIG 
			I2C_3->CR1 &=~ ((0b1)<< (12));       I2C_3->CR1 |= ((PEC)<< (12)); // PEC TRANSFER 
			I2C_3->CR1 &=~ ((0b1)<< (4));        I2C_3->CR1 |= ((ENARP)<< (4)); // ARP enable
			I2C_3->CR1 &=~ ((0b1)<< (13));       I2C_3->CR1 |= ((ALERT)<< (13)); // SMbus ALERT 
		    I2C_3->CR1 &=~ ((0b1)<< (7));        I2C_3->CR1 |= ((CLOCK_STRETCHING)<< (7)); // CLOCK_STRETCHING ENABLED OR NOT AS IN CONFIG FILE  
		    I2C_3->CR1 &=~ ((0b1)<< (6));        I2C_3->CR1 |= ((GENERAL_CALL)<< (6)); // GENERAL CALL ENABLE OR NOT
			I2C_3->CCR &=~ ((0xFFF)<< (0));      I2C_3->CCR |= ((CLK_SM)<< (0)); // clock control configurtion 
			I2C_3->TRISE &=~ ((0b111111)<< (0)); I2C_3->TRISE |= ((RISE_TIME_SM)<< (0)); // set rise time 
			I2C_3->CR1 |= ((0b1)<< (0)); // enable the peripheral to start 
	    break ;	
	}
}






void MI2C_voidEnableDmaRequest(u8 Copy_u8I2C)
{
		switch(Copy_u8I2C)
    {
    case 0 :
        I2C_1->CR2 &=~((0b1)<< (10));  //Disable Buffer interrupt enable 
        I2C_1->CR2 |=((0b1)<< (11));   //DMA requests enable
	    break ;
		
	case 1 :
        I2C_2->CR2 &=~((0b1)<< (10));  //Disable Buffer interrupt enable 
        I2C_2->CR2 |=((0b1)<< (11));   //DMA requests enable
	    break ;
		
	case 2 :
        I2C_3->CR2 &=~((0b1)<< (10));  //Disable Buffer interrupt enable 
        I2C_3->CR2 |=((0b1)<< (11));   //DMA requests enable
	    break ;		
	}
}


void MI2C_voidDmaLastTransfer(u8 Copy_u8I2C)
{		switch(Copy_u8I2C)
    {
        case 0 :
	    I2C_1->CR2 |=((0b1)<< (12));   // DMA last transfer 
	    break ;
        
		case 1 :
	    I2C_2->CR2 |=((0b1)<< (12));   // DMA last transfer 
	    break ;
        
		case 2 :
	    I2C_3->CR2 |=((0b1)<< (12));   // DMA last transfer 
	    break ;
	}
}


void MI2C_voidInterruptEnable( u8 Copy_u8I2C , u8 Copy_u8Int)
{	switch(Copy_u8I2C)
    {
        case I2C1 :
	 	I2C_1->CR2 |=((0b1)<< (Copy_u8Int)); 
	    break ;

        case I2C2 :
	 	I2C_2->CR2 |=((0b1)<< (Copy_u8Int)); 
	    break ;

        case I2C3 :
	 	I2C_3->CR2 |=((0b1)<< (Copy_u8Int)); 
	    break ;
    }
}



void MI2C_voidInterruptDisable( u8 Copy_u8I2C , u8 Copy_u8Int)
{   
    switch(Copy_u8I2C)
    {
        case I2C1 :
	 	I2C_1->CR2 &=~((0b1)<< (Copy_u8Int)); 
	    break ;
        
		case I2C2 :
	 	I2C_2->CR2 &=~((0b1)<< (Copy_u8Int)); 
	    break ;

        case I2C3 :
	 	I2C_3->CR2 &=~((0b1)<< (Copy_u8Int)); 
	    break ;
		}
}



void MI2C_voidSlaveAddressSetting1(u8 Copy_u8I2C)
{
    switch(Copy_u8I2C)
    {
        case I2C1 :
	 	I2C_1->OAR1 = OWN_ADD_1 ; 
	    break ;

        case I2C2 :
	 	I2C_2->OAR1 = OWN_ADD_1 ; 
	    break ;

        case I2C3 :
	 	I2C_3->OAR1 = OWN_ADD_1 ; 
	    break ;
	}
}

/*
void MI2C_voidEnableDualAdd(u8 Copy_u8I2C)
{
    switch(Copy_u8I2C)
    {
        case I2C1 :
	 	I2C_1->OAR2 = OWN_ADD_2 ; 
		I2C_1->OAR2 |= 1 ;
	    break ;

        case I2C2 :
	 	I2C_2->OAR2 = OWN_ADD_2 ; 
        case I2C3 :
	 	I2C_3->OAR2 = OWN_ADD_2 ; 
    }
}
*/

void MI2C_voidSlaveTransmitter(u8 Copy_u8I2C )
{
	switch(Copy_u8I2C)
    {
        case I2C1 :
        while((GET_BIT( I2C_1->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware		
        while((GET_BIT( I2C_1->SR1  , ADDR_BIT ))==0){}// slave address is the sama as the own address 1 
	    while((GET_BIT( I2C_1->SR2 , TRA ))==0){}//Do Nothing till TRA (slave detected as transmitter) is SET by hardware
	    break ;
        
		case I2C2 :
        while((GET_BIT( I2C_2->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware		
        while((GET_BIT( I2C_2->SR1  , ADDR_BIT ))==0){}// slave address is the sama as the own address 1 
	    while((GET_BIT( I2C_2->SR2 , TRA ))==0){}//Do Nothing till TRA (slave detected as transmitter) is SET by hardware
	    break ;
        
		case I2C3 :
        while((GET_BIT( I2C_3->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware		
        while((GET_BIT( I2C_3->SR1  , ADDR_BIT ))==0){}// slave address is the sama as the own address 1 
	    while((GET_BIT( I2C_3->SR2 , TRA ))==0){}//Do Nothing till TRA (slave detected as transmitter) is SET by hardware
	    break ;     	
	}	
}


void MI2C_voidSlaveReciver(u8 Copy_u8I2C )
{
	switch(Copy_u8I2C)
    {
        case I2C1 :
        while((GET_BIT( I2C_1->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware		
        while((GET_BIT( I2C_1->SR1  , ADDR_BIT ))==0){}// slave address is the sama as the own address 1 
	    while((GET_BIT( I2C_1->SR2 , TRA ))==1){}//Do Nothing till TRA (slave detected as transmitter) is SET by hardware
	    break ;
        
		case I2C2 :
        while((GET_BIT( I2C_2->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware		
        while((GET_BIT( I2C_2->SR1  , ADDR_BIT ))==0){}// slave address is the sama as the own address 1 
	    while((GET_BIT( I2C_2->SR2 , TRA ))==1){}//Do Nothing till TRA (slave detected as transmitter) is SET by hardware
	    break ;
        
		case I2C3 :
        while((GET_BIT( I2C_3->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware		
        while((GET_BIT( I2C_3->SR1  , ADDR_BIT ))==0){}// slave address is the sama as the own address 1 
	    while((GET_BIT( I2C_3->SR2 , TRA ))==1){}//Do Nothing till TRA (slave detected as transmitter) is SET by hardware
	    break ;     	
	}	
}


void MI2C_voidSlaveTransmitterFinishing(u8 Copy_u8I2C)
{
	switch(Copy_u8I2C)
    {     
    	case I2C1 :
		while((GET_BIT( I2C_1->SR1 , TxE_BIT ))==0){}//Do Nothing till TXE BIT is SET by hardware
		while((GET_BIT( I2C_1->SR1 , BTF_BIT ))==0){}//Do Nothing till BTF BIT is SET by hardware
        while((GET_BIT( I2C_1->SR1 , AF_BIT ))==0){}//Do Nothing till ACKNOWLEDGE FAILURE BIT is SET by hardware	
		CLR_BIT(I2C_1->SR1 , BTF_BIT); // CLEAR BTF 
		CLR_BIT(I2C_1->SR1 , AF_BIT); // CLEAR AF TO RELEASE CLOCK LINE 
	    break ;
		
		case I2C2 :
		while((GET_BIT( I2C_2->SR1 , TxE_BIT ))==0){}//Do Nothing till TXE BIT is SET by hardware
		while((GET_BIT( I2C_2->SR1 , BTF_BIT ))==0){}//Do Nothing till BTF BIT is SET by hardware
        while((GET_BIT( I2C_2->SR1 , AF_BIT ))==0){}//Do Nothing till ACKNOWLEDGE FAILURE BIT is SET by hardware	
		CLR_BIT(I2C_2->SR1 , BTF_BIT); // CLEAR BTF 
		CLR_BIT(I2C_2->SR1 , AF_BIT); // CLEAR AF TO RELEASE CLOCK LINE 
	    break ;
		
		case I2C3 :
		while((GET_BIT( I2C_3->SR1 , TxE_BIT ))==0){}//Do Nothing till TXE BIT is SET by hardware
		while((GET_BIT( I2C_3->SR1 , BTF_BIT ))==0){}//Do Nothing till BTF BIT is SET by hardware
        while((GET_BIT( I2C_3->SR1 , AF_BIT ))==0){}//Do Nothing till ACKNOWLEDGE FAILURE BIT is SET by hardware	
		CLR_BIT(I2C_3->SR1 , BTF_BIT); // CLEAR BTF 
		CLR_BIT(I2C_3->SR1 , AF_BIT); // CLEAR AF TO RELEASE CLOCK LINE 
	    break ;
	}
}    

void MI2C_voidSlaveRecieverFinishing(u8 Copy_u8I2C)
{
	switch(Copy_u8I2C)
    {     
    	case I2C1 :
        while((GET_BIT( I2C_1->SR1 , AF_BIT ))==0){}//Do Nothing till ACKNOWLEDGE FAILURE BIT is SET by hardware	
		CLR_BIT(I2C_1->SR1 , AF_BIT); // CLEAR AF TO RELEASE CLOCK LINE 
	    break ;
        
		case I2C2 :
        while((GET_BIT( I2C_2->SR1 , AF_BIT ))==0){}//Do Nothing till ACKNOWLEDGE FAILURE BIT is SET by hardware	
		CLR_BIT(I2C_2->SR1 , AF_BIT); // CLEAR AF TO RELEASE CLOCK LINE 
	    break ;
		
        case I2C3 :
        while((GET_BIT( I2C_3->SR1 , AF_BIT ))==0){}//Do Nothing till ACKNOWLEDGE FAILURE BIT is SET by hardware	
		CLR_BIT(I2C_3->SR1 , AF_BIT); // CLEAR AF TO RELEASE CLOCK LINE 
	    break ;
		}
}






void MI2C_voidMasterTransmitterSpecial_7bit(u8 Copy_u8I2C , u8 Copy_u8SlaveAddress, u8 *ARRAY_DATA )
{
	switch(Copy_u8I2C)
    {
        case I2C1 :
		SET_BIT(I2C_1->CR1,ACK_BIT) ; // mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
		        SET_BIT(I2C_1->CR1,START) ; //  start generation
	            while((GET_BIT( I2C_1->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware
				(void)I2C_1->SR1; 
				I2C_1->DR = ((Copy_u8SlaveAddress)<< (1)); // SLAVE ADDRESS IN DR with WRITE BIT  
                while((GET_BIT( I2C_1->SR1  , ADDR_BIT ))==0){}//Do Nothing till ADDR BIT is SET by hardware   
                
									I2C_1->DR = ARRAY_DATA[0];									
               for(int v;v<=110;v++){}
									I2C_1->DR = ARRAY_DATA[1];
							for(int v;v<=110;v++){}
	            MI2C_voidGetReady(I2C1);
             	MI2C_voidI2c1_MasterTransmitterFinishing();		
        break;
        case I2C2 :
		//SET_BIT(I2C_2->CR1,ACK_BIT) ; // mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
		        SET_BIT(I2C_2->CR1,START) ; //  start generation
	            while((GET_BIT( I2C_2->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware
				(void)I2C_2->SR1; 
				I2C_2->DR = ((Copy_u8SlaveAddress)<< (1)); // SLAVE ADDRESS IN DR with WRITE BIT  
                while((GET_BIT( I2C_2->SR1  , ADDR_BIT ))==0){}//Do Nothing till ADDR BIT is SET by hardware   
                I2C_2->DR = ARRAY_DATA[0];
	            MI2C_voidGetReady(I2C2);
             	MI2C_voidI2c2_MasterTransmitterFinishing();		


	    break ;
	}
}

void MI2C_voidReInit(void){
	I2C_1->CR1 &=~ ((0b1)<< (0)); // disable the peripheral to set the configurtion
				I2C_1->CR1 &=~ ((0b1)<< (15));
			//I2C_1->CR1 &=~ ((0b1)<< (1)); // I2C mode 
		    I2C_1->CR2 &=~ ((0b111111)<< (0));   I2C_1->CR2 |= (FREQ); // frequency seection 
			I2C_1->CCR &=~ ((0b1)<< (15));       I2C_1->CCR |= ((MODE)<< (15)); // select the master mode 
		    I2C_1->CCR &=~((0b1)<< (14));        I2C_1->CCR |=((DUTY)<< (14)); // duty cycle 	
		    I2C_1->CR1 &=~ ((0b1)<< (7));        I2C_1->CR1 |= ((CLOCK_STRETCHING)<< (7)); // CLOCK_STRETCHING ENABLED OR NOT AS IN CONFIG FILE  
		    I2C_1->CR1 &=~ ((0b1)<< (6));        I2C_1->CR1 |= ((GENERAL_CALL)<< (6)); // GENERAL CALL ENABLE OR NOT
			I2C_1->CCR &=~ ((0xFFF)<< (0));      I2C_1->CCR |= ((CLK)<< (0)); // clock control configurtion 
			I2C_1->TRISE &=~ ((0b111111)<< (0)); I2C_1->TRISE |= ((RISE_TIME)<< (0)); // set rise time 
			I2C_1->CR1 |= ((0b1)<< (0)); // enable the peripheral to start 
	//MI2C_voidInit( I2C1 );
  MI2C_voidEnableDmaRequest(I2C1);
  MI2C_voidDmaLastTransfer(I2C1);
	//SET_BIT(I2C_1->CR1,STOP) ;
}

void MI2C_voidBusy(void){
 while((GET_BIT( I2C_1->SR2 , 1 ))==1){
				GPIOB_CRL |=(0xFF000000);
				 SET_BIT(I2C_1->CR1,15) ;
 }
 }

void MI2C_voidMasterTransmitter_7bit(u8 Copy_u8I2C , u16 Copy_u16SlaveAddress)
{
	switch(Copy_u8I2C)
    {
        case I2C1 :			
				//SET_BIT(I2C_1->CR1,ACK_BIT) ; // mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
   	SET_BIT(I2C_1->CR1,START) ; //  start generation
			
 /* while((GET_BIT( I2C_1->SR1 , 8 ))==1){SET_BIT(I2C_1->CR1,15) ;MI2C_voidInit( I2C1 );
  MI2C_voidEnableDmaRequest(I2C1);
  MI2C_voidDmaLastTransfer(I2C1);
	SET_BIT(I2C_1->CR1,START) ; }	*/         
  while((GET_BIT( I2C_1->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware
				
				(void)I2C_1->SR1; 
				I2C_1->DR = ((Copy_u16SlaveAddress)<< (1)); // SLAVE ADDRESS IN DR with WRITE BIT  
//		SET_BIT(I2C_1->CR1,9) ;  
 //   MSTK_void_SysTick_Delay(100);
                while((GET_BIT( I2C_1->SR1  , ADDR_BIT ))==0){}//Do Nothing till ADDR BIT is SET by hardware  
									
	    break ;
		
        case I2C2 :
		//SET_BIT(I2C_2->CR1,ACK_BIT) ; // mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
		        SET_BIT(I2C_2->CR1,START) ; //  start generation
	            while((GET_BIT( I2C_2->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware
				(void)I2C_2->SR1; 
				I2C_2->DR = ((Copy_u16SlaveAddress)<< (1)); // SLAVE ADDRESS IN DR with WRITE BIT  
                while((GET_BIT( I2C_2->SR1  , ADDR_BIT ))==0){}//Do Nothing till ADDR BIT is SET by hardware   
	    break ;
		
        case I2C3 :
	//	SET_BIT(I2C_3->CR1,ACK_BIT) ; // mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
		        SET_BIT(I2C_3->CR1,START) ; //  start generation
	            while((GET_BIT( I2C_3->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware
				(void)I2C_3->SR1; 
				I2C_3->DR = ((Copy_u16SlaveAddress)<< (1)); // SLAVE ADDRESS IN DR with WRITE BIT  
               while((GET_BIT( I2C_3->SR1  , ADDR_BIT ))==0){}//Do Nothing till ADDR BIT is SET by hardware   
	 //   break ;
	}			
}



void MI2C_voidMasterTransmitter_10bit(u8 Copy_u8I2C , u16 Copy_u16SlaveAddress)
{
	switch(Copy_u8I2C)
    {
        case I2C1 :
		//SET_BIT(I2C_1->CR1,ACK_BIT) ;
		        SET_BIT(I2C_1->CR1,START) ; //  start generation
	            while((GET_BIT( I2C_1->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware
				(void)I2C_1->SR1;
	
					I2C_1->DR =(((Copy_u16SlaveAddress>>7)&(0x00F6))|(0b1111<<4)); // HEADER WITH WRITE BIT
					//set the most significant 2 bits of slave address beside the header with WRITE bit 
					while((GET_BIT( I2C_1->SR1  , ADD10_BIT ))==0){}// Master has sent first address byte (header)
					(void)I2C_1->SR1; // READ SR1
					while((GET_BIT( I2C_1->SR1 , TxE_BIT ))==0){}//Do Nothing till TxE (DATA REG IS EMPTY) BIT is SET by hardware
					I2C_1->DR =((Copy_u16SlaveAddress)&(0x00FF)); // WRITE 2ND BYTE OF ADDRESS IN DR  					
				
				while((GET_BIT( I2C_1->SR1  , ADDR_BIT ))==0){}//Do Nothing till ADDR BIT is SET by hardware   
	    break ;
		
        case I2C2 :
		//SET_BIT(I2C_2->CR1,ACK_BIT) ;
		        SET_BIT(I2C_2->CR1,START) ; //  start generation
	            while((GET_BIT( I2C_2->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware
				(void)I2C_2->SR1;
	
					I2C_2->DR =(((Copy_u16SlaveAddress>>7)&(0x00F6))|(0b1111<<4)); // HEADER WITH WRITE BIT
					//set the most significant 2 bits of slave address beside the header with WRITE bit 
					while((GET_BIT( I2C_2->SR1  , ADD10_BIT ))==0){}// Master has sent first address byte (header)
					(void)I2C_2->SR1; // READ SR1
					while((GET_BIT( I2C_2->SR1 , TxE_BIT ))==0){}//Do Nothing till TxE (DATA REG IS EMPTY) BIT is SET by hardware
					I2C_2->DR =((Copy_u16SlaveAddress)&(0x00FF)); // WRITE 2ND BYTE OF ADDRESS IN DR  					
				
				while((GET_BIT( I2C_2->SR1  , ADDR_BIT ))==0){}//Do Nothing till ADDR BIT is SET by hardware   
	    break ;
		
        case I2C3 :
		//SET_BIT(I2C_3->CR1,ACK_BIT) ;
		        SET_BIT(I2C_3->CR1,START) ; //  start generation
	            while((GET_BIT( I2C_3->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware
				(void)I2C_3->SR1;
	
					I2C_3->DR =(((Copy_u16SlaveAddress>>7)&(0x00F6))|(0b1111<<4)); // HEADER WITH WRITE BIT
					//set the most significant 2 bits of slave address beside the header with WRITE bit 
					while((GET_BIT( I2C_3->SR1  , ADD10_BIT ))==0){}// Master has sent first address byte (header)
					(void)I2C_3->SR1; // READ SR1
					while((GET_BIT( I2C_3->SR1 , TxE_BIT ))==0){}//Do Nothing till TxE (DATA REG IS EMPTY) BIT is SET by hardware
					I2C_3->DR =((Copy_u16SlaveAddress)&(0x00FF)); // WRITE 2ND BYTE OF ADDRESS IN DR  					
				//I2C_3->DR =(Copy_u16SlaveAddress); // WRITE 2ND BYTE OF ADDRESS IN DR  	
				while((GET_BIT( I2C_3->SR1  , ADDR_BIT ))==0){}//Do Nothing till ADDR BIT is SET by hardware   
	    break ;
		
    }
}



void MI2C_voidSendRegisterAddress(u8 Copy_u8I2C , u8 Copy_u8NumberOfData ,u8 Copy_u8RegAddress)
{
	switch(Copy_u8I2C)
    {
        case I2C1 :
		(void)I2C_1->SR1; (void)I2C_1->SR2;// reading SR1 & SR2 to CLEAR ADDR BIT 
		while((GET_BIT( I2C_1->SR1 , TxE_BIT ))==0){}//Do Nothing till TxE (DATA REG IS EMPTY) BIT is SET by hardware
		if (Copy_u8NumberOfData == 1)
				{
					SET_BIT(I2C_1->CR1,ACK_BIT) ; //ENABLE ACK IF MORE_THAN_ONE_BYTE WILL BE TRANSFER 
					I2C_1->DR = ((Copy_u8RegAddress)|(0x80)); // REGISTER ADDRESS IN DR 
				}
				else 
				{
					CLR_BIT(I2C_1->CR1,ACK_BIT) ;// DISABLE ACK IN CASE OF ONE BYTE
					I2C_1->DR = ((Copy_u8RegAddress));
				}
				while((GET_BIT( I2C_1->SR1 , BTF_BIT ))==0){}//Do Nothing till BYTE TRANSFER FINISHED BIT is SET by hardware
	    break ;
		
		case I2C2 :	
        (void)I2C_2->SR1; (void)I2C_2->SR2;// reading SR1 & SR2 to CLEAR ADDR BIT 
		while((GET_BIT( I2C_2->SR1 , TxE_BIT ))==0){}//Do Nothing till TxE (DATA REG IS EMPTY) BIT is SET by hardware
        if (Copy_u8NumberOfData == 1)
				{
					SET_BIT(I2C_2->CR1,ACK_BIT) ; //ENABLE ACK IF MORE_THAN_ONE_BYTE WILL BE TRANSFER 
					I2C_2->DR = ((Copy_u8RegAddress)|(0x80)); // REGISTER ADDRESS IN DR 
				}
				else 
				{
					CLR_BIT(I2C_2->CR1,ACK_BIT) ;// DISABLE ACK IN CASE OF ONE BYTE
					I2C_2->DR = ((Copy_u8RegAddress));
				}
				while((GET_BIT( I2C_2->SR1 , BTF_BIT ))==0){}//Do Nothing till BYTE TRANSFER FINISHED BIT is SET by hardware
	    break ;
		
        case I2C3 :
		(void)I2C_3->SR1; (void)I2C_3->SR2;// reading SR1 & SR2 to CLEAR ADDR BIT 
		while((GET_BIT( I2C_3->SR1 , TxE_BIT ))==0){}//Do Nothing till TxE (DATA REG IS EMPTY) BIT is SET by hardware
        if (Copy_u8NumberOfData == 1)
				{
					SET_BIT(I2C_3->CR1,ACK_BIT) ; //ENABLE ACK IF MORE_THAN_ONE_BYTE WILL BE TRANSFER 
					I2C_3->DR = ((Copy_u8RegAddress)|(0x80)); // REGISTER ADDRESS IN DR 
				}
				else 
				{
					CLR_BIT(I2C_3->CR1,ACK_BIT) ;// DISABLE ACK IN CASE OF ONE BYTE
					I2C_3->DR = ((Copy_u8RegAddress));
				}
				while((GET_BIT( I2C_3->SR1  , BTF_BIT ))==0){}//Do Nothing till BYTE TRANSFER FINISHED BIT is SET by hardware
	 //   break ;	
	}				
}



void MI2C_voidMasterRead_7bit(u8 Copy_u8I2C , u16 Copy_u16SlaveAddress )
{
	switch(Copy_u8I2C)
    {
        case I2C1 :
		        SET_BIT(I2C_1->CR1,START) ; //  restart generation
	            while((GET_BIT( I2C_1->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware
			    (void)I2C_1->SR1; 
						
			    I2C_1->DR = (((Copy_u16SlaveAddress)<< (1))|1); // SLAVE ADDRESS IN DR with READ BIT  				
    		    while((GET_BIT( I2C_1->SR1  , ADDR_BIT ))==0){}//Do Nothing till ADDR BIT is SET by hardware   
				// READING SR2 IS DELAYED , SO THE ADDR FALAG IS NOT CLEARED TILL THE DMA RECIEVER IS READY 
	    break ;
		
        case I2C2 :
		        SET_BIT(I2C_2->CR1,START) ; //  restart generation
	            while((GET_BIT( I2C_2->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware
			    (void)I2C_2->SR1; 
						
				I2C_2->DR = (((Copy_u16SlaveAddress)<< (1))|1); // SLAVE ADDRESS IN DR with READ BIT  				
				while((GET_BIT( I2C_2->SR1  , ADDR_BIT ))==0){}//Do Nothing till ADDR BIT is SET by hardware   
				// READING SR2 IS DELAYED , SO THE ADDR FALAG IS NOT CLEARED TILL THE DMA RECIEVER IS READY 
	    break ;
		
        case I2C3 :
		        SET_BIT(I2C_3->CR1,START) ; //  restart generation
	            while((GET_BIT( I2C_3->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware
			    (void)I2C_3->SR1; 
						
				I2C_3->DR = (((Copy_u16SlaveAddress)<< (1))|1); // SLAVE ADDRESS IN DR with READ BIT  				
				while((GET_BIT( I2C_3->SR1  , ADDR_BIT ))==0){}//Do Nothing till ADDR BIT is SET by hardware   
				// READING SR2 IS DELAYED , SO THE ADDR FALAG IS NOT CLEARED TILL THE DMA RECIEVER IS READY 
	    break ;
	}			
}


void MI2C_voidMasterRead_10bit(u8 Copy_u8I2C , u16 Copy_u16SlaveAddress )
{
	switch(Copy_u8I2C)
    {
        case I2C1 :
		        SET_BIT(I2C_1->CR1,START) ; //  restart generation
	            while((GET_BIT( I2C_1->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware
			    (void)I2C_1->SR1; 
						
				I2C_1->DR =(((Copy_u16SlaveAddress>>7)&(0x0006))|(0x00F1)); // HEADER WITH READ BIT									
				while((GET_BIT( I2C_1->SR1  , ADDR_BIT ))==0){}//Do Nothing till ADDR BIT is SET by hardware   
				// READING SR2 IS DELAYED , SO THE ADDR FALAG IS NOT CLEARED TILL THE DMA RECIEVER IS READY 
	    break ;
		
        case I2C2 :
		        SET_BIT(I2C_2->CR1,START) ; //  restart generation
	            while((GET_BIT( I2C_2->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware
			    (void)I2C_2->SR1; 
						
				I2C_2->DR =(((Copy_u16SlaveAddress>>7)&(0x0006))|(0x00F1)); // HEADER WITH READ BIT									
				while((GET_BIT( I2C_2->SR1  , ADDR_BIT ))==0){}//Do Nothing till ADDR BIT is SET by hardware   
				// READING SR2 IS DELAYED , SO THE ADDR FALAG IS NOT CLEARED TILL THE DMA RECIEVER IS READY 
	    break ;
		
        case I2C3 :
		        SET_BIT(I2C_3->CR1,START) ; //  restart generation
	            while((GET_BIT( I2C_3->SR1 , SB_BIT ))==0){}//Do Nothing till START BIT is SET by hardware
			    (void)I2C_3->SR1; 
						
				I2C_3->DR =(((Copy_u16SlaveAddress>>7)&(0x0006))|(0x00F1)); // HEADER WITH READ BIT									
				while((GET_BIT( I2C_3->SR1  , ADDR_BIT ))==0){}//Do Nothing till ADDR BIT is SET by hardware   
				// READING SR2 IS DELAYED , SO THE ADDR FALAG IS NOT CLEARED TILL THE DMA RECIEVER IS READY 
	    break ;


	}
}






void MI2C_voidI2c1_MasterTransmitterFinishing(void)
{
		while((GET_BIT( I2C_1->SR1 , TxE_BIT ))==0){}//Do Nothing till TxE (DATA REG IS EMPTY) BIT is SET by hardware
		while((GET_BIT( I2C_1->SR1 , BTF_BIT ))==0){}//Do Nothing till BTF (Byte transfer finished) BIT is SET by hardware
		SET_BIT(I2C_1->CR1,STOP) ;
}



void MI2C_voidI2c2_MasterTransmitterFinishing(void)
{
		while((GET_BIT( I2C_2->SR1 , TxE_BIT ))==0){}//Do Nothing till TxE (DATA REG IS EMPTY) BIT is SET by hardware
		while((GET_BIT( I2C_2->SR1 , BTF_BIT ))==0){}//Do Nothing till BTF (Byte transfer finished) BIT is SET by hardware
		SET_BIT(I2C_2->CR1,STOP) ;	
}


void MI2C_voidI2c3_MasterTransmitterFinishing(void)
{
		while((GET_BIT( I2C_3->SR1 , TxE_BIT ))==0){}//Do Nothing till TxE (DATA REG IS EMPTY) BIT is SET by hardware
		while((GET_BIT( I2C_3->SR1 , BTF_BIT ))==0){}//Do Nothing till BTF (Byte transfer finished) BIT is SET by hardware
		SET_BIT(I2C_3->CR1,STOP) ;
}



void MI2C_voidGetReady(u8 Copy_u8I2C )
{   switch(Copy_u8I2C)
    {
    case I2C1 :
        (void)I2C_1->SR1; (void)I2C_1->SR2;// reading SR1 & SR2 to CLEAR ADDR BIT  
    break ;
     
    case I2C2 :
        (void)I2C_2->SR1; (void)I2C_2->SR2;
	break ;
	
	case I2C3 :
        (void)I2C_3->SR1; (void)I2C_3->SR2;
	break ;    
	}
}


void MI2C_voidI2c1_MasterRecieverFinishing(void)
{
		CLR_BIT(I2C_1->CR1,ACK_FAILURE) ; // NOT ACKNOWLEDGE 
		SET_BIT(I2C_1->CR1,STOP) ;	
}


void MI2C_voidI2c2_MasterRecieverFinishing(void)
{
		CLR_BIT(I2C_2->CR1,ACK_FAILURE) ; // NOT ACKNOWLEDGE 
		SET_BIT(I2C_2->CR1,STOP) ;
}

void MI2C_voidI2c3_MasterRecieverFinishing(void)
{
		CLR_BIT(I2C_3->CR1,ACK_FAILURE) ; // NOT ACKNOWLEDGE 
		SET_BIT(I2C_3->CR1,STOP) ;
}
