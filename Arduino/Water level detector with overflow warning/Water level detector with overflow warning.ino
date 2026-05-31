int buzzer = 4;
int red = 5;
int yellow = 6;
int green = 7;
int waterLevel = 0;
int waterPin = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(buzzer, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  waterLevel = analogRead(waterPin);
  Serial.println(waterLevel);
  if(waterLevel > 100 && waterLevel < 550) {
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(buzzer, LOW);
  }
  else if(waterLevel > 550 && waterLevel < 600) {
    digitalWrite(yellow, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(buzzer, LOW);
  }
  else if(waterLevel > 600 && waterLevel < 620) {
    digitalWrite(yellow, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(buzzer, LOW);
  }
  else if(waterLevel > 620) {
    digitalWrite(yellow, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(buzzer, HIGH);
  }
  else {
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    digitalWrite(buzzer, LOW);
  }

}
