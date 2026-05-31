
int trigPinForward = 2;      // trig pin of HC-SR04
int echoPinForward = 3;     // Echo pin of HC-SR04
int trigPinRight = 4;      // trig pin of HC-SR04
int echoPinRight= 5;     // Echo pin of HC-SR04
int trigPinLeft = 6;      // trig pin of HC-SR04
int echoPinLeft = 7;     // Echo pin of HC-SR04
int enA = 9;
int enB = 10;
int revLeft = 8;       //REVerse motion of Left motor
int fwdLeft = 11;       //ForWarD motion of Left motor
int fwdRight = 12;      //REVerse motion of Right motor
int revRight = 13;      //ForWarD motion of Right motor

long duration, forwardDistance, leftDistance, rightDistance;

long distance;

bool isInitialized = false;
bool goRight = true;

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(revLeft, OUTPUT);      // set Motor pins as output
  pinMode(fwdLeft, OUTPUT);
  pinMode(fwdRight, OUTPUT);
  pinMode(revRight, OUTPUT);
  
  pinMode(trigPinForward, OUTPUT);         // set trig pin as output
  pinMode(echoPinForward, INPUT);          //set echo pin as input to capture reflected waves
  pinMode(trigPinRight, OUTPUT);         // set trig pin as output
  pinMode(echoPinRight, INPUT);          //set echo pin as input to capture reflected waves
  pinMode(trigPinLeft, OUTPUT);         // set trig pin as output
  pinMode(echoPinLeft, INPUT);          //set echo pin as input to capture reflected waves

  Serial.begin(9600);
}

void loop() {
  


lookForward();





  if (forwardDistance > 30)            
  {
//For left motor
    digitalWrite(fwdLeft, HIGH);                                
    digitalWrite(revLeft, LOW);  
    analogWrite(enB, 130);

    //for right motor
     digitalWrite(fwdRight, HIGH);                    // move forward
    digitalWrite(revRight, LOW);
    analogWrite(enA, 90);                                                    
  }


  else
  {    
    lookRight();
    lookLeft();
    
    if(!isInitialized){
      initialize();
    }
    if(rightDistance < 30) {
//     lookForward();
//      turnRight();
  goRight = false;
  
   }
   
   else if(leftDistance < 30) {
    goRight = true;
   }
   else {
    goRight = !goRight;
   }

   if (goRight) {
    cleanRight();
   }
   else {
    cleanLeft();
   }
    


   // direction = random(0,10);     

//   if(rightDistance > leftDistance) {
//     lookForward();
//      turnRight();
//   }
//    else {
//      lookForward();
//      turnLeft();
//    }
   
  }
}

void lookLeft() {

  digitalWrite(trigPinLeft, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPinLeft, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  digitalWrite(trigPinLeft, LOW);
  duration = pulseIn(echoPinLeft, HIGH); // receive reflected waves
  leftDistance = duration / 58.2;   // convert to distance  
  Serial.println("Left"); 
  Serial.println(leftDistance); 
}

void lookRight() {

  digitalWrite(trigPinRight, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPinRight, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  digitalWrite(trigPinRight, LOW);
  duration = pulseIn(echoPinRight, HIGH); // receive reflected waves
  rightDistance = duration / 58.2;   // convert to distance  
  Serial.println("Right"); 
  Serial.println(rightDistance); 
}

void lookForward() {
  digitalWrite(trigPinForward, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPinForward, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  digitalWrite(trigPinForward, LOW);
  duration = pulseIn(echoPinForward, HIGH); // receive reflected waves
  forwardDistance = duration / 58.2;   // convert to distance 
  Serial.println("Forward"); 
  Serial.println(forwardDistance);
}


void cleanLeft() {
  digitalWrite(revRight, LOW);  //Stop                
    digitalWrite(fwdRight, LOW);
    analogWrite(enA, 0);
    digitalWrite(fwdLeft, LOW);                                
    digitalWrite(revLeft, LOW); 
    analogWrite(enB, 0); 
    delay(1000);  
    
    digitalWrite(fwdRight, HIGH);      //Turn left         
    digitalWrite(revRight, LOW);
    analogWrite(enA, 90);
    digitalWrite(fwdLeft, LOW);                                
    digitalWrite(revLeft, HIGH);
    analogWrite(enB, 120);
    delay(500);
        
    digitalWrite(revRight, LOW);  //Stop                
    digitalWrite(fwdRight, LOW);
    analogWrite(enA, 0);
    digitalWrite(fwdLeft, LOW);                                
    digitalWrite(revLeft, LOW); 
    analogWrite(enB, 0); 
    delay(1000);  

    //For left motor
    digitalWrite(fwdLeft, HIGH);              // move forward                   
    digitalWrite(revLeft, LOW);  
    analogWrite(enB, 120);
    //for right motor
     digitalWrite(fwdRight, HIGH);                   
    digitalWrite(revRight, LOW);
    analogWrite(enA, 90);  
    
    delay(500);

    digitalWrite(revRight, LOW);  //Stop                
    digitalWrite(fwdRight, LOW);
    analogWrite(enA, 0);
    digitalWrite(fwdLeft, LOW);                                
    digitalWrite(revLeft, LOW); 
    analogWrite(enB, 0); 
    delay(1000); 

    digitalWrite(fwdRight, HIGH);      //Turn left         
    digitalWrite(revRight, LOW);
    analogWrite(enA, 90);
    digitalWrite(fwdLeft, LOW);                                
    digitalWrite(revLeft, HIGH);
    analogWrite(enB, 120);
    delay(500);

    digitalWrite(revRight, LOW);  //Stop                
    digitalWrite(fwdRight, LOW);
    analogWrite(enA, 0);
    digitalWrite(fwdLeft, LOW);                                
    digitalWrite(revLeft, LOW); 
    analogWrite(enB, 0); 
    delay(1000);  
}

void cleanRight() {
  digitalWrite(revRight, LOW);  //Stop                
    digitalWrite(fwdRight, LOW);
    analogWrite(enA, 0);
    digitalWrite(fwdLeft, LOW);                                
    digitalWrite(revLeft, LOW); 
    analogWrite(enB, 0); 
    delay(1000);  
    
    digitalWrite(fwdRight, LOW);      //Turn right         
    digitalWrite(revRight, HIGH);
    analogWrite(enA, 120);
    digitalWrite(fwdLeft, HIGH);                                
    digitalWrite(revLeft, LOW);
    analogWrite(enB, 120);
    delay(750);
        
    digitalWrite(revRight, LOW);  //Stop                
    digitalWrite(fwdRight, LOW);
    analogWrite(enA, 0);
    digitalWrite(fwdLeft, LOW);                                
    digitalWrite(revLeft, LOW); 
    analogWrite(enB, 0); 
    delay(1000);  

    //For left motor
    digitalWrite(fwdLeft, HIGH);              // move forward                   
    digitalWrite(revLeft, LOW);  
    analogWrite(enB, 120);
    //for right motor
     digitalWrite(fwdRight, HIGH);                   
    digitalWrite(revRight, LOW);
    analogWrite(enA, 90);  
    
    delay(500);

    digitalWrite(revRight, LOW);  //Stop                
    digitalWrite(fwdRight, LOW);
    analogWrite(enA, 0);
    digitalWrite(fwdLeft, LOW);                                
    digitalWrite(revLeft, LOW); 
    analogWrite(enB, 0); 
    delay(1000); 

    digitalWrite(fwdRight, LOW);      //Turn right         
    digitalWrite(revRight, HIGH);
    analogWrite(enA, 120);
    digitalWrite(fwdLeft, HIGH);                                
    digitalWrite(revLeft, LOW);
    analogWrite(enB, 120);
    delay(500);

    digitalWrite(revRight, LOW);  //Stop                
    digitalWrite(fwdRight, LOW);
    analogWrite(enA, 0);
    digitalWrite(fwdLeft, LOW);                                
    digitalWrite(revLeft, LOW); 
    analogWrite(enB, 0); 
    delay(1000);  
}

void initialize() {
  isInitialized = true;
  if (rightDistance > leftDistance) {
    goRight = true;
}
else {
  goRight = false;
}
}
