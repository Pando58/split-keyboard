#pragma once

#include <Arduino.h>

namespace serial_keymap {

void readKeys(void (*onKeyChange)(uint8_t index, bool pressed));

}
