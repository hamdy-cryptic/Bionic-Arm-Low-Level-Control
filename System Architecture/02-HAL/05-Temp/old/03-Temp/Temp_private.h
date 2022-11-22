/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 12 February 2020                                 */
/* Version : V01                                             */
/*************************************************************/
#ifndef  TEMP_PRIVATE_H
#define  TEMP_PRIVATE_H


  
          /*     OP_Code    */
		  
#define    TEMP_RAM_ACCESS               0x00
#define    TEMP_EEPROM_ACCESS            0x20
#define    TEMP_SLEEP_MODE               0xFF 
#define    TEMP_READ_FLAGS               0xF0

              /* EEPROM Addresses */

#define     TEMP_TO_MAX                 (TEMP_EEPROM_ACCESS | 0x00)                      //customer dependent object temperature range Maximum
#define     TEMP_TO_MIN                 (TEMP_EEPROM_ACCESS | 0x01)                       //customer dependent object temperature range Minimum
#define     TEMP_PWMCTRL                (TEMP_EEPROM_ACCESS | 0x02)                       // pulse width modulation output control 
#define     TEMP_TA_RANGE               (TEMP_EEPROM_ACCESS | 0x03)                      // customer dependent ambient temperature range
#define     TEMP_ECC                    (TEMP_EEPROM_ACCESS | 0x04)                       // Emissivity correction coefficient
#define     TEMP_CONFIG_REGISTER1       (TEMP_EEPROM_ACCESS | 0x05) 
#define     TEMP_SMBUS_ADDRESS          (TEMP_EEPROM_ACCESS | 0x0E)
#define     TEMP_ID1                    (TEMP_EEPROM_ACCESS | 0x1C)
#define     TEMP_ID2                    (TEMP_EEPROM_ACCESS | 0x1D)
#define     TEMP_ID3                    (TEMP_EEPROM_ACCESS | 0x1E)
#define     TEMP_ID4                    (TEMP_EEPROM_ACCESS | 0x1F)


           /*   RAM Addresses   */
		   
#define    TEMP_RAW1                    (TEMP_RAM_ACCESS|0x04)
#define    TEMP_RAW2                    (TEMP_RAM_ACCESS|0x05) 
#define    TEMP_TA                      (TEMP_RAM_ACCESS|0x06)  
#define    TEMP_TO_1                    (TEMP_RAM_ACCESS|0x07) 
#define    TEMP_TO_2                    (TEMP_RAM_ACCESS|0x08)

        
            /* ConfigRegister1 (IN EEPROM) control bits */
#define    TEMP_IIR_Coeff                 0 
#define    TEMP_Ta_To                     4                 // 0 0 -(Ta , Tobj1) ,  0 1 - (Ta , Tobj2) , 1 0 - (Tobj2) , 1 1 - (Tobj1, Tobj2) 
#define    TEMP_Single_Dual_IR            6                 // 0- Single IR sensor & 1- Dual IR sensor
#define    TEMP_FIR_Coeff                 8                 

            /* PWM Control   (In EEPROM) control bits   */
			
#define    TEMP_PWM_EXTENDED_SINGEL                  0
#define    TEMP_PWM_ENABLED_DISABLED                 1  
#define    TEMP_SDA_OD_PP                            2
#define    TEMP_PWM_OR_TR_SELECTED                   3
#define    TEMP_PWM_REPETITION                       4
#define    TEMP_PWM_PERIOD                           9


               /*  Read EEPROM Flags */
					  
#define     TEMP_DATA_INIT                        0x10                      // POR initialization routine is still ongoing. Low active 
#define     TEMP_DATA_EE_DEAD                     0x20                     // EEPROM double error has occured. High active
#define     TEMP_DATA_EEBUSY                      0x80                     //  the previous write/erase EEPROM access is still in progress.High active 

         /* FLAGS/ERRORS   */
	
#define    TEMP_READ_WRITE_ERROR                 0 
//#define    TEMP_Wrong_Data                   0x20


#define     Sensor_Address                     0x5A
#define     TEMP_POLYNOMIAL                    0x7


#endif




