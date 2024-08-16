#pragma once
#include <Arduino.h>

struct gfx_font_t {
    const uint8_t* index_index;
    const uint16_t* index;
    const uint8_t* bitmap;
    uint8_t lineHeight;
    uint8_t indexLength;
};

namespace gfx {

struct Glyph {
    Glyph(const gfx_font_t& font, int16_t idx) {
        if (!font.index_index) return;
        const void* index_p = memchr_P(font.index_index, idx, font.indexLength);
        if (!index_p) return;
        uint16_t index = pgm_read_word(&font.index[(const uint8_t*)index_p - font.index_index]);
        data = font.bitmap + index;
        offset = pgm_read_byte(data++);
        width = pgm_read_byte(data++);
        height = pgm_read_byte(data++);
        uint16_t next = pgm_read_word(&font.index[(const uint8_t*)index_p - font.index_index + 1]);
        len = next - index - 3;
    }

    operator bool() const {
        return data;
    }

    const uint8_t* data = nullptr;
    uint8_t offset = 0;
    uint8_t width = 0;
    uint8_t height = 0;
    uint16_t len = 0;
};

}  // namespace gfx