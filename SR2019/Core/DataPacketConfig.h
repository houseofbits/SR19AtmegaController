/*
 * DataPacketConfig.h
 *
 * Created: 4/21/2019 21:40:43
 *  Author: T510
 */ 


#ifndef DATAPACKETCONFIG_H_
#define DATAPACKETCONFIG_H_

#define PACKET_HEADER "SR2019LT"
					   	
enum PacketClassEnumerator : unsigned short
{
	HEADER = 0,
	WING_LIGHT_DATA,
	LIGHT_DATA,
	MOVER_DATA,
};

typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
}LightColor;

typedef struct {
	LightColor colors[7];
}LightWing;

typedef struct {
	LightColor	colors[7];
	uint8_t		wingId;
}LightWingData;


struct LightDataOutStructure {
	LightWing wingData[12];
};
struct MoverDataOutStructure {
	unsigned char data[12];
};

typedef DataPacket<LightWingData, PacketClassEnumerator> WingLightDataPacket;
typedef DataPacket<LightDataOutStructure, PacketClassEnumerator> LightDataPacket;
typedef DataPacket<MoverDataOutStructure, PacketClassEnumerator> MoverDataPacket;

#endif /* DATAPACKETCONFIG_H_ */