const int trigPin = 3;
const int echoPin = 2;
const int buzzer = 5;

long duration;
int distance;
int safetyDistance;

// Adjust this value to change the speed of sound for your environment
const float speedOfSound = 0.0343; // 343 meters per second (default)

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  // Calculate distance using the adjusted speed of sound value
  distance = (duration * speedOfSound) / 2;
  safetyDistance = distance;

  if (safetyDistance <= 30) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  Serial.print("Distance: ");
  Serial.println(distance);
}
