#include "scene.h"

scene::Scene::Scene(Adafruit_SSD1306 *display0, Adafruit_SSD1306 *display1)
	: m_display0(display0), m_display1(display1) {}

void scene::Scene::onLayerChange() {}
