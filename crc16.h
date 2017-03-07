
#ifndef CRC16_H
#define CRC16_H

#include <stddef.h>
#include <stdint.h>

class CRC16 {
	public:
	   CRC16();
     uint16_t processByte(uint8_t data);
	   uint16_t processBuffer(const char *data_p, uint16_t length);
	   uint16_t getCrc() { return crc; };
	private:
	   uint16_t crc;
};	

#endif
