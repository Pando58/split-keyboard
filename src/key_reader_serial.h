#pragma once

#include "defines.h"
#include <Arduino.h>

namespace key_reader_serial {

class KeyReader {
	bool m_keys_pressed[TOTAL_KEYS_ONE_SIDE];
	void (*m_onKeyChange)(uint8_t index, bool pressed);

  public:
	KeyReader(void (*onKeyChange)(uint8_t index, bool pressed));

	void readKeys();
};

}
