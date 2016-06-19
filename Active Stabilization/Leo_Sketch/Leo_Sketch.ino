
//Connect IMU to TX1 and RX1 and then connect RX0 to TX1 and steal the data

String sensorData;
char c;
void setup() {
  Serial.begin(9600);
  //Serial1.begin(9600);
  Serial.println("9DOF Test"); 
}
  
void loop() {

  while (Serial.available()) {  
    if (Serial.available() >0) {
  c = Serial.read(); 
  //sensorData += c; //adds c to the sensorData string
       Serial.print(c); //see whatever came in on Serial.read()
    }
  }

  if (sensorData.length() >0) {
   Serial.println(sensorData);  //output the string
//readString=""; //resets reString for the next iteration of the loop
  } 
}
