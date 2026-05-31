// C++ code
//
int ckey = 0;

int dkey = 0;

int ekey = 0;

int fkey = 0;

int gkey = 0;

int akey = 0;

int bkey = 0;
int highckey = 0;


;
void setup()
{
  pinMode(13, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(5, OUTPUT);
}

void loop()
{
  ckey = digitalRead(13);
  dkey = digitalRead(12);
  ekey = digitalRead(11);
  fkey = digitalRead(10);
  gkey = digitalRead(9);
  akey = digitalRead(8);
  bkey = digitalRead(7);
  highckey = digitalRead(6);
  if (ckey == LOW) {
    tone(5, 523, 1000); // play tone 60 (C5 = 523 Hz)
  }
  if (dkey == LOW) {
    tone(5, 587, 1000); // play tone 62 (D5 = 587 Hz)
  }
  if (ekey == LOW) {
    tone(5, 659, 1000); // play tone 64 (E5 = 659 Hz)
  }
  if (fkey == LOW) {
    tone(5, 698, 1000); // play tone 65 (F5 = 698 Hz)
  }
  if (gkey == LOW) {
    tone(5, 784, 1000); // play tone 67 (G5 = 784 Hz)
  }
  if (akey == LOW) {
    tone(5, 880, 1000); // play tone 69 (A5 = 880 Hz)
  }
  if (bkey == LOW) {
    tone(5, 988, 1000); // play tone 71 (B5 = 988 Hz)
  }
  if (highckey == LOW) {
    tone(5, 1047, 1000); // play tone 72 (C6 = 1047 Hz)
  }
  delay(10); // Delay a little bit to improve simulation performance
}
