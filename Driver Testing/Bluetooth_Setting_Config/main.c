#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "USART_interface.h"
#include "DMA_interface.h"
#include "USART_private.h"
#include "STK_interface.h"
#include "Servo_interface.h"


u8 RX_1[30]={0};
u8 RX_2[30]={0};
u8 RX_3[10]={0};

u8  TX1[10]="AT+ADDR?\r\n";
u8  TX2[50]={0};
u8  TX3[10]={0};


int main()
 {
	
RCC_voidInitSysClock();
RCC_voidEnableClock (RCC_APB2, RCC_GPIOA ); 
MSTK_void_SysTick_Initialize();
USART_Init(); 
//USART2_DMA_Transmit_Init();
//USART2_DMA_Transmit(TX2,20);

USART1_DMA_Receiver_Init();
USART1_DMA_RECEIVE(RX_1,25); 

Servo_VoidInit(SERVO_PA6);
	 while(1)
{
//USART1_SENDSTRING(TX1);	
//MSTK_void_SysTick_Delay (500); 
Servo_VoidWrite(SERVO_PA6,0);
MSTK_void_SysTick_Delay (200);
Servo_VoidWrite(SERVO_PA6,180);
MSTK_void_SysTick_Delay (200);	
}
}