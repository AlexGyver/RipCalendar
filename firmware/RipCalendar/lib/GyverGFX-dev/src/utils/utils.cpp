#include "utils.h"

namespace gfx {

// определить длину строки с любыми символами (в т.ч. русскими)
uint16_t strlen_fix(const char* str, bool pgm) {
    uint16_t count = 0;
    while (true) {
        char c = pgm ? pgm_read_byte(str) : *str;
        if (!c) break;
        if ((c & 0xc0) != 0x80) count++;
        str++;
    }
    return count;
}

// определить длину PGM строки с любыми символами (в т.ч. русскими)
uint16_t strlen_fix_P(PGM_P str) {
    return strlen_fix(str, true);
}

}