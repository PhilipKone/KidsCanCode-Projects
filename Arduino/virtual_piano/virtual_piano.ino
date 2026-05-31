// C++ code
//
int distance = 0;
int trig = 11; //trig pin of ultrasonic sensor
int echo = 12; //echo pin of ultrasonic sensor

void setup()
{
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  Serial.begin(9600);
}

void loop()
{


//Ultrasonic Sensor Measures distance
//trigger the ultrasonic sensor for 10 microseconds to send out 8 pulses
  digitalWrite(trig, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW); 
  long duration = pulseIn(echo, HIGH); 
  int distance = duration*0.034/2; 
  Serial.print("Distance in cm : "); 
  Serial.println(distance); 
  


//Use distance measured to play tones
  if (distance > 0 && distance < 5) {
    tone(7, 523, 250); // play tone 60 (C5 = 523 Hz)
  }
  if (distance > 5 && distance < 10) {
    tone(7, 587, 250); // play tone 62 (D5 = 587 Hz)
  }
  if (distance > 10 && distance < 15) {
    tone(7, 659, 250); // play tone 64 (E5 = 659 Hz)
  }
  if (distance > 15 && distance < 20) {
    tone(7, 698, 250); // play tone 65 (F5 = 698 Hz)
  }
  if (distance > 20 && distance < 25) {
    tone(7, 784, 250); // play tone 67 (G5 = 784 Hz)
  }
  delay(10); // Delay a little bit to improve simulation performance
}
