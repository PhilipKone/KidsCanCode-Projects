#include <Servo.h>

// Pin Definitions
const int PUMP_PIN = 11;
const int SERVO_PIN = 10;
const int POTHOLE_L = A1;
const int POTHOLE_R = A2;
const int LINE_L = 7;
const int LINE_C = 8;
const int LINE_R = 9;

Servo paintServo;
int White = 0;

void setup() {
  Serial.begin(9600);
  
  // Setup Sensors
  pinMode(LINE_L, INPUT);
  pinMode(LINE_C, INPUT);
  pinMode(LINE_R, INPUT);
  pinMode(POTHOLE_L, INPUT_PULLUP);
  pinMode(POTHOLE_R, INPUT_PULLUP);
  
  // Setup Outputs
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  
  // Setup Servo
  paintServo.attach(SERVO_PIN);
  paintServo.write(0); // Start Closed
  
  digitalWrite(PUMP_PIN, LOW); // Ensure pump is OFF
  
  Serial.println("Car 1_3: FULL SYSTEM ONLINE (Pump + Servo)");
  delay(2000);
}

void Infrared_Tracing() {
  int L = digitalRead(LINE_L);
  int C = digitalRead(LINE_C);
  int R = digitalRead(LINE_R);

  // Read pothole sensors
  int P_L = digitalRead(POTHOLE_L);
  int P_R = digitalRead(POTHOLE_R);

  // --- STABILIZED POTHOLE REPAIR LOGIC ---
  if (P_L == White || P_R == White) {
    delay(40); 
    if (digitalRead(POTHOLE_L) == White || digitalRead(POTHOLE_R) == White) {
      
      // 1. FULL STOP
      digitalWrite(2, LOW);
      analogWrite(5, 0);
      digitalWrite(4, HIGH);
      analogWrite(6, 0);
      Serial.println("!!! REPAIR IN PROGRESS !!!");

      // 2. DISPENSE (Servo + Pump)
      paintServo.write(90);        // Lower the arm
      delay(500);
      digitalWrite(PUMP_PIN, HIGH); // Turn on the pump
      delay(2000);                 // Spray for 2 seconds
      digitalWrite(PUMP_PIN, LOW);  // Turn off the pump
      
      // 3. RESET
      paintServo.write(0);         // Raise the arm
      delay(1000);
      
      // 4. SMART RESUME
      digitalWrite(2, HIGH);
      analogWrite(5, 150);
      digitalWrite(4, LOW);
      analogWrite(6, 150);
      delay(400); 
      
      Serial.println("Repair Complete. Resuming...");
    }
  }

  // --- LINE TRACKING ---
  if (L != White && (C == White && R != White)) {
    digitalWrite(2, HIGH);
    analogWrite(5, 140);
    digitalWrite(4, LOW);
    analogWrite(6, 140);
  } else if (L == White && (C == White && R != White)) {
    digitalWrite(2, LOW);
    analogWrite(5, 110);
    digitalWrite(4, LOW);
    analogWrite(6, 110);
  } else if (L == White && (C != White && R != White)) {
    digitalWrite(2, LOW);
    analogWrite(5, 140);
    digitalWrite(4, LOW);
    analogWrite(6, 140);
  } else if (L != White && (C != White && R == White)) {
    digitalWrite(2, HIGH);
    analogWrite(5, 110);
    digitalWrite(4, HIGH);
    analogWrite(6, 110);
  } else if (L != White && (C == White && R == White)) {
    digitalWrite(2, HIGH);
    analogWrite(5, 140);
    digitalWrite(4, HIGH);
    analogWrite(6, 140);
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
