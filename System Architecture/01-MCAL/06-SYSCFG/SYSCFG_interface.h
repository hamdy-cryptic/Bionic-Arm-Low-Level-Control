/*********************************************************/
/*Author     : youstina                                  */
/*version    : v01                                       */
/*date       : 10 DEC 2020                               */
/*********************************************************/
#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H
#include <STD_TYPES.h>

void MSYSCFG_voidSetEXTIConfiguration(u8 Copy_u8Line ,u8 Copy_u8PortMap); //Set the port used with the EXTI Line
/*Options for Copy_u8Line
from 0   to  15
*/

/*Options for Copy_u8PortMap*/
#define SYSCFG_PORTA  0b0000
#define SYSCFG_PORTC  0b0010

#endif