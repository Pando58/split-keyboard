#pragma once

#include "key_type.h"
#include <Arduino.h>

const uint8_t (*getKeyBitmap(const KeyType *key))[7];
