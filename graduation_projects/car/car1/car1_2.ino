#include <Servo.h>

Servo paintServo;

void Infrared_Tracing() {
  int L = digitalRead(7);
  int C = digitalRead(8);
  int R = digitalRead(9);
  int White = 0;

  // Read pothole sensors
  int P_L = digitalRead(A1);
  int P_R = digitalRead(A2);

  // --- STABILIZED POTHOLE DETECTION ---
  if (P_L == White || P_R == White) {
    delay(30); 
    if (digitalRead(A1) == White || digitalRead(A2) == White) {
      
      // 1. FULL STOP
      digitalWrite(2, LOW);
      analogWrite(5, 0);
      digitalWrite(4, HIGH);
      analogWrite(6, 0);
      Serial.println("Fixing Pothole...");

      // 2. SERVO ACTION (Happens during the wait)
      paintServo.write(90); // Open
      delay(1000);
      paintServo.write(0);  // Close
      
      // 3. REMAINING WAIT
      delay(3500); // Wait the rest of the 5 seconds

      // 4. SMART RESUME
      // Boost forward just a tiny bit to clear the pothole
      digitalWrite(2, HIGH);
      analogWrite(5, 140);
      digitalWrite(4, LOW);
      analogWrite(6, 140);
      delay(300); 
      
      Serial.println("Resuming Tracking...");
      // No return here - let it go straight into the tracking logic below!
    }
  }

  // --- PERFECT LINE TRACKING ---
  if (L != White && (C == White && R != White)) {
    // Forward (1-0-1)
    digitalWrite(2, HIGH);
    analogWrite(5, 140);
    digitalWrite(4, LOW);
    analogWrite(6, 140);
  } else if (L == White && (C == White && R != White)) {
    // Left (0-0-1)
    digitalWrite(2, LOW);
    analogWrite(5, 110);
    digitalWrite(4, LOW);
    analogWrite(6, 110);
  } else if (L == White && (C != White && R != White)) {
    // Hard Left (0-1-1)
    digitalWrite(2, LOW);
    analogWrite(5, 140);
    digitalWrite(4, LOW);
    analogWrite(6, 140);
  } else if (L != White && (C != White && R == White)) {
    // Right (1-1-0)
    digitalWrite(2, HIGH);
    analogWrite(5, 110);
    digitalWrite(4, HIGH);
    analogWrite(6, 110);
  } else if (L != White && (C == White && R == White)) {
    // Sharp Right (1-0-0)
    digitalWrite(2, HIGH);
    analogWrite(5, 140);
    digitalWrite(4, HIGH);
    analogWrite(6, 140);
  } else if (L == White && (C == White && R == White)) {
    // End of Line (0-0-0)
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
  pinMode(A1, INPUT_PULLUP); 
  pinMode(A2, INPUT_PULLUP); 
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  
  paintServo.attach(10); // Servo on official Pin 10
  paintServo.write(0);
  
  Serial.println("Car 1_2: Advanced Pothole Fixer Ready");
  delay(2000);
}

void loop() { 
  Infrared_Tracing(); 
}
