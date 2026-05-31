int VRx = A0;         //VRx of the joystick module
int VRy = A1;         //VRy of the joystick module

int enA = 5;
int enB = 9;
int revleft = 7;       //REVerse motion of Left motor
int fwdleft = 8;       //ForWarD motion of Left motor
int revright = 4;      //REVerse motion of Right motor
int fwdright = 3;      //ForWarD motion of Right motor

long duration, distance;
int xVal;
int yVal;

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(revleft, OUTPUT);      // set Motor pins as output
  pinMode(fwdleft, OUTPUT);
  pinMode(revright, OUTPUT);
  pinMode(fwdright, OUTPUT);
  
//  pinMode(trigPin, OUTPUT);         // set trig pin as output
//  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
  pinMode(VRx, INPUT);            //set OUT pin of IR sensor as input
  pinMode(VRy, INPUT);  
}

void loop() {

  xVal = analogRead(VRx);     //read the joystick position in the x axis
  yVal = analogRead(VRy);     ////read the joystick position in the y axis
  
  
  while (yVal >= 950)            //when the joystick is moved forward
  {
    digitalWrite(fwdright, HIGH);                    // move forward
    digitalWrite(revright, LOW);
    analogWrite(enB, 130);
    digitalWrite(fwdleft, HIGH);                                
    digitalWrite(revleft, LOW);   
    analogWrite(enA, 150); 
    yVal = analogRead(VRy);                          //read the joystick position on the y axis
                                                       
  }
  while(yVal <= 100)            //when the joystick is moved backward
  {
    digitalWrite(fwdright, LOW);                    // move backward
    digitalWrite(revright, HIGH);
    analogWrite(enB, 130);
    digitalWrite(fwdleft, LOW);                                
    digitalWrite(revleft, HIGH);   
    analogWrite(enA, 150);  
    yVal = analogRead(VRy);                         //read the joystick position on the y axis                                          
  }
   while(xVal >= 950) {                //when the joystick is moved left
    digitalWrite(fwdright, HIGH);      //Turn left       
    digitalWrite(revright, LOW);
    analogWrite(enA, 120);
    digitalWrite(fwdleft, LOW);                                
    digitalWrite(revleft, HIGH);
    analogWrite(enB, 120);
    xVal = analogRead(VRx);           //read the joystick position on the x axis
  }
  while(xVal <= 100) {                //when the joystick is moved right
    digitalWrite(fwdright, LOW);      //Turn right       
    digitalWrite(revright, HIGH);
    analogWrite(enA, 120);
    digitalWrite(fwdleft, HIGH);                                
    digitalWrite(revleft, LOW);
    analogWrite(enB, 120);
    xVal = analogRead(VRx);           //read the joystick position on the x axis
  }

    
    digitalWrite(fwdright, LOW);  //Stop if the joystick is in the middle.           
    digitalWrite(revright, LOW);
    analogWrite(enB, 0);
    digitalWrite(fwdleft, LOW);                                
    digitalWrite(revleft, LOW); 
    analogWrite(enA, 0); 

}


