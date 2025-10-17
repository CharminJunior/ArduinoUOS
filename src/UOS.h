// UOS.h
#ifndef ARDUINOOS_H
#define ARDUINOOS_H

#include <Arduino.h>
#include <EEPROM.h>
// #include <EEPROM_R4T0.h>
// #include <avr/wdt.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// #include <U8g2lib.h>
// #include <type_traits>
#include "tinyexpr.h"

/* ----------------------------
   Definitions and Constants
   ---------------------------- */

// ON / OFF for digitalWrite
#define ON  HIGH
#define OFF LOW

// ลดขนาดลิสต์จาก 100 → 20, ความยาวแต่ละรายการจาก 10 → 12
#define MAX_LIST_ITEMS 5
#define MAX_ITEM_LEN   8

extern int H1;

/* ----------------------------
   Global Variables (Lists)
   ---------------------------- */
// ตอนนี้กิน SRAM เพียง 20×12 + 20×12 = 480 bytes เท่านั้น
extern char hsuorg[MAX_LIST_ITEMS][MAX_ITEM_LEN];
extern char sysItems[MAX_LIST_ITEMS][MAX_ITEM_LEN];
extern int list_count;
extern int list_count_2;

/* ----------------------------
   My_print Class Declaration
   ---------------------------- */
class My_print {
//   U8G2* u8g2 = nullptr;
//   int x = 0, y = 0;

public:
  My_print();

  /** ฟังก์ชัน non‑template **/
  void b(long baud);
  void b(long baud, bool Serial_bit);
//   void b(long baud, int oledType);

  /** ฟั่งชันพิเศษของ จอรุ่น SH1106 **/
//   void set(int X, int Y);
//   void move(int dx, int dy);
//   void oled(int num);
//   void oled(long num);
//   void oled(float num);
//   void oled(const char* s);
//   void oled(int num, int t);
//   void oled(long num, int t); 
//   void oled(float num, int t);
//   void oled(const char* s, int t);
//   void oled(int X, int Y, const char* s);
//   void oled(int X, int Y, int num);
//   void oled(int X, int Y, long num);
//   void oled(int X, int Y, float num);
//   void oled(int X, int Y, const char* s, int t);
//   void oled(int X, int Y, int num, int t);
//   void oled(int X, int Y, long num, int t);
//   void oled(int X, int Y, float num, int t);
//   void clear();
//   void show();
//   void Pixel(int x, int y);
//   void Pixel(int x, int y, int x1, int y1);
  // ฟังก์ชันเลือกฟอนต์จากหมายเลข 1-10
//   void SF(int n);

  /** template text() ทั้ง declaration + definition อยู่ที่นี่เลย **/
  template<typename First>
  void text(const First& t) {
    Serial.print(t);
  }

  // ถ้าต้องการ overload รับหลาย args
  template<typename First, typename... Rest>
  void text(const First& first, const Rest&... rest) {
    Serial.print(first);
    text(rest...);
  }

  bool operator()() const {
    return (bool)Serial;
  }
};

extern My_print p;  // ประกาศตัวแปร global

/* ----------------------------
   I/O Helpers
   ---------------------------- */
bool DRead(int pin, int SetPin);		// อ่าน Digital
bool btn(int pin);				// อ่าน Digital ที่เป็นปุ่ม
int ARead(int ch);				// อ่าน analog
void pwm(uint8_t idx, uint8_t value);		// ส่งค่าเป็น PWM
void outD(int pin, bool value);			// ส่งค่าเป็น Digital
unsigned long gml();
unsigned long gmc();

/* ----------------------------
   EEPROM Helpers (ของเก่า)
   ---------------------------- */
/*
void writeByteToEEPROM(int address, byte value);
byte readByteFromEEPROM(int address);
void writeIntToEEPROM(int address, int value);
int readIntFromEEPROM(int address);
void writeStringToEEPROM(int address, const String &data);
String readStringFromEEPROM(int address);
*/

// ส่วนเสริม **จำเป็น**
bool isValidPosition(int pos, int length);
bool isNumber(String str);
int findValidPosition(String Compilation);

// ----------------------------
// Result Struct Declaration
// ----------------------------
struct Result {
    enum Type { INT, LONG, FLOAT, STRING } type;
    union {
        int iVal;
        long lVal;
        float fVal;
    };
    String sVal;

    // Constructors
    Result() { type = STRING; sVal = ""; }
    Result(int x)   { type = INT; iVal = x; }
    Result(long x)  { type = LONG; lVal = x; }
    Result(float x) { type = FLOAT; fVal = x; }
    Result(String x){ type = STRING; sVal = x; }

    // ตรวจสอบชนิด
    bool isnum()   { return type==INT || type==LONG || type==FLOAT; }
    bool isint()   { return type==INT; }
    bool islong()  { return type==LONG; }
    bool isfloat() { return type==FLOAT; }
    bool isstr()   { return type==STRING; }

    // แปลงเป็น float สำหรับคำนวณ
    float toFloat() const {
        switch(type){
            case INT: return iVal;
            case LONG: return lVal;
            case FLOAT: return fVal;
            default: return 0;
        }
    }

    // แปลงเป็น String
    String toString() const {
        switch(type){
            case INT: return String(iVal);
            case LONG: return String(lVal);
            case FLOAT: return String(fVal);
            case STRING: return sVal;
        }
        return "";
    }

    // Conversion operators
    operator int() const { return (int)toFloat(); }
    operator long() const { return (long)toFloat(); }
    operator float() const { return toFloat(); }
    operator String() const { return toString(); }

    // Operator + - * /
    Result operator+(const Result &rhs) const { return Result(toFloat() + rhs.toFloat()); }
    Result operator-(const Result &rhs) const { return Result(toFloat() - rhs.toFloat()); }
    Result operator*(const Result &rhs) const { return Result(toFloat() * rhs.toFloat()); }
    Result operator/(const Result &rhs) const { return Result(rhs.toFloat()!=0 ? toFloat()/rhs.toFloat() : 0); }

    // Operator == !=
    bool operator==(const Result &rhs) const {
        if(type != rhs.type) return false;
        switch(type){
            case INT: return iVal == rhs.iVal;
            case LONG: return lVal == rhs.lVal;
            case FLOAT: return fVal == rhs.fVal;
            case STRING: return sVal == rhs.sVal;
        }
        return false;
    }

    bool operator!=(const Result &rhs) const {
        return !(*this == rhs);
    }
};

// ----------------------------
// New EEPROM Class 
// ----------------------------
// #(int), @(long), $(float), %(string)
// รูปแบบการเก็บข้อมูล: @name&value&
class My_eerom {
  // int H1;
public:

  My_eerom();  // ประกาศ constructor ไว้ด้วย
  #if !defined(ESP8266) && !defined(ESP32)
    void begin();       // AVR / UNO ใช้ได้
  #else
    void begin(size_t size); // ESP ต้องส่ง size
  #endif
  int GEUP();
  float GEUP_F();
  void clear();
  void D(String name);
  void W(String name, Result Text);
  Result R(String nane);
  Result R(String nane, int &rawLength);

  int H();

};

extern My_print p;
extern My_eerom E;

/* ----------------------------
   Pin-Mode Abstraction
   ---------------------------- */
void setPinMode(uint8_t pin, uint8_t mode);

/* ----------------------------
   Serial Input Helpers
   ---------------------------- */
// เปลี่ยนเป็นรับ input เป็น char buffer แทน String เพื่อประหยัด SRAM
 char* input(const char* prompt);
 char* input();

/* ----------------------------
   List Management Helpers
   ---------------------------- */
void outS();
void outL();
void addS(const char* text);
void addL(const char* text);

double fx(const char* num);

#endif // ARDUINOOS_H


