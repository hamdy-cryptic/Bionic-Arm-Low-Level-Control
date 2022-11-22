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

/* STREAM SELECTED OPTIONS : FROM STREAM_0 TO STREAM_7   */
#define       STREAM_ID           STREAM_0

/* OPTIONS FOR STREAM_MASK : Stream0_Mask - Stream7_Mask */
#define   STREAM_MASK   Stream0_Mask

/* CHOOSE THE WANTED CHANNEL      FROM CHANNEL0-7  */
#define        CHANNEL_ID         CHANNEL1

/* options : VERY_HIGH, HIGH , MEDIUM, LOW  */
#define      PRIORITY_LEVEL          VERY_HIGH

/* OPTIONS FOR MEMORY DATA SIZE & PERIPHERAL DATA SIZE : BYTE , HALF_WORD , WORD  */
#define      MEMORY_DATA_SIZE          WORD
#define      PERIPHERAL_DATA_SIZE      WORD

/* OPTIONS FOR MEMORY & PERIPHERAL INCREAMENT MODE : ACTIVATED , DEACTIVATED */
#define           MEMORY_INCREAMENT_MODE                  ACTIVATED      /*  memory address pointer is incremented after each data transfer */
#define           PERIPHERAL_INCREAMENT_MODE              ACTIVATED      /*  peripheral address pointer is incremented after each data transfer */

/* OPTIONS FOR CIRCULAR MODE : ENABLED , DISABLED */
#define    CIRCULAR_MODE                DISABLED 

/* OPTIONS FOR DATA TRANSFER DIRECTION : PERIPHERAL_TO_MEMORY , MEMORY_TO_PERIPHERAL , MEMORY_TO_MEMORY */
#define     DATA_TRANSFER_DIRECTION          PERIPHERAL_TO_MEMORY

/* OPTIONS FOR TRANSFER_COMPLETE_INTERRUPT : ENABLED , DISABLED  */
#define      TRANSFER_COMPLETE_INTERRUPT        ENABLED 

/* OPTIONS FOR HALF_TRANSFER_INTERRUPT : ENABLED , DISABLED  */
#define      HALF_TRANSFER_INTERRUPT                DISABLED 

/* OPTIONS FOR TRANSFER_ERROR_INTERRUPT : ENABLED , DISABLED  */
#define      TRANSFER_ERROR_INTERRUPT              ENABLED 

/* OPTIONS FOR DIRECT_MODE_ERROR_INTERRUPT : ENABLED , DISABLED  */
#define      DIRECT_MODE_ERROR_INTERRUPT        ENABLED  

/* OPTIONS FOR  number of data items to transfer from 0 to 65535 */
//#define     NUM_DATA_ITEMS_TR             32768

/* options for peripheral address IN THE INTERFACE FILE  */
//#define    PERIPHERAL_ADDRESS             ADC1

/* options for MEMORY address IN THE INTERFACE FILE  */
//#define    MEMORY0_ADDRESS             ADC1

/* FIFO or DIRECT MODE :  DIRECT_MODE_ENABLED ,  DIRECT_MODE_DISABLED */
#define    DIRECT_MODE       DIRECT_MODE_ENABLED         //IN CASE OF MEMORY_TO_MEMORY MUST BE DISABLED  

#endif
