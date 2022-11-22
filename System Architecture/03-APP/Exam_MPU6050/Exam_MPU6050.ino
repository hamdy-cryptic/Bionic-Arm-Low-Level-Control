
#include "mpu.h"


MPU6050 mpu;
#include <SoftwareSerial.h>
SoftwareSerial BTSerial (2,3);


#define GREEN_LED  0
#define BLUE_LED   7
#define RED_LED    8

// Define FSR pin:
#define fsrpin1 A0
#define fsrpin2 A1
#define fsrpin3 A2
#define fsrpin4 A3
//Define variable to store sensor readings:
int fsrreading_1; //Variable to store FSR1 value
int fsrreading_2; //Variable to store FSR2 value
int fsrreading_3; //Variable to store FSR3 value
int fsrreading_4; //Variable to store FSR4 value



void setup() 
{
  Serial.begin(9600);
  
    pinMode(GREEN_LED , OUTPUT);
    pinMode(BLUE_LED , OUTPUT);   
    pinMode(RED_LED , OUTPUT); 
        
  dmpDataReady();
  dmp_setup();
}

void loop() 
{
  static uint32_t tTime[4];
 
  
  dmp_loop();
      
  if( (millis() - tTime[2]) >= 50 )
  {
    tTime[2] = millis();
    Serial.print("roll : ");
    Serial.print(String(roll, 2));Serial.print('\n');
 //   Serial.print("  pitch : ");
 //   Serial.print(String(pitch, 2));
//    Serial.print("  yaw : ");
//    Serial.println(String(yaw, 2));
  }

  // Read the FSR pin and store the output as fsrreading:
  fsrreading_1 = analogRead(fsrpin1);
  fsrreading_2 = analogRead(fsrpin2);
  fsrreading_3 = analogRead(fsrpin3);
  fsrreading_4 = analogRead(fsrpin4);
  Serial.print("fsrreading_1 : ");
    Serial.print(String(fsrreading_1, 2));Serial.print('\n');
    
    Serial.print("fsrreading_2 : ");
    Serial.print(String(fsrreading_2, 2));Serial.print('\n');
    
    Serial.print("fsrreading_3 : ");
    Serial.print(String(fsrreading_3, 2));Serial.print('\n');
    
    Serial.print("fsrreading_4 : ");
    Serial.print(String(fsrreading_4, 2));Serial.print('\n');
    //Serial.flush();//Waits for the transmission of outgoing serial data to complete.
   if(roll > 60){Serial.print( 16 , BIN);Serial.print('\n');digitalWrite(RED_LED, HIGH); }
   else if(roll < -30){Serial.print( 32 , BIN);Serial.print('\n');digitalWrite(BLUE_LED, HIGH); }
   
   //arranged in descending order according to priority
   else if(fsrreading_1 > 400){Serial.print( 1 , BIN);Serial.print('\n');}
   else if(fsrreading_2 > 400){Serial.print( 2 , BIN);Serial.print('\n');}
   else if(fsrreading_3 > 400){Serial.print( 4 , BIN);Serial.print('\n');}
   else if(fsrreading_4 > 400){Serial.print( 8 , BIN);Serial.print('\n');} 
 //  else if(pitch > 60){Serial.print( 16 , BIN);digitalWrite(GREEN_LED, HIGH); delay(500);}
 //  else if(pitch < -30){Serial.print( 32 , BIN);digitalWrite(BLUE_LED, HIGH); delay(500);} 
  //else {Serial.print( 0 , BIN);digitalWrite(RED_LED, HIGH); delay(500);}
 else {Serial.print( 0 , BIN);Serial.print('\n');digitalWrite(GREEN_LED, HIGH);}
 //  delay(2000);//delay of 2 seconds
}





////////////////////////////////////////
//        IMU
/////////////////////////////////////////
/*---------------------------------------------------------------------------
     TITLE   : dmpDataReady
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
#define INTERRUPT_PIN 4
void dmpDataReady() {
    mpuInterrupt = true;
}

/*---------------------------------------------------------------------------
     TITLE   : dmp_setup
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
void dmp_setup() {
  Wire.begin();
 
    // initialize device
    Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();
    pinMode(INTERRUPT_PIN, INPUT);

    // verify connection
    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    // wait for ready
    Serial.println(F("\nSend any character to begin DMP programming and demo: "));
  //  while (Serial.available() && Serial.read()); // empty buffer
  //  while (!Serial.available());                 // wait for data
  //  while (Serial.available() && Serial.read()); // empty buffer again

    // load and configure the DMP
    Serial.println(F("Initializing DMP..."));
    devStatus = mpu.dmpInitialize();

    // supply your own gyro offsets here, scaled for min sensitivity
    //mpu.setXGyroOffset(220);
    //mpu.setYGyroOffset(76);
    //mpu.setZGyroOffset(-85);
    //mpu.setZAccelOffset(1788); // 1688 factory default for my test chip

    // make sure it worked (returns 0 if so)
    if (devStatus == 0) {
        // turn on the DMP, now that it's ready
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
        attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }
}

/*---------------------------------------------------------------------------
     TITLE   : dmp_loop
     WORK    : 
     ARG     : void
     RET     : void
---------------------------------------------------------------------------*/
void dmp_loop() {
    // if programming failed, don't try to do anything
    if (!dmpReady) return;

    // wait for MPU interrupt or extra packet(s) available
    if (!mpuInterrupt && fifoCount < packetSize) return;

    // reset interrupt flag and get INT_STATUS byte
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();

    // get current FIFO count
    fifoCount = mpu.getFIFOCount();

    // check for overflow (this should never happen unless our code is too inefficient)
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        // reset so we can continue cleanly
        mpu.resetFIFO();
      //  Serial.println(F("FIFO overflow!"));

    // otherwise, check for DMP data ready interrupt (this should happen frequently)
    } else if (mpuIntStatus & 0x02) {
        // wait for correct available data length, should be a VERY short wait
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        
        // track FIFO count here in case there is > 1 packet available
        // (this lets us immediately read more without waiting for an interrupt)
        fifoCount -= packetSize;

    
        // display Euler angles in degrees
        mpu.dmpGetQuaternion (&q, fifoBuffer);
        mpu.dmpGetGravity (&gravity, &q);
        mpu.dmpGetYawPitchRoll  (ypr, &q, &gravity);

        // store roll, pitch, yaw
        yaw = ypr[0] * 180/M_PI;
        roll = ypr[1] * 180/M_PI;
        pitch = ypr[2] * 180/M_PI;                       
    }
}
