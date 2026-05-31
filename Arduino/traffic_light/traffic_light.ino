#include <Servo.h>

int servoPin = 1;
Servo servo;

void setup() {
  servo.attach(servoPin);
}

void loop() {
  servo.write(0);
  delay(1000);
  servo.write(90);
  delay(1000);
  servo.write(180);
  delay(1000);
  }
