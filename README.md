
# ArduinoUOS

It is to make the Arduino UNO work better, and it will improve further in the future.

## Function/Working

- I/O

- PWM

- miniOS(Easy like RTOS but you have to do everything yourself.)

- EEROM

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
