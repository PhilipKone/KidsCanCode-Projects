/*
Adafruit Arduino - Lesson 4. 8 LEDs and a Shift Register
*/

int latchPin = 5;
int clockPin = 6;
int dataPin = 4;

byte leds = 0;

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(10, INPUT);
  pinMode(11, OUTPUT);
}

void loop() 
{
  leds = 0;
  
  bitSet(leds, 0);
//  int button = digitalRead(10);
  
   updateShiftRegister();
  delay(200);
//  for (int i = 0; i < 8; i++)
//  {
//    int x = 4;
//    bitSet(leds, i);
//    updateShiftRegister();
//    delay(500);
//  }
}

void updateShiftRegister()
{
  
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
 
}
