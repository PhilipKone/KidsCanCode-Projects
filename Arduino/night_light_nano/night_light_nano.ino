// C++ code
//

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int val = analogRead(A0); 
  Serial.println(val);
  if(val > 30){ 
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    }
  else {
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
