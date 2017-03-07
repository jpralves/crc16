// Example testing sketch for simple CRC16
// Written by joao alves, public domain

#include "crc16.h"

char *buffer = "The quick brown fox jumps over the lazy dog";
CRC16 crc;

void setup() {
  Serial.begin(9600);
  Serial.println("CRC16 test!");
  crc.processBuffer(buffer, strlen(buffer));
  Serial.print("The resulting CRC16 is : 0x");
  Serial.println(crc.getCrc(),HEX);
}

void loop() {
}