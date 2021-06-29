/*
 * Core.h
 *
 * Created: 3/26/2019 20:57:35
 *  Author: T510
 */ 


#ifndef CORE_H_
#define CORE_H_

#define BAUD 115200//9600

#define BAUD_TOL 2

//#define F_CPU 16000000UL

#include <string.h>

#include <util/setbaud.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define FLIPBIT(ADDRESS,BIT) (ADDRESS ^= (1<<BIT))
#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))

#define SETBITMASK(x,y) (x |= (y))
#define CLEARBITMASK(x,y) (x &= (~y))
#define FLIPBITMASK(x,y) (x ^= (y))
#define CHECKBITMASK(x,y) (x & (y))



//#include "light_ws2812.h"

#include "Serial.h"

//#include "DataPacketParse.h"

//#include "DataResponse.h"

#endif /* CORE_H_ */