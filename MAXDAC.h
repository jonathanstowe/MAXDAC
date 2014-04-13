/*
  MAXDAC.h - Library for controling MAX520/521 Digital-Analog Converters (DACs).
  Created by Stephen Jones (TchnclFl), June 7th 2010.
  Released into the public domain.
*/

#ifndef MAXDAC_h
#define MACDAC_h


#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

#include "tiny_support.h"

#ifdef _MAXDAC_TINY
#include <USI_TWI_Master.h>
#include <TinyWireM.h>
#else
#include <Wire.h>
#endif

class maxdac
{
  public:
    maxdac(byte address);
	void write(int port, int value);
	void reset();
	void shutDown(boolean shutdown);
  private:
    byte _address;
};

#endif
