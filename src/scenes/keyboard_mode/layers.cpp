#include "layers.h"
#include "key_codes.h"

Layer0::Layer0(Layout *layout, Key *keys)
	: Layer(layout, keys) {}

void Layer0::onKeyChange(uint8_t index, bool pressed) {
	Serial.printf("Layer0: %c %s\n", m_keys[index].value, pressed ? "pressed" : "released");

	if (index == 12 && pressed) {
		m_layout->transition(1);
	}
}

Layer0Shift::Layer0Shift(Layout *layout, Key *keys)
	: Layer(layout, keys) {}

void Layer0Shift::onKeyChange(uint8_t index, bool pressed) {
	Serial.printf("Layer0 (shift): %c %s\n", m_keys[index].value, pressed ? "pressed" : "released");

	if (index == 12 && !pressed) {
		m_layout->transition(0);
	}
}

// clang-format off
Key layer0_keys[TOTAL_KEYS_BOTH_SIDES] = {
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

Key layer0_shift_keys[TOTAL_KEYS_BOTH_SIDES] = {
	kc(KEY_TAB), kc('Q'), kc('W'), kc('E'), kc('R'), kc('T'),
	kc(KEY_CAPS_LOCK), kc('A'), kc('S'), kc('D'), kc('F'), kc('G'),
	kc(KEY_LEFT_SHIFT), kc('Z'), kc('X'), kc('C'), kc('V'), kc('B'),
	kc(KEY_LEFT_CTRL), kc(KEY_LEFT_GUI), kc(KEY_LEFT_ALT), kc(' '),
	kl(L4), kl(L5), kl(L6),

	kc(KEY_BACKSPACE), kc('P'), kc('O'), kc('I'), kc('U'), kc('Y'),
	kc('}'), kc('{'), kc('L'), kc('K'), kc('J'), kc('H'),
	kc(':'), kc('?'), kc('>'), kc('<'), kc('M'), kc('N'),
	kc('"'), kl(R3), kl(R2), kc(KEY_RETURN),
	kl(R6), kl(R5), kl(R4),
};
