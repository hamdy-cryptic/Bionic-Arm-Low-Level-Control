/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 24 MAR 2021                            */
/* Version   : 01                                     */
/******************************************************/



#ifndef FSR_CONFIGURATION_H
#define FSR_CONFIGURATION_H 

#include "DataTypes_and_BitMath.h"

#define GPIO_SPEED 3      // 0: 2 MHz ..... 1:25 MHz .... 2: 50 MHz .... 3: 100 MHz

#define FSR_PORT  'A'     // A,B,C,D,E,F,G,H

#define FSR_PIN    0      // 0 ... 15

#define ADC_PA     0      // 0 ... 15

/* All five curve equation of the force sensors are polynomial of degree 5 and has the form:*/

/* load = (p1*pow(fsrResistance,4)) + (p2*pow(fsrResistance,3)) + (p3*pow(fsrResistance,2)) + (p4*fsrResistance) + (p5) */

#endif
