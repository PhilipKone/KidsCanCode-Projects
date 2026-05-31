// C++ code
//
int ckey = 0;

int dkey = 0;

int ekey = 0;

int fkey = 0;

int gkey = 0;


void setup()
{
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  ckey = digitalRead(13);
  dkey = digitalRead(12);
  ekey = digitalRead(11);
  fkey = digitalRead(10);
  gkey = digitalRead(9);
  if (ckey == HIGH) {
    tone(7, 523, 250); // play tone 60 (C5 = 523 Hz)
  }
  if (dkey == HIGH) {
    tone(7, 587, 250); // play tone 62 (D5 = 587 Hz)
  }
  if (ekey == HIGH) {
    tone(7, 659, 250); // play tone 64 (E5 = 659 Hz)
  }
  if (fkey == HIGH) {
    tone(7, 698, 250); // play tone 65 (F5 = 698 Hz)
  }
  if (gkey == HIGH) {
    tone(7, 784, 250); // play tone 67 (G5 = 784 Hz)
  }
  delay(10); // Delay a little bit to improve simulation performance
}
