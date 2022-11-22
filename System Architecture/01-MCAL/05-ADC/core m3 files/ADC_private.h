/***************************************************************
   File:        Private Functions and Registers of ADC Driver  *
   Author:      Hamdy Osama Mohamed                            *
   Version:     V01                                            *
   Date:        6/12/2020                                      *
   Updates:     ----                                           *
***************************************************************/
   
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

//Base Register for Driver
#define ADC_BASE_ADDRESS          0x40012400
#define ADC2_OFFSET               0x400
#define ADC3_OFFSET               0x1800

//Register Offsets   (ADC1)
#define ADC1_SR        *((volatile u32*)(ADC_BASE_ADDRESS+0x00))
#define ADC1_CR1       *((volatile u32*)(ADC_BASE_ADDRESS+0x04))
#define ADC1_CR2       *((volatile u32*)(ADC_BASE_ADDRESS+0x08))
#define ADC1_SMPR1     *((volatile u32*)(ADC_BASE_ADDRESS+0x0C))
#define ADC1_SMPR2     *((volatile u32*)(ADC_BASE_ADDRESS+0x10))
#define ADC1_JOFR1     *((volatile u32*)(ADC_BASE_ADDRESS+0x14))
#define ADC1_JOFR2     *((volatile u32*)(ADC_BASE_ADDRESS+0x18))
#define ADC1_JOFR3     *((volatile u32*)(ADC_BASE_ADDRESS+0x1C))
#define ADC1_JOFR4     *((volatile u32*)(ADC_BASE_ADDRESS+0x20))
#define ADC1_HTR       *((volatile u32*)(ADC_BASE_ADDRESS+0x24))
#define ADC1_LTR       *((volatile u32*)(ADC_BASE_ADDRESS+0x28))
#define ADC1_SQR1      *((volatile u32*)(ADC_BASE_ADDRESS+0x2C))
#define ADC1_SQR2      *((volatile u32*)(ADC_BASE_ADDRESS+0x30))
#define ADC1_SQR3      *((volatile u32*)(ADC_BASE_ADDRESS+0x34))
#define ADC1_JSQR      *((volatile u32*)(ADC_BASE_ADDRESS+0x38))
#define ADC1_JDR1      *((volatile u32*)(ADC_BASE_ADDRESS+0x3C))
#define ADC1_JDR2      *((volatile u32*)(ADC_BASE_ADDRESS+0x40))
#define ADC1_JDR3      *((volatile u32*)(ADC_BASE_ADDRESS+0x44))
#define ADC1_JDR4      *((volatile u32*)(ADC_BASE_ADDRESS+0x48))
#define ADC1_DR        *((volatile u32*)(ADC_BASE_ADDRESS+0x4C))


//Register Offsets   (ADC2)
#define ADC2_SR        *((volatile u32*)(ADC_BASE_ADDRESS+0x00+ADC2_OFFSET))
#define ADC2_CR1       *((volatile u32*)(ADC_BASE_ADDRESS+0x04+ADC2_OFFSET))
#define ADC2_CR2       *((volatile u32*)(ADC_BASE_ADDRESS+0x08+ADC2_OFFSET))
#define ADC2_SMPR1     *((volatile u32*)(ADC_BASE_ADDRESS+0x0C+ADC2_OFFSET))
#define ADC2_SMPR2     *((volatile u32*)(ADC_BASE_ADDRESS+0x10+ADC2_OFFSET))
#define ADC2_JOFR1     *((volatile u32*)(ADC_BASE_ADDRESS+0x14+ADC2_OFFSET))
#define ADC2_JOFR2     *((volatile u32*)(ADC_BASE_ADDRESS+0x18+ADC2_OFFSET))
#define ADC2_JOFR3     *((volatile u32*)(ADC_BASE_ADDRESS+0x1C+ADC2_OFFSET))
#define ADC2_JOFR4     *((volatile u32*)(ADC_BASE_ADDRESS+0x20+ADC2_OFFSET))
#define ADC2_HTR       *((volatile u32*)(ADC_BASE_ADDRESS+0x24+ADC2_OFFSET))
#define ADC2_LTR       *((volatile u32*)(ADC_BASE_ADDRESS+0x28+ADC2_OFFSET))
#define ADC2_SQR1      *((volatile u32*)(ADC_BASE_ADDRESS+0x2C+ADC2_OFFSET))
#define ADC2_SQR2      *((volatile u32*)(ADC_BASE_ADDRESS+0x30+ADC2_OFFSET))
#define ADC2_SQR3      *((volatile u32*)(ADC_BASE_ADDRESS+0x34+ADC2_OFFSET))
#define ADC2_JSQR      *((volatile u32*)(ADC_BASE_ADDRESS+0x38+ADC2_OFFSET))
#define ADC2_JDR1      *((volatile u32*)(ADC_BASE_ADDRESS+0x3C+ADC2_OFFSET))
#define ADC2_JDR2      *((volatile u32*)(ADC_BASE_ADDRESS+0x40+ADC2_OFFSET))
#define ADC2_JDR3      *((volatile u32*)(ADC_BASE_ADDRESS+0x44+ADC2_OFFSET))
#define ADC2_JDR4      *((volatile u32*)(ADC_BASE_ADDRESS+0x48+ADC2_OFFSET))
#define ADC2_DR        *((volatile u32*)(ADC_BASE_ADDRESS+0x4C+ADC2_OFFSET))


//Register Offsets   (ADC3)
#define ADC3_SR        *((volatile u32*)(ADC_BASE_ADDRESS+0x00+ADC3_OFFSET))
#define ADC3_CR1       *((volatile u32*)(ADC_BASE_ADDRESS+0x04+ADC3_OFFSET))
#define ADC3_CR2       *((volatile u32*)(ADC_BASE_ADDRESS+0x08+ADC3_OFFSET))
#define ADC3_SMPR1     *((volatile u32*)(ADC_BASE_ADDRESS+0x0C+ADC3_OFFSET))
#define ADC3_SMPR2     *((volatile u32*)(ADC_BASE_ADDRESS+0x10+ADC3_OFFSET))
#define ADC3_JOFR1     *((volatile u32*)(ADC_BASE_ADDRESS+0x14+ADC3_OFFSET))
#define ADC3_JOFR2     *((volatile u32*)(ADC_BASE_ADDRESS+0x18+ADC3_OFFSET))
#define ADC3_JOFR3     *((volatile u32*)(ADC_BASE_ADDRESS+0x1C+ADC3_OFFSET))
#define ADC3_JOFR4     *((volatile u32*)(ADC_BASE_ADDRESS+0x20+ADC3_OFFSET))
#define ADC3_HTR       *((volatile u32*)(ADC_BASE_ADDRESS+0x24+ADC3_OFFSET))
#define ADC3_LTR       *((volatile u32*)(ADC_BASE_ADDRESS+0x28+ADC3_OFFSET))
#define ADC3_SQR1      *((volatile u32*)(ADC_BASE_ADDRESS+0x2C+ADC3_OFFSET))
#define ADC3_SQR2      *((volatile u32*)(ADC_BASE_ADDRESS+0x30+ADC3_OFFSET))
#define ADC3_SQR3      *((volatile u32*)(ADC_BASE_ADDRESS+0x34+ADC3_OFFSET))
#define ADC3_JSQR      *((volatile u32*)(ADC_BASE_ADDRESS+0x38+ADC3_OFFSET))
#define ADC3_JDR1      *((volatile u32*)(ADC_BASE_ADDRESS+0x3C+ADC3_OFFSET))
#define ADC3_JDR2      *((volatile u32*)(ADC_BASE_ADDRESS+0x40+ADC3_OFFSET))
#define ADC3_JDR3      *((volatile u32*)(ADC_BASE_ADDRESS+0x44+ADC3_OFFSET))
#define ADC3_JDR4      *((volatile u32*)(ADC_BASE_ADDRESS+0x48+ADC3_OFFSET))
#define ADC3_DR        *((volatile u32*)(ADC_BASE_ADDRESS+0x4C+ADC3_OFFSET))

//ADC Prescaler Register
#define ADC_RCC_PRE    *((volatile u32*)(0x40021000+0x04))

//Macros used in Config

#define RIGHT                     0
#define LEFT                      1
#endif
