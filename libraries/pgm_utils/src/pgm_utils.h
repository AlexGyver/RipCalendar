#pragma once
#include <Arduino.h>
#include <FOR_MACRO.h>
#include <limits.h>

// =================== PUT ===================

// VAL

// поместить одиночное значение val типа T в PROGMEM под именем name
#define PGM_VAL(T, name, val) const T name PROGMEM = val;

// поместить одиночное значение val типа T (класс, структура) в PROGMEM под именем name, передать список для инициализации
#define PGM_STRUCT(T, name, ...) const T name PROGMEM = {__VA_ARGS__};

// =================== STR ===================

// поместить строку str в PROGMEM под именем name
#define PGM_STR(name, str) const char name[] PROGMEM = str;

#define _MAKE_STR(N, i, name, val) const char name##_##i[] PROGMEM = val;
#define _MAKE_STR_STATIC(N, i, name, val) static const char name##_##i[] PROGMEM = val;
#define _MAKE_LIST(N, i, name, val) name##_##i,

// поместить строки в PROGMEM и в список указателей под именем name
#define PGM_STR_LIST(name, ...)             \
    FOR_MACRO(_MAKE_STR, name, __VA_ARGS__) \
    const char* const name[] PROGMEM = {FOR_MACRO(_MAKE_LIST, name, __VA_ARGS__)};

// поместить строки в PROGMEM и в список указателей под именем name
#define PGM_STR_LIST_STATIC(name, ...)             \
    FOR_MACRO(_MAKE_STR_STATIC, name, __VA_ARGS__) \
    const char* const name[] PROGMEM = {FOR_MACRO(_MAKE_LIST, name, __VA_ARGS__)};

// поместить строки в PROGMEM и в список указателей + создать объект StringList с именем name
#define PGM_STR_LIST_OBJ(name, ...)        \
    PGM_STR_LIST(name##_list, __VA_ARGS__) \
    pgm::StringList name(name##_list, sizeof(name##_list) / sizeof(const char*));

// поместить строки в PROGMEM и в список указателей + создать объект StringList с именем name
#define PGM_STR_LIST_OBJ_STATIC(name, ...)        \
    PGM_STR_LIST_STATIC(name##_list, __VA_ARGS__) \
    pgm::StringList name(name##_list, sizeof(name##_list) / sizeof(const char*));

// создать объект pgm::StringList с посчитанным количеством строк
#define MAKE_STR_LIST(name) pgm::StringList(name, sizeof(name) / sizeof(const char*));

// =================== ARR ===================

// поместить массив типа T в PROGMEM под именем name
#define PGM_ARRAY(T, name, ...) const T name[] PROGMEM = {__VA_ARGS__};

// поместить массивы типа T в PROGMEM массив указателей под именем name
#define PGM_ARRAY_LIST(T, name, ...) const T* const name[] PROGMEM = {__VA_ARGS__};

// создать объект pgm::Array типа T с посчитанной длиной массива
#define MAKE_ARRAY(T, name) pgm::Array<T>(name, sizeof(name) / sizeof(T));

// создать PROGMEM массив типа T и объект name класса pgm::Array из него
#define PGM_ARRAY_OBJ(T, name, ...)       \
    PGM_ARRAY(T, name##_arr, __VA_ARGS__) \
    pgm::Array<T> name(name##_arr, sizeof(name##_arr) / sizeof(T));

// =================== CAST ===================

#ifndef FSTR
#define FSTR const __FlashStringHelper*
#endif

#ifndef FPSTR
#define FPSTR(x) (reinterpret_cast<FSTR>(x))
#endif

// =================== PGM_READ ===================

// прочитать данные любого типа
template <typename T>
T pgm_read(const T* ptr) {
    T res;
    memcpy_P(&res, ptr, sizeof(T));
    return res;
}

#define _MAKE_READ_F(T, f)            \
    template <>                       \
    inline T pgm_read(const T* ptr) { \
        return (T)f(ptr);             \
    }

_MAKE_READ_F(bool, pgm_read_byte)
_MAKE_READ_F(char, pgm_read_byte)
_MAKE_READ_F(signed char, pgm_read_byte)
_MAKE_READ_F(unsigned char, pgm_read_byte)
_MAKE_READ_F(short, pgm_read_word)
_MAKE_READ_F(unsigned short, pgm_read_word)
_MAKE_READ_F(long, pgm_read_dword)
_MAKE_READ_F(unsigned long, pgm_read_dword)
_MAKE_READ_F(float, pgm_read_float)

#ifdef pgm_read_double
_MAKE_READ_F(double, pgm_read_double)
#endif

#if (UINT_MAX == UINT32_MAX)
_MAKE_READ_F(int, pgm_read_dword)
_MAKE_READ_F(unsigned int, pgm_read_dword)
#else
_MAKE_READ_F(int, pgm_read_word)
_MAKE_READ_F(unsigned int, pgm_read_word)
#endif

// =================== CLASS ===================

namespace pgm {

// чтение одномерного массива
template <typename T>
class Array {
   public:
    Array(const T* arr, size_t len = 0) : _arr(arr), _len(len) {}

    // длина массива. 0 если не указана при инициализации
    size_t length() const {
        return _len;
    }

    // получить значение по индексу
    T operator[](int idx) const {
        return pgm_read(_arr + idx);
    }

   private:
    const T* _arr;
    size_t _len;
};

// чтение массива из массива указателей на массивы
template <typename T>
class ArrayList {
   public:
    ArrayList(const T* const* const arr, size_t len = 0) : _arr(arr), _len(len) {}

    // длина массива. 0 если не указана при инициализации
    size_t length() const {
        return _len;
    }

    // прочитать массив как pgm::Array по индексу
    Array<T> operator[](int idx) const {
        return (const T*)pgm_read_ptr(_arr + idx);
    }

   private:
    const T* const* const _arr;
    size_t _len;
};

// работа с PROGEMEM строкой
class PString : public Printable {
   public:
    PString(PGM_P str, size_t len = 0) : pstr(str), _len(len) {}

    // напечатать
    size_t printTo(Print& p) const {
        return p.print(FPSTR(pstr));
    }

    // длина строки
    size_t length() {
        return _len ? _len : _len = strlen_P(pstr);
    }

    // вывести в char[]
    void toStr(char* buf) const {
        strcpy_P(buf, pstr);
    }

    // вывести в String
    String toString(char* buf) const {
        return String(f_str());
    }

    // сравнить со строкой
    bool compare(const char* str) const {
        return !strcmp_P(str, pstr);
    }

    bool operator==(const char* str) const {
        return compare(str);
    }

    // сравнить со строкой
    bool compare(const String& str) const {
        return compare(str.c_str());
    }

    bool operator==(const String& str) const {
        return compare(str);
    }

    // получить как FlashStringHelper*
    FSTR f_str() const {
        return FPSTR(pstr);
    }

    // получить символ
    char operator[](int idx) const {
        return pgm_read_byte(pstr + idx);
    }

    operator PGM_P() const {
        return pstr;
    }

    operator FSTR() const {
        return FPSTR(pstr);
    }

    operator String() const {
        return f_str();
    }

    // указатель на строку
    PGM_P pstr;

   private:
    size_t _len = 0;
};

// работа с массивом строк из массива указателей
class StringList {
   public:
    StringList(const char* const* const arr, size_t len = 0) : _arr(arr), _len(len) {}

    // длина массива. 0 если не указана при инициализации
    size_t length() const {
        return _len;
    }

    // получить строку
    PString operator[](int idx) const {
        return (PGM_P)pgm_read_ptr(_arr + idx);
    }

   private:
    const char* const* const _arr;
    size_t _len;
};

}  // namespace pgm
