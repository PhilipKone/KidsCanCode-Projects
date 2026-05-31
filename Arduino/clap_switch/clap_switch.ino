int led1 = 5;
int led2 = 6;
int led3 = 7;
int sensorPin = 2;
int sensorVal = 0;
bool ledState = false;
int interruptPin = 2;
int numberOfClaps = 0;
long unsigned int lastClapTime = 0;
long unsigned int temp = 0;
int debounceTime = 200;
int ledSelect = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
//attach interrupt
  attachInterrupt(digitalPinToInterrupt(sensorPin), ISR_turn_leds_on, CHANGE);
}

void loop() {

  
  // put your main code here, to run repeatedly:
  sensorVal = digitalRead(sensorPin);
  Serial.println(sensorVal);
//  Serial.println("led select");
//  Serial.println(ledSelect);
//  delay(100);

if(numberOfClaps == 1) {
  delay(2000);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}
else if(numberOfClaps == 2) {
  delay(2000);
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led3, LOW);
}
else if(numberOfClaps == 3) {
  delay(2000);
  digitalWrite(led3, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}
else {
  //delay(1000);
  digitalWrite(led3, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

  
  
}


//Interupt Service routine
void ISR_turn_leds_on() {
  if((millis()-lastClapTime) > debounceTime) {
      temp = lastClapTime;
      lastClapTime = millis(); 
      Serial.println("Inside interrupt");

      if((millis()- temp) > 2000) {
        numberOfClaps = 1;
      } else {
      
      numberOfClaps++;
      }
      Serial.println("number of claps: ");
      Serial.print(numberOfClaps);

      if(numberOfClaps > 3) {
        numberOfClaps = 0;
      }
      
      
    }
  
}
