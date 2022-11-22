/**********************************************/
/* Author    : Hamdy Osama Mohamed            */
/* File      : App Function of the PALM MCU   */
/* Date      : 9/7/2021                       */
/* Version   :   V01                          */
/**********************************************/

#ifndef PALM_H
#define PALM_H

 #include "STD_TYPES.h"
 #define APP_PALM_FUNCTIONS_H

 void Palm_Initialize();
 void Palm_Pin_Remap();
 
 u8 Sync_Recieved_Data(u8 POS_Info);
 
 void Palm_MUX_Init(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2, u8 Copy_u8Pin3);
 void Palm_MUX_RESET(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2, u8 Copy_u8Pin3);
 void Palm_MUX_SET(u8 Copy_u8Port, u8 Copy_u8Pin1, u8 Copy_u8Pin2, u8 Copy_u8Pin3);
 
 void Palm_Move_Index(u8 desired_pos);
 void Palm_Move_Middle(u8 desired_pos);
 void Palm_Move_Ring(u8 desired_pos);
 void Palm_Move_Pinky(u8 desired_pos);


//Important Definitions

#define INDEX_INFO      0 
#define MIDDLE_INFO     1
#define RING_INFO       2
#define PINKY_INFO      3
#define THUMB_INFO      4
#define WRIST1_INFO     5
#define WRIST2_INFO     6


#endif


