#include <Servo.h>

int servoPin = 2;
Servo servo;
int trigPin = 6;      // trig pin of HC-SR04
int echoPin = 10;     // Echo pin of HC-SR04
int rightIRPin = 10;  //left IR obstacle avoidance signal pin                                        n...;
int leftIRPin = 11; //right IR obstacle avoidance signal pin

int enA = 5;
int enB = 11;
int revLeft = 7;       //REVerse motion of Left motor
int fwdLeft = 8;       //ForWarD motion of Left motor
int fwdRight = 4;      //REVerse motion of Right motor
int revRight = 3;      //ForWarD motion of Right motor

long duration, forwardDistance, leftDistance, rightDistance;
int rightIRVal = HIGH;
int leftIRVal = HIGH;
long distance;

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(revLeft, OUTPUT);      // set Motor pins as output
  pinMode(fwdLeft, OUTPUT);
  pinMode(fwdRight, OUTPUT);
  pinMode(revRight, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
  pinMode(rightIRPin, INPUT);
  pinMode(leftIRPin, INPUT);
 servo.attach(servoPin);           //attach servoPin to servo object
}

void loop() {
  

 lookForward();

//  controlRobot();
//  delay(500);
//  servo.write(135);
//  controlRobot();
//  delay(500);
//  servo.write(90);
//  controlRobot();
//  delay(500);
//  servo.write(45);
//  controlRobot();
//  delay(500);

// rightIRVal = digitalRead(rightIRPin);
// leftIRVal = digitalRead(leftIRPin);

// digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);   
//   digitalWrite(trigPin, HIGH);     // send waves for 10 us
//   delayMicroseconds(10);
//   duration = pulseIn(echoPin, HIGH); // receive reflected waves
//   distance = duration / 58.2;   // convert to distance
//   delay(10);
// Serial.println(distance);
//     If you dont get proper movements of your robot then alter the pin numbers


  if (forwardDistance > 30)            
  {
//For left motor
    digitalWrite(fwdLeft, HIGH);                                
    digitalWrite(revLeft, LOW);  
    analogWrite(enB, 85);

    //for right motor
     digitalWrite(fwdRight, HIGH);                    // move forward
    digitalWrite(revRight, LOW);
    analogWrite(enA, 90);                                                    
  }


  else
  {    
    digitalWrite(revRight, LOW);  //Stop                
    digitalWrite(fwdRight, LOW);
    analogWrite(enA, 0);
    digitalWrite(fwdLeft, LOW);                                
    digitalWrite(revLeft, LOW); 
    analogWrite(enB, 0); 
    delay(1000);  
    
    digitalWrite(fwdRight, LOW);      //movebackword         
    digitalWrite(revRight, HIGH);
    analogWrite(enA, 90);
    digitalWrite(fwdLeft, LOW);                                
    digitalWrite(revLeft, HIGH);
    analogWrite(enB, 85);
    delay(500);
        
    digitalWrite(revRight, LOW);  //Stop                
    digitalWrite(fwdRight, LOW);
    analogWrite(enA, 0);
    digitalWrite(fwdLeft, LOW);                                
    digitalWrite(revLeft, LOW); 
    analogWrite(enB, 0); 
    delay(500);  

    lookLeft();
   
    lookRight();


   // direction = random(0,10);     

   if(rightDistance > leftDistance) {
     lookForward();
      turnRight();
   }
    else {
      lookForward();
      turnLeft();
    }
   
  }
}

void lookLeft() {
servo.write(180);
  delay(500);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  leftDistance = duration / 58.2;   // convert to distance 
  delay(500); 
  servo.write(90);
  delay(500);
}

void lookRight() {
servo.write(0);
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
servo.write(90);
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
  //For left motor
    digitalWrite(fwdLeft, HIGH);           //Turn right                     
    digitalWrite(revLeft, LOW);  
    analogWrite(enB, 85);

    //for right motor
     digitalWrite(revRight, HIGH);                    
    digitalWrite(fwdRight, LOW);
    analogWrite(enA, 90);    
    delay(300);  
}

void turnLeft() {
  //For left motor
    digitalWrite(fwdLeft, LOW);           //Turn right                     
    digitalWrite(revLeft, HIGH);  
    analogWrite(enB, 85);

    //for right motor
     digitalWrite(revRight, LOW);                    
    digitalWrite(fwdRight, HIGH);
    analogWrite(enA, 90);    
    delay(300);  
}
