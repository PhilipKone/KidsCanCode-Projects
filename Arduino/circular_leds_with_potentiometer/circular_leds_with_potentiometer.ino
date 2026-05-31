int ledPin[] = {1,2,3,4,5,6};
int potPin = A0;

void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<6;i++){
    pinMode(ledPin[i], OUTPUT); 
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int x=0;x<6;x++) {
    digitalWrite(ledPin[x], HIGH);
    delay(analogRead(potPin));
    digitalWrite(ledPin[x], LOW);
  }

}
