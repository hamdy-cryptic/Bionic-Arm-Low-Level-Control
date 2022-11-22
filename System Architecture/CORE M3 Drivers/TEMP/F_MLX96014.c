#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "F_SMBUS.h"
#include "F_MLX90614.h"


u8 R_Data[3];
f32 MLX90614_READ(u8 ambient_or_object)
{
	u32 temp_data;
	f32 T;
	SMBUS_START();
	SMBUS_SEND_SLAVE_ADDRESS(MLX90614_ADDR_WRITE);
	SMBUS_S_TO_M_ACK();
	SMBUS_SEND_SLAVE_ADDRESS(ambient_or_object);
	SMBUS_S_TO_M_ACK();
	SMBUS_START();
	SMBUS_SEND_SLAVE_ADDRESS(MLX90614_ADDR_READ);
	SMBUS_S_TO_M_ACK();
	R_Data[0]=SMBUS_READ_BYTE();
	SMBUS_M_TO_S_ACK();
	R_Data[1]= SMBUS_READ_BYTE();
	SMBUS_M_TO_S_ACK();
	R_Data[2]= SMBUS_READ_BYTE();
	SMBUS_M_TO_S_ACK();
	SMBUS_STOP();
	
	temp_data= R_Data[1]*256+ R_Data[0];
	if(temp_data >= 0x8000)
	{
		return 0 ;
	}
	if(temp_data==0)
	{
		return 0;
	}
	T= temp_data*0.02 ;
	if(T >= 273.15)
	{
		return (T-273.15);
	}
	else 
	{
		return -(273.15 - T);
	}
}