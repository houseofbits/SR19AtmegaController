/*
 * Core.h
 *
 * Created: 3/26/2019 20:57:35
 *  Author: T510
 */ 


#ifndef CORE_H_
#define CORE_H_

#define BAUD 115200 //115200//

#define BAUD_TOL 2

#include <string.h>

#include <util/setbaud.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#define SETBIT(ADDRESS,BIT) (ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT) (ADDRESS &= ~(1<<BIT))
#define FLIPBIT(ADDRESS,BIT) (ADDRESS ^= (1<<BIT))
#define CHECKBIT(ADDRESS,BIT) (ADDRESS & (1<<BIT))

#define SETBITMASK(x,y) (x |= (y))
#define CLEARBITMASK(x,y) (x &= (~y))
#define FLIPBITMASK(x,y) (x ^= (y))
#define CHECKBITMASK(x,y) (x & (y))

#include "light_ws2812.h"

#include "Serial.h"

static unsigned char CRC8(const unsigned char* data, unsigned short len) {
	unsigned char crc = 0x00;
	while (len--) {
		unsigned char extract = *data++;
		for (unsigned char tempI = 8; tempI; tempI--) {
			unsigned char sum = (crc ^ extract) & 0x01;
			crc >>= 1;
			if (sum) {
				crc ^= 0x8C;
			}
			extract >>= 1;
		}
	}
	return crc;
}

#endif /* CORE_H_ */