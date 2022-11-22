/*********************************************************/
/*Author    : youstina                                   */
/*version   : v01                                        */
/*date      : 20 MAR 2021                                */
/*********************************************************/

   #include    "BIT_MATH.h"
   #include    "STD_TYPES.h"


   #include    "RCC_interface.h"
   #include    "GPIO_interface.h"
	 
   #include    "NVIC_interface.h"
	 #include    "EXTI_interface.h"
	 
	 
   #include    "MDMA_interface.h"


   #include    "MI2C_interface.h"
   #include    "MI2C_private.h"
   #include    "MI2C_config.h"


   #include    "HIMU_interface.h"
   #include    "HIMU_private.h"
   #include    "HIMU_config.h"
	 
	 #include <math.h>

#define     M_PI     3.1416
/* for configurations */
u8 volatile RECIEVER[1];
u8 volatile INT_STATUS[1] ;
u8 volatile SAMPLE_RATE[2]={SMPLRT_DIV, SMPL_RATE_DIV};
u8 volatile POWER_MANG_1[2]={PWR_MGMT_1,CLOCK_SRC};
u8 volatile GYROSCOPE_CONFIG[2]={GYRO_CONFIG,((GFS_SEL)<<3)};
u8 volatile CONFIGURE[2]={CONFIG, DLPF_CFG};
u8 volatile ACCELEROMETER_CONFIG[2]={ACCEL_CONFIG,((AFS_SEL)<<3)};
u8 volatile INTERRUPT_CONFIG[2]={INT_ENABLE,(((I2C_MST_INT)<<3)|((FIFO_OVER_FLOW_INT)<4)|(DATA_RDY_INT))};
u8 volatile USER_FIFO_RESET [2]= {USER_CTRL,(DMP_EN_BIT | FIFO_EN_BIT | FIFO_RST)};


/* GYRO OFFSETS */
u8 volatile GYRO_X_OFFSET[3]= {XG_OFFS_USRH,(GYRO_X_OFFSET_CONFIG>>8),GYRO_X_OFFSET_CONFIG};
u8 volatile GYRO_Y_OFFSET[3]= {YG_OFFS_USRH,(GYRO_Y_OFFSET_CONFIG>>8),GYRO_Y_OFFSET_CONFIG};
u8 volatile GYRO_Z_OFFSET[3]= {ZG_OFFS_USRH,(GYRO_Z_OFFSET_CONFIG>>8),GYRO_Z_OFFSET_CONFIG};



/* ACCEL OFFSETS */
u8 volatile ACCEL_X_OFFSET[3]= {XA_OFFS_H,(ACCEL_X_OFFSET_CONFIG>>8),ACCEL_X_OFFSET_CONFIG};
u8 volatile ACCEL_Y_OFFSET[3]= {YA_OFFS_H,(ACCEL_Y_OFFSET_CONFIG>>8),ACCEL_Y_OFFSET_CONFIG};
u8 volatile ACCEL_Z_OFFSET[3]= {ZA_OFFS_H,(ACCEL_Z_OFFSET_CONFIG>>8),ACCEL_Z_OFFSET_CONFIG};




//u8 ACCEL_X_OUT[2]; u16 ACC_X_RAW =((ACCEL_X_OUT[0]<<8) |(ACCEL_X_OUT[1])); u16 ACC_X = (ACC_X_RAW*ACC_SENSITIVITY);
//u8 ACCEL_Y_OUT[2]; u16 ACC_Y_RAW =((ACCEL_Y_OUT[0]<<8) |(ACCEL_Y_OUT[1])); u16 ACC_Y = (ACC_Y_RAW*ACC_SENSITIVITY);
//u8 ACCEL_Z_OUT[2]; u16 ACC_Z_RAW =((ACCEL_Z_OUT[0]<<8) |(ACCEL_Z_OUT[1])); u16 ACC_Z = (ACC_Z_RAW*ACC_SENSITIVITY);

//u8 GYRO_X_OUT[2]; u16 GYR_X_RAW = ((GYRO_X_OUT[0]<<8) |(GYRO_X_OUT[1])); u16 GYR_X = (GYR_X_RAW*GYR_SENSITIVITY);
//u8 GYRO_Y_OUT[2]; u16 GYR_Y_RAW = ((GYRO_Y_OUT[0]<<8) |(GYRO_Y_OUT[1])); u16 GYR_Y = (GYR_Y_RAW*GYR_SENSITIVITY);
//u8 GYRO_Z_OUT[2]; u16 GYR_Z_RAW = ((GYRO_Z_OUT[0]<<8) |(GYRO_Z_OUT[1])); u16 GYR_Z = (GYR_Z_RAW*GYR_SENSITIVITY);

//volatile u8 TEMP_OUT[2]; u16 TEMP = (((TEMP_OUT[0])<<8) |((TEMP_OUT[1])));


u8 volatile FIFO[2];      
//u8 FIFO_BUFFER[1];

u8 volatile PACKET_SIZE = 42 ;
u8 volatile fifoBuffer[42];
u8 volatile Quaternion[4];
u16 volatile GRAVITY[4];
u16 volatile ypr[3]; 
volatile u8 IMU_INTERRUPT;

typedef volatile struct
{
	u16 volatile X;
	u16 volatile Y;
	u16 volatile Z;
}VECTOR;
	VECTOR V ; 
void CRITICAL_GPIO_IMU_Config(void)
{
  /* Enable port A and C clocks */
RCC_voidEnableClock ( RCC_AHB1 , RCC_GPIOA);
RCC_voidEnableClock ( RCC_AHB1 , RCC_GPIOC);
 
 /* Select Alternate function mode */
 /************** GPIO_PIN : SELECT PIN ********************/
GPIO_voidSetPinDirection(GPIOA ,  8 , GPIO_AF );
GPIO_voidSetPinDirection(GPIOC ,  9 , GPIO_AF );

  /* Select output type open drain */
GPIO_SET_PP_OD (GPIOA , 8 , GPIO_OUTPUT_OD );
GPIO_SET_PP_OD (GPIOC, 9, GPIO_OUTPUT_OD); 

  /* Select output speed very high */
SET_GPIO_SPEED( GPIOA , 8 ,GPIO_SPEED_HIGH );
SET_GPIO_SPEED( GPIOC , 9 ,GPIO_SPEED_HIGH );

  /* Select pull-up */
GPIO_SET_PU_PD (GPIOA , 8, GPIO_PU);
GPIO_SET_PU_PD (GPIOC , 9, GPIO_PU);

  /* Select AF4 (I2C) */
GPIO_Set_AF(GPIOA , 8 , 4 );
GPIO_Set_AF(GPIOC , 9 , 4 );

/***** there is extra config for the interrupt pin *******/

	/**		GPIO Direction	**/
	/*		A0 = input =====> PULL UP Resistor	*/
    GPIO_voidSetPinDirection(GPIOA ,  0 , GPIO_INPUT );
  /* Select pull-up */
    GPIO_SET_PU_PD (GPIOA , 0, GPIO_PU);
	MNVIC_voidEnableInterrupt(EXTI0);

}


void HIMU_VoidPreInit (void){   
/********* START I2C **********/
    CRITICAL_GPIO_IMU_Config();	
    MI2C_voidInit( I2C3 );
    MI2C_voidEnableDmaRequest(I2C3);
    MI2C_voidDmaLastTransfer(I2C3);

//DMA_1 , STREAM_2 (I2C3_RX)
    DMA_SetConfig( 1 , STREAM_2 , PERIPHERAL_TO_MEMORY , BYTE , BYTE , ACTIVATED , DEACTIVATED);
    DMA_VoidSelectChannel(1, STREAM_2 , CHANNEL3 );

    DMA_VoidInerruptEnable(1, STREAM_2 , TCIE );

//configure DMA_transmitter
   DMA_SetConfig(1 ,STREAM_4, MEMORY_TO_PERIPHERAL , BYTE , BYTE , ACTIVATED , DEACTIVATED);
   DMA_VoidSelectChannel(1, STREAM_4 , CHANNEL3 );

   DMA_VoidSetAddress(1, STREAM_2 , &(I2C_3->DR) , &RECIEVER , 1 );
   
/* I2C MASTER RECIEVER */

/* WRITE THE SENSOR ADDRESS IN DR */ 
    MI2C_voidMasterTransmitter_7bit(I2C3 , SENSOR_ADDRESS);

/* SPECIFY THE REGISTER ADDRESS TO READ */
    MI2C_voidSendRegisterAddress(I2C3 , ONE_BYTE  , WHO_AM_I_REG);

/* READ THE WHO_AM_I_REG VALUE */
    MI2C_voidMasterRead_7bit(I2C3 , SENSOR_ADDRESS );

    DMA_VoidDMAEnable(1, STREAM_2 );
		//RECIEVER[0]= I2C_3-> DR;

/*HERE THE INTERFACE IS READY TO TRANSFER DATA SO CLEAR THE FLAG */
    MI2C_voidGetReady(I2C3 );

    while( RECIEVER[0] != WHO_AM_I_REG_VAL){} //Do nothing if the value read is not as the expected 
  
/*stop i2c when the dma transfe complete flag is on */
    MDMA_VidSetCallBack_I2C3_RX( MI2C_voidI2c3_MasterRecieverFinishing);
}


void HIMU_VoidConfig(u8 *Copy_u8Array ){
	/* WRITE THE IMU SENSOR ADDRESS IN DR */ 
    MI2C_voidMasterTransmitter_7bit(I2C3 , SENSOR_ADDRESS);
    /* SPECIFY THE REGISTER ADDRESS TO WRITE IN IT */
	DMA_VoidSetAddress( 1, STREAM_4 , &(I2C_3->DR) , Copy_u8Array , 2 );
	DMA_VoidDMAEnable(1 , STREAM_4 );
	MI2C_voidGetReady(I2C3);
	MI2C_voidI2c3_MasterTransmitterFinishing();		
}


void HIMU_VoidInit (void){
 /**************** set configurations *********************/
/* SPECIFY THE SAMPLE_RATE_DIVISION REGISTER ADDRESS TO WRITE IN IT */
    HIMU_VoidConfig( SAMPLE_RATE );
	
/* SPECIFY THE POWER_MANG_1 REGISTER ADDRESS TO WRITE IN IT */
    HIMU_VoidConfig( POWER_MANG_1 );

/* SPECIFY THE GYROSCOPE_CONFIG REGISTER ADDRESS TO WRITE IN IT */
    HIMU_VoidConfig( GYROSCOPE_CONFIG );

    HIMU_VoidConfig( CONFIGURE );

    HIMU_VoidConfig( ACCELEROMETER_CONFIG );

    HIMU_VoidConfig( INTERRUPT_CONFIG );
}   



void HIMU_VoidGetResult(u8 Copy_U8Register, u8 Copy_U8Reciever){
   DMA_VoidSetAddress(1, STREAM_2 , &(I2C_3->DR) , Copy_U8Reciever , 2 );
	
/* WRITE THE SENSOR ADDRESS IN DR */ 
    MI2C_voidMasterTransmitter_7bit(I2C3 , SENSOR_ADDRESS);

/* SPECIFY THE REGISTER ADDRESS TO READ */
    MI2C_voidSendRegisterAddress(I2C3 , MORE_THAN_ONE_BYTE  , Copy_U8Register);

/* READ THE WHO_AM_I_REG VALUE */
    MI2C_voidMasterRead_7bit(I2C3 , SENSOR_ADDRESS );

    DMA_VoidDMAEnable(1, STREAM_2 ); 

/*HERE THE INTERFACE IS READY TO TRANSFER DATA SO CLEAR THE FLAG */
    MI2C_voidGetReady(I2C3 );

    MI2C_voidI2c3_MasterRecieverFinishing();
	
}
/*****ACCEL_X*****/
/*void HIMU_VoidGetAcc_XResult(){
	HIMU_VoidGetResult(ACCEL_XOUT_H, ACCEL_X_OUT );	
}

/*****ACCEL_Y*****/
/*void HIMU_VoidGetAcc_YResult(){
	HIMU_VoidGetResult(ACCEL_YOUT_H, ACCEL_Y_OUT );	
}
*/
/*****ACCEL_Z*****/
/*void HIMU_VoidGetAcc_ZResult(){
	HIMU_VoidGetResult(ACCEL_ZOUT_H, ACCEL_Z_OUT );	
}
*/
/*****GYROSCOPE_X*****/
/*void HIMU_VoidGetGyro_XResult(){
	HIMU_VoidGetResult(GYRO_XOUT_H, GYRO_X_OUT );	
}
*/
/*****GYROSCOPE_Y*****/
/*void HIMU_VoidGetGyro_YResult(){
	HIMU_VoidGetResult(GYRO_YOUT_H, GYRO_Y_OUT );	
}
*/
/*****GYROSCOPE_Z*****/
/*void HIMU_VoidGetGyro_ZResult(){
	HIMU_VoidGetResult(GYRO_ZOUT_H, GYRO_Z_OUT );	
}
*/
/*****TEMP_OUT*****/
/*void HIMU_VoidGetTemp_Result(){
	HIMU_VoidGetResult(TEMP_OUT_H, TEMP_OUT );	
}
*/

void HIMU_VoidOffset(u8 *Copy_u8Array ){
	/* WRITE THE IMU SENSOR ADDRESS IN DR */ 
    MI2C_voidMasterTransmitter_7bit(I2C3 , SENSOR_ADDRESS);
    /* SPECIFY THE REGISTER ADDRESS TO WRITE IN IT */
	DMA_VoidSetAddress( 1, STREAM_4 , &(I2C_3->DR) , Copy_u8Array , 2 );
	DMA_VoidDMAEnable(1 , STREAM_4 );
	MI2C_voidGetReady(I2C3);
	MI2C_voidI2c3_MasterTransmitterFinishing();		
}

/****** GYRO OFFSET ******/
void HIMU_VoidSetGyro_X_Offset(void){
	HIMU_VoidOffset(GYRO_X_OFFSET);
}

void HIMU_VoidSetGyro_Y_Offset(void){
	HIMU_VoidOffset(GYRO_Y_OFFSET);
}

void HIMU_VoidSetGyro_Z_Offset(void){
	HIMU_VoidOffset(GYRO_Z_OFFSET);
}


/****** ACCEL OFFSET ******/
void HIMU_VoidSetAccel_X_Offset(void){
	HIMU_VoidOffset(ACCEL_X_OFFSET);
}

void HIMU_VoidSetAccel_Y_Offset(void){
	HIMU_VoidOffset(ACCEL_Y_OFFSET);
}

void HIMU_VoidSetAccel_Z_Offset(void){
	HIMU_VoidOffset(ACCEL_Z_OFFSET);
}

u16 HIMU_U16GetFifoCount(void){
	HIMU_VoidGetResult(MPU6050_RA_FIFO_COUNTH, FIFO );	
	volatile u16 FIFO_COUNT =((FIFO[0]<<8) |(FIFO[1]));
	return FIFO_COUNT ;
}


u8 HIMU_U8GetStatus(void){
   DMA_VoidSetAddress(1, STREAM_2 , &(I2C_3->DR) , INT_STATUS , 1 );
	
/* WRITE THE SENSOR ADDRESS IN DR */ 
    MI2C_voidMasterTransmitter_7bit(I2C3 , SENSOR_ADDRESS);

/* SPECIFY THE REGISTER ADDRESS TO READ */
    MI2C_voidSendRegisterAddress(I2C3 , ONE_BYTE  , INTERRUPT_STATUS);

/* READ THE WHO_AM_I_REG VALUE */
    MI2C_voidMasterRead_7bit(I2C3 , SENSOR_ADDRESS );

    DMA_VoidDMAEnable(1, STREAM_2 ); 

/*HERE THE INTERFACE IS READY TO TRANSFER DATA SO CLEAR THE FLAG */
    MI2C_voidGetReady(I2C3 );

    MI2C_voidI2c3_MasterRecieverFinishing();
	
	return INT_STATUS[0] ;
}

/*
void HIMU_VoidGetFifoBuffer(void){
   DMA_VoidSetAddress(1, STREAM_2 , &(I2C_3->DR) , FIFO_BUFFER , 1 );
    MI2C_voidMasterTransmitter_7bit(I2C3 , SENSOR_ADDRESS);
    MI2C_voidSendRegisterAddress(I2C3 , ONE_BYTE  , MPU6050_RA_FIFO_R_W);
    MI2C_voidMasterRead_7bit(I2C3 , SENSOR_ADDRESS );
    DMA_VoidDMAEnable(1, STREAM_2 ); 
    MI2C_voidGetReady(I2C3 );
    MI2C_voidI2c3_MasterRecieverFinishing();	
}
*/

void HIMU_VoidInterrupt(void){
	IMU_INTERRUPT=1;
}

void HIMU_VoidGetFifoBuffer(void){
   DMA_VoidSetAddress(1, STREAM_2 , &(I2C_3->DR) , fifoBuffer , 42 );
    MI2C_voidMasterTransmitter_7bit(I2C3 , SENSOR_ADDRESS);
    MI2C_voidSendRegisterAddress(I2C3 , MORE_THAN_ONE_BYTE , MPU6050_RA_FIFO_R_W);
    MI2C_voidMasterRead_7bit(I2C3 , SENSOR_ADDRESS );
    DMA_VoidDMAEnable(1, STREAM_2 ); 
    MI2C_voidGetReady(I2C3 );
    MI2C_voidI2c3_MasterRecieverFinishing();	
}


void HIMU_VoidDmpGetQuaternion(u16 *data, u8* packet) {
    // TODO: accommodate different arrangements of sent data (ONLY default supported now)
  //  if (packet == 0) packet = dmpPacketBuffer;
    data[0] = ((packet[0] << 8) | packet[1]);
    data[1] = ((packet[4] << 8) | packet[5]);
    data[2] = ((packet[8] << 8) | packet[9]);
    data[3] = ((packet[12] << 8) | packet[13]);
}


void HIMU_VoidDmpGetQuaternion2(u16 *q, u8* packet) {
    // TODO: accommodate different arrangements of sent data (ONLY default supported now)
    u16 qI[4];
    HIMU_VoidDmpGetQuaternion(qI, packet);
    	q[0] = (float)qI[0] / 16384.0f;
        q[1] = (float)qI[1] / 16384.0f;
        q[2] = (float)qI[2] / 16384.0f;
        q[3] = (float)qI[3] / 16384.0f;
}


void HIMU_VoidDmpGetGravity(VECTOR *v, u8 *q) {
    v -> X = 2 * (q[1]*q[3] - q[0]*q[2]);
    v -> Y = 2 * (q[0]*q[1] + q[2]*q[3]);
    v -> Z = q[0]*q[0] - q[1]*q[1] - q[2]*q[2] + q[3]*q[3];
}


void HIMU_VoidDmpGetYawPitchRoll(u16 *data, u8 *q, VECTOR *gravity) {
    // yaw: (about Z axis)
    data[0] = atan2(2*q [1]*q [2] - 2*q [0]*q [3], 2*q [0]*q [0] + 2*q [1]*q [1] - 1);
    // pitch: (nose up/down, about Y axis)
	//double VAL_1 = gravity ->Y *gravity ->Y + gravity ->Z *gravity ->Z ; 
	//double sqrt_p = squareRoot(VAL_1) ;
    data[1] = atan(gravity ->X / sqrt(gravity ->Y *gravity ->Y + gravity ->Z *gravity ->Z ));
    // roll: (tilt left/right, about X axis)
    data[2] = atan(gravity ->Y / sqrt(gravity ->X *gravity ->X + gravity ->Z *gravity ->Z ));
}


void HIMU_VoidDmpConfig_ResetFifo(void){
    HIMU_VoidConfig(USER_FIFO_RESET);
}



void HIMU_VoidSetUp(void){
	
	CRITICAL_GPIO_IMU_Config();
	HIMU_VoidPreInit ();
	HIMU_VoidInit ();
	MEXTI_voidSetCallBack(HIMU_VoidInterrupt);

	
	HIMU_VoidSetGyro_X_Offset();
	HIMU_VoidSetGyro_Y_Offset();
	HIMU_VoidSetGyro_Z_Offset();
	
	HIMU_VoidSetAccel_X_Offset();
	HIMU_VoidSetAccel_Y_Offset();
	HIMU_VoidSetAccel_Z_Offset();
	
	HIMU_VoidDmpConfig_ResetFifo();
}


volatile u16 yaw ;
volatile u16 roll ;
volatile u16 pitch ;



void HIMU_VoidReading(void){ 
    u8 IMU_INT_STATUS;
	u16 IMU_FIFO_COUNT;
	IMU_FIFO_COUNT = HIMU_U16GetFifoCount();
    // wait for MPU interrupt or extra packet(s) available
	while(IMU_INTERRUPT==1 || ( IMU_FIFO_COUNT >= PACKET_SIZE ) ){
		IMU_INTERRUPT =0 ;
		IMU_INT_STATUS = HIMU_U8GetStatus(); 
		IMU_FIFO_COUNT = HIMU_U16GetFifoCount();
		if (IMU_FIFO_COUNT==1024 || (IMU_INT_STATUS & FIFO_OVERFLOW_INT)){
			HIMU_VoidDmpConfig_ResetFifo();
		}
		else if (IMU_INT_STATUS & DMP_INT){
			while (IMU_FIFO_COUNT < PACKET_SIZE)
			{
				IMU_FIFO_COUNT = HIMU_U16GetFifoCount();
			}
        // read a packet from FIFO
		HIMU_VoidGetFifoBuffer();	
        IMU_FIFO_COUNT -= PACKET_SIZE ;
        HIMU_VoidDmpGetQuaternion2( Quaternion, fifoBuffer ) ;
		HIMU_VoidDmpGetGravity( &V , Quaternion) ;
		HIMU_VoidDmpGetYawPitchRoll( ypr, Quaternion, &V ) ;
        // store roll, pitch, yaw
        yaw = ypr[0] * 180/M_PI;
        roll = ypr[1] * 180/M_PI;
        pitch = ypr[2] * 180/M_PI;                       
		
		}
		
	}  	
}


u16 HIMU_U16GetYaw(void){
	return yaw ;
}


u16 HIMU_U16GetPitch(void){
	return pitch ;
}


u16 HIMU_U16GetRoll(void){
	return roll ;
}