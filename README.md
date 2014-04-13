MAXDAC
======

This is a fork of the MAXDAC Arduino library by Steve Jones, to include
fixes for modern Arduino toolkits and Attiny parts

There are examples for both "normal" and ATtiny parts.

In order for this to work with the ATtiny you will need to use the
Adafruit version of the TinyWireM library at:

    https://github.com/adafruit/TinyWireM

As this has an interface consistent with the more recent Wire library.

The library provides an Arduino interface to the Maxim MAX520/MAX521 octal digital to analogue coverters.
