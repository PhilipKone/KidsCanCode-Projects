#include <Servo.h>

Servo paintServo;
int White = 0;

void setup() {
  Serial.begin(9600);
  
  // Tracing Pins
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  
  // Pothole Sensor (Only D10)
  pinMode(10, INPUT_PULLUP); 
  
  // Motor Pins
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  
  // Servo on Pin 11
  paintServo.attach(11); 
  paintServo.write(0);   // Start Closed
  
  Serial.println("Car 5.1: Stabilized Mode Started");
  delay(2000); // Wait for power to settle
}

void Infrared_Tracing() {
  int L = digitalRead(7);
  int C = digitalRead(8);
  int R = digitalRead(9);

  // --- STABLE POTHOLE CHECK ---
  if (digitalRead(10) == White) {
    delay(50);
    if (digitalRead(10) == White) {
      
      // 1. STOP
      digitalWrite(2, LOW);
      analogWrite(5, 0);
      digitalWrite(4, HIGH);
      analogWrite(6, 0);
      
      // 2. SERVO TURN
      paintServo.write(90); 
      delay(1000); 
      
      // 3. SERVO BACK
      paintServo.write(0);
      delay(500);

      // 4. BOOST FORWARD (To clear the pothole)
      digitalWrite(2, HIGH);
      analogWrite(5, 120);
      digitalWrite(4, LOW);
      analogWrite(6, 120);
      delay(400);
      
      return; 
    }
  }

  // --- NORMAL LINE TRACING ---
  if (L != White && (C == White && R != White)) {
    digitalWrite(2, HIGH);
    analogWrite(5, 120);
    digitalWrite(4, LOW);
    analogWrite(6, 120);
  } else if (L == White && (C == White && R != White)) {
    digitalWrite(2, LOW);
    analogWrite(5, 80);
    digitalWrite(4, LOW);
    analogWrite(6, 80);
  } else if (L == White && (C != White && R != White)) {
    digitalWrite(2, LOW);
    analogWrite(5, 120);
    digitalWrite(4, LOW);
    analogWrite(6, 120);
  } else if (L != White && (C != White && R == White)) {
    digitalWrite(2, HIGH);
    analogWrite(5, 120);
    digitalWrite(4, HIGH);
    analogWrite(6, 120);
  } else if (L != White && (C == White && R == White)) {
    digitalWrite(2, HIGH);
    analogWrite(5, 80);
    digitalWrite(4, HIGH);
    analogWrite(6, 80);
  } else if (L == White && (C == White && R == White)) {
    digitalWrite(2, LOW);
    analogWrite(5, 0);
    digitalWrite(4, HIGH);
    analogWrite(6, 0);
  }
}

void loop() { Infrared_Tracing(); }