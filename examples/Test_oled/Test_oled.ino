#include <UOS.h>

int ledPin = 13;  // PWM pin
int brightness = 0;
int fadeAmount = 5; // ค่าที่เพิ่ม/ลดต่อครั้ง

void setup() {
  // put your setup code here, to run once:
  p.b(115200,1106);
  p.text("Hello UNO R4\n");
  p.set(2,12);
  p.SF(2);
  
}

void loop() {
  // // ตั้งค่า PWM ตามความสว่างปัจจุบัน
  // pwm(ledPin, brightness);

  // // ปรับความสว่างขึ้นหรือลง
  // brightness = brightness + fadeAmount;
  // if (brightness <= 0 || brightness >= 255) {
  //   fadeAmount = -fadeAmount;
  // }
  // delay(30);
  p.text("Stert oled\n");
  p.clear();

  for(int u=0; u <= 128; u++) {
    p.set(100,60);
    p.oled("%");
    p.move(7,0);
    p.oled((u*100)/128);
    p.Pixel(0,62,u,62);
    p.Pixel(0,63,u,63);
    p.show();
  }

  p.set(2,12);
  p.oled("Hello World!");
  p.text("end\n");
  p.show();
  //delay(2000);
  long start = gml();
  for (long now = start; now <= start + 2500; now = gml()) {
      pwm(ledPin, brightness);
      brightness += fadeAmount;
      if (brightness <= 0 || brightness >= 255) {
          fadeAmount = -fadeAmount;
      }
      delay(10);
  }
  pwm(ledPin,0);
}
