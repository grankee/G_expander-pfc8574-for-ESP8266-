#include "G_expander.h"


ESP_pfc8574::ESP_pfc8574(uint8_t addr,uint8_t sda,uint8_t scl)
{
	address=addr;
	pins=255;
	Wire.begin(sda,scl);
	Wire.beginTransmission(address);
	Wire.write(pins);
	Wire.endTransmission();
}
ESP_pfc8574::ESP_pfc8574(uint8_t addr)
{
	address=addr;
	pins=255;
	Wire.begin();
	Wire.beginTransmission(address);
	Wire.write(pins);
	Wire.endTransmission();
}
void  ESP_pfc8574::digitalWrite(uint8_t pin, uint8_t state)
{
	if(state==LOW && (pins&(1<<pin)))
		pins^=(1<<pin);
	else if(state==HIGH && !(pins&(1<<pin)))
		pins|=(1<<pin);
	Wire.beginTransmission(address);
	Wire.write(pins);
	Wire.endTransmission();
	
}
uint8_t ESP_pfc8574::pinRead(uint8_t pin)
{
	if(pins&(1<<pin))
		return HIGH;
	else return LOW;
}
uint8_t ESP_pfc8574::getByte() {
	Wire.requestFrom(address, 1);
	return Wire.read();
} // End of getByte

/**
 * Get the value of the bit of the GPIO as input.
 */
bool ESP_pfc8574::getBit(uint8_t bit) {
	if (bit < 0 || bit > 7) {
		return 0;
	}
	uint8_t byteValue = getByte();
	return (byteValue & (1<<bit)) != 0;
} // End of getBit