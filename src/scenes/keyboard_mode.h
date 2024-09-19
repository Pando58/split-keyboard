#pragma once

#include "scene.h"
#include <Adafruit_SSD1306.h>
#include <Arduino.h>

class KeyboardMode : public scene::Scene {
  public:
	KeyboardMode(Adafruit_SSD1306 *display0, Adafruit_SSD1306 *display1);

	void enter();

	void loop();

	void onKeyChange(uint8_t index, bool pressed);
};
