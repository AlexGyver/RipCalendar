#pragma once
#include <Arduino.h>
#include <BufferGFX.h>

class StreamDisplay : public BufferGFX {
   public:
    StreamDisplay(uint16_t width, uint16_t height, Stream* stream = nullptr) : BufferGFX(width, height), stream(stream) {}

    void update() {
        if (!stream) return;
        for (uint16_t y = 0; y < bufHeight(); y++) {
            for (uint16_t x = 0; x < bufWidth(); x++) {
                stream->print(bufGet(x, y) ? "[]" : "  ");
            }
            stream->println();
        }
    }

    void begin() {}

   private:
    Stream* stream = nullptr;

    using gfx::buffer_t::bufGet;
    using gfx::buffer_t::bufSet;
};