#include "RCC_interface.h"
#include "STK_interface.h"

#include "USART_interface.h"

volatile u8 Recieved_Data[10]={0};
volatile u8 Sent_Data[10] = {0,1,2,3,4,5,6,7,8,9};
int main(){
	USART_Init();
	
	USART2_DMA_Receiver_Init();
	USART2_DMA_RECEIVE(Recieved_Data, 10);

	USART3_DMA_Transmit_Init();
	USART3_DMA_Transmit(Sent_Data, 10);
	
	while(1){
		for (int i =0 ; i<10 ; i++){
			Sent_Data[i]+=1;
		}
		MSTK_void_SysTick_Delay(500); 
	}
}