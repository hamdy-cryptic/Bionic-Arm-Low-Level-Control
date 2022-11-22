/************************************/
/* Author : Yomna Attia             */
/* Date : 12/12/2020                */
/* version : 01                     */
/************************************/
#ifndef RCC_private_h
#define RCC_private_h

/*Register Definitions */
#define RCC_CR             *( (volatile u32*)0x40021000)
#define RCC_CFGR           *( (volatile u32*)0x40021004)
#define RCC_CIR            *( (volatile u32*)0x40021008)
#define RCC_APB2RSTR       *( (volatile u32*)0x4002100C)
#define RCC_APB1RSTR       *( (volatile u32*)0x40021010)
#define RCC_AHB1ENR        *( (volatile u32*)0x40021014)
#define RCC_APB2ENR        *( (volatile u32*)0x40021018)
#define RCC_APB1ENR        *( (volatile u32*)0x4002101C)
#define RCC_BDCR           *( (volatile u32*)0x40021020)
#define RCC_CSR            *( (volatile u32*)0x40021024)
#define RCC_AHB1RSTR       *( (volatile u32*)0x40021028)
#define RCC_CFGR2       *( (volatile u32*)0x4002102C)

#define FLASH_ACR          *( (volatile u32*)0x40022000)

/* CLOCK TYPES*/ 
#define RCC_HSE_CRYSTAL     0
#define RCC_HSE_RC          1
#define RCC_HSI             2
#define RCC_PLL             3


/* PLL options*/
#define RCC_PLL_HSI            0
#define RCC_PLL_HSE_Crystal    1
#define RCC_PLL_HSE_RC         2
			        
#endif