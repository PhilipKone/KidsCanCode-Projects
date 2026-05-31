#include <Servo.h>

// Pin Definitions
const int LEFT_MOTOR_DIR = 2;
const int LEFT_MOTOR_PWM = 5;
const int RIGHT_MOTOR_DIR = 4;
const int RIGHT_MOTOR_PWM = 6;

const int LINE_LEFT = 7;
const int LINE_CENTER = 8;
const int LINE_RIGHT = 9;

const int POTHOLE_L = 10;
const int PAINT_SERVO_PIN = 11;

Servo paintServo;
int White = 0; 

void setup() {
  Serial.begin(9600);
  
  pinMode(LINE_LEFT, INPUT);
  pinMode(LINE_CENTER, INPUT);
  pinMode(LINE_RIGHT, INPUT);
  pinMode(POTHOLE_L, INPUT_PULLUP);
  
  pinMode(LEFT_MOTOR_DIR, OUTPUT);
  pinMode(LEFT_MOTOR_PWM, OUTPUT);
  pinMode(RIGHT_MOTOR_DIR, OUTPUT);
  pinMode(RIGHT_MOTOR_PWM, OUTPUT);
  
  paintServo.attach(PAINT_SERVO_PIN);
  paintServo.write(0); // Start Closed
  
  Serial.println("System Initializing...");
  delay(2000); 
  Serial.println("System Ready!");
}

void Infrared_Tracing() {
  int L = digitalRead(LINE_LEFT);
  int C = digitalRead(LINE_CENTER);
  int R = digitalRead(LINE_RIGHT);

  // --- TRIPLE CHECK POTHOLE ---
  if (digitalRead(POTHOLE_L) == White) {
    delay(50);
    if (digitalRead(POTHOLE_L) == White) {
      delay(50);
      if (digitalRead(POTHOLE_L) == White) {
        
        // 1. STOP
        digitalWrite(LEFT_MOTOR_DIR, LOW);
        analogWrite(LEFT_MOTOR_PWM, 0);
        digitalWrite(RIGHT_MOTOR_DIR, HIGH);
        analogWrite(RIGHT_MOTOR_PWM, 0);
        Serial.println("Pothole detected!");
        delay(800);

        // 2. DISPENSE
        paintServo.write(90);
        delay(1500); 

        // 3. CLOSE
        paintServo.write(0);
        delay(800);
        
        // 4. BOOST PAST
        digitalWrite(LEFT_MOTOR_DIR, HIGH);
        analogWrite(LEFT_MOTOR_PWM, 140);
        digitalWrite(RIGHT_MOTOR_DIR, LOW);
        analogWrite(RIGHT_MOTOR_PWM, 140);
        delay(500); 
        
        return; 
      }
    }
  }

  // --- LINE TRACKING ---
  if (L != White && (C == White && R != White)) {
    digitalWrite(LEFT_MOTOR_DIR, HIGH);
    analogWrite(LEFT_MOTOR_PWM, 120);
    digitalWrite(RIGHT_MOTOR_DIR, LOW);
    analogWrite(RIGHT_MOTOR_PWM, 120);
  } else if (L == White && (C == White && R != White)) {
    digitalWrite(LEFT_MOTOR_DIR, LOW);
    analogWrite(LEFT_MOTOR_PWM, 90);
    digitalWrite(RIGHT_MOTOR_DIR, LOW);
    analogWrite(RIGHT_MOTOR_PWM, 90);
  } else if (L == White && (C != White && R != White)) {
    digitalWrite(LEFT_MOTOR_DIR, LOW);
    analogWrite(LEFT_MOTOR_PWM, 130);
    digitalWrite(RIGHT_MOTOR_DIR, LOW);
    analogWrite(RIGHT_MOTOR_PWM, 130);
  } else if (L != White && (C != White && R == White)) {
    digitalWrite(LEFT_MOTOR_DIR, HIGH);
    analogWrite(LEFT_MOTOR_PWM, 130);
    digitalWrite(RIGHT_MOTOR_DIR, HIGH);
    analogWrite(RIGHT_MOTOR_PWM, 130);
  } else if (L != White && (C == White && R == White)) {
    digitalWrite(LEFT_MOTOR_DIR, HIGH);
    analogWrite(LEFT_MOTOR_PWM, 90);
    digitalWrite(RIGHT_MOTOR_DIR, HIGH);
    analogWrite(RIGHT_MOTOR_PWM, 90);
  } else if (L == White && (C == White && R == White)) {
    digitalWrite(LEFT_MOTOR_DIR, LOW);
    analogWrite(LEFT_MOTOR_PWM, 0);
    digitalWrite(RIGHT_MOTOR_DIR, HIGH);
    analogWrite(RIGHT_MOTOR_PWM, 0);
  }
}

void loop() { 
  Infrared_Tracing(); 
}
