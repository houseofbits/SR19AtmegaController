
#ifndef ASERIAL_H
#define ASERIAL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include <avr/interrupt.h>
#include <compat/deprecated.h>  // for sbi, cbi
#include <avr/sfr_defs.h>

void serialBegin(long baud);
void serialWrite(uint8_t c);
void serialWrite(const char *str);
void serialWriteLn(const char *str);

#endif