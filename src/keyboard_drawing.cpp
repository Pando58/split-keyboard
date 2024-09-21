#include "keyboard_drawing.h"

int16_t get_position(uint8_t i, bool flip) {
	int8_t x_initial;
	int8_t y_initial;

	if (i < 19) {
		uint8_t x_cell = i % 6;

		x_initial = x_cell * 10;
		y_initial = (i / 6) * 10 + (x_cell == 1 || x_cell == 4 ? 3 : x_cell == 5 ? 6
																				 : 0);
	} else {
		uint8_t x_cell = (i - 19) % 3;

		x_initial = 33 + (x_cell * 10);
		y_initial = 37 + ((i - 19) / 3 * 10) + (x_cell * 3);
	}

	if (flip) {
		x_initial = 64 - 11 - x_initial;
	}

	int8_t x_rotated = -10 - y_initial;
	int8_t y_rotated = x_initial;

	return ((int16_t)x_rotated << 8) | y_rotated;
}

int8_t keyboard_drawing::get_position_x(uint8_t index, bool flip) {
	return get_position(index, flip) >> 8;
}

int8_t keyboard_drawing::get_position_y(uint8_t index, bool flip) {
	return get_position(index, flip) & 0xFF;
}
