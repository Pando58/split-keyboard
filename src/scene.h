#pragma once

#include <Adafruit_SSD1306.h>
#include <Arduino.h>

namespace scene {

class Scene {
  protected:
	Adafruit_SSD1306 *m_display0;
	Adafruit_SSD1306 *m_display1;

  public:
	Scene(Adafruit_SSD1306 *display0, Adafruit_SSD1306 *display1);

	virtual void enter() = 0;

	virtual void loop() = 0;

	virtual void onKeyChange(uint8_t index, bool pressed) = 0;
};

}
