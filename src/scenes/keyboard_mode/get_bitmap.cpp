#include "get_bitmap.h"
#include "bitmaps.h"

const uint8_t (*getKeyBitmap(const Key *key))[7] {
	if (key->type == KeyType::Normal) {
		uint8_t ch = key->value;

		if ((ch >= 97 && ch <= 122)) // 'a' .. 'z'
			return &key_bitmaps[ch - 64];

		if ((ch >= 32 && ch <= 96)) // ' ' .. '`'
			return &key_bitmaps[ch - 32];

		if ((ch >= 123 && ch <= 126)) // '{' .. '~'
			return &key_bitmaps[ch - 58];

		if (ch >= 128 && ch <= 131) // KEY_LEFT_CTRL .. KEY_LEFT_GUI
			return &key_bitmaps[ch - 59];

		if (ch >= 176 && ch <= 179) // KEY_RETURN .. KEY_TAB
			return &key_bitmaps[ch - 103];

		if (ch == 193) // KEY_RETURN .. KEY_TAB
			return &key_bitmaps[77];
	} else {
		return &key_bitmaps[78 + key->value];
	}

	return &key_bitmaps[0];
}
