/*********************************************************/
/*Author    : youstina                                   */
/*version   : v04                                        */
/*date      : 13 SEP 2021                                */
/*********************************************************/

   #include    "BIT_MATH.h"
   #include    "STD_TYPES.h"
   #include    "math.h"
   #include <stdlib.h>

   #include    "RCC_interface.h"
   #include    "GPIO_interface.h"	 
   #include    "DMA_interface.h"
   #include    "MI2C_interface.h"
   #include    "MI2C_private.h"
   #include    "MI2C_config.h"

   #include "STK_interface.h"


	 

   #include    "HIMU_private.h"
   #include    "HIMU_config.h"
   #include    "HIMU_interface.h"


volatile u8 POWER_MANG_1[2]={PWR_MGMT_1,0};
volatile u8 SAMPLE_RATE[2]={SMPLRT_DIV, SMPL_RATE_DIV};
volatile u8 ACCELEROMETER_CONFIG[2]={ACCEL_CONFIG,((AFS_SEL)<<3)};
volatile u8 GYROSCOPE_CONFIG_1[2]={GYRO_CONFIG,((0)<<3)};


#define     M_PI     3.1416
#define    RAD_TO_DEG        180/M_PI



// Kalman structure
typedef struct {
    double Q_angle;
    double Q_bias;
    double R_measure;
    double angle;
    double bias;
    double P[2][2];
} Kalman_t;


Kalman_t KalmanX = {
        .Q_angle = 0.001f,
        .Q_bias = 0.003f,
        .R_measure = 0.03f
};

Kalman_t KalmanY = {
        .Q_angle = 0.001f,
        .Q_bias = 0.003f,
        .R_measure = 0.03f,
};


const double Accel_Z_corrector = 14418.0;
volatile u8 CONFIRM[1];

/***** imported FROM GPIO DRIVER ******/

#define          GPIOB_BASE_ADDRESS                0x40010C00
#define           GPIOB_CRL                                  *((u32 *)(GPIOB_BASE_ADDRESS + 0x00))

void CRITICAL_GPIO_IMU_Config(void)
{
  /* Enable port A and C clocks */
RCC_voidEnableClock ( RCC_APB2 , RCC_GPIOB); //PORT B CLOCK
RCC_voidEnableClock ( RCC_APB2 , 0);// ALTERNATIVE FUNCTIONS CLOCK

 /* Select Alternate function mode */
 /************** GPIO_PIN : SELECT PIN ********************/
GPIO_voidSetPinDirection(GPIOB ,  SCL_PIN , GPIO_AF_OD );
GPIO_voidSetPinDirection(GPIOB ,  SDA_PIN , GPIO_AF_OD );

  /* Select output type open drain */
GPIO_SET_PP_OD (GPIOB , SCL_PIN , GPIO_OUTPUT_OD );
GPIO_SET_PP_OD (GPIOB, SDA_PIN, GPIO_OUTPUT_OD); 

  /* Select output speed very high */
SET_GPIO_SPEED( GPIOB , SCL_PIN ,3 );
SET_GPIO_SPEED( GPIOB , SDA_PIN ,3 );

  /* Select pull-up */
GPIO_SET_PU_PD (GPIOB , SCL_PIN, GPIO_PU);
GPIO_SET_PU_PD (GPIOB , SDA_PIN, GPIO_PU);

/***** Alternate function output Open-drain WITH max speed 50 MHz *****/
  GPIOB_CRL |=(0xFF000000); 
  /* Select AF4 (I2C) */
//GPIO_Set_AF(GPIOB , 6 , 4 );
//GPIO_Set_AF(GPIOB , 7 , 4 );
}


void HIMU_VoidPreInit (void){   
/********* START I2C **********/
    CRITICAL_GPIO_IMU_Config();	
    MI2C_voidInit( I2C1 );
    MI2C_voidEnableDmaRequest(I2C1);
    MI2C_voidDmaLastTransfer(I2C1);

/********* NEED CHECK ***********/
//DMA_1 , CHANNEL7 (I2C1_RX)
    DMA_SetConfig( 1 , CHANNEL7 , PERIPHERAL_TO_MEMORY , BYTE , BYTE , ACTIVATED , DEACTIVATED);
 
    DMA_VoidInerruptEnable(1, CHANNEL7 , TCIE );

//configure DMA_transmitter
   DMA_SetConfig(1 ,CHANNEL6, MEMORY_TO_PERIPHERAL , BYTE , BYTE , ACTIVATED , DEACTIVATED);
  

   DMA_VoidSetAddress(1, CHANNEL7 , &(I2C_1->DR) , &CONFIRM , 1 );
   
/* I2C MASTER RECIEVER */

/* WRITE THE SENSOR ADDRESS IN DR */ 
    MI2C_voidMasterTransmitter_7bit(I2C1 , SENSOR_ADDRESS);

/* SPECIFY THE REGISTER ADDRESS TO READ */
    MI2C_voidSendRegisterAddress(I2C1 , ONE_BYTE  , WHO_AM_I_REG);

/* READ THE WHO_AM_I_REG VALUE */
    MI2C_voidMasterRead_7bit(I2C1 , SENSOR_ADDRESS );

    DMA_VoidDMAEnable(1, CHANNEL7 );

/*HERE THE INTERFACE IS READY TO TRANSFER DATA SO CLEAR THE FLAG */
    MI2C_voidGetReady(I2C1 );

    while( WHO_AM_I_REG_VAL != CONFIRM[0]){} //Do nothing if the value read is not as the expected 
  
  /****** NEED CHECK *******/
/*stop i2c when the dma transfe complete flag is on */
 //   MDMA_VidSetCallBack_I2C1_RX( MI2C_voidI2c1_MasterRecieverFinishing);
MI2C_voidI2c1_MasterRecieverFinishing;
			
}


// SPECIFY THE REGISTER ADDRESS TO WRITE IN IT 
void HIMU_VoidConfig(u8 * Copy_u8Array ){
    MI2C_voidMasterTransmitter_7bit(I2C1 , SENSOR_ADDRESS);
    DMA_VoidSetAddress( 1, CHANNEL6 , &(I2C_1->DR) , Copy_u8Array , 2 );
	DMA_VoidDMAEnable(1 , CHANNEL6 );
	MI2C_voidGetReady(I2C1);
	MI2C_voidI2c1_MasterTransmitterFinishing();		
}
	
	
void HIMU_VoidInit (void){
	/**** STEPS TO AVOID ERRORS OF I2C *****/
	MI2C_voidBusy();
  	MI2C_Busy();
	MI2C_voidReInit();
 /**************** set configurations *********************/
   
/* SPECIFY THE POWER_MANG_1 REGISTER ADDRESS TO WRITE IN IT SLEEP_MODE_DISABLED */
    HIMU_VoidConfig( POWER_MANG_1 );
	
// Set DATA RATE of 1KHz by writing SMPLRT_DIV register
    HIMU_VoidConfig( SAMPLE_RATE );
				
// Set accelerometer configuration in ACCEL_CONFIG Register
    HIMU_VoidConfig( ACCELEROMETER_CONFIG );

/* SPECIFY THE GYROSCOPE_CONFIG REGISTER ADDRESS TO WRITE IN IT GYRO_FULL_SCALE */
    HIMU_VoidConfig( GYROSCOPE_CONFIG_1 );
}   


	
double Kalman_getAngle(Kalman_t *Kalman, double newAngle, double newRate, double dt) {
    double rate = newRate - Kalman->bias;
    Kalman->angle += dt * rate;

    Kalman->P[0][0] += dt * (dt * Kalman->P[1][1] - Kalman->P[0][1] - Kalman->P[1][0] + Kalman->Q_angle);
    Kalman->P[0][1] -= dt * Kalman->P[1][1];
    Kalman->P[1][0] -= dt * Kalman->P[1][1];
    Kalman->P[1][1] += Kalman->Q_bias * dt;

    double S = Kalman->P[0][0] + Kalman->R_measure;
    double K[2];
    K[0] = Kalman->P[0][0] / S;
    K[1] = Kalman->P[1][0] / S;

    double y = newAngle - Kalman->angle;
    Kalman->angle += K[0] * y;
    Kalman->bias += K[1] * y;

    double P00_temp = Kalman->P[0][0];
    double P01_temp = Kalman->P[0][1];

    Kalman->P[0][0] -= K[0] * P00_temp;
    Kalman->P[0][1] -= K[0] * P01_temp;
    Kalman->P[1][0] -= K[1] * P00_temp;
    Kalman->P[1][1] -= K[1] * P01_temp;

    return Kalman->angle;
};

void nothing (){}


    void MPU6050_Read_All(MPU6050_t *DataStruct) {
        u8 Rec_Data[14];
	u8 G_X[2];u8 G_Y[2];u8 G_Z[2];
	u8 A_X[2];u8 A_Y[2];u8 A_Z[2];
    u8 T[2];  
    u16 temp;
	//MSTK_void_SysTick_Initialize ();
   MSTK_voidInit();//ASSAF
    
	// Read 14 BYTES of data starting from ACCEL_XOUT_H register

		DMA_VoidSetAddress(1, CHANNEL7 , &(I2C_1->DR) , Rec_Data , 14 );
    MI2C_voidMasterTransmitter_7bit(I2C1 , SENSOR_ADDRESS);
    MI2C_voidSendRegisterAddress(I2C1 , MORE_THAN_ONE_BYTE  , ACCEL_XOUT_H);
    MI2C_voidMasterRead_7bit(I2C1 , SENSOR_ADDRESS );
    DMA_VoidDMAEnable(1, CHANNEL7 ); 
    MI2C_voidGetReady(I2C1 );
    MI2C_voidI2c1_MasterRecieverFinishing();
    

    DataStruct->Accel_X_RAW = (u16) (Rec_Data[0] << 8 | Rec_Data[1]);
    DataStruct->Accel_Y_RAW = (u16) (Rec_Data[2] << 8 | Rec_Data[3]);
    DataStruct->Accel_Z_RAW = (u16) (Rec_Data[4] << 8 | Rec_Data[5]);
    temp = (u16) (Rec_Data[6] << 8 | Rec_Data[7]);
    DataStruct->Gyro_X_RAW = (u16) (Rec_Data[8] << 8 | Rec_Data[9]);
    DataStruct->Gyro_Y_RAW = (u16) (Rec_Data[10] << 8 | Rec_Data[11]);
    DataStruct->Gyro_Z_RAW = (u16) (Rec_Data[12] << 8 | Rec_Data[13]);

    DataStruct->Ax = DataStruct->Accel_X_RAW / 16384.0;
    DataStruct->Ay = DataStruct->Accel_Y_RAW / 16384.0;
    DataStruct->Az = DataStruct->Accel_Z_RAW / Accel_Z_corrector;
    DataStruct->Temperature = (float) ((u16) temp / (float) 340.0 + (float) 36.53);
    DataStruct->Gx = DataStruct->Gyro_X_RAW / 131.0;
    DataStruct->Gy = DataStruct->Gyro_Y_RAW / 131.0;
    DataStruct->Gz = DataStruct->Gyro_Z_RAW / 131.0;


    // Kalman angle solve
	
	//MSTK_uint32_SysTick_STimer (1000, nothing);
	volatile double dt = (double)MSTK_u32GetElapsedTime();//ASSAF		
		dt =(dt/((8*1000000)/8))*1000;
		//dt =dt/1000;

	MSTK_voidSetIntervalSingle  ( 1000000, nothing );//ASSAF

// double dt = ((double)MSTK_uint32_SysTick_ElapsedTime()/ 1000);
/*double dt ; dt = 0.007;	*/
	double roll;
    double roll_sqrt = sqrt(fabs(
            DataStruct->Accel_X_RAW * DataStruct->Accel_X_RAW + DataStruct->Accel_Z_RAW * DataStruct->Accel_Z_RAW));
    if (roll_sqrt != 0.0) {
        roll = atan(DataStruct->Accel_Y_RAW / roll_sqrt) * RAD_TO_DEG;
    } else {
        roll = 0.0;
    }
    double pitch = atan2(-DataStruct->Accel_X_RAW, DataStruct->Accel_Z_RAW) * RAD_TO_DEG;
    if ((pitch < -90 && DataStruct->KalmanAngleY > 90) || (pitch > 90 && DataStruct->KalmanAngleY < -90)) {
        KalmanY.angle = pitch;
        DataStruct->KalmanAngleY = pitch;
    } else {
			 DataStruct->KalmanAngleY = Kalman_getAngle(&KalmanY, pitch, DataStruct->Gy, dt);
    }
    if (fabs(DataStruct->KalmanAngleY) > 90)
        DataStruct->Gx = -DataStruct->Gx;
        DataStruct->KalmanAngleX = Kalman_getAngle(&KalmanX, roll, DataStruct->Gy, dt);
		
		double yaw;
    double yaw_sqrt = sqrt(fabs(
            DataStruct->Accel_X_RAW * DataStruct->Accel_X_RAW + DataStruct->Accel_Z_RAW * DataStruct->Accel_Z_RAW));
    if (yaw_sqrt > 0.0) {
        yaw = atan(DataStruct->Accel_Z_RAW / yaw_sqrt) * RAD_TO_DEG;
    } else {
        yaw = 0.0;
    }
		DataStruct->KalmanAngleZ = yaw ;
}
