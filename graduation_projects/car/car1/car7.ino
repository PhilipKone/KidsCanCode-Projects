#include <Servo.h>

// Pin Definitions
const int LEFT_MOTOR_DIR = 2;
const int LEFT_MOTOR_PWM = 5;
const int RIGHT_MOTOR_DIR = 4;
const int RIGHT_MOTOR_PWM = 6;

const int LINE_LEFT = 7;
const int LINE_CENTER = 8;
const int LINE_RIGHT = 9;

// Using A1 and A2 for potholes (Manufacturer Standard)
const int POTHOLE_L = A1; 
const int POTHOLE_R = A2; 
const int PAINT_SERVO_PIN = 10; 

Servo paintServo;
int White = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(LINE_LEFT, INPUT);
  pinMode(LINE_CENTER, INPUT);
  pinMode(LINE_RIGHT, INPUT);
  
  pinMode(POTHOLE_L, INPUT);
  pinMode(POTHOLE_R, INPUT);
  
  pinMode(LEFT_MOTOR_DIR, OUTPUT);
  pinMode(LEFT_MOTOR_PWM, OUTPUT);
  pinMode(RIGHT_MOTOR_DIR, OUTPUT);
  pinMode(RIGHT_MOTOR_PWM, OUTPUT);
  
  paintServo.attach(PAINT_SERVO_PIN);
  paintServo.write(0); 
  
  Serial.println("Car 7.1: Double IR Pothole System Ready");
  delay(2000); 
}

void Infrared_Tracing() {
  int L = digitalRead(LINE_LEFT);
  int C = digitalRead(LINE_CENTER);
  int R = digitalRead(LINE_RIGHT);

  // Read both pothole sensors
  int P_L = digitalRead(POTHOLE_L);
  int P_R = digitalRead(POTHOLE_R);

  // --- STABLE DOUBLE POTHOLE CHECK ---
  if (P_L == White || P_R == White) {
    delay(50); // Double check for stability
    if (digitalRead(POTHOLE_L) == White || digitalRead(POTHOLE_R) == White) {
      
      // 1. STOP
      digitalWrite(2, LOW);
      analogWrite(5, 0);
      digitalWrite(4, HIGH);
      analogWrite(6, 0);
      Serial.println("Pothole detected (A1 or A2)!");
      delay(500);

      // 2. PAINT
      paintServo.write(90);
      delay(1200); 

      // 3. CLOSE
      paintServo.write(0);
      delay(500);
      
      // 4. BOOST FORWARD
      digitalWrite(2, HIGH);
      analogWrite(5, 140);
      digitalWrite(4, LOW);
      analogWrite(6, 140);
      delay(500); 
      
      return; 
    }
  }

  // --- LINE TRACKING (CAR1.INO LOGIC) ---
  if (L != White && (C == White && R != White)) {
    digitalWrite(2, HIGH);
    analogWrite(5, 120);
    digitalWrite(4, LOW);
    analogWrite(6, 120);
  } else if (L == White && (C == White && R != White)) {
    digitalWrite(2, LOW);
    analogWrite(5, 90);
    digitalWrite(4, LOW);
    analogWrite(6, 90);
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
    analogWrite(5, 90);
    digitalWrite(4, HIGH);
    analogWrite(6, 90);
  } else if (L == White && (C == White && R == White)) {
    digitalWrite(2, LOW);
    analogWrite(5, 0);
    digitalWrite(4, HIGH);
    analogWrite(6, 0);
  }
}

void loop() { 
  Infrared_Tracing(); 
}
