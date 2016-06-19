#include <SoftwareSerial.h>
boolean launch = 0;
int testPin = 4;
char inputCMD;
// software serial : TX = digital pin 10, RX = digital pin 11
SoftwareSerial portOne(10, 11);

// software serial : TX = digital pin 8, RX = digital pin 9
SoftwareSerial portTwo(8, 9);

void setup()
{
  // Start the hardware serial port
  Serial.begin(9600);

}

void loop()
{
  Serial.println("Hello");
  delay(5000);
 
}
