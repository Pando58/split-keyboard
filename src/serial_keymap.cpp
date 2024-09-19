#include "serial_keymap.h"
#include "defines.h"

// clang-format off
uint8_t serial_keymap_press[TOTAL_KEYS_ONE_SIDE] = {
	 49,  50,  51,  52,  53,  54,
	113, 119, 101, 114, 116, 121,
	 97, 115, 100, 102, 103, 104,
	122,
	               117, 105, 111,
	               106, 107, 108,
};

uint8_t serial_keymap_release[TOTAL_KEYS_ONE_SIDE] = {
	33, 64, 35, 36, 37, 94,
	81, 87, 69, 82, 84, 89,
	65, 83, 68, 70, 71, 72,
	90,
	            85, 73, 79,
	            74, 75, 76,
};
// clang-format on

void serial_keymap::readKeys(void (*onKeyChange)(uint8_t index, bool pressed)) {
	while (Serial.available()) {
		uint8_t data = Serial.read();

		for (uint8_t i = 0; i < TOTAL_KEYS_ONE_SIDE; i++) {
			if (data == serial_keymap_press[i]) {
				onKeyChange(i, true);
				break;
			}

			if (data == serial_keymap_release[i]) {
				onKeyChange(i, false);
				break;
			}
		}
	}
}
