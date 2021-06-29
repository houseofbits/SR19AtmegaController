/*
 * Application.h
 *
 * Created: 4/18/2019 22:57:17
 *  Author: T510
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Core/Core.h"
//#include "DataResponse.h"

class Application// : public DataResponse
{
public:
	Application();

	void init();
	void run();
	//void OnReceivePacket(PacketClassEnumerator classType, unsigned char* buffer, unsigned short size);

	//struct cRGB led[84];
	
	//LightDataPacket		lightData;
	
	//WingLightDataPacket wingLightData;
	
	//struct cRGB		ledData[12][7];
	
	
	//bool			hasNewLightData;



	void processReceivedData(uint8_t c);
	
	uint8_t		dataUpdated;
	
	bool		currentBuffer;

	uint8_t		bufferedData[2][253] PROGMEM;	//252
		
	uint8_t		ser_data[15];
	uint8_t		ser_data_pos = 0;
	uint8_t		ser_header_pos = 0;	
	uint8_t		crc;	
	
};


#endif /* APPLICATION_H_ */