#pragma once

#include <Arduino.h>

enum LayerKey {
	L4 = 3,
	L5 = 4,
	L6 = 5,
	R2 = 7,
	R3 = 8,
	R4 = 9,
	R5 = 10,
	R6 = 11,
};

enum class KeyTypeEnum {
	Normal,
	Layer,
};

struct KeyType {
	KeyTypeEnum type;
	union {
		uint8_t ch;
		LayerKey layer;
	} value;
};
