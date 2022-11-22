/******************************************************/
/* Author    : Salem Majed                            */
/* Date      : 15 DEC 2020                            */
/* Version   : 1                                      */
/******************************************************/

#include <DataTypes_and_BitMath.h>
#include <STK_interface.h>
#include <STK_Configuration.h>
#include <STK_Private.h>

static volatile uint32 cnt;
void static(* ptr_interr)(void);                                                                      /* Global pointer that stores the enterrupt function address*/

		/************** The Initialization Function ****************/
		
void MSTK_void_SysTick_Initialize ()
{
	if (SYS_CLK_SEL && DEFAULT_T_UNITS) 						   // checking the time units and clock cycle selection
	{
		SysTick_CTRL=0; 															            /* Disabling the SysTick module */
		SysTick_LOAD = (SYS_CLK * SYS_OVERFLOW)-1;           									/* Setting the reload value between Interrupts */
		cnt=SysTick_LOAD;
		//NVIC_setpPririty (SysTiick, SysTick_Priority)  										/* Setting the SysTick priority */
		SysTick_VAL=0;                                   									    /* Clearing the Cureent value register */
		SysTick_CTRL= (SysTick_CTRL_ENABLE|SysTick_CTRL_TICKINT|SysTick_CTRL_CLKSOURCE);  		/* Enabling the SysTick Module */
	}
	else if (SYS_CLK_SEL && DEFAULT_T_UNITS == 0)
	{
		SysTick_CTRL=0; 															   			/* Disabling the SysTick module */
		SysTick_LOAD = (SYS_CLK * SYS_OVERFLOW*1000)-1;       									/* Setting the reload value between Interrupts */
		cnt=SysTick_LOAD;
		//NVIC_setpPririty (SysTiick, SysTick_Priority)  										/* Setting the SysTick priority */
		SysTick_VAL=0;                                   										/* Clearing the Cureent value register */
		SysTick_CTRL= (SysTick_CTRL_ENABLE|SysTick_CTRL_TICKINT|SysTick_CTRL_CLKSOURCE);  		/* Enabling the SysTick Module */
	}
		else if (SYS_CLK_SEL == 0 && DEFAULT_T_UNITS)
	{
		SysTick_CTRL=0; 															   			/* Disabling the SysTick module */
		SysTick_LOAD = (SYS_CLK/8 * SYS_OVERFLOW)-1;       										/* Setting the reload value between Interrupts */
		cnt=SysTick_LOAD;
		//NVIC_setpPririty (SysTiick, SysTick_Priority)  										/* Setting the SysTick priority */
		SysTick_VAL=0;                                   										/* Clearing the Cureent value register */
		SysTick_CTRL= (SysTick_CTRL_ENABLE|SysTick_CTRL_TICKINT|SysTick_CTRL_CLKSOURCE_BY8);    /* Enabling the SysTick Module */
	}
	else
	{
		SysTick_CTRL=0; 															   			/* Disabling the SysTick module */
		SysTick_LOAD = (SYS_CLK/8 * SYS_OVERFLOW*1000)-1;       								/* Setting the reload value between Interrupts */
		cnt=SysTick_LOAD;
		//NVIC_setpPririty (SysTiick, SysTick_Priority)  										/* Setting the SysTick priority */
		SysTick_VAL=0;                                   									    /* Clearing the Cureent value register */
		SysTick_CTRL= (SysTick_CTRL_ENABLE|SysTick_CTRL_TICKINT|SysTick_CTRL_CLKSOURCE_BY8);    /* Enabling the SysTick Module */
	}
}

		/************** The SysTick_Handler Function ****************/

void SysTick_Handler (void)
{
	ptr_interr ();
}

		/************** Ticks2Millisec Function ****************/

uint32 Ticks2Millisec (uint32 ticks)
{
	uint32 m_Secs=0;
	if (SYS_CLK_SEL)
		return m_Secs = (ticks/(SYS_CLK))*1000;
	else
		return m_Secs = (ticks/(SYS_CLK/8))*1000;
}

		/************** Millisec2Ticks Function ****************/

uint32 Millisec2Ticks (uint32 m_Secs)
{
	uint32 ticks=0;
	if (SYS_CLK_SEL)
		return ticks = (m_Secs*(SYS_CLK))/1000;
	else
		return ticks = (m_Secs*(SYS_CLK/8))/1000;
}

		/************** The Delay Function ****************/

void MSTK_void_SysTick_Delay (uint32 t)
{
	uint32 Ticks=0; 	
	Ticks=Millisec2Ticks (t);
	
	if (~DEFAULT_T_UNITS)                       /* The t is in milliseconds */
	{
		SysTick_VAL=0;
    SysTick_LOAD=Ticks-1;
		while (~(GET_BIT(SysTick_CTRL,16)));    /* Do nothing until the counterflag is 1 */
	}
  else                                          /* The t is in microseconds */
	{
		SysTick_VAL=0;
		SysTick_LOAD=(Ticks*1000)-1;
		while (~(GET_BIT(SysTick_CTRL,16))); 	/* Do nothing until the counterflag is 1 */
	}		
}

		/************** The Elapsed Time Function ****************/

uint32 MSTK_uint32_SysTick_ElapsedTime (void)
{
	uint32 elap_t=0;
	if (~DEFAULT_T_UNITS)                     /* The elapsed time is in milliseconds */
	{
		elap_t = Ticks2Millisec (SysTick_LOAD) - Ticks2Millisec (SysTick_VAL);
		return elap_t;
	}
	else                                     /* The elapsed time is in microseconds */
	{
		elap_t = Ticks2Millisec (SysTick_LOAD) - Ticks2Millisec (SysTick_VAL);
		return elap_t*1000;	
	}
}

		/************** The Single Timer Function ****************/

uint32 MSTK_uint32_SysTick_STimer (uint32 t, void (*interr_funct_name)(void))
{
	uint32 Ticks=0; 	
	Ticks=Millisec2Ticks (t);
	ptr_interr = interr_funct_name;           /* The function adress is saved in the global pointer ptr_interr that will be called in the handler */
	if (~DEFAULT_T_UNITS)                     /* The t is in milliseconds */
	{
		SysTick_VAL=0;
		SysTick_LOAD=Ticks-1;
	}
  else                                        /* The t is in microseconds */
	{
		SysTick_VAL=0;
		SysTick_LOAD=(Ticks*1000)-1;
	}
	
    if (GET_BIT(SysTick_CTRL,16))             /* Preventing a periodic counting */
		SysTick_LOAD=0;	
}

		/************** The Periodic Timer Function ****************/

uint32 MSTK_uint32_SysTick_PTimer (uint32 t, void (*interr_funct_name)(void))
{
	uint32 Ticks=0; 	
	Ticks=Millisec2Ticks (t);
	ptr_interr = interr_funct_name;           /* The function adress is saved in the global pointer ptr_interr that will be called in the handler */
	if (~DEFAULT_T_UNITS)                     /* The t is in milliseconds */
	{
		SysTick_VAL=0;
		SysTick_LOAD=Ticks-1;
	}
  else                                        /* The t is in microseconds */
	{
		SysTick_VAL=0;
		SysTick_LOAD=(Ticks*1000)-1;
	}
}

		/************** The SysTick TimePause Function ****************/
		
void MSTK_void_SysTick_TimePause (void)
{
	SysTick_CTRL = SysTick_CTRL_DISABLE;     /* Setting the enable bit to 0 */
}

		/************** The SysTick TimeResume Function ****************/
		
void MSTK_void_SysTick_TimeResume (void)
{
	SysTick_CTRL = SysTick_CTRL_ENABLE;     /* Setting the enable bit to 1 */
}

