/******************************************************************/
/* File    : PID Interface File  to use the driver features       */
/* Date    : 24/6/2021                                             */
/* Version : V01                                                  */
/* Updates : ---                                                  */
/* Author  : Hamdy Osama                                          */
/******************************************************************/


#ifndef PID_INTERFACE_H
#define PID_INTERFACE_H
#include "STD_TYPES.h"
#include "PID_private.h"

void PID_Init(PID_t *my_pid, f32 kp, f32 ki, f32 kd, f32 lower_limit, f32 upper_limit, u8 channel);   //Initialize PID Controller
s32 PID_s32ControlOutput (PID_t *my_pid, f32 desired_position);                                       //Get controller output to be used to actuate motors

/*
IMPORTANT NOTE: you should initialize potentiometer first before using pid driver.
+ use channel names as stated in potentiometer driver.
*/


/*Steps to use the driver:
	1- Define a variable of the type PID_t that represents a pid instance. Check the following example for illustration
	2- Start PID control to return the controller output
*/

/*Defining a vaiable of type PID_t example: 
	PID_t my_pid;
	PID_Init(&my_pid,1,1,1,0,90,POT_PA0);
*/

#endif
