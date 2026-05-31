#include <Servo.h>   //servo library
Servo servo;    
int trigPin = 5;   
int echoPin = 6;  
int servoPin = 7;
int redLed= 12;
int greenLed= 11;
long duration, dist, average;  
long aver[3];   //array for averaxge
void setup() {      
    Serial.begin(9600);
    servo.attach(servoPin); 
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);  
    servo.write(180);         //close cap on power on
    delay(100);
    servo.detach();
}
void measure() { 
  delay(100);
 digitalWrite(10,HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);   
dist = (duration/2) / 29.1;    //obtain distance
}
void loop() {
  for (int i=0;i<=2;i++) {   //average distance
    measure();              
   aver[i]=dist;           
    delay(10);              //delay between measurements
  }
 dist=(aver[0]+aver[1]+aver[2])/3;   
if ( dist<20 ) {
//Change distance as per your need
digitalWrite(redLed, LOW);
digitalWrite(greenLed, HIGH);
delay(500);
 servo.attach(servoPin);
  delay(1);
 servo.write(90); 
 delay(3000);      
 servo.write(180);   
 delay(1000);
 servo.detach();  
 digitalWrite(redLed, HIGH);
digitalWrite(greenLed, LOW);   
}
Serial.println(dist);
}
