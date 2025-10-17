// UOS.cpp
#include "UOS.h"  // ต้องแก้ด้วยชื่อไฟล์จริง

// นิยามตัวแปร global
My_print p;
My_eerom E;

// ประกาศ pointer ไว้ข้างนอกฟังก์ชัน เพื่อใช้ทั่วโปรแกรม
// U8G2* u8g2 = nullptr;

/* ----------------------------
   Global Variables (Definitions)
   ---------------------------- */
char hsuorg[MAX_LIST_ITEMS][MAX_ITEM_LEN];
char sysItems[MAX_LIST_ITEMS][MAX_ITEM_LEN];
int list_count = 0;
int list_count_2 = 0;

int H1 = 0;

/* ----------------------------
   EEPROM Size Check for ESP
   ---------------------------- */
// #if defined(ESP8266) || defined(ESP32)
//     // ESP ต้องมีขนาด EEPROM
//     #ifndef EEPROM_SIZE_DEFINED
//         #define CHECK_EEPROM_SIZE_MACRO
//     #endif
// #else
//     // บอร์ดอื่น (เช่น AVR) ไม่ต้องใช้ size
// #endif

/* ----------------------------
   My_print Class Implementation
   ---------------------------- */

// constructor
My_print::My_print() {
  // ไม่ต้องทำอะไรพิเศษ
}

// ฟังก์ชัน non‑template
void My_print::b(long baud) {
  Serial.begin(baud);
  while (!Serial) {}
}

void My_print::b(long baud, bool Serial_bit) {
  Serial.begin(baud);
  if(Serial_bit) { while (!Serial) {} }
}

// void My_print::b(long baud, int oledType) {
//   if (u8g2) {
//     delete u8g2;  // ล้างตัวเดิมก่อน
//     u8g2 = nullptr;
//   }

//   if (oledType == 1306) {
//     //u8g2 = new U8G2_SH1315_128X64_NONAME_F_HW_I2C(U8G2_R0, U8X8_PIN_NONE);
//   } else if (oledType == 1106) {
//     u8g2 = new U8G2_SH1106_128X64_NONAME_F_HW_I2C(U8G2_R0, U8X8_PIN_NONE);
//   }

//   if (u8g2) {
//     u8g2->begin();
//     u8g2->setBusClock(800000); // I2C เร็วขึ้น (อาจไม่จำเป็นในจอนี้ก็ได้)
//   } else {
//     // แจ้ง error หรือ fallback
//   }
//   Serial.begin(baud);
//   while (!Serial) {}
// }

// void My_print::set(int X, int Y) {
//   if (!u8g2) return;
//   x = X; y = Y;
// }

// void My_print::move(int dx, int dy) {
//   if (!u8g2) return;
//   x += dx; y += dy;
//   // if (x < 0) x = 0; else if (x > 127) x = 127;
//   // if (y < 0) y = 0; else if (y > 63) y = 63;
// }

// void My_print::oled(int num) {
//   if (!u8g2) return;
//   u8g2->setCursor(x, y);
//   u8g2->print(num);
// }

// void My_print::oled(long num) {
//   if (!u8g2) return;
//   u8g2->setCursor(x, y);
//   u8g2->print(num);
// }

// void My_print::oled(float num) {
//   if (!u8g2) return;
//   u8g2->setCursor(x, y);
//   u8g2->print(num, 2); // ทศนิยม 2 หลัก
// }

// void My_print::oled(const char* s) {
//   if (!u8g2) return;
//   u8g2->setCursor(x, y);
//   u8g2->print(s);
// }

// void My_print::oled(int num, int t) {
//   if (!u8g2) return;
//   u8g2->setDrawColor(t);
//   u8g2->setCursor(x, y);
//   u8g2->print(num);
// }

// void My_print::oled(long num, int t) {
//   if (!u8g2) return;
//   u8g2->setDrawColor(t);
//   u8g2->setCursor(x, y);
//   u8g2->print(num);
// }

// void My_print::oled(float num, int t) {
//   if (!u8g2) return;
//   u8g2->setDrawColor(t);
//   u8g2->setCursor(x, y);
//   u8g2->print(num, 2); // ทศนิยม 2 หลัก
// }

// void My_print::oled(const char* s, int t) {
//   if (!u8g2) return;
//   u8g2->setDrawColor(t);
//   u8g2->setCursor(x, y);
//   u8g2->print(s);
// }

// void My_print::oled(int X, int Y, const char* s) {
//   set(X, Y);
//   oled(s);
// }

// void My_print::oled(int X, int Y, int num) {
//   set(X, Y);
//   oled(num);
// }

// void My_print::oled(int X, int Y, long num) {
//   set(X, Y);
//   oled(num);
// }

// void My_print::oled(int X, int Y, float num) {
//   set(X, Y);
//   oled(num);
// }

// void My_print::oled(int X, int Y, const char* s, int t) {
//   u8g2->setDrawColor(t);
//   set(X, Y);
//   oled(s);
// }

// void My_print::oled(int X, int Y, int num, int t) {
//   u8g2->setDrawColor(t);
//   set(X, Y);
//   oled(num);
// }

// void My_print::oled(int X, int Y, long num, int t) {
//   u8g2->setDrawColor(t);
//   set(X, Y);
//   oled(num);
// }

// void My_print::oled(int X, int Y, float num, int t) {
//   u8g2->setDrawColor(t);
//   set(X, Y);
//   oled(num);
// }

// void My_print::clear() {
//   if (!u8g2) return;
//   u8g2->clearBuffer();
// }

// void My_print::show() {
//   if (!u8g2) return;
//   u8g2->sendBuffer();
// }

// void My_print::Pixel(int x, int y) {
//   if (!u8g2) return;
//   u8g2->drawPixel(x, y);
// }

// void My_print::Pixel(int x0, int y0, int x1, int y1) {
//   if (!u8g2) return;
//   u8g2->drawLine(x0,y0,x1,y1);
// }

// // ฟังก์ชันเลือกฟอนต์จากหมายเลข 1-10
// void My_print::SF(int n) {
//   if (!u8g2) return;

//   switch(n) {
//     case 1: u8g2->setFont(u8g2_font_ncenB08_tr); break;
//     case 2: u8g2->setFont(u8g2_font_6x10_tf); break;
//     case 3: u8g2->setFont(u8g2_font_7x14_tf); break;
//     case 4: u8g2->setFont(u8g2_font_crox3h_tf); break;
//     case 5: u8g2->setFont(u8g2_font_fub11_tf); break;
//     case 6: u8g2->setFont(u8g2_font_t0_11b_tf); break;
//     case 7: u8g2->setFont(u8g2_font_logisoso16_tf); break;
//     case 8: u8g2->setFont(u8g2_font_5x7_tf); break;
//     case 9: u8g2->setFont(u8g2_font_squeezed_b7_tn); break;
//     case 10: u8g2->setFont(u8g2_font_unifont_t_symbols); break;
//     default: u8g2->setFont(u8g2_font_ncenB08_tr); break;  // ฟอนต์ดีฟอลต์
//   }
// }

/* ----------------------------
   I/O Helpers Implementation
   ---------------------------- */
bool DRead(int pin, int SetPin) {
  setPinMode(pin, SetPin);
  return digitalRead(pin);
}

bool btn(int pin) {
  return !(bool(DRead(pin, 3)));
}

int ARead(int ch) {
  return analogRead(ch);
}

void pwm(uint8_t idx, uint8_t value) {
  uint8_t pin = idx;
  pinMode(pin, OUTPUT);
  analogWrite(pin, value);
}

void outD(int pin, bool value) {
  setPinMode(pin, 1);
  digitalWrite(pin, value ? HIGH : LOW);
}

unsigned long gml() {
  return millis();
}

unsigned long gmc() {
  return micros();
}

/* ----------------------------
   EEPROM Helpers Implementation
   ---------------------------- */

bool isValidPosition(int pos, int length) {
  for (int i = pos; i < pos + length; i++) {
    char c = EEPROM.read(i);
    if (c == '@' || c == '#' || c == '&') {
      return false; // เจอตัวอักษรพิเศษ
    }
  }
  return true;
}

bool isNumber(String str) {
  if (str.length() == 0) return false;

  int start = 0;
  if (str[0] == '-' || str[0] == '+') { // มีเครื่องหมายบวก/ลบ
    if (str.length() == 1) return false; // มีแค่เครื่องหมาย ไม่มีเลข
    start = 1;
  }

  bool hasDecimal = false;
  for (int i = start; i < str.length(); i++) {
    if (str[i] == '.') {
      if (hasDecimal) return false; // เจอจุดทศนิยมซ้ำ
      hasDecimal = true;
    }
    else if (!isDigit(str[i])) {
      return false; // ไม่ใช่ตัวเลข
    }
  }
  return true;
}

int findValidPosition(String Compilation) {
  //int T3 = -1; // ตำแหน่งที่จะเขียน
  int maxPos = EEPROM.length() - Compilation.length();
  int trialCount = 0;  // ป้องกันวนไม่จบ (กรณีไม่มีตำแหน่งว่าง)
  const int maxTrials = 100; 

  while (trialCount < maxTrials) {
    int pos = random(0, maxPos + 1); // +1 เพราะช่วงบน exclusive
    if (isValidPosition(pos, Compilation.length())) {
      //T3 = pos;
      return pos;
    }
    trialCount++;
  }

  // ถ้าหมดรอบแล้วยังหาไม่ได้คืน false
  return -1;
}

My_eerom::My_eerom() {
  // ไม่มีอะไร
}

#if !defined(ESP8266) && !defined(ESP32)
  void My_eerom::begin() {
    // AVR / UNO ใช้ได้
  }
#else
  void My_eerom::begin(size_t size) {
    #if defined(ESP8266) || defined(ESP32)
      EEPROM.begin(size);
    #endif
  }
#endif

int My_eerom::GEUP() {
  int count = 0;
  int size = EEPROM.length();

  for (int i = 0; i < size; i++) {
    byte val = EEPROM.read(i);
    if (val != 0xFF) {
      count++;
    }
  }
  return count; // คืนจำนวนไบต์ที่มีข้อมูลจริง
}

float My_eerom::GEUP_F() {
  int validCount = 0;
  int size = EEPROM.length();

  for (int i = 0; i < size; i++) {
    if (EEPROM.read(i) != 0xFF) {
      validCount++;
    }
  }

  float percent = (validCount * 100.0) / size;
  return percent; // เปอร์เซ็นต์ข้อมูลจริง
}

void My_eerom::clear() {
  if(GEUP_F() != 0) {
    int eepromSize = EEPROM.length(); // ขนาด EEPROM ของบอร์ด

    p.text("Size EEPROM = ",eepromSize,"\n");
    p.text("Perform cleaning...\n");

    int n1 = 0;

    for (int i = 0; i < eepromSize; i++) {
      EEPROM.write(i, 0xFF);  // หรือจะเขียน 0 ก็ได้
      //n1 = (i*100)/eepromSize;
      //lod(i,eepromSize);
    }
    // EEPROM.commit();
    #if defined(ESP8266) || defined(ESP32)
    EEPROM.commit();  // จำเป็นบน ESP
    #endif

    p.text("EEPROM is clear!\n");
  } else {
    p.text("EEPROM is clear!\n");
  }
}

void My_eerom::D(String name) {
  int X1;
  R(name,X1);

  if(H1 != -1) {
    int X2 = H1;
    for(int i=0; i <= X1; i++) {
      EEPROM.write(i+X2, 0xFF);  // หรือจะเขียน 0 ก็ได้
    }
    // EEPROM.commit();
    #if defined(ESP8266) || defined(ESP32)
    EEPROM.commit();  // จำเป็นบน ESP
    #endif
  }
}

void My_eerom::W(String name, Result Text) {
  if(R(name) != Text) {
    D(name);
    
    String in2;
    String Compilation;
    int T1, T2;
    String in;

    if (Text.isint()) {
      in2 = "#" + name;  // เป็นตัวเลข int
    } else if (Text.islong()) {
      in2 = "@" + name;  // เป็นตัวเลข long
    } else if (Text.isfloat()) {
      in2 = "$" + name;  // เป็นตัวเลข float
    } else if (Text.isstr()) {
      in2 = "%" + name;  // เป็นข้อความ string
    } else {
      // ไม่รู้จักชนิดข้อมูล
      p.text("Error: Unknown data type\n");
      return;
    }

    in = Text.toString();
    Compilation = in2 + "&" + in + "&";

    p.text("Compilation : ",Compilation,"\n");

    //T1 = random(0, EEPROM.length() - Compilation.length());
    //T1 = 1; // EEPROM.length() - Compilation.length();
    T1 = findValidPosition(Compilation);
    T2 = 1;

    // วนตามความยาว Compilation
    for (int i = 0; i < Compilation.length(); i++) {
      EEPROM.write(T1 + T2, Compilation.charAt(T2 - 1));
      T2++;
    }
    #if defined(ESP8266) || defined(ESP32)
    EEPROM.commit();  // จำเป็นบน ESP
    #endif
  }
}

Result My_eerom::R(String nane) {
  long addr = 0;
  String Lite = "";
  Result Vode;

  // วนหา '@', '#', '$', '%' ก่อน
  while (addr < EEPROM.length()) {
    char ch = (char)EEPROM.read(addr);
    if (ch != '#' && ch != '@' && ch != '$' && ch != '%') {
      addr++;
      continue;
    }

    addr++; // ข้ามตัวอักษรชนิดข้อมูล

    // อ่านชื่อจนเจอ '&'1
    Lite = "";
    while (addr < EEPROM.length()) {
      char c = (char)EEPROM.read(addr);
      if (c == '&') {
        addr++;
        break;
      }
      Lite += c;
      addr++;
    }

    // ชื่อไม่ตรง → ข้ามค่าข้อมูล
    if (Lite != nane) {
      while (addr < EEPROM.length()) {
        if ((char)EEPROM.read(addr) == '&') {
          addr++;
          break;
        }
        addr++;
      }
      continue;
    }

    // ตัวแปร → อ่านค่าข้อมูลจนเจอ '&'2
    String data = "";
    while (addr < EEPROM.length()) {
      char c = (char)EEPROM.read(addr);
      if (c == '&') {
        addr++;
        break;
      }
      data += c;
      addr++;
    }

    // Vode = data; // เก็บชื่อ (ถ้าต้องการ)

    // แปลงค่าและเก็บใน Result
    if (ch == '@') {           // long
      Vode.type = Result::LONG;
      Vode.lVal = data.toInt();
    } else if (ch == '#') {    // int
      Vode.type = Result::INT;
      Vode.iVal = data.toInt();
    } else if (ch == '$') {    // float
      Vode.type = Result::FLOAT;
      Vode.fVal = data.toFloat();
    } else if (ch == '%') {    // string
      Vode.type = Result::STRING;
      Vode.sVal = data;
    }

    return Vode; // คืนค่าข้อมูล
  }

  // ไม่เจอ → คืนค่า Result แบบ type = STRING และ sVal = "-1"
  Result empty;
  empty.type = Result::STRING;
  empty.sVal = "-1";
  return empty;
}

Result My_eerom::R(String nane, int &rawLength) {
  long addr = 0;
  String Lite = "";
  Result Vode;
  rawLength = 0;

  while (addr < EEPROM.length()) {
    // หา '@', '#', '$', '%' ก่อน
    char ch = (char)EEPROM.read(addr);
    if (ch != '#' && ch != '@' && ch != '$' && ch != '%') {
      addr++;
      continue;
    }
    long startAddr = addr;  // เก็บตำแหน่งเริ่มต้นของข้อมูลดิบ
    H1 = addr;
    addr++; // ข้าม '@', '#', '$', '%'

    // อ่านชื่อ (จนเจอ '&')
    Lite = "";
    while (addr < EEPROM.length()) {
      char c = (char)EEPROM.read(addr);
      if (c == '&') { addr++; break; }
      Lite += c;
      addr++;
    }

    // ถ้าไม่ตรงชื่อ ให้ข้ามข้อมูล (ค่าข้อมูล) ไปจนเจอ '&' ตัวที่สอง
    if (Lite != nane) {
      while (addr < EEPROM.length()) {
        if ((char)EEPROM.read(addr) == '&') { addr++; break; }
        addr++;
      }
      continue; // อ่านชุดถัดไป
    }

    // ชื่อตรง → อ่านค่าข้อมูล (จนเจอ '&')
    // Vode = "";
    String data = "";
    while (addr < EEPROM.length()) {
      char c = (char)EEPROM.read(addr);
      if (c == '&') { addr++; break; }
      data += c;
      addr++;
    }

    // คำนวณความยาวข้อมูลดิบ ตั้งแต่ตำแหน่ง '@', '#', '$', '%' ถึง & ตัวที่สอง
    rawLength = addr - startAddr;

    // แปลงค่าและเก็บใน Result
    if (ch == '@') {           // long
      Vode.type = Result::LONG;
      Vode.lVal = data.toInt();
    } else if (ch == '#') {    // int
      Vode.type = Result::INT;
      Vode.iVal = data.toInt();
    } else if (ch == '$') {    // float
      Vode.type = Result::FLOAT;
      Vode.fVal = data.toFloat();
    } else if (ch == '%') {    // string
      Vode.type = Result::STRING;
      Vode.sVal = data;
    }

    return Result(Vode);  // <-- คืนค่า Result แทน String
  }

  rawLength = 0;
  H1 = -1;
  return Result(String("-1")); // <-- คืนค่า Result
}

int My_eerom::H() {
  return H1;
}

/* ----------------------------
   Pin-Mode Abstraction Implementation
   ---------------------------- */
void setPinMode(uint8_t pin, uint8_t mode) {
  const uint8_t yio[] = { 0, OUTPUT, INPUT, INPUT_PULLUP };
  if (mode >= 1 && mode <= 3) {
    pinMode(pin, yio[mode]);
  }
}

/* ----------------------------
   Serial Input Helpers Implementation
   ---------------------------- */
// อ่านจนเจอ '\n' หรือจนบัฟเฟอร์เต็ม (เหลือ 1 byte 0-terminator)
char* input(const char* prompt) {
  // จองบัฟเฟอร์ภายในฟังก์ชัน (ปรับขนาดได้ตามต้องการ)
  static char buf[64];
  size_t idx = 0;
  p.text(prompt," >>> ");
  while (true) {
    if (Serial.available() > 0) {
      char c = Serial.read();
      if (c == '\r') continue;            // ข้าม CR
      if (c == '\n' || idx >= sizeof(buf)-1) break;
      buf[idx++] = c;
    }
  }
  buf[idx] = '\0';
  p.text(buf,"\n");
  return buf;
}

char* input() {
  // จองบัฟเฟอร์ภายในฟังก์ชัน (ปรับขนาดได้ตามต้องการ)
  static char buf[64];
  size_t idx = 0;
  while (true) {
    if (Serial.available() > 0) {
      char c = Serial.read();
      if (c == '\r') continue;            // ข้าม CR
      if (c == '\n' || idx >= sizeof(buf)-1) break;
      buf[idx++] = c;
    }
  }
  buf[idx] = '\0';
  return buf;
}

/* ----------------------------
   List Management Implementation
   ---------------------------- */
void outS() {
  list_count = 0;
}

void outL() {
  list_count_2 = 0;
}

void addS(const char* text) {
  if (list_count >= MAX_LIST_ITEMS) return;
  strncpy(hsuorg[list_count], text, MAX_ITEM_LEN - 1);
  hsuorg[list_count][MAX_ITEM_LEN - 1] = '\0';
  list_count++;
}

void addL(const char* text) {
  if (list_count_2 >= MAX_LIST_ITEMS) return;
  strncpy(sysItems[list_count_2], text, MAX_ITEM_LEN - 1);
  sysItems[list_count_2][MAX_ITEM_LEN - 1] = '\0';
  list_count_2++;
}

double fx(const char* num) {
  return te_interp(num, 0);
}


