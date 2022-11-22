/**********************************************************/
/*Author    : youstina                                    */
/*version   : v01                                         */
/*date      : 16 JAN 2021                                 */
/**********************************************************/
#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "STD_TYPES.h"


typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 OAR1;
	volatile u32 OAR2;
	volatile u32 DR;
	volatile u32 SR1;
	volatile u32 SR2;
	volatile u32 CCR;
	volatile u32 TRISE;
	volatile u32 FLTR;
}I2C_t;


#define     I2C_1    ((volatile I2C_t*)0x40005400)
#define     I2C_2    ((volatile I2C_t*)0x40005800)
#define     I2C_3    ((volatile I2C_t*)0x40005C00)


/* I2C OPTIONS */
#define     I2C1    0 
#define     I2C2    1
#define     I2C3    2

/* MODE OPTIONS */
#define      STD_MODE          0b0
#define      FAST_MODE         0b1


/* CLOCK_STRETCHING OPTIONS */
#define     CLOCK_STRETCHING_DISABLED      1
#define     CLOCK_STRETCHING_ENABLED       0


/* General_Call OPTIONS */
#define     GENERAL_CALL_ENABLE            1
#define     GENERAL_CALL_DISABLE           0

/* DUTY CYCLE OPTIONS */
#define     ENABLE_DUTY           1
#define     DISABLE_DUTY          0

/* INTERRUPTS OPTIONS */
#define     BUFFER_INT            10
#define     EVENT_INT              9
#define     ERROR_INT              8


/* STATUS1 OPTIONS */
#define      SB_BIT                   0
#define      ADDR_BIT                 1
#define      BTF_BIT                  2
#define      ADD10_BIT                3
#define      STOPF_BIT                4
#define      RxNE_BIT                 6
#define      TxE_BIT                  7
#define      BERR_BIT                 8
#define      ARLO_BIT                 9
#define      AF_BIT                   10 
#define      OVR_BIT                  11
#define     PECERR_BIT                12
#define     TIMEOUT_BIT               14
#define     SMBALERT_BIT              15


/* STATUS2 OPTIONS */
#define     DUALF                7  
#define     SMBHOST              6     
#define     SMBDEFAULT           5
#define     GENCALL              4  
#define     TRA                  2  
#define     BUSY                 1  
#define     MSL                  0  

/* BitToClear OPTIONS */
#define     SMB_ALERT            15
#define     TIME_OUT             14
#define     PEC_ERROR            12
#define     OVER_RUN             11
#define     ACK_FAILURE          10
#define     ARBITERATION_LOSS    9
#define     BUS_ERROR            8

/* ADDRESS_MODE OPTIONS */
#define     _7BIT_ADD             0
#define     _10BIT_ADD            1

/* NumberOfData OPTIONS */
#define     ONE_BYTE                       0
#define     MORE_THAN_ONE_BYTE             1


/* BITS NAMES */
#define     START                8
#define     STOP                 9
#define     ACK_BIT              10


/* SMBus communication */
#define     ENABLE       1
#define     DISABLE      0


#endif
