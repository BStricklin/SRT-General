/*
 * Code works. Just hook up GND, 3.3V, and
 * TX1 and RX1 to the IMU
 */

char val;
int ledpin = 13;
void setup() 
{
  Serial.begin(115200);
  Serial1.begin(57600);
  pinMode(13,OUTPUT);
}

void loop() 
{
 if (Serial1.available()) 
 { 
   val = Serial1.read();
   //digitalWrite(ledpin,HIGH);
   Serial.write(val);
   // delay(1000);
   // digitalWrite(ledpin,LOW);
   // delay(1000);    
   }
}
