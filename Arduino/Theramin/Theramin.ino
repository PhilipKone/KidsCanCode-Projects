int speakerPin = 12;
int photocellPin = 0;

void setup()
{

}

void loop()
{
  int reading = analogRead(photocellPin);
  if(reading < 30) tone(speakerPin, 262);
  if(reading > 30 && reading < 60) tone(speakerPin, 294);
  if(reading > 60 && reading < 90) tone(speakerPin, 330);
  if(reading > 90 && reading < 120) tone(speakerPin, 349);
  if(reading > 120 && reading < 150) tone(speakerPin, 392);
  if(reading > 150 && reading < 180) tone(speakerPin, 440);
  if(reading > 180 && reading < 210) tone(speakerPin, 494);
  if(reading > 210) tone(speakerPin, 523);
  
}