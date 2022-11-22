/*********************************************************/
/*Author     : youstina                                  */
/*version    : v01                                       */
/*date       : 10 DEC 2020                                */
/*********************************************************/



#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H
#include "STD_TYPES.h"

/* OPTIONS FOR Copy_u8IntNumber */
#define    WWDG                     0
#define    PVD                      1
#define    TAMPER                   2
#define    RTC                      3
#define    FLASH                    4
#define    RCC                      5
#define    EXTI0                    6
#define    EXTI1                    7
#define    EXTI2                    8
#define    EXTI3                    9
#define    EXTI4                    10
#define    DMA1_Channel1            11
#define    DMA1_Channel2            12
#define    DMA1_Channel3            13
#define    DMA1_Channel4            14
#define    DMA1_Channel5            15
#define    DMA1_Channel6            16
#define    DMA1_Channel7            17
#define    ADC1_2                   18
#define    CAN1_TX                  19
#define    CAN1_RX0                 20
#define    CAN1_RX1                 21
#define    CAN1_SCE                 22
#define    EXTI9_5                  23
#define    TIM1_BRK                 24
#define    TIM1_UP_TIM10            25
#define    TIM1_TRG_COM             26
#define    TIM1_CC                  27
#define    NVIC_TIM2                28
#define    TIM3                     29
#define    TIM4                     30
#define    TIM8_UP_TIM13            44
#define    I2C1_EV                  31
#define    I2C1_ER                  32
#define    I2C2_EV                  33
#define    I2C2_ER                  34
#define    SPI1                     35 
#define    SPI2                     36
#define    NVIC_USART1              37
#define    NVIC_USART2              38
#define    NVIC_USART3              39
#define    EXTI15_10                40
#define    RTCAlarm                 41
#define    OTG_FS_WKUP              42
#define    TIM5                     50
#define    SPI3                     51
#define    UART4                    52
#define    UART5                    53
#define    TIM6                     54
#define    TIM7                     55
#define    DMA2_Channel1            56
#define    DMA2_Channel2            57
#define    DMA2_Channel3            58
#define    DMA2_Channel4            59
#define    DMA2_Channel5            60
#define    ETH                      61
#define    ETH_WKUP                 62
#define    CAN2_TX                  63
#define    CAN2_RX0                 64
#define    CAN2_RX1                 65
#define    CAN2_SCE                 66
#define    OTG_FS                   67

void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber);   //Enable Interrupt of Peripheral
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);	 //Disable Interrupt of Peripheral

void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber);	 //used to excecute interrupt
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);	 //used to clear pending flag

u8   MNVIC_u8GetActiveFlag        (u8 Copy_u8IntNumber); //Read the flag status



/* OPTIONS FOR copy_u32Group */
#define NVIC_GROUP_4_SUB_0    0x05FA0300     /*4 bits for group priority (IPR)*/
#define NVIC_GROUP_3_SUB_1    0x05FA0400     /*3 bits for group priority & 1 bit for sub priority (IPR)*/
#define NVIC_GROUP_2_SUB_2    0x05FA0500     /*2 bits for group priority & 2 bits for sub priority (IPR)*/
#define NVIC_GROUP_1_SUB_3    0x05FA0600     /*1 bits for group priority & 3 bits for sub priority (IPR)*/
#define NVIC_GROUP_0_SUB_4    0x05FA0700     /*4 bits for sub priority (IPR)*/ 


void MNVIC_voidSetPriority (s8 copy_s8IntID , u8 copy_u8GroupPriority , u8 copy_u8SubPriority , u32 copy_u32Group); //used to set interrupt priority

/*Group Priority and Subpriority
max value 15, min value 0
Highest Priority = 0
based on GROUP Choice for bit configuration

Group Priority allows for nested interrupt enabling based on priority
Sub priority allows for non nested prioritizing interrupts

If the function is not used, hardware priority prevails
		
*/

#endif