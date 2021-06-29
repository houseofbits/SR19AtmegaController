/*
 * SR2019.cpp
 *
 * Created: 11.07.2019 11:42:15
 * Author : KristsPudzens
 */ 

#define _ASSERT_ENABLE_

#include "Core/Core.h"

#define DATA_SIZE 7//3

uint8_t		data[DATA_SIZE];
uint8_t		ser_data[15];
uint8_t		ser_data_pos = 0;
uint8_t		ser_header_pos = 0;
uint8_t		crc;

bool		motorOn = false;
bool		motorDirection = false;
uint8_t		motorSpeed = 150;


unsigned char CRC8(const unsigned char* data, unsigned short len) {
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

void processReceivedData(uint8_t dataIn)
{
	//'O'
	if(ser_header_pos == 3){
		if(dataIn == 79){

			//start new data
			ser_header_pos = 0;
			ser_data_pos = 0;
			
			return;
			
			}else{
			ser_header_pos = 0;
		}
	}
	//'T'
	if(ser_header_pos == 2){
		if(dataIn == 84)ser_header_pos++;
		else{
			ser_header_pos = 0;
		}
	}
	//'O'
	if(ser_header_pos == 1){
		if(dataIn == 79)ser_header_pos++;
		else{
			ser_header_pos = 0;
		}
	}
	//'M'
	if(ser_header_pos == 0){
		if(dataIn == 77)ser_header_pos++;
		else{
			ser_header_pos = 0;
		}
	}
	
	if(ser_data_pos < DATA_SIZE){
		
		data[ser_data_pos] = dataIn;
		
	}
	
	if(ser_data_pos == DATA_SIZE){
		
		crc = CRC8((const unsigned char*)&data, DATA_SIZE);
		
		if(crc == dataIn && 
			data[3] == 'S' &&
			data[4] == 'T' &&
			data[5] == 'P' &&
			data[6] == 'R'){

			motorOn = (data[0] > 0);
			motorDirection = (data[1] > 0);
			motorSpeed = data[2];
			
			if(motorOn)CLEARBIT(PORTB, 1);
			else SETBIT(PORTB, 1);
			
			if(motorDirection)CLEARBIT(PORTB, 2);
			else SETBIT(PORTB, 2);		
			
			OCR1A = motorSpeed;	
		}

	}
	
	ser_data_pos++;
}

ISR(USART_RX_vect)
{
	unsigned char c = UDR;
	processReceivedData(c);
	
	/*
	//Test stuff
	if(c == 'a'){
		SETBIT(PORTB, 1);
	}
	if(c == 'b'){
		CLEARBIT(PORTB, 1);
	}	
	if(c == 'c'){
		SETBIT(PORTB, 2);
	}
	if(c == 'd'){
		CLEARBIT(PORTB, 2);
	}	
	*/
}

int main(void)
{
	
	//20000000 / 2 * 64 * (1 + val)
	//20000000/(2*64*100) = 156Hz
	//200 = 781Hz
	//50 = 3125Hz
	//20 = 7812Hz
	
	//B1 - ENA
	//B2 - DIR
	//B3 - PUL
	
	SETBIT(DDRB, 1);
	SETBIT(DDRB, 2);
	SETBIT(DDRB, 3);
	
	SETBIT(PORTB, 1);
	CLEARBIT(PORTB, 2);
	CLEARBIT(PORTB, 3);
	
	sei();
	
	serialBegin(115200);

	//Set up OC1A CTC mode

	// Set up timer with prescaler = 64 and CTC mode
    TCCR1B |= (1 << WGM12)|(1 << CS11)|(1 << CS10);

    // set up timer OC1A pin in toggle mode
    TCCR1A |= (1 << COM1A0);
	
	// initialize counter
	TCNT1 = 0;

	// initialize compare value
	OCR1A = 110; //110-200

	while(true){

		

	}	
}


