void Infrared_Tracing() {
  int L = digitalRead(7);
  int C = digitalRead(8);
  int R = digitalRead(9);
  int White = 0;

  // Read pothole sensors
  int P_L = digitalRead(A1);
  int P_R = digitalRead(A2);

  // --- DEBUG PRINTING ---
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint > 500) { 
    Serial.print("LCR="); Serial.print(L); Serial.print(C); Serial.print(R);
    Serial.print(" | POT="); Serial.print(P_L); Serial.println(P_R);
    lastPrint = millis();
  }

  // --- TRIPLE-CHECK POTHOLE LOGIC ---
  if (P_L == White || P_R == White) {
    delay(20); // Wait a tiny bit
    if (digitalRead(A1) == White || digitalRead(A2) == White) {
      delay(20); // Wait again
      if (digitalRead(A1) == White || digitalRead(A2) == White) {
        // ONLY STOP IF WE SEE IT 3 TIMES
        digitalWrite(2, LOW);
        analogWrite(5, 0);
        digitalWrite(4, HIGH);
        analogWrite(6, 0);
        Serial.println("!!! REAL POTHOLE DETECTED !!!");
        
        delay(5000); // Your 5 second wait

        // Boost past it
        digitalWrite(2, HIGH);
        analogWrite(5, 160);
        digitalWrite(4, LOW);
        analogWrite(6, 160);
        delay(600); 
        return; 
      }
    }
  }

  // --- ROBUST LINE TRACKING ---
  if (L != White && (C == White && R != White)) {
    // Forward
    digitalWrite(2, HIGH);
    analogWrite(5, 140);
    digitalWrite(4, LOW);
    analogWrite(6, 140);
  } else if (L == White && (C == White && R != White)) {
    // Left
    digitalWrite(2, LOW);
    analogWrite(5, 120);
    digitalWrite(4, LOW);
    analogWrite(6, 120);
  } else if (L == White && (C != White && R != White)) {
    // Hard Left
    digitalWrite(2, LOW);
    analogWrite(5, 150);
    digitalWrite(4, LOW);
    analogWrite(6, 150);
  } else if (L != White && (C != White && R == White)) {
    // Right
    digitalWrite(2, HIGH);
    analogWrite(5, 120);
    digitalWrite(4, HIGH);
    analogWrite(6, 120);
  } else if (L != White && (C == White && R == White)) {
    // Sharp Right
    digitalWrite(2, HIGH);
    analogWrite(5, 150);
    digitalWrite(4, HIGH);
    analogWrite(6, 150);
  } else {
    // IF LOST (111), don't stop immediately, just slow down and coast
    // This gives it a chance to find the line again.
    analogWrite(5, 50); 
    analogWrite(6, 50);
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
  Serial.println("STABILIZED SYSTEM READY");
}

void loop() { 
  Infrared_Tracing(); 
}
