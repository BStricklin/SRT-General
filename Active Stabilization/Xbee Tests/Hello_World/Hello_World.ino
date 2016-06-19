/* Copyright (c) 2010-2011 mbed.org, MIT License
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software
* and associated documentation files (the "Software"), to deal in the Software without
* restriction, including without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or
* substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
* BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
* DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
 
#include "mbed.h"
#include "xbee.h"
 
/** On many platforms USBTX/USBRX overlap with serial on D1/D0 pins and enabling the below will interrupt the communication.
 *  You can use an LCD display to print the values or store them on an SD card etc.
 */
//Serial pc(USBTX, USBRX);
 
/**
 * D1 - TX pin (RX on the shield side)
 * D0 - RX pin (TX on the shield side)
 * NC - Reset pin; use D5 otherwise the shield might get into reset loop
 */
xbee xb(D1, D0, D5);
 
void setup
{
    char data[202];
 
    while(1) {
        xb.SendData("HellWorld");   // Send "HelloWorld"
        xb.RecieveData(data, 0);    // Read data
        printf("Received:%s", data);
        wait(1);
    }
}
 
            
