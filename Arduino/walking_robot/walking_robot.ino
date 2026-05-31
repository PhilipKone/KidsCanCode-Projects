#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int trigPin = 6;      // trig pin of HC-SR04
int echoPin = 10;     // Echo pin of HC-SR04
int rightIRPin = 10;  //left IR obstacle avoidance signal pin                                        n...;
int leftIRPin = 11; //right IR obstacle avoidance signal pin



long duration, forwardDistance, leftDistance, rightDistance;

long distance;

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
 
  
  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
  
 servo1.attach(3);           //attach servoPin to servo object
 servo2.attach(5);
 servo3.attach(6);
 servo4.attach(9);

 servo1.write(90);
 servo2.write(90);
 servo3.write(90);
 servo4.write(90);
 delay(2000);
 
}

void loop() {
  //for foot correction
  for(int i=110;i>=90;i--){
    servo3.write(i);
 servo4.write(i);
 delay(15);
  }
  delay(100);
//for foot
  for(int i=90;i>=60;i--){
    servo3.write(i);
 servo4.write(i);
 delay(15);
  }
  delay(100);

  //correction of waist
  for(int i=80;i<=90;i++){
    servo1.write(i);
 servo2.write(i);
 delay(15);
  }
  delay(100);
  
//for waist
  for(int i=90;i<120;i++){
    servo1.write(i);
 servo2.write(i);
 delay(15);
  }
  delay(500);
//for foot
  for(int i=60;i<=110;i++){
    servo3.write(i);
 servo4.write(i);
 delay(15);
  }
  delay(100);
//for waist
 for(int i=120;i>70;i--){
    servo2.write(i);
 servo1.write(i);
 delay(15);
  }
  delay(100);
  

// lookForward();
//
//
//
//  if (forwardDistance > 30)            
//  {
//                                                
//  }
//
//
//  else
//  {    
//    
//    lookLeft();
//   
//    lookRight();
//
//
//   // direction = random(0,10);     
//
//   if(rightDistance > leftDistance) {
//     lookForward();
//      turnRight();
//   }
//    else {
//      lookForward();
//      turnLeft();
//    }
//   
//  }
}

void lookLeft() {

  delay(500);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  leftDistance = duration / 58.2;   // convert to distance 
  delay(500); 

  delay(500);
}

void lookRight() {

delay(500);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  rightDistance = duration / 58.2;   // convert to distance  
  delay(500); 
  //servo.write(90);
}

void lookForward() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  forwardDistance = duration / 58.2;   // convert to distance  
  Serial.println(forwardDistance);
}

void turnRight() {
  
}

void turnLeft() {

}
