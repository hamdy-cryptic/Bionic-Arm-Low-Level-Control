/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 24 MAR 2021                            */
/* Version   : 01                                     */
/******************************************************/

#ifndef FSR_PRIVATE_H
#define FSR_PRIVATE_H 

#include "DataTypes_and_BitMath.h"

/*************** Index Parameters *************/

#define INDEX_a 9.486e+12
#define INDEX_b -2.486

/*************** Middle Parameters *************/

#define Middle_a 1.373e+10
#define Middle_b -1.719

/*************** Ring Parameters *************/

#define Ring_a 6.724e+13
#define Ring_b -2.698

/*************** Pinky Parameters *************/

#define Pinky_a 
#define Pinky_b 

/*************** Thumb Parameters *************/

#define Thumb_a 8.608e+08
#define Thumb_b -1.484

uint32 Power (uint32 x, uint32 y);

#endif
