#pragma once
#include <Arduino.h>
#include <BufferGFX.h>

#define ASC_TAB 0x09
#define ASC_LF 0x0A
#define ASC_CR 0x0D
#define ASC_HT 0x09
#define ASC_FF 0x0C
#define ASC_ESC 0x1B
#define ASC_GS 0x1D
#define ASC_FS 0x1C
#define ASC_DC2 0x12

#define FONT_B bit(0)
#define FONT_REVERSE bit(1)
#define FONT_FLIP bit(2)
#define FONT_EMPH bit(3)
#define FONT_DOUBLE_H bit(4)
#define FONT_DOUBLE_W bit(5)
#define FONT_DELLINE bit(6)

class Printer : public Print {
   public:
    Printer(Stream& stream) : stream(stream) {}

    size_t write(uint8_t data) {
        _write(data);
        return 1;
    }

    void feed(uint8_t lines = 1) {
        while (lines--) println();
    }

    void printBuffer(gfx::buffer_t& gfx, bool TTL_mode) {
        // TTL
        if (TTL_mode) {
            uint16_t width = (gfx.bufWidth() + 8 - 1) / 8;
            uint16_t height = gfx.bufHeight();

            _write(ASC_GS);
            _write('v');
            _write('0');
            _write('0');
            _write(width & 0xFF);
            _write((width >> 8) & 0xFF);
            _write(height & 0xFF);
            _write((height >> 8) & 0xFF);

            for (uint16_t y = 0; y < height; y++) {
                for (uint16_t x = 0; x < gfx.bufWidth();) {
                    uint8_t b = 0;
                    for (uint8_t bb = 0; bb < 8; bb++) {
                        b <<= 1;
                        b |= gfx.bufGet(x, y);
                        x++;
                    }
                    _write(b);
                }
                delay(0);
            }

            // RS232
        } else {
            for (uint16_t h = 0; h < gfx.bufHeight(); h++) {
                if (h % 255 == 0) {
                    _beginBitmap(gfx.bufWidth(), min(gfx.bufHeight() - h, 0xff));
                }

                for (int x = 0; x < gfx.bufWidth();) {
                    uint8_t b = 0;
                    for (uint8_t bb = 0; bb < 8; bb++) {
                        b <<= 1;
                        b |= gfx.bufGet(x, h);
                        x++;
                    }
                    _write(b);
                }
                delay(0);
            }
        }
    }

    void begin() {
        wake();
        init();
    }

    void font(uint8_t mode) {
        _write(ASC_ESC, '!', mode);
    }
    void setCharTable(uint8_t table) {
        _write(ASC_ESC, 't', table);
    }

    void config(uint8_t dots = 7, uint8_t time = 80, uint8_t interval = 2) {
        _write(ASC_ESC, '7', dots, time, interval);
    }

    void init() {
        _write(ASC_ESC, '@');
    }

    void wake() {
        _write(0xff);
        delay(60);
    }

    void sleep() {
        _write(ASC_ESC, '8', 1, 0);
    }

    void statusBack(bool rts = 1, bool asb = 0) {
        _write(ASC_GS, 'a', (asb << 2) | (rts << 5));
    }

   private:
    Stream& stream;

    void _write(uint8_t b0) {
        stream.write(b0);
    }
    void _write(uint8_t b0, uint8_t b1) {
        stream.write(b0);
        stream.write(b1);
    }
    void _write(uint8_t b0, uint8_t b1, uint8_t b2) {
        stream.write(b0);
        stream.write(b1);
        stream.write(b2);
    }
    void _write(uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3) {
        stream.write(b0);
        stream.write(b1);
        stream.write(b2);
        stream.write(b3);
    }
    void _write(uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4) {
        stream.write(b0);
        stream.write(b1);
        stream.write(b2);
        stream.write(b3);
        stream.write(b4);
    }

    void _beginBitmap(uint16_t w, uint8_t h) {
        _write(ASC_DC2, '*', h, w / 8);
    }
};