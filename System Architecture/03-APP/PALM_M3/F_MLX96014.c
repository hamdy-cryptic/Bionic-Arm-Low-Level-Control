#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "F_SMBUS.h"
#include "F_MLX90614.h"
#include "RCC_interface.h"
#include "DMA_interface.h"


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


	void GPIO_SCL_SDA_INIT(u8 z, u8 x,u8 y)
{
		switch (z){
		case GPIOA: RCC_voidEnableClock(RCC_APB2, RCC_GPIOA); break;
		case GPIOB: RCC_voidEnableClock(RCC_APB2, RCC_GPIOB); break;
		case GPIOC: RCC_voidEnableClock(RCC_APB2, RCC_GPIOC); break;
		default : break;
	}
	GPIO_voidSetPinDirection(z , x , GPIO_OUTPUT);
	GPIO_voidSetPinDirection(z , y , GPIO_OUTPUT);
	GPIO_SET_PP_OD (z , x,GPIO_OUTPUT_OD);
	GPIO_SET_PP_OD (z , y,GPIO_OUTPUT_OD);
	SET_GPIO_SPEED( z , x ,GPIO_SPEED_LOW );
	SET_GPIO_SPEED( z , y ,GPIO_SPEED_LOW );
}

void DMA_SCL_SDA_INIT(void)
{
DMA_SetConfig(1,CHANNEL7,MEMORY_TO_PERIPHERAL,BYTE,BYTE, ACTIVATED,DEACTIVATED);
 DMA_VoidConfigPriority(1 ,CHANNEL7, LOW);
 DMA_VoidInerruptEnable(1,CHANNEL7, TCIE );
DMA_VoidDMAEnable(1,CHANNEL7);
}



void MLX90614_Init (u8 z, u8 x,u8 y){
	
	GPIO_SCL_SDA_INIT(z, x, y);
	DMA_SCL_SDA_INIT();

	
}
