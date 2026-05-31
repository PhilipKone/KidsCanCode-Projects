/*
* LED 8x8 DotMarix using Arduino
* Created by TheCircuit
*/

#include <LedControl.h>

int DIN = 12; 
int CS =  11;
int CLK = 10; 
int interruptPin = 2;
long unsigned int lastPress = 0;
int debounceTime = 500;
int faceVal = 0;
LedControl lc=LedControl(DIN,CLK,CS,0);

void setup(){
  pinMode(2,INPUT_PULLUP);
 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display

 attachInterrupt(digitalPinToInterrupt(interruptPin), ISR_change_face, CHANGE);
}

void loop(){ 

    
    byte smile[8] = {0x3C,0x52,0xA5,0xA1,0xA1,0xA5,0x52,0x3C};
    byte noface[8] = {0x3C,0x42,0x81,0x81,0x81,0x81,0x42,0x3C,};
    byte eyesOnly[8] = {0x3C,0x42,0x85,0x81,0x81,0x85,0x42,0x3C};
    byte neutral[8] = {0x3C,0x42,0xA5,0xA1,0xA1,0xA5,0x42,0x3C};
    byte sad[8] = {0x3C,0x42,0xB5,0x91,0x91,0xB5,0x42,0x3C};
    byte eyesDown[8] = {0x3C,0x42,0x89,0x81,0x81,0x89,0x42,0x3C};
  
    if(faceVal == 0) {
      
    printByte(eyesOnly);
    delay(2000);
    printByte(eyesDown);
    delay(500);
    printByte(eyesOnly);
    delay(250);
    printByte(noface);
    delay(250);
    
    }

    if(faceVal == 1) {
      for(int i=0; i<50; i++) {
      printByte(smile);
      printByte(sad);
      printByte(eyesOnly);
      }
    printByte(smile);
    delay(5000);
    faceVal = 0;
    }

    if(faceVal == 2) {
      for(int i=0; i<50; i++) {
      printByte(smile);
      printByte(sad);
      printByte(eyesOnly);
      }
    printByte(neutral);
    delay(5000);
    faceVal = 0;
    }

    if(faceVal == 3) {
      for(int i=0; i<50; i++) {
      printByte(smile);
      printByte(sad);
      printByte(eyesOnly);
      }
    printByte(sad);
    delay(5000);
    faceVal = 0;
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

void ISR_change_face() {
Serial.println("inside ISR");
  if((millis()-lastPress) > debounceTime) {
      lastPress = millis(); 

      faceVal = random(1,4);
  }  
}
