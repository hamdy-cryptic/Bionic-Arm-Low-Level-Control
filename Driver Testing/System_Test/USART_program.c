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
//#include "STRING_COMPARE.h"


  void USART_Init(void)
{
     u32  DIV_Mantissa;
	   u32  DIV_Fraction;
    #ifdef usart1 	
		                    
					  
            #if  USART_OVERSAMPLING == USART_OVERSAMPLING_BY_16
			           CLR_BIT( USART1 -> CR1 , 15 );
			         DIV_Mantissa = (fck2)/(16* USART_BAUD_RATE) ;
			         DIV_Fraction= ( ( ( fck2 * 100 ) / ( 16 * USART_BAUD_RATE )  ) % 100 ) * 16 ;
			         if( DIV_Fraction > 1500 )
			             { 
			                DIV_Mantissa += 1 ; 
			                DIV_Fraction  = 0 ; 
			        }
		       #elif   USART_OVERSAMPLING == USART_OVERSAMPLING_BY_8
			   SET_BIT(USART1 -> CR1, 15);  
			 DIV_Mantissa = (fck2)/(8* USART_BAUD_RATE) ;
			 DIV_Fraction= (((fck2 * 100 ) / ( 8 * USART_BAUD_RATE ))% 100) * 8 ;
			 if( DIV_Fraction > 700 )
			 { 
			 DIV_Mantissa += 1 ; 
			 DIV_Fraction  = 0 ; 
			 }
			 #endif
			 
			 
			 #if USART_STATUS == USART_ENABLE

		             SET_BIT(USART1 -> CR1, 13);

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
		           
					  
            #if  USART_OVERSAMPLING == USART_OVERSAMPLING_BY_16
			  CLR_BIT( USART2 -> CR1 , 15 );
			  DIV_Mantissa = (fck1)/(16* USART_BAUD_RATE) ;
			  DIV_Fraction= ( ( ( fck1 * 100 ) / ( 16 * USART_BAUD_RATE )  ) % 100 ) * 16 ;
			 if( DIV_Fraction > 1500 )
			 { 
			 DIV_Mantissa += 1 ; 
			 DIV_Fraction  = 0 ; 
			 }
		       #elif   USART_OVERSAMPLING == USART_OVERSAMPLING_BY_8
			   SET_BIT(USART2 -> CR1, 15);  
			 DIV_Mantissa = (fck1)/(8* USART_BAUD_RATE) ;
			 DIV_Fraction= (((fck1 * 100 ) / ( 8 * USART_BAUD_RATE ))% 100) * 8 ;
			 if( DIV_Fraction > 700 )
			 { 
			 DIV_Mantissa += 1 ; 
			 DIV_Fraction  = 0 ; 
			 }
			 #endif
			 
			 
			 #if USART_STATUS == USART_ENABLE

		             SET_BIT(USART2 -> CR1, 13);

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
		              
            #if  USART_OVERSAMPLING == USART_OVERSAMPLING_BY_16
			  CLR_BIT( USART3 -> CR1 , 15 );
			 DIV_Mantissa = (fck1)/(16* USART_BAUD_RATE) ;
			 DIV_Fraction= ( ( ( fck1 * 100 ) / ( 16 * USART_BAUD_RATE )  ) % 100 ) * 16 ;
			 if( DIV_Fraction > 1500 )
			 { 
			 DIV_Mantissa += 1 ; 
			 DIV_Fraction  = 0 ; 
			 }
		       #elif   USART_OVERSAMPLING == USART_OVERSAMPLING_BY_8
			   SET_BIT(USART3 -> CR1, 15);  
			 DIV_Mantissa = (fck1)/(8* USART_BAUD_RATE) ;
			 DIV_Fraction= (((fck1 * 100 ) / ( 8 * USART_BAUD_RATE ))% 100) * 8 ;
			 if( DIV_Fraction > 700 )
			 { 
			 DIV_Mantissa += 1 ; 
			 DIV_Fraction  = 0 ; 
			 }
			 #endif
			 
			 
			 #if USART_STATUS == USART_ENABLE

		             SET_BIT(USART3 -> CR1, 13);

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
		           
            #if  USART_OVERSAMPLING == USART_OVERSAMPLING_BY_16
			  CLR_BIT( USART4 -> CR1 , 15 );
			 DIV_Mantissa = (fck1)/(16* USART_BAUD_RATE) ;
			 DIV_Fraction= ( ( ( fck1 * 100 ) / ( 16 * USART_BAUD_RATE )  ) % 100 ) * 16 ;
			 if( DIV_Fraction > 1500 )
			 { 
			 DIV_Mantissa += 1 ; 
			 DIV_Fraction  = 0 ; 
			 }
		       #elif   USART_OVERSAMPLING == USART_OVERSAMPLING_BY_8
			   SET_BIT(USART4 -> CR1, 15);  
			 DIV_Mantissa = (fck1)/(8* USART_BAUD_RATE) ;
			 DIV_Fraction= (((fck1 * 100 ) / ( 8 * USART_BAUD_RATE ))% 100) * 8 ;
			 if( DIV_Fraction > 700 )
			 { 
			 DIV_Mantissa += 1 ; 
			 DIV_Fraction  = 0 ; 
			 }
			 #endif
			 
			 
			 #if USART_STATUS == USART_ENABLE

		             SET_BIT(USART4 -> CR1, 13);

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
		        
            #if  USART_OVERSAMPLING == USART_OVERSAMPLING_BY_16
			  CLR_BIT( USART5 -> CR1 , 15 );
			 DIV_Mantissa = (fck1)/(16* USART_BAUD_RATE) ;
			 DIV_Fraction= ( ( ( fck1 * 100 ) / ( 16 * USART_BAUD_RATE )  ) % 100 ) * 16 ;
			 if( DIV_Fraction > 1500 )
			 { 
			 DIV_Mantissa += 1 ; 
			 DIV_Fraction  = 0 ; 
			 }
		       #elif   USART_OVERSAMPLING == USART_OVERSAMPLING_BY_8
			   SET_BIT(USART5 -> CR1, 15);  
			 DIV_Mantissa = (fck1)/(8* USART_BAUD_RATE) ;
			 DIV_Fraction= (((fck1 * 100 ) / ( 8 * USART_BAUD_RATE ))% 100) * 8 ;
			 if( DIV_Fraction > 700 )
			 { 
			 DIV_Mantissa += 1 ; 
			 DIV_Fraction  = 0 ; 
			 }
			 #endif
			 
			 
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
	
 #ifdef usart6 
		           
            #if  USART_OVERSAMPLING == USART_OVERSAMPLING_BY_16
			  CLR_BIT( USART6 -> CR1 , 15 );
			 DIV_Mantissa = (fck2)/(16* USART_BAUD_RATE) ;
			 DIV_Fraction= ( ( ( fck2 * 100 ) / ( 16 * USART_BAUD_RATE )  ) % 100 ) * 16 ;
			 if( DIV_Fraction > 1500 )
			 { 
			 DIV_Mantissa += 1 ; 
			 DIV_Fraction  = 0 ; 
			 }
		       #elif   USART_OVERSAMPLING == USART_OVERSAMPLING_BY_8
			   SET_BIT(USART6 -> CR1, 15);  
			 DIV_Mantissa = (fck2)/(8* USART_BAUD_RATE) ;
			 DIV_Fraction= (((fck2 * 100 ) / ( 8 * USART_BAUD_RATE ))% 100) * 8 ;
			 if( DIV_Fraction > 700 )
			 { 
			 DIV_Mantissa += 1 ; 
			 DIV_Fraction  = 0 ; 
			 }
			 #endif
			 
			 
			 #if USART_STATUS == USART_ENABLE

		             SET_BIT(USART6 -> CR1, 13);

		    #if   USART_WORD_LENGTH == 8

					CLR_BIT( USART6 -> CR1 , 12 );

		#elif USART_WORD_LENGTH ==   9

					SET_BIT( USART6 -> CR1 , 12 );

		#endif

		#if   USART_CONTROL_PARITY == PARITY_CONTROL_DISABLE

					CLR_BIT( USART6 -> CR1 , 10 );

		#elif USART_CONTROL_PARITY == EVEN_PARITY

					SET_BIT( USART6 -> CR1 , 10 );
					CLR_BIT( USART6 -> CR1 , 9 );

		#elif USART_CONTROL_PARITY == ODD_PARITY

					SET_BIT( USART6 -> CR1 , 10 );
					SET_BIT( USART6 -> CR1 , 9 );

		#endif

		#if  USART_INTERRUPT == INT_DISABLE

                    CLR_BIT( USART6 -> CR1 , 4 );
					CLR_BIT( USART6 -> CR1 , 5 );
					CLR_BIT( USART6 -> CR1 , 6 );
					CLR_BIT( USART6 -> CR1 , 7 );
					CLR_BIT( USART6 -> CR1 , 8 );
        
		#elif USART_INTERRUPT == IDLE_INT_ENABLE
		
		           SET_BIT( USART6 -> CR1 , 4 );
		
		#elif USART_INTERRUPT == RXNE_INT_ENABLE

					SET_BIT( USART6 -> CR1 , 5 );

		#elif USART_INTERRUPT == TCE_INT_ENABLE

					SET_BIT( USART6 -> CR1 , 6 );

		#elif USART_INTERRUPT == TXE_INT_ENABLE

					SET_BIT( USART6 -> CR1 , 7 );
					
		#elif USART_INTERRUPT == PE_INT_ENABLE

					SET_BIT( USART6 -> CR1 , 8 );

		#endif

		#if   USART_TRANSMITTER == TRANSMITTER_ENABLE

					SET_BIT( USART6 -> CR1 , 3 );

		#elif USART_TRANSMITTER == TRANSMITTER_DISABLE

					CLR_BIT( USART6 -> CR1 , 3 );

		#endif

		#if   USART_RECEIVER == RECEIVER_ENABLE

					SET_BIT( USART6 -> CR1 , 2 );

		#elif USART_RECEIVER == RECEIVER_DISBLE

					CLR_BIT( USART6 -> CR1 , 2 );

		#endif
         
		
		#if    USART_HW_FLOW_CONTROL == USART_CTS 
		         SET_BIT(USART6 -> CR3 , 9);
		#elif   USART_HW_FLOW_CONTROL == USART_RTS 
		         SET_BIT(USART6 -> CR3 , 8)	;	 
		#elif   USART_HW_FLOW_CONTROL == USART_CTS_RTS 
		         SET_BIT(USART6 -> CR3 , 8) ;
						 SET_BIT(USART6 -> CR3 , 9);
	    #elif   USART_HW_FLOW_CONTROL == USART_NO_CTS_RTS
		         CLR_BIT(USART6 -> CR3 , 8) ;
						 CLR_BIT(USART6 -> CR3 , 9);
		#endif
				 
		#if   USART_STOP_BITS == ONE_STOP_BIT

					CLR_BIT( USART6 -> CR2 , 12 ); 
					CLR_BIT( USART6 -> CR2 , 13 );

		#elif USART_STOP_BITS == HALF_STOP_BIT

					SET_BIT( USART6 -> CR2 , 12 ); 
					CLR_BIT( USART6 -> CR2 , 13 );

		#elif USART_STOP_BITS == TWO_STOP_BIT

					CLR_BIT( USART6 -> CR2 , 12 );
					SET_BIT( USART6 -> CR2 , 13 );

		#elif USART_STOP_BITS == ONE_AND_HALF_STOP_BIT

					SET_BIT( USART6 -> CR2 , 12 ); 
					SET_BIT( USART6 -> CR2 , 13 );

        

		#endif
		USART6 -> BRR = (DIV_Mantissa << 4  ) | ( DIV_Fraction / 100 ) ;
		USART6-> SR = 0 ;

		
	#elif USART_STATUS == USART_DISABLE
		CLR_BIT( USART6 -> CR1 , 13 );
		

	#endif
#endif
	
}

	 void  USART_SEND_CHAR(u8 character)
{
 
 
#ifdef  usart1 
	
		  USART1 -> DR = character ;
		/* wait till transmission is complete  */
		while(((USART1 -> SR ) & 0x40 )==0);
		CLR_BIT(USART1 -> SR ,6);
	
#endif
     #ifdef  usart2 
	 
         USART2 -> DR = character ;
		/* wait till transmission is complete  */
		while(((USART2 -> SR ) &(1<<6) )==0);
		CLR_BIT(USART2 -> SR ,6);
#endif
    #ifdef  usart3 
       USART3 -> DR = character ;
		/* wait till transmission is complete  */
		while(((USART3 -> SR ) & 0x40 )==0);
		CLR_BIT(USART3 -> SR ,6);
#endif
     #ifdef usart4 
        USART4 -> DR = character ;
		/* wait till transmission is complete  */
		while(((USART4 -> SR ) & 0x40 )==0);
		CLR_BIT(USART4 -> SR ,6);
#endif
   #ifdef  usart5 
        USART5 -> DR = character ;
		/* wait till transmission is complete  */
		while(((USART5 -> SR ) & 0x40 )==0);
		CLR_BIT(USART5 -> SR ,6);
	#endif
  #ifdef usart6 
         USART6 -> DR = character ;
		/* wait till transmission is complete  */
		while(((USART6 -> SR ) & 0x40 )==0);
		CLR_BIT(USART6 -> SR ,6);
	#endif
	
}	


   u8   USART_Receive (void)
{
#ifdef  usart1 	
	 while(((USART1 -> SR)&(1<<5))==0);
	 return (0xFF&(USART1-> DR ));
#endif
    #ifdef usart2	
	 while(((USART2 -> SR) & (1<<5))==0);
	 return (0xFF &(USART2-> DR ));
	#endif
	 
 #ifdef usart3 	
	 while(((USART3 -> SR) & 0X40)==0);
	 return (0xFF &(USART3-> DR ));
	 #endif
	 
 #ifdef usart4	
	 while(((USART4 -> SR) & 0X40)==0);
	 return (0xFF &(USART4-> DR ));
	 #endif
	 
#ifdef usart5 	
	 while(((USART5 -> SR) & 0X40)==0);
	 return (0xFF &(USART5-> DR ));
	 #endif
	 
#ifdef  usart6 	
	 while(((USART6 -> SR) & 0X40)==0);
	 return (0xFF &(USART6-> DR ));
	 #endif
 }
 
 
 void USART_SENDSTRING(u8 *ptr_string)
 {
	 u8 i=0;
	 while(ptr_string[i]!='\0')
	 {
		  USART_SEND_CHAR(ptr_string[i]);
		  i++;
	 }
 }
 
 


