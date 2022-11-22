/*********************************************************/
/*Author    : youstina                                   */
/*version   : v03*                                        */
/*date      : 20 FEB 2021                                */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "MDMA_private.h"
#include "MDMA_config.h"
#include "MDMA_interface.h"

#define NULL		(void * )0

static void (* DMA_CallBack_I2C3_RX)(void) = NULL ;
static void (* DMA_CallBack_I2C3_TX)(void) = NULL ;


static void (* DMA_CallBack_I2C2_RX)(void) = NULL ;
static void (* DMA_CallBack_I2C2_TX)(void) = NULL ;

void   MDMA_voidChannelInit(void)
{// as in config file 

    if (DMA == DMA1){ 
    /*Enable clock on DMA1 Peripheral*/
	RCC_voidEnableClock (RCC_AHB1, 21); }
    else if (DMA == DMA2) {
    /*Enable clock on DMA2 Peripheral*/
    RCC_voidEnableClock (RCC_AHB1, 22);} 
    else  /*error*/;	
	

    CLR_BIT(DMA -> Stream[STREAM_ID].SCR , EN );
    while(GET_BIT(DMA -> Stream[STREAM_ID].SCR  , EN)==1){}//Do Nothing till ENABLE BIT is CLEARED 
	DMA -> Stream[STREAM_ID].SCR &=~((0b111)<<25);DMA -> Stream[STREAM_ID].SCR |=(CHANNEL_ID<<25);  // select the channel as in config file	
	DMA -> Stream[STREAM_ID].SCR &=~((0b11)<<16); DMA -> Stream[STREAM_ID].SCR |=(PRIORITY_LEVEL<<16);  // set the priority as in config file
 	DMA -> Stream[STREAM_ID].SCR &=~(0b11<<11);   DMA -> Stream[STREAM_ID].SCR |=(PERIPHERAL_DATA_SIZE<<11);  // set the PERIPHERAL DATA SIZE as in config file 
 	DMA -> Stream[STREAM_ID].SCR &=~(0b11<<13);   DMA -> Stream[STREAM_ID].SCR |=(MEMORY_DATA_SIZE<<13);  // set the MEMORY DATA SIZE as in config file 
 	DMA -> Stream[STREAM_ID].SCR &=~(0b1<<10);    DMA -> Stream[STREAM_ID].SCR |=(MEMORY_INCREAMENT_MODE<<10);  // set the MEMORY INCREAMENT MODE as in config file 
 	DMA -> Stream[STREAM_ID].SCR &=~(0b1<<9);     DMA -> Stream[STREAM_ID].SCR |=(PERIPHERAL_INCREAMENT_MODE<<9);  // set the PERIPHERAL INCREAMENT MODE as in config file
	DMA -> Stream[STREAM_ID].SCR &=~(0b1<<8);     DMA -> Stream[STREAM_ID].SCR |=(CIRCULAR_MODE<<8);  // set the CIRCUILAR MODE as in config file
	DMA -> Stream[STREAM_ID].SCR &=~(0b11<<6);    DMA -> Stream[STREAM_ID].SCR |=(DATA_TRANSFER_DIRECTION<<6);  // select the DATA TRANSFER DIRECTION as in config file	
	DMA -> Stream[STREAM_ID].SCR &=~(30);  
	DMA -> Stream[STREAM_ID].SCR |=((TRANSFER_COMPLETE_INTERRUPT<<4)|(TRANSFER_ERROR_INTERRUPT<<2)|(HALF_TRANSFER_INTERRUPT<<3)|(DIRECT_MODE_ERROR_INTERRUPT<<1));  // set or clear the INTERRUPTS as in config file	


	DMA -> Stream[STREAM_ID].SFCR &=~(0b1<<2); DMA -> Stream[STREAM_ID].SFCR |=(DIRECT_MODE<<2);  // set DIRECT_MODE as in config file	
	
    	
}



void DMA_StartTransfer(u32* Copy_pu32PeripheralAddress, u32* Copy_pu32MemoryAddress, u16 Copy_u16BlockLength)
{// as in config file
/*in case of memory to memory source address is in peripheral address register  */
	DMA -> Stream[STREAM_ID].SNDTR =(Copy_u16BlockLength);  // set  number of data items to transfer 
	DMA -> Stream[STREAM_ID].SPAR =((u32)Copy_pu32PeripheralAddress);  // set  peripheral address 	
	DMA -> Stream[STREAM_ID].SM0AR =((u32)Copy_pu32MemoryAddress);  // set  memory address 	

	if (STREAM_ID <4){ 
	DMA -> LIFCR &=~ STREAM_MASK ; DMA -> LIFCR |= STREAM_MASK ;   // CLEAR THE INT FLAGS 
	}
	else if (STREAM_ID < 8){
	DMA -> HIFCR &=~ STREAM_MASK ; DMA -> HIFCR |= STREAM_MASK ;   // CLEAR THE INT FLAGS 
	}
	else 	/*error (" wrong operation!")*/
	
	
	SET_BIT(DMA -> Stream[STREAM_ID].SCR , EN );	
}

void DMA_SetConfig(u8 Copy_u8Dma , u8 Copy_u8Stream , u8 Copy_u8DataDirection , u8 Copy_u8MemDataSize , u8 Copy_u8PerDataSize , u8 Copy_u8MemInc , u8 Copy_u8PerInc)
{        /************** DMA ********/ 
	
	switch(Copy_u8Dma)
    {
        case 1 :
		  /*Enable clock on DMA1 Peripheral*/
    	RCC_voidEnableClock (RCC_AHB1, 21); 
		
		CLR_BIT(DMA1-> Stream[Copy_u8Stream].SCR , EN ); // CLEAR ENABLE BIT TO CONFIGURE 
	    while( GET_BIT(DMA1-> Stream[Copy_u8Stream].SCR , EN) == 1 ){}; // Wait Until DMA Disable
		 
 		  /*************** DATA DIRECTION *******************/
		DMA1-> Stream[Copy_u8Stream].SCR &=~(0b11<<6); DMA -> Stream[Copy_u8Stream].SCR |=(Copy_u8DataDirection<<6); 

          /****************** MEMORY & PERIPHERAL DATA SIZE ***********/
		DMA1-> Stream[Copy_u8Stream].SCR &=~(0b11<<13);  DMA1-> Stream[Copy_u8Stream].SCR |=(Copy_u8MemDataSize<<13); 
		DMA1-> Stream[Copy_u8Stream].SCR &=~(0b11<<11);  DMA1-> Stream[Copy_u8Stream].SCR |=(Copy_u8PerDataSize<<11); 

          /**************** PERIPHERAL INCREAMENT & MEMORY INCREAMENT ******************/
		DMA1-> Stream[Copy_u8Stream].SCR &=~(0b1<<10);  DMA1-> Stream[Copy_u8Stream].SCR |=(Copy_u8MemInc<<10); 
		DMA1-> Stream[Copy_u8Stream].SCR &=~(0b1<<9);   DMA1-> Stream[Copy_u8Stream].SCR |=(Copy_u8PerInc<<9); 
	   
break;	 
	 
		case 2 : 
		  /*Enable clock on DMA2 Peripheral*/
        RCC_voidEnableClock (RCC_AHB1, 22);  
	
		CLR_BIT(DMA2-> Stream[Copy_u8Stream].SCR , EN ); // CLEAR ENABLE BIT TO CONFIGURE 
	    while( GET_BIT(DMA2-> Stream[Copy_u8Stream].SCR , EN) == 1 ){}; // Wait Until DMA Disable
		 
 		  /*************** DATA DIRECTION *******************/
		DMA2-> Stream[Copy_u8Stream].SCR &=~(0b11<<6); DMA -> Stream[Copy_u8Stream].SCR |=(Copy_u8DataDirection<<6); 

          /****************** MEMORY & PERIPHERAL DATA SIZE ***********/
		DMA2-> Stream[Copy_u8Stream].SCR &=~(0b11<<13);  DMA2-> Stream[Copy_u8Stream].SCR |=(Copy_u8MemDataSize<<13); 
		DMA2-> Stream[Copy_u8Stream].SCR &=~(0b11<<11);  DMA2-> Stream[Copy_u8Stream].SCR |=(Copy_u8PerDataSize<<11); 

          /**************** PERIPHERAL INCREAMENT & MEMORY INCREAMENT ******************/
		DMA2-> Stream[Copy_u8Stream].SCR &=~(0b1<<10);  DMA2-> Stream[Copy_u8Stream].SCR |=(Copy_u8MemInc<<10); 
		DMA2-> Stream[Copy_u8Stream].SCR &=~(0b1<<9);   DMA2-> Stream[Copy_u8Stream].SCR |=(Copy_u8PerInc<<9); 
break;	   
	}	 
}// set in run time


/* DISABLE DMA */
void MDMA_VoidDMADisable( u8 Copy_u8Dma , u8 Copy_u8Stream )
{
	switch(Copy_u8Dma)
    {
        case 1 :
	    CLR_BIT(DMA1-> Stream[Copy_u8Stream].SCR , EN );
		break;
		case 2 :
	    CLR_BIT(DMA2-> Stream[Copy_u8Stream].SCR , EN );
		break;
	}	
}

/* ENABLE INTTERUPT */
void DMA_VoidInerruptEnable(u8 Copy_u8Dma , u8 Copy_u8Stream , u8 Copy_u8INTSource )
{
	switch(Copy_u8Dma)
    {
        case 1 :
	    SET_BIT( DMA1->Stream[Copy_u8Stream].SCR , Copy_u8INTSource );
		break;
		case 2 :
	    SET_BIT( DMA2->Stream[Copy_u8Stream].SCR , Copy_u8INTSource );
		break;
	}
}

/* SET ADDRESS OF SOURCE & DESTINATION */
/*in case of memory to memory source address is in peripheral address register  */
void DMA_VoidSetAddress(u8 Copy_u8Dma , u8 Copy_u8Stream , u32 * Copy_pu32PeripheralAddress , u32 * Copy_pu32MemoryAddress , u16 Copy_u16BlockLength )
{   
    switch(Copy_u8Dma)
    {
        case 1 :
        CLR_BIT(DMA1-> Stream[Copy_u8Stream].SCR , EN );
        while(GET_BIT(DMA1-> Stream[Copy_u8Stream].SCR  , EN)==1){}//Do Nothing till ENABLE BIT is CLEARED 
	    DMA1-> Stream[Copy_u8Stream].SNDTR =(Copy_u16BlockLength);  // set  number of data items to transfer 
	    DMA1-> Stream[Copy_u8Stream].SPAR =((u32)Copy_pu32PeripheralAddress);  // set  peripheral address 	
    	DMA1-> Stream[Copy_u8Stream].SM0AR =((u32)Copy_pu32MemoryAddress);  // set  memory address 	        
		break;
		
		case 2 :
        CLR_BIT(DMA2-> Stream[Copy_u8Stream].SCR , EN );
        while(GET_BIT(DMA2-> Stream[Copy_u8Stream].SCR  , EN)==1){}//Do Nothing till ENABLE BIT is CLEARED 
	    DMA2-> Stream[Copy_u8Stream].SNDTR =(Copy_u16BlockLength);  // set  number of data items to transfer 
	    DMA2-> Stream[Copy_u8Stream].SPAR =((u32)Copy_pu32PeripheralAddress);  // set  peripheral address 	
    	DMA2-> Stream[Copy_u8Stream].SM0AR =((u32)Copy_pu32MemoryAddress);  // set  memory address 	
		break;

    }
}

/* CLEAR FLAG OF INTTERUPT */
void DMA_VoidClearFlag(u8 Copy_u8Dma , u8 Copy_u8Stream , u8 Copy_u8Flag )
{	
    u8 intt=0 ;
    switch(Copy_u8Dma)
    {
        case 1 :
        if (Copy_u8Stream<4)
    	{
		intt = (16 * (Copy_u8Stream /2))+((Copy_u8Stream % 2)*6)+Copy_u8Flag ;
		SET_BIT( DMA1->LIFCR , intt );
	    }
        
		else if(Copy_u8Stream<8)
	    {
		Copy_u8Stream -=4 ;
		intt = (16 * (Copy_u8Stream /2))+((Copy_u8Stream % 2)*6)+Copy_u8Flag ;		
    	SET_BIT( DMA1->HIFCR , intt );	
    	}
	    break;
	    
		case 2 :
        if (Copy_u8Stream<4)
    	{
		intt = (16 * (Copy_u8Stream /2))+((Copy_u8Stream % 2)*6)+Copy_u8Flag ;
		SET_BIT( DMA2->LIFCR , intt );
	    }
        
		else if(Copy_u8Stream<8)
	    {
		Copy_u8Stream -=4 ;
		intt = (16 * (Copy_u8Stream /2))+((Copy_u8Stream % 2)*6)+Copy_u8Flag ;		
    	SET_BIT( DMA2->HIFCR , intt );	
    	}
		break;
	}
}


/* ENABLE DMA */
void DMA_VoidDMAEnable(u8 Copy_u8Dma , u8 Copy_u8Stream )
{
	 switch(Copy_u8Dma)
    {
        case 1 :
	    DMA_VoidClearFlag(1 , Copy_u8Stream , FEIF );
	    DMA_VoidClearFlag(1 , Copy_u8Stream , DMEIF );
    	DMA_VoidClearFlag(1 , Copy_u8Stream , TEIF );
	    DMA_VoidClearFlag(1 , Copy_u8Stream , HTIF );
	    DMA_VoidClearFlag(1 , Copy_u8Stream , TCIF );
		
    	SET_BIT(DMA1-> Stream[Copy_u8Stream].SCR , EN );	
		break;
		
		case 2 :
	    DMA_VoidClearFlag(2 , Copy_u8Stream , FEIF );
	    DMA_VoidClearFlag(2 , Copy_u8Stream , DMEIF );
    	DMA_VoidClearFlag(2 , Copy_u8Stream , TEIF );
	    DMA_VoidClearFlag(2 , Copy_u8Stream , HTIF );
	    DMA_VoidClearFlag(2 , Copy_u8Stream , TCIF );
		
    	SET_BIT(DMA2-> Stream[Copy_u8Stream].SCR , EN );	
		break;
    }
}


void DMA_VoidSelectChannel(u8 Copy_u8Dma ,u8 Copy_u8Stream , u8 Copy_u8Channel )
{
	switch(Copy_u8Dma)
    {
        case 1 :
	    CLR_BIT(DMA1-> Stream[Copy_u8Stream].SCR , EN );
        while(GET_BIT(DMA1-> Stream[Copy_u8Stream].SCR  , EN)==1){}//Do Nothing till ENABLE BIT is CLEARED 
	    DMA1-> Stream[Copy_u8Stream].SCR &=~(0b111<<25);   DMA1-> Stream[Copy_u8Stream].SCR |=(Copy_u8Channel<<25);  // select the channel 
		break;
		
        case 2 :		
	    CLR_BIT(DMA2-> Stream[Copy_u8Stream].SCR , EN );
        while(GET_BIT(DMA2-> Stream[Copy_u8Stream].SCR  , EN)==1){}//Do Nothing till ENABLE BIT is CLEARED 
	    DMA2-> Stream[Copy_u8Stream].SCR &=~(0b111<<25);   DMA2-> Stream[Copy_u8Stream].SCR |=(Copy_u8Channel<<25);  // select the channel 
		break;
	}
}

u8 DMA_u8GetFlag(u8 Copy_u8Dma , u8 Copy_u8Stream , u8 Copy_u8Flag )
{
// PLEASE NOTE THAT DMA IS DEFINED AS DMA1 OR DMA2 IN CONFIG FILE
	u8 LOC_u8Result = 0;
    u8 intt=0 ;
    switch(Copy_u8Dma)
    {
        case 1 :
        if (Copy_u8Stream<4)
    	{
		intt = (16 * (Copy_u8Stream /2))+((Copy_u8Stream % 2)*6)+Copy_u8Flag ;
    	LOC_u8Result = GET_BIT (DMA1->LISR , intt );
	    }

        else if(Copy_u8Stream<8)
	    {
		Copy_u8Stream -=4 ;
		intt = (16 * (Copy_u8Stream /2))+((Copy_u8Stream % 2)*6)+Copy_u8Flag ;		
	    LOC_u8Result = GET_BIT( DMA1->HISR ,intt );	
	    }
       
	    else  
	    { 
	       /*  return error  */
	    }
		break;
		
	    case 2 :
        if (Copy_u8Stream<4)
    	{
		intt = (16 * (Copy_u8Stream /2))+((Copy_u8Stream % 2)*6)+Copy_u8Flag ;
    	LOC_u8Result = GET_BIT (DMA2->LISR , intt );
	    }

        else if(Copy_u8Stream<8)
	    {
		Copy_u8Stream -=4 ;
		intt = (16 * (Copy_u8Stream /2))+((Copy_u8Stream % 2)*6)+Copy_u8Flag ;		
	    LOC_u8Result = GET_BIT( DMA2->HISR ,intt );	
	    }
       
	    else  
	    { 
	       /*  return error  */
	    }
		break;	   
	return LOC_u8Result ;
    }
}


void DMA_VoidConfigPriority(u8 Copy_u8Dma ,u8 Copy_u8Stream, u8 Copy_u8PeriorityLevel)
{
	switch(Copy_u8Dma)
    {
    case 1 :
	CLR_BIT(DMA1-> Stream[Copy_u8Stream].SCR , EN );
	while(GET_BIT(DMA1-> Stream[Copy_u8Stream].SCR  , EN)==1){}//Do Nothing till ENABLE BIT is CLEARED 
	DMA1-> Stream[Copy_u8Stream].SCR &=~(0b11<<16);   DMA1-> Stream[Copy_u8Stream].SCR |=(Copy_u8PeriorityLevel<<16);
	break;

    case 2 :
	CLR_BIT(DMA2-> Stream[Copy_u8Stream].SCR , EN );
	while(GET_BIT(DMA2-> Stream[Copy_u8Stream].SCR  , EN)==1){}//Do Nothing till ENABLE BIT is CLEARED 
	DMA2-> Stream[Copy_u8Stream].SCR &=~(0b11<<16);   DMA2-> Stream[Copy_u8Stream].SCR |=(Copy_u8PeriorityLevel<<16);
	break;
	}
}


void DMA_VoidSetCircularMode(u8 Copy_u8Dma ,u8 Copy_u8Stream)
{
	switch(Copy_u8Dma)
    {
    case 1 :
	SET_BIT(DMA1-> Stream[Copy_u8Stream].SCR , CIRC );//enable circular mode 
	break;
    
	case 2 :
	SET_BIT(DMA2-> Stream[Copy_u8Stream].SCR , CIRC );//enable circular mode 
   	break;
	}
}

void DMA_VoidConfigBurstTransfer(u8 Copy_u8Dma ,u8 Copy_u8Stream , u8 Copy_u8PerBurst, u8 Copy_u8MemBurst)
{
	switch(Copy_u8Dma)
    {
    case 1 :
    CLR_BIT(DMA1-> Stream[Copy_u8Stream].SCR , EN );
    while(GET_BIT(DMA1-> Stream[Copy_u8Stream].SCR  , EN)==1){}//Do Nothing till ENABLE BIT is CLEARED 
	DMA1-> Stream[Copy_u8Stream].SCR &=~(0b11<<MBURST); DMA1-> Stream[Copy_u8Stream].SCR |=(Copy_u8MemBurst<<MBURST);// for MBURST 
	DMA1-> Stream[Copy_u8Stream].SCR &=~(0b11<<PBURST); DMA1-> Stream[Copy_u8Stream].SCR |=(Copy_u8PerBurst<<PBURST);//for PBURST
	break;
	
    case 2 :
    CLR_BIT(DMA2-> Stream[Copy_u8Stream].SCR , EN );
    while(GET_BIT(DMA2-> Stream[Copy_u8Stream].SCR  , EN)==1){}//Do Nothing till ENABLE BIT is CLEARED 
	DMA2-> Stream[Copy_u8Stream].SCR &=~(0b11<<MBURST); DMA2-> Stream[Copy_u8Stream].SCR |=(Copy_u8MemBurst<<MBURST);// for MBURST 
	DMA2-> Stream[Copy_u8Stream].SCR &=~(0b11<<PBURST); DMA2-> Stream[Copy_u8Stream].SCR |=(Copy_u8PerBurst<<PBURST);//for PBURST
    break;
	}
}


void DMA_VoidPeripheralFlowController(u8 Copy_u8Dma ,u8 Copy_u8Stream)
{
	switch(Copy_u8Dma)
    {
    case 1 :	
    CLR_BIT(DMA1-> Stream[Copy_u8Stream].SCR , EN );
    while(GET_BIT(DMA1-> Stream[Copy_u8Stream].SCR  , EN)==1){}//Do Nothing till ENABLE BIT is CLEARED 
	SET_BIT(DMA1-> Stream[Copy_u8Stream].SCR , PFCTRL ); //not used in memory to memory direction (forced by HW) 
	break;	
    
	case 2 :	
    CLR_BIT(DMA2-> Stream[Copy_u8Stream].SCR , EN );
    while(GET_BIT(DMA2-> Stream[Copy_u8Stream].SCR  , EN)==1){}//Do Nothing till ENABLE BIT is CLEARED 
	SET_BIT(DMA2-> Stream[Copy_u8Stream].SCR , PFCTRL ); //not used in memory to memory direction (forced by HW) 
	break;    
	}
}

/* ENABLE FIFO ERROR INTTERUPT */
void DMA_VoidEnableFifoInt(u8 Copy_u8Dma ,u8 Copy_u8Stream)
{
	switch(Copy_u8Dma)
    {
    case 1 :
	SET_BIT(DMA1-> Stream[Copy_u8Stream].SFCR , FIFO_INT );
	break;
    case 2 :
	SET_BIT(DMA2-> Stream[Copy_u8Stream].SFCR , FIFO_INT );
    break;
	}
}

/* READ FIFO STATUS */
/*void DMA_U8GetFifoStatus(u8 Copy_u8Stream)
{
		
}
*/

 /* SELECT FIFO THRESHOLD */
void DMA_VoidSelectFifoThreshold(u8 Copy_u8Dma ,u8 Copy_u8Stream , u8 Copy_u8Threshold)
{
	switch(Copy_u8Dma)
    {
    case 1 :
    CLR_BIT(DMA1-> Stream[Copy_u8Stream].SCR , EN );  // CLEAR THE ENABLE BIT
    while(GET_BIT(DMA1-> Stream[Copy_u8Stream].SCR  , EN)==1){}//Do Nothing till ENABLE BIT is CLEARED 
	SET_BIT(DMA1-> Stream[Copy_u8Stream].SFCR , DIR_MODE_DISABLE ); // DIRECT MODE DISABLED	
	DMA1-> Stream[Copy_u8Stream].SFCR &=~(0b11);     DMA1-> Stream[Copy_u8Stream].SFCR |=(Copy_u8Threshold);
	break;
    
	case 2 :
    CLR_BIT(DMA2-> Stream[Copy_u8Stream].SCR , EN );  // CLEAR THE ENABLE BIT
    while(GET_BIT(DMA2-> Stream[Copy_u8Stream].SCR  , EN)==1){}//Do Nothing till ENABLE BIT is CLEARED 
	SET_BIT(DMA2-> Stream[Copy_u8Stream].SFCR , DIR_MODE_DISABLE ); // DIRECT MODE DISABLED	
	DMA2-> Stream[Copy_u8Stream].SFCR &=~(0b11);     DMA2-> Stream[Copy_u8Stream].SFCR |=(Copy_u8Threshold);
	break;
	}
}

void DMA_VoidSetDoubleBufferMODE(u8 Copy_u8Dma ,u8 Copy_u8Stream,u8 Copy_u8CurrentTarget , u32 * Copy_pu32PeripheralAddress , u32 * Copy_pu32Memory0Address ,u32 * Copy_pu32Memory1Address , u16 Copy_u16BlockLength)
{
	switch(Copy_u8Dma)
    {
    case 1 :
    CLR_BIT(DMA1-> Stream[Copy_u8Stream].SCR , EN );  // CLEAR THE ENABLE BIT
    while(GET_BIT(DMA1-> Stream[Copy_u8Stream].SCR  , EN)==1){}//Do Nothing till ENABLE BIT is CLEARED 
	SET_BIT(DMA1-> Stream[Copy_u8Stream].SCR , DBM ); // DOUBLE BUFFER MODE 	
    //  indicate the target memory area of the first transfer once the stream is enabled 
	DMA1-> Stream[Copy_u8Stream].SCR &=~(0b1<<CT);     DMA1-> Stream[Copy_u8Stream].SCR |=(Copy_u8CurrentTarget<<CT);
    
  	DMA1-> Stream[Copy_u8Stream].SNDTR =(Copy_u16BlockLength);  // set  number of data items to transfer 
	DMA1-> Stream[Copy_u8Stream].SPAR =((u32)Copy_pu32PeripheralAddress);  // set  peripheral address 	
	DMA1-> Stream[Copy_u8Stream].SM0AR =((u32)Copy_pu32Memory0Address);  // set  memory0 address 	
	DMA1-> Stream[Copy_u8Stream].SM1AR =((u32)Copy_pu32Memory1Address);  // set  memory1 address
	break;
		
    case 2 :
    CLR_BIT(DMA2-> Stream[Copy_u8Stream].SCR , EN );  // CLEAR THE ENABLE BIT
    while(GET_BIT(DMA2-> Stream[Copy_u8Stream].SCR  , EN)==1){}//Do Nothing till ENABLE BIT is CLEARED 
	SET_BIT(DMA2-> Stream[Copy_u8Stream].SCR , DBM ); // DOUBLE BUFFER MODE 	
    //  indicate the target memory area of the first transfer once the stream is enabled 
	DMA2-> Stream[Copy_u8Stream].SCR &=~(0b1<<CT);     DMA2-> Stream[Copy_u8Stream].SCR |=(Copy_u8CurrentTarget<<CT);
    
  	DMA2-> Stream[Copy_u8Stream].SNDTR =(Copy_u16BlockLength);  // set  number of data items to transfer 
	DMA2-> Stream[Copy_u8Stream].SPAR =((u32)Copy_pu32PeripheralAddress);  // set  peripheral address 	
	DMA2-> Stream[Copy_u8Stream].SM0AR =((u32)Copy_pu32Memory0Address);  // set  memory0 address 	
	DMA2-> Stream[Copy_u8Stream].SM1AR =((u32)Copy_pu32Memory1Address);  // set  memory1 address
	break;
    }
}

/* interrupt */
void MDMA_VidSetCallBack_I2C3_RX( void ( *Ptr ) ( void ) )
{
	DMA_CallBack_I2C3_RX = Ptr ;
}

void DMA1_I2C3_RX_IRQHandler(void)
{
	DMA_CallBack_I2C3_RX();
	DMA_VoidClearFlag(1, STREAM_2 , TCIF );
}


void MDMA_VidSetCallBack_I2C2_RX( void ( *Ptr ) ( void ) )
{
	DMA_CallBack_I2C2_RX = Ptr ;
}


void DMA1_I2C2_RX_IRQHandler(void)
{
	DMA_CallBack_I2C2_RX();
	DMA_VoidClearFlag(1, STREAM_3 , TCIF );
}

void MDMA_VidSetCallBack_I2C3_TX( void ( *Ptr ) ( void ) )
{
	DMA_CallBack_I2C3_TX = Ptr ;
}

void DMA1_I2C3_TX_IRQHandler(void)
{
	DMA_CallBack_I2C3_TX();
    DMA_VoidClearFlag(1, STREAM_4 , TCIF );
}


void MDMA_VidSetCallBack_I2C2_TX( void ( *Ptr ) ( void ) )
{
	DMA_CallBack_I2C2_TX = Ptr ;
}

void DMA1_I2C2_TX_IRQHandler(void)
{
	DMA_CallBack_I2C2_TX();
    DMA_VoidClearFlag(1, STREAM_7 , TCIF );
}



/*
 """in main file """
 void handler (void)
 {// do anything ;}
 
 int main ()
 {	MDMA_VidSetCallBackChannel1( handler ); return 0; }
*/
