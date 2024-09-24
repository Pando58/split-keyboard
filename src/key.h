#pragma once

#include <Arduino.h>

namespace LayerKey {

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

}

enum class KeyType {
	Normal,
	Layer,
};

struct Key {
	KeyType type;
	uint8_t value;
};
