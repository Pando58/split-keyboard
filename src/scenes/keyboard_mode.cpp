#include "keyboard_mode.h"
#include "defines.h"
#include "keyboard_drawing.h"
#include "keyboard_mode/get_bitmap.h"

KeyboardMode::KeyboardMode(Adafruit_SSD1306 *display0, Adafruit_SSD1306 *display1)
	: scene::Scene(display0, display1), m_layout(this), m_layer0(&m_layout, layer0_keys), m_layer0_shift(&m_layout, layer0_shift_keys), m_layers{&m_layer0, &m_layer0_shift} {
	m_layout.set_layers(*m_layers, 2);
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
	}

	for (uint8_t i = 0; i < TOTAL_KEYS_ONE_SIDE; i++) {
		int8_t x = keyboard_drawing::get_position_x(i, false, true);
		int8_t y = keyboard_drawing::get_position_y(i, false, true) + 24;

		m_display1->drawRect(x, y, 11, 11, SSD1306_WHITE);
	}

	drawAllKeys();

	m_display0->display();
	m_display1->display();
}

void KeyboardMode::loop() {}

void KeyboardMode::onKeyChange(uint8_t index, bool pressed) {
	m_layout.onKeyChange(index, pressed);

	drawKey(index, pressed, true);
}

void KeyboardMode::onLayerChange() {
	drawAllKeys();
}

void KeyboardMode::drawKey(uint8_t index, bool pressed, bool update) {
	Key *keys = m_layout.currentKeys();

	bool on_left_side = index < 25;
	uint8_t index_one_side = index % 25;

	int8_t x = keyboard_drawing::get_position_x(index_one_side, false, !on_left_side);
	int8_t y = keyboard_drawing::get_position_y(index_one_side, false, !on_left_side) + 24;

	Adafruit_SSD1306 *display = on_left_side ? m_display0 : m_display1;

	display->fillRect(x + 1, y + 1, 9, 9, pressed ? SSD1306_WHITE : SSD1306_BLACK);
	display->drawBitmap(x + 2, y + 2, *getKeyBitmap(&keys[index]), 7, 7, !pressed ? SSD1306_WHITE : SSD1306_BLACK);

	if (update)
		display->display();
}

void KeyboardMode::drawAllKeys() {
	bool *keys_pressed = m_layout.currentKeysPressed();

	for (uint8_t i = 0; i < TOTAL_KEYS_BOTH_SIDES; i++) {
		drawKey(i, keys_pressed[i], false);
	}

	m_display0->display();
	m_display1->display();
}
