/*
 * Application.cpp
 *
 * Created: 5/11/2019 23:16:40
 *  Author: T510
 */ 
 #include "Application.h"

Application::Application() : 
// DataResponse(),
	//lightData(PacketClassEnumerator::LIGHT_DATA),
	//wingLightData(PacketClassEnumerator::WING_LIGHT_DATA),
	//hasNewLightData(false),
	
	ser_header_pos(0)
{	}

void Application::init(){

	//initRequests();

	sei();
	
	//serial.writeLn("Init SR2019 application");

}

void Application::run(){

	//uint8_t ri=0;

	do{

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

		cli();
		if(dataUpdated == 1){

			ws2812_setleds_array((uint8_t*)&bufferedData[currentBuffer], 84);
			
			dataUpdated = 0;
		}
		sei();
		
	}while (true);

}

#define DATA_SIZE 252//21

void Application::processReceivedData(uint8_t data)
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

/*
//Implemented from DataPacketParse
void Application::OnReceivePacket(PacketClassEnumerator classType, unsigned char* buffer, unsigned short size) {

	switch(classType){
		case PacketClassEnumerator::WING_LIGHT_DATA:

		//serial.writeLn("WING_LIGHT_DATA packet received");

		wingLightData.fromBytes(buffer, size);
		
		memcpy(&ledData[wingLightData.packet.data.wingId], &wingLightData.packet.data.colors, 7*3);
		
		hasNewLightData = true;

		break;		
		case PacketClassEnumerator::LIGHT_DATA:

		//serial.writeLn("LIGHT_DATA packet received");

		lightData.fromBytes(buffer, size);
		hasNewLightData = true;

		break;
		case PacketClassEnumerator::MOVER_DATA:

		//serial.writeLn("MOVER_DATA packet received");
		
		break;
		default:
			break;		
	};
	//serial.writeLn("Packet received");


}
*/