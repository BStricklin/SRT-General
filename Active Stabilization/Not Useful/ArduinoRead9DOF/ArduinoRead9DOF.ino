#include <Wire.h>

#define PRINT_ANALOGS 0 //Will print the analog raw data
#define PRINT_EULER 1   //Will print the Euler angles Roll, Pitch and Yaw

#define ADC_WARM_CYCLES 50
#define STATUS_LED 13 

int8_t sensors[3] = {1,2,0};  // Map the ADC channels gyro_x, gyro_y, gyro_z
int SENSOR_SIGN[9] = {-1,1,-1,1,1,1,-1,-1,-1};  //Correct directions x,y,z - gyros, accels, magnetormeter

float G_Dt=0.02;    // Integration time (DCM algorithm)  We will run the integration loop at 50Hz if possible

long timer=0;   //general purpuse timer
long timer_old;
long timer24=0; //Second timer used to print values 
int AN[6]; //array that store the 3 ADC filtered data (gyros)
int AN_OFFSET[6]={0,0,0,0,0,0}; //Array that stores the Offset of the sensors
int ACC[3];          //array that store the accelerometers data

int accel_x;
int accel_y;
int accel_z;
int magnetom_x;
int magnetom_y;
int magnetom_z;
float MAG_Heading;

float Accel_Vector[3]= {0,0,0}; //Store the acceleration in a vector
float Gyro_Vector[3]= {0,0,0};//Store the gyros turn rate in a vector
float Omega_Vector[3]= {0,0,0}; //Corrected Gyro_Vector data
float Omega_P[3]= {0,0,0};//Omega Proportional correction
float Omega_I[3]= {0,0,0};//Omega Integrator
float Omega[3]= {0,0,0};

// Euler angles
float roll;
float pitch;
float yaw;

float errorRollPitch[3]= {0,0,0}; 
float errorYaw[3]= {0,0,0};

unsigned int counter=0;
byte gyro_sat=0;

float DCM_Matrix[3][3]= {
 {
   1,0,0  }
 ,{
   0,1,0  }
 ,{
   0,0,1  }
}; 
float Update_Matrix[3][3]={{0,1,2},{3,4,5},{6,7,8}}; //Gyros here


float Temporary_Matrix[3][3]={
 {
   0,0,0  }
 ,{
   0,0,0  }
 ,{
   0,0,0  }
};

//ADC variables
volatile uint8_t MuxSel=0;
volatile uint8_t analog_reference;
volatile uint16_t analog_buffer[8];
volatile uint8_t analog_count[8];

void setup()
{ 
 Serial.begin(57600);
 pinMode (STATUS_LED,OUTPUT);  // Status LED
 
 Analog_Reference(DEFAULT); 
 Analog_Init();
 I2C_Init();
 Accel_Init();
 Read_Accel();

 Serial.println("Sparkfun 9DOF Razor AHRS");

 digitalWrite(STATUS_LED,LOW);
 delay(1500);

 // Magnetometer initialization
 Compass_Init();
 
 // Initialze ADC readings and buffers
 Read_adc_raw();
 delay(20);
 
 for(int i=0;i<32;i++)    // We take some readings...
   {
   Read_adc_raw();
   Read_Accel();
   for(int y=0; y<6; y++)   // Cumulate values
     AN_OFFSET[y] += AN[y];
   delay(20);
   }
   
 for(int y=0; y<6; y++)
   AN_OFFSET[y] = AN_OFFSET[y]/32;
   
 AN_OFFSET[5]-=GRAVITY*SENSOR_SIGN[5];
 
 //Serial.println("Offset:");
 for(int y=0; y<6; y++)
   Serial.println(AN_OFFSET[y]);
 
 delay(2000);
 digitalWrite(STATUS_LED,HIGH);
   
 Read_adc_raw();     // ADC initialization
 timer=millis();
 delay(20);
 counter=0;
}

void loop() //Main Loop
{
 if((millis()-timer)>=20)  // Main loop runs at 50Hz
 {
   counter++;
   timer_old = timer;
   timer=millis();
   if (timer>timer_old)
     G_Dt = (timer-timer_old)/1000.0;    // Real time of loop run. We use this on the DCM algorithm (gyro integration time)
   else
     G_Dt = 0;
   
   // *** DCM algorithm
   // Data adquisition
   Read_adc_raw();   // This read gyro data
   Read_Accel();     // Read I2C accelerometer
   
   if (counter > 5)  // Read compass data at 10Hz... (5 loop runs)
     {
     counter=0;
     Read_Compass();    // Read I2C magnetometer
     Compass_Heading(); // Calculate magnetic heading  
     }
   
   // Calculations...
   Matrix_update(); 
   Normalize();
   Drift_correction();
   Euler_angles();
   // ***
  
   printdata();
   
   //Turn off the LED when you saturate any of the gyros.
   if((abs(Gyro_Vector[0])>=ToRad(300))||(abs(Gyro_Vector[1])>=ToRad(300))||(abs(Gyro_Vector[2])>=ToRad(300)))
     {
     if (gyro_sat<50)
       gyro_sat+=10;
     }
   else
     {
     if (gyro_sat>0)
       gyro_sat--;
     }
 
   if (gyro_sat>0)
     digitalWrite(STATUS_LED,LOW);  
   else
     digitalWrite(STATUS_LED,HIGH);  
 
 }
  
}
