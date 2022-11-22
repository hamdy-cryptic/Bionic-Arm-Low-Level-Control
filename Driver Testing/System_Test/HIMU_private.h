/*********************************************************/
/*Author    : youstina                                   */
/*version   : v01                                        */
/*date      : 3 FEB 2021                                 */
/*********************************************************/

#ifndef   HIMU_PRIVATE_H
#define  HIMU_PRIVATE_H


#define          WHO_AM_I_REG           0x75
#define          WHO_AM_I_REG_VAL    0x68

/***** FOR CONFIGURATION REGISTERS *****/
#define          SMPLRT_DIV                 0x19
#define          PWR_MGMT_1              0x6B
#define          CONFIG                       0x1A
#define          GYRO_CONFIG             0x1B
#define          ACCEL_CONFIG            0x1C
#define          INT_ENABLE                 0x38
#define          USER_CTRL                  0x6A


/***** FOR OUTPUT REGISTERS *****/
#define         ACCEL_XOUT_H            0x3B
#define         ACCEL_XOUT_L            0x3C
#define         ACCEL_YOUT_H            0x3D
#define         ACCEL_YOUT_L             0x3E
#define         ACCEL_ZOUT_H            0x3F
#define         ACCEL_ZOUT_L             0x40
#define         TEMP_OUT_H                0x41
#define         TEMP_OUT_L                0x42
#define         GYRO_XOUT_H             0x43
#define         GYRO_XOUT_L              0x44
#define         GYRO_YOUT_H             0x45
#define         GYRO_YOUT_L              0x46
#define         GYRO_ZOUT_H             0x47
#define         GYRO_ZOUT_L              0x48


/***** FOR ACCEL OFFSET REGISTERS *****/
#define      XA_OFFS_H                      0x06
#define      XA_OFFS_L_TC                 0x07
#define      YA_OFFS_H                      0x08
#define      YA_OFFS_L_TC                 0x09
#define      ZA_OFFS_H                     0x0A
#define      ZA_OFFS_L_TC                0x0B


/***** FOR GYRO OFFSET REGISTERS *****/
#define     XG_OFFS_USRH              0x13
#define     XG_OFFS_USRL               0x14
#define     YG_OFFS_USRH              0x15
#define     YG_OFFS_USRL               0x16
#define     ZG_OFFS_USRH              0x17
#define     ZG_OFFS_USRL               0x18


/***** FIFO REGISTERS ******/

#define          MPU6050_RA_FIFO_COUNTH      0x72
#define          MPU6050_RA_FIFO_COUNTL       0x73

#define          MPU6050_RA_FIFO_R_W              0x74

/****** STATUS REGISTERS ********/
#define          INTERRUPT_STATUS                    0x3A

/****** stastus register bits ********/
#define          DMP_INT                               0x02
#define          FIFO_OVERFLOW_INT             0x10
#define          FIFO_RST                  0x4


#define          DISABLED                 0x0
#define          ENABLED                  0x1

/*** user control bits ***/
#define          DMP_EN_BIT             0x80
#define          FIFO_EN_BIT             0x40
#define          FIFO_RST                  0x4


#endif

