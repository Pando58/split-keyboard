#include "defines.h"
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <Wire.h>

void receiveEvent(int how_many);

void requestEvent();

void setup() {
	Serial.begin(115200);

	Wire.setSDA(20);
	Wire.setSCL(21);

	Wire.begin(RP_I2C_ADDRESS);
	Wire.onRequest(requestEvent);
	Wire.onReceive(receiveEvent);
}

void loop() {}

void receiveEvent(int how_many) {}

void requestEvent() {}
