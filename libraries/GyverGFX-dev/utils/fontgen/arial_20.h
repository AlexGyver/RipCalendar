#pragma once
#include <FontGFX.h>

// name: arial_20
// arial.ttf, height $20, threshold 0.9
// glyphs: abcdefghijklmnopqrstuvwxyz,W
// 796 bytes

static const uint8_t arial_20_index_index[] PROGMEM = {
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 
	0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0xb, 0x36, 
};

static const uint16_t arial_20_index[] PROGMEM = {
    0x0, 0x24, 0x42, 0x5e, 0x7a, 0xa2, 0xb4, 0xdb, 0xee, 0xf8, 0x108, 0x123, 0x129, 0x146, 0x158, 0x171, 
	0x18f, 0x1ad, 0x1ba, 0x1e1, 0x1f3, 0x205, 0x21c, 0x23d, 0x25a, 0x275, 0x292, 0x29a, 0x2c4, 
};

static const uint8_t arial_20_bitmap[] PROGMEM = {
    0x9, 0xe, 0xf, 0x90, 0x52, 0xb, 0x10, 0x91, 0x8f, 0x8, 0x91, 0x19, 0x18, 0x71, 0xd, 0x20, 0x52, 0xb, 0x18, 0x72, 0x9, 0x20, 0x71, 0x8d, 0x18, 0x71, 0x8d, 0x18, 0x71, 0x7, 0x9, 0xd0, 0x9f, 0x9, 0xd2, 0x17, 	// a (0)
	0x4, 0xd, 0x14, 0xff, 0xf4, 0xc6, 0x2c, 0xc2, 0x50, 0x1c, 0xa1, 0xd2, 0x1c, 0xa1, 0x56, 0x14, 0xa1, 0xd2, 0x1c, 0xa1, 0xd2, 0x1c, 0xa2, 0x4e, 0x24, 0xc6, 0xd0, 0x5d, 0x44, 0x48, 	// b (1)
	0x9, 0xd, 0xf, 0x19, 0x32, 0x97, 0x19, 0xb0, 0x89, 0x38, 0xf4, 0x8d, 0x48, 0xb5, 0x8b, 0x48, 0xd4, 0x91, 0x20, 0xd0, 0x89, 0x20, 0xb1, 0x87, 0x20, 0x95, 0x83, 0x28, 	// c (2)
	0x4, 0xe, 0x14, 0xe1, 0x35, 0x17, 0x41, 0xb3, 0x9, 0x38, 0x92, 0x87, 0x48, 0x72, 0x85, 0x58, 0x52, 0x85, 0x58, 0x52, 0x87, 0x48, 0x73, 0x7, 0x3b, 0xff, 0xc5, 0xa0, 	// d (3)
	0x9, 0xe, 0xf, 0x91, 0x32, 0x97, 0x19, 0xb0, 0x89, 0x10, 0x51, 0x8f, 0x18, 0x52, 0xd, 0x18, 0x52, 0xb, 0x20, 0x52, 0x8b, 0x18, 0x52, 0x8b, 0x18, 0x52, 0xf, 0x10, 0x52, 0x7, 0x8, 0xf1, 0x87, 0x18, 0xd1, 0x87, 0x20, 0xb1, 0x85, 0x10, 	// e (4)
	0x4, 0x9, 0x14, 0x28, 0x59, 0x5, 0x73, 0xff, 0xc4, 0x15, 0xa1, 0x46, 0x15, 0xa1, 0x46, 0x15, 0xa1, 0x64, 	// f (5)
	0x9, 0xe, 0x14, 0x38, 0x37, 0x93, 0x18, 0x72, 0x17, 0x10, 0x91, 0x1b, 0x9, 0x33, 0x89, 0x10, 0xd4, 0x87, 0x10, 0xb5, 0x85, 0x18, 0x95, 0x85, 0x18, 0xb4, 0x87, 0x10, 0xf4, 0x7, 0x10, 0x70, 0x8b, 0x1b, 0xd0, 0xa5, 0x11, 0xd3, 0x0, 	// g (6)
	0x4, 0xd, 0x14, 0xff, 0xf9, 0x4a, 0x1e, 0x21, 0xe2, 0x16, 0x41, 0xe2, 0x1e, 0x27, 0xcc, 0x74, 0xc7, 0x52, 0x5c, 	// h (7)
	0x4, 0x4, 0x14, 0x1c, 0x49, 0x44, 0x94, 0x49, 0x44, 0x7c, 	// i (8)
	0x4, 0x7, 0x19, 0xc0, 0x3b, 0x85, 0xb8, 0xb1, 0x2f, 0x12, 0xf1, 0x27, 0x8, 0x71, 0x21, 0x20, 	// j (9)
	0x4, 0xd, 0x14, 0xff, 0xf9, 0x52, 0x25, 0xe3, 0x5a, 0x4d, 0x42, 0x42, 0x35, 0x2, 0x48, 0x34, 0xc1, 0xce, 0x2c, 0xa1, 0x52, 0x24, 0xa0, 0xd8, 0x16, 0x60, 0xc0, 	// k (10)
	0x4, 0x4, 0x14, 0xff, 0xba, 0x0, 	// l (11)
	0x9, 0x14, 0xf, 0xfd, 0xd0, 0xa3, 0x60, 0x76, 0x5, 0x68, 0x76, 0x9, 0x59, 0xf0, 0x9d, 0x9, 0xd0, 0x87, 0x58, 0x76, 0x5, 0x68, 0x56, 0x87, 0x61, 0xf0, 0x9d, 0x11, 0xb0, 	// m (12)
	0x9, 0xd, 0xf, 0xfd, 0xd0, 0xa3, 0x60, 0x76, 0x5, 0x68, 0x56, 0x87, 0x61, 0xf0, 0x9d, 0x9, 0xd2, 0x17, 	// n (13)
	0x9, 0xf, 0xf, 0x91, 0x32, 0x97, 0x19, 0xb0, 0x89, 0x38, 0xf4, 0x8d, 0x48, 0xb5, 0x8b, 0x48, 0xd4, 0x8f, 0x38, 0x90, 0x9b, 0x19, 0x72, 0x93, 0x90, 	// o (14)
	0x9, 0xd, 0x14, 0xff, 0xb0, 0x8b, 0x21, 0xd4, 0x7, 0x28, 0x74, 0x87, 0x28, 0x55, 0x85, 0x28, 0x74, 0x87, 0x28, 0x74, 0x87, 0x28, 0x93, 0x89, 0x31, 0xb4, 0x17, 0x51, 0x14, 0x80, 	// p (15)
	0x9, 0xe, 0x14, 0xb9, 0x35, 0x17, 0x41, 0xb3, 0x9, 0x38, 0x92, 0x87, 0x48, 0x72, 0x85, 0x50, 0x72, 0x85, 0x58, 0x52, 0x87, 0x48, 0x72, 0x89, 0x38, 0x93, 0xd, 0xb, 0xfa, 0xe8, 	// q (16)
	0x9, 0x9, 0xf, 0xfd, 0xd0, 0xa3, 0x60, 0x56, 0x87, 0x60, 0x76, 0x3, 0x70, 	// r (17)
	0x9, 0xd, 0xf, 0x88, 0x92, 0x7, 0x18, 0xd1, 0x89, 0x9, 0x11, 0x11, 0x10, 0x72, 0xd, 0x10, 0x91, 0x8b, 0x18, 0x92, 0xb, 0x18, 0x72, 0xb, 0x18, 0x71, 0x8f, 0x10, 0x90, 0x89, 0x8, 0x71, 0x8f, 0x18, 0x51, 0x8f, 0x50, 0x71, 0x80, 	// s (18)
	0x4, 0x8, 0x14, 0x28, 0x59, 0x5, 0x72, 0x50, 0xbf, 0x4c, 0xa1, 0x54, 0x1c, 0xa1, 0x56, 0x16, 0x60, 0xc0, 	// t (19)
	0x9, 0xd, 0xf, 0x5c, 0x87, 0x42, 0x7d, 0x23, 0x58, 0x1d, 0xa1, 0x5a, 0x15, 0x81, 0xd6, 0x94, 0x2f, 0x5e, 	// u (20)
	0x9, 0xe, 0xf, 0x15, 0xa2, 0x56, 0x3d, 0x24, 0xd2, 0x4d, 0x24, 0x54, 0x2d, 0x3, 0xcc, 0x44, 0x84, 0xc6, 0x4c, 0xc3, 0x52, 0x1f, 0x60, 	// v (21)
	0x9, 0x14, 0xf, 0x1d, 0x83, 0x52, 0x54, 0xe5, 0xd0, 0x4d, 0x42, 0xce, 0x44, 0x65, 0xc2, 0x54, 0xa3, 0x52, 0x4c, 0xe6, 0x4e, 0x55, 0x23, 0x50, 0x3c, 0x85, 0x42, 0x5c, 0x83, 0xd0, 0x25, 0x60, 0xdc, 	// w (22)
	0x9, 0xe, 0xf, 0xd, 0xa1, 0xd4, 0x3c, 0xe4, 0xc8, 0x34, 0x23, 0x42, 0x2c, 0x85, 0x4e, 0x35, 0x4, 0x4c, 0x5c, 0x43, 0x46, 0x2c, 0x22, 0x4c, 0x45, 0x22, 0x58, 0x15, 0xe0, 	// x (23)
	0x9, 0xe, 0x14, 0xe, 0x62, 0x5a, 0x55, 0x46, 0xce, 0x1c, 0x65, 0x48, 0x1c, 0xc7, 0x52, 0x55, 0x44, 0x52, 0x45, 0x24, 0x52, 0x4d, 0x63, 0x5c, 0x1f, 0xe3, 0x0, 	// y (24)
	0x9, 0xd, 0xf, 0x68, 0x94, 0x8d, 0x40, 0xf3, 0x91, 0x30, 0x90, 0x89, 0x20, 0xb1, 0x9, 0x18, 0xb1, 0x89, 0x10, 0xb2, 0x13, 0x31, 0x13, 0x8f, 0x40, 0xb5, 0x9, 0x58, 0x50, 	// z (25)
	0x15, 0x4, 0x7, 0x1c, 0x47, 0xc2, 0x1c, 0x80, 	// , (26)
	0x4, 0x1a, 0x14, 0x16, 0x43, 0x5c, 0x55, 0x66, 0xd6, 0x6d, 0x85, 0x5c, 0x35, 0x84, 0x52, 0x5c, 0xa5, 0xca, 0x5d, 0x4, 0xd6, 0x2d, 0xe3, 0xda, 0x5d, 0x85, 0xd8, 0x65, 0x85, 0x5c, 0x35, 0x84, 0x4e, 0x64, 0x86, 0x4a, 0x65, 0x4, 0x58, 0x27, 0xe2, 0x80, 	// W (27)
};


const gfx_font_t arial_20 PROGMEM = {arial_20_index_index, arial_20_index, arial_20_bitmap, 30, 28};