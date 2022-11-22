/************************************************************
   Author  :  Omaima                                         
   Date    : 6/6/2021                                         
   Version : V01                                             
*************************************************************/


#include "SMBUS_interface.h"
#include "MLX90614.h"


u32 R_DATA[3];
f32 MLX90614_READ(u16 ambient_or_object)
{
	 u8 PEC=0;
	 u8 pec=0;
u32 data;	
SMBUS_START();
SMBUS_SEND_SLAVE_ADDRESS(MLX90614_ADD,WR_BIT);  //slave_address--> master transmitter
SMBUS_SEND_DATA(&ambient_or_object);   // command
SMBUS_START();
SMBUS_SEND_SLAVE_ADDRESS(MLX90614_ADD,RD_BIT);
R_DATA[0]=SMBUS_READ_DATA(&ambient_or_object);
SMBUS_CHECK_READ_DATA();
R_DATA[1]=SMBUS_READ_DATA(&ambient_or_object);
SMBUS_CHECK_READ_DATA();
PEC=R_DATA[2]=SMBUS_READ_DATA(&ambient_or_object);
//pec=SMBUS_CRC8(((ambient_or_object << 16) | R_DATA[0] << 8) | R_DATA[1]);
//if(PEC !=pec) {return 0 ;}	
SMBUS_STOP();


  data= ((R_DATA[1]<<8)|R_DATA[0]);

		  
		  if(data >=0x8000 || data==0)
		  {
			  return 0;
		  }
		  else 
		  {
			 return data; 
		  }
		  
}

f32  MLX90614_READ_TEMPERATURE( u8 SOURCE, u8 UNIT)
{    u32 T_RECEIVED;	
     u32 TEMP =0;
     switch(SOURCE)
{
   case MLX90614_SOURCE_AMBIENT:  TEMP= MLX90614_READ(MLX90614_TA);
   break;
   case MLX90614_OBJ_IR_SOURCE_1: TEMP= MLX90614_READ(MLX90614_TO_1);
   break;
   case MLX90614_OBJ_IR_SOURCE_2 :TEMP= MLX90614_READ(MLX90614_TO_2);
   break;
   default: TEMP=MLX90614_READ(MLX90614_TA);
   break;
}
  TEMP*=0.02;
  switch(UNIT)
{
   case MLX90614_Kelvin: 
           return   TEMP;
            break;
   
   case MLX90614_Centigrade :
          TEMP=MLX90614_CONVERSION_K_TO_C(TEMP); 
                    
       break;

  case MLX90614_Fahrenheit:
       TEMP= MLX90614_CONVERSION_K_TO_F(TEMP);
	   
      break;

}
   return TEMP;
}

f32 MLX90614_CONVERSION_K_TO_C(f32 Degree_K){
  return (Degree_K -237.15);
}

f32 MLX90614_CONVERSION_C_TO_F(f32 Degree_C){
   return ((Degree_C*1.8)+32.0);
}
f32 MLX90614_CONVERSION_K_TO_F(f32 Degree_K){
          f64 Degree_C= Degree_K -237.15;
          return MLX90614_CONVERSION_C_TO_F(Degree_C);          
}


