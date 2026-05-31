
int buzzer = 8;
int sensorPin = A0;              
int redLed = 6;
int greenLed = 5;
int Signal;     //this will be used to read the state of the PIR sensor



void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Signal = analogRead(sensorPin);
  Serial.println(Signal);
  if (Signal > 1)
  {
//    digitalWrite(buzzer, HIGH);
//    digitalWrite(led, HIGH);
digitalWrite(greenLed, LOW);
     startAlarm();
  }
  else
  {
    digitalWrite(buzzer, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    
  }

}

void startAlarm() {
  for(int x=0; x<10; x++){
    digitalWrite(buzzer, HIGH);
    digitalWrite(redLed, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    digitalWrite(redLed, LOW);
    delay(500);
  }
}
