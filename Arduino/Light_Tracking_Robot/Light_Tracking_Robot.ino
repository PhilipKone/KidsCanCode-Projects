#include <Servo.h>

int servoPin = 2;
Servo servo;

int leftLDRpin = A0;
int rightLDRpin = A1;
int servoAngle = 90;


void setup() {
  // put your setup code here, to run once:
  pinMode(leftLDRpin, INPUT);
  pinMode(rightLDRpin, INPUT);
  servo.attach(servoPin);
  servo.write(servoAngle);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int leftLightVal = analogRead(leftLDRpin);
  int rightLightVal = analogRead(rightLDRpin);
  Serial.print("Left LDR: ");
  Serial.print(leftLightVal);
  Serial.print("  Right LDR: ");
  Serial.println(rightLightVal);


  servo.write(180);
  //delay(500);
//if(leftLightVal > 900 || rightLightVal > 900){
  if(leftLightVal < rightLightVal) {
    if(servoAngle < 180){
    servoAngle+=2;
    }
    servo.write(servoAngle);
    
  }
  else if(leftLightVal == rightLightVal){
    servo.write(servoAngle);
  }
  else{
    if(servoAngle > 0){
    servoAngle -= 2;
    }
    servo.write(servoAngle);
   
  }
//}

}
