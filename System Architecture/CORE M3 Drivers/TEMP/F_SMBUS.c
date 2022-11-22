#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "F_SMBUS.h"
#include "GPIO_interface.h"
#include "PWM_interface.h"



void SMBUS_START(void)
{
	SMBUS_SDA_H();
	SMBUS_SCL_H();
	MSTK_void_SysTick_Delay(5);
	SMBUS_SDA_L();
	MSTK_void_SysTick_Delay(5);
	SMBUS_SCL_L();
	MSTK_void_SysTick_Delay(5);
}
void SMBUS_SEND_SLAVE_ADDRESS(u8 byte_data)
{
	u8 i;
	u8 temp=0x80;
    
for(i=0;i<8;i++)
{
	SMBUS_SCL_L();
	MSTK_void_SysTick_Delay(6);
	if((byte_data&temp)==0)
	{
		SMBUS_SDA_L();
	}
	else 
	{
		SMBUS_SDA_H();
	}
   temp >>=1 ;
   MSTK_void_SysTick_Delay(6);
   SMBUS_SCL_H();
   MSTK_void_SysTick_Delay(6);
}	
}
u8 SMBUS_S_TO_M_ACK(void)
{
   SMBUS_SCL_L();
   MSTK_void_SysTick_Delay(6);
   SMBUS_SDA_H();
   MSTK_void_SysTick_Delay(6);
   if(MGPIO_u8GetPinValue(SMBUS_SDA_PORT , SMBUS_SDA_PIN ) == 0)
	{
		SMBUS_SCL_H();
		MSTK_void_SysTick_Delay(6);
		if(MGPIO_u8GetPinValue(SMBUS_SDA_PORT , SMBUS_SDA_PIN )== 0)
		{
			SMBUS_SCL_L();
		  MSTK_void_SysTick_Delay(6);
			if(MGPIO_u8GetPinValue(SMBUS_SDA_PORT , SMBUS_SDA_PIN )== 1)
			{
				return 0;    
			}
			return 1;
		}
		return 2;
	}
	return 3;  
}

u8 SMBUS_READ_BYTE(void)
{
	u8 i;
	u8 byte_data;
	u8 temp=0x80;
	
	MSTK_void_SysTick_Delay(6);
	for(i=0;i<8;i++)
	{
		SMBUS_SCL_L();
		MSTK_void_SysTick_Delay(6);
		if(MGPIO_u8GetPinValue(SMBUS_SDA_PORT , SMBUS_SDA_PIN )==0)
			byte_data &= ~temp;
		else
			byte_data |= temp;
		temp >>=1;
		SMBUS_SCL_H();
		MSTK_void_SysTick_Delay(6);
	}
	return byte_data;
}
	

void SMBUS_M_TO_S_ACK(void)
{
	SMBUS_SCL_L();
	SMBUS_SDA_L();
	MSTK_void_SysTick_Delay(6);
	SMBUS_SCL_H();
	MSTK_void_SysTick_Delay(6);
	SMBUS_SCL_L();
	MSTK_void_SysTick_Delay(6);
	SMBUS_SDA_H();
	MSTK_void_SysTick_Delay(6);
}
void SMBUS_STOP(void)
{
  MSTK_void_SysTick_Delay(5);
	SMBUS_SDA_L();
	MSTK_void_SysTick_Delay(5);
	SMBUS_SCL_H();
	MSTK_void_SysTick_Delay(5);
	SMBUS_SDA_H();
	MSTK_void_SysTick_Delay(5);
}