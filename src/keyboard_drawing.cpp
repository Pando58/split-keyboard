#include "keyboard_drawing.h"

int16_t get_position(uint8_t i, bool rotate, bool flip) {
	int8_t x;
	int8_t y;

	if (i < 19) {
		uint8_t x_cell = i % 6;

		x = x_cell * 10;
		y = (i / 6) * 10 + (x_cell == 1 || x_cell == 4 ? 3 : x_cell == 5 ? 6
																		 : 0);
	} else {
		uint8_t x_cell = (i - 19) % 3;

		x = 33 + (x_cell * 10);
		y = 37 + ((i - 19) / 3 * 10) + (x_cell * 3);
	}

	if (flip) {
		x = 64 - 11 - x;
	}

	if (rotate) {
		x = -10 - y;
		y = x;
	}

	return ((int16_t)x << 8) | y;
}

int8_t keyboard_drawing::get_position_x(uint8_t index, bool rotate, bool flip) {
	return get_position(index, rotate, flip) >> 8;
}

int8_t keyboard_drawing::get_position_y(uint8_t index, bool rotate, bool flip) {
	return get_position(index, rotate, flip) & 0xFF;
}
