#include <Servo.h>

int servoPin = 2;
Servo servo;
int trigPin = 3;      // trig pin of HC-SR04
int echoPin = 11;     // Echo pin of HC-SR04
int rightIRPin = 10;  //left IR obstacle avoidance signal pin...;
int leftIRPin = 11; //right IR obstacle avoidance signal pin

int enA = 9;
int enB = 10;
int revLeft = 4;       //REVerse motion of Left motor
int fwdLeft = 5;       //ForWarD motion of Left motor
int fwdRight = 6;      //REVerse motion of Right motor
int revRight = 7;      //ForWarD motion of Right motor

long duration, forwardDistance, leftDistance, rightDistance;
int rightIRVal = HIGH;
int leftIRVal = HIGH;
long dist;
long aver[3];   //array for averaxge

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
//Serial.println(dist);
//  turnRight();

  


  for (int i=0;i<=2;i++) {   //average distance
     measure();              
    aver[i]=dist;           
     delay(10);              //delay between measurements
   }
  dist=(aver[0]+aver[1]+aver[2])/3;   

  Serial.println(dist);

   if (dist > 30)            
   {
 //For left motor
     digitalWrite(fwdLeft, LOW);                                
     digitalWrite(revLeft, HIGH);  
     analogWrite(enA, 80);

     //for right motor
      digitalWrite(fwdRight, HIGH);                    // move forward
     digitalWrite(revRight, LOW);
     analogWrite(enB, 80);    

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
     analogWrite(enB, 70);
     delay(500);
        
     digitalWrite(revRight, LOW);  //Stop                
     digitalWrite(fwdRight, LOW);
     analogWrite(enA, 0);
     digitalWrite(fwdLeft, LOW);                                
     digitalWrite(revLeft, LOW); 
     analogWrite(enB, 0); 
     delay(500);  

 turnRight();
  
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
    // digitalWrite(fwdLeft, HIGH);           //Turn right                     
    // digitalWrite(revLeft, LOW);  
    // analogWrite(enA, 255);

    //for right motor
     digitalWrite(revRight, HIGH);                    
    digitalWrite(fwdRight, LOW);
    digitalWrite(enB, HIGH);    
    //delay(300);  
}

void turnLeft() {
  //For left motor
    digitalWrite(fwdLeft, LOW);           //Turn right                     
    digitalWrite(revLeft, HIGH);  
    digitalWrite(enB, HIGH);

    //for right motor
     digitalWrite(revRight, LOW);                    
    digitalWrite(fwdRight, HIGH);
    analogWrite(enA, 80);    
    delay(300);  
}
