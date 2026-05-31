/* -------------------------------------------------
Copyright (c)
Arduino project modified to work with analog-active-low flame sensors.
-------------------------------------------------*/
#include <AFMotor.h>
#include <Servo.h>

// Motors
AF_DCMotor leftMotor(3);    // M3
AF_DCMotor rightMotor(2);   // M2
AF_DCMotor pumpMotor(4);    // M4 for water pump

Servo sprayServo;

// Flame sensors A0–A4
const int flamePins[5] = { A0, A1, A2, A3, A4 };
const int flameThreshold = 500;  // Below this = flame detected

void setup() {
  Serial.begin(9600);
  sprayServo.attach(9);
  sprayServo.write(90);  // Center the servo

  leftMotor.setSpeed(100);
  rightMotor.setSpeed(100);
  pumpMotor.setSpeed(200);
}

void loop() {
  int values[5];
  int minValue = 1023;
  int flameIndex = -1;

  // Read sensors and find the one with strongest flame (lowest analog value)
  for (int i = 0; i < 5; i++) {
    values[i] = analogRead(flamePins[i]);
    Serial.print(values[i]);
    if (i < 4) Serial.print(", ");
    
    // Lower value means stronger flame
    if (values[i] < minValue) {
      minValue = values[i];
      flameIndex = i;
    }
  }
  Serial.println();

  // If the strongest flame reading is below our threshold, fire is detected
  if (minValue < flameThreshold) {
    Serial.println("Flame Detected");

    if (flameIndex < 2) {
      turnLeft();
    } else if (flameIndex > 2) {
      turnRight();
    } else {
      // Flame centered
      if (values[2] < 200) {  // Close enough (low value means very close)
        stopMotors();
        extinguish();
      } else {
        moveForward();
      }
    }
  } else {
    Serial.println("No Flame");
    stopMotors();
    pumpMotor.run(RELEASE);
  }

  delay(200);
}

void turnLeft() {
  leftMotor.run(BACKWARD);
  rightMotor.run(FORWARD);
}

void turnRight() {
  leftMotor.run(FORWARD);
  rightMotor.run(BACKWARD);
}

void moveForward() {
  leftMotor.run(BACKWARD);
  rightMotor.run(BACKWARD);
}

void stopMotors() {
  leftMotor.run(RELEASE);
  rightMotor.run(RELEASE);
}

void extinguish() {
  pumpMotor.run(FORWARD);

  for (int pos = 80; pos <= 100; pos += 5) {
    sprayServo.write(pos);
    delay(100);
  }
  for (int pos = 100; pos >= 80; pos -= 5) {
    sprayServo.write(pos);
    delay(100);
  }

  sprayServo.write(90);
  pumpMotor.run(RELEASE);
}
