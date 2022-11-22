/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 12 February 2020                                 */
/* Version : V01                                             */
/*************************************************************/

#include "CRC_private.h"
#include "CRC_interface.h"
#include "CRC_config.h"
#include "RCC_program.c"

#define NULL		(void * )0
	
 void CRC_INIT(void)
 {
	RCC_voidEnableClock (RCC_AHB1, 12) ;
 }
 
 void CRC_DEINIT(void)
 {
  RCC_voidDisableClock (RCC_AHB1 , 12);
 }
 
 void CRC_RESET(void)
 {
	 CRC_CR |= CRC_CR_RESET;
 }
 
 u32 CRC_READ_DATA(u32 CRC_DATA)
 {
	 CRC_DR = CRC_DATA;
	 return CRC_DR;
 }
 
 
 u32 GET_CRC_DR(void)
 {
	 return CRC_DR;
 }
 
 void CRC_SET_IDR(u8 CRC_ID_DATA)
 {
	  CRC_DR = CRC_ID_DATA ;
 }
 
 u8 CRC_GET_IDR(void)
 {
	 return CRC_IDR;
 }
 
 
 
 u32 CRC_HW_16(u16 *Data , u32 size)
 {
	 if(Data !=NULL)
	 {
		 CRC_CR = CRC_CR_RESET ;
	 }
	  while(size--)
	  {
		  CRC_DR= *Data;
	  }
	  return CRC_DR;
 }
 
 u32 CRC_HW_32(u32 *Data , u32 size)
 {
	 if(Data !=NULL)
	 {
		 CRC_CR = CRC_CR_RESET ;
	 }
	  while(size--)
	  {
		  CRC_DR= *Data;
	  }
	  return CRC_DR;
 }
 
 u8 CRC_SW_8(u8 Data , u8 size , u8 polynomial)
 {
	 u8 crc=0;
	 u8 _crc;
	 crc^= Data;
	 for(u8 i=0 ; i<size ; ++i )
	 {
		 if(crc&0x80)
		 {
			 _crc=(crc<<1) ;
			 _crc^=polynomial;
		 }
		 else 
		 {
			 _crc=crc<<1;
		 }
		 return _crc;
	 }
 }
 
 
 
 