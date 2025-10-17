#include <UOS.h>

void setup() {
  p.b(9600);                            // set Serial = 9600
  p.text("Hello UNO!\n");               // Hello UNO!
  p.text("input >>>",input(),"\n");     // input >>>
  p.text("hello : ",5," :)\n");         // hello : 5 :)
}

void loop() {}
