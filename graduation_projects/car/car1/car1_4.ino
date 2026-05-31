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

// Memory variable to track the last steering direction:
// -1 = Left Turn, 1 = Right Turn, 0 = Straight / Centered
int lastTurnDirection = 0; 

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
  
  Serial.println("Car 1_4: FULL SYSTEM ONLINE (U-Turn & Pothole Safeguards Active)");
  delay(2000);
}

void Infrared_Tracing() {
  int L = digitalRead(LINE_L);
  int C = digitalRead(LINE_C);
  int R = digitalRead(LINE_R);

  // Read pothole sensors
  int P_L = digitalRead(POTHOLE_L);
  int P_R = digitalRead(POTHOLE_R);

  // --- SAFE POTHOLE REPAIR LOGIC ---
  // Only check potholes when the car is relatively straight (Center sees the line)
  // This prevents fake stops when turning sharply across a curve!
  if (C == White && (P_L == White || P_R == White)) {
    delay(40); // Double-check debounce delay
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

  // --- LINE TRACKING WITH MEMORY & SMART TURN SPEEDS ---
  if (L != White && (C == White && R != White)) {
    // 1. Forward (Both sensors off-line, center on-line)
    digitalWrite(2, HIGH);
    analogWrite(5, 140);
    digitalWrite(4, LOW);
    analogWrite(6, 140);
    lastTurnDirection = 0; // Centered
    
  } else if (L == White && (C == White && R != White)) {
    // 2. Slight Left Turn (Slow and smooth)
    digitalWrite(2, LOW);
    analogWrite(5, 95);
    digitalWrite(4, LOW);
    analogWrite(6, 95);
    lastTurnDirection = -1; // Remember left turn
    
  } else if (L == White && (C != White && R != White)) {
    // 3. Sharp Left Turn (Slightly slower for grip, but still sharp)
    digitalWrite(2, LOW);
    analogWrite(5, 110);
    digitalWrite(4, LOW);
    analogWrite(6, 110);
    lastTurnDirection = -1; // Remember left turn
    
  } else if (L != White && (C != White && R == White)) {
    // 4. Slight Right Turn (Slow and smooth)
    digitalWrite(2, HIGH);
    analogWrite(5, 95);
    digitalWrite(4, HIGH);
    analogWrite(6, 95);
    lastTurnDirection = 1; // Remember right turn
    
  } else if (L != White && (C == White && R == White)) {
    // 5. Sharp Right Turn (Slightly slower for grip, but still sharp)
    digitalWrite(2, HIGH);
    analogWrite(5, 110);
    digitalWrite(4, HIGH);
    analogWrite(6, 110);
    lastTurnDirection = 1; // Remember right turn
    
  } else if (L == White && (C == White && R == White)) {
    // 6. Stop Line / Intersection
    digitalWrite(2, LOW);
    analogWrite(5, 0);
    digitalWrite(4, HIGH);
    analogWrite(6, 0);
    
  } else if (L != White && (C != White && R != White)) {
    // 7. TRACK LOST RECOVERY STATE (e.g. Sharp U-Turns)
    // Spin in the direction of the last known turn to find the line again!
    if (lastTurnDirection == -1) {
      // Spin Left safely
      digitalWrite(2, LOW);
      analogWrite(5, 100);
      digitalWrite(4, LOW);
      analogWrite(6, 100);
      Serial.println("Line lost! Searching LEFT...");
    } else if (lastTurnDirection == 1) {
      // Spin Right safely
      digitalWrite(2, HIGH);
      analogWrite(5, 100);
      digitalWrite(4, HIGH);
      analogWrite(6, 100);
      Serial.println("Line lost! Searching RIGHT...");
    } else {
      // If we don't know which way, go forward slowly to find it
      digitalWrite(2, HIGH);
      analogWrite(5, 80);
      digitalWrite(4, LOW);
      analogWrite(6, 80);
      Serial.println("Line lost! Searching FORWARD...");
    }
  }
}

void loop() { 
  Infrared_Tracing(); 
}
