#include "defines.h"
#include "keyboard_drawing.h"
#include "serial_keymap.h"
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <Wire.h>

Adafruit_SSD1306 display0(128, 64, &Wire);
Adafruit_SSD1306 display1(128, 64, &Wire1);

bool keys_pressed[TOTAL_KEYS_ONE_SIDE];

void setup() {
	Serial.begin(115200);

	// I2C0 - SDA: 21, SCL: 22
	Wire1.setPins(32, 33);

	Wire.begin();

	if (!display0.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS)) {
		Serial.println("SSD1306 I2C0 allocation failed");
		for (;;)
			;
	}

	if (!display1.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS)) {
		Serial.println("SSD1306 I2C1 allocation failed");
		for (;;)
			;
	}

	display0.clearDisplay();

	for (uint8_t i = 0; i < TOTAL_KEYS_ONE_SIDE; i++) {
		int8_t x = keyboard_drawing::get_position_x(i);
		int8_t y = keyboard_drawing::get_position_y(i);

		display0.drawRect(x, y, 11, 11, SSD1306_WHITE);
	}

	display0.display();
}

void loop() {
	while (Serial.available()) {
		uint8_t data = Serial.read();

		for (uint8_t i = 0; i < TOTAL_KEYS_ONE_SIDE; i++) {
			if (data == serial_keymap_press[i]) {
				keys_pressed[i] = true;

				int8_t x = keyboard_drawing::get_position_x(i);
				int8_t y = keyboard_drawing::get_position_y(i);

				display0.fillRect(x + 3, y + 3, 5, 5, SSD1306_WHITE);
				display0.display();

				break;
			}

			if (data == serial_keymap_release[i]) {
				keys_pressed[i] = false;

				int8_t x = keyboard_drawing::get_position_x(i);
				int8_t y = keyboard_drawing::get_position_y(i);

				display0.fillRect(x + 3, y + 3, 5, 5, SSD1306_BLACK);
				display0.display();

				break;
			}
		}
	}
}
