#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Temp_program.c"
#include "stdio.h"



int main (void)
{
	RCC_voidEnableClock(RCC_AHB1,RCC_GPIOB);
RCC_voidEnableClock(RCC_APB1,RCC_I2C1);
	
    TEMP_SENSOR_Init();
	 f32 volatile T_A=0 ; 
f32 volatile T_OB1=0 ; 
f32 volatile T_OB2=0;
	
	while(1){
	   T_A=TEMP_READ( TEMP_SOURCE_AMBIENT, TEMP_Centigrade); 
      T_OB1= TEMP_READ( TEMP_OBJ_IR_SOURCE_1, TEMP_Centigrade); 
     T_OB2=  TEMP_READ( TEMP_OBJ_IR_SOURCE_2, TEMP_Centigrade);		
		
		
	}
}
