#pragma once

#include <Arduino.h>

enum I2CCommandID {
	GetKeyBufferLength,
	GetKeyBuffer,
	SendKeyThroughUSB,
};

const uint8_t command_byte_amount[] = {
	1,
	1,
	3,
};
