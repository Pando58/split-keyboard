#include "defines.h"
#include "key_reader_serial.h"
#include <Arduino.h>
#include <Wire.h>

#define KEY_BUFFER_CAPACITY 8

void receiveEvent(int how_many);
void requestEvent();
void onKeyChange(uint8_t index, bool pressed);

key_reader_serial::KeyReader key_reader(true, &onKeyChange);

uint8_t key_buffer[KEY_BUFFER_CAPACITY * 2];
uint8_t key_buffer_length = 0;

uint8_t esp_i2c_command = 0;

void setup() {
	Serial.begin(115200);

	Wire.setSDA(20);
	Wire.setSCL(21);

	Wire.begin(RP_I2C_ADDRESS);
	Wire.onRequest(requestEvent);
	Wire.onReceive(receiveEvent);
}

void loop() {
}

void loop1() {
	key_reader.readKeys();
}

void receiveEvent(int how_many) {
	if (how_many == 1) {
		esp_i2c_command = Wire.read();
	} else if (how_many == 2) {
		Serial.printf("Key %c %s\n", Wire.read(), Wire.read() ? "pressed" : "released");
	}
}

void requestEvent() {
	if (esp_i2c_command == 1) {
		Wire.write(key_buffer_length);
	} else if (esp_i2c_command == 2) {
		Wire.write(key_buffer, key_buffer_length * 2);
		key_buffer_length = 0;
	}
}

void onKeyChange(uint8_t index, bool pressed) {
	Serial.printf("%i - %i\n", index, pressed);

	if (key_buffer_length < KEY_BUFFER_CAPACITY) {
		key_buffer[key_buffer_length * 2] = index;
		key_buffer[key_buffer_length * 2 + 1] = pressed;
		key_buffer_length++;
	}
}
