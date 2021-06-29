/*
 * Application.cpp
 *
 * Created: 5/11/2019 23:16:40
 *  Author: T510
 */ 
/*

 #include "Application.h"

Application::Application()
{	}

void Application::init(){

	//Set up OC1A CTC mode
	
	//OC1A = PB5 / ATmega32u4
	
	//Set as output
	SETBIT(DDRB, 5);
	
    // Set up timer with prescaler = 64 and CTC mode
    TCCR1B |= (1 << WGM12)|(1 << CS11)|(1 << CS10);


    // set up timer OC1A pin in toggle mode
    TCCR1A |= (1 << COM1A0);
	
	// initialize counter
	TCNT1 = 0;
	// initialize compare value
	OCR1A = 75; //80-200
			
	/*
	//Enable interrupts
	TIMSK1 |= (1 << OCIE1A);

    // initialize counter
    TCNT1 = 0;
    
    // initialize compare value
    OCR1A = 500;
	
	TIFR1 |= (1 << OCF1A);
	
	sei();
*/
	
	
	//PF1 - ENA
	//PF0 - DIR
	
//	SETBIT(DDRF, 1);
//	SETBIT(DDRF, 0);
//	SETBIT(DDRF, 4);
	
//	CLEARBIT(PORTF, 1);
//	CLEARBIT(PORTF, 0);	
//	CLEARBIT(PORTF, 4);	
	
//	SETBIT(PORTF, 1);
//	SETBIT(PORTF, 0);	
//	SETBIT(PORTF, 4);
/*
	
}

void Application::run(){

	//uint8_t ri=0;

	do{	
		/*
        // check whether the flag bit is set
        // if set, it means that there has been a compare match
        // and the timer has been cleared
        // use this opportunity to toggle the led
        if (TIFR1 & (1 << OCF1A)) // NOTE: '>=' used instead of '=='
        {
			FLIPBIT(PORTF, 1);
			FLIPBIT(PORTF, 0);		
        }
        
        // wait! we are not done yet!
        // clear the flag bit manually since there is no ISR to execute
        // clear it by writing '1' to it (as per the datasheet)
        TIFR1 |= (1 << OCF1A);
        
        */
		/*
		FLIPBIT(PORTF, 1);
		FLIPBIT(PORTF, 0);
		FLIPBIT(PORTF, 4);
		
		_delay_ms(1);
		_delay_us();
		*/
		/*
		SETBIT(PORTF, 1);
		SETBIT(PORTF, 0);		

		_delay_ms(1500);

		CLEARBIT(PORTF, 1);
		CLEARBIT(PORTF, 0);

		_delay_ms(1500);
		*/
		
		
		/**
			ri++;
		
		  for (uint8_t i=0; i<10; i++)
		  {
			  led[i].r = ri;	//rand();
			  led[i].g = 0;		// rand();
			  led[i].b = 0;		//rand();
		  }
		  ws2812_setleds(led, 84);
		  
		  _delay_ms(1);
		  
		*/
/*
		//cli();

		

		//sei();
		
	}while (true);

}

#define DATA_SIZE 252//21

void Application::processReceivedData(uint8_t data)
{




}
*/