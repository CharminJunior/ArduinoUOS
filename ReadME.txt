UOS Library Notes

เอกสารฉบับนี้เป็นสรุปฟังก์ชันและการใช้งานเบื้องต้น สำหรับผู้เริ่มต้นหรือผู้ที่ไม่คุ้นเคยกับไลบรารี UOS สามารถคัดลอกไฟล์นี้ไปวางเป็น "README.txt" หรือเปิดอ่านในโฟลเดอร์ไลบรารีได้เลย

1. I/O Helpers
  1.0 "setPinMode(pin,m)"
    - เซ็ตโหมดพิน (m: 1=OUTPUT,2=INPUT,3=INPUT\_PULLUP)
  1.1 "DRead(pin,mode)"
    - เซ็ตโหมดพิน (mode: 2=INPUT,3=INPUT\_PULLUP) แล้วอ่านค่าสัญญาณดิจิทัล
  1.2 "btn(pin)"
    - อ่านปุ่มแบบ active-low (กดแล้วคืนค่า true)
  1.3 "ARead(ch)"
    - อ่านค่าแอนะล็อกจากช่อง ch (0–1023)
  1.4 "pwm(i,v)"
    - เขียน PWM ไปยังพินในตาราง pwmPins\[] ตามดัชนี i
  1.5 "outD(pin,v)"
    - เซ็ตพินเป็น OUTPUT แล้ว digitalWrite(v)
  1.6 "gml()"
    - คืนค่า millis() 
  1.7 "gmc()"
    - คืนค่า micros()

2. EEPROM Helpers
  2.1 "E.W(name, data)"
    - เอาไวเก็บข้อมูลลง EERROM แบบ อัด
  2.2 "E.R(name)"
    - อ่านตัวแปรที่เก็บไว ถ้าไม่เจอขึ้น -1
     2.2.1 "E.R(name)"
      - ใส่ชื่อตัวแปรที่จะอ่าน
     2.2.2 "E.R(name, J1)"
      - ใส่ชื่อตัวแปรที่จะอ่าน พร้อม J1 คือขนาดข้อมูลจริง
  2.3 "E.clear()"
    - Formrt EEROM ให้เข้ากับ ไลเบรารีนี้(เมือใช้ครั้งแรก)
  2.4 "E.D(name)"
    - ลบตัวแปรออกจาก EEROM
  2.5 "E.GEUP()"
    - ดูพื่นที่ว่างแบบดิบ
  2.6 "E.GEUP_F()"
    - ดูพื่นที่ว่างแบบ %
  2.7 "E.H()"
    - ดูตำแหน่งบล็อกล่าสุดใน EEROM ที่เขียนไป หรือ อ่าน

3. Result 
  - เป็นตั้งค่าตัวแปรที่ปลี่ยนไปๆมาๆได้ แบบเดียวกับ int -> chat โดยไม่ต้องแก้โค้คเองไห้มาก
  เช่น Result UI = 1; หรือ Result UI = "1"; หรือ Result UI = 1.00; เป็นต้น

4. Pin-Mode Abstraction
  4.1 "setPinMode(pin,m)"
    - เซ็ตโหมดพิน (m: 1=OUTPUT,2=INPUT,3=INPUT\_PULLUP)

5. Serial I/O Helpers
  5.1 "sIn(prompt)"
    - แสดง prompt แล้วอ่านบรรทัดจาก Serial (return char\*)

6. List Management (สองลิสต์)
   * ลิสต์หลัก: เก็บข้อความในตัวแปร hsuorg
   * ลิสต์รอง: เก็บข้อความในตัวแปร sysItems
       6.1 "pClr()"
     * เคลียร์ลิสต์หลัก (reset index)
       6.2 "pAdd(txt)"
     * เพิ่มข้อความ txt ลงลิสต์หลัก
       6.3 "sClr()"
     * เคลียร์ลิสต์รอง
       6.4 "sAdd(txt)"
     * เพิ่มข้อความ txt ลงลิสต์รอง

7. My_print Class (object: p)
   * ใช้พิมพ์ข้อความผ่าน Serial ง่ายๆ
       7.1 "p.b(b)"
     * เริ่ม Serial ด้วย baud rate b
       7.2 "p.b(b, Serial_bit)"
     * เริ่ม Serial ด้วย baud rate b และ ใส่ว่าจะรอเชื่อมกับ Serial ไหม เช่นใส่ 1 จะรอ ใส่ 0 จะข้ามไปรันโค้ค
       7.3 "p.text(x)"
     * พิมพ์ ข้อความลงไปใน x
       7.4 "p()"
     * คืน true ถ้า Serial พร้อมใช้งาน
