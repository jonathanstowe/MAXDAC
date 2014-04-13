/*
  MAXDAC.h - Library for controling MAX520/521 Digital-Analog Converters (DACs).
  Created by Stephen Jones (TchnclFl), June 7th 2010.
  Released into the public domain.
*/

#ifndef MAXDAC_h
#define MACDAC_h

#include "WProgram.h"
#include "Wire.h"

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