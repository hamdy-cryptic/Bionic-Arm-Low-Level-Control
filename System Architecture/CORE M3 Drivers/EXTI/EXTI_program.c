/*********************************************************/
/*Author     : youstina                                  */
/*version    : v01                                       */
/*date       : 9 DEC 2020                                */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
				 
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


#define NULL		(void * )0

static void (* EXTI0_CallBack) (void) = NULL ;

/* ENABLED AT PREPROCESSING TIME ACCORDING TO THE CONFIGURED VALUE IN CONFIG FILE  */
void MEXTI_voidInit (void)
{
        SET_BIT(EXTI -> IMR , EXTI_LINE);

    #if EXTI_MODE == RISING 
        SET_BIT(EXTI -> RTSR , EXTI_LINE);   
	#elif EXTI_MODE == FALLING 
        SET_BIT(EXTI -> FTSR , EXTI_LINE);   
	#elif EXTI_MODE == ON_CHANGE 
        SET_BIT(EXTI -> RTSR , EXTI_LINE);
		SET_BIT(EXTI -> FTSR , EXTI_LINE);	
    #else
    	#error (" wrong external interrupt sense mode ! ")
	#endif
       /*DISABLE INTERRUPT AT INITIALIZATION*/
	   // CLR_BIT(EXTI -> IMR , EXTI_LINE);

}


/* ENABLED AT RUN TIME */
void MEXTI_voidEnableEXTI (u8 Copy_u8Line)
{
    SET_BIT(EXTI -> IMR , Copy_u8Line);
}

void MEXTI_voidDisableEXTI (u8 Copy_u8Line)
{
    CLR_BIT(EXTI -> IMR , Copy_u8Line);
}

void MEXTI_voidSwTrigger (u8 Copy_u8Line)
{
    SET_BIT(EXTI -> IMR , Copy_u8Line);
    SET_BIT(EXTI -> SWIER , Copy_u8Line);
	  SET_BIT(EXTI -> PR , Copy_u8Line);

}

/* ENABLED AT RUN TIME */
void MEXTI_voidSetSignalLatch (u8 Copy_u8Line , u8 Copy_u8Mode)
{
    switch(Copy_u8Mode)
	{
         case RISING:         SET_BIT(EXTI -> RTSR , Copy_u8Line); break;
         case FALLING:        SET_BIT(EXTI -> FTSR , Copy_u8Line); break;
         case ON_CHANGE:      SET_BIT(EXTI -> RTSR , Copy_u8Line); 
		                      SET_BIT(EXTI -> FTSR , Copy_u8Line); break;		 
	
	}
}



void MEXTI_voidSetCallBack (void (*ptr)(void))
{
   EXTI0_CallBack = ptr ;

}

void	 EXTI15_10_IRQHandler(void)
{
	EXTI0_CallBack();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI -> PR , 0);
	
}