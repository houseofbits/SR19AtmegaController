/*
 * DataRequests.h
 *
 * Created: 4/21/2019 21:31:30
 *  Author: T510
 */ 

#ifndef DATAREQUESTS_H_
#define DATAREQUESTS_H_

#include "Serial.h"
#include "DataPacketParse.h"
#include "DataPacketConfig.h"

class DataResponse : DataPacketParse<PacketClassEnumerator>
{
	public:

	DataResponse() : DataPacketParse<PacketClassEnumerator>(PACKET_HEADER),
	serial()
	{	}		

	HardwareSerial		serial;
	uint8_t				buffer[128];
	unsigned int		size;
	uint8_t				data;

	void initRequests(){
		serial.begin(BAUD);
	}

	void processRequests(){		
		while(serial.available() > 0){
			data = serial.read();
			readPacketByte(data);
		}
	}

	void writePacket(BaseDataPacket * packet) {
		size = packet->getSize();
		packet->toBytes(buffer, size);
		write(buffer, size);
	}

	void write(uint8_t* buffer, unsigned int size){

	}
};

#endif /* DATAREQUESTS_H_ */