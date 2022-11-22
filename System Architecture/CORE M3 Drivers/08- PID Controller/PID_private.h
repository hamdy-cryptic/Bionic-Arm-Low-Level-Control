/******************************************************************/
/* File    : PID Private File (USER USAGE IS BANNED)              */
/* Date    : 24/6/2021                                             */
/* Version : V01                                                  */
/* Updates : ---                                                  */
/* Author  : Hamdy Osama                                          */
/******************************************************************/


#ifndef PID_PRIVATE_H
#define PID_PRIVATE_H

// variable types used by the PID driver.
#include "STD_TYPES.h"

typedef volatile struct {
	f32 volatile lower_limit;
	f32 volatile upper_limit;
	u8 volatile pid_sensor_channel;
	s32 volatile pid_output;
	f32 volatile pid_error;
	f32 volatile pid_prev_error;
	f32 volatile pid_prev_int;
	f32 volatile pid_A;
	f32 volatile pid_B;
	f32 volatile pid_C;
} PID_t;

#endif