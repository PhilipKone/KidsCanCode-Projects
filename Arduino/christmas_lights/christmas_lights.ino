int red = 6;
int green = 5;
int yellow = 4;
int buttonPin = 2;
bool state = true;
unsigned int lastPress = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(buttonPin), button_ISR, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  
Serial.println(state);
  if (state == true) {
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(500);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(200);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(400);
  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);
  delay(200);
  }

  else if (state == false) {
    digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(1000);
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  delay(2000);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(1000);
  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);
  delay(2000);
  }

}

void button_ISR () {
  if((millis()-lastPress) > 500) {
   lastPress = millis();
    state = !state;
  }
}
