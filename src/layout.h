#pragma once

#include "defines.h"
#include "layer.h"
#include <Arduino.h>

class Layer;

class Layout {
	Layer *m_layers;
	uint8_t m_n_layers;
	uint8_t m_current_layer;
	uint8_t m_keys_pressed[TOTAL_KEYS_BOTH_SIDES] = {0};
	void (*m_onTransition)();

  public:
	void set_layers(Layer *layers, uint8_t n_layers);

	void set_onTransition(void (*onTransition)());

	void onKeyChange(uint8_t index, bool pressed);

	static void transition(Layout *layout, uint8_t next_layer);
};
