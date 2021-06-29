/*
 * Serial.cpp
 *
 * Created: 5/12/2019 10:26:00
 *  Author: T510
 */ 
 
#include "Core.h"

static char numberStringBuffer[20];

void serialBegin(long baud)
{
	uint16_t baud_setting;

	UCSRA = 0;
	baud_setting = (F_CPU / 8 / baud - 1) / 2;

	UBRRH = baud_setting >> 8;
	UBRRL = baud_setting;

	UCSRB |= (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);
	UCSRB &= ~UDRE;
}
void serialWrite(uint8_t c)
{
	while (!(UCSRA & (1 << UDRE)))
	;
	UDR = c;
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
void serialWriteInt(uint32_t d)
{
	itoa(d,numberStringBuffer, 10);
	serialWrite(numberStringBuffer);
}
void serialWriteIntLn(uint32_t d)
{
	itoa(d,numberStringBuffer, 10);
	serialWrite(numberStringBuffer);
	serialWrite('\r');
	serialWrite('\n');
}
void serialWriteFloat(float f, char digits)
{
	dtostrf(f, 6, digits, numberStringBuffer);
	serialWrite(numberStringBuffer);
}