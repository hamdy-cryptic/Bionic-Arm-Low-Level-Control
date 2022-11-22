/*********************************************************/
/*Author    : youstina                                   */
/*version   : v03*                                        */
/*date      : 20 FEB 2021                                */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"
#include "DMA_interface.h"



#define NULL		(void * )0

static void (* DMA_CallBack_I2C2_RX)(void) = NULL ;
static void (* DMA_CallBack_I2C2_TX)(void) = NULL ;



void   MDMA_voidChannelInit(void)
{   
	 if (DMA ==DMA1){ 
    /*Enable clock on DMA1 Peripheral*/
	RCC_voidEnableClock (RCC_AHB1,RCC_DMA1); }
    else if (DMA == DMA2) {
    /*Enable clock on DMA2 Peripheral*/
    RCC_voidEnableClock (RCC_AHB1,RCC_DMA2);} 
    else  /*error*/;
	CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 0 ); //Disable DMA
	while( GET_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 0 ) == 1 ){}  // Wait Until DMA Disable
	#if DATA_TRANSFER_DIRECTION ==  MEMORY_TO_MEMORY 
	   SET_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 14 );
	#elif  DATA_TRANSFER_DIRECTION == PERIPHERAL_TO_MEMORY 
      CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 4  );
    #elif  DATA_TRANSFER_DIRECTION == MEMORY_TO_PERIPHERAL
	  SET_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 4  );
	#endif
	
    #if CIRCULAR_MODE == ENABLED
	  SET_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 5  );
	#elif  CIRCULAR_MODE == DISABLED
     CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 5 );
	#endif
	
	#if MEMORY_INCREAMENT_MODE == ACTIVATED
    SET_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 7  );
	#elif  MEMORY_INCREAMENT_MODE == DEACTIVATED
	CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 7  );
    #endif
	
	#if  PERIPHERAL_INCREAMENT_MODE == ACTIVATED
	  SET_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 6  );
	#elif   PERIPHERAL_INCREAMENT_MODE == DEACTIVATED
     CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 6  );
	#endif
	
	#if  MEMORY_DATA_SIZE == BYTE
       CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 10 );
	   CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 11 );
    #elif  MEMORY_DATA_SIZE == HALF_WORD
       SET_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 10 );
	   CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 11 );
	#elif   MEMORY_DATA_SIZE == WORD
	   CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 10 );
	   SET_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 11 );
    #endif
    
    #if PERIPHERAL_DATA_SIZE == BYTE
        CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 8 );
		CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 9 );
    #elif  PERIPHERAL_DATA_SIZE == HALF_WORD
        SET_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 8 );
		CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 9 );
    #elif  PERIPHERAL_DATA_SIZE == WORD
        CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 8 );
		SET_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 9 );
    #endif
	
	#if PRIORITY_LEVEL == LOW
	 CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 12 );
	 CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 13 );
	
	#elif PRIORITY_LEVEL== MEDIUM 
        SET_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 12 );
		CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 13 );
    #elif PRIORITY_LEVEL== HIGH 
	    CLR_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 12 );
		SET_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 13 );
	#elif PRIORITY_LEVEL==VERY_HIGH
        SET_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 12 );
		SET_BIT( DMA->CHANNEL[CHANNEL_ID].CCR , 13 );
	#endif
}

void DMA_SetConfig(u8 Copy_u8Dma , u8 Copy_u8CHANNEL , u8 Copy_u8DataDirection , u8 Copy_u8MemDataSize , u8 Copy_u8PerDataSize , u8 Copy_u8MemInc , u8 Copy_u8PerInc)

{        /************** DMA ********/ 
	
	switch(Copy_u8Dma)
    {
        case 1 :
		  /*Enable clock on DMA1 Peripheral*/
    	RCC_voidEnableClock (RCC_AHB1,RCC_DMA1);
		
		CLR_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 0 ); // CLEAR ENABLE BIT TO CONFIGURE
	    while( GET_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 0 ) == 1 ); // Wait Until DMA Disable
		 
 		  /*************** DATA DIRECTION *******************/
		  if( Copy_u8DataDirection ==  MEMORY_TO_MEMORY )
	      { SET_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 14 ); }
	      else if (Copy_u8DataDirection == PERIPHERAL_TO_MEMORY)
          { CLR_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 4  ); }
          else if (Copy_u8DataDirection == MEMORY_TO_PERIPHERAL)
	      {SET_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 4  ); }
	
          /****************** MEMORY & PERIPHERAL DATA SIZE ***********/
		  
		  if(Copy_u8MemDataSize == BYTE)
		  {CLR_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 10 );
		  CLR_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 11 ); }
          else if (Copy_u8MemDataSize== HALF_WORD)
		  { SET_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 10 );
		    CLR_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 11 ); }
	       else if (Copy_u8MemDataSize== WORD)
		   { CLR_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 10 );
	         SET_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 11 ); }
			 
			 
			if(Copy_u8PerDataSize == BYTE)
			{  CLR_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 8 );
			   CLR_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 9 ); }
           else if (Copy_u8PerDataSize == HALF_WORD)
           { SET_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 8 );
		   CLR_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 9 ); }
          else if (Copy_u8PerDataSize ==WORD)
		  { CLR_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 8 );
		   SET_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 9 ); }
    
          /**************** PERIPHERAL INCREAMENT & MEMORY INCREAMENT ******************/
		  
		  if(Copy_u8MemInc == ACTIVATED)
		  { SET_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 7  ); }
	      else  if(Copy_u8MemInc == DEACTIVATED)
	      {CLR_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 7  );  }
   
	
	      if(Copy_u8PerInc == ACTIVATED)
		  { SET_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 6  ); }
	      else if(Copy_u8PerInc == DEACTIVATED)
          {CLR_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 6  ); }
	      break;
		case 2 : 
		   /*Enable clock on DMA2 Peripheral*/
    	RCC_voidEnableClock (RCC_AHB1,RCC_DMA2);
		
   		CLR_BIT( DMA2->CHANNEL[ Copy_u8CHANNEL].CCR , 0 ); // CLEAR ENABLE BIT TO CONFIGURE
	    while( GET_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 0 ) == 1 ); // Wait Until DMA Disable
		 break;
		default : break;
 		  /*************** DATA DIRECTION *******************/
		  if( Copy_u8DataDirection ==  MEMORY_TO_MEMORY )
	      { SET_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 14 ); }
	      else if (Copy_u8DataDirection == PERIPHERAL_TO_MEMORY)
          { CLR_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 4  ); }
          else if (Copy_u8DataDirection == MEMORY_TO_PERIPHERAL)
	      {SET_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 4  ); }
	
          /****************** MEMORY & PERIPHERAL DATA SIZE ***********/
		  
		  if(Copy_u8MemDataSize == BYTE)
		  {CLR_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 10 );
		  CLR_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 11 ); }
          else if (Copy_u8MemDataSize== HALF_WORD)
		  { SET_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 10 );
		    CLR_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 11 ); }
	       else if (Copy_u8MemDataSize== WORD)
		   { CLR_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 10 );
	         SET_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 11 ); }
			 
			 
			if(Copy_u8PerDataSize == BYTE)
			{  CLR_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 8 );
			   CLR_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 9 ); }
           else if (Copy_u8PerDataSize == HALF_WORD)
           { SET_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 8 );
		   CLR_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 9 ); }
          else if (Copy_u8PerDataSize ==WORD)
		  { CLR_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 8 );
		   SET_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 9 ); }
    
          /**************** PERIPHERAL INCREAMENT & MEMORY INCREAMENT ******************/
		  
		  if(Copy_u8MemInc == ACTIVATED)
		  { SET_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 7  ); }
	      else  if(Copy_u8MemInc == DEACTIVATED)
	      {CLR_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 7  );  }
   
	
	      if(Copy_u8PerInc == ACTIVATED)
		  { SET_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 6  ); }
	      else if(Copy_u8PerInc == DEACTIVATED)
          {CLR_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 6  ); }
	   
	}	 
}// set in run time



/* DISABLE DMA */
void MDMA_VoidDMADisable( u8 Copy_u8Dma , u8 Copy_u8CHANNEL )
{
	switch(Copy_u8Dma)
    {
        case 1 :
	    CLR_BIT(DMA1-> CHANNEL[Copy_u8CHANNEL].CCR , 0 );  break;
		
		case 2 :
	    CLR_BIT(DMA2-> CHANNEL[Copy_u8CHANNEL].CCR , 0 );
		break;
		default : break;
	}	
}

/* ENABLE INTTERUPT */
void DMA_VoidInerruptEnable(u8 Copy_u8Dma , u8 Copy_u8CHANNEL , u8 Copy_u8INTSource )
{
	switch(Copy_u8Dma)
    {
        case 1 :
	    SET_BIT( DMA1-> CHANNEL[Copy_u8CHANNEL].CCR , Copy_u8INTSource );  break;
		
		case 2 :
	    SET_BIT( DMA2-> CHANNEL[Copy_u8CHANNEL].CCR , Copy_u8INTSource ); break;
		default : break;
	}
}


void DMA_VoidSetAddress(u8 Copy_u8Dma , u8 Copy_u8CHANNEL , u32 * Copy_pu32PeripheralAddress , u32 * Copy_pu32MemoryAddress , u16 Copy_u16BlockLength )
{   
    switch(Copy_u8Dma)
    {
        case 1 :
        CLR_BIT(DMA1-> CHANNEL[Copy_u8CHANNEL].CCR , 0 );
         while( GET_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 0 ) == 1 ); // Wait Until DMA Disable
		 DMA1-> CHANNEL[Copy_u8CHANNEL].CPAR =((u32)Copy_pu32PeripheralAddress);  // set  peripheral address 
		 DMA1-> CHANNEL[Copy_u8CHANNEL].CMAR =((u32)Copy_pu32MemoryAddress);  // set  memory address 	 
		 DMA1-> CHANNEL[Copy_u8CHANNEL].CNDTR  =(Copy_u16BlockLength);  // set  number of data items to transfer 
	   break;
		case 2 :
         CLR_BIT(DMA2-> CHANNEL[Copy_u8CHANNEL].CCR , 0 );
         while( GET_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 0 ) == 1 ); // Wait Until DMA Disable
		 DMA2-> CHANNEL[Copy_u8CHANNEL].CPAR =((u32)Copy_pu32PeripheralAddress);  // set  peripheral address 
		 DMA2-> CHANNEL[Copy_u8CHANNEL].CMAR =((u32)Copy_pu32MemoryAddress);  // set  memory address 	 
		 DMA2-> CHANNEL[Copy_u8CHANNEL].CNDTR  =(Copy_u16BlockLength);  // set  number of data items to transfer
    break;
		default : break;
    }
}

/* CLEAR FLAG OF INTTERUPT */
void DMA_VoidClearFlag(u8 Copy_u8Dma ,u8 Copy_u8CHANNEL , u8 Copy_u8Flag )
{
	
 switch(Copy_u8Dma)
    {
        case 1 :
        Copy_u8CHANNEL *= 4 ;
        SET_BIT( DMA1->IFCR , (Copy_u8CHANNEL + Copy_u8Flag) );    break;
   
	    case 2 :
        Copy_u8CHANNEL*= 4 ;
        SET_BIT( DMA2->IFCR , (Copy_u8CHANNEL + Copy_u8Flag) );   break;
			default : break;
	}
}

/* ENABLE DMA */
void DMA_VoidDMAEnable(u8 Copy_u8Dma , u8 Copy_u8CHANNEL )
{
	 switch(Copy_u8Dma)
    {
        case 1 :
	    DMA_VoidClearFlag(1 , Copy_u8CHANNEL , GIF );
	    DMA_VoidClearFlag(1 , Copy_u8CHANNEL , TCIF  );
    	DMA_VoidClearFlag(1 , Copy_u8CHANNEL , HTIF );
	    DMA_VoidClearFlag(1 , Copy_u8CHANNEL , TEIF );
	    
		
    	SET_BIT(DMA1-> CHANNEL[Copy_u8CHANNEL].CCR , 0 );	
		break;
		case 2 :
	    DMA_VoidClearFlag(2 , Copy_u8CHANNEL , GIF );
	    DMA_VoidClearFlag(2 , Copy_u8CHANNEL , TCIF  );
    	DMA_VoidClearFlag(2 , Copy_u8CHANNEL , HTIF );
	    DMA_VoidClearFlag(2 , Copy_u8CHANNEL , TEIF );
		
    	SET_BIT(DMA2-> CHANNEL[Copy_u8CHANNEL].CCR , 0 );	
		break;
		default : break;
    }
}


u8 DMA_u8GetFlag(u8 Copy_u8Dma ,u8 Copy_u8CHANNEL , u8 Copy_u8Flag )
{
// PLEASE NOTE THAT DMA IS DEFINED AS DMA1 OR DMA2 IN CONFIG FILE
	u8 LOC_u8Result = 0;
    
    switch(Copy_u8Dma)
    {
        case 1 :
       
	   Copy_u8CHANNEL*= 4 ;
    	LOC_u8Result = GET_BIT (DMA1->ISR , (Copy_u8CHANNEL+ Copy_u8Flag) );   break;
		
	    case 2 :
        Copy_u8CHANNEL*= 4 ;
    	LOC_u8Result = GET_BIT (DMA2->ISR , (Copy_u8CHANNEL+ Copy_u8Flag) );  break;
			default : break;
	}   
	return LOC_u8Result ;
    
}


void DMA_VoidConfigPriority(u8 Copy_u8Dma ,u8 Copy_u8CHANNEL, u8 Copy_u8PeriorityLevel)
{
	switch(Copy_u8Dma)
    {
    case 1 :
	CLR_BIT(DMA1-> CHANNEL[Copy_u8CHANNEL].CCR , 0 );
	while( GET_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 0 ) == 1 ); // Wait Until DMA Disable 
	DMA1-> CHANNEL[Copy_u8CHANNEL].CCR &=~(0b11<<12);   DMA1-> CHANNEL[Copy_u8CHANNEL].CCR |=(Copy_u8PeriorityLevel<<12);
  break;
    case 2 :
	CLR_BIT(DMA2-> CHANNEL[Copy_u8CHANNEL].CCR , 0 );
	while( GET_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 0 ) == 1 ); // Wait Until DMA Disable 
	DMA2-> CHANNEL[Copy_u8CHANNEL].CCR &=~(0b11<<12);   DMA2-> CHANNEL[Copy_u8CHANNEL].CCR |=(Copy_u8PeriorityLevel<<12);
		break;
		default : break;
	}
}


void DMA_VoidSetCircularMode(u8 Copy_u8Dma ,u8 Copy_u8CHANNEL)
{
	switch(Copy_u8Dma)
    {
    case 1 :
	 SET_BIT( DMA1->CHANNEL[Copy_u8CHANNEL].CCR , 5  );//enable circular mode  
	 break;
    case 2 :
	 SET_BIT( DMA2->CHANNEL[Copy_u8CHANNEL].CCR , 5  );//enable circular mode 
		break;
		default : break;
    }
}


/* interrupt */



void MDMA_VidSetCallBack_I2C2_RX( void ( *Ptr ) ( void ) )
{
	DMA_CallBack_I2C2_RX = Ptr ;
}


void DMA1_I2C2_RX_IRQHandler(void)
{
	DMA_CallBack_I2C2_RX();
	DMA_VoidClearFlag(1, CHANNEL5 , TCIF );
}


void MDMA_VidSetCallBack_I2C2_TX( void ( *Ptr ) ( void ) )
{
	DMA_CallBack_I2C2_TX = Ptr ;
}

void DMA1_I2C2_TX_IRQHandler(void)
{
	DMA_CallBack_I2C2_TX();
    DMA_VoidClearFlag(1,CHANNEL4 , TCIF );
}
