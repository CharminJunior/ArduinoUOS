
# ArduinoUOS

It is to make the Arduino UNO work better, and it will improve further in the future.

## Function/Working

- I/O

- PWM

- miniOS(Easy like RTOS but you have to do everything yourself.)

- EasyEEROM

- EasySerial(input,print)
## Running Tests

It's a simple Hello performance.

```bash
#include <ArduinoUOS.h>

void setup() {
  p.b(9600);                            // set Serial = 9600
  p.text("Hello UNO!\n");               // Hello UNO!
  p.text("input >>>",input(),"\n");     // input >>>
  p.text("hello : ",5," :)\n");         // hello : 5 :)
}

void loop() {}

```

## EEROM Tests

Writing EEROM will be very easy.

```bash
#include <ArduinoUOS.h> // ไลบรารีของคุณ

void setup() {
  p.b(115200);           // เริ่ม Serial Monitor
  //EEPROM.begin(1024);    // เริ่ม EEPROM สำหรับ UNO (1KB)

  p.text("\n--- เริ่มทดสอบ ArduinoUOS ---\n");

  // ล้าง EEPROM ครั้งแรก (ถ้าต้องการ)
  // E.clear();
  
  // เขียนข้อมูลใหม่ (จะเขียนก็ต่อเมื่อค่าเปลี่ยน)
  E.W("text", "Hello World");
  E.W("name", "ArduinoUOS");
  
  // อ่านค่าที่เก็บไว้
  String val1 = E.R("text");
  String val2 = E.R("name");
  p.text("ค่า text: ", val1, "\n");
  p.text("ค่า name: ", val2, "\n");

  // อ่านค่าพร้อมความยาวจริงใน EEPROM
  int size;
  String val3 = E.R("text", size);
  p.text("ค่า text (ขนาดจริง): ", val3, " / ", size, " bytes\n");

  // ลบข้อมูล name
  E.D("name");
  p.text("ลบ 'name' แล้ว\n");

  // ตรวจสอบพื้นที่ EEPROM
  int freeBytes = E.GEUP();      // byte ที่มีข้อมูลจริง
  float freePercent = E.GEUP_F();// เปอร์เซ็นต์การใช้งาน
  p.text("พื้นที่ที่ใช้จริง: ", freeBytes, " bytes\n");
  p.text("คิดเป็น: ", freePercent, "%\n");

  // อ่านตำแหน่งล่าสุด (H1)
  p.text("ตำแหน่งล่าสุด H(): ", E.H(), "\n");

  p.text("--- จบการทดสอบ ---\n");
}

void loop() {
  // ไม่มีอะไรใน loop
}

```
## 1. I/O Helpers

| ฟังก์ชัน             | คำอธิบาย                                                       | ตัวอย่างการใช้                        |
| -------------------- | -------------------------------------------------------------- | ------------------------------------- |
| `setPinMode(pin, m)` | ตั้งโหมดพิน (m: 1=OUTPUT, 2=INPUT, 3=INPUT\_PULLUP)            | `setPinMode(5,1); // ตั้งเป็น OUTPUT` |
| `DRead(pin, mode)`   | ตั้งโหมดพิน (2=INPUT,3=INPUT\_PULLUP) แล้วอ่านค่าสัญญาณดิจิทัล | `int val = DRead(7, 2);`              |
| `btn(pin)`           | อ่านปุ่มแบบ active-low (กดคืนค่า `true`)                       | `if(btn(2)) { /* กดปุ่ม */ }`         |
| `ARead(ch)`          | อ่านค่าแอนะล็อกจากช่อง ch (0–1023)                             | `int sensorVal = ARead(0);`           |
| `pwm(i, v)`          | เขียน PWM ไปยังพินในตาราง pwmPins\[] ตามดัชนี i                | `pwm(0, 128); // ครึ่งความสว่าง`      |
| `outD(pin, v)`       | ตั้งพินเป็น OUTPUT แล้ว digitalWrite(v)                        | `outD(13, HIGH);`                     |
| `gml()`              | คืนค่า `millis()`                                              | `unsigned long t = gml();`            |
| `gmc()`              | คืนค่า `micros()`                                              | `unsigned long us = gmc();`           |

## 2. EEPROM Helpers

| ฟังก์ชัน          | คำอธิบาย                                       | ตัวอย่างการใช้                    |
| ----------------- | ---------------------------------------------- | --------------------------------- |
| `E.W(name, data)` | เก็บข้อมูลลง EEPROM แบบบีบอัด                  | `E.W("count", 123);`              |
| `E.R(name)`       | อ่านตัวแปรที่เก็บไว้ (ไม่เจอคืนค่า -1)         | `int val = E.R("count");`         |
| `E.R(name, size)` | อ่านตัวแปร พร้อมระบุขนาดข้อมูลจริง             | `E.R("config", 16);`              |
| `E.clear()`       | ฟอร์แมต EEPROM ให้เข้ากับไลบรารีนี้ (ครั้งแรก) | `E.clear();`                      |
| `E.D(name)`       | ลบตัวแปรออกจาก EEPROM                          | `E.D("temp");`                    |
| `E.GEUP()`        | ดูพื้นที่ว่างแบบดิบใน EEPROM                   | `int freeBytes = E.GEUP();`       |
| `E.GEUP_F()`      | ดูพื้นที่ว่างแบบเปอร์เซ็นต์ใน EEPROM           | `float freePercent = E.GEUP_F();` |
| `E.H()`           | ดูตำแหน่งบล็อกล่าสุดที่เขียน/อ่านใน EEPROM     | `int lastBlock = E.H();`          |

## 3. Watchdog
| ฟังก์ชัน | คำอธิบาย                       | ตัวอย่างการใช้ |
| -------- | ------------------------------ | -------------- |
| `wdOn()` | เปิดใช้งาน watchdog (1 วินาที) | `wdOn();`      |
| `wdR()`  | รีเซ็ต watchdog                | `wdR();`       |

## 4. Pin-Mode Abstraction
| ฟังก์ชัน             | คำอธิบาย                                            | ตัวอย่างการใช้      |
| -------------------- | --------------------------------------------------- | ------------------- |
| `setPinMode(pin, m)` | ตั้งโหมดพิน (m: 1=OUTPUT, 2=INPUT, 3=INPUT\_PULLUP) | `setPinMode(9, 2);` |

## 5. Serial I/O Helpers
| ฟังก์ชัน      | คำอธิบาย                                             | ตัวอย่างการใช้                       |
| ------------- | ---------------------------------------------------- | ------------------------------------ |
| `sIn(prompt)` | แสดง prompt แล้วอ่านบรรทัดจาก Serial (คืนค่า char\*) | `char* input = sIn("Enter name: ");` |

## 6. List Management (สองลิสต์ข้อความ)
| ฟังก์ชัน    | คำอธิบาย                       | ตัวอย่างการใช้   |
| ----------- | ------------------------------ | ---------------- |
| `pClr()`    | เคลียร์ลิสต์หลัก (reset index) | `pClr();`        |
| `pAdd(txt)` | เพิ่มข้อความ txt ลงลิสต์หลัก   | `pAdd("Hello");` |
| `sClr()`    | เคลียร์ลิสต์รอง                | `sClr();`        |
| `sAdd(txt)` | เพิ่มข้อความ txt ลงลิสต์รอง    | `sAdd("World");` |

## 7. My_print Class (object: p)
| ฟังก์ชัน    | คำอธิบาย                             | ตัวอย่างการใช้             |
| ----------- | ------------------------------------ | -------------------------- |
| `p.b(b)`    | เริ่ม Serial ด้วย baud rate b        | `p.b(115200);`             |
| `p.text(x)` | พิมพ์ข้อความ `x`                     | `p.text("Hello, world");`  |
| `p()`       | คืนค่า `true` หาก Serial พร้อมใช้งาน | `if(p()) p.text("Ready");` |

## 8. ฟังก์ชันสำหรับ OLED Display (ใช้ไลบรารี u8g2)
| หมายเลข | ชื่อฟอนต์                     | ลักษณะ                        | คำอธิบายย่อ                                                  |
| ------- | ----------------------------- | ----------------------------- | ------------------------------------------------------------ |
| 1       | `u8g2_font_ncenB08_tr`        | Medium, serif, 8 pixel height | ฟอนต์ตัวหนังสือทั่วไป เส้นหนาชัดเจน เหมาะสำหรับข้อความทั่วไป |
| 2       | `u8g2_font_6x10_tf`           | Fixed width 6x10 pixel        | ฟอนต์แบบตัวหนาและกว้างคงที่ เหมาะกับข้อความระยะเท่ากัน       |
| 3       | `u8g2_font_7x14_tf`           | Fixed width 7x14 pixel        | ฟอนต์สูง เหมาะกับข้อความขนาดใหญ่ขึ้น                         |
| 4       | `u8g2_font_crox3h_tf`         | Sans serif, bold, medium size | ฟอนต์แบบไม่มีหัว (sans serif) หนาและอ่านง่าย เหมาะกับ UI     |
| 5       | `u8g2_font_fub11_tf`          | Modern, sans serif, 11 pixel  | ฟอนต์สวยทันสมัย ขนาดกลาง เหมาะกับ UI ทันสมัย                 |
| 6       | `u8g2_font_t0_11b_tf`         | Tiny, bold                    | ฟอนต์ตัวเล็กและหนา เหมาะกับข้อความขนาดเล็กหรือแสดงสถานะ      |
| 7       | `u8g2_font_logisoso16_tf`     | Very large, sans serif        | ฟอนต์ขนาดใหญ่ เหมาะกับหัวข้อหรือข้อความเน้น                  |
| 8       | `u8g2_font_5x7_tf`            | Very small, fixed width       | ฟอนต์ขนาดเล็กมาก เหมาะกับข้อมูลที่ต้องการความกระชับ          |
| 9       | `u8g2_font_squeezed_b7_tnf`   | แคบ, ตัวเล็ก                  | ฟอนต์เล็กและแคบ เหมาะกับข้อความบีบอัดบนหน้าจอ                |
| 10      | `u8g2_font_unifont_t_symbols` | ฟอนต์สัญลักษณ์ Unicode        | ฟอนต์สำหรับแสดงสัญลักษณ์, อักขระพิเศษ Unicode                |
