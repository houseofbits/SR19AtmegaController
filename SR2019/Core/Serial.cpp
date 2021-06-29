/*
 * Serial.cpp
 *
 * Created: 5/12/2019 10:26:00
 *  Author: T510
 */ 
 
#include "Core.h"

void serialWrite(uint8_t c)
{
	while (!(UCSR0A & (1 << UDRE0)))
	;
	UDR0 = c;
}

void serialWrite(const char *str)
{
	while (*str)serialWrite(*str++);
}
void serialWriteLn(const char *str)
{
	while (*str)serialWrite(*str++);
	serialWrite('\r');
	serialWrite('\n');
}
void serialBegin(long baud)
{
	uint16_t baud_setting;

	UCSR0A = 0;
	baud_setting = (F_CPU / 8 / baud - 1) / 2;

	UBRR0H = baud_setting >> 8;
	UBRR0L = baud_setting;

	UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
	UCSR0B &= ~UDRE0;
}
