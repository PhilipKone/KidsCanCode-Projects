int buzzer = 8; //assign pin 8 to buzzer pin
int PIRPin = 7; //assign pin 7 to PIR pin
int ledPin = 9; //assign pin 9 to led pin



//run once
void setup() 
{
  pinMode(buzzer, OUTPUT); //Make buzzer output device
  pinMode(led, OUTPUT);   //Make LED output device
  pinMode(PIR, INPUT);    //Make PIR input device
}



//run forever
void loop() 
{
  if (digitalRead(PIR) == HIGH)
  {
    digitalWrite(buzzer, HIGH);   //turn on buzzer
    digitalWrite(led, HIGH);    //Switch on led
    delay(500);                 //wait for half a second
    digitalWrite(buzzer, LOW);  //turn off buzzer
    digitalWrite(led, LOW);     //turn off led
    delay(500);                  //wait for half a second
  }
  else
  {
    digitalWrite(buzzer, LOW);    //turn off buzzer
    digitalWrite(led, LOW);       //turn off led
  }

}
