int enA = 5;
int enB = 9;
int in1 = 7;
int in2 = 8;
int in3 = 4;
int in4 = 3;


void setup() {
  // put your setup code here, to run once:
   pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
   pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
   pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 
  //reset the ultrasonic sensor
  
   digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // analogWrite(enA, 255);
    digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // analogWrite(enB, 255);
}
void loop() {
  
}

