#pragma once

#include "keyboard_mode/layers.h"
#include "layout.h"
#include "scene.h"
#include <Adafruit_SSD1306.h>
#include <Arduino.h>

class KeyboardMode : public scene::Scene {
	Layout m_layout;
	Layer0 m_layer0;
	Layer0Shift m_layer0_shift;
	Layer *m_layers[2];

  public:
	KeyboardMode(Adafruit_SSD1306 *display0, Adafruit_SSD1306 *display1);

	void enter() override;

	void loop() override;

	void onKeyChange(uint8_t index, bool pressed) override;
};
