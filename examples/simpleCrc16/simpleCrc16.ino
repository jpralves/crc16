/*
 * Filename: simpleCrc16.ino
 * Description: Example for library CRC16
 *
 * Version: 1.0.0
 * Author: Joao Alves <jpralves@gmail.com>
 * Required files: -
 * Required libraries: CRC16
 * Tested on: Arduino Nano, Arduino Uno, ESP8266
 *
 * History:
 * 1.0.0 - 2017-03-14 - Initial Version
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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