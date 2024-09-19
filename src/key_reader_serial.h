#pragma once

#include <Arduino.h>

namespace key_reader_serial {

class KeyReader {
	void (*m_onKeyChange)(uint8_t index, bool pressed);

  public:
	KeyReader(void (*onKeyChange)(uint8_t index, bool pressed));

	void readKeys();
};

}
