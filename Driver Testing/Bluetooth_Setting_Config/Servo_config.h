/*************************************************************
   File:       config of Servo Driver                        *
   Author:      Yomna Abdelhameed                            *
   Version:     V01                                          *
   Date:        06/4/2021                                    *
*************************************************************/


#ifndef SERVO_CONFIG_H
#define SERVO_CONFIG_H

/*This configuration file is used to tell the driver what is the operating clock of 
   the timers on APB1 and APB2 Buses. This info is vital because it is used in calculating
   the period of the pwm signal sent to the servos in use.
   
   The value written in this configuration file should be after applying any prescaler to 
   timer clock if needed
   */
   
   
//APB1 Timers are: TIM2, TIM3, TIM4, TIM5   (Default frequency is 1MHz)
#define SERVO_TIM_CLOCK_APB1           1

//APB2 Timers are: TIM1, TIM8               (Default frequency is 2MHz)
#define SERVO_TIM_CLOCK_APB2           2


#endif