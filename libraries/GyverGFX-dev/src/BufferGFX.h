#pragma once
#include <Arduino.h>
#include <GyverGFX.h>

// TODO запоминать графницы fastSet()

class BufferGFX : public GyverGFX, public gfx::buffer_t {
   public:
    BufferGFX(uint16_t width, uint16_t height) : GyverGFX(width, height), gfx::buffer_t(width, height) {
        _buffer = new uint8_t[width * _hbytes];
        clear();
    }
    ~BufferGFX() {
        delete[] _buffer;
    }

    // 0, 1, 2, 3 по часовой начиная с верха
    void setRotation(uint8_t rot) {
        _rot = rot;
        if (_rot == 1 || _rot == 3) GyverGFX::size(_height, _width);
        else GyverGFX::size(_width, _height);
    }

    BufferGFX(BufferGFX& b) {
        move(b);
    }
    void operator=(BufferGFX& b) {
        move(b);
    }

#if __cplusplus >= 201103L
    BufferGFX(BufferGFX&& b) noexcept {
        move(b);
    }
    void operator=(BufferGFX&& b) noexcept {
        move(b);
    }
#endif

    void move(BufferGFX& b) {
        delete[] _buffer;
        _buffer = b._buffer;
        b._buffer = nullptr;
    }

   protected:
    using gfx::buffer_t::bufGet;
    using gfx::buffer_t::bufSet;

   private:
    uint8_t _rot = 0;
    using gfx::buffer_t::_buffer;
    using gfx::buffer_t::_hbytes;
    using gfx::buffer_t::_height;
    using gfx::buffer_t::_width;

    void _rotXY(int& x, int& y) {
        switch (_rot) {
            case 1: {
                int yy = y;
                y = x;
                x = _width - yy - 1;
            } break;
            case 2:
                x = _width - x - 1;
                y = _height - y - 1;
                break;
            case 3: {
                int yy = y;
                y = _height - x - 1;
                x = yy;
            } break;
        }
    }

    // установить пиксель цветом getColor(), всегда вызывается внутри дисплея
    void fastSet(int x, int y) {
        if (!_buffer) return;
        _rotXY(x, y);
        gfx::buffer_t::bufSet(x, y, getColor());
    }

    // получить пиксель, всегда вызывается внутри дисплея
    uint16_t fastGet(int x, int y) {
        if (!_buffer) return 0;
        _rotXY(x, y);
        return gfx::buffer_t::bufGet(x, y);
    }

    // // горизонтальная линия цветом getColor(), всегда слева направо и внутри дисплея
    // void fastLineH(int y, int x0, int x1) {
    //     for (int x = x0; x <= x1; x++) fastSet(x, y);
    // }

    // // вертикальная линия цветом getColor(), всегда сверху вниз и внутри дисплея
    // void fastLineV(int x, int y0, int y1) {
    //     for (int y = y0; y <= y1; y++) fastSet(x, y);
    // }

    // // четырёхугольник заливка цветом getColor(), всегда вызывается внутри дисплея
    // void fastRect(int x0, int y0, int x1, int y1) {
    //     for (int x = x0; x <= x1; x++) fastLineV(x, y0, y1);
    // }

    // // вывести столбик 8 бит (MSB снизу) цветом getColor(). x всегда внутри дисплея, (y >= -7) и (y < height)
    // void fastByte(int x, int y, uint8_t mask) {
    //     for (uint8_t i = 0; i < 8; i++) {
    //         if (y >= 0 && y < _h && (mask & 1)) fastSet(x, y);
    //         mask >>= 1;
    //         y++;
    //     }
    // }

    // заливка всего экрана
    void fastFill(uint16_t color) {
        if (_buffer) memset(_buffer, color, _width * _hbytes);
    }
};