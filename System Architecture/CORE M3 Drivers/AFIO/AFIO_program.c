/*********************************************************/
/*Author     : youstina                                  */
/*version    : v01                                       */
/*date       : 10 DEC 2020                                */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
//#include "AFIO_config.h"


void AFIO_TIM3_MAP(u8 remap_value){
	AFIO->MAPR &=~(3<<10);      //Reset Tim3 Selection
	AFIO->MAPR &=~(7<<24);      //Reset Debugging Pins
	AFIO->MAPR |= (1<<24);      //Set debugging pins to release PB4
	if(remap_value < 4){
		AFIO->MAPR |= (remap_value<<10);
	}
}
void AFIO_TIM2_MAP(u8 remap_value){
		AFIO->MAPR &=~(3<<8);
	if(remap_value < 4){
		AFIO->MAPR |= (remap_value<<8);
	}
}

 void AFIO_Set(u8 AFIO_PORT , u8 AFIO_PIN ){
	 AFIO->EVCR =0X00;
	 SET_BIT(AFIO->EVCR,7);
	 switch(AFIO_PORT)
	 {
		 case AFIO_PA: AFIO->EVCR |=(AFIO_PA<<4); break;
		 case AFIO_PB: AFIO->EVCR |=(AFIO_PB<<4); break; 
         case AFIO_PC: AFIO->EVCR |=(AFIO_PC<<4); break;
         case AFIO_PD: AFIO->EVCR |=(AFIO_PD<<4); break;	
         case AFIO_PE: AFIO->EVCR |=(AFIO_PE<<4); break;	
         default: break;		 
	 } 
	 switch(AFIO_PIN)
	 {
		 case AFIO_PIN0:   AFIO->EVCR |=(AFIO_PIN0); break;
		 case AFIO_PIN1:   AFIO->EVCR |=(AFIO_PIN1); break;
		 case AFIO_PIN2:   AFIO->EVCR |=(AFIO_PIN2); break;
		 case AFIO_PIN3:   AFIO->EVCR |=(AFIO_PIN3); break;
		 case AFIO_PIN4:   AFIO->EVCR |=(AFIO_PIN4); break;
		 case AFIO_PIN5:   AFIO->EVCR |=(AFIO_PIN5); break;
		 case AFIO_PIN6:   AFIO->EVCR |=(AFIO_PIN6); break;
		 case AFIO_PIN7:   AFIO->EVCR |=(AFIO_PIN7); break;
		 case AFIO_PIN8:   AFIO->EVCR |=(AFIO_PIN8); break;
		 case AFIO_PIN9:   AFIO->EVCR |=(AFIO_PIN9); break;
		 case AFIO_PIN10:  AFIO->EVCR |=(AFIO_PIN10); break;
		 case AFIO_PIN11:  AFIO->EVCR |=(AFIO_PIN11); break;
		 case AFIO_PIN12:  AFIO->EVCR |=(AFIO_PIN12); break;
		 case AFIO_PIN13:  AFIO->EVCR |=(AFIO_PIN13); break;
		 case AFIO_PIN14:  AFIO->EVCR |=(AFIO_PIN14); break;
		 case AFIO_PIN15:  AFIO->EVCR |=(AFIO_PIN15); break;
		 default: break;
	 }
	 
 }

void	AFIO_voidSetEXTIConfiguration(u8 Copy_u8Line ,u8 Copy_u8PortMap)
{
	u8 volatile Local_u8RegIndex = 0 ;		
	/* Assign to EXTICRX register	*/
	if(Copy_u8Line <= 3 )
	{
			Local_u8RegIndex = 0;
	}
	else if(Copy_u8Line<=7)
	{
			/*	another	solution	                */
			/*	line 7 => 1....                         */
			/*	Local_u8RegIndex = copy_u8Line/4	*/
			/*	copy_u8Line = copy_u8Line%4 => (3 in the EXTICR2)*/	
		Local_u8RegIndex = 1;
		Copy_u8Line -= 4;
	}
	else if(Copy_u8Line<=11)
	{
		Local_u8RegIndex = 2;
		Copy_u8Line -= 8;
	
	}
	else if(Copy_u8Line<=15)
	{
		Local_u8RegIndex = 3;
		Copy_u8Line -= 12;
	}
	AFIO->EXTICR[Local_u8RegIndex] &= ~((0b1111) << (Copy_u8Line * 4));
	AFIO->EXTICR[Local_u8RegIndex]  |= ((Copy_u8PortMap) << (Copy_u8Line * 4));	
}