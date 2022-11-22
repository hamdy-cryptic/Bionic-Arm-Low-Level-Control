/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 24 MAR 2021                            */
/* Version   : 01                                     */
/******************************************************/


#ifndef FSR_INTERFACE_H
#define FSR_INTERFACE_H 

#include "DataTypes_and_BitMath.h"

#include "GPIO_interface.h"
#include "ADC_interface.h"

void fsrInitialize (void);
double fsrIndex_double_Load  (void);     //Function that calculates the load (gm) on the Index finger 
double fsrMiddle_double_Load (void);     //Function that calculates the load (gm) on the Middle finger
double fsrRing_double_Load   (void);     //Function that calculates the load (gm) on the Ring finger
double fsrPinky_double_Load  (void);     //Function that calculates the load (gm) on the Pinky finger
double fsrThumb_double_Load  (void);     //Function that calculates the load (gm) on the Thumb finger

#endif
