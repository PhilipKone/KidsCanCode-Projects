#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

int waistAngle = 0;
int armAngle = 0;
int gripAngle = 0;
bool grip = false;
long unsigned int lastPress = 0;
int debounceTime = 500; 
int pot_1_position[10];
int pot_2_position[10];
int pot_3_position[10];
int number_of_steps = 0;
bool play_mode = false;
bool record_mode = true;

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  
 servo1.attach(5);           //attach servoPin to servo object
 servo2.attach(6);
 servo3.attach(9);

 servo1.write(90);
 servo2.write(90);
 servo3.write(40);

 attachInterrupt(digitalPinToInterrupt(2), play_steps, CHANGE);

 attachInterrupt(digitalPinToInterrupt(3), record_steps, CHANGE);
 
 delay(2000);
 
}

void loop() {

waistAngle = map(analogRead(A0), 0, 1023, 0, 180);
armAngle = map(analogRead(A1), 0, 1023, 0, 180);
gripAngle = map(analogRead(A2), 0, 1023, 0, 180);

  Serial.println(gripAngle);
if(record_mode) {
  //Serial.println("in record mode");
  servo1.write(waistAngle);
  servo2.write(armAngle);
  servo3.write(gripAngle);

//  if(grip == 1) {
//    servo3.write(75);
//  }
//  else {
//    servo3.write(40);
//  }
}


 else {
  //Serial.println("in play mode");
  int temp = number_of_steps;
  Serial.println("number of steps");
  Serial.println(temp);
  int tempWaistAngle = waistAngle;
  int tempArmAngle = armAngle;
  int tempGripAngle = gripAngle;

  for(int steps=0;steps<temp;steps++) {
//    servo1.write(pot_1_position[steps]);
//    servo2.write(pot_2_position[steps]);
//    servo3.write(pot_3_position[steps]);

if(tempWaistAngle < pot_1_position[steps]){
    for(int i = tempWaistAngle; i<pot_1_position[steps]; i++){
      servo1.write(i);
      delay(20);
      tempWaistAngle = i;
    }
    }
    else {
      for(int i = tempWaistAngle; i>pot_1_position[steps]; i--){
      servo1.write(i);
      delay(20);


      tempWaistAngle = i;
    }
    } 

    if(tempArmAngle < pot_2_position[steps]){
    for(int i = tempArmAngle; i<pot_2_position[steps]; i++){
      servo2.write(i);
      delay(20);
      tempArmAngle = i;
    }
    }
    else {
      for(int i = tempArmAngle; i>pot_2_position[steps]; i--){
      servo2.write(i);
      delay(20);
      tempArmAngle = i;
    }
    }

        if(tempGripAngle < pot_3_position[steps]){
    for(int i = tempGripAngle; i<pot_3_position[steps]; i++){
      servo3.write(i);
      delay(20);
      tempGripAngle = i;
    }
    }
    else {
      for(int i = tempGripAngle; i>pot_3_position[steps]; i--){
      servo3.write(i);
      delay(20);
      tempGripAngle = i;
    }
    }

delay(500);
  }
  //number_of_steps = 0;
 }


}

//void toggle_grip() {
//  if((millis()-lastPress) > debounceTime) {
//      lastPress = millis(); 
// 
//      grip = !grip;
//      Serial.println("inside interrupt");
//      Serial.println(grip);
// 
//    }
//}

void record_steps() {
  if((millis()-lastPress) > debounceTime) {
      lastPress = millis();

      if(record_mode) {
      Serial.println("recording...");

        pot_1_position[number_of_steps] = waistAngle;
 pot_2_position[number_of_steps] = armAngle;
 pot_3_position[number_of_steps] = gripAngle;
 Serial.println("pot1");
 Serial.println(pot_1_position[number_of_steps]);
 Serial.println("pot2");
 Serial.println(pot_2_position[number_of_steps]);
 Serial.println("pot3");
 Serial.println(pot_3_position[number_of_steps]);
      number_of_steps++;
      }
 
    }
}

void play_steps() {
  if((millis()-lastPress) > debounceTime) {
      lastPress = millis();

delay(5000);
       
      record_mode = !record_mode;
      if(record_mode) {
        Serial.println("recording...");
        number_of_steps = 0;
      }
      else Serial.println("playing...");
      
 
    }
}
