#include <Servo.h>

Servo servo1;

int distance = 0;
int trig = 11; //trig pin of ultrasonic sensor
int echo = 12; //echo pin of ultrasonic sensor



void setup() {
  
  delay(random(500,2000));   // delay for random time
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  
  Serial.begin(9600);
  
 servo1.attach(2);           //attach servoPin to servo object
 
 delay(2000);
 
}

void loop() {

  //Ultrasonic Sensor Measures distance
//trigger the ultrasonic sensor for 10 microseconds to send out 8 pulses
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 
  long duration = pulseIn(echo, HIGH); 
  int distance = duration*0.034/2; 
  Serial.print("Distance in cm : "); 
  Serial.println(distance); 

int angle = map(distance, 0, 20, 0, 180);


  Serial.println(angle);

  servo1.write(angle);
  


}
