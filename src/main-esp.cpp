#include "defines.h"
#include "key_reader_serial.h"
#include "scene.h"
#include "scenes.h"
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <Wire.h>

Adafruit_SSD1306 display0(128, 64, &Wire);
Adafruit_SSD1306 display1(128, 64, &Wire1);

bool keys_pressed[TOTAL_KEYS_ONE_SIDE];

scenes::KeyboardMode scene_keyboard_mode(&display0, &display1);
scene::Scene *current_scene = &scene_keyboard_mode;

void onKeyChange(uint8_t index, bool pressed) {
	keys_pressed[index] = pressed;

	current_scene->onKeyChange(index, pressed);
}

key_reader_serial::KeyReader key_reader(&onKeyChange);

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

	current_scene->enter();
}

void loop() {
	key_reader.readKeys();
}
