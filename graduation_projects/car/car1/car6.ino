#include <Servo.h>

Servo paintServo;

void Infrared_Tracing() {
  int Left_Tra_Value = 0;
  int Center_Tra_Value = 0;
  int Right_Tra_Value = 0;
  int White = 0;
  Left_Tra_Value = digitalRead(7);
  Center_Tra_Value = digitalRead(8);
  Right_Tra_Value = digitalRead(9);

  // Read pothole sensors
  int Pothole_L = digitalRead(10);
  // int Pothole_R = digitalRead(11); // Pin 11 is now used for the Servo

  // If a pothole is detected, stop and turn servo once
  if (Pothole_L == White) {
    // 1. STOP
    digitalWrite(2, LOW);
    analogWrite(5, 0);
    digitalWrite(4, HIGH);
    analogWrite(6, 0);
    
    // 2. TURN SERVO ONCE
    paintServo.write(90);
    delay(1000);
    
    // 3. TURN BACK
    paintServo.write(0);
    delay(1000);
    
    return; // Stay stopped and stop processing movement
  }
  
  if (Left_Tra_Value != White &&
      (Center_Tra_Value == White && Right_Tra_Value != White)) {
    digitalWrite(2, HIGH);
    analogWrite(5, 120);
    digitalWrite(4, LOW);
    analogWrite(6, 120);

  } else if (Left_Tra_Value == White &&
             (Center_Tra_Value == White && Right_Tra_Value != White)) {
    digitalWrite(2, LOW);
    analogWrite(5, 80);
    digitalWrite(4, LOW);
    analogWrite(6, 80);
  } else if (Left_Tra_Value == White &&
             (Center_Tra_Value != White && Right_Tra_Value != White)) {
    digitalWrite(2, LOW);
    analogWrite(5, 120);
    digitalWrite(4, LOW);
    analogWrite(6, 120);
  } else if (Left_Tra_Value != White &&
             (Center_Tra_Value != White && Right_Tra_Value == White)) {
    digitalWrite(2, HIGH);
    analogWrite(5, 120);
    digitalWrite(4, HIGH);
    analogWrite(6, 120);
  } else if (Left_Tra_Value != White &&
             (Center_Tra_Value == White && Right_Tra_Value == White)) {
    digitalWrite(2, HIGH);
    analogWrite(5, 80);
    digitalWrite(4, HIGH);
    analogWrite(6, 80);
  } else if (Left_Tra_Value == White &&
             (Center_Tra_Value == White && Right_Tra_Value == White)) {
    digitalWrite(2, LOW);
    analogWrite(5, 0);
    digitalWrite(4, HIGH);
    analogWrite(6, 0);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT_PULLUP); 
  pinMode(11, INPUT_PULLUP); 
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  
  paintServo.attach(11); // Attaching to Pin 11
  paintServo.write(0);
}

void loop() { Infrared_Tracing(); }