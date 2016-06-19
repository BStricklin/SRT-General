#include <SoftwareSerial.h>
String charm;

SoftwareSerial mySerial(10, 11);

void setup() {

  mySerial.begin(9600);
  Serial.begin(9600);

}

void loop() {

    for (int x = 0; x<10; x++)
    {
    if (mySerial.available())
    {
      Serial.println(mySerial.available());
      charm = mySerial.readStringUntil('\n');
      Serial.println(charm);
      
    }
    else
    {
      Serial.println("Nothing");
    }
    
    delay(500);
    }
mySerial.end();
Serial.println(mySerial.available());
Serial.println('i');
    
}
