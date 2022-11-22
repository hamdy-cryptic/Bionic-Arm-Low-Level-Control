/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 12 February 2020                                 */
/* Version : V01                                             */
/*************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "MI2C_interface.h"
#include "MDMA_interface.h"

#include "MI2C_private.h"

#include "TEMP_interface.h"
#include "TEMP_private.h"
#include "TEMP_config.h"
//#include "CRC_program.c"



 u32 Data[3];


void CRITICAL_GPIO_Config(void)
{
	RCC_voidEnableClock(RCC_AHB1, RCC_GPIOB);
	GPIO_voidSetPinDirection(GPIOB , 3 , GPIO_AF );     // I2C2_SDA pin11 
	SET_GPIO_SPEED( GPIOB ,3 , GPIO_SPEED_LOW  );         //Speed 2MHZ
	GPIO_Set_AF(GPIOB , 3 , 4 );                           // Alternative function
	GPIO_SET_PP_OD ( GPIOB , 3, GPIO_OUTPUT_OD);           // Open drain
	GPIO_SET_PU_PD ( GPIOB , 3, GPIO_PU);                  // pull up
	
	GPIO_voidSetPinDirection(GPIOB , 10 , GPIO_AF );   // I2C2_SCL pin10
	SET_GPIO_SPEED( GPIOB , 10 , GPIO_SPEED_LOW  );        // Speed 2MHZ
	GPIO_Set_AF(GPIOB , 10 , 4 );                          //Alternative function
	GPIO_SET_PP_OD ( GPIOB , 10, GPIO_OUTPUT_OD);           // Open drain
	GPIO_SET_PU_PD ( GPIOB , 10, GPIO_PU);                  // pull up
   	
}

void TEMP_SENSOR_Init(void){
	
	
	   CRITICAL_GPIO_Config();
	  MI2C_voidSMbus_Request();
    MI2C_voidSMbus_Mode(I2C2);
    MI2C_voidEnableDmaRequest(I2C2);
    MI2C_voidDmaLastTransfer(I2C2); 
    DMA_SetConfig( 1 , STREAM_3 , PERIPHERAL_TO_MEMORY , BYTE , BYTE , ACTIVATED , DEACTIVATED);
    DMA_VoidSelectChannel(1, STREAM_3 , CHANNEL7 );
    DMA_VoidInerruptEnable(1, STREAM_3 , TCIE );
	
//configure DMA_transmitter
   DMA_SetConfig(1 ,STREAM_7, MEMORY_TO_PERIPHERAL , BYTE , BYTE , ACTIVATED , DEACTIVATED);
   DMA_VoidSelectChannel( 1,STREAM_7 , CHANNEL7 );
   DMA_VoidSetAddress(1, STREAM_7 , &(I2C_2->DR) ,Data , 1 );
}
   
u16 READ_RAM_EEPROM(u8 Command)       
{

	u16 Temp;

	 MI2C_voidMasterTransmitter_7bit( I2C2 , Sensor_Address );  // Master sends start bit, slave address from master to slave with write bit
	// MI2C_voidSlaveRecieverFinishing(I2C2);       // from slave to master
	 MI2C_voidSendRegisterAddress( I2C2, ONE_BYTE , Command);   // send command from master to slave
	 MI2C_voidMasterRead_7bit(I2C2 , Sensor_Address );     // Repeat start , Slave address from master to slave with read bit
	 
	 DMA_VoidDMAEnable(1, STREAM_3 );
	 MI2C_voidGetReady(I2C2 );
	
	MDMA_VidSetCallBack_I2C2_RX(MI2C_voidI2c2_MasterRecieverFinishing);

//     CRC_SW_8(Sensor_Address<<1 , 8 , TEMP_POLYNOMIAL);
//     CRC_SW_8(Command , 8 , TEMP_POLYNOMIAL);
//     CRC_SW_8(((Sensor_Address<<1)|1) , 8 , TEMP_POLYNOMIAL);
//	   CRC_SW_8( Data[0] , 8 , TEMP_POLYNOMIAL);
//	   CRC_SW_8( Data[1], 8 , TEMP_POLYNOMIAL);
//	 if((CRC_SW_8( Data[2], 8 , TEMP_POLYNOMIAL))!= Data[2])
//	 {
//		 return 0;
//	 }
		  Temp= ((Data[1]<<8)|Data[0]);
		  
		  if(Temp>=0x8000 || Temp==0)
		  {
			  return 0;
		  }
		  else 
		  {
			 return Temp; 
		  }
		  
}

f64  TEMP_READ( u64 TEMP_SOURCE, u64 TEMP_UNIT)
{
     u64 T=0;
     switch(TEMP_SOURCE)
{
   case TEMP_SOURCE_AMBIENT:  T= READ_RAM_EEPROM(TEMP_TA);
   break;
   case TEMP_OBJ_IR_SOURCE_1: T= READ_RAM_EEPROM(TEMP_TO_1);
   break;
   case TEMP_OBJ_IR_SOURCE_2 :T= READ_RAM_EEPROM(TEMP_TO_2);
   break;
   default: T= READ_RAM_EEPROM(TEMP_TA);
   break;
}
  T*=0.02;
  switch(TEMP_UNIT)
{
   case TEMP_Kelvin: 
          
            return T;
            break;
   
   case TEMP_Centigrade :
          return TEMP_CONVERSION_K_TO_C(T);           
       break;

  case TEMP_Fahrenheit:
     TEMP_CONVERSION_K_TO_F(T);
      break;

}
   return T;
}

f64 TEMP_CONVERSION_K_TO_C(f64 Degree_K){
  return (Degree_K -237.15);
}

f64   TEMP_CONVERSION_C_TO_F(f64 Degree_C){
   return ((Degree_C*1.8)+32.0);
}
f64   TEMP_CONVERSION_K_TO_F(f64 Degree_K){
          f64 Degree_C= Degree_K -237.15;
          return TEMP_CONVERSION_C_TO_F(Degree_C);          
}


