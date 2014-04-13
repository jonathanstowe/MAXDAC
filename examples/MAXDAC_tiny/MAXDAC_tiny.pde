/*
This example program demonstrates basic use of the MAXDAC library.
It shows all functions are describes their syntax.
The MAX520/1 has a system for configuring the I2C address that
involves pulling 2 pins (for the '521) or 3 pins (for the '520)
either High or low.  Check datasheets for these pin numbers.
*/

#include <MAXDAC.h> //Import the MAXDAC library

// These are required for this to work on the Tiny parts
// You will need to be using the Adafruit version of TinyWireM library
// From https://github.com/adafruit/TinyWireM
#include <USI_TWI_Master.h>
#include <TinyWireM.h>


maxdac dac(B0101000); //start the MAXDAC library under the instance "dac".  The syntax for this command is "maxdac <instance>(<Device address>)
//the device address is as follows: "B0101{AD0}{AD1}{AD2}.  There is no AD2 on the MAX521, its bit is always 0.

void setup() {
  //nothing here
}

void loop() {
  for (int i=0; i<8; i++) {
    dac.write(i, 255); //writes all the registers to full power
  }
  delay(5000);
  dac.reset(); //resets all registers to off
  delay(5000);
  dac.shutDown(true); //shuts down the DAC into power save mode
  delay(5000);
  dac.shutDown(false); //wakes the DAC. Any write command will also wake the DAC from power save mode
  delay(5000);
  for (int i=0; i<8; i++) {
    dac.write(i, 127); //writes all the registers to half power
  }
  delay(5000);
}

