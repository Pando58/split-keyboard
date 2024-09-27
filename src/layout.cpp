#include "layout.h"

Layout::Layout(scene::Scene *scn) {
	m_scene = scn;
}

void Layout::set_layers(Layer *layers, uint8_t n_layers) {
	m_layers = layers;
	m_n_layers = n_layers;
	m_current_layer = 0;
}

void Layout::onKeyChange(uint8_t index, bool pressed) {
	m_keys_pressed[index] = pressed;

	m_layers[m_current_layer].onKeyChange(index, pressed);
}

void Layout::transition(uint8_t next) {
	Layer *previous_layer = &m_layers[m_current_layer];
	Layer *next_layer = &m_layers[next];

	for (uint8_t i = 0; i < TOTAL_KEYS_BOTH_SIDES; i++) {
		if (!m_keys_pressed[i])
			continue;

		Key previous_key = previous_layer->getKey(i);
		Key next_key = next_layer->getKey(i);

		if (previous_key.type != next_key.type || previous_key.value != next_key.value) {
			previous_layer->onKeyChange(i, false);
			next_layer->onKeyChange(i, true);
		}
	}

	m_current_layer = next;

	m_scene->onLayerChange();
}

Key *Layout::currentKeys() {
	return m_layers[m_current_layer].keys();
}

bool *Layout::currentKeysPressed() {
	return m_keys_pressed;
}
