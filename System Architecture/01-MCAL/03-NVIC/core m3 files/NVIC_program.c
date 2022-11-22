/*********************************************************/
/*Author    : youstina                                   */
/*version   : v01                                        */
/*date      : 8 DEC 2020                                 */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
//#include "NVIC_config.h"



void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{

   if ( Copy_u8IntNumber <=31 )
       {
        NVIC_ISER0 = (1<<Copy_u8IntNumber);
       }

    else if ( Copy_u8IntNumber <=63 )
       {
	    Copy_u8IntNumber -= 32;
        NVIC_ISER1 = (1<<Copy_u8IntNumber) ;
       }
    
	else if ( Copy_u8IntNumber <=95 )
       {
	    Copy_u8IntNumber -= 64;
        NVIC_ISER2 = (1<<Copy_u8IntNumber) ;
       }
	   
    else if ( Copy_u8IntNumber <=127 )
       {
	    Copy_u8IntNumber -= 96;
        NVIC_ISER3 = (1<<Copy_u8IntNumber) ;
       }
    
    else 
	   { 
	       /*  return error  */
	   }
}


void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{

   if ( Copy_u8IntNumber <=31 )
       {
        NVIC_ICER0 = (1<<Copy_u8IntNumber);
       }

    else if ( Copy_u8IntNumber <=63 )
       {
	    Copy_u8IntNumber -= 32;
        NVIC_ICER1 = (1<<Copy_u8IntNumber) ;
       }

    else if ( Copy_u8IntNumber <=95 )
       {
	    Copy_u8IntNumber -= 64;
        NVIC_ICER2 = (1<<Copy_u8IntNumber) ;
       }
    
	    else if ( Copy_u8IntNumber <=127 )
       {
	    Copy_u8IntNumber -= 96;
        NVIC_ICER3 = (1<<Copy_u8IntNumber) ;
       }

    else 
	   { 
	       /*  return error  */
	   }
}

void MNVIC_voidSetPendingFlag (u8 Copy_u8IntNumber)
{
   if ( Copy_u8IntNumber <=31 )
       {
        NVIC_ISPR0 = (1<<Copy_u8IntNumber);
       }

    else if ( Copy_u8IntNumber <=63 )
       {
	    Copy_u8IntNumber -= 32;
        NVIC_ISPR1 = (1<<Copy_u8IntNumber) ;
       }

    else if ( Copy_u8IntNumber <=95 )
       {
	    Copy_u8IntNumber -= 64;
        NVIC_ISPR2 = (1<<Copy_u8IntNumber) ;
       }
    
	    else if ( Copy_u8IntNumber <=127 )
       {
	    Copy_u8IntNumber -= 96;
        NVIC_ISPR3 = (1<<Copy_u8IntNumber) ;
       }

    else 
	   { 
	       /*  return error  */
	   }
}

void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber)
{
   if ( Copy_u8IntNumber <=31 )
       {
        NVIC_ICPR0 = (1<<Copy_u8IntNumber);
       }

    else if ( Copy_u8IntNumber <=63 )
       {
	    Copy_u8IntNumber -= 32;
        NVIC_ICPR1 = (1<<Copy_u8IntNumber) ;
       }
    
    else if ( Copy_u8IntNumber <=95 )
       {
	    Copy_u8IntNumber -= 64;
        NVIC_ICPR2 = (1<<Copy_u8IntNumber) ;
       }
    
    else if ( Copy_u8IntNumber <=127 )
       {
	    Copy_u8IntNumber -= 96;
        NVIC_ICPR3 = (1<<Copy_u8IntNumber) ;
       }
    
    else 
	   { 
	       /*  return error  */
	   }
}

u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber)
{
   u8 Local_u8Result ;
   if ( Copy_u8IntNumber <=31 )
       {
        Local_u8Result = GET_BIT(NVIC_IABR0 , Copy_u8IntNumber);
       }

    else if ( Copy_u8IntNumber <=63 )
       {
	    Copy_u8IntNumber -= 32;
	    Local_u8Result = GET_BIT(NVIC_IABR1 , Copy_u8IntNumber);
       }
    
    else if ( Copy_u8IntNumber <=95 )
       {
	    Copy_u8IntNumber -= 64;
	    Local_u8Result = GET_BIT(NVIC_IABR2 , Copy_u8IntNumber);
       }
    
    else if ( Copy_u8IntNumber <=127 )
       {
	    Copy_u8IntNumber -= 96;
	    Local_u8Result = GET_BIT(NVIC_IABR3 , Copy_u8IntNumber);
       }
    
    else 
	   { 
	       /*  return error  */
	   }
	   return Local_u8Result ;
}


void MNVIC_voidSetPriority (s8 copy_s8IntID , u8 copy_u8GroupPriority , u8 copy_u8SubPriority , u32 copy_u32Group)
{
    u8 Local_u8Priority = copy_u8SubPriority | (copy_u8GroupPriority<<((copy_u32Group - 0x05FA0300 )/256)) ;
	/* core peripheral */
	
	/* external peripheral */
	
    if (copy_s8IntID >= 0)
	{
	    NVIC_IPR[copy_s8IntID] = Local_u8Priority << 4 ;
	
	}
SCB_AIRCR = copy_u32Group ;

}
