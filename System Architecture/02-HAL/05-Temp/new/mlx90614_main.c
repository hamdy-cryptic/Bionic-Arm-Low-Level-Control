#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SMBUS_interface.h"
#include "STK_interface.h"
#include "MLX90614.h"


int main()
{
RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
RCC_voidEnableClock(RCC_APB1,RCC_I2C1);

SMBUS_init();
f32 T_A=0 ; 
f32 T_OB1=0 ; 
f32 T_OB2=0;
while(1)
{
  T_A=MLX90614_READ_TEMPERATURE( MLX90614_TA ,MLX90614_Centigrade);
  T_OB1=MLX90614_READ_TEMPERATURE( MLX90614_TO_1 ,MLX90614_Centigrade);
  T_OB2=MLX90614_READ_TEMPERATURE( MLX90614_TO_2 ,MLX90614_Centigrade);
}
return 0;
}