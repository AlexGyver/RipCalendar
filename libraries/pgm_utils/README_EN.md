This is an automatic translation, may be incorrect in some places. See sources and examples!

# pgm_utils
A set of convenient tools for working with Progmem, C ++ wrapping for standard PGM functions
- one function for reading any data
- Reading multidimensional arrays
- Reading the array of lines

## compatibility
Compatible with all arduino platforms (used arduino functions)

## Content
- [use] (#usage)
- [versions] (#varsions)
- [installation] (# Install)
- [bugs and feedback] (#fedback)

<a id="usage"> </a>

## Usage
### macros and functions
`` `CPP
// Synonym Constring __flashstringhelper*
FSTR

// Transform pgm_p to fstr
Fpstr (x)

// Place the single value of VAL type t in Progmem under the name NAME
PGM_VAL (T, NAME, VAL)

// Place a single value of VAL type t (class, structure) in Progmem under the name NAME, transfer the list for initialization
Pgm_struct (t, name, ...)

// Place the string string in Progmem under the name NAME
Pgm_str (name, str)

// Place the lines in Progmem and in the list of signs under the name NAME
Pgm_str_list (name, ...)

// Place the lines in Progmem and in the list of signs + create an object Stringlist with the name NAME
// Create a Progmem massif NAME_LIST and lines NAME_LIST_0, ... NAME_LIST_N
Pgm_str_list_obj (name, ...)

// Create an object pgm :: Stringlist with a calculated number of lines
Make_str_list (name)

// Place an array of type t in progmem under the name NAME
Pgm_array (t, name, ...)

// Place arrays of type T in the Progmem array of signs under the name NAME
Pgm_array_list (t, name, ...)

// Create an object pgm :: type T with the calculated array calculated
Make_array (t, name)

// Create a Progmem Massive type T and an object of class PGM :: Array from it
// Create a Progmem massif name_arr
Pgm_array_obj (t, name, ...)

// Read data of any type
T pgm_read (const t* ptr);
`` `

### classes
#### `Template <Typename T> PGM :: Array`
Reading one -dimensional array

`` `CPP
Array (const* arr, size_t len ​​= 0);

// The length of the array.0 If not indicated during initialization
Size_t Length ();

// Get a value by index
T Operator [] (int IDX);
`` `

### `Template <Typename T> PGM :: ArrayList`
Reading an array of array of indicators for arrays

`` `CPP
Arraylist (const t ** arr, size_t len ​​= 0);

// The length of the array.0 If not indicated during initialization
Size_t Length ();

// Read the array as pgm :: Array by index
Array <t> operator [] (int IDX);
`` `

### `pgm :: pstring`
Working with Progemem a line

`` `CPP
Pstring (pgm_p str, size_t len ​​= 0);

// Print
Size_t Printto (Print & P);

// Line length
Size_t Length ();

// Bring to Char []
VOID TOSTR (Char* BUF);

// Bring to String
String Tostring ();

// compare with the line
Bool Compare (Consta Char* str);
Bool Operator == (Consta Char* str);

// compare with the line
Bool Compare (Constation String & STR);
Bool Operator == (COST String & STR);

// Get like flashstringhelper*
Fstr f_str ();

// Get a symbol
Char Operator [] (int IDX);

Operator pgm_p ();
Operator FSTR ();
Pgm_p pstr;
`` `

### `pgm :: stringlist`
Working with an array of array of signs

`` `CPP
Stringlist (const char ** arr, size_t len ​​= 0);

// The length of the array.0 If not indicated during initialization
S.Ize_t Length ();

// Get a line
Pstring Operator [] (int IDX);
`` `

### Note
`Pgm_str_list (name," str1 "," str2 "," str3 ")` unfolds in:
`` `CPP
const char name_0 [] progmem = "str1";
const char name_1 [] progmem = "str2";
const char name_2 [] progmem = "str3";
const char* const name [] = {name_0, name_1, name_2};
`` `
> Maximum number of lines - `128`

### Examples
### values
`` `CPP
Pgm_val (int, vali, 123);
PGM_VAL (FLOAT, VALF, 3.14);

Struct test {
byte i;
Chard [10];
};
Pgm_struct (test, ptest, 10, "test");

VOID FOO () {
Serial.println (pgm_read (& vali));// 123
Serial.println (pgm_read (& valf));// 3.14

Test T = pgm_read (& ptest);
Serial.println (T.I);// 10
Serial.println (T.str);// test
}
`` `

### lines
`` `CPP
PGM_STR (PGMSTR, "HELLO");

VOID FOO () {
PGM :: pstring pstr (pgmstr);
Serial.println (pstr);// Hello
Serial.println (pstr.length ());// 5
for (int i = 0; i <pstr.length (); i ++) {
Serial.print (pstr [i]);
}
Serial.println ();

// When working with String, use f_str ()!
// This is the best of all
String s = pgmstr.f_str ();
s += pgmstr.f_str ();
}
`` `

### MASSIVES
`` `CPP
Pgm_array (byte, pgmarrb, 1, 2, 3);// PGM massif
Pgm_array (int, pgmarri, 123, 456, 789);// PGM massif
Pgm_array_obj (Float, Arrf, 1.12, 2.34, 3.45);// Array + object PGM :: Array

VOID FOO () {
// The length is unknown
PGM :: Array <Byte> arrb (pgmarrb);
Serial.println (arrb [1]);// 2

// length is counted in MAKE
PGM :: Array <THet> arri = make_array (int, pgmarri);
Serial.println (arri [1]);// 456
Serial.println (arri.length ());// 3

// Ready object
Serial.println (arrf [1]);// 2.34
}
`` `

#### Arrays of the lines
`` `CPP
Pgm_str_list (pstrlist, "String 1", "Kek", "Hello");
Pgm_str_list_obj (pstrlist_obj, "str1", "str2", "str3");

VOID FOO () {
PGM :: Stringlist List (Pstrlist);
// pgm :: stringlist list = make_str_list (pstrlist);// here the length is known
Serial.println (list.length ());
Serial.println (list [1]);
Serial.println (list [1] .Length ());
Serial.println (list [0] == "string 1");

// str1, str2, str3
for (int i = 0; i <pstrlist_obj.length (); i ++) {
Serial.println (pstrlist_obj [i]);
}
}
`` `

<a id="versions"> </a>

## versions
- V1.0

<a id="install"> </a>
## Installation
- The library can be found by the name ** pgm_utils ** and installed through the library manager in:
- Arduino ide
- Arduino ide v2
- Platformio
- [download the library] (https://github.com/gyverlibs/pgm_utils/archive/refs/heads/main.zip) .Zip archive for manual installation:
- unpack and put in * C: \ Program Files (X86) \ Arduino \ Libraries * (Windows X64)
- unpack and put in * C: \ Program Files \ Arduino \ Libraries * (Windows X32)
- unpack and put in *documents/arduino/libraries/ *
- (Arduino id) Automatic installation from. Zip: * sketch/connect the library/add .Zip library ... * and specify downloaded archive
- Read more detailed instructions for installing libraries [here] (https://alexgyver.ru/arduino-first/#%D0%A3%D1%81%D1%82%D0%B0%BD%D0%BE%BE%BE%BED0%B2%D0%BA%D0%B0_%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA)
### Update
- I recommend always updating the library: errors and bugs are corrected in the new versions, as well as optimization and new features are added
- through the IDE library manager: find the library how to install and click "update"
- Manually: ** remove the folder with the old version **, and then put a new one in its place.“Replacement” cannot be done: sometimes in new versions, files that remain when replacing are deleted and can lead to errors!

<a id="feedback"> </a>

## bugs and feedback
Create ** Issue ** when you find the bugs, and better immediately write to the mail [alex@alexgyver.ru] (mailto: alex@alexgyver.ru)
The library is open for refinement and your ** pull Request ** 'ow!

When reporting about bugs or incorrect work of the library, it is necessary to indicate:
- The version of the library
- What is MK used
- SDK version (for ESP)
- version of Arduino ide
- Is it correctCranberries are built -in examples that use the functions and designs that lead to a bug in your code
- what code has been loaded, what work was expected from it and how it works in reality
- Ideally, attach the minimum code in which the bug is observed.Not a canvas of a thousand lines, but a minimum code