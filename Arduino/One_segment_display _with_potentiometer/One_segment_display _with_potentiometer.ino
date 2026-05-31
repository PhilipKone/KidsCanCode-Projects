int ledPin[] = {2,3,4,5,6,7,8,9};
int potPin = A0;
int potValue = 0;

void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<8;i++){
    pinMode(ledPin[i], OUTPUT); 
  }

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  potValue = analogRead(potPin);
  Serial.println(potValue);

  if(potValue < 102) {
    //For 0
digitalWrite(ledPin[5], HIGH);
      digitalWrite(ledPin[6], HIGH);
       digitalWrite(ledPin[0], HIGH);
      digitalWrite(ledPin[1], HIGH);
       digitalWrite(ledPin[4], HIGH);
       digitalWrite(ledPin[2], HIGH);
 
  }

  if(potValue > 102 && potValue < 204) {
    digitalWrite(ledPin[5], LOW);
      digitalWrite(ledPin[6], LOW);
       digitalWrite(ledPin[0], LOW);
      digitalWrite(ledPin[1], LOW);
       digitalWrite(ledPin[4], LOW);
       digitalWrite(ledPin[2], LOW);
       digitalWrite(ledPin[3], LOW);
       digitalWrite(ledPin[7], LOW);
       
     //For 1
  digitalWrite(ledPin[4], HIGH);
  digitalWrite(ledPin[2], HIGH);
 
  }

  if(potValue > 204 && potValue < 306) {
    digitalWrite(ledPin[5], LOW);
      digitalWrite(ledPin[6], LOW);
       digitalWrite(ledPin[0], LOW);
      digitalWrite(ledPin[1], LOW);
       digitalWrite(ledPin[4], LOW);
       digitalWrite(ledPin[2], LOW);
       digitalWrite(ledPin[3], LOW);
       digitalWrite(ledPin[7], LOW);
     //For 2
  digitalWrite(ledPin[5], HIGH);                                                                                                                                                                                                                                                                                                                                                                                                    
 digitalWrite(ledPin[4], HIGH);
  digitalWrite(ledPin[7], HIGH);
   digitalWrite(ledPin[0], HIGH);
    digitalWrite(ledPin[1], HIGH);

  }

if(potValue > 306 && potValue < 408) {
  digitalWrite(ledPin[5], LOW);
      digitalWrite(ledPin[6], LOW);
       digitalWrite(ledPin[0], LOW);
      digitalWrite(ledPin[1], LOW);
       digitalWrite(ledPin[4], LOW);
       digitalWrite(ledPin[2], LOW);
       digitalWrite(ledPin[3], LOW);
       digitalWrite(ledPin[7], LOW);
  //For 3
     digitalWrite(ledPin[5], HIGH);
      digitalWrite(ledPin[4], HIGH);
       digitalWrite(ledPin[2], HIGH);
      digitalWrite(ledPin[7], HIGH);
       digitalWrite(ledPin[1], HIGH);

}

if(potValue > 408 && potValue < 510) {
  digitalWrite(ledPin[5], LOW);
      digitalWrite(ledPin[6], LOW);
       digitalWrite(ledPin[0], LOW);
      digitalWrite(ledPin[1], LOW);
       digitalWrite(ledPin[4], LOW);
       digitalWrite(ledPin[2], LOW);
       digitalWrite(ledPin[3], LOW);
       digitalWrite(ledPin[7], LOW);
  //For 4
digitalWrite(ledPin[6], HIGH);
      digitalWrite(ledPin[7], HIGH);
       digitalWrite(ledPin[4], HIGH);
      digitalWrite(ledPin[2], HIGH);

}

if(potValue > 510 && potValue < 612) {
  digitalWrite(ledPin[5], LOW);
      digitalWrite(ledPin[6], LOW);
       digitalWrite(ledPin[0], LOW);
      digitalWrite(ledPin[1], LOW);
       digitalWrite(ledPin[4], LOW);
       digitalWrite(ledPin[2], LOW);
       digitalWrite(ledPin[3], LOW);
       digitalWrite(ledPin[7], LOW);
//For 5
      digitalWrite(ledPin[5], HIGH);
      digitalWrite(ledPin[6], HIGH);
       digitalWrite(ledPin[7], HIGH);
      digitalWrite(ledPin[2], HIGH);
       digitalWrite(ledPin[1], HIGH);

}

if(potValue > 612 && potValue < 714) {
  digitalWrite(ledPin[5], LOW);
      digitalWrite(ledPin[6], LOW);
       digitalWrite(ledPin[0], LOW);
      digitalWrite(ledPin[1], LOW);
       digitalWrite(ledPin[4], LOW);
       digitalWrite(ledPin[2], LOW);
       digitalWrite(ledPin[3], LOW);
       digitalWrite(ledPin[7], LOW);
  //For 6
digitalWrite(ledPin[5], HIGH);
      digitalWrite(ledPin[6], HIGH);
       digitalWrite(ledPin[0], HIGH);
      digitalWrite(ledPin[1], HIGH);
       digitalWrite(ledPin[2], HIGH);
       digitalWrite(ledPin[7], HIGH);

}

if(potValue > 714 && potValue < 816) {
  digitalWrite(ledPin[5], LOW);
      digitalWrite(ledPin[6], LOW);
       digitalWrite(ledPin[0], LOW);
      digitalWrite(ledPin[1], LOW);
       digitalWrite(ledPin[4], LOW);
       digitalWrite(ledPin[2], LOW);
       digitalWrite(ledPin[3], LOW);
       digitalWrite(ledPin[7], LOW);
  //For 7
digitalWrite(ledPin[5], HIGH);
      digitalWrite(ledPin[4], HIGH);
       digitalWrite(ledPin[2], HIGH);

}

if(potValue > 816 && potValue < 918) {
  digitalWrite(ledPin[5], LOW);
      digitalWrite(ledPin[6], LOW);
       digitalWrite(ledPin[0], LOW);
      digitalWrite(ledPin[1], LOW);
       digitalWrite(ledPin[4], LOW);
       digitalWrite(ledPin[2], LOW);
       digitalWrite(ledPin[3], LOW);
       digitalWrite(ledPin[7], LOW);
  //For 8
digitalWrite(ledPin[5], HIGH);
      digitalWrite(ledPin[4], HIGH);
       digitalWrite(ledPin[2], HIGH);
      digitalWrite(ledPin[7], HIGH);
       digitalWrite(ledPin[1], HIGH);
       digitalWrite(ledPin[6], HIGH);
      digitalWrite(ledPin[0], HIGH);

}

if(potValue > 918) {
  digitalWrite(ledPin[5], LOW);
      digitalWrite(ledPin[6], LOW);
       digitalWrite(ledPin[0], LOW);
      digitalWrite(ledPin[1], LOW);
       digitalWrite(ledPin[4], LOW);
       digitalWrite(ledPin[2], LOW);
       digitalWrite(ledPin[3], LOW);
       digitalWrite(ledPin[7], LOW);
//For 9
digitalWrite(ledPin[5], HIGH);
      digitalWrite(ledPin[6], HIGH);
       digitalWrite(ledPin[7], HIGH);
      digitalWrite(ledPin[4], HIGH);
       digitalWrite(ledPin[2], HIGH);
       digitalWrite(ledPin[1], HIGH);

}

       
   
       
      

}
