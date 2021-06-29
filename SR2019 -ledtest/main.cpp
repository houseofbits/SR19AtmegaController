/*
 * SR2019.cpp
 *
 * Created: 11.07.2019 11:42:15
 * Author : KristsPudzens
 */ 

#define _ASSERT_ENABLE_

//#include "Core/Core.h"

#include <stdlib.h>

#include "light_ws2812.h"

//uint8_t	numLeds = 10;

#define numLeds 40

struct cRGB led[numLeds];

//uint8_t		bufferedData[253];

int main(void)
{
	uint8_t b=10;
	
	uint8_t a=0;
	uint8_t i=0;
	uint8_t f=0;
	
	while(b > 1)	
	{
		/*
		//None
		for (i=0; i<numLeds; i++)
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
		/*
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
		
		*/
		//Individual
		for (a=0; a<numLeds; a++){
			for (i=0; i<numLeds; i++)
			{	
				if(a == i){
					led[i].r = 10;
					led[i].g = 255;
					led[i].b = 10;					
				}else{
					led[i].r = 30;
					led[i].g = 10;
					led[i].b = 30;					
				}
			}
			ws2812_setleds(led,numLeds);
			_delay_ms(100);
		}
		_delay_ms(500);
		////////////////////////////////////////////////////////////////////////////////
		//White
		//Fast fade
		for (f=0; f<255; f++){
			for (i=0; i<numLeds; i++)
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
		for (f=0; f<255; f++){
			for (i=0; i<numLeds; i++)
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
		for (f=0; f<255; f++){
			for (i=0; i<numLeds; i++)
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
		for (f=0; f<255; f++){
			for (i=0; i<numLeds; i++)
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
		for (f=0; f<255; f++){
			for (i=0; i<numLeds; i++)
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
		for (f=0; f<255; f++){
			for (i=0; i<numLeds; i++)
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
		for (f=0; f<255; f++){
			for (i=0; i<numLeds; i++)
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
		for (f=0; f<255; f++){
			for (i=0; i<numLeds; i++)
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
	
	
}