#pragma once

#include "key.h"
#include <Arduino.h>

const uint8_t (*getKeyBitmap(const Key *key))[7];
