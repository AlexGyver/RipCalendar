#include <Arduino.h>

#include "pgm_utils.h"

PGM_VAL(int, vali, 123);
PGM_VAL(float, valf, 3.14);

struct Test {
    byte i;
    char str[10];
};

PGM_STRUCT(Test, ptest, 10, "test");

PGM_STR(pgmstr, "hello");

PGM_ARRAY(byte, pgmarrb, 1, 2, 3);
PGM_ARRAY(int, pgmarri, 123, 456, 789);
PGM_ARRAY_OBJ(float, arrf, 1.12, 2.34, 3.45);

PGM_ARRAY(byte, parr1, 1, 2, 3);
PGM_ARRAY(byte, parr2, 4, 5, 6);
PGM_ARRAY(byte, parr3, 7, 8, 9);
PGM_ARRAY_LIST(byte, plist, parr1, parr2, parr3);

PGM_STR_LIST(pstrlist, "string 1", "kek", "hello");
PGM_STR_LIST_OBJ(pstrlist_obj, "str1", "str2", "str3");

void setup() {
    Serial.println(pgm_read(&vali));  // 123
    Serial.println(pgm_read(&valf));  // 3.14

    Test t = pgm_read(&ptest);
    Serial.println(t.i);
    Serial.println(t.str);

    pgm::PString pstr(pgmstr);
    Serial.println(pstr);
    Serial.println(pstr.length());
    for (int i = 0; i < pstr.length(); i++) {
        Serial.print(pstr[i]);
    }
    Serial.println();

    pgm::Array<byte> arrb(pgmarrb);
    Serial.println(arrb[1]);

    pgm::Array<int> arri = MAKE_ARRAY(int, pgmarri);
    Serial.println(arri[1]);
    Serial.println(arri.length());

    Serial.println(arrf[1]);

    pgm::ArrayList<byte> arrlist(plist);
    Serial.println(arrlist[0][0]);  // 1
    Serial.println(arrlist[1][1]);  // 5
    Serial.println(arrlist[2][2]);  // 9

    pgm::Array<byte> row1 = arrlist[1];
    Serial.println(row1[0]);  // 4
    Serial.println(row1[1]);  // 5
    Serial.println(row1[2]);  // 6

    pgm::StringList list(pstrlist);
    // pgm::StringList list = MAKE_STR_LIST(pstrlist);
    Serial.println(list.length());
    Serial.println(list[1]);
    Serial.println(list[1].length());
    Serial.println(list[0] == "string 1");

    // str1, str2, str3
    for (int i = 0; i < pstrlist_obj.length(); i++) {
        Serial.println(pstrlist_obj[i]);
    }
}

void loop() {
}