#include <SoftwareSerial.h>
boolean launchReady = 1;
boolean finalLaunchReady = 1;
boolean launchTime = 1;
String abortLaunch;
char inputCMD;

//// software serial : TX = digital pin 10, RX = digital pin 11
//SoftwareSerial portOne(10, 11);
//
//// software serial : TX = digital pin 8, RX = digital pin 9
//SoftwareSerial portTwo(8, 9);

void setup()
{
  // Start the hardware serial port
  Serial.begin(9600);

  

}

void loop()
{
  Serial.println("Test Start");
  for (int n =1; n<=10; n++)
  {
    String data = "Sensor Test - Th1: ";
    data = data + String(readThermo(1),DEC);
    data = data + " Th2: ";
    data = data + String(readThermo(2),DEC);
    data = data + " Th3: ";
    data = data + String(readThermo(3),DEC);
    data = data + " Pr1: ";
    data = data + String(readPressure(1),DEC);
    data = data + " Pr2: ";
    data = data + String(readPressure(2),DEC);
    data = data + ".";
    Serial.println(data);
    delay(500);
  }
  Serial.println("Test End");
}

double readThermo(int therm)
{
  if (therm == 1)
  {
//    return thermocouple1.readCelsius();
      return 1;
  }

  if (therm == 2)
  {
//    return thermocouple2.readCelsius();
      return 2;
  }

  if (therm == 3)
  {
//    return thermocouple3.readCelsius();
      return 3;
  }
  return -99;
}

double readPressure(int pres)
{
  if (pres == 1)
  {
//    return analogRead(pressurePin1);
      return 4;
  }

  if (pres == 2)
  {
//    return analogRead(pressurePin2);
            return 5;
  }

  return -99;
}
