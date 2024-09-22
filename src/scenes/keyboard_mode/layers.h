#pragma once

#include "defines.h"
#include "key_codes.h"
#include "key_type.h"

#define kc(key)                \
	KeyType {                  \
		KeyTypeEnum::Normal, { \
			.ch = key          \
		}                      \
	}

#define kl(key)               \
	KeyType {                 \
		KeyTypeEnum::Layer, { \
			.layer = key      \
		}                     \
	}

// clang-format off
const static KeyType layer0[TOTAL_KEYS_BOTH_SIDES] = {
	kc(KEY_TAB), kc('q'), kc('w'), kc('e'), kc('r'), kc('t'),
	kc(KEY_ESC), kc('a'), kc('s'), kc('d'), kc('f'), kc('g'),
	kc(KEY_LEFT_SHIFT), kc('z'), kc('x'), kc('c'), kc('v'), kc('b'),
	kc(KEY_LEFT_CTRL), kc(KEY_LEFT_GUI), kc(KEY_LEFT_ALT), kc(' '),
	kl(L4), kl(L5), kl(L6),

	kc(KEY_BACKSPACE), kc('p'), kc('o'), kc('i'), kc('u'), kc('y'),
	kc(']'), kc('['), kc('l'), kc('k'), kc('j'), kc('h'),
	kc(';'), kc('/'), kc('.'), kc(','), kc('m'), kc('n'),
	kc('\''), kl(R3), kl(R2), kc(KEY_RETURN),
	kl(R6), kl(R5), kl(R4),
};
