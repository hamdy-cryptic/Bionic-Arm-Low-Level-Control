/************************************/
/* Author : Yomna Attia             */
/* Date : 12/12/2020                */
/* version : 01                     */
/************************************/
#ifndef RCC_interface_h
#define RCC_interface_h
#include "STD_TYPES.h"
//Buses used in BusID
#define RCC_AHB1     0
#define RCC_APB1     3
#define RCC_APB2     4
//Peripherals used in PerID for AHB1
#define RCC_DMA1    0
#define RCC_DMA2    1
#define RCC_CRC     6
//Peripherals used in PerID for APB2
#define RCC_AFIO     0
#define RCC_GPIOA    2
#define RCC_GPIOB    3
#define RCC_GPIOC    4
#define RCC_GPIOD    5
#define RCC_GPIOE    6
#define RCC_ADC1     9
#define RCC_ADC2     10
#define RCC_TIM1     11
#define RCC_TIM8     13
#define RCC_USART1   14
//Peripherals used in PerID for APB1
#define RCC_TIM2     0
#define RCC_TIM3     1
#define RCC_TIM4     2
#define RCC_TIM5     3
#define RCC_TIM6     4
#define RCC_TIM7     5
#define RCC_USART2   17
#define RCC_USART3   18
#define RCC_USART4   19
#define RCC_USART5   20
#define RCC_I2C1     21
#define RCC_I2C2     22
#define RCC_DAC      29
/*functions prototypes*/

/*this function intialises system clock 
you should choose the RCC_CLOCK_TYPE in the configuration file
the function will intialise it   */
void RCC_voidInitSysClock (void);


/*this function enables the clock it takes the bus ID , the perepheral ID  */
void RCC_voidEnableClock (u8 Copy_u8BusId, u8 Copy_u8PerId);

/*this function disables the clock it takes the bus ID , the perepheral ID  */
void RCC_voidDisableClock (u8 Copy_u8BusId, u8 Copy_u8PerId);


#endif
