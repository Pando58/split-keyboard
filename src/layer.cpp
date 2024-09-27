#include "layer.h"
#include "defines.h"

Layer::Layer(Layout *layout, Key keys[TOTAL_KEYS_BOTH_SIDES])
	: m_layout(layout), m_keys(keys) {}

Key Layer::getKey(uint8_t index) {
	return m_keys[index];
}

Key *Layer::keys() {
	return m_keys;
}
