/*********************************************************/
/*Author    : youstina                                   */
/*version   : v01                                        */
/*date      : 3 FEB 2021                                 */
/*********************************************************/

#ifndef   HIMU_CONFIG_H
#define  HIMU_CONFIG_H


/* The least significant bit is determined by the value of the AD0 pin 
ADDRESS =  0x69 or 0x68   */

#define          SENSOR_ADDRESS       0x68       

/* configure the i2c used with IMU */
#define          HIMU_I2C                     I2C3


/* OPTIONS FOR CLOCK_SRC : */

#define       INT_8MHZ_OSC           0x0                //Internal 8MHz oscillator 
#define       X_AXIS_GYR_REF          0x1                //PLL with X axis gyroscope reference
#define       Y_AXIS_GYR_REF          0x2                //PLL with Y axis gyroscope reference
#define       Z_AXIS_GYR_REF          0x3               //PLL with Z axis gyroscope reference
#define       EXT_32KHZ_REF           0x4               //PLL with external 32.768kHz reference
#define       EXT_19MHZ_REF          0x5               //PLL with external 19.2MHz reference
#define       STOP_CLOCK               0x7               //Stops the clock and keeps the timing generator in reset


#define         CLOCK_SRC              X_AXIS_GYR_REF      


/* OPTIONS FOR DIGITAL LOW PASS FILTER 0:7 
0 FOR The highest bandwidth frequency  */
#define          DLPF_CFG                0x0                         


/* OPTIONS FOR accelerometer full-scale : */

#define       _2GRAVITY             0
#define       _4GRAVITY             1
#define       _8GRAVITY             2
#define       _16GRAVITY            3


#define         AFS_SEL           _2GRAVITY   



/* OPTIONS FOR gyroscopes full-scale : */

#define       _250_DEG_PER_SEC              0
#define       _500_DEG_PER_SEC              1
#define       _1000_DEG_PER_SEC             2
#define       _2000_DEG_PER_SEC            3


#define         GFS_SEL           _250_DEG_PER_SEC

/* INTERRUPT SOURCES */
#define    FIFO_OVER_FLOW_INT            ENABLED
#define    I2C_MST_INT                          DISABLED
#define    DATA_RDY_INT                       DISABLED



/* CONFIGURE SAMPLE RATE */
/* Sample Rate = Gyroscope Output Rate / (1 + SMPLRT_DIV) */
/* Gyroscope Output Rate = 8kHz */
/*OPTIONS : 0x00 -> 0xFF*/
#define         SMPL_RATE_DIV       0x07

/* OFFSET OF GYRO READINGS */
#define          GYRO_X_OFFSET_CONFIG      0xC      //12
#define          GYRO_Y_OFFSET_CONFIG      0xC      //12
#define          GYRO_Z_OFFSET_CONFIG      0x13     //19


/* OFFSET OF ACCEL READINGS */
#define          ACCEL_X_OFFSET_CONFIG      -4020
#define          ACCEL_Y_OFFSET_CONFIG      -1176
#define          ACCEL_Z_OFFSET_CONFIG      2613


#endif
