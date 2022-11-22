/***********************************************************************/
/* File    : Encoder Configuration File to alter the driver features   */
/* Date    : 2/4/2021                                                  */
/* Version : V01                                                       */
/* Updates : ---                                                       */
/* Author  : Hamdy Osama                                               */
/***********************************************************************/


#ifndef ENCODER_CONFIG_H
#define ENCODER_CONFIG_H

/*This part of the folder have general configuration that describe the properties of the encoder activated
	OPTIONS:
	1- Encoder Edges per Revolution (ENCODER_EPR)
	2- Timer Operation clock speed in MHz (ENC_TIM_CLK)
*/

 /*1- Encoder Edges per revolution: this number indicates the resolution of the used encoder (Pulses * 2) */
 
 #define ENCODER_EPR    14
 
 /*2- Timer Operation clock speed: the clock speed of the encoder timers in MHz*/

 #define ENC_TIM_CLK    45 


#endif