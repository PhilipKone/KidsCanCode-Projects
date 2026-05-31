#include <LedControl.h>

int trigPin = 5;   
int echoPin = 6; 
int tiltPin = 8;
int leftLDRPin = A0;
int rightLDRPin = A1;


int DIN = 12; 
int CS =  11;
int CLK = 10;

long duration, dist, average;  
long unsigned int lastPress = 0;
int debounceTime = 500;
int faceVal = 0;
boolean shaken = false;

LedControl lc=LedControl(DIN,CLK,CS,0);

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT);

    lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);     
Serial.begin(9600);

attachInterrupt(digitalPinToInterrupt(2), ISR_shake_response, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
 digitalWrite(10,HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);   
dist = (duration/2) / 29.1;    //obtain distance

Serial.println(dist);

//byte smile[8] = {0x04,0x08,0x10,0x10,0x10,0x10,0x08,0x04};
byte happy[8] = {0x0C,0x14,0x28,0x28,0x28,0x28,0x14,0x0C};
//    byte noface[8] = {0x3C,0x42,0x81,0x81,0x81,0x81,0x42,0x3C,};
//    byte eyesOnly[8] = {0x3C,0x42,0x85,0x81,0x81,0x85,0x42,0x3C};
//    byte neutral[8] = {0x3C,0x42,0xA5,0xA1,0xA1,0xA5,0x42,0x3C};
//    byte sad[8] = {0x20,0x10,0x08,0x08,0x08,0x08,0x10,0x20};
    byte afraid[8] = {0x78,0x24,0x12,0x12,0x12,0x12,0x24,0x78};

byte smile[8] = {0x00,0x10,0x24,0x20,0x20,0x24,0x10,0x00,};
    byte noface[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    byte eyesOnly[8] = {0x00,0x00,0x04,0x00,0x00,0x04,0x00,0x00};
    byte eyesInward[8] = {0x3C,0x42,0x81,0x85,0x85,0x81,0x42,0x3C};
    byte angry[8] = {0x3C,0x42,0xB5,0xB1,0xB1,0xB5,0x42,0x3C};
    byte angryEyesInward[8] = {0x00,0x00,0x30,0x34,0x34,0x30,0x00,0x00};
    byte angryEyesOutward[8] = {0x00,0x00,0x34,0x30,0x30,0x34,0x00,0x00,};
    byte sad[8] = {0x00,0x40,0x24,0x20,0x20,0x24,0x40,0x00};
    byte eyesDown[8] = {0x00,0x00,0x02,0x00,0x00,0x02,0x00,0x00};
    byte lookLeft[8] = {0x00,0x04,0x00,0x00,0x04,0x00,0x00,0x00};
    byte lookRight[8] = {0x00,0x00,0x00,0x04,0x00,0x00,0x04,0x00};
    byte neutral[8] = {0x00,0x00,0x04,0x20,0x20,0x04,0x00,0x00};

    //printByte(sad);
    int leftLDRVal = analogRead(leftLDRPin);
    int rightLDRVal = analogRead(rightLDRPin);
    
    if(dist <= 50 && !shaken && leftLDRVal < 400 && rightLDRVal < 400) {
      faceVal = 0;
      
    }
    else if(dist >= 50 && !shaken && leftLDRVal < 400 && rightLDRVal < 400){
      faceVal = 1;
      
    }
    else if(leftLDRVal > rightLDRVal && !shaken) {
      faceVal = 3;
    }
    else if(leftLDRVal < rightLDRVal && !shaken) {
      faceVal = 4;
    }

    if(faceVal == 0){
      printByte(neutral);
      delay(200);
      printByte(smile);
      delay(2000);
    }
    else if(faceVal == 2) {
      for(int x=0; x<10; x++) {
      printByte(angryEyesInward);
      delay(50);
      printByte(angryEyesOutward);
      delay(50);
      }
       printByte(sad);
       delay(2000);
      shaken = false;
    }
    else if(faceVal == 3) {
      printByte(lookLeft);
      //delay(1000);
      
      delay(2000);
    }
    else if(faceVal == 4) {
      printByte(lookRight);
      //delay(1000);
      
      delay(2000);
    }
    else {
      printByte(eyesOnly);
    delay(2000);
    printByte(eyesDown);
    delay(500);
    printByte(eyesOnly);
    delay(2000);
//    printByte(eyesDown);
//    delay(500);
//    printByte(eyesOnly);
//    delay(250);
    printByte(noface);
    delay(125);
    printByte(eyesOnly);
    delay(250);
    printByte(noface);
    delay(125);
    
    
    }
       

    
    

}

void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}

void ISR_shake_response() {
Serial.println("inside ISR");
  if((millis()-lastPress) > debounceTime) {
      lastPress = millis(); 
faceVal = 2;
shaken = true;
//      faceVal = random(1,4);
    }
 
}
