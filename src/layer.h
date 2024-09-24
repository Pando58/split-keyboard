#pragma once

#include "key.h"
#include "layout.h"
#include <Arduino.h>

class Layout;

class Layer {
  protected:
	Layout *m_layout;
	Key *m_keys;

  public:
	Layer(Layout *layout, Key *keys);

	virtual void onKeyChange(uint8_t index, bool pressed) = 0;

	Key getKey(uint8_t index);
};
