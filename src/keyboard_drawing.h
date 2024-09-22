#pragma once

#include <Arduino.h>

namespace keyboard_drawing {

int8_t get_position_x(uint8_t i, bool rotate = false, bool flip = false);
int8_t get_position_y(uint8_t i, bool rotate = false, bool flip = false);

}
