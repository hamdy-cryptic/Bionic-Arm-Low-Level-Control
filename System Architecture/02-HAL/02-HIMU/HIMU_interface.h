/*********************************************************/
/*Author    : youstina                                   */
/*version   : v04                                        */
/*date      : 13 SEP 2021                                */
/*********************************************************/

#ifndef HIMU_INTERFACE_H
#define HIMU_INTERFACE_H


#include "STD_TYPES.h"


/* The least significant bit is determined by the value of the AD0 pin 
ADDRESS =  0x69 or 0x68   */

#define       SENSOR_ADDRESS         0x68       

/* configure the i2c used with IMU */
#define       HIMU_I2C               I2C1



/***** ALL I2C PINS ARE IN PORT B ******/
/*******I2C PINS******/
#define           SDA_PIN          7
#define           SCL_PIN          6


typedef struct {

    u16 Accel_X_RAW;
    u16 Accel_Y_RAW;
    u16 Accel_Z_RAW;
    double Ax;
    double Ay;
    double Az;

    u16 Gyro_X_RAW;
    u16 Gyro_Y_RAW;
    u16 Gyro_Z_RAW;
    double Gx;
    double Gy;
    double Gz;

    float Temperature;

    double KalmanAngleX;
    double KalmanAngleY;
   	double KalmanAngleZ;
} MPU6050_t;
 

/**** CONFIGURATION OF INCLUDED DRIVERS: USED BERFORE ANY IMU OTHER FUNCTION *****/
void HIMU_VoidPreInit (void);

/**** CONFIGURATION FOR IMU & OTHER I2C FUNCTIONS TO AVOID ERRORS **********/
void HIMU_VoidInit (void);

/**** TO READ THE WHOLE DATA; GYRO, ACCEL, TEMP ****/
void MPU6050_Read_All(MPU6050_t *DataStruct);




#endif

