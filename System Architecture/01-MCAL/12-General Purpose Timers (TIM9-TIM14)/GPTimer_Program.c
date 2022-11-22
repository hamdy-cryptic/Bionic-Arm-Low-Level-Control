/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 11 JAN 2021                            */
/* Version   : 01                                     */
/******************************************************/

#include "DataTypes_and_BitMath.h"
#include "GPTimer_Interface.h"
#include "GPTimer_Configuration.h"
#include "GPTimer_Private.h"

#include "RCC_interface.h"

static uint32 new_value=0, old_value=0, capture=0; 

/************************* Input Capture Function ***************************/

uint32 MGPTimer_uint32_InpCap (uint32 TIM_NUM)
{
	uint32 frequency=0;
	
	/********************* GPTimer 9 ***********************/
	
	if (TIM_NUM==9)                                     
	{
		GP_TIM9->CCMR1 = 0;  												//Reset Register
		GP_TIM9->CR1 = 0;    												//Reset Register
		GP_TIM9->SR = 0;                            //Reset Register
		
		RCC_voidEnableClock (RCC_APB2,16);          //Enable clock to the timer
		GP_TIM9->ARR=GPTIM_ARR;                     //Setting the auto reload register
		GP_TIM9->PSC=PSC_VALUE;                     //Setting the prescaller value
		GP_TIM9->CR1|= (GPTIM_CLK_DIVISION<<8);     //Setting the Clock division Config
		
		switch (GPTIM_CH)
		{
			/***********************Channel 1*****************************/
			case 1: 
					GP_TIM9->CCMR1|= (GPTIM_CC1S<<0);       //Chaneel 1 Config
					GP_TIM9->CCMR1|= (GPTIM_FILTER<<4);     //Filter Config
					if (GPTIM_EDGE_SELEC==0)                //Edge Detection Config
					{
						GP_TIM9->CCER|= ((0U<<1)|(0U<<3));    //Rising Egde
					}
					else 
					{
						GP_TIM9->CCER|= ((1U<<1)|(0U<<3));    //Falling Edge
					}
					GP_TIM9->CCMR1|= (GPTIM_INPUTPSC<<2);   //Input Prescaler Config
					GP_TIM9->CCER|= (1U<<0);                //Capture Enable
					GP_TIM9->DIER|= (0U<<1);                //Interrupt NOT Needed
					
					GP_TIM9->CR1|= (1U<<0);                 //Enable counting
					
					while (~GET_BIT(GP_TIM9->SR,1))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					old_value=GP_TIM9->CCR1;                //Storing the first capture in the variable (old_value)
					GP_TIM9->SR &= ~(1U<<1);                //Clearing the capture flag
					
					while (~GET_BIT(GP_TIM9->SR,1))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					new_value=GP_TIM9->CCR1;                //Storing the first capture in the variable (new_value)
					GP_TIM9->SR &= ~(1U<<1);                //Clearing the capture flag
					GP_TIM9->CR1|= (0U<<0);                 //Disaable counting
					
					if (new_value>old_value)
					{
						capture=new_value-old_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
					else if (old_value>new_value)
					{
						capture=(GPTIM_ARR-old_value)+new_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
			break;
					
					/***********************Channel 2*****************************/
					
				case 2: 
					GP_TIM9->CCMR1|= (GPTIM_CC2S<<8);       //Chaneel 2 Config
					GP_TIM9->CCMR1|= (GPTIM_FILTER<<12);    //Filter Config
					if (GPTIM_EDGE_SELEC==0)                //Edge Detection Config
					{
						GP_TIM9->CCER|= ((0U<<5)|(0U<<7));    //Rising Egde
					}
					else
					{
						GP_TIM9->CCER|= ((1U<<5)|(0U<<7));    //Falling Edge
					}
					GP_TIM9->CCMR1|= (GPTIM_INPUTPSC<<10);  //Input Prescaler Config
					GP_TIM9->CCER|= (1U<<0);                //Capture Enable
					GP_TIM9->DIER|= (0U<<2);                //Interrupt NOT Needed
					
					GP_TIM9->CR1|= (1U<<0);                 //Enable counting
					
					while (~GET_BIT(GP_TIM9->SR,2))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					old_value=GP_TIM9->CCR2;                //Storing the first capture in the variable (old_value)
					GP_TIM9->SR &= ~(1U<<2);                //Clearing the capture flag
					
					while (~GET_BIT(GP_TIM9->SR,2))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					new_value=GP_TIM9->CCR2;                //Storing the first capture in the variable (new_value)
					GP_TIM9->SR &= ~(1U<<2);                //Clearing the capture flag
					GP_TIM9->CR1|= (0U<<0);                 //Disaable counting
					
					if (new_value>old_value)
					{
						capture=new_value-old_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
					else if (old_value>new_value)
					{
						capture=(GPTIM_ARR-old_value)+new_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
			break;
		}
		}
	
	/********************* GPTimer 12 ***********************/
	
	else if (TIM_NUM==12)                               
	{
		GP_TIM12->CCMR1 = 0;  											 //Reset Register
		GP_TIM12->CR1 = 0;    											 //Reset Register
		GP_TIM12->SR = 0;                            //Reset Register
		
		RCC_voidEnableClock (RCC_APB1,6);            //Enable clock to the timer
		GP_TIM12->ARR=GPTIM_ARR;                     //Setting the auto reload register
		GP_TIM12->PSC=PSC_VALUE;                     //Setting the prescaller value
		GP_TIM12->CR1|= (GPTIM_CLK_DIVISION<<8);     //Setting the Clock division Config
		
		switch (GPTIM_CH)
		{
			/***********************Channel 1*****************************/
			case 1: 
					GP_TIM12->CCMR1|= (GPTIM_CC1S<<0);      //Chaneel 1 Config
					GP_TIM12->CCMR1|= (GPTIM_FILTER<<4);    //Filter Config
					if (GPTIM_EDGE_SELEC==0)                //Edge Detection Config
					{
						GP_TIM12->CCER|= ((0U<<1)|(0U<<3));   //Rising Egde
					}
				  else 
					{
						GP_TIM12->CCER|= ((1U<<1)|(0U<<3));    //Falling Edge
					}
					GP_TIM12->CCMR1|= (GPTIM_INPUTPSC<<2);   //Input Prescaler Config
					GP_TIM12->CCER|= (1U<<0);                //Capture Enable
					GP_TIM12->DIER|= (0U<<1);                //Interrupt NOT Needed
					
					GP_TIM12->CR1|= (1U<<0);                 //Enable counting
					
					while (~GET_BIT(GP_TIM12->SR,1))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					old_value=GP_TIM12->CCR1;                //Storing the first capture in the variable (old_value)
					GP_TIM12->SR &= ~(1U<<1);                //Clearing the capture flag
					
					while (~GET_BIT(GP_TIM12->SR,1))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					new_value=GP_TIM12->CCR1;                //Storing the first capture in the variable (new_value)
					GP_TIM12->SR &= ~(1U<<1);                //Clearing the capture flag
					GP_TIM12->CR1|= (0U<<0);                 //Disaable counting
					
					if (new_value>old_value)
					{
						capture=new_value-old_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
					else if (old_value>new_value)
					{
						capture=(GPTIM_ARR-old_value)+new_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
			break;
					
					/***********************Channel 2*****************************/
					
				case 2: 
					GP_TIM12->CCMR1|= (GPTIM_CC2S<<8);       //Chaneel 2 Config
					GP_TIM12->CCMR1|= (GPTIM_FILTER<<12);    //Filter Config
				  if (GPTIM_EDGE_SELEC==0)                 //Edge Detection Config
					{
						GP_TIM12->CCER|= ((0U<<5)|(0U<<7));    //Rising Egde
					}
					else
					{
						GP_TIM12->CCER|= ((1U<<5)|(0U<<7));    //Falling Edge
					}
					GP_TIM12->CCMR1|= (GPTIM_INPUTPSC<<10);  //Input Prescaler Config
					GP_TIM12->CCER|= (1U<<0);                //Capture Enable
					GP_TIM12->DIER|= (0U<<2);                //Interrupt NOT Needed
					
					GP_TIM12->CR1|= (1U<<0);                 //Enable counting
					
					while (~GET_BIT(GP_TIM12->SR,2))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					old_value=GP_TIM12->CCR2;                //Storing the first capture in the variable (old_value)
					GP_TIM12->SR &= ~(1U<<2);                //Clearing the capture flag
					
					while (~GET_BIT(GP_TIM12->SR,2))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					new_value=GP_TIM12->CCR2;                //Storing the first capture in the variable (new_value)
					GP_TIM12->SR &= ~(1U<<2);                //Clearing the capture flag
					GP_TIM12->CR1|= (0U<<0);                 //Disaable counting
					
					if (new_value>old_value)
					{
						capture=new_value-old_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
					else if (old_value>new_value)
					{
						capture=(GPTIM_ARR-old_value)+new_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
			break;
		}
	}
	
	
	/********************* GPTimer 10 ***********************/
	
	else if (TIM_NUM==10)
	{
		GP_TIM10->CCMR1 = 0;  											 //Reset Register
		GP_TIM10->CR1 = 0;    											 //Reset Register
		GP_TIM10->SR = 0;                            //Reset Register
		
		RCC_voidEnableClock (RCC_APB2,17);           //Enable clock to the timer
		GP_TIM10->ARR=GPTIM_ARR;                     //Setting the auto reload register
		GP_TIM10->PSC=PSC_VALUE;                     //Setting the prescaller value
		GP_TIM10->CR1|= (GPTIM_CLK_DIVISION<<8);     //Setting the Clock division Config
		
		GP_TIM10->CCMR1|= (GPTIM_CC1S<<0);             //Chaneel 1 Config
					GP_TIM10->CCMR1|= (GPTIM_FILTER<<4);     //Filter Config
					if (GPTIM_EDGE_SELEC==0)                 //Edge Detection Config
					{
						GP_TIM10->CCER|= ((0U<<1)|(0U<<3));    //Rising Egde
					}
					else
					{
						GP_TIM10->CCER|= ((1U<<1)|(0U<<3));    //Falling Edge
					}
					GP_TIM10->CCMR1|= (GPTIM_INPUTPSC<<2);   //Input Prescaler Config
					GP_TIM10->CCER|= (1U<<0);                //Capture Enable
					GP_TIM10->DIER|= (0U<<1);                //Interrupt NOT Needed
					
					GP_TIM10->CR1|= (1U<<0);                 //Enable counting
					
					while (~GET_BIT(GP_TIM10->SR,1))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					old_value=GP_TIM10->CCR1;               //Storing the first capture in the variable (old_value)
					GP_TIM10->SR &= ~(1U<<1);               //Clearing the capture flag
					
					while (~GET_BIT(GP_TIM10->SR,1))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					new_value=GP_TIM10->CCR1;                //Storing the first capture in the variable (new_value)
					GP_TIM10->SR &= ~(1U<<1);                //Clearing the capture flag
					GP_TIM10->CR1|= (0U<<0);                 //Disaable counting
					
					if (new_value>old_value)
					{
						capture=new_value-old_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
					else if (old_value>new_value)
					{
						capture=(GPTIM_ARR-old_value)+new_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
	}
	
	/********************* GPTimer 11 ***********************/
	
	else if (TIM_NUM==11)
	{
		GP_TIM11->CCMR1 = 0;  											 //Reset Register
		GP_TIM11->CR1 = 0;    											 //Reset Register
		GP_TIM11->SR = 0;                            //Reset Register
		
		RCC_voidEnableClock (RCC_APB2,18);           //Enable clock to the timer
		GP_TIM11->ARR=GPTIM_ARR;                     //Setting the auto reload register
		GP_TIM11->PSC=PSC_VALUE;                     //Setting the prescaller value
		GP_TIM11->CR1|= (GPTIM_CLK_DIVISION<<8);     //Setting the Clock division Config
		
				GP_TIM11->CCMR1|= (GPTIM_CC1S<<0);         //Chaneel 1 Config
					GP_TIM11->CCMR1|= (GPTIM_FILTER<<4);     //Filter Config
					if (GPTIM_EDGE_SELEC==0)                 //Edge Detection Config
					{
						GP_TIM11->CCER|= ((0U<<1)|(0U<<3));    //Rising Egde
					}
					else
					{
						GP_TIM11->CCER|= ((1U<<1)|(0U<<3));    //Falling Edge
					}
					GP_TIM11->CCMR1|= (GPTIM_INPUTPSC<<2);   //Input Prescaler Config
					GP_TIM11->CCER|= (1U<<0);                //Capture Enable
					GP_TIM11->DIER|= (0U<<1);                //Interrupt NOT Needed
					
					GP_TIM11->CR1|= (1U<<0);                 //Enable counting
					
					while (~GET_BIT(GP_TIM11->SR,1))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					old_value=GP_TIM11->CCR1;               //Storing the first capture in the variable (old_value)
					GP_TIM11->SR &= ~(1U<<1);               //Clearing the capture flag
					
					while (~GET_BIT(GP_TIM11->SR,1))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					new_value=GP_TIM11->CCR1;                //Storing the first capture in the variable (new_value)
					GP_TIM11->SR &= ~(1U<<1);                //Clearing the capture flag
					GP_TIM11->CR1|= (0U<<0);                 //Disaable counting
					
					if (new_value>old_value)
					{
						capture=new_value-old_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
					else if (old_value>new_value)
					{
						capture=(GPTIM_ARR-old_value)+new_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
	}
	
	/********************* GPTimer 13 ***********************/
	
	else if (TIM_NUM==13)
	{
		GP_TIM13->CCMR1 = 0;  											 //Reset Register
		GP_TIM13->CR1 = 0;    											 //Reset Register
		GP_TIM13->SR = 0;                            //Reset Register
		
		RCC_voidEnableClock (RCC_APB1,7);            //Enable clock to the timer
		GP_TIM13->ARR=GPTIM_ARR;                     //Setting the auto reload register
		GP_TIM13->PSC=PSC_VALUE;                     //Setting the prescaller value
		GP_TIM13->CR1|= (GPTIM_CLK_DIVISION<<8);     //Setting the Clock division Config
		
				GP_TIM13->CCMR1|= (GPTIM_CC1S<<0);             //Chaneel 1 Config
					GP_TIM13->CCMR1|= (GPTIM_FILTER<<4);     //Filter Config
					if (GPTIM_EDGE_SELEC==0)                 //Edge Detection Config
					{
						GP_TIM13->CCER|= ((0U<<1)|(0U<<3));    //Rising Egde
					}
					else
					{
						GP_TIM13->CCER|= ((1U<<1)|(0U<<3));    //Falling Edge
					}
					GP_TIM13->CCMR1|= (GPTIM_INPUTPSC<<2);   //Input Prescaler Config
					GP_TIM13->CCER|= (1U<<0);                //Capture Enable
					GP_TIM13->DIER|= (0U<<1);                //Interrupt NOT Needed
					
					GP_TIM13->CR1|= (1U<<0);                 //Enable counting
					
					while (~GET_BIT(GP_TIM13->SR,1))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					old_value=GP_TIM13->CCR1;               //Storing the first capture in the variable (old_value)
					GP_TIM13->SR &= ~(1U<<1);               //Clearing the capture flag
					
					while (~GET_BIT(GP_TIM13->SR,1))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					new_value=GP_TIM13->CCR1;                //Storing the first capture in the variable (new_value)
					GP_TIM13->SR &= ~(1U<<1);                //Clearing the capture flag
					GP_TIM13->CR1|= (0U<<0);                 //Disaable counting
					
					if (new_value>old_value)
					{
						capture=new_value-old_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
					else if (old_value>new_value)
					{
						capture=(GPTIM_ARR-old_value)+new_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
	}
	
	/********************* GPTimer 14 ***********************/
	
	else if (TIM_NUM==14)
	{
		GP_TIM14->CCMR1 = 0;  											 //Reset Register
		GP_TIM14->CR1 = 0;    											 //Reset Register
		GP_TIM14->SR = 0;                            //Reset Register
		
		RCC_voidEnableClock (RCC_APB1,8);            //Enable clock to the timer
		GP_TIM14->ARR=GPTIM_ARR;                     //Setting the auto reload register
		GP_TIM14->PSC=PSC_VALUE;                     //Setting the prescaller value
		GP_TIM14->CR1|= (GPTIM_CLK_DIVISION<<8);     //Setting the Clock division Config
		
				GP_TIM14->CCMR1|= (GPTIM_CC1S<<0);             //Chaneel 1 Config
					GP_TIM14->CCMR1|= (GPTIM_FILTER<<4);     //Filter Config
					if (GPTIM_EDGE_SELEC==0)                 //Edge Detection Config
					{
						GP_TIM14->CCER|= ((0U<<1)|(0U<<3));    //Rising Egde
					}
					else
					{
						GP_TIM14->CCER|= ((1U<<1)|(0U<<3));    //Falling Edge
					}
					GP_TIM14->CCMR1|= (GPTIM_INPUTPSC<<2);   //Input Prescaler Config
					GP_TIM14->CCER|= (1U<<0);                //Capture Enable
					GP_TIM14->DIER|= (0U<<1);                //Interrupt NOT Needed
					
					GP_TIM14->CR1|= (1U<<0);                 //Enable counting
					
					while (~GET_BIT(GP_TIM14->SR,1))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					old_value=GP_TIM14->CCR1;               //Storing the first capture in the variable (old_value)
					GP_TIM14->SR &= ~(1U<<1);               //Clearing the capture flag
					
					while (~GET_BIT(GP_TIM14->SR,1))
					{
						//Wait until the Capture happens and check if the interrupt flag is set or not. 
					}
					new_value=GP_TIM14->CCR1;                //Storing the first capture in the variable (new_value)
					GP_TIM14->SR &= ~(1U<<1);                //Clearing the capture flag
					GP_TIM14->CR1|= (0U<<0);                 //Disaable counting
					
					if (new_value>old_value)
					{
						capture=new_value-old_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
					else if (old_value>new_value)
					{
						capture=(GPTIM_ARR-old_value)+new_value;
						frequency=TIM_CLK/(capture*PSC_VALUE+1);
					}
	}
	
	else
	{
		//Error
	}
	return frequency;
}
