/*
 * Helper to make MAXDAC work with ATtiny parts
*/

#ifndef _TINY_SUPPORT_H
#define _TINY_SUPPORT_H

// This may not be an exhaustive list 
#if defined(__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__) || defined(__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
#define _MAXDAC_TINY 1
#endif

#endif
