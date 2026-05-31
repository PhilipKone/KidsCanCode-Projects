int enA = 5;
int enB = 9;
int in1 = 7;
int in2 = 8;
int in3 = 4;
int in4 = 3;

int trig = 11;
int echo = 12;

void setup() {
  // put your setup code here, to run once:
   pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
   pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
   pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
   pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  //reset the ultrasonic sensor
   digitalWrite(trig, LOW);
   Serial.begin(9600);
  

}

void loop() {
  //trigger the ultrasonic sensor for 10 microseconds to send out 8 pulses
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 
  long duration = pulseIn(echo, HIGH); 
  int distance = duration*0.034/2; 
  Serial.print("Distance in cm : "); 
  Serial.println(distance); 

  if(distance < 30) {
  stopMotion();
  delay(2000);
  turn();
  delay(1000);
  stopMotion();
  delay(2000);
   
  }
  else {
   moveForward();
  }

}

void moveForward() {
   digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
   analogWrite(enA, 210);
    digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
   analogWrite(enB, 210);
}

void reverse() {
   digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
   analogWrite(enA, 150);
    digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
   analogWrite(enB, 150);
}

void turn() {
   digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
   analogWrite(enA, 150);
    digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
   analogWrite(enB, 150);
}

void stopMotion() {
   digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
   analogWrite(enA, 0);
    digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
   analogWrite(enB, 0);
}

