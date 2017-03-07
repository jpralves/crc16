
/**************************************************************************
  //
  // crc16.cpp - generate a ccitt 16 bit cyclic redundancy check (crc)
  //
  //      The code in this module generates the crc for a block of data.
  //
**************************************************************************/

//                                 16  12  5
// The CCITT CRC 16 polynomial is X + X + X + 1.
// In binary, this is the bit pattern 1 0001 0000 0010 0001, and in hex it
//  is 0x11021.
// A 17 bit register is simulated by testing the MSB before shifting
//  the data, which affords us the luxury of specifiy the polynomial as a
//  16 bit value, 0x1021.

// initial CRC = 0;

#include "crc16.h"

#define POLY 0x1021

CRC16::CRC16() {
	crc = 0;
}

uint16_t CRC16::processByte(uint8_t data) {
  uint8_t i;

  crc = crc ^ ((uint16_t)data << 8);
  for (i = 0; i < 8; i++) {
    if (crc & 0x8000)
      crc = (crc << 1) ^ POLY;
    else
      crc <<= 1;
  }
  return crc;
}

uint16_t CRC16::processBuffer(const char *data_p, uint16_t length) {
/*  uint8_t i;
  uint16_t data;*/

  while(length--) {
    processByte(*data_p++);
/*    data = *data_p++;
    crc = crc ^ ((uint16_t)data << 8);
    for (i = 0; i < 8; i++) {
      if (crc & 0x8000)
        crc = (crc << 1) ^ POLY;
      else
        crc <<= 1;
    }*/
  }
  return crc;
}
