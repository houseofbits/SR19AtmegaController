/*
 * SR2019.cpp
 *
 * Created: 11.07.2019 11:42:15
 * Author : KristsPudzens
 */ 

#define _ASSERT_ENABLE_

#define BUFFER_SIZE 20

#include "Core/Core.h"

uint8_t		dataUpdated;
	
bool		currentBuffer;

uint8_t		bufferedData[2][253];
	
uint8_t		ser_data[15];
uint8_t		ser_data_pos = 0;
uint8_t		ser_header_pos = 0;
uint8_t		crc;

#define DATA_SIZE 252

void processReceivedData(uint8_t data)
{
	//'9'
	if(ser_header_pos == 3){
		if(data == 57){

			//start new data
			ser_header_pos = 0;
			ser_data_pos = 0;
			
			return;
			
			}else{
			ser_header_pos = 0;
		}
	}
	//'1'
	if(ser_header_pos == 2){
		if(data == 49)ser_header_pos++;
		else{
			ser_header_pos = 0;
		}
	}
	//'R'
	if(ser_header_pos == 1){
		if(data == 82)ser_header_pos++;
		else{
			ser_header_pos = 0;
		}
	}
	//'S'
	if(ser_header_pos == 0){
		if(data == 83)ser_header_pos++;
		else{
			ser_header_pos = 0;
		}
	}
	
	if(ser_data_pos < DATA_SIZE){
		
		bufferedData[!currentBuffer][ser_data_pos] = data;
		
	}
	
	if(ser_data_pos == DATA_SIZE){
		
		crc = CRC8((const unsigned char*)&bufferedData[!currentBuffer], DATA_SIZE);
		
		if(crc == data){
			
			currentBuffer = !currentBuffer;
			
			dataUpdated = 1;
			
		}

	}
	
	ser_data_pos++;
}

uint8_t index = 0;

ISR(USART_RX_vect)
{
	unsigned char c = UDR0;
	
	//serialWrite(c);
	
	processReceivedData(c);
}

int main(void)
{
	/**/
	
	struct cRGB nullLed[1];
	
	nullLed[0].r = 255;
	nullLed[0].g = 0;
	nullLed[0].b = 0;
	
	serialBegin(115200);

	sei();
	
	do{

		cli();
		if(dataUpdated == 1){

			ws2812_setleds_nrs(nullLed, 1);

			ws2812_setleds_array((uint8_t*)&bufferedData[currentBuffer], 84);
			
			dataUpdated = 0;
		}
		sei();
		
	}while (true);	


	/**
	uint8_t	numLeds= 100;
	struct cRGB led[numLeds];
	
	uint8_t b=10;
	
	while(b > 1)
	{

		//None
		for (uint8_t i=0; i<numLeds; i++)
		{
			led[i].r = 0;
			led[i].g = 0;
			led[i].b = 0;
		}
		
		ws2812_setleds(led,numLeds);
		_delay_ms(500);
		
		//Red
		for (uint8_t i=0; i<numLeds; i++)
		{
			led[i].r = 255;
			led[i].g = 0;
			led[i].b = 0;
		}		
		
		ws2812_setleds(led,numLeds);		
		_delay_ms(500);

		//Green
		for (uint8_t i=0; i<numLeds; i++)
		{
			led[i].r = 0;
			led[i].g = 255;
			led[i].b = 0;
		}
		
		ws2812_setleds(led,numLeds);		
		_delay_ms(500);

		//Blue
		for (uint8_t i=0; i<numLeds; i++)
		{
			led[i].r = 0;
			led[i].g = 0;
			led[i].b = 255;
		}
		
		ws2812_setleds(led,numLeds);
		_delay_ms(500);
		
		//Yellow
		for (uint8_t i=0; i<numLeds; i++)
		{
			led[i].r = 255;
			led[i].g = 255;
			led[i].b = 0;
		}
		
		ws2812_setleds(led,numLeds);
		_delay_ms(500);		
		
		//Random 
		for (uint8_t i=0; i<numLeds; i++)
		{
			led[i].r = rand();
			led[i].g = rand();
			led[i].b = rand();
		}
		ws2812_setleds(led,numLeds);
		_delay_ms(500);
		
		////////////////////////////////////////////////////////////////////////////////
		//White
		//Fast fade
		for (uint8_t f=0; f<255; f++){
			for (uint8_t i=0; i<numLeds; i++)
			{
				led[i].r = f;
				led[i].g = f;
				led[i].b = f;
			}
			ws2812_setleds(led,numLeds);	
			_delay_ms(10);		
		}
		_delay_ms(500);
		
		//Fast fade
		for (uint8_t f=0; f<255; f++){
			for (uint8_t i=0; i<numLeds; i++)
			{
				led[i].r = 255-f;
				led[i].g = 255-f;
				led[i].b = 255-f;
			}
			ws2812_setleds(led,numLeds);
			_delay_ms(10);
		}
		_delay_ms(500);	
		////////////////////////////////////////////////////////////////////////////////
		//Red
		//Fast fade
		for (uint8_t f=0; f<255; f++){
			for (uint8_t i=0; i<numLeds; i++)
			{
				led[i].r = f;
				led[i].g = 0;
				led[i].b = 0;
			}
			ws2812_setleds(led,numLeds);
			_delay_ms(10);
		}
		_delay_ms(500);
		
		//Fast fade
		for (uint8_t f=0; f<255; f++){
			for (uint8_t i=0; i<numLeds; i++)
			{
				led[i].r = 255-f;
				led[i].g = 0;
				led[i].b = 0;
			}
			ws2812_setleds(led,numLeds);
			_delay_ms(10);
		}
		_delay_ms(500);	
		
		////////////////////////////////////////////////////////////////////////////////
		//Green
		//Fast fade
		for (uint8_t f=0; f<255; f++){
			for (uint8_t i=0; i<numLeds; i++)
			{
				led[i].r = 0;
				led[i].g = f;
				led[i].b = 0;
			}
			ws2812_setleds(led,numLeds);
			_delay_ms(10);
		}
		_delay_ms(500);
		
		//Fast fade
		for (uint8_t f=0; f<255; f++){
			for (uint8_t i=0; i<numLeds; i++)
			{
				led[i].r = 0;
				led[i].g = 255-f;
				led[i].b = 0;
			}
			ws2812_setleds(led,numLeds);
			_delay_ms(10);
		}
		_delay_ms(500);				
		
		////////////////////////////////////////////////////////////////////////////////
		//Blue
		//Fast fade
		for (uint8_t f=0; f<255; f++){
			for (uint8_t i=0; i<numLeds; i++)
			{
				led[i].r = 0;
				led[i].g = 0;
				led[i].b = f;
			}
			ws2812_setleds(led,numLeds);
			_delay_ms(10);
		}
		_delay_ms(500);
		
		//Fast fade
		for (uint8_t f=0; f<255; f++){
			for (uint8_t i=0; i<numLeds; i++)
			{
				led[i].r = 0;
				led[i].g = 0;
				led[i].b = 255-f;
			}
			ws2812_setleds(led,numLeds);
			_delay_ms(10);
		}
		_delay_ms(500);		
		
	}
	/**/
	
}
