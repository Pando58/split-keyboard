#pragma once

#include "defines.h"
#include "key.h"
#include "layer.h"
#include "scene.h"
#include <Arduino.h>

class Layer;

class Layout {
	scene::Scene *m_scene;
	Layer *m_layers;
	uint8_t m_n_layers;
	uint8_t m_current_layer;
	bool m_keys_pressed[TOTAL_KEYS_BOTH_SIDES] = {false};

  public:
	Layout(scene::Scene *scn);

	void set_layers(Layer *layers, uint8_t n_layers);

	void onKeyChange(uint8_t index, bool pressed);

	void transition(uint8_t next_layer);

	Key *currentKeys();

	bool *currentKeysPressed();
};
