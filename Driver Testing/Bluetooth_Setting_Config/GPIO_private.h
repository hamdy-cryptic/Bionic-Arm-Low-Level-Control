/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 11 December 2020                                 */
/* Version : V02.5                                            */
/*************************************************************/
#ifndef  GPIO_PRIVATE_H
#define  GPIO_PRIVATE_H

#define  GPIOA_BASE_ADDRESS  0x40010800
#define  GPIOB_BASE_ADDRESS  0x40010C00
#define  GPIOC_BASE_ADDRESS  0x40011000
#define  GPIOD_BASE_ADDRESS  0x40011400
#define  GPIOE_BASE_ADDRESS  0x40011800
#define  GPIOF_BASE_ADDRESS  0x40011C00
#define  GPIOG_BASE_ADDRESS  0x40012000




  
                    /* REGISTERS ADDRESSES FOR PORTA  */

#define   GPIOA_CRL                                  *((u32 *)(GPIOA_BASE_ADDRESS + 0x00))
#define   GPIOA_CRH                                  *((u32 *)(GPIOA_BASE_ADDRESS + 0x04))
#define   GPIOA_IDR                                  *((u32 *)(GPIOA_BASE_ADDRESS + 0x08))
#define   GPIOA_ODR                                  *((u32 *)(GPIOA_BASE_ADDRESS + 0x0C))
#define   GPIOA_BSRR                                 *((u32 *)(GPIOA_BASE_ADDRESS + 0x10))
#define   GPIOA_BRR                                  *((u32 *)(GPIOA_BASE_ADDRESS + 0x14))
#define   GPIOA_LCKR                                 *((u32 *)(GPIOA_BASE_ADDRESS + 0x18))


                    /* REGISTERS ADDRESSES FOR PORTB  */

#define   GPIOB_CRL                                  *((u32 *)(GPIOB_BASE_ADDRESS + 0x00))
#define   GPIOB_CRH                                  *((u32 *)(GPIOB_BASE_ADDRESS + 0x04))
#define   GPIOB_IDR                                  *((u32 *)(GPIOB_BASE_ADDRESS + 0x08))
#define   GPIOB_ODR                                  *((u32 *)(GPIOB_BASE_ADDRESS + 0x0C))
#define   GPIOB_BSRR                                 *((u32 *)(GPIOB_BASE_ADDRESS + 0x10))
#define   GPIOB_BRR                                  *((u32 *)(GPIOB_BASE_ADDRESS + 0x14))
#define   GPIOB_LCKR                                 *((u32 *)(GPIOB_BASE_ADDRESS + 0x18))



                   /* REGISTERS ADDRESSES FOR PORTC  */

#define   GPIOC_CRL                                  *((u32 *)(GPIOC_BASE_ADDRESS + 0x00))
#define   GPIOC_CRH                                  *((u32 *)(GPIOC_BASE_ADDRESS + 0x04))
#define   GPIOC_IDR                                  *((u32 *)(GPIOC_BASE_ADDRESS + 0x08))
#define   GPIOC_ODR                                  *((u32 *)(GPIOC_BASE_ADDRESS + 0x0C))
#define   GPIOC_BSRR                                 *((u32 *)(GPIOC_BASE_ADDRESS + 0x10))
#define   GPIOC_BRR                                  *((u32 *)(GPIOC_BASE_ADDRESS + 0x14))
#define   GPIOC_LCKR                                 *((u32 *)(GPIOC_BASE_ADDRESS + 0x18))


                /* REGISTERS ADDRESSES FOR PORTD  */

#define   GPIOD_CRL                                  *((u32 *)(GPIOD_BASE_ADDRESS + 0x00))
#define   GPIOD_CRH                                  *((u32 *)(GPIOD_BASE_ADDRESS + 0x04))
#define   GPIOD_IDR                                  *((u32 *)(GPIOD_BASE_ADDRESS + 0x08))
#define   GPIOD_ODR                                  *((u32 *)(GPIOD_BASE_ADDRESS + 0x0C))
#define   GPIOD_BSRR                                 *((u32 *)(GPIOD_BASE_ADDRESS + 0x10))
#define   GPIOD_BRR                                  *((u32 *)(GPIOD_BASE_ADDRESS + 0x14))
#define   GPIOD_LCKR                                 *((u32 *)(GPIOD_BASE_ADDRESS + 0x18))



                   /* REGISTERS ADDRESSES FOR PORTE  */

#define   GPIOE_CRL                                  *((u32 *)(GPIOE_BASE_ADDRESS + 0x00))
#define   GPIOE_CRH                                  *((u32 *)(GPIOE_BASE_ADDRESS + 0x04))
#define   GPIOE_IDR                                  *((u32 *)(GPIOE_BASE_ADDRESS + 0x08))
#define   GPIOE_ODR                                  *((u32 *)(GPIOE_BASE_ADDRESS + 0x0C))
#define   GPIOE_BSRR                                 *((u32 *)(GPIOE_BASE_ADDRESS + 0x10))
#define   GPIOE_BRR                                  *((u32 *)(GPIOE_BASE_ADDRESS + 0x14))
#define   GPIOE_LCKR                                 *((u32 *)(GPIOE_BASE_ADDRESS + 0x18))



                 /* REGISTERS ADDRESSES FOR PORTF  */

#define   GPIOF_CRL                                  *((u32 *)(GPIOF_BASE_ADDRESS + 0x00))
#define   GPIOF_CRH                                  *((u32 *)(GPIOF_BASE_ADDRESS + 0x04))
#define   GPIOF_IDR                                  *((u32 *)(GPIOF_BASE_ADDRESS + 0x08))
#define   GPIOF_ODR                                  *((u32 *)(GPIOF_BASE_ADDRESS + 0x0C))
#define   GPIOF_BSRR                                 *((u32 *)(GPIOF_BASE_ADDRESS + 0x10))
#define   GPIOF_BRR                                  *((u32 *)(GPIOF_BASE_ADDRESS + 0x14))
#define   GPIOF_LCKR                                 *((u32 *)(GPIOF_BASE_ADDRESS + 0x18))


                /* REGISTERS ADDRESSES FOR PORTG  */

#define   GPIOG_CRL                                  *((u32 *)(GPIOG_BASE_ADDRESS + 0x00))
#define   GPIOG_CRH                                  *((u32 *)(GPIOG_BASE_ADDRESS + 0x04))
#define   GPIOG_IDR                                  *((u32 *)(GPIOG_BASE_ADDRESS + 0x08))
#define   GPIOG_ODR                                  *((u32 *)(GPIOG_BASE_ADDRESS + 0x0C))
#define   GPIOG_BSRR                                 *((u32 *)(GPIOG_BASE_ADDRESS + 0x10))
#define   GPIOG_BRR                                  *((u32 *)(GPIOG_BASE_ADDRESS + 0x14))
#define   GPIOG_LCKR                                 *((u32 *)(GPIOG_BASE_ADDRESS + 0x18))

                            


                                  


#endif     
