//pin declarations
int ledPin[] = {5, 6, 7};            
int interruptPin = 2;
 
//Global variables
volatile int patternSelect = 1
;
long unsigned int lastPress = 0;
int debounceTime = 500; 

 
void setup() {
  // put your setup code here, to run once:
  
  for(int i=0; i < 3; i++) {
  pinMode(ledPin[i], OUTPUT);
  }

 
  //pinMode(buttonPin, INPUT_PULLUP);
 
  attachInterrupt(digitalPinToInterrupt(interruptPin), ISR_play_song, CHANGE);
Serial.begin(9600);
  
}
 
void loop() {
  // put your main code here, to run repeatedly:
 
  Serial.println(digitalRead(interruptPin));

  
  while(patternSelect==1) {
  digitalWrite(ledPin[0], HIGH);
  digitalWrite(ledPin[1], LOW);  
digitalWrite(ledPin[2], HIGH);  
delay(500);
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], HIGH);
  digitalWrite(ledPin[2], LOW);
  delay(500);  
  }
 
  while(patternSelect == 2) {
    digitalWrite(ledPin[0], HIGH);
  digitalWrite(ledPin[1], LOW);  
digitalWrite(ledPin[2], LOW);  
delay(250);
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], HIGH);
  digitalWrite(ledPin[2], LOW);
  delay(250);  
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], LOW);
  digitalWrite(ledPin[2], HIGH);
  delay(250); 
  }
 
  while(patternSelect == 3) {
    digitalWrite(ledPin[0], HIGH);
  digitalWrite(ledPin[1], LOW);  
digitalWrite(ledPin[2], LOW);  
delay(1000);
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], LOW);
  digitalWrite(ledPin[2], HIGH);
  delay(1000);  
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], HIGH);
  digitalWrite(ledPin[2], LOW);
  delay(1000); 
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], LOW);
  digitalWrite(ledPin[2], HIGH);
  delay(1000); 
  }
}
 
 
void ISR_play_song() {
  Serial.println("inside ISR");
  if((millis()-lastPress) > debounceTime) {
      lastPress = millis(); 
      
      
       if(patternSelect < 3){
        patternSelect++;
       }
       else {
        patternSelect = 1;
       }
  }  
}
   
