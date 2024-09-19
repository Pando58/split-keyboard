#include "keyboard_mode.h"
#include "defines.h"
#include "keyboard_drawing.h"

KeyboardMode::KeyboardMode(Adafruit_SSD1306 *display0, Adafruit_SSD1306 *display1)
	: scene::Scene(display0, display1) {}

void KeyboardMode::enter() {
	m_display0->clearDisplay();

	for (uint8_t i = 0; i < TOTAL_KEYS_ONE_SIDE; i++) {
		int8_t x = keyboard_drawing::get_position_x(i);
		int8_t y = keyboard_drawing::get_position_y(i);

		m_display0->drawRect(x, y, 11, 11, SSD1306_WHITE);
	}

	m_display0->display();
}

void KeyboardMode::loop() {}

void KeyboardMode::onKeyChange(uint8_t index, bool pressed) {
	int8_t x = keyboard_drawing::get_position_x(index);
	int8_t y = keyboard_drawing::get_position_y(index);

	m_display0->fillRect(x + 3, y + 3, 5, 5, pressed ? SSD1306_WHITE : SSD1306_BLACK);
	m_display0->display();
}
