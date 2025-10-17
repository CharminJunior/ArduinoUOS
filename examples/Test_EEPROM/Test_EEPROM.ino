#include <UOS.h> // ไลบรารีของคุณ

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
