/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 11 JAN 2021                            */
/* Version   : 01                                     */
/******************************************************/

#include "DataTypes_and_BitMath.h"

#ifndef BTIMER_INTERFACE_H
#define BTIMER_INTERFACE_H 				                               

void MBTimer_void_STimer (uint32 TIM_NUM, uint32 time_ms, void (*interr_funct_name)(void));    
//Single timer function of basic timers, depending on your decesion (6 or 7)

void MBTimer_void_PTimer (uint32 TIM_NUM, uint32 time_ms, void (*interr_funct_name)(void));    
//Periodic timer function of basic timers, depending on your decesion (6 or 7)

#endif
