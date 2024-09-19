#pragma once

#include <Arduino.h>

namespace serial_keymap {

class KeyReader {
	void (*m_onKeyChange)(uint8_t index, bool pressed);

  public:
	KeyReader(void (*onKeyChange)(uint8_t index, bool pressed));

	void readKeys();
};

}
