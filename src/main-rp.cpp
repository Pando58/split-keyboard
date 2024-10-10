#include "defines.h"
#include "i2c_commands.h"
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

void receiveEvent(int byte_amount) {
	esp_i2c_command = Wire.read();

	if (byte_amount != command_byte_amount[esp_i2c_command]) {
		Serial.printf("Amount of bytes doesn't match with command %i: %i != %i\n", esp_i2c_command, byte_amount, command_byte_amount[esp_i2c_command]);
	}

	if (esp_i2c_command == I2CCommandID::SendKeyThroughUSB) {
		Serial.printf("Key %c %s\n", Wire.read(), Wire.read() ? "pressed" : "released");
	}
}

void requestEvent() {
	if (esp_i2c_command == I2CCommandID::GetKeyBufferLength) {
		Wire.write(key_buffer_length);
	} else if (esp_i2c_command == I2CCommandID::GetKeyBuffer) {
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
