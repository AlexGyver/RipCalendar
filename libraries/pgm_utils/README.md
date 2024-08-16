[![latest](https://img.shields.io/github/v/release/GyverLibs/pgm_utils.svg?color=brightgreen)](https://github.com/GyverLibs/pgm_utils/releases/latest/download/pgm_utils.zip)
[![PIO](https://badges.registry.platformio.org/packages/gyverlibs/library/pgm_utils.svg)](https://registry.platformio.org/libraries/gyverlibs/pgm_utils)
[![Foo](https://img.shields.io/badge/Website-AlexGyver.ru-blue.svg?style=flat-square)](https://alexgyver.ru/)
[![Foo](https://img.shields.io/badge/%E2%82%BD%24%E2%82%AC%20%D0%9F%D0%BE%D0%B4%D0%B4%D0%B5%D1%80%D0%B6%D0%B0%D1%82%D1%8C-%D0%B0%D0%B2%D1%82%D0%BE%D1%80%D0%B0-orange.svg?style=flat-square)](https://alexgyver.ru/support_alex/)
[![Foo](https://img.shields.io/badge/README-ENGLISH-blueviolet.svg?style=flat-square)](https://github-com.translate.goog/GyverLibs/pgm_utils?_x_tr_sl=ru&_x_tr_tl=en)  

[![Foo](https://img.shields.io/badge/ПОДПИСАТЬСЯ-НА%20ОБНОВЛЕНИЯ-brightgreen.svg?style=social&logo=telegram&color=blue)](https://t.me/GyverLibs)

# pgm_utils
Набор удобных инструментов для работы с PROGMEM, C++ обёртка на стандартные pgm-функции
- Одна функция для чтения любых данных
- Чтение многомерных массивов
- Чтение массива строк

### Совместимость
Совместима со всеми Arduino платформами (используются Arduino-функции)

## Содержание
- [Использование](#usage)
- [Версии](#versions)
- [Установка](#install)
- [Баги и обратная связь](#feedback)

<a id="usage"></a>

## Использование
### Макросы и функции
```cpp
// синоним const __FlashStringHelper*
FSTR

// преобразовать PGM_P в FSTR
FPSTR(x)

// поместить одиночное значение val типа T в PROGMEM под именем name
PGM_VAL(T, name, val)

// поместить одиночное значение val типа T (класс, структура) в PROGMEM под именем name, передать список для инициализации
PGM_STRUCT(T, name, ...)

// поместить строку str в PROGMEM под именем name
PGM_STR(name, str)

// поместить строки в PROGMEM и в список указателей под именем name
PGM_STR_LIST(name, ...)
PGM_STR_LIST_STATIC(name, ...)

// поместить строки в PROGMEM и в список указателей + создать объект StringList с именем name
// создаст progmem массив name_list и строки name_list_0, ... name_list_n
PGM_STR_LIST_OBJ(name, ...)
PGM_STR_LIST_OBJ_STATIC(name, ...)

// создать объект pgm::StringList с посчитанным количеством строк
MAKE_STR_LIST(name)

// поместить массив типа T в PROGMEM под именем name
PGM_ARRAY(T, name, ...)

// поместить массивы типа T в PROGMEM массив указателей под именем name
PGM_ARRAY_LIST(T, name, ...)

// создать объект pgm::Array типа T с посчитанной длиной массива
MAKE_ARRAY(T, name)

// создать PROGMEM массив типа T и объект name класса pgm::Array из него
// создаст progmem массив name_arr
PGM_ARRAY_OBJ(T, name, ...)

// прочитать данные любого типа
T pgm_read(const T* ptr);
```

### Классы
#### `template <typename T> pgm::Array`
Чтение одномерного массива

```cpp
Array(const T* arr, size_t len = 0);

// длина массива. 0 если не указана при инициализации
size_t length();

// получить значение по индексу
T operator[](int idx);
```

#### `template <typename T> pgm::ArrayList`
Чтение массива из массива указателей на массивы

```cpp
ArrayList(const T** arr, size_t len = 0);

// длина массива. 0 если не указана при инициализации
size_t length();

// прочитать массив как pgm::Array по индексу
Array<T> operator[](int idx);
```

#### `pgm::PString`
Работа с PROGEMEM строкой

```cpp
PString(PGM_P str, size_t len = 0);

// напечатать
size_t printTo(Print& p);

// длина строки
size_t length();

// вывести в char[]
void toStr(char* buf);

// вывести в String
String toString();

// сравнить со строкой
bool compare(const char* str);
bool operator==(const char* str);

// сравнить со строкой
bool compare(const String& str);
bool operator==(const String& str);

// получить как FlashStringHelper*
FSTR f_str();

// получить символ
char operator[](int idx);

operator PGM_P();
operator FSTR();
PGM_P pstr;
```

#### `pgm::StringList`
Работа с массивом строк из массива указателей

```cpp
StringList(const char** arr, size_t len = 0);

// длина массива. 0 если не указана при инициализации
size_t length();

// получить строку
PString operator[](int idx);
```

### Примечание
`PGM_STR_LIST(name, "str1", "str2", "str3")` разворачивается в:
```cpp
const char name_0[] PROGMEM = "str1";
const char name_1[] PROGMEM = "str2";
const char name_2[] PROGMEM = "str3";
const char* const name[] = {name_0, name_1, name_2};
```
> Максимальное количество строк - `512`

### Примеры
#### Значения
```cpp
PGM_VAL(int, vali, 123);
PGM_VAL(float, valf, 3.14);

struct Test {
  byte i;
  char str[10];
};
PGM_STRUCT(Test, ptest, 10, "test");

void foo() {
  Serial.println(pgm_read(&vali));  // 123
  Serial.println(pgm_read(&valf));  // 3.14

  Test t = pgm_read(&ptest);
  Serial.println(t.i);    // 10
  Serial.println(t.str);  // test
}
```

#### Строки
```cpp
PGM_STR(pgmstr, "hello");

void foo() {
  pgm::PString pstr(pgmstr);
  Serial.println(pstr);  //  hello
  Serial.println(pstr.length());  // 5
  for (int i = 0; i < pstr.length(); i++) {
    Serial.print(pstr[i]);
  }
  Serial.println();

  // при работе со String используй f_str()!
  // это оптимальнее всего
  String s = pgmstr.f_str();
  s += pgmstr.f_str();
}
```

#### Массивы
```cpp
PGM_ARRAY(byte, pgmarrb, 1, 2, 3);              // pgm массив
PGM_ARRAY(int, pgmarri, 123, 456, 789);         // pgm массив
PGM_ARRAY_OBJ(float, arrf, 1.12, 2.34, 3.45);   // массив + объект pgm::Array

void foo() {
  // длина неизвестна
  pgm::Array<byte> arrb(pgmarrb);
  Serial.println(arrb[1]); // 2
  
  // длина посчитается в MAKE
  pgm::Array<int> arri = MAKE_ARRAY(int, pgmarri);
  Serial.println(arri[1]);        // 456
  Serial.println(arri.length());  // 3
 
  // готовый объект
  Serial.println(arrf[1]);  // 2.34
}
```

#### Массивы строк
```cpp
PGM_STR_LIST(pstrlist, "string 1", "kek", "hello");
PGM_STR_LIST_OBJ(pstrlist_obj, "str1", "str2", "str3");

void foo() {
  pgm::StringList list(pstrlist);
  // pgm::StringList list = MAKE_STR_LIST(pstrlist);  // тут длина известна
  Serial.println(list.length());
  Serial.println(list[1]);
  Serial.println(list[1].length());
  Serial.println(list[0] == "string 1");

  // str1, str2, str3
  for (int i = 0; i < pstrlist_obj.length(); i++) {
    Serial.println(pstrlist_obj[i]);
  }
}
```

<a id="versions"></a>

## Версии
- v1.0

<a id="install"></a>
## Установка
- Библиотеку можно найти по названию **pgm_utils** и установить через менеджер библиотек в:
    - Arduino IDE
    - Arduino IDE v2
    - PlatformIO
- [Скачать библиотеку](https://github.com/GyverLibs/pgm_utils/archive/refs/heads/main.zip) .zip архивом для ручной установки:
    - Распаковать и положить в *C:\Program Files (x86)\Arduino\libraries* (Windows x64)
    - Распаковать и положить в *C:\Program Files\Arduino\libraries* (Windows x32)
    - Распаковать и положить в *Документы/Arduino/libraries/*
    - (Arduino IDE) автоматическая установка из .zip: *Скетч/Подключить библиотеку/Добавить .ZIP библиотеку…* и указать скачанный архив
- Читай более подробную инструкцию по установке библиотек [здесь](https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Обновление
- Рекомендую всегда обновлять библиотеку: в новых версиях исправляются ошибки и баги, а также проводится оптимизация и добавляются новые фичи
- Через менеджер библиотек IDE: найти библиотеку как при установке и нажать "Обновить"
- Вручную: **удалить папку со старой версией**, а затем положить на её место новую. "Замену" делать нельзя: иногда в новых версиях удаляются файлы, которые останутся при замене и могут привести к ошибкам!

<a id="feedback"></a>

## Баги и обратная связь
При нахождении багов создавайте **Issue**, а лучше сразу пишите на почту [alex@alexgyver.ru](mailto:alex@alexgyver.ru)  
Библиотека открыта для доработки и ваших **Pull Request**'ов!

При сообщении о багах или некорректной работе библиотеки нужно обязательно указывать:
- Версия библиотеки
- Какой используется МК
- Версия SDK (для ESP)
- Версия Arduino IDE
- Корректно ли работают ли встроенные примеры, в которых используются функции и конструкции, приводящие к багу в вашем коде
- Какой код загружался, какая работа от него ожидалась и как он работает в реальности
- В идеале приложить минимальный код, в котором наблюдается баг. Не полотно из тысячи строк, а минимальный код