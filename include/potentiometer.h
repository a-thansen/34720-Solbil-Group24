#include <SPI.h>

#define POTENTIOMETER_SCK PA5
#define POTENTIOMETER_SDI PA6
#define POTENTIOMETER_SDO PA7
// CS is active low
#define POTENTIOMETER_CS PB6

void init_potentiometer();

void set_potentiometer(uint16_t data);
