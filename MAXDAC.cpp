/*
  MAXDAC.cpp - Library for controling MAX520/521 Digital-Analog Converters (DACs).
  Created by Stephen Jones (TchnclFl), June 7th 2010.
  Released into the public domain.
*/

#include "WProgram.h"
#include "MAXDAC.h"
#include "Wire.h"

maxdac::maxdac(byte address) //address should be 7 bits
{
  Wire.begin();
  _address = address;
}

void maxdac::write(int port, int value) //port is 0-7 for MAX521 and 0-3 for MAX520
{
  Wire.beginTransmission(_address); //tell the device we are ready to begin transmitting
  Wire.send((B00000111 & port)); //use some BitWise "&" to combine the command to write to a port with the port you wish to write to
  Wire.send(value); //send the actual value to the port
  Wire.endTransmission(); //stop communication
}

void maxdac::reset()
{
  Wire.beginTransmission(_address);
  Wire.send(B00010000); //this command byte tells the registers to reset
  Wire.send(B00000000); //dummy output byte
  Wire.endTransmission();
}

void maxdac::shutDown(boolean shutdown)
{
  if (shutdown == true) {
    Wire.beginTransmission(_address);
    Wire.send(B00001000); //this command byte tells the chip to shutdown
    Wire.send(B00000000); //dummy output byte
    Wire.endTransmission();
  }
  else
  {
    Wire.beginTransmission(_address);
	Wire.send(B00000000); //this command byte tells the chip to wake up from shutdown
	Wire.send(B00000000); //dummy output byte
	Wire.endTransmission();
  }
}