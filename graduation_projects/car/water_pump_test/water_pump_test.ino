/*
  Water Pump Test Project
  This code will turn the pump ON for 3 seconds and OFF for 3 seconds.
*/

const int PUMP_PIN = 11; // Connect your transistor base or relay to Pin 3

void setup() {
  Serial.begin(9600);
  pinMode(PUMP_PIN, OUTPUT);
  Serial.println("--- Water Pump Test Starting ---");
}

void loop() {
  // Turn PUMP ON
  Serial.println("Pump status: ON");
  digitalWrite(PUMP_PIN, HIGH);
  delay(30); // Wait 3 seconds

  // Turn PUMP OFF
  Serial.println("Pump status: OFF");
  digitalWrite(PUMP_PIN, LOW);
  delay(300000); // Wait 3 seconds
}
