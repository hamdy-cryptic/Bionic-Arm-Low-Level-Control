/*********************************************************/
/*Author    : youstina                                   */
/*version   : v02                                        */
/*date      : 25 JAN 2021                                */
/*********************************************************/
#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H

/* DMA OPTIONS : DMA1 , DMA2 */
/*IN CASE OF MEMORY TO MEMORY DMA2 IS A MUST */
#define     DMA       DMA1 
/* CHOOSE THE WANTED CHANNEL      FROM CHANNEL0-7  */
#define        CHANNEL_ID               CHANNEL1

/* options : VERY_HIGH, HIGH , MEDIUM, LOW  */
#define      PRIORITY_LEVEL          VERY_HIGH

/* OPTIONS FOR DATA TRANSFER DIRECTION : PERIPHERAL_TO_MEMORY , MEMORY_TO_PERIPHERAL , MEMORY_TO_MEMORY */
#define     DATA_TRANSFER_DIRECTION          PERIPHERAL_TO_MEMORY

/* OPTIONS FOR CIRCULAR MODE : ENABLED , DISABLED */
#define    CIRCULAR_MODE                       DISABLED 

/* OPTIONS FOR MEMORY & PERIPHERAL INCREAMENT MODE : ACTIVATED , DEACTIVATED */
#define           MEMORY_INCREAMENT_MODE                  ACTIVATED      /*  memory address pointer is incremented after each data transfer */
#define           PERIPHERAL_INCREAMENT_MODE              ACTIVATED      /*  peripheral address pointer is incremented after each data transfer */

/* OPTIONS FOR MEMORY DATA SIZE & PERIPHERAL DATA SIZE : BYTE , HALF_WORD , WORD  */
#define      MEMORY_DATA_SIZE          WORD
#define      PERIPHERAL_DATA_SIZE      WORD


/* OPTIONS FOR  number of data items to transfer from 0 to 65535 */
//#define     NUM_DATA_ITEMS_TR             32768

/* options for peripheral address IN THE INTERFACE FILE  */
//#define    PERIPHERAL_ADDRESS             ADC1

/* options for MEMORY address IN THE INTERFACE FILE  */
//#define    MEMORY0_ADDRESS             ADC1
#endif
