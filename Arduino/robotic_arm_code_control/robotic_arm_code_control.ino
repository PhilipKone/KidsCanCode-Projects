#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

int waistAngle = 90;
int armAngle = 90;
int gripAngle = 180;
bool grip = false;
long unsigned int lastPress = 0;
int debounceTime = 500; 


void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  
 servo1.attach(3);           //attach servoPin to servo object
 servo2.attach(5);
 servo3.attach(6);

 servo1.write(90);
 servo2.write(90);
 servo3.write(180);
 
 delay(2000);
 
}

void loop() {

//////////Write robot commands here/////////////

///////Robot commands://////////

//turnLeft(): makes robot turn to the left
//turnRight(): makes robot turn to the right
//raiseUp(): makes robot lift its arm
//lowerArm(): makes robot bring its arm down
//openJaw(): makes robot open its jaw
//closeJaw(): makes robot close its jaw


turnLeft(100);

turnRight(150);

lowerArm(40);













}



void turnRight(int angle) {
 
  for(int i=waistAngle;i<=angle;i++){
    servo1.write(i);
    waistAngle = i;
 delay(15);
  }
  
  delay(500);
}


void turnLeft(int angle) {
  int res = waistAngle - angle;
 for(int i=waistAngle;i>=res;i--){
    servo1.write(i);
    waistAngle = i;
 delay(15);
 }
  delay(500);
}


void raiseArm(int angle) {
  for(int i=armAngle;i<=angle;i++){
    servo2.write(i);
    armAngle = i;
 delay(15);
  }

    for(int i=armAngle;i>=angle;i--){
    servo2.write(i);
    armAngle = i;
 delay(15);
    }
  
  delay(500);
}

void lowerArm(int angle) {
    int res = armAngle - angle;
    for(int i=armAngle;i>=res;i--){
    servo2.write(i);
    armAngle = i;
 delay(15);
    }
  
  delay(500);
}


void closeJaw() {
  
    servo3.write(140);
 delay(500);
}

void openJaw() {
  
    servo3.write(180);
    delay(500);
}
