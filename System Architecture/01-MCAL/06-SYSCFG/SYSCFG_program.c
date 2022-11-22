/*********************************************************/
/*Author     : youstina                                  */
/*version    : v01                                       */
/*date       : 10 DEC 2020                                */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSCFG_interface.h"
#include "SYSCFG_private.h"
#include "SYSCFG_config.h"



void	MSYSCFG_voidSetEXTIConfiguration(u8 Copy_u8Line ,u8 Copy_u8PortMap)
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
	SYSCFG->EXTICR[Local_u8RegIndex] &= ~((0b1111) << (Copy_u8Line * 4));
	SYSCFG->EXTICR[Local_u8RegIndex]  |= ((Copy_u8PortMap) << (Copy_u8Line * 4));	
}
