#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Temp_program.c"
#include "stdio.h"



int main (void)
{
	
    TEMP_SENSOR_Init();
	 
	
	while(1)
	{
		printf("\n Ambient Temperature: %0.2f", TEMP_READ( TEMP_SOURCE_AMBIENT, TEMP_Centigrade)); 
        printf("\n Object Temperature: %0.2f",TEMP_READ( TEMP_OBJ_IR_SOURCE_1, TEMP_Centigrade)); 
        printf("\n Object Temperature: %0.2f",TEMP_READ( TEMP_OBJ_IR_SOURCE_2, TEMP_Centigrade));		
		
		
	}
	
}