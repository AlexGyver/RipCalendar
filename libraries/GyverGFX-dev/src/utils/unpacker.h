#pragma once
#include <Arduino.h>
#include <StreamIO.h>

// aaaaaabb
// bbbbcccc
// ccdddddd

namespace gfx {

class Unpacker : public Reader {
   public:
    struct Chunk {
        bool value;
        uint8_t size;
    };

    Unpacker(Reader& reader, uint16_t height) : Reader(reader), _height(height) {}
    Unpacker(Stream& stream, uint16_t len, uint16_t height) : Reader(stream, len), _height(height) {}
    Unpacker(const uint8_t* data, uint16_t len, uint16_t height, bool pgm = true) : Reader(data, len, pgm), _height(height) {}

    Chunk readChunk() {
        uint8_t chunk = 0;

        switch ((_shift++) & 0b11) {
            case 0:
                chunk = (read() >> 2);
                break;
            case 1:
                chunk = (current() << 4) & 0b00110000;
                chunk |= (read() >> 4);
                break;
            case 2:
                chunk = (current() << 2) & 0b00111100;
                chunk |= (read() >> 6);
                break;
            case 3:
                chunk = current() & 0b00111111;
                break;
        }

        return Chunk{bool(chunk & 1), uint8_t(chunk >> 1)};
    }

    inline uint16_t height() {
        return _height;
    }

   protected:
    uint16_t _height = 0;
    uint8_t _shift = 0;

   private:
};

}  // namespace gfx
