/********************************************************
   File:        ADC Functions and Macros (interace)     *
   Author:      Hamdy Osama Mohamed                     *
   Version:     V01                                     *
   Date:        6/12/2020                               *
   Updates:     ----                                    *
********************************************************/
   
   #ifndef ADC_INTERFACE_H
   #define ADC_INTERFACE_H
   
   
   void  MADC_voidInit(void); //Used to initialize ADC in system
   
   u16   MADC_u16AnalogSingleRead(u8 Copy_u8Channel); 
   //Used to read single one channel and return conversion value
   /* Copy_u8Channel OPTIONS:
   Takes values in numerical form from 0 to 15
   0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
   */
   
   
   #endif



