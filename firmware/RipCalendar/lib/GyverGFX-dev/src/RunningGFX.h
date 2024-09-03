#pragma once
#include <Arduino.h>

// движок бегущей строки для GyverGFX

#include "GyverGFX.h"

#define RG_IDLE 0
#define RG_MOVE 1
#define RG_FINISH 2

class RunningGFX : public gfx::Printer {
   public:
    RunningGFX(GyverGFX* gfx) : _gfx(gfx) {
        cfg.bound0 = cfg.y = 0;
        cfg.bound1 = _gfx->width();
        cfg.autoline = 0;
    }

    // установить текст const char*
    void setText(const char* str) {
        _str = str;
        _pgm = 0;
        _len = _gfx->strlen_fix(_str) * 6;
    }

    // установить текст const char*
    void setText(const __FlashStringHelper* str) {
        setText_P((PGM_P)str);
    }

    // установить текст String
    void setText(String& str) {
        setText(str.c_str());
    }

    // установить текст из PROGMEM (глобальный)
    void setText_P(PGM_P str) {
        _str = str;
        _pgm = 1;
        _len = _gfx->strlen_fix_P(_str) * 6;
    }

    // установить окно (x0, x1, y)
    void setWindow(int x0, int x1, int y) {
        setTextBound(x0, x1);
        cfg.y = y;
    }

    // установить скорость (пикселей в секунду)
    void setSpeed(uint16_t pixPerSec) {
        if (!pixPerSec) pixPerSec = 1;
        _prd = 1000 / pixPerSec;
    }

    // запустить бегущую строку с начала
    void start() {
        cfg.x = cfg.bound1 + 1;
        resume();
    }

    // остановить бегущую строку
    void stop() {
        _run = 0;
    }

    // продолжить движение с момента остановки
    void resume() {
        _tmr = millis();
        _run = 1;
    }

    // строка движется
    bool running() {
        return _run;
    }

    // тикер. Вернёт 0 в холостом, 1 при новом шаге, 2 при завершении движения
    // Можно передать false чтобы дисплей не обновлялся сам
    uint8_t tick(bool update = true) {
        if (!_str) return 0;
        if (_run && (uint16_t)((uint16_t)millis() - _tmr) >= _prd) {
            resume();
            return tickManual(update);
        }
        return RG_IDLE;
    }

    // сдвинуть строку на 1 пиксель. Можно передать false чтобы дисплей не обновлялся сам
    uint8_t tickManual(bool update = true) {
        if (!_str) return 0;
        gfx::print_t cfgb = _gfx->cfg;
        _gfx->cfg = cfg;
        if (_pgm) _gfx->print((const __FlashStringHelper*)_str);
        else _gfx->print(_str);
        _gfx->cfg = cfgb;
        if (update) _gfx->update();
        if (--cfg.x <= cfg.bound0 - (int)(_len * cfg.scale)) {
            start();
            return RG_FINISH;
        }
        return RG_MOVE;
    }

   private:
    GyverGFX* _gfx = nullptr;
    const char* _str = nullptr;
    bool _pgm = 0;
    bool _run = 0;
    uint16_t _tmr = 0, _prd = 50;
    uint16_t _len = 0;

    using gfx::Printer::autoPrintln;
    using gfx::Printer::setCursor;
    using gfx::Printer::setTextBound;
};