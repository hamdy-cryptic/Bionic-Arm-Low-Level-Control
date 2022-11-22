/************************************************************
   Author  :  Omaima                                         
   Date    : 6/6/2021                                         
   Version : V01                                             
*************************************************************/
#ifndef  SMBUS_CONFIG_H
#define  SMBUS_CONFIG_H

/**** NOTE: you'll need to enable pin clocks if it isn't   for I2C_1 --> RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
                                                                         RCC_voidEnableClock(RCC_APB1,RCC_I2C1);
																		 
														    for I2C_2 --> RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
                                                                          RCC_voidEnableClock(RCC_APB1,RCC_I2C2);
																		  
                                                           for I2C_3 --> RCC_voidEnableClock(RCC_AHB1,RCC_GPIOA);
														                 RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB); 
                                                                         RCC_voidEnableClock(RCC_APB1,RCC_I2C3);																		 
															
												                  ****/
/*** SMBUS_I2C_1    :   SCL1 --> PB6  , SDA1 --> PB7  ,  SMBA1 --> PB5
     SMBUS_I2C_2    :   SCL2 --> PB10 , SDA2 --> PB3  , SMBA2 --> PB12
	 SMBUS_I2C_2    :   SCL3 --> PA8  , SDA3 --> PB4  , SMBA3 --> PA9
                        PB8 --> SCL1 (SDA3)  , PB9 --> SDA1 (SDA2)      ***/
						
				
#define SMBUS_I2C1
//#define SMBUS_I2C2
//#define SMBUS_I2C3

// SMBUS_I2C_DEVICE  || SMBUS_I2C_HOST 

#define SMBUS_I2C_TYPE    SMBUS_I2C_HOST 

//  SMBUS_I2C_DUTY_2     ||   SMBUS_I2C_DUTY_16_9   

#define SMBUS_I2C_DUTY    SMBUS_I2C_DUTY_2

// SMBUS_I2C_ACK_ENABLED || SMBUS_I2C_ACK_DISABLED

#define SMBUS_I2C_ACK     SMBUS_I2C_ACK_ENABLED

// SMBUS_I2C_ACK_ADDRESS_7_BIT || SMBUS_I2C_ACK_ADDRESS_10_BIT
#define  SMBUS_I2C_ACK_ADDRESS  SMBUS_I2C_ACK_ADDRESS_7_BIT   

//  SMBUS_I2C_ALERT_LOW   ||  SMBUS_I2C_ALERT_HIGH
#define  SMBUS_I2C_ALERT    SMBUS_I2C_ALERT_LOW  
#define  SMBUS_I2C_CLK      8000000UL       
#define  SMBUS_I2C_SPEED    100000            //100 KHZ
#define  SMBUS_I2C_OWN_ADD_1  0x5A
#define  SMBUS_I2C_DELAY      10000    //10 KHZ 

#endif
