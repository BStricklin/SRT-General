// We'll use SoftwareSerial to communicate with the XBee:
#include <SoftwareSerial.h>
// XBee's DOUT (TX) is connected to pin 0 (Arduino's Software RX)
// XBee's DIN (RX) is connected to pin 1 (Arduino's Software TX)
SoftwareSerial XBee(0, 1); // RX, TX

void setup()
{
Serial.begin(9600);
XBee.begin(9600);

}

void loop()
{
if (XBee.available()) {
byte incomingByte = XBee.read();
Serial.print(incomingByte, HEX);
Serial.print(" , ");

}

}
