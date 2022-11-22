/************************************/
/* Author : Yomna Attia             */
/* Date : 12/12/2020                */
/* version : 01                     */
/************************************/
#ifndef RCC_interface_h
#define RCC_interface_h

#define RCC_AHB1     0
#define RCC_AHB2     1
#define RCC_AHB3     2
#define RCC_APB1     3
#define RCC_APB2     4
#define RCC_AHB1LP   5
#define RCC_AHB2LP   6
#define RCC_AHB3LP   7
#define RCC_APB1LP   8
#define RCC_APB2LP   9

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