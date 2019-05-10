#ifndef G_expander_h
#define G_expander_h



#include "Arduino.h"
#include <Wire.h>
class ESP_pfc8574
{
	private:
	uint8_t address;
	uint8_t pins;
	
	public:
	ESP_pfc8574(uint8_t addr);
	ESP_pfc8574(uint8_t addr,uint8_t sda,uint8_t scl);
	void digitalWrite(uint8_t pin, uint8_t state);
	uint8_t pinRead(uint8_t pin);//this method DOESN'T READ real state of pin, it returns state of pin which has been set last time!
	uint8_t getByte();
	bool getBit(uint8_t bit);
};

#endif