#pragma once
#include <Arduino.h>

namespace gfx {

// определить длину строки с любыми символами (в т.ч. русскими)
uint16_t strlen_fix(const char* str, bool pgm = 0);

// определить длину PGM строки с любыми символами (в т.ч. русскими)
uint16_t strlen_fix_P(PGM_P str);

}