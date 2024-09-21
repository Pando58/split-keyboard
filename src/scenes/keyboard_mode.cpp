#include "keyboard_mode.h"
#include "defines.h"
#include "keyboard_drawing.h"

KeyboardMode::KeyboardMode(Adafruit_SSD1306 *display0, Adafruit_SSD1306 *display1)
	: scene::Scene(display0, display1) {}

void KeyboardMode::enter() {
	m_display0->clearDisplay();
	m_display1->clearDisplay();

	for (uint8_t i = 0; i < TOTAL_KEYS_ONE_SIDE; i++) {
		int8_t x = keyboard_drawing::get_position_x(i) + 103;
		int8_t y = keyboard_drawing::get_position_y(i);

		m_display0->drawRect(x, y, 11, 11, SSD1306_WHITE);
	}

	for (uint8_t i = 0; i < TOTAL_KEYS_ONE_SIDE; i++) {
		int8_t x = keyboard_drawing::get_position_x(i, true) + 103;
		int8_t y = keyboard_drawing::get_position_y(i, true);

		m_display1->drawRect(x, y, 11, 11, SSD1306_WHITE);
	}

	m_display0->display();
	m_display1->display();
}

void KeyboardMode::loop() {}

void KeyboardMode::onKeyChange(uint8_t index, bool pressed) {
	bool left_side = index < 25;
	index %= 25;

	int8_t x = keyboard_drawing::get_position_x(index, !left_side) + 103;
	int8_t y = keyboard_drawing::get_position_y(index, !left_side);

	Adafruit_SSD1306 *display = left_side ? m_display0 : m_display1;

	display->fillRect(x + 3, y + 3, 5, 5, pressed ? SSD1306_WHITE : SSD1306_BLACK);
	display->display();
}
