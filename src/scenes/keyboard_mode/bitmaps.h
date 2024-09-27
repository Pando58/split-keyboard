#pragma once

#include <Arduino.h>

static const uint8_t key_bitmaps[][7] PROGMEM = {
	// 32 .. 96
	{
		0b00000000, // Space
		0b00000000,
		0b00000000,
		0b00000000,
		0b10000010,
		0b10000010,
		0b11111110,
	},
	{
		0b00110000, // !
		0b00110000,
		0b00110000,
		0b00110000,
		0b00110000,
		0b00000000,
		0b00110000,
	},
	{
		0b01101100, // "
		0b01101100,
		0b00100100,
		0b01001000,
		0b00000000,
		0b00000000,
		0b00000000,
	},
	{
		0b01101100, // #
		0b01101100,
		0b11111110,
		0b01101100,
		0b11111110,
		0b01101100,
		0b01101100,
	},
	{
		0b00010000, // $
		0b01111100,
		0b11010000,
		0b01111100,
		0b00010110,
		0b01111100,
		0b00010000,
	},
	{
		0b01000010, // %
		0b10100100,
		0b01001000,
		0b00010000,
		0b00100100,
		0b01001010,
		0b10000100,
	},
	{
		0b00110000, // &
		0b01001000,
		0b01101000,
		0b01110000,
		0b10011010,
		0b10001100,
		0b01111010,
	},
	{
		0b00110000, // '
		0b00110000,
		0b00010000,
		0b00100000,
		0b00000000,
		0b00000000,
		0b00000000,
	},
	{
		0b00011000, // (
		0b00110000,
		0b01100000,
		0b01100000,
		0b01100000,
		0b00110000,
		0b00011000,
	},
	{
		0b00110000, // )
		0b00011000,
		0b00001100,
		0b00001100,
		0b00001100,
		0b00011000,
		0b00110000,
	},
	{
		0b00101000, // *
		0b00010000,
		0b00101000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
	},
	{
		0b00000000, // +
		0b00010000,
		0b00010000,
		0b01111100,
		0b00010000,
		0b00010000,
		0b00000000,
	},
	{
		0b00000000, // ,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00011000,
		0b00011000,
		0b00110000,
	},
	{
		0b00000000, // -
		0b00000000,
		0b00000000,
		0b01111100,
		0b00000000,
		0b00000000,
		0b00000000,
	},
	{
		0b00000000, // .
		0b00000000,
		0b00000000,
		0b00000000,
		0b00011000,
		0b00011000,
		0b00000000,
	},
	{
		0b00001000, // Slash
		0b00001000,
		0b00011000,
		0b00010000,
		0b00110000,
		0b00100000,
		0b00100000,
	},
	{
		0b01111100, // 0
		0b11000110,
		0b11000110,
		0b11000110,
		0b11000110,
		0b11000110,
		0b01111100,
	},
	{
		0b00110000, // 1
		0b01110000,
		0b00110000,
		0b00110000,
		0b00110000,
		0b00110000,
		0b11111100,
	},
	{
		0b01111100, // 2
		0b11000110,
		0b00001110,
		0b00011100,
		0b00111000,
		0b01110000,
		0b11111110,
	},
	{
		0b01111100, // 3
		0b11000110,
		0b00000110,
		0b01111100,
		0b00000110,
		0b11000110,
		0b01111100,
	},
	{
		0b00011100, // 4
		0b00111100,
		0b01101100,
		0b11001100,
		0b11111110,
		0b00001100,
		0b00001100,
	},
	{
		0b11111100, // 5
		0b11000000,
		0b11000000,
		0b11111100,
		0b00000110,
		0b11000110,
		0b01111100,
	},
	{
		0b01111100, // 6
		0b11000000,
		0b11000000,
		0b11111100,
		0b11000110,
		0b11000110,
		0b01111100,
	},
	{
		0b11111110, // 7
		0b11000110,
		0b00001100,
		0b00011000,
		0b00110000,
		0b00110000,
		0b00110000,
	},
	{
		0b01111100, // 8
		0b11000110,
		0b11000110,
		0b01111100,
		0b11000110,
		0b11000110,
		0b01111100,
	},
	{
		0b01111100, // 9
		0b11000110,
		0b11000110,
		0b01111110,
		0b00000110,
		0b00001100,
		0b01111000,
	},
	{
		0b00000000, // :
		0b00011000,
		0b00011000,
		0b00000000,
		0b00011000,
		0b00011000,
		0b00000000,
	},
	{
		0b00000000, // ;
		0b00011000,
		0b00011000,
		0b00000000,
		0b00011000,
		0b00011000,
		0b00110000,
	},
	{
		0b00011000, // <
		0b00110000,
		0b01100000,
		0b11000000,
		0b01100000,
		0b00110000,
		0b00011000,
	},
	{
		0b00000000, // =
		0b00000000,
		0b11111110,
		0b00000000,
		0b11111110,
		0b00000000,
		0b00000000,
	},
	{
		0b00110000, // >
		0b00011000,
		0b00001100,
		0b00000110,
		0b00001100,
		0b00011000,
		0b00110000,
	},
	{
		0b01111100, // ?
		0b11000110,
		0b11000110,
		0b00011100,
		0b00110000,
		0b00000000,
		0b00110000,
	},
	{
		0b01111100, // @
		0b10000010,
		0b10111010,
		0b10101010,
		0b10111110,
		0b10000000,
		0b01111100,
	},
	{
		0b00111000, // A
		0b01101100,
		0b11000110,
		0b11000110,
		0b11111110,
		0b11000110,
		0b11000110,
	},
	{
		0b11111100, // B
		0b11000110,
		0b11000110,
		0b11111100,
		0b11000110,
		0b11000110,
		0b11111100,
	},
	{
		0b01111100, // C
		0b11000110,
		0b11000000,
		0b11000000,
		0b11000000,
		0b11000110,
		0b01111100,
	},
	{
		0b11111000, // D
		0b11001100,
		0b11000110,
		0b11000110,
		0b11000110,
		0b11001100,
		0b11111000,
	},
	{
		0b11111110, // E
		0b11000000,
		0b11000000,
		0b11111100,
		0b11000000,
		0b11000000,
		0b11111110,
	},
	{
		0b11111110, // F
		0b11000000,
		0b11000000,
		0b11111100,
		0b11000000,
		0b11000000,
		0b11000000,
	},
	{
		0b01111100, // G
		0b11000110,
		0b11000000,
		0b11000000,
		0b11001110,
		0b11000110,
		0b01111100,
	},
	{
		0b11000110, // H
		0b11000110,
		0b11000110,
		0b11111110,
		0b11000110,
		0b11000110,
		0b11000110,
	},
	{
		0b11111100, // I
		0b00110000,
		0b00110000,
		0b00110000,
		0b00110000,
		0b00110000,
		0b11110000,
	},
	{
		0b00011110, // J
		0b00000110,
		0b00000110,
		0b00000110,
		0b11000110,
		0b11000110,
		0b01111100,
	},
	{
		0b11000110, // K
		0b11001100,
		0b11011000,
		0b11110000,
		0b11011000,
		0b11001100,
		0b11000110,
	},
	{
		0b11000000, // L
		0b11000000,
		0b11000000,
		0b11000000,
		0b11000000,
		0b11000000,
		0b11111110,
	},
	{
		0b11000110, // M
		0b11101110,
		0b11111110,
		0b11010110,
		0b11000110,
		0b11000110,
		0b11000110,
	},
	{
		0b11000110, // N
		0b11100110,
		0b11110110,
		0b11011110,
		0b11001110,
		0b11000110,
		0b11000110,
	},
	{
		0b01111100, // O
		0b11000110,
		0b11000110,
		0b11000110,
		0b11000110,
		0b11000110,
		0b01111100,
	},
	{
		0b11111100, // P
		0b11000110,
		0b11000110,
		0b11000110,
		0b11111100,
		0b11000000,
		0b11000000,
	},
	{
		0b01111100, // Q
		0b11000110,
		0b11000110,
		0b11000110,
		0b11010110,
		0b11001100,
		0b01111010,
	},
	{
		0b11111100, // R
		0b11000110,
		0b11000110,
		0b11111100,
		0b11011000,
		0b11001100,
		0b11000110,
	},
	{
		0b01111100, // S
		0b11000110,
		0b11000000,
		0b01111100,
		0b00000110,
		0b11000110,
		0b01111100,
	},
	{
		0b11111100, // T
		0b00110000,
		0b00110000,
		0b00110000,
		0b00110000,
		0b00110000,
		0b00110000,
	},
	{
		0b11000110, // U
		0b11000110,
		0b11000110,
		0b11000110,
		0b11000110,
		0b11000110,
		0b01111100,
	},
	{
		0b11000110, // V
		0b11000110,
		0b11000110,
		0b11000110,
		0b01101100,
		0b00111000,
		0b00010000,
	},
	{
		0b11000110, // W
		0b11000110,
		0b11000110,
		0b11010110,
		0b11111110,
		0b11101110,
		0b11000110,
	},
	{
		0b11000110, // X
		0b11101110,
		0b01111100,
		0b00111000,
		0b01111100,
		0b11101110,
		0b11000110,
	},
	{
		0b11001100, // Y
		0b11001100,
		0b11001100,
		0b01111000,
		0b00110000,
		0b00110000,
		0b00110000,
	},
	{
		0b11111110, // Z
		0b00001110,
		0b00011100,
		0b00111000,
		0b01110000,
		0b11100000,
		0b11111110,
	},
	{
		0b00111000, // [
		0b00110000,
		0b00110000,
		0b00110000,
		0b00110000,
		0b00110000,
		0b00111000,
	},
	{
		0b00100000, // Backslash
		0b00100000,
		0b00110000,
		0b00010000,
		0b00011000,
		0b00001000,
		0b00001000,
	},
	{
		0b00111000, // ]
		0b00011000,
		0b00011000,
		0b00011000,
		0b00011000,
		0b00011000,
		0b00111000,
	},
	{
		0b00010000, // ^
		0b00111000,
		0b00101000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
	},
	{
		0b00000000, // _
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b01111100,
	},
	{
		0b00100000, // `
		0b00010000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000000,
	},

	// 123 .. 126
	{
		0b00011000, // {
		0b00110000,
		0b00110000,
		0b01100000,
		0b00110000,
		0b00110000,
		0b00011000,
	},
	{
		0b00010000, // |
		0b00010000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b00010000,
	},
	{
		0b00110000, // }
		0b00011000,
		0b00011000,
		0b00001100,
		0b00011000,
		0b00011000,
		0b00110000,
	},
	{
		0b00000000, // ~
		0b00000000,
		0b01100000,
		0b10010010,
		0b00001100,
		0b00000000,
		0b00000000,
	},

	// Other keys
	{
		0b00010000, // Control
		0b00111000,
		0b01101100,
		0b01000100,
		0b00000000,
		0b00000000,
		0b00000000,
	},
	{
		0b00000000, // Shift
		0b00010000,
		0b00111000,
		0b01111100,
		0b11111110,
		0b00111000,
		0b00111000,
	},
	{
		0b00000000, // Alt
		0b11001110,
		0b00100000,
		0b00010000,
		0b00001000,
		0b11100110,
		0b00000000,
	},
	{
		0b10111010, // Super
		0b01101100,
		0b11000110,
		0b10010010,
		0b11000110,
		0b01101100,
		0b10111010,
	},
	{
		0b00000000, // Return
		0b00100010,
		0b01100010,
		0b11111110,
		0b01100000,
		0b00100000,
		0b00000000,
	},
	{
		0b00001110, // Escape
		0b00100010,
		0b01100010,
		0b11111010,
		0b01100010,
		0b00100010,
		0b00001110,
	},
	{
		0b00000000, // Backspace
		0b00100000,
		0b01100000,
		0b11111110,
		0b01100000,
		0b00100000,
		0b00000000,
	},
	{
		0b00000000, // Tab
		0b00100010,
		0b00110010,
		0b11111010,
		0b00110010,
		0b00100010,
		0b00000000,
	},
	{
		0b00000000, // Caps Lock
		0b00000000,
		0b00000100,
		0b00001010,
		0b01101110,
		0b10101010,
		0b01101010,
	},

	{
		0b00000000, // L1
		0b10000100,
		0b10001100,
		0b10000100,
		0b10000100,
		0b11101110,
		0b00000000,
	},
	{
		0b00000000, // L2
		0b10001110,
		0b10000010,
		0b10001110,
		0b10001000,
		0b11101110,
		0b00000000,
	},
	{
		0b00000000, // L3
		0b10001110,
		0b10000010,
		0b10000110,
		0b10000010,
		0b11101110,
		0b00000000,
	},
	{
		0b00000000, // L4
		0b10001010,
		0b10001010,
		0b10001110,
		0b10000010,
		0b11100010,
		0b00000000,
	},
	{
		0b00000000, // L5
		0b10001110,
		0b10001000,
		0b10001110,
		0b10000010,
		0b11101110,
		0b00000000,
	},
	{
		0b00000000, // L6
		0b10001110,
		0b10001000,
		0b10001110,
		0b10001010,
		0b11101110,
		0b00000000,
	},

	{
		0b00000000, // R1
		0b11100100,
		0b10101100,
		0b11000100,
		0b10100100,
		0b10101110,
		0b00000000,
	},
	{
		0b00000000, // R2
		0b11101110,
		0b10100010,
		0b11001110,
		0b10101000,
		0b10101110,
		0b00000000,
	},
	{
		0b00000000, // R3
		0b11101110,
		0b10100010,
		0b11000110,
		0b10100010,
		0b10101110,
		0b00000000,
	},
	{
		0b00000000, // R4
		0b11101010,
		0b10101010,
		0b11001110,
		0b10100010,
		0b10100010,
		0b00000000,
	},
	{
		0b00000000, // R5
		0b11101110,
		0b10101000,
		0b11001110,
		0b10100010,
		0b10101110,
		0b00000000,
	},
	{
		0b00000000, // R6
		0b11101110,
		0b10101000,
		0b11001110,
		0b10101010,
		0b10101110,
		0b00000000,
	},
};
