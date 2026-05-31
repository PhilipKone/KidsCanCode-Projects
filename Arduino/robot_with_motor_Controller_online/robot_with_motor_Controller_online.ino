int trigPin = 6;      // trig pin of HC-SR04
int echoPin = 2;     // Echo pin of HC-SR04
int piezoPin = 11;    // positive pin of passive buzzer

int enA = 5;
int enB = 9;
int revleft = 7;       //REVerse motion of Left motor
int fwdleft = 8;       //ForWarD motion of Left motor
int revright = 4;      //REVerse motion of Right motor
int fwdright = 3;      //ForWarD motion of Right motor

long duration, distance;

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(revleft, OUTPUT);      // set Motor pins as output
  pinMode(fwdleft, OUTPUT);
  pinMode(revright, OUTPUT);
  pinMode(fwdright, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  distance = duration / 58.2;   // convert to distance
  //delay(10);
  
    // If you dont get proper movements of your robot then alter the pin numbers
  if (distance > 10)            
  {
    digitalWrite(fwdright, HIGH);                    // move forward
    digitalWrite(revright, LOW);
    analogWrite(enB, 200);
    digitalWrite(fwdleft, HIGH);                                
    digitalWrite(revleft, LOW);   
    analogWrite(enA, 220);                                                    
  }

  else
  {
    
    digitalWrite(fwdright, LOW);  //Stop                
    digitalWrite(revright, LOW);
    analogWrite(enA, 0);
    digitalWrite(fwdleft, LOW);                                
    digitalWrite(revleft, LOW);
    analogWrite(enB, 0);
    tone(piezoPin, 1000, 750);  //beep at 1000 Hz for 250 microseconds
    //delay(750);
    //tone(piezoPin, 1000, 250);  //beep at 1000 Hz for 250 microseconds
    digitalWrite(fwdright, LOW);      //move backward         
    digitalWrite(revright, HIGH);
    analogWrite(enA, 200);
    digitalWrite(fwdleft, LOW);                                
    digitalWrite(revleft, HIGH);
    analogWrite(enB, 200);
    delay(250);
    //tone(piezoPin, 1000, 250);  //beep at 1000 Hz for 250 microseconds
    digitalWrite(fwdright, LOW);  //Stop                
    digitalWrite(revright, LOW);
    analogWrite(enA, 0);
    digitalWrite(fwdleft, LOW);                                
    digitalWrite(revleft, LOW); 
    analogWrite(enB, 0); 
    delay(500);  
    tone(piezoPin, 1000, 250);  //beep at 1000 Hz for 250 microseconds
    digitalWrite(fwdright, LOW);      //Turn         
    digitalWrite(revright, HIGH);
    analogWrite(enA, 150);
    digitalWrite(fwdleft, HIGH);                                
    digitalWrite(revleft, LOW);
    analogWrite(enB, 150);
    delay(300);
    //tone(piezoPin, 1000, 250);  //beep at 1000 Hz for 250 microseconds
    digitalWrite(fwdright, LOW);  //Stop                
    digitalWrite(revright, LOW);
    analogWrite(enA, 0);
    digitalWrite(fwdleft, LOW);                                
    digitalWrite(revleft, LOW); 
    analogWrite(enB, 0); 
    delay(450);  
    tone(piezoPin, 1000, 250);  //beep at 1000 Hz for 250 microseconds
    delay(250); 
  }

}


