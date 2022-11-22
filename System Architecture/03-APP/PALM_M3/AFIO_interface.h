/*********************************************************/
/*Author     : youstina                                  */
/*version    : v01                                       */
/*date       : 10 DEC 2020                                */
/*********************************************************/



#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

#include "STD_TYPES.h"

void AFIO_TIM3_MAP(u8 remap_value);
/*Remap_Value OPTIONS:
	0: No remap (CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1)
	1: Not used
	2: Partial remap (CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1)
	3: Full remap (CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9)
	
*/

void AFIO_TIM2_MAP(u8 remap_value);

/*Remap_Value OPTIONS:
	0: No remap (CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3)
	1: Partial remap (CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3)
	2: Partial remap (CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11)
	3: Full remap (CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11)
*/

void AFIO_voidSetEXTIConfiguration(u8 Copy_u8Line ,u8 Copy_u8PortMap); //Set the port used with the EXTI Line
/*Options for Copy_u8Line
from 0   to  15
*/
 void AFIO_Set(u8 AFIO_PORT , u8 AFIO_PIN );
 
/* Options for  AFIO_PORT */
#define AFIO_PA      0b000
#define AFIO_PB      0b001
#define AFIO_PC      0b010
#define AFIO_PD      0b011
#define AFIO_PE      0b100

/* Options for AFIO_PIN */
#define AFIO_PIN0     0b0000
#define AFIO_PIN1     0b0001
#define AFIO_PIN2     0b0010
#define AFIO_PIN3     0b0011
#define AFIO_PIN4     0b0100
#define AFIO_PIN5     0b0101
#define AFIO_PIN6     0b0110
#define AFIO_PIN7     0b0111
#define AFIO_PIN8     0b1000
#define AFIO_PIN9     0b1001
#define AFIO_PIN10    0b1010
#define AFIO_PIN11    0b1011
#define AFIO_PIN12    0b1100
#define AFIO_PIN13    0b1101
#define AFIO_PIN14    0b1110
#define AFIO_PIN15    0b1111




/*Options for Copy_u8PortMap*/
#define AFIO_PORTA  0b0000
#define AFIO_PORTB  0b0001
#define AFIO_PORTC  0b0010
#define AFIO_PORTD  0b0011
#define AFIO_PORTE  0b0100
#define AFIO_PORTF  0b0101
#define AFIO_PORTG  0b0110


#endif