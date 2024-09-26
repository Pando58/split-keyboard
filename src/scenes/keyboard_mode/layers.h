#pragma once

#include "defines.h"
#include "key.h"
#include "layer.h"
#include "layout.h"

class Layer0 : public Layer {
  public:
	Layer0(Layout *layout, Key *keys);

	void onKeyChange(uint8_t index, bool pressed) override;
};

class Layer0Shift : public Layer {
  public:
	Layer0Shift(Layout *layout, Key *keys);

	void onKeyChange(uint8_t index, bool pressed) override;
};

#define kc(key)              \
	Key {                    \
		KeyType::Normal, key \
	}

#define kl(key)                       \
	Key {                             \
		KeyType::Layer, LayerKey::key \
	}

extern Key layer0_keys[TOTAL_KEYS_BOTH_SIDES];

extern Key layer0_shift_keys[TOTAL_KEYS_BOTH_SIDES];
