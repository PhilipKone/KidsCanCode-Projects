// C++ code
//
int distance = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(9, OUTPUT);
}

void loop()
{
  distance = 0.01723 * readUltrasonicDistance(3, 2);
  if (distance < 5) {
    tone(9, 523, 1000); // play tone 60 (C5 = 523 Hz)
  }
  if (distance > 5 && distance < 10) {
    tone(9, 587, 1000); // play tone 62 (D5 = 587 Hz)
  }
  if (distance > 10 && distance < 15) {
    tone(9, 440 * pow(2.0, (constrain(int(distance), 35, 127) - 57) / 12.0), 1000);
  }
  if (distance > 15 && distance < 20) {
    tone(9, 698, 1000); // play tone 65 (F5 = 698 Hz)
  }
  if (distance > 20 && distance < 25) {
    tone(9, 784, 1000); // play tone 67 (G5 = 784 Hz)
  }
  if (distance > 25 && distance < 30) {
    tone(9, 880, 1000); // play tone 69 (A5 = 880 Hz)
  }
  if (distance > 30 && distance < 35) {
    tone(9, 988, 1000); // play tone 71 (B5 = 988 Hz)
  }
  if (distance > 35 && distance < 40) {
    tone(9, 1047, 1000); // play tone 72 (C6 = 1047 Hz)
  }
  delay(10); // Delay a little bit to improve simulation performance
}