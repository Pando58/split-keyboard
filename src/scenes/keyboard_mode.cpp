#include "keyboard_mode.h"
#include "defines.h"
#include "keyboard_drawing.h"
#include "keyboard_mode/get_bitmap.h"

void testOnTransition() {
	Serial.println("onTransition");
}

KeyboardMode::KeyboardMode(Adafruit_SSD1306 *display0, Adafruit_SSD1306 *display1)
	: scene::Scene(display0, display1), m_layer0(&m_layout, layer0_keys), m_layer1(&m_layout, layer0_keys), m_layers{&m_layer0, &m_layer1} {
	m_layout.set_layers(*m_layers, 2);
	m_layout.set_onTransition(testOnTransition);
}

void KeyboardMode::enter() {
	m_display0->setRotation(1);
	m_display1->setRotation(1);
	m_display0->clearDisplay();
	m_display1->clearDisplay();

	for (uint8_t i = 0; i < TOTAL_KEYS_ONE_SIDE; i++) {
		int8_t x = keyboard_drawing::get_position_x(i);
		int8_t y = keyboard_drawing::get_position_y(i) + 24;

		m_display0->drawRect(x, y, 11, 11, SSD1306_WHITE);
		m_display0->drawBitmap(x + 2, y + 2, *getKeyBitmap(&layer0_keys[i]), 7, 7, SSD1306_WHITE);
	}

	for (uint8_t i = 0; i < TOTAL_KEYS_ONE_SIDE; i++) {
		int8_t x = keyboard_drawing::get_position_x(i, false, true);
		int8_t y = keyboard_drawing::get_position_y(i, false, true) + 24;

		m_display1->drawRect(x, y, 11, 11, SSD1306_WHITE);
		m_display1->drawBitmap(x + 2, y + 2, *getKeyBitmap(&layer0_keys[i + TOTAL_KEYS_ONE_SIDE]), 7, 7, SSD1306_WHITE);
	}

	m_display0->display();
	m_display1->display();
}

void KeyboardMode::loop() {}

void KeyboardMode::onKeyChange(uint8_t index, bool pressed) {
	m_layout.onKeyChange(index, pressed);

	bool on_left_side = index < 25;
	uint8_t index_one_side = index % 25;

	int8_t x = keyboard_drawing::get_position_x(index_one_side, false, !on_left_side);
	int8_t y = keyboard_drawing::get_position_y(index_one_side, false, !on_left_side) + 24;

	Adafruit_SSD1306 *display = on_left_side ? m_display0 : m_display1;

	display->fillRect(x + 1, y + 1, 9, 9, pressed ? SSD1306_WHITE : SSD1306_BLACK);
	display->drawBitmap(x + 2, y + 2, *getKeyBitmap(&layer0_keys[index]), 7, 7, !pressed ? SSD1306_WHITE : SSD1306_BLACK);
	display->drawRect(x, y, 11, 11, !pressed ? SSD1306_WHITE : SSD1306_BLACK);
	display->display();
}
