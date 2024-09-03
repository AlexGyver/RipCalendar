#pragma once
#include <Arduino.h>

// тикающий unix - встроенный таймер на 1 секунду

#include "core/StampCore.h"

class StampTicker : public StampCore {
#ifdef __AVR__
    typedef void (*SecondHandler)();
#else
    typedef std::function<void()> SecondHandler;
#endif

   public:
    // установить unix и миллисекунды
    StampTicker(uint32_t unix = 0, uint16_t ms = 0) {
        update(unix, ms);
    }

    // установить unix и миллисекунды
    void update(uint32_t unix, uint16_t ms = 0, bool skipTicks = false) {
        if (unix) {
            if (_unix && skipTicks) {
                _diff = unix - _unix;
            } else {
                _unix = unix;
                _diff = 0;
            }
            _tmr = millis() - ms;
        }
    }

    // пропустить отставшие секунды (вызывать после update)
    void skipTicks() {
        if (_diff) {
            _unix += _diff;
            _diff = 0;
        }
    }

    // время синхронизировано
    inline bool synced() {
        return _unix;
    }

    // время синхронизировано
    explicit operator bool() {
        return synced();
    }

    // секундный флаг
    inline bool newSecond() {
        return _ready;
    }

    // тикер, вызывать в loop. Вернёт true на новой секунде
    bool tick() {
        if (_ready) _ready = 0;
        if (_unix && (millis() - _tmr >= 1000 || _diff > 0)) {
            if (_diff) {
                if (_diff > 0) {
                    _unix++;
                    _diff--;
                } else {
                    _tmr += 1000;
                    _diff++;
                    return 0;
                }
            } else {
                _unix++;
                _tmr += 1000;
            }
            _ready = 1;
            if (_cb) _cb();
            return 1;
        }
        return 0;
    }

    // подключить функцию-обработчик новой секунды (вида void f())
    void attachSecond(SecondHandler handler) {
        _cb = handler;
    }

    // отключить функцию-обработчик новой секунды
    void detachSecond() {
        _cb = nullptr;
    }

    // получить текущий unix
    uint32_t getUnix() {
        return _unix;
    }

    // получить миллисекунды текущей секунды
    uint16_t ms() {
        return synced() ? ((millis() - _tmr) % 1000ul) : 0;
    }

    // получить миллисекунды с epoch
    uint64_t unixMs() {
        return synced() ? (getUnix() * 1000ull + ms()) : 0;
    }

    inline bool ready() __attribute__((deprecated)) {
        return _ready;
    }

   private:
    uint32_t _unix = 0;
    uint32_t _tmr = 0;
    int16_t _diff = 0;
    bool _ready = 0;
    SecondHandler _cb = nullptr;
};