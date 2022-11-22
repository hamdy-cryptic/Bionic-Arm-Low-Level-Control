/******************************************************************/
/* File    : Encoder Private File (USER USAGE IS BANNED)          */
/* Date    : 2/4/2021                                             */
/* Version : V01                                                  */
/* Updates : ---                                                  */
/* Author  : Hamdy Osama                                          */
/******************************************************************/


#ifndef ENCODER_PRIVATE_H
#define ENCODER_PRIVATE_H

// variable types used by the encoder driver.
#include "STD_TYPES.h"

void ENCODER_Init(encoder_t *encoder);           //Used to initialize the encoder pins (as described below)

typedef volatile struct {
	u32 volatile speed;
	u8  volatile direction;
	u32 volatile position;
	s32 volatile revolutions;
	u8  volatile pins_set;
} encoder_t;

#endif