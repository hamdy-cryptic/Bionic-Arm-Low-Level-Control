/*********************************************************/
/*Author     : youstina                                  */
/*version    : v02                                       */
/*date       : 3 JAN 2021                                */
/*********************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H
#include "STD_TYPES.h"

/* OPTIONS FOR Copy_u8IntNumber */
#define   WWDG                        0    //Window Watchdog interrupt
#define   PVD                         1    //PVD through EXTI line detection interrupt
#define   TAMP_STAMP                  2    //Tamper and TimeStamp interrupts through the EXTI line
#define   RTC_WKUP                    3    //RTC Wakeup interrupt through the EXTI line
#define   FLASH                       4    //Flash global interrupt
#define   RCC                         5    //RCC global interrupt

#define   EXTI0                       6    //EXTI Line0 interrupt
#define   EXTI1                       7    //EXTI Line1 interrupt
#define   EXTI2                       8    //EXTI Line2 interrupt
#define   EXTI3                       9    //EXTI Line3 interrupt
#define   EXTI4                      10    //EXTI Line4 interrupt

#define   DMA1_Stream0               11    //DMA1 Stream0 global interrupt
#define   DMA1_Stream1               12    //DMA1 Stream1 global interrupt
#define   DMA1_Stream2               13    //DMA1 Stream2 global interrupt
#define   DMA1_Stream3               14    //DMA1 Stream3 global interrupt
#define   DMA1_Stream4               15    //DMA1 Stream4 global interrupt
#define   DMA1_Stream5               16    //DMA1 Stream5 global interrupt
#define   DMA1_Stream6               17    //DMA1 Stream6 global interrupt

#define   ADC                        18    //ADC1, ADC2 and ADC3 global interrupts

#define   CAN1_TX                    19    //CAN1 TX interrupts
#define   CAN1_RX0                   20    //CAN1 RX0 interrupts
#define   CAN1_RX1                   21    //CAN1 RX1 interrupt
#define   CAN1_SCE                   22    //CAN1 SCE interrupt

#define   EXTI9_5                    23    //EXTI Line[9:5] interrupts

#define   TIM1_BRK_TIM9              24    //TIM1 Break interrupt and TIM9 global interrupt
#define   TIM1_UP_TIM10              25    //TIM1 Update interrupt and TIM10 global interrupt
#define   TIM1_TRG_COM_TIM11         26    //TIM1 Trigger and Commutation interrupts and TIM11 global interrupt
#define   TIM1_CC                    27    //TIM1 Capture Compare interrupt
#define   NVIC_TIM2                  28    //TIM2 global interrupt
#define   TIM3                       29    //TIM3 global interrupt
#define   NVIC_TIM4                  30    //TIM4 global interrupt

#define   I2C1_EV                    31    //I2C1 event interrupt
#define   I2C1_ER                    32    //I2C1 error interrupt
#define   I2C2_EV                    33    //I2C2 event interrupt
#define   I2C2_ER                    34    //I2C2 error interrupt

#define   SPI1                       35    //SPI1 global interrupt
#define   SPI2                       36    //SPI2 global interrupt

#define   USART1                     37    //USART1 global interrupt
#define   USART2                     38    //USART2 global interrupt
#define   USART3                     39    //USART3 global interrupt

#define   EXTI15_10                  40    //EXTI Line[15:10] interrupts

#define   RTC_Alarm                  41    //RTC Alarms (A and B) through EXTI line interrupt
#define   OTG_FS_WKUP                42    //USB On-The-Go FS Wakeup through EXTI line interrupt

#define   TIM8_BRK_TIM12             43    //TIM8 Break interrupt and TIM12 global interrupt
#define   TIM8_UP_TIM13              44    //TIM8 Update interrupt and TIM13 global interrupt 
#define   TIM8_TRG_COM_TIM14         45    //TIM8 Trigger and Commutation interrupts and TIM14 global interrupt
#define   TIM8_CC                    46    //TIM8 Capture Compare interrupt

#define   DMA1_Stream7               47    //DMA1 Stream7 global interrupt

#define   FMC                        48    //FMC global interrupt
#define   SDIO                       49    //SDIO global interrupt

#define   TIM5                       50    //TIM5 global interrupt

#define   SPI3                       51    //SPI3 global interrupt

#define   UART4                      52    //UART4 global interrupt
#define   UART5                      53    //UART5 global interrupt

#define   TIM6_DAC                   54    //TIM6 global interrupt, DAC1 and DAC2 underrun error interrupts
#define   TIM7                       55    //TIM7 global interrupt

#define   DMA2_Stream0               56    //DMA2 Stream0 global interrupt
#define   DMA2_Stream1               57    //DMA2 Stream1 global interrupt
#define   DMA2_Stream2               58    //DMA2 Stream2 global interrupt
#define   DMA2_Stream3               59    //DMA2 Stream3 global interrupt
#define   DMA2_Stream4               60    //DMA2 Stream4 global interrupt

#define   CAN2_TX                    63    //CAN2 TX interrupts
#define   CAN2_RX0                   64    //CAN2 RX0 interrupts
#define   CAN2_RX1                   65    //CAN2 RX1 interrupt
#define   CAN2_SCE                   66    //CAN2 SCE interrupt

#define   OTG_FS                     67    //USB On The Go FS global interrupt

#define   DMA2_Stream5               68    //DMA2 Stream5 global interrupt
#define   DMA2_Stream6               69    //DMA2 Stream6 global interrupt 
#define   DMA2_Stream7               70    //DMA2 Stream7 global interrupt

#define   USART6                     71    //USART6 global interrupt

#define   I2C3_EV                    72    //I2C3 event interrupt
#define   I2C3_ER                    73    //I2C3 error interrupt

#define   OTG_HS_EP1_OUT             74    //USB On The Go HS End Point 1 Out global interrupt
#define   OTG_HS_EP1_IN              75    //USB On The Go HS End Point 1 In global interrupt
#define   OTG_HS_WKUP                76    //USB On The Go HS Wakeup through EXTI interrupt
#define   OTG_HS                     77    //USB On The Go HS global interrupt
#define   DCMI                       78    //DCMI global interrupt

#define   FPU                        81    //FPU global interrupt

#define   SPI4                       84    //SPI 4 global interrupt

#define   SAI1                       87    //SAI1 global interrupt

#define   SAI2                       91    //SAI2 global interrupt
#define   QuadSPI                    92    //QuadSPI global interrupt
#define   HDMI-CEC                   93    //HDMI-CEC global interrupt
#define   SPDIF-Rx                   94    //SPDIF-Rx global interrupt 
#define   FMPI2C1                    95    //FMPI2C1 event interrupt
#define   FMPI2C1_error              96    //FMPI2C1 error interrupt



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