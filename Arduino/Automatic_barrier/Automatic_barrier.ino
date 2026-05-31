#include <Servo.h>

// int trigPin = 6;      // trig pin of HC-SR04
// int echoPin = 4;     // Echo pin of HC-SR04
int IRPin = 7;
int servoPin = 2;
Servo servo;
long distance, duration;
int redPin = 12;
int greenPin = 11;   

void setup() {
  // put your setup code here, to run once:
  // pinMode(trigPin, OUTPUT);         // set trig pin as output
  // pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
  pinMode(IRPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  servo.attach(servoPin); 
  servo.write(90);
  Serial.begin(9600);

  
}

void loop() {
  // put your main code here, to run repeatedly:
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);   
//   digitalWrite(trigPin, HIGH);     // send waves for 10 us
//   delayMicroseconds(10);
//   duration = pulseIn(echoPin, HIGH); // receive reflected waves
//   distance = duration / 58.2;   // convert to distance
//   delay(10);
// Serial.println(distance);
Serial.println(digitalRead(IRPin));

if (digitalRead(IRPin) == HIGH) {
  //delay(500);
servo.write(30);
digitalWrite(redPin, LOW);
digitalWrite(greenPin, HIGH);
delay(3000);
}
else {
  digitalWrite(redPin, HIGH);
digitalWrite(greenPin, LOW);
  servo.write(90);
  }

}
