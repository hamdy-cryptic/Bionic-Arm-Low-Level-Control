/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 27 December 2020                                 */
/* Version : V01                                            */
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"
#include "DMA_interface.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"






  void USART_Init(void)
{
     u32  DIV_Mantissa;
	   u32  DIV_Fraction;
    #ifdef usart1 	
		                   
					  
            // USART_OVERSAMPLING_BY_16
			         
		       RCC_voidEnableClock (RCC_APB2, 14);          //Enable USART1 clock
           RCC_voidEnableClock (RCC_APB2, RCC_GPIOA ); //Enable GPIOA clock
	         GPIO_voidSetPinDirection(GPIOA , 9 , GPIO_AF); // Set TX pin to AF
           GPIO_voidSetPinDirection(GPIOA , 10 , GPIO_INPUT); // Set RX pin to INPUT
		       GPIO_SET_PU_PD (GPIOA , 10, GPIO_PU);
		       GPIO_SET_PP_OD (GPIOA , 9, GPIO_OUTPUT_PP);
           SET_GPIO_SPEED( GPIOA ,9,GPIO_SPEED_HIGH);
           SET_GPIO_SPEED( GPIOA ,10,GPIO_SPEED_HIGH);	
     
					 
			         DIV_Mantissa = (fck2)/(16* USART_BAUD_RATE) ;
			         DIV_Fraction= ( ( ( fck2 * 100 ) / ( 16 * USART_BAUD_RATE )  ) % 100 ) * 16 ;
			         if( DIV_Fraction > 1500 )
			             { 
			                DIV_Mantissa += 1 ; 
			                DIV_Fraction  = 0 ; 
			             }
		     USART1 -> CR1 =0x00;
			 #if USART_STATUS == USART_ENABLE

		             SET_BIT(USART1 -> CR1, 13);
		
            #if   USART_DMA_TX==DMAT_ENABLE    
                SET_BIT( USART1 -> CR3 , 7 );		
            #elif USART_DMA_TX==DMAT_DISABLE 
			    CLR_BIT( USART1 -> CR3 , 7 );
            #endif			
			#if   USART_DMA_RX==DMAR_ENABLE    
                SET_BIT( USART1 -> CR3 , 6 );		
            #elif USART_DMA_RX==DMAR_DISABLE 
			    CLR_BIT( USART1 -> CR3 , 6 );
            #endif			
              
		    #if   USART_WORD_LENGTH == 8

					 CLR_BIT( USART1 -> CR1 , 12);

		#elif USART_WORD_LENGTH ==   9

					SET_BIT( USART1 -> CR1 , 12 );

		#endif

		#if   USART_CONTROL_PARITY == PARITY_CONTROL_DISABLE

					CLR_BIT( USART1 -> CR1 , 10 );

		#elif USART_CONTROL_PARITY == EVEN_PARITY

					SET_BIT( USART1 -> CR1 , 10 );
					CLR_BIT( USART1 -> CR1 , 9 );

		#elif USART_CONTROL_PARITY == ODD_PARITY

					SET_BIT( USART1 -> CR1 , 10 );
					SET_BIT( USART1 -> CR1 , 9 );

		#endif

		#if  USART_INTERRUPT == INT_DISABLE

          CLR_BIT( USART1 -> CR1 , 4 );
					CLR_BIT( USART1 -> CR1 , 5 );
					CLR_BIT( USART1 -> CR1 , 6 );
					CLR_BIT( USART1 -> CR1 , 7 );
					CLR_BIT( USART1 -> CR1 , 8 );
        
		#elif USART_INTERRUPT == IDLE_INT_ENABLE
		
		           SET_BIT( USART1 -> CR1 , 4 );
		
		#elif USART_INTERRUPT == RXNE_INT_ENABLE

					SET_BIT( USART1 -> CR1 , 5 );

		#elif USART_INTERRUPT == TCE_INT_ENABLE

					SET_BIT( USART1 -> CR1 , 6 );

		#elif USART_INTERRUPT == TXE_INT_ENABLE

					SET_BIT( USART1 -> CR1 , 7 );
					
		#elif USART_INTERRUPT == PE_INT_ENABLE

					SET_BIT( USART1 -> CR1 , 8 );

		#endif

		#if   USART_TRANSMITTER == TRANSMITTER_ENABLE

					SET_BIT( USART1 -> CR1 , 3 );

		#elif USART_TRANSMITTER == TRANSMITTER_DISABLE

					CLR_BIT( USART1 -> CR1 , 3 );

		#endif

		#if   USART_RECEIVER == RECEIVER_ENABLE

					SET_BIT( USART1 -> CR1 , 2 );

		#elif USART_RECEIVER == RECEIVER_DISBLE

					CLR_BIT( USART1 -> CR1 , 2 );

		#endif
		
		#if    USART_HW_FLOW_CONTROL == USART_CTS 
		         SET_BIT(USART1 -> CR3 , 9);
		#elif   USART_HW_FLOW_CONTROL == USART_RTS 
		         SET_BIT(USART1 -> CR3 , 8)	;	 
		#elif   USART_HW_FLOW_CONTROL == USART_CTS_RTS 
		         SET_BIT(USART1 -> CR3 , 8) ;
						 SET_BIT(USART1 -> CR3 , 9);
	    #elif   USART_HW_FLOW_CONTROL == USART_NO_CTS_RTS
		         CLR_BIT(USART1 -> CR3 , 8);
						 CLR_BIT(USART1 -> CR3 , 9);
		#endif

		#if   USART_STOP_BITS == ONE_STOP_BIT

					CLR_BIT( USART1 -> CR2 , 12 ); 
					CLR_BIT( USART1 -> CR2 , 13 );

		#elif USART_STOP_BITS == HALF_STOP_BIT

					SET_BIT( USART1 -> CR2 , 12 ); 
					CLR_BIT( USART1 -> CR2 , 13 );

		#elif USART_STOP_BITS == TWO_STOP_BIT

					CLR_BIT( USART1 -> CR2 , 12 );
					SET_BIT( USART1 -> CR2 , 13 );

		#elif USART_STOP_BITS == ONE_AND_HALF_STOP_BIT

					SET_BIT( USART1 -> CR2 , 12 ); 
					SET_BIT( USART1 -> CR2 , 13 );


		#endif
		USART1 -> BRR = (DIV_Mantissa << 4  ) | ( DIV_Fraction / 100 ) ;
		USART1-> SR = 0 ;

		
	#elif USART_STATUS == USART_DISABLE
		CLR_BIT( USART1 -> CR1 , 13 );
		#endif
	#endif

    #ifdef  usart2 	
		           
		       RCC_voidEnableClock (RCC_APB1, 17);
           RCC_voidEnableClock (RCC_APB2, RCC_GPIOA ); //Enable GPIOA clock
	         GPIO_voidSetPinDirection(GPIOA , 2 , GPIO_AF_OD); // Set TX pin to AF
           GPIO_voidSetPinDirection(GPIOA , 3 , GPIO_INPUT); // Set RX pin to INPUT
		       GPIO_SET_PU_PD (GPIOA , 3, GPIO_PU);
		      // GPIO_SET_PP_OD (GPIOA , 2, GPIO_OUTPUT_PP);
           SET_GPIO_SPEED( GPIOA ,2,GPIO_SPEED_HIGH);
           SET_GPIO_SPEED( GPIOA ,3,GPIO_SPEED_HIGH);	  
            // USART_OVERSAMPLING_BY_16
			 
			  DIV_Mantissa = (fck1)/(16* USART_BAUD_RATE) ;
			  DIV_Fraction= ( ( ( fck1 * 100 ) / ( 16 * USART_BAUD_RATE )  ) % 100 ) * 16 ;
			 if( DIV_Fraction > 1500 )
			 { 
			 DIV_Mantissa += 1 ; 
			 DIV_Fraction  = 0 ; 
			 }
			 USART2 -> CR1 =0x00;
			 #if USART_STATUS == USART_ENABLE

		         SET_BIT(USART2 -> CR1, 13);
             #if   USART_DMA_TX==DMAT_ENABLE    
                SET_BIT( USART2 -> CR3 , 7 );		
            #elif USART_DMA_TX==DMAT_DISABLE 
			    CLR_BIT( USART2 -> CR3 , 7 );
            #endif			
			#if   USART_DMA_RX==DMAR_ENABLE    
                SET_BIT( USART2 -> CR3 , 6 );		
            #elif USART_DMA_RX==DMAR_DISABLE 
			    CLR_BIT( USART2 -> CR3 , 6 );
            #endif			
		    #if   USART_WORD_LENGTH == 8

					CLR_BIT( USART2 -> CR1 , 12 );

		#elif USART_WORD_LENGTH ==   9

					SET_BIT( USART2 -> CR1 , 12 );

		#endif

		#if   USART_CONTROL_PARITY == PARITY_CONTROL_DISABLE

					CLR_BIT( USART2 -> CR1 , 10 );

		#elif USART_CONTROL_PARITY == EVEN_PARITY

					SET_BIT( USART2 -> CR1 , 10 );
					CLR_BIT( USART2 -> CR1 , 9 );

		#elif USART_CONTROL_PARITY == ODD_PARITY

					SET_BIT( USART2 -> CR1 , 10 );
					SET_BIT( USART2 -> CR1 , 9 );

		#endif

		#if  USART_INTERRUPT == INT_DISABLE

                    CLR_BIT( USART2 -> CR1 , 4 );
					CLR_BIT( USART2 -> CR1 , 5 );
					CLR_BIT( USART2 -> CR1 , 6 );
					CLR_BIT( USART2 -> CR1 , 7 );
					CLR_BIT( USART2 -> CR1 , 8 );
        
		#elif USART_INTERRUPT == IDLE_INT_ENABLE
		
		           SET_BIT( USART2 -> CR1 , 4 );
		
		#elif USART_INTERRUPT == RXNE_INT_ENABLE

					SET_BIT( USART2 -> CR1 , 5 );

		#elif USART_INTERRUPT == TCE_INT_ENABLE

					SET_BIT( USART2 -> CR1 , 6 );

		#elif USART_INTERRUPT == TXE_INT_ENABLE

					SET_BIT( USART2 -> CR1 , 7 );
					
		#elif USART_INTERRUPT == PE_INT_ENABLE

					SET_BIT( USART2 -> CR1 , 8 );

		#endif

		#if   USART_TRANSMITTER == TRANSMITTER_ENABLE

					SET_BIT( USART2 -> CR1 , 3 );

		#elif USART_TRANSMITTER == TRANSMITTER_DISABLE

					CLR_BIT( USART2 -> CR1 , 3 );

		#endif

		#if   USART_RECEIVER == RECEIVER_ENABLE

					SET_BIT( USART2 -> CR1 , 2 );

		#elif USART_RECEIVER == RECEIVER_DISBLE

					CLR_BIT( USART2 -> CR1 , 2 );

		#endif
		
		#if    USART_HW_FLOW_CONTROL == USART_CTS 
		         SET_BIT(USART2 -> CR3 , 9);
		#elif   USART_HW_FLOW_CONTROL == USART_RTS 
		         SET_BIT(USART2 -> CR3 , 8)	;	 
		#elif   USART_HW_FLOW_CONTROL == USART_CTS_RTS 
		         SET_BIT(USART2 -> CR3 , 8); 
						 SET_BIT(USART2 -> CR3 , 9);
	    #elif   USART_HW_FLOW_CONTROL == USART_NO_CTS_RTS
		         CLR_BIT(USART2 -> CR3 , 8); 
						 CLR_BIT(USART2 -> CR3 , 9);
		#endif

		#if   USART_STOP_BITS == ONE_STOP_BIT

					CLR_BIT( USART2 -> CR2 , 12 ); 
					CLR_BIT( USART2 -> CR2 , 13 );

		#elif USART_STOP_BITS == HALF_STOP_BIT

					SET_BIT( USART2 -> CR2 , 12 ); 
					CLR_BIT( USART2 -> CR2 , 13 );

		#elif USART_STOP_BITS == TWO_STOP_BIT

					CLR_BIT( USART2 -> CR2 , 12 );
					SET_BIT( USART2 -> CR2 , 13 );

		#elif USART_STOP_BITS == ONE_AND_HALF_STOP_BIT

					SET_BIT( USART2 -> CR2 , 12 ); 
					SET_BIT( USART2 -> CR2 , 13 );


		#endif
		USART2 -> BRR = (DIV_Mantissa << 4  ) | ( DIV_Fraction / 100 ) ;
		USART2-> SR = 0 ;

		
	#elif USART_STATUS == USART_DISABLE
		CLR_BIT( USART2 -> CR1 , 13 );
		
    #endif
#endif	

 #ifdef usart3
 
		       RCC_voidEnableClock (RCC_APB1, 18);          //Enable USART3 clock
           RCC_voidEnableClock (RCC_APB2, RCC_GPIOB ); //Enable GPIOB clock
	         GPIO_voidSetPinDirection(GPIOB , 10 , GPIO_AF); // Set TX pin to AF
           GPIO_voidSetPinDirection(GPIOB , 11, GPIO_INPUT); // Set RX pin to INPUT
		       GPIO_SET_PU_PD (GPIOB , 11, GPIO_PU);
		       GPIO_SET_PP_OD (GPIOB , 10, GPIO_OUTPUT_PP);
           SET_GPIO_SPEED( GPIOB ,10,GPIO_SPEED_HIGH);
           SET_GPIO_SPEED( GPIOB ,11,GPIO_SPEED_HIGH);	
     
        
            // USART_OVERSAMPLING_BY_16
			 
			 DIV_Mantissa = (fck1)/(16* USART_BAUD_RATE) ;
			 DIV_Fraction= ( ( ( fck1 * 100 ) / ( 16 * USART_BAUD_RATE )  ) % 100 ) * 16 ;
			 if( DIV_Fraction > 1500 )
			 { 
			 DIV_Mantissa += 1 ; 
			 DIV_Fraction  = 0 ; 
			 }
		     USART3 -> CR1 =0x00;
			 #if USART_STATUS == USART_ENABLE

		        SET_BIT(USART3 -> CR1, 13);
		     #if   USART_DMA_TX==DMAT_ENABLE    
                SET_BIT( USART3 -> CR3 , 7 );		
            #elif USART_DMA_TX==DMAT_DISABLE 
			    CLR_BIT( USART3 -> CR3 , 7 );
            #endif			
			#if   USART_DMA_RX==DMAR_ENABLE    
                SET_BIT( USART3 -> CR3 , 6 );		
            #elif USART_DMA_RX==DMAR_DISABLE 
			    CLR_BIT( USART3 -> CR3 , 6 );
            #endif			

		    #if   USART_WORD_LENGTH == 8

					CLR_BIT( USART3 -> CR1 , 12 );

		#elif USART_WORD_LENGTH ==   9

					SET_BIT( USART3 -> CR1 , 12 );

		#endif

		#if   USART_CONTROL_PARITY == PARITY_CONTROL_DISABLE

					CLR_BIT( USART3 -> CR1 , 10 );

		#elif USART_CONTROL_PARITY == EVEN_PARITY

					SET_BIT( USART3 -> CR1 , 10 );
					CLR_BIT( USART3 -> CR1 , 9 );

		#elif USART_CONTROL_PARITY == ODD_PARITY

					SET_BIT( USART3 -> CR1 , 10 );
					SET_BIT( USART3 -> CR1 , 9 );

		#endif

		#if  USART_INTERRUPT == INT_DISABLE

                    CLR_BIT( USART3 -> CR1 , 4 );
					CLR_BIT( USART3 -> CR1 , 5 );
					CLR_BIT( USART3 -> CR1 , 6 );
					CLR_BIT( USART3 -> CR1 , 7 );
					CLR_BIT( USART3 -> CR1 , 8 );
        
		#elif USART_INTERRUPT == IDLE_INT_ENABLE
		
		           SET_BIT( USART3 -> CR1 , 4 );
		
		#elif USART_INTERRUPT == RXNE_INT_ENABLE

					SET_BIT( USART3 -> CR1 , 5 );

		#elif USART_INTERRUPT == TCE_INT_ENABLE

					SET_BIT( USART3 -> CR1 , 6 );

		#elif USART_INTERRUPT == TXE_INT_ENABLE

					SET_BIT( USART3 -> CR1 , 7 );
					
		#elif USART_INTERRUPT == PE_INT_ENABLE

					SET_BIT( USART3 -> CR1 , 8 );

		#endif

		#if   USART_TRANSMITTER == TRANSMITTER_ENABLE

					SET_BIT( USART3 -> CR1 , 3 );

		#elif USART_TRANSMITTER == TRANSMITTER_DISABLE

					CLR_BIT( USART3 -> CR1 , 3 );

		#endif

		#if   USART_RECEIVER == RECEIVER_ENABLE

					SET_BIT( USART3 -> CR1 , 2 );

		#elif USART_RECEIVER == RECEIVER_DISBLE

					CLR_BIT( USART3 -> CR1 , 2 );

		#endif
		
		#if    USART_HW_FLOW_CONTROL == USART_CTS 
		         SET_BIT(USART3 -> CR3 , 9);
		#elif   USART_HW_FLOW_CONTROL == USART_RTS 
		         SET_BIT(USART3 -> CR3 , 8)	;	 
		#elif   USART_HW_FLOW_CONTROL == USART_CTS_RTS 
		         SET_BIT(USART3 -> CR3 , 8) ;
						 SET_BIT(USART3 -> CR3 , 9);
	    #elif   USART_HW_FLOW_CONTROL == USART_NO_CTS_RTS
		         CLR_BIT(USART3 -> CR3 , 8) ;
						 CLR_BIT(USART3 -> CR3 , 9);
		#endif

		#if   USART_STOP_BITS == ONE_STOP_BIT

					CLR_BIT( USART3 -> CR2 , 12 ); 
					CLR_BIT( USART3 -> CR2 , 13 );

		#elif USART_STOP_BITS == HALF_STOP_BIT

					SET_BIT( USART3 -> CR2 , 12 ); 
					CLR_BIT( USART3 -> CR2 , 13 );

		#elif USART_STOP_BITS == TWO_STOP_BIT

					CLR_BIT( USART3 -> CR2 , 12 );
					SET_BIT( USART3 -> CR2 , 13 );

		#elif USART_STOP_BITS == ONE_AND_HALF_STOP_BIT

					SET_BIT( USART3 -> CR2 , 12 ); 
					SET_BIT( USART3 -> CR2 , 13 );


		#endif
		USART3 -> BRR = (DIV_Mantissa << 4  ) | ( DIV_Fraction / 100 ) ;
		USART3-> SR = 0 ;

		
	#elif USART_STATUS == USART_DISABLE
		CLR_BIT( USART3 -> CR1 , 13 );
		
    #endif
#endif	
	
	
        #ifdef  usart4 	
		           
            // USART_OVERSAMPLING_BY_16
			  CLR_BIT( USART4 -> CR1 , 15 );
			 DIV_Mantissa = (fck1)/(16* USART_BAUD_RATE) ;
			 DIV_Fraction= ( ( ( fck1 * 100 ) / ( 16 * USART_BAUD_RATE )  ) % 100 ) * 16 ;
			 if( DIV_Fraction > 1500 )
			 { 
			 DIV_Mantissa += 1 ; 
			 DIV_Fraction  = 0 ; 
			 } 
			 USART4 -> CR1 =0x00;
			 #if USART_STATUS == USART_ENABLE

		             SET_BIT(USART4 -> CR1, 13);
             #if   USART_DMA_TX==DMAT_ENABLE    
                SET_BIT( USART4 -> CR3 , 7 );		
            #elif USART_DMA_TX==DMAT_DISABLE 
			    CLR_BIT( USART4 -> CR3 , 7 );
            #endif			
			#if   USART_DMA_RX==DMAR_ENABLE    
                SET_BIT( USART4 -> CR3 , 6 );		
            #elif USART_DMA_RX==DMAR_DISABLE 
			    CLR_BIT( USART4 -> CR3 , 6 );
            #endif			
		    #if   USART_WORD_LENGTH == 8

					CLR_BIT( USART4 -> CR1 , 12 );

		#elif USART_WORD_LENGTH ==   9

					SET_BIT( USART4 -> CR1 , 12 );

		#endif

		#if   USART_CONTROL_PARITY == PARITY_CONTROL_DISABLE

					CLR_BIT( USART4 -> CR1 , 10 );

		#elif USART_CONTROL_PARITY == EVEN_PARITY

					SET_BIT( USART4 -> CR1 , 10 );
					CLR_BIT( USART4 -> CR1 , 9 );

		#elif USART_CONTROL_PARITY == ODD_PARITY

					SET_BIT( USART4 -> CR1 , 10 );
					SET_BIT( USART4 -> CR1 , 9 );

		#endif

		#if  USART_INTERRUPT == INT_DISABLE

          CLR_BIT( USART4 -> CR1 , 4 );
					CLR_BIT( USART4 -> CR1 , 5 );
					CLR_BIT( USART4 -> CR1 , 6 );
					CLR_BIT( USART4 -> CR1 , 7 );
					CLR_BIT( USART4 -> CR1 , 8 );
        
		#elif USART_INTERRUPT == IDLE_INT_ENABLE
		
		           SET_BIT( USART4 -> CR1 , 4 );
		
		#elif USART_INTERRUPT == RXNE_INT_ENABLE

					SET_BIT( USART4 -> CR1 , 5 );

		#elif USART_INTERRUPT == TCE_INT_ENABLE

					SET_BIT( USART4 -> CR1 , 6 );

		#elif USART_INTERRUPT == TXE_INT_ENABLE

					SET_BIT( USART4 -> CR1 , 7 );
					
		#elif USART_INTERRUPT == PE_INT_ENABLE

					SET_BIT( USART4 -> CR1 , 8 );

		#endif

		#if   USART_TRANSMITTER == TRANSMITTER_ENABLE

					SET_BIT( USART4 -> CR1 , 3 );

		#elif USART_TRANSMITTER == TRANSMITTER_DISABLE

					CLR_BIT( USART4 -> CR1 , 3 );

		#endif

		#if   USART_RECEIVER == RECEIVER_ENABLE

					SET_BIT( USART4 -> CR1 , 2 );

		#elif USART_RECEIVER == RECEIVER_DISBLE

					CLR_BIT( USART4 -> CR1 , 2 );

		#endif

		#if   USART_STOP_BITS == ONE_STOP_BIT

					CLR_BIT( USART4 -> CR2 , 12 ); 
					CLR_BIT( USART4 -> CR2 , 13 );

		#elif USART_STOP_BITS == HALF_STOP_BIT

					SET_BIT( USART4 -> CR2 , 12 ); 
					CLR_BIT( USART4 -> CR2 , 13 );

		#elif USART_STOP_BITS == TWO_STOP_BIT

					CLR_BIT( USART4 -> CR2 , 12 );
					SET_BIT( USART4 -> CR2 , 13 );

		#elif USART_STOP_BITS == ONE_AND_HALF_STOP_BIT

					SET_BIT( USART4 -> CR2 , 12 ); 
					SET_BIT( USART4 -> CR2 , 13 );


		#endif
		USART4 -> BRR = (DIV_Mantissa << 4  ) | ( DIV_Fraction / 100 ) ;
		USART4-> SR = 0 ;

		
	#elif USART_STATUS == USART_DISABLE
		CLR_BIT( USART4 -> CR1 , 13 );
	#endif
#endif	
	
	
  #ifdef usart5 	
		        
            //USART_OVERSAMPLING_BY_16
			  CLR_BIT( USART5 -> CR1 , 15 );
			 DIV_Mantissa = (fck1)/(16* USART_BAUD_RATE) ;
			 DIV_Fraction= ( ( ( fck1 * 100 ) / ( 16 * USART_BAUD_RATE )  ) % 100 ) * 16 ;
			 if( DIV_Fraction > 1500 )
			 { 
			 DIV_Mantissa += 1 ; 
			 DIV_Fraction  = 0 ; 
			 }
		      
			 USART5 -> CR1 =0x00;
			 #if USART_STATUS == USART_ENABLE

		             SET_BIT(USART5 -> CR1, 13);

		    #if   USART_WORD_LENGTH == 8

					CLR_BIT( USART5 -> CR1 , 12 );

		#elif USART_WORD_LENGTH ==   9

					SET_BIT( USART5 -> CR1 , 12 );

		#endif

		#if   USART_CONTROL_PARITY == PARITY_CONTROL_DISABLE

					CLR_BIT( USART5 -> CR1 , 10 );

		#elif USART_CONTROL_PARITY == EVEN_PARITY

					SET_BIT( USART5 -> CR1 , 10 );
					CLR_BIT( USART5 -> CR1 , 9 );

		#elif USART_CONTROL_PARITY == ODD_PARITY

					SET_BIT( USART5 -> CR1 , 10 );
					SET_BIT( USART5 -> CR1 , 9 );

		#endif

		#if  USART_INTERRUPT == INT_DISABLE

                    CLR_BIT( USART5 -> CR1 , 4 );
					CLR_BIT( USART5 -> CR1 , 5 );
					CLR_BIT( USART5 -> CR1 , 6 );
					CLR_BIT( USART5 -> CR1 , 7 );
					CLR_BIT( USART5 -> CR1 , 8 );
        
		#elif USART_INTERRUPT == IDLE_INT_ENABLE
		
		           SET_BIT( USART5 -> CR1 , 4 );
		
		#elif USART_INTERRUPT == RXNE_INT_ENABLE

					SET_BIT( USART5 -> CR1 , 5 );

		#elif USART_INTERRUPT == TCE_INT_ENABLE

					SET_BIT( USART5 -> CR1 , 6 );

		#elif USART_INTERRUPT == TXE_INT_ENABLE

					SET_BIT( USART5 -> CR1 , 7 );
					
		#elif USART_INTERRUPT == PE_INT_ENABLE

					SET_BIT( USART5 -> CR1 , 8 );

		#endif

		#if   USART_TRANSMITTER == TRANSMITTER_ENABLE

					SET_BIT( USART5 -> CR1 , 3 );

		#elif USART_TRANSMITTER == TRANSMITTER_DISABLE

					CLR_BIT( USART5 -> CR1 , 3 );

		#endif

		#if   USART_RECEIVER == RECEIVER_ENABLE

					SET_BIT( USART5 -> CR1 , 2 );

		#elif USART_RECEIVER == RECEIVER_DISBLE

					CLR_BIT( USART5 -> CR1 , 2 );
					
		#endif
		

		#if   USART_STOP_BITS == ONE_STOP_BIT

					CLR_BIT( USART5 -> CR2 , 12 ); 
					CLR_BIT( USART5 -> CR2 , 13 );

		#elif USART_STOP_BITS == HALF_STOP_BIT

					SET_BIT( USART5 -> CR2 , 12 ); 
					CLR_BIT( USART5 -> CR2 , 13 );

		#elif USART_STOP_BITS == TWO_STOP_BIT

					CLR_BIT( USART5 -> CR2 , 12 );
					SET_BIT( USART5 -> CR2 , 13 );

		#elif USART_STOP_BITS == ONE_AND_HALF_STOP_BIT

					SET_BIT( USART5 -> CR2 , 12 ); 
					SET_BIT( USART5 -> CR2 , 13 );


		#endif
		USART5 -> BRR = (DIV_Mantissa << 4  ) | ( DIV_Fraction / 100 ) ;
		USART5-> SR = 0 ;

		
	#elif USART_STATUS == USART_DISABLE
		CLR_BIT( USART5 -> CR1 , 13 );
		
	#endif
#endif
   	
}

void  USART1_SEND_CHAR(u8 character)
{
         USART1 -> DR = character ;
		/* wait till transmission is complete  */
		while(((USART1 -> SR ) &(1<<6) )==0);
		CLR_BIT(USART1 -> SR ,6);
}

void  USART2_SEND_CHAR(u8 character)
{
         USART2 -> DR = character ;
		/* wait till transmission is complete  */
		while(((USART2 -> SR ) &(1<<6) )==0);
		CLR_BIT(USART2 -> SR ,6);
}

void  USART3_SEND_CHAR(u8 character)
{
         USART3 -> DR = character ;
		/* wait till transmission is complete  */
		while(((USART3 -> SR ) &(1<<6) )==0);
		CLR_BIT(USART3 -> SR ,6);
}

u8 USART1_Receive (void)
{
 	 while(((USART1 -> SR)&(1<<5))==0);
	return (0xFF&(USART1-> DR ));
	 
}
u8 USART2_Receive (void){
while(((USART2 -> SR) & (1<<5))==0);
	 return (0xFF &(USART2-> DR ));
	
}
u8 USART3_Receive (void)
{ 	
	 while(((USART3 -> SR) & (1<<5))==0);
	 return(0xFF &(USART3-> DR ));
}
	  
 void USART1_SENDSTRING(u8 *ptr_string)
 {
	 u8 i=0;
	 while(ptr_string[i]!='\0')
	 {
		  USART1_SEND_CHAR(ptr_string[i]);
		  i++;
	 }
 }
 
  void USART2_SENDSTRING(u8 *ptr_string)
 {
	 u8 i=0;
	 while(ptr_string[i]!='\0')
	 {
		  USART2_SEND_CHAR(ptr_string[i]);
		  i++;
	 }
 }
 
  void USART3_SENDSTRING(u8 *ptr_string)
 {
	 u8 i=0;
	 while(ptr_string[i]!='\0')
	 {
		  USART3_SEND_CHAR(ptr_string[i]);
		  i++;
	 }
 }
  

void USART1_DMA_Transmit_Init(void){
	
	// usart1
	DMA_SetConfig(1 ,CHANNEL4 , MEMORY_TO_PERIPHERAL , BYTE, BYTE ,  DEACTIVATED,ACTIVATED);
	DMA_VoidSetCircularMode(1 ,CHANNEL4 );
	DMA_VoidConfigPriority(1 ,CHANNEL4, LOW);

}
	
void USART2_DMA_Transmit_Init(void){
	// usart2
	
	DMA_SetConfig(1 ,CHANNEL7 , MEMORY_TO_PERIPHERAL , BYTE , BYTE ,  DEACTIVATED, ACTIVATED);
	DMA_VoidSetCircularMode(1 ,CHANNEL7 );
	DMA_VoidConfigPriority(1 ,CHANNEL7, LOW);
	
}
void USART3_DMA_Transmit_Init(void){
	// usart3
	DMA_SetConfig(1 ,CHANNEL2 , MEMORY_TO_PERIPHERAL , BYTE ,BYTE , DEACTIVATED, ACTIVATED);
	DMA_VoidSetCircularMode(1 ,CHANNEL2 );
	DMA_VoidConfigPriority(1 ,CHANNEL2, LOW);
	
	}



void USART1_DMA_Receiver_Init(void)
{  // usart1
	DMA_SetConfig(1 ,CHANNEL5 , PERIPHERAL_TO_MEMORY , BYTE, BYTE, ACTIVATED, DEACTIVATED);
	DMA_VoidSetCircularMode(1 ,CHANNEL5 );
	DMA_VoidConfigPriority(1 ,CHANNEL5, LOW);
	
}
void USART2_DMA_Receiver_Init(void)
{
	// usart2
	DMA_SetConfig(1 ,CHANNEL6 , PERIPHERAL_TO_MEMORY , BYTE , BYTE , ACTIVATED, DEACTIVATED);
	DMA_VoidSetCircularMode(1 ,CHANNEL6 );
	DMA_VoidConfigPriority(1 ,CHANNEL6, LOW);
	
}
void USART3_DMA_Receiver_Init(void){
	//usart3
	DMA_SetConfig(1 ,CHANNEL3 , PERIPHERAL_TO_MEMORY , BYTE , BYTE , ACTIVATED, DEACTIVATED);
	DMA_VoidSetCircularMode(1 ,CHANNEL3 );
	DMA_VoidConfigPriority(1 ,CHANNEL3, LOW);
}

void USART2_DMA_RECEIVE(u32* recieved[])
{
		
	DMA_VoidSetAddress(1 ,CHANNEL6 , (u32) &USART2->DR , (u32)&recieved , 64 );
	DMA_VoidDMAEnable(1 , CHANNEL6  );
}

/*u8 USART3_DMA_RECEIVE(void)
{
	
  
	DMA_VoidSetAddress(1 ,CHANNEL3 , (u32) &USART3->DR , (u32)&RX_3 , 64 );
	DMA_VoidDMAEnable(1 , CHANNEL3  );
	return &RX_3;
}*/

/*u8 USART1_DMA_RECEIVE(void)
{
	
	
	DMA_VoidSetAddress(1 ,CHANNEL5 , (u32) &USART1->DR , (u32)&RX_1 , 64 );
	DMA_VoidDMAEnable(1 , CHANNEL5  );
	return &RX_1;
}*/


/*void USART1_DMA_Transmit(u8 *Tx_data[]){
 
	USART1->SR =0;
	USART1->DR= Tx_data;
	DMA_VoidSetAddress(1 ,CHANNEL4 , (u32)&TX_1 , (u32) &USART1->DR , 64 );	
	DMA_VoidDMAEnable(1 , CHANNEL4);
}*/


/*void USART2_DMA_Transmit(u8 *Tx_data[]){
 
	USART2->SR =0;
	USART2->DR= Tx_data;
	DMA_VoidSetAddress(1 ,CHANNEL7 , (u32)&TX_2 , (u32) &USART2->DR , 64 );	
	DMA_VoidDMAEnable(1 , CHANNEL7);
}*/

/*void USART3_DMA_Transmit(u8 *Tx_data[]){
 
	USART3->SR =0;
	USART3->DR= Tx_data;
	DMA_VoidSetAddress(1 ,CHANNEL2 , (u32)&TX_3 , (u32) &USART3->DR , 64 );	
	DMA_VoidDMAEnable(1 , CHANNEL2);
}*/
