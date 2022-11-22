/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 11 December 2020                                 */
/* Version : V02.5                                            */
/*************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

 void GPIO_voidSetPinDirection(u8 GPIO_PORT , u8 GPIO_PIN , u8 GPIO_Mode ) 
 {
   switch (GPIO_PORT)
   { 
       case GPIOA :
	        if(GPIO_PIN<8){
				   if (GPIO_Mode == GPIO_ANALOG){
					   GPIOA_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF){
					   GPIOA_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs
					   GPIOA_CRL |= ((0x9UL)<<(GPIO_PIN*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF_OD){
					   GPIOA_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs
					   GPIOA_CRL |= ((0xDUL)<<(GPIO_PIN*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_INPUT){
						GPIOA_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
						GPIOA_CRL |=((GPIO_Mode&3)<<(GPIO_PIN*4));   //Set as Input Mode
						GPIOA_CRL |=((4)<<(GPIO_PIN*4));             //Set as Floating Point
						break;
				   }
				   else if (GPIO_Mode == GPIO_OUTPUT){
					   GPIOA_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
					   GPIOA_CRL |=((GPIO_Mode&3)<<(GPIO_PIN*4));   //Set as OUTPUT 10MHz Mode (push pull)
					   break;
				   }
			}
			else if (GPIO_PIN < 16){
				   if (GPIO_Mode == GPIO_ANALOG){
					   GPIOA_CRH &=~((0x15UL)<<(((GPIO_PIN-8))*4));       //Reset Pin Configs 
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF){
					   GPIOA_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs
					   GPIOA_CRH |= ((0x9UL)<<((GPIO_PIN-8)*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF_OD){
					   GPIOA_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs
					   GPIOA_CRH |= ((0xDUL)<<((GPIO_PIN-8)*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_INPUT){
						GPIOA_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs 
						GPIOA_CRH |=((GPIO_Mode&3)<<((GPIO_PIN-8)*4));   //Set as Input Mode
						GPIOA_CRH |=((4)<<((GPIO_PIN-8)*4));             //Set as Floating Point
						break;
				   }
				   else if (GPIO_Mode == GPIO_OUTPUT){
					   GPIOA_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs 
					   GPIOA_CRH |=((GPIO_Mode&3)<<((GPIO_PIN-8)*4));   //Set as OUTPUT 10MHz Mode (push pull)
					   break;
				   }
			}
				   break;
	   case GPIOB :
				   if(GPIO_PIN<8){
				   if (GPIO_Mode == GPIO_ANALOG){
					   GPIOB_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF){
					   GPIOB_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs
					   GPIOB_CRL |= ((0x9UL)<<(GPIO_PIN*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF_OD){
					   GPIOB_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs
					   GPIOB_CRL |= ((0xDUL)<<(GPIO_PIN*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_INPUT){
						GPIOB_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
						GPIOB_CRL |=((GPIO_Mode&3)<<(GPIO_PIN*4));   //Set as Input Mode
						GPIOB_CRL |=((4)<<(GPIO_PIN*4));             //Set as Floating Point
						break;
				   }
				   else if (GPIO_Mode == GPIO_OUTPUT){
					   GPIOB_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
					   GPIOB_CRL |=((GPIO_Mode&3)<<(GPIO_PIN*4));   //Set as OUTPUT 10MHz Mode (push pull)
					   break;
				   }
			}
			else if (GPIO_PIN < 16){
				   if (GPIO_Mode == GPIO_ANALOG){
					   GPIOB_CRH &=~((0x15UL)<<(((GPIO_PIN-8))*4));       //Reset Pin Configs 
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF){
					   GPIOB_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs
					   GPIOB_CRH |= ((0x9UL)<<((GPIO_PIN-8)*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF_OD){
					   GPIOB_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs
					   GPIOB_CRH |= ((0xDUL)<<((GPIO_PIN-8)*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_INPUT){
						GPIOB_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs 
						GPIOB_CRH |=((GPIO_Mode&3)<<((GPIO_PIN-8)*4));   //Set as Input Mode
						GPIOB_CRH |=((4)<<((GPIO_PIN-8)*4));             //Set as Floating Point
						break;
				   }
				   else if (GPIO_Mode == GPIO_OUTPUT){
					   GPIOB_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs 
					   GPIOB_CRH |=((GPIO_Mode&3)<<((GPIO_PIN-8)*4));   //Set as OUTPUT 10MHz Mode (push pull)
					   break;
				   }
			}
				   break;
	               
	   case GPIOC :
				   if(GPIO_PIN<8){
				   if (GPIO_Mode == GPIO_ANALOG){
					   GPIOC_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF){
					   GPIOC_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs
					   GPIOC_CRL |= ((0x9UL)<<(GPIO_PIN*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF_OD){
					   GPIOC_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs
					   GPIOC_CRL |= ((0xDUL)<<(GPIO_PIN*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_INPUT){
						GPIOC_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
						GPIOC_CRL |=((GPIO_Mode&3)<<(GPIO_PIN*4));   //Set as Input Mode
						GPIOC_CRL |=((4)<<(GPIO_PIN*4));             //Set as Floating Point
						break;
				   }
				   else if (GPIO_Mode == GPIO_OUTPUT){
					   GPIOC_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
					   GPIOC_CRL |=((GPIO_Mode&3)<<(GPIO_PIN*4));   //Set as OUTPUT 10MHz Mode (push pull)
					   break;
				   }
			}
			else if (GPIO_PIN < 16){
				   if (GPIO_Mode == GPIO_ANALOG){
					   GPIOC_CRH &=~((0x15UL)<<(((GPIO_PIN-8))*4));       //Reset Pin Configs 
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF){
					   GPIOC_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs
					   GPIOC_CRH |= ((0x9UL)<<((GPIO_PIN-8)*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF_OD){
					   GPIOC_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs
					   GPIOC_CRH |= ((0xDUL)<<((GPIO_PIN-8)*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_INPUT){
						GPIOC_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs 
						GPIOC_CRH |=((GPIO_Mode&3)<<((GPIO_PIN-8)*4));   //Set as Input Mode
						GPIOC_CRH |=((4)<<((GPIO_PIN-8)*4));             //Set as Floating Point
						break;
				   }
				   else if (GPIO_Mode == GPIO_OUTPUT){
					   GPIOC_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs 
					   GPIOC_CRH |=((GPIO_Mode&3)<<((GPIO_PIN-8)*4));   //Set as OUTPUT 10MHz Mode (push pull)
					   break;
				   }
			}
				   break;
	   case GPIOD :
				   if(GPIO_PIN<8){
				   if (GPIO_Mode == GPIO_ANALOG){
					   GPIOD_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF){
					   GPIOD_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs
					   GPIOD_CRL |= ((0x9UL)<<(GPIO_PIN*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF_OD){
					   GPIOD_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs
					   GPIOD_CRL |= ((0xDUL)<<(GPIO_PIN*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_INPUT){
						GPIOD_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
						GPIOD_CRL |=((GPIO_Mode&3)<<(GPIO_PIN*4));   //Set as Input Mode
						GPIOD_CRL |=((4)<<(GPIO_PIN*4));             //Set as Floating Point
						break;
				   }
				   else if (GPIO_Mode == GPIO_OUTPUT){
					   GPIOD_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
					   GPIOD_CRL |=((GPIO_Mode&3)<<(GPIO_PIN*4));   //Set as OUTPUT 10MHz Mode (push pull)
					   break;
				   }
			}
			else if (GPIO_PIN < 16){
				   if (GPIO_Mode == GPIO_ANALOG){
					   GPIOD_CRH &=~((0x15UL)<<(((GPIO_PIN-8))*4));       //Reset Pin Configs 
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF){
					   GPIOD_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs
					   GPIOD_CRH |= ((0x9UL)<<((GPIO_PIN-8)*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF_OD){
					   GPIOD_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs
					   GPIOD_CRH |= ((0xDUL)<<((GPIO_PIN-8)*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_INPUT){
						GPIOD_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs 
						GPIOD_CRH |=((GPIO_Mode&3)<<((GPIO_PIN-8)*4));   //Set as Input Mode
						GPIOD_CRH |=((4)<<((GPIO_PIN-8)*4));             //Set as Floating Point
						break;
				   }
				   else if (GPIO_Mode == GPIO_OUTPUT){
					   GPIOD_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs 
					   GPIOD_CRH |=((GPIO_Mode&3)<<((GPIO_PIN-8)*4));   //Set as OUTPUT 10MHz Mode (push pull)
					   break;
				   }
			}
				   break;
	   case GPIOE : 
				   if(GPIO_PIN<8){
				   if (GPIO_Mode == GPIO_ANALOG){
					   GPIOE_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF){
					   GPIOE_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs
					   GPIOE_CRL |= ((0x9UL)<<(GPIO_PIN*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF_OD){
					   GPIOE_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs
					   GPIOE_CRL |= ((0xDUL)<<(GPIO_PIN*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_INPUT){
						GPIOE_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
						GPIOE_CRL |=((GPIO_Mode&3)<<(GPIO_PIN*4));   //Set as Input Mode
						GPIOE_CRL |=((4)<<(GPIO_PIN*4));             //Set as Floating Point
						break;
				   }
				   else if (GPIO_Mode == GPIO_OUTPUT){
					   GPIOE_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
					   GPIOE_CRL |=((GPIO_Mode&3)<<(GPIO_PIN*4));   //Set as OUTPUT 10MHz Mode (push pull)
					   break;
				   }
			}
			else if (GPIO_PIN < 16){
				   if (GPIO_Mode == GPIO_ANALOG){
					   GPIOE_CRH &=~((0x15UL)<<(((GPIO_PIN-8))*4));       //Reset Pin Configs 
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF){
					   GPIOE_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs
					   GPIOE_CRH |= ((0x9UL)<<((GPIO_PIN-8)*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF_OD){
					   GPIOE_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs
					   GPIOE_CRH |= ((0xDUL)<<((GPIO_PIN-8)*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_INPUT){
						GPIOE_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs 
						GPIOE_CRH |=((GPIO_Mode&3)<<((GPIO_PIN-8)*4));   //Set as Input Mode
						GPIOE_CRH |=((4)<<((GPIO_PIN-8)*4));             //Set as Floating Point
						break;
				   }
				   else if (GPIO_Mode == GPIO_OUTPUT){
					   GPIOE_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs 
					   GPIOE_CRH |=((GPIO_Mode&3)<<((GPIO_PIN-8)*4));   //Set as OUTPUT 10MHz Mode (push pull)
					   break;
				   }
			}
				   break;
	   case GPIOF :
				   if(GPIO_PIN<8){
				   if (GPIO_Mode == GPIO_ANALOG){
					   GPIOF_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF){
					   GPIOF_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs
					   GPIOF_CRL |= ((0x9UL)<<(GPIO_PIN*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF_OD){
					   GPIOF_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs
					   GPIOF_CRL |= ((0xDUL)<<(GPIO_PIN*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_INPUT){
						GPIOF_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
						GPIOF_CRL |=((GPIO_Mode&3)<<(GPIO_PIN*4));   //Set as Input Mode
						GPIOF_CRL |=((4)<<(GPIO_PIN*4));             //Set as Floating Point
						break;
				   }
				   else if (GPIO_Mode == GPIO_OUTPUT){
					   GPIOF_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
					   GPIOF_CRL |=((GPIO_Mode&3)<<(GPIO_PIN*4));   //Set as OUTPUT 10MHz Mode (push pull)
					   break;
				   }
			}
			else if (GPIO_PIN < 16){
				   if (GPIO_Mode == GPIO_ANALOG){
					   GPIOF_CRH &=~((0x15UL)<<(((GPIO_PIN-8))*4));       //Reset Pin Configs 
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF){
					   GPIOF_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs
					   GPIOF_CRH |= ((0x9UL)<<((GPIO_PIN-8)*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF_OD){
					   GPIOF_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs
					   GPIOF_CRH |= ((0xDUL)<<((GPIO_PIN-8)*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_INPUT){
						GPIOF_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs 
						GPIOF_CRH |=((GPIO_Mode&3)<<((GPIO_PIN-8)*4));   //Set as Input Mode
						GPIOF_CRH |=((4)<<((GPIO_PIN-8)*4));             //Set as Floating Point
						break;
				   }
				   else if (GPIO_Mode == GPIO_OUTPUT){
					   GPIOF_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs 
					   GPIOF_CRH |=((GPIO_Mode&3)<<((GPIO_PIN-8)*4));   //Set as OUTPUT 10MHz Mode (push pull)
					   break;
				   }
			}
				   break;
	   case GPIOG :
				   if(GPIO_PIN<8){
				   if (GPIO_Mode == GPIO_ANALOG){
					   GPIOG_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF){
					   GPIOG_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs
					   GPIOG_CRL |= ((0x9UL)<<(GPIO_PIN*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF_OD){
					   GPIOG_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs
					   GPIOG_CRL |= ((0xDUL)<<(GPIO_PIN*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_INPUT){
						GPIOG_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
						GPIOG_CRL |=((GPIO_Mode&3)<<(GPIO_PIN*4));   //Set as Input Mode
						GPIOG_CRL |=((4)<<(GPIO_PIN*4));             //Set as Floating Point
						break;
				   }
				   else if (GPIO_Mode == GPIO_OUTPUT){
					   GPIOG_CRL &=~((0x15UL)<<(GPIO_PIN*4));       //Reset Pin Configs 
					   GPIOG_CRL |=((GPIO_Mode&3)<<(GPIO_PIN*4));   //Set as OUTPUT 10MHz Mode (push pull)
					   break;
				   }
			}
			else if (GPIO_PIN < 16){
				   if (GPIO_Mode == GPIO_ANALOG){
					   GPIOG_CRH &=~((0x15UL)<<(((GPIO_PIN-8))*4));       //Reset Pin Configs 
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF){
					   GPIOG_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs
					   GPIOG_CRH |= ((0x9UL)<<((GPIO_PIN-8)*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_AF_OD){
					   GPIOG_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs
					   GPIOG_CRH |= ((0xDUL)<<((GPIO_PIN-8)*4));        //Set AF output 10MHz with PP Mode
				       break;
				   }
				   else if (GPIO_Mode == GPIO_INPUT){
						GPIOG_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs 
						GPIOG_CRH |=((GPIO_Mode&3)<<((GPIO_PIN-8)*4));   //Set as Input Mode
						GPIOG_CRH |=((4)<<((GPIO_PIN-8)*4));             //Set as Floating Point
						break;
				   }
				   else if (GPIO_Mode == GPIO_OUTPUT){
					   GPIOG_CRH &=~((0x15UL)<<((GPIO_PIN-8)*4));       //Reset Pin Configs 
					   GPIOG_CRH |=((GPIO_Mode&3)<<((GPIO_PIN-8)*4));   //Set as OUTPUT 10MHz Mode (push pull)
					   break;
				   }
			}
				   break;
				default : break;
 }
 }
 
 void SET_GPIO_SPEED( u8 GPIO_PORT , u8 GPIO_PIN ,u8 GPIO_Speed )
 {
 switch (GPIO_PORT)
   { 
       case GPIOA :
				   if(GPIO_PIN<8){
						if ((((GPIOA_CRL)>>(GPIO_PIN*4))&3)==1){
							if (GPIO_Speed == GPIO_SPEED_LOW){
								GPIOA_CRL &=~((0x1)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOA_CRL |=((0x2)<<(GPIO_PIN*4));           //Set as OUTPUT 2MHz Mode 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_MEDIUM){ 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_HIGH){ 
								GPIOA_CRL |=((0x3UL)<<(GPIO_PIN*4));           //Set as OUTPUT 50MHz Mode 
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
				   if ((((GPIOA_CRH)>>((GPIO_PIN-8)*4))&3)==1){
							if (GPIO_Speed == GPIO_SPEED_LOW){
								GPIOA_CRH &=~((0x1)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOA_CRH |=((0x2)<<((GPIO_PIN-8)*4));           //Set as OUTPUT 2MHz Mode 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_MEDIUM){ 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_HIGH){ 
								GPIOA_CRH |=((0x3UL)<<((GPIO_PIN-8)*4));           //Set as OUTPUT 50MHz Mode 
								break;
							}
						}
				   }
				   break;
	 case GPIOB :
				   if(GPIO_PIN<8){
						if ((((GPIOB_CRL)>>(GPIO_PIN*4))&3)==1){
							if (GPIO_Speed == GPIO_SPEED_LOW){
								GPIOB_CRL &=~((0x1)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOB_CRL |=((0x2)<<(GPIO_PIN*4));           //Set as OUTPUT 2MHz Mode 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_MEDIUM){ 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_HIGH){ 
								GPIOB_CRL |=((0x3UL)<<(GPIO_PIN*4));           //Set as OUTPUT 50MHz Mode 
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
				   if ((((GPIOB_CRH)>>((GPIO_PIN-8)*4))&3)==1){
							if (GPIO_Speed == GPIO_SPEED_LOW){
								GPIOB_CRH &=~((0x1)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOB_CRH |=((0x2)<<((GPIO_PIN-8)*4));           //Set as OUTPUT 2MHz Mode 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_MEDIUM){ 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_HIGH){ 
								GPIOB_CRH |=((0x3UL)<<((GPIO_PIN-8)*4));           //Set as OUTPUT 50MHz Mode 
								break;
							}
						}
				   }
				   break;
	 case GPIOC :
				   if(GPIO_PIN<8){
						if ((((GPIOC_CRL)>>(GPIO_PIN*4))&3)==1){
							if (GPIO_Speed == GPIO_SPEED_LOW){
								GPIOC_CRL &=~((0x1)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOC_CRL |=((0x2)<<(GPIO_PIN*4));           //Set as OUTPUT 2MHz Mode 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_MEDIUM){ 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_HIGH){ 
								GPIOC_CRL |=((0x3UL)<<(GPIO_PIN*4));           //Set as OUTPUT 50MHz Mode 
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
				   if ((((GPIOC_CRH)>>((GPIO_PIN-8)*4))&3)==1){
							if (GPIO_Speed == GPIO_SPEED_LOW){
								GPIOC_CRH &=~((0x1)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOC_CRH |=((0x2)<<((GPIO_PIN-8)*4));           //Set as OUTPUT 2MHz Mode 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_MEDIUM){ 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_HIGH){ 
								GPIOC_CRH |=((0x3UL)<<((GPIO_PIN-8)*4));           //Set as OUTPUT 50MHz Mode 
								break;
							}
						}
				   }
				   break;
	   case GPIOD :			  
				   if(GPIO_PIN<8){
						if ((((GPIOD_CRL)>>(GPIO_PIN*4))&3)==1){
							if (GPIO_Speed == GPIO_SPEED_LOW){
								GPIOD_CRL &=~((0x1)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOD_CRL |=((0x2)<<(GPIO_PIN*4));           //Set as OUTPUT 2MHz Mode 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_MEDIUM){ 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_HIGH){ 
								GPIOD_CRL |=((0x3UL)<<(GPIO_PIN*4));           //Set as OUTPUT 50MHz Mode 
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
				   if ((((GPIOD_CRH)>>((GPIO_PIN-8)*4))&3)==1){
							if (GPIO_Speed == GPIO_SPEED_LOW){
								GPIOD_CRH &=~((0x1)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOD_CRH |=((0x2)<<((GPIO_PIN-8)*4));           //Set as OUTPUT 2MHz Mode 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_MEDIUM){ 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_HIGH){ 
								GPIOD_CRH |=((0x3UL)<<((GPIO_PIN-8)*4));           //Set as OUTPUT 50MHz Mode 
								break;
							}
						}
				   }
				   break;
	   case GPIOE : 
				   if(GPIO_PIN<8){
						if ((((GPIOE_CRL)>>(GPIO_PIN*4))&3)==1){
							if (GPIO_Speed == GPIO_SPEED_LOW){
								GPIOE_CRL &=~((0x1)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOE_CRL |=((0x2)<<(GPIO_PIN*4));           //Set as OUTPUT 2MHz Mode 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_MEDIUM){ 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_HIGH){ 
								GPIOE_CRL |=((0x3UL)<<(GPIO_PIN*4));           //Set as OUTPUT 50MHz Mode 
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
				   if ((((GPIOE_CRH)>>((GPIO_PIN-8)*4))&3)==1){
							if (GPIO_Speed == GPIO_SPEED_LOW){
								GPIOE_CRH &=~((0x1)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOE_CRH |=((0x2)<<((GPIO_PIN-8)*4));           //Set as OUTPUT 2MHz Mode 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_MEDIUM){ 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_HIGH){ 
								GPIOE_CRH |=((0x3UL)<<((GPIO_PIN-8)*4));           //Set as OUTPUT 50MHz Mode 
								break;
							}
						}
				   }
				   break;
	   case GPIOF : 
				   if(GPIO_PIN<8){
						if ((((GPIOF_CRL)>>(GPIO_PIN*4))&3)==1){
							if (GPIO_Speed == GPIO_SPEED_LOW){
								GPIOF_CRL &=~((0x1)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOF_CRL |=((0x2)<<(GPIO_PIN*4));           //Set as OUTPUT 2MHz Mode 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_MEDIUM){ 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_HIGH){ 
								GPIOF_CRL |=((0x3UL)<<(GPIO_PIN*4));           //Set as OUTPUT 50MHz Mode 
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
				   if ((((GPIOF_CRH)>>((GPIO_PIN-8)*4))&3)==1){
							if (GPIO_Speed == GPIO_SPEED_LOW){
								GPIOF_CRH &=~((0x1)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOF_CRH |=((0x2)<<((GPIO_PIN-8)*4));           //Set as OUTPUT 2MHz Mode 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_MEDIUM){ 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_HIGH){ 
								GPIOF_CRH |=((0x3UL)<<((GPIO_PIN-8)*4));           //Set as OUTPUT 50MHz Mode 
								break;
							}
						}
				   }
				   break;
	   case GPIOG :
				   if(GPIO_PIN<8){
						if ((((GPIOG_CRL)>>(GPIO_PIN*4))&3)==1){
							if (GPIO_Speed == GPIO_SPEED_LOW){
								GPIOG_CRL &=~((0x1)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOG_CRL |=((0x2)<<(GPIO_PIN*4));           //Set as OUTPUT 2MHz Mode 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_MEDIUM){ 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_HIGH){ 
								GPIOG_CRL |=((0x3UL)<<(GPIO_PIN*4));           //Set as OUTPUT 50MHz Mode 
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
				   if ((((GPIOG_CRH)>>((GPIO_PIN-8)*4))&3)==1){
							if (GPIO_Speed == GPIO_SPEED_LOW){
								GPIOG_CRH &=~((0x1)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOG_CRH |=((0x2)<<((GPIO_PIN-8)*4));           //Set as OUTPUT 2MHz Mode 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_MEDIUM){ 
								break;
							}
							else if (GPIO_Speed == GPIO_SPEED_HIGH){ 
								GPIOG_CRH |=((0x3UL)<<((GPIO_PIN-8)*4));           //Set as OUTPUT 50MHz Mode 
								break;
							}
						}
				   }
				   break;
				   default: break;
 }
 }
 
 
 void GPIO_SET_PP_OD (u8 GPIO_PORT , u8 GPIO_PIN, u8 GPIO_PP_OD)
 {
 switch (GPIO_PORT)
   { 
       case GPIOA :
				   if(GPIO_PIN<8){
						if (((((GPIOA_CRL)>>(GPIO_PIN*4))&3)!=0) && ((((GPIOA_CRL)>>(GPIO_PIN*4+2))&3)< 2) ){               //Check Output Mode
							if (GPIO_PP_OD == GPIO_OUTPUT_PP){
								GPIOA_CRL &=~((0xC)<<(GPIO_PIN*4));          //Reset Pin Configs  (Push pull)
								break;
							}
							else if (GPIO_PP_OD == GPIO_OUTPUT_OD){ 
								GPIOA_CRL &=~((0xC)<<(GPIO_PIN*4));          //Reset Pin Configs (Push pull)
								GPIOA_CRL |= ((0x4)<<(GPIO_PIN*4));          //Set Pin Configs (open drain)
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
						if (((((GPIOA_CRH)>>((GPIO_PIN-8)*4))&3)!=0)  && ((((GPIOA_CRH)>>((GPIO_PIN-8)*4+2))&3)< 2)){               //Check Output Mode
							if (GPIO_PP_OD == GPIO_OUTPUT_PP){
								GPIOA_CRH &=~((0xC)<<((GPIO_PIN-8)*4));          //Reset Pin Configs  (Push pull)
								break;
							}
							else if (GPIO_PP_OD == GPIO_OUTPUT_OD){ 
								GPIOA_CRH &=~((0xC)<<((GPIO_PIN-8)*4));          //Reset Pin Configs (Push pull)
								GPIOA_CRH |= ((0x4)<<((GPIO_PIN-8)*4));          //Set Pin Configs (open drain)
								break;
							}
						}
				   }
				   break;
	  case GPIOB :
				 if(GPIO_PIN<8){
						if (((((GPIOB_CRL)>>(GPIO_PIN*4))&3)!=0) && ((((GPIOB_CRL)>>(GPIO_PIN*4+2))&3)< 2) ){               //Check Output Mode
							if (GPIO_PP_OD == GPIO_OUTPUT_PP){
								GPIOB_CRL &=~((0xC)<<(GPIO_PIN*4));          //Reset Pin Configs  (Push pull)
								break;
							}
							else if (GPIO_PP_OD == GPIO_OUTPUT_OD){ 
								GPIOB_CRL &=~((0xC)<<(GPIO_PIN*4));          //Reset Pin Configs (Push pull)
								GPIOB_CRL |= ((0x4)<<(GPIO_PIN*4));          //Set Pin Configs (open drain)
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
						if (((((GPIOB_CRH)>>((GPIO_PIN-8)*4))&3)!=0)  && ((((GPIOB_CRH)>>((GPIO_PIN-8)*4+2))&3)< 2)){               //Check Output Mode
							if (GPIO_PP_OD == GPIO_OUTPUT_PP){
								GPIOB_CRH &=~((0xC)<<((GPIO_PIN-8)*4));          //Reset Pin Configs  (Push pull)
								break;
							}
							else if (GPIO_PP_OD == GPIO_OUTPUT_OD){ 
								GPIOB_CRH &=~((0xC)<<((GPIO_PIN-8)*4));          //Reset Pin Configs (Push pull)
								GPIOB_CRH |= ((0x4)<<((GPIO_PIN-8)*4));          //Set Pin Configs (open drain)
								break;
							}
						}
				   }
				   break;
	   case GPIOC :
				 if(GPIO_PIN<8){
						if (((((GPIOC_CRL)>>(GPIO_PIN*4))&3)!=0) && ((((GPIOC_CRL)>>(GPIO_PIN*4+2))&3)< 2) ){               //Check Output Mode
							if (GPIO_PP_OD == GPIO_OUTPUT_PP){
								GPIOC_CRL &=~((0xC)<<(GPIO_PIN*4));          //Reset Pin Configs  (Push pull)
								break;
							}
							else if (GPIO_PP_OD == GPIO_OUTPUT_OD){ 
								GPIOC_CRL &=~((0xC)<<(GPIO_PIN*4));          //Reset Pin Configs (Push pull)
								GPIOC_CRL |= ((0x4)<<(GPIO_PIN*4));          //Set Pin Configs (open drain)
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
						if (((((GPIOC_CRH)>>((GPIO_PIN-8)*4))&3)!=0)  && ((((GPIOC_CRH)>>((GPIO_PIN-8)*4+2))&3)< 2)){               //Check Output Mode
							if (GPIO_PP_OD == GPIO_OUTPUT_PP){
								GPIOC_CRH &=~((0xC)<<((GPIO_PIN-8)*4));          //Reset Pin Configs  (Push pull)
								break;
							}
							else if (GPIO_PP_OD == GPIO_OUTPUT_OD){ 
								GPIOC_CRH &=~((0xC)<<((GPIO_PIN-8)*4));          //Reset Pin Configs (Push pull)
								GPIOC_CRH |= ((0x4)<<((GPIO_PIN-8)*4));          //Set Pin Configs (open drain)
								break;
							}
						}
				   }
				   break;
	   case GPIOD :
				  if(GPIO_PIN<8){
						if (((((GPIOD_CRL)>>(GPIO_PIN*4))&3)!=0) && ((((GPIOD_CRL)>>(GPIO_PIN*4+2))&3)< 2) ){               //Check Output Mode
							if (GPIO_PP_OD == GPIO_OUTPUT_PP){
								GPIOD_CRL &=~((0xC)<<(GPIO_PIN*4));          //Reset Pin Configs  (Push pull)
								break;
							}
							else if (GPIO_PP_OD == GPIO_OUTPUT_OD){ 
								GPIOD_CRL &=~((0xC)<<(GPIO_PIN*4));          //Reset Pin Configs (Push pull)
								GPIOD_CRL |= ((0x4)<<(GPIO_PIN*4));          //Set Pin Configs (open drain)
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
						if (((((GPIOD_CRH)>>((GPIO_PIN-8)*4))&3)!=0)  && ((((GPIOD_CRH)>>((GPIO_PIN-8)*4+2))&3)< 2)){               //Check Output Mode
							if (GPIO_PP_OD == GPIO_OUTPUT_PP){
								GPIOD_CRH &=~((0xC)<<((GPIO_PIN-8)*4));          //Reset Pin Configs  (Push pull)
								break;
							}
							else if (GPIO_PP_OD == GPIO_OUTPUT_OD){ 
								GPIOD_CRH &=~((0xC)<<((GPIO_PIN-8)*4));          //Reset Pin Configs (Push pull)
								GPIOD_CRH |= ((0x4)<<((GPIO_PIN-8)*4));          //Set Pin Configs (open drain)
								break;
							}
						}
				   }
				   break;
	   case GPIOE :
				   if(GPIO_PIN<8){
						if (((((GPIOE_CRL)>>(GPIO_PIN*4))&3)!=0) && ((((GPIOE_CRL)>>(GPIO_PIN*4+2))&3)< 2) ){               //Check Output Mode
							if (GPIO_PP_OD == GPIO_OUTPUT_PP){
								GPIOE_CRL &=~((0xC)<<(GPIO_PIN*4));          //Reset Pin Configs  (Push pull)
								break;
							}
							else if (GPIO_PP_OD == GPIO_OUTPUT_OD){ 
								GPIOE_CRL &=~((0xC)<<(GPIO_PIN*4));          //Reset Pin Configs (Push pull)
								GPIOE_CRL |= ((0x4)<<(GPIO_PIN*4));          //Set Pin Configs (open drain)
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
						if (((((GPIOE_CRH)>>((GPIO_PIN-8)*4))&3)!=0)  && ((((GPIOE_CRH)>>((GPIO_PIN-8)*4+2))&3)< 2)){               //Check Output Mode
							if (GPIO_PP_OD == GPIO_OUTPUT_PP){
								GPIOE_CRH &=~((0xC)<<((GPIO_PIN-8)*4));          //Reset Pin Configs  (Push pull)
								break;
							}
							else if (GPIO_PP_OD == GPIO_OUTPUT_OD){ 
								GPIOE_CRH &=~((0xC)<<((GPIO_PIN-8)*4));          //Reset Pin Configs (Push pull)
								GPIOE_CRH |= ((0x4)<<((GPIO_PIN-8)*4));          //Set Pin Configs (open drain)
								break;
							}
						}
				   }
				   break;
	   case GPIOF :
				   if(GPIO_PIN<8){
						if (((((GPIOF_CRL)>>(GPIO_PIN*4))&3)!=0) && ((((GPIOF_CRL)>>(GPIO_PIN*4+2))&3)< 2) ){               //Check Output Mode
							if (GPIO_PP_OD == GPIO_OUTPUT_PP){
								GPIOF_CRL &=~((0xC)<<(GPIO_PIN*4));          //Reset Pin Configs  (Push pull)
								break;
							}
							else if (GPIO_PP_OD == GPIO_OUTPUT_OD){ 
								GPIOF_CRL &=~((0xC)<<(GPIO_PIN*4));          //Reset Pin Configs (Push pull)
								GPIOF_CRL |= ((0x4)<<(GPIO_PIN*4));          //Set Pin Configs (open drain)
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
						if (((((GPIOF_CRH)>>((GPIO_PIN-8)*4))&3)!=0)  && ((((GPIOF_CRH)>>((GPIO_PIN-8)*4+2))&3)< 2)){               //Check Output Mode
							if (GPIO_PP_OD == GPIO_OUTPUT_PP){
								GPIOF_CRH &=~((0xC)<<((GPIO_PIN-8)*4));          //Reset Pin Configs  (Push pull)
								break;
							}
							else if (GPIO_PP_OD == GPIO_OUTPUT_OD){ 
								GPIOF_CRH &=~((0xC)<<((GPIO_PIN-8)*4));          //Reset Pin Configs (Push pull)
								GPIOF_CRH |= ((0x4)<<((GPIO_PIN-8)*4));          //Set Pin Configs (open drain)
								break;
							}
						}
				   }
				   break;
	   case GPIOG :
				  if(GPIO_PIN<8){
						if (((((GPIOG_CRL)>>(GPIO_PIN*4))&3)!=0) && ((((GPIOG_CRL)>>(GPIO_PIN*4+2))&3)< 2) ){               //Check Output Mode
							if (GPIO_PP_OD == GPIO_OUTPUT_PP){
								GPIOG_CRL &=~((0xC)<<(GPIO_PIN*4));          //Reset Pin Configs  (Push pull)
								break;
							}
							else if (GPIO_PP_OD == GPIO_OUTPUT_OD){ 
								GPIOG_CRL &=~((0xC)<<(GPIO_PIN*4));          //Reset Pin Configs (Push pull)
								GPIOG_CRL |= ((0x4)<<(GPIO_PIN*4));          //Set Pin Configs (open drain)
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
						if (((((GPIOG_CRH)>>((GPIO_PIN-8)*4))&3)!=0)  && ((((GPIOG_CRH)>>((GPIO_PIN-8)*4+2))&3)< 2)){               //Check Output Mode
							if (GPIO_PP_OD == GPIO_OUTPUT_PP){
								GPIOG_CRH &=~((0xC)<<((GPIO_PIN-8)*4));          //Reset Pin Configs  (Push pull)
								break;
							}
							else if (GPIO_PP_OD == GPIO_OUTPUT_OD){ 
								GPIOG_CRH &=~((0xC)<<((GPIO_PIN-8)*4));          //Reset Pin Configs (Push pull)
								GPIOG_CRH |= ((0x4)<<((GPIO_PIN-8)*4));          //Set Pin Configs (open drain)
								break;
							}
						}
				   }
				   break;
				default : break;
 }
 }
 void GPIO_SET_PU_PD (u8 GPIO_PORT , u8 GPIO_PIN, u8 GPIO_PU_PD)
 {
 switch (GPIO_PORT)
   { 
       case GPIOA :
				   if(GPIO_PIN<8){
						if ((((GPIOA_CRL)>>(GPIO_PIN*4))&3)==0){               //Check Input Mode
							if (GPIO_PU_PD == GPIO_NO_PU_PD){
								break;
							}
							else if (GPIO_PU_PD == GPIO_PU){ 
								GPIOA_CRL &=~((0x4)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOA_CRL |= ((0x8)<<(GPIO_PIN*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOA_ODR |= ((0x1)<<(GPIO_PIN));          //Pull Up Mode
								break;
							}
							else if (GPIO_PU_PD == GPIO_PD){ 
								GPIOA_CRL &=~((0x4)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOA_CRL |= ((0x8)<<(GPIO_PIN*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOA_ODR &=~((0x1)<<(GPIO_PIN));          //Pull Down Mode
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
						if ((((GPIOA_CRH)>>((GPIO_PIN-8)*4))&3)==0){               //Check Input Mode
							if (GPIO_PU_PD == GPIO_NO_PU_PD){
								break;
							}
							else if (GPIO_PU_PD == GPIO_PU){ 
								GPIOA_CRH &=~((0x4)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOA_CRH |= ((0x8)<<((GPIO_PIN-8)*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOA_ODR |= ((0x1)<<(GPIO_PIN));          //Pull Up Mode
								break;
							}
							else if (GPIO_PU_PD == GPIO_PD){ 
								GPIOA_CRH &=~((0x4)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOA_CRH |= ((0x8)<<((GPIO_PIN-8)*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOA_ODR &=~((0x1)<<(GPIO_PIN));          //Pull Down Mode
								break;
							}
						}
				   }
				   break;  
	   case GPIOB :
				   if(GPIO_PIN<8){
						if ((((GPIOB_CRL)>>(GPIO_PIN*4))&3)==0){               //Check Input Mode
							if (GPIO_PU_PD == GPIO_NO_PU_PD){
								break;
							}
							else if (GPIO_PU_PD == GPIO_PU){ 
								GPIOB_CRL &=~((0x4)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOB_CRL |= ((0x8)<<(GPIO_PIN*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOB_ODR |= ((0x1)<<(GPIO_PIN));          //Pull Up Mode
								break;
							}
							else if (GPIO_PU_PD == GPIO_PD){ 
								GPIOB_CRL &=~((0x4)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOB_CRL |= ((0x8)<<(GPIO_PIN*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOB_ODR &=~((0x1)<<(GPIO_PIN));          //Pull Down Mode
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
						if ((((GPIOB_CRH)>>((GPIO_PIN-8)*4))&3)==0){               //Check Input Mode
							if (GPIO_PU_PD == GPIO_NO_PU_PD){
								break;
							}
							else if (GPIO_PU_PD == GPIO_PU){ 
								GPIOB_CRH &=~((0x4)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOB_CRH |= ((0x8)<<((GPIO_PIN-8)*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOB_ODR |= ((0x1)<<(GPIO_PIN));          //Pull Up Mode
								break;
							}
							else if (GPIO_PU_PD == GPIO_PD){ 
								GPIOB_CRH &=~((0x4)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOB_CRH |= ((0x8)<<((GPIO_PIN-8)*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOB_ODR &=~((0x1)<<(GPIO_PIN));          //Pull Down Mode
								break;
							}
						}
				   }
				   break;  
	   case GPIOC :
				   if(GPIO_PIN<8){
						if ((((GPIOC_CRL)>>(GPIO_PIN*4))&3)==0){               //Check Input Mode
							if (GPIO_PU_PD == GPIO_NO_PU_PD){
								break;
							}
							else if (GPIO_PU_PD == GPIO_PU){ 
								GPIOC_CRL &=~((0x4)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOC_CRL |= ((0x8)<<(GPIO_PIN*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOC_ODR |= ((0x1)<<(GPIO_PIN));          //Pull Up Mode
								break;
							}
							else if (GPIO_PU_PD == GPIO_PD){ 
								GPIOC_CRL &=~((0x4)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOC_CRL |= ((0x8)<<(GPIO_PIN*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOC_ODR &=~((0x1)<<(GPIO_PIN));          //Pull Down Mode
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
						if ((((GPIOC_CRH)>>((GPIO_PIN-8)*4))&3)==0){               //Check Input Mode
							if (GPIO_PU_PD == GPIO_NO_PU_PD){
								break;
							}
							else if (GPIO_PU_PD == GPIO_PU){ 
								GPIOC_CRH &=~((0x4)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOC_CRH |= ((0x8)<<((GPIO_PIN-8)*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOC_ODR |= ((0x1)<<(GPIO_PIN));          //Pull Up Mode
								break;
							}
							else if (GPIO_PU_PD == GPIO_PD){ 
								GPIOC_CRH &=~((0x4)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOC_CRH |= ((0x8)<<((GPIO_PIN-8)*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOC_ODR &=~((0x1)<<(GPIO_PIN));          //Pull Down Mode
								break;
							}
						}
				   }
				   break;    
	   case GPIOD :
				   if(GPIO_PIN<8){
						if ((((GPIOD_CRL)>>(GPIO_PIN*4))&3)==0){               //Check Input Mode
							if (GPIO_PU_PD == GPIO_NO_PU_PD){
								break;
							}
							else if (GPIO_PU_PD == GPIO_PU){ 
								GPIOD_CRL &=~((0x4)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOD_CRL |= ((0x8)<<(GPIO_PIN*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOD_ODR |= ((0x1)<<(GPIO_PIN));          //Pull Up Mode
								break;
							}
							else if (GPIO_PU_PD == GPIO_PD){ 
								GPIOD_CRL &=~((0x4)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOD_CRL |= ((0x8)<<(GPIO_PIN*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOD_ODR &=~((0x1)<<(GPIO_PIN));          //Pull Down Mode
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
						if ((((GPIOD_CRH)>>((GPIO_PIN-8)*4))&3)==0){               //Check Input Mode
							if (GPIO_PU_PD == GPIO_NO_PU_PD){
								break;
							}
							else if (GPIO_PU_PD == GPIO_PU){ 
								GPIOD_CRH &=~((0x4)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOD_CRH |= ((0x8)<<((GPIO_PIN-8)*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOD_ODR |= ((0x1)<<(GPIO_PIN));          //Pull Up Mode
								break;
							}
							else if (GPIO_PU_PD == GPIO_PD){ 
								GPIOD_CRH &=~((0x4)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOD_CRH |= ((0x8)<<((GPIO_PIN-8)*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOD_ODR &=~((0x1)<<(GPIO_PIN));          //Pull Down Mode
								break;
							}
						}
				   }
				   break;   
	   case GPIOE : 
				   if(GPIO_PIN<8){
						if ((((GPIOE_CRL)>>(GPIO_PIN*4))&3)==0){               //Check Input Mode
							if (GPIO_PU_PD == GPIO_NO_PU_PD){
								break;
							}
							else if (GPIO_PU_PD == GPIO_PU){ 
								GPIOE_CRL &=~((0x4)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOE_CRL |= ((0x8)<<(GPIO_PIN*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOE_ODR |= ((0x1)<<(GPIO_PIN));          //Pull Up Mode
								break;
							}
							else if (GPIO_PU_PD == GPIO_PD){ 
								GPIOE_CRL &=~((0x4)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOE_CRL |= ((0x8)<<(GPIO_PIN*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOE_ODR &=~((0x1)<<(GPIO_PIN));          //Pull Down Mode
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
						if ((((GPIOE_CRH)>>((GPIO_PIN-8)*4))&3)==0){               //Check Input Mode
							if (GPIO_PU_PD == GPIO_NO_PU_PD){
								break;
							}
							else if (GPIO_PU_PD == GPIO_PU){ 
								GPIOE_CRH &=~((0x4)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOE_CRH |= ((0x8)<<((GPIO_PIN-8)*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOE_ODR |= ((0x1)<<(GPIO_PIN));          //Pull Up Mode
								break;
							}
							else if (GPIO_PU_PD == GPIO_PD){ 
								GPIOE_CRH &=~((0x4)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOE_CRH |= ((0x8)<<((GPIO_PIN-8)*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOE_ODR &=~((0x1)<<(GPIO_PIN));          //Pull Down Mode
								break;
							}
						}
				   }
				   break;  
	   case GPIOF :			   
				  if(GPIO_PIN<8){
						if ((((GPIOF_CRL)>>(GPIO_PIN*4))&3)==0){               //Check Input Mode
							if (GPIO_PU_PD == GPIO_NO_PU_PD){
								break;
							}
							else if (GPIO_PU_PD == GPIO_PU){ 
								GPIOF_CRL &=~((0x4)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOF_CRL |= ((0x8)<<(GPIO_PIN*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOF_ODR |= ((0x1)<<(GPIO_PIN));          //Pull Up Mode
								break;
							}
							else if (GPIO_PU_PD == GPIO_PD){ 
								GPIOF_CRL &=~((0x4)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOF_CRL |= ((0x8)<<(GPIO_PIN*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOF_ODR &=~((0x1)<<(GPIO_PIN));          //Pull Down Mode
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
						if ((((GPIOF_CRH)>>((GPIO_PIN-8)*4))&3)==0){               //Check Input Mode
							if (GPIO_PU_PD == GPIO_NO_PU_PD){
								break;
							}
							else if (GPIO_PU_PD == GPIO_PU){ 
								GPIOF_CRH &=~((0x4)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOF_CRH |= ((0x8)<<((GPIO_PIN-8)*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOF_ODR |= ((0x1)<<(GPIO_PIN));          //Pull Up Mode
								break;
							}
							else if (GPIO_PU_PD == GPIO_PD){ 
								GPIOF_CRH &=~((0x4)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOF_CRH |= ((0x8)<<((GPIO_PIN-8)*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOF_ODR &=~((0x1)<<(GPIO_PIN));          //Pull Down Mode
								break;
							}
						}
				   }
				   break;  
	   case GPIOG :
				  if(GPIO_PIN<8){
						if ((((GPIOG_CRL)>>(GPIO_PIN*4))&3)==0){               //Check Input Mode
							if (GPIO_PU_PD == GPIO_NO_PU_PD){
								break;
							}
							else if (GPIO_PU_PD == GPIO_PU){ 
								GPIOG_CRL &=~((0x4)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOG_CRL |= ((0x8)<<(GPIO_PIN*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOG_ODR |= ((0x1)<<(GPIO_PIN));          //Pull Up Mode
								break;
							}
							else if (GPIO_PU_PD == GPIO_PD){ 
								GPIOG_CRL &=~((0x4)<<(GPIO_PIN*4));          //Reset Pin Configs 
								GPIOG_CRL |= ((0x8)<<(GPIO_PIN*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOG_ODR &=~((0x1)<<(GPIO_PIN));          //Pull Down Mode
								break;
							}
						}
				   }
			
					else if (GPIO_PIN < 16){
						if ((((GPIOG_CRH)>>((GPIO_PIN-8)*4))&3)==0){               //Check Input Mode
							if (GPIO_PU_PD == GPIO_NO_PU_PD){
								break;
							}
							else if (GPIO_PU_PD == GPIO_PU){ 
								GPIOG_CRH &=~((0x4)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOG_CRH |= ((0x8)<<((GPIO_PIN-8)*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOG_ODR |= ((0x1)<<(GPIO_PIN));          //Pull Up Mode
								break;
							}
							else if (GPIO_PU_PD == GPIO_PD){ 
								GPIOG_CRH &=~((0x4)<<((GPIO_PIN-8)*4));          //Reset Pin Configs 
								GPIOG_CRH |= ((0x8)<<((GPIO_PIN-8)*4));          //Set Pin Configs   (Push Pull Mode)
								GPIOG_ODR &=~((0x1)<<(GPIO_PIN));          //Pull Down Mode
								break;
							}
						}
				   }
				   break;   
				default : break;
	   
 }
 }
 
 
 
void GPIO_voidSetPinValue(u8 GPIO_PORT , u8 GPIO_PIN , u8 GPIO_Value)
{
     switch(GPIO_PORT)
	 {  
	      case GPIOA :
                       if(GPIO_Value == GPIO_HIGH)
                        {
                            SET_BIT(GPIOA_ODR , GPIO_PIN);
                        }
                       else if(GPIO_Value == GPIO_LOW)
                        {
                            CLR_BIT(GPIOA_ODR, GPIO_PIN);						
                        }
						break;
			case GPIOB :			
						if(GPIO_Value == GPIO_HIGH)
                        {
                            SET_BIT(GPIOB_ODR , GPIO_PIN);
                        }
                       else if(GPIO_Value == GPIO_LOW)
                        {
                            CLR_BIT(GPIOB_ODR, GPIO_PIN);						
                        }
						break;
	        case GPIOC :			
						if(GPIO_Value == GPIO_HIGH)
                        {
                            SET_BIT(GPIOC_ODR , GPIO_PIN);
                        }
                       else if(GPIO_Value == GPIO_LOW)
                        {
                            CLR_BIT(GPIOC_ODR, GPIO_PIN);						
                        }
						break;
		    case GPIOD :			
						if(GPIO_Value == GPIO_HIGH)
                        {
                            SET_BIT(GPIOD_ODR , GPIO_PIN);
                        }
                       else if(GPIO_Value == GPIO_LOW)
                        {
                            CLR_BIT(GPIOD_ODR, GPIO_PIN);						
                        }
						break;
			case GPIOE :			
						if(GPIO_Value == GPIO_HIGH)
                        {
                            SET_BIT(GPIOE_ODR , GPIO_PIN);
                        }
                       else if(GPIO_Value == GPIO_LOW)
                        {
                            CLR_BIT(GPIOE_ODR, GPIO_PIN);						
                        }
						break;	
			case GPIOF :			
						if(GPIO_Value == GPIO_HIGH)
                        {
                            SET_BIT(GPIOF_ODR , GPIO_PIN);
                        }
                       else if(GPIO_Value == GPIO_LOW)
                        {
                            CLR_BIT(GPIOF_ODR, GPIO_PIN);						
                        }
						break;	
			case GPIOG :			
						if(GPIO_Value == GPIO_HIGH)
                        {
                            SET_BIT(GPIOG_ODR , GPIO_PIN);
                        }
                       else if(GPIO_Value == GPIO_LOW)
                        {
                            CLR_BIT(GPIOG_ODR, GPIO_PIN);						
                        }
						break;	
            default: break;						
}
}

u8 MGPIO_u8GetPinValue(u8 GPIO_PORT , u8 GPIO_PIN )
{
    u8 LOCAL_Result = 0 ;
	switch(GPIO_PORT)
	 {
	 case GPIOA : 
	              LOCAL_Result = GET_BIT(GPIOA_IDR , GPIO_PIN );
				  break;
	 case GPIOB : 
	              LOCAL_Result = GET_BIT(GPIOB_IDR , GPIO_PIN );
				  break;
	 case GPIOC : 
	              LOCAL_Result = GET_BIT(GPIOC_IDR , GPIO_PIN );
				  break;
	case GPIOD : 
	              LOCAL_Result = GET_BIT(GPIOD_IDR , GPIO_PIN );
				  break;
	case GPIOE : 
	              LOCAL_Result = GET_BIT(GPIOE_IDR , GPIO_PIN );
				  break;
	case GPIOF : 
	              LOCAL_Result = GET_BIT(GPIOF_IDR , GPIO_PIN );
				  break;	
    case GPIOG : 
	              LOCAL_Result = GET_BIT(GPIOG_IDR , GPIO_PIN );
				  break;	
                 default : break;				  
} 
   return LOCAL_Result;
   }
   
  