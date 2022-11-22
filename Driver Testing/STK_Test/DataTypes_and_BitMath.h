/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 15 DEC 2020                            */
/* Version   : 1                                      */
/******************************************************/

//#include <stm32f446xx.h>
#ifndef DATATYPES_AND_BITMATH
#define DATATYPES_AND_BITMATH

// Data types names used in the driver //

typedef unsigned short int 		    uint16;
typedef unsigned long int 		    uint32;
typedef unsigned char 				uch8;
typedef unsigned char 				sch8; 

#endif

// Bit Math used in the driver //

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)          VAR |=  (1 << (BIT))
#define CLR_BIT(VAR,BIT)          VAR &= ~(1 << (BIT)) 
#define GET_BIT(VAR,BIT)          ((VAR >> BIT) & 1  )
#define TOG_BIT(VAR,BIT)          VAR ^=  (1 << (BIT))

#endif
