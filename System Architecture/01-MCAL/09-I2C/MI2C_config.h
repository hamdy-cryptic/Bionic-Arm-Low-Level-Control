/*********************************************************/
/*Author    : youstina                                   */
/*version   : v04                                        */
/*date      : 31 MAR 2021                                */
/*********************************************************/
#ifndef MI2C_CONFIG_H
#define MI2C_CONFIG_H



/********** MASTER CONFIGURATION **********/

/* CLOCK_STRETCHING_ENABLED OR CLOCK_STRETCHING_DISABLED */
/*  the interface holds the clock line low before transmission OR NOT  */
#define    CLOCK_STRETCHING   CLOCK_STRETCHING_ENABLED 

/* OPTIONS FOR FREQ :from 4 to 45 IN CASE OF FAST_MODE & from 2 to 45 IN CASE OF STD_MODE */
#define    FREQ               50

/* OPTIONS FOR MODE : STD_MODE , FAST_MODE */
#define    MODE               FAST_MODE  

/* OPTIONS FOR DUTY (IN CASE OF FAST_MODE): ENABLE_DUTY , DISABLE_DUTY */
#define    DUTY               DISABLE_DUTY       

/* OPTIONS FOR GENERAL_CALL : GENERAL_CALL_ENABLE , GENERAL_CALL_DISABLE */
#define    GENERAL_CALL       GENERAL_CALL_DISABLE      


/* OPTIONS FOR CLK : from 0x04  to 0xFFF  (from  0x01 in CASE OF FAST DUTY ) */
#define    CLK                30


/* OPTIONS FOR RISE_TIME : from 2 to 63 */
#define    RISE_TIME          51


/******* SLAVE CONFIGURATION **********/
/* OPTIONS FOR OWN_ADD_1 & OWN_ADD_2 : FROM 0x4000 TO 0x40FF */
#define   OWN_ADD_1      0x4004
#define   OWN_ADD_2      0x4040



/******** CONFIGURATION FOR SMBus **********/

#define    ENPEC           ENABLE      // ENPEC OPTIONS : ENABLE , DISABLE
#define    PEC             TRANSFER    // PEC OPTIONS : TRANSFER NO_TRANSFER
#define    ENARP           ENABLE      // address recognition 
#define    ALERT           HIGH_ALERT        // ALERT OPTIONS : HIGH , LOW 
#define    SMBTYPE         HOST        // SMBTYPE OPTIONS : HOST , DEVICE

/* OPTIONS FOR CLK : from 0x04  to 0xFFF  */
#define    CLK_SM          100
#define    RISE_TIME_SM    9

#define    CCR_REQ         3000
#define    FREQ_REQ        2

/******* SMBUS STATUS BITS *************/
#define    TIMEOUT         0x4000
#define    PECERR          0x1000
#define    ARLO            0x0200
#define    SMBALERT        0x8000

/* SMBTYPE OPTIONS */
#define     HOST           1
#define     DEVICE         0


/* SMBus communication */
#define     ENABLE         1
#define     DISABLE        0

/* ALERT OPTIONS */
#define     HIGH_ALERT     1
#define     LOW_ALERT      0

/* ALERT OPTIONS */
#define     TRANSFER       1
#define     NO_TRANSFER    0



#endif