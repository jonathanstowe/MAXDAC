/*
  MAXDAC.cpp - Library for controling MAX520/521 Digital-Analog Converters (DACs).
  Created by Stephen Jones (TchnclFl), June 7th 2010.
  Released into the public domain.
*/

#include "MAXDAC.h"

/*
 * The _MACRO will be the appropriate Wire or TinyWireM
*/
maxdac::maxdac(byte address) //address should be 7 bits
{
  _WIRE.begin();
  _address = address;
}

void maxdac::write(int port, int value) //port is 0-7 for MAX521 and 0-3 for MAX520
{
  _WIRE.beginTransmission(_address); //tell the device we are ready to begin transmitting
  _WIRE.write((B00000111 & port)); //use some BitWise "&" to combine the command to write to a port with the port you wish to write to
  _WIRE.write(value); //write the actual value to the port
  _WIRE.endTransmission(); //stop communication
}

void maxdac::reset()
{
  _WIRE.beginTransmission(_address);
  _WIRE.write(B00010000); //this command byte tells the registers to reset
  _WIRE.write(B00000000); //dummy output byte
  _WIRE.endTransmission();
}

void maxdac::shutDown(boolean shutdown)
{
  if (shutdown == true) {
    _WIRE.beginTransmission(_address);
    _WIRE.write(B00001000); //this command byte tells the chip to shutdown
    _WIRE.write(B00000000); //dummy output byte
    _WIRE.endTransmission();
  }
  else
  {
    _WIRE.beginTransmission(_address);
	_WIRE.write(B00000000); //this command byte tells the chip to wake up from shutdown
	_WIRE.write(B00000000); //dummy output byte
	_WIRE.endTransmission();
  }
}
