/******************************************************************/
/* File    : PID Program File with driver logic               */
/*               (USER MODIFICATION IS BANNED)                    */
/* Date    : 24/6/2021                                             */
/* Version : V01                                                  */
/* Updates : ---                                                  */
/* Author  : Hamdy Osama                                          */
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "POT_interface.h"
#include "DC_motor.h"

#include "PID_private.h"
#include "PID_config.h"
#include "PID_interface.h"





void PID_Init(PID_t *my_pid, f32 kp, f32 ki, f32 kd, f32 lower_limit, f32 upper_limit, u8 channel){
	//Initialize PID Parameters.. For more info about these parameters, check Mechatronics Lecture 6 of Discretizing control
	my_pid -> pid_A = (kp + ((ki * PID_TS )/2) + (kd/PID_TS));
	my_pid -> pid_B = (((kp * PID_TS )/2) - (kd /PID_TS));
	my_pid -> pid_C = ki;
	my_pid -> lower_limit = lower_limit;
	my_pid -> upper_limit = upper_limit;
	my_pid -> pid_sensor_channel = channel;
	//Initialize PID output and calculations with a value of zero
	my_pid -> pid_output = 0;
	my_pid -> pid_error = 0;
	my_pid -> pid_prev_error = 0;
	my_pid -> pid_prev_int = 0;
	
	}



s32 PID_s32ControlOutput (PID_t *my_pid, f32 desired_position){
	//Get current position
	f32 current_position = Pot_f32GetAngle(my_pid -> pid_sensor_channel);
	//Calculate Error 
	my_pid ->pid_error = desired_position - current_position;
	//Get PID Controller output
	my_pid -> pid_output = my_pid -> pid_A * my_pid ->pid_error + my_pid -> pid_B * my_pid -> pid_prev_error + my_pid -> pid_C * my_pid -> pid_prev_int;
	//update previous error values and previous integral area
	my_pid -> pid_prev_int = my_pid -> pid_prev_int + ( ((my_pid ->pid_error + my_pid -> pid_prev_error)/2) * PID_TS );
	my_pid -> pid_prev_error = my_pid ->pid_error;
	//Return controller output
	return my_pid -> pid_output;
	
	
}
				
	






