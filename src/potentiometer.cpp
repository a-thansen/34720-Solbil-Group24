// This code is for the MCP4131-503E/P
// THIS CODE WAS WRITTEN BY POLLY
#include "potentiometer.h"
// #include <SPI.h>

// #define POTENTIOMETER_SCK PA5
// #define POTENTIOMETER_SDI PA6
// #define POTENTIOMETER_SDO PA7
// // CS is active low
// #define POTENTIOMETER_CS PB6

void init_potentiometer() {
    pinMode(POTENTIOMETER_CS, OUTPUT);

    digitalWrite(POTENTIOMETER_CS, LOW);
    SPI.begin();
}

// Value is a number between 0 and 128 (inclusive of both)
// `value` is not 7-bit, since 128 is 8-bit. In total it has 129 different configurations.
void set_potentiometer(uint16_t value) {
    digitalWrite(POTENTIOMETER_CS, LOW);
//    printf("Set %d to LOW\r\n", POTENTIOMETER_CS);

 //  delay(100);

    // 4 bits
    uint16_t addr = 0x00; // Volatile wiper 0
    // 2 bits
    uint16_t command = 0b00; // Write data

    uint16_t packed = (addr << 12) | (command << 10) | value;

    SPI.transfer16(packed);

  //  delay(100);
    digitalWrite(POTENTIOMETER_CS, HIGH);
//  printf("Set %d to HIGH\r\n", POTENTIOMETER_CS);
}

