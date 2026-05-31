#include "pitches.h"
#include <IRremote.h>
#include <Tone.h>

Tone tonePin;
const uint8_t buzzer = 8;

 
//Melodies
 //Happy Birthday Melody
int happyBirthday[] = {
NOTE_D5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_G5, NOTE_FS5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_D5, NOTE_D6, NOTE_B5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_G5, NOTE_A5, NOTE_G5};
int happyBirthdayNoteDurations[] = {
8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 4, 4, 4, 8, 8, 4, 4, 4, 2,
}; 
 
int happyBirthdayModified[] = {
NOTE_D5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_B5, NOTE_G5, NOTE_D5, NOTE_D5, NOTE_D6, NOTE_B5, NOTE_C5, NOTE_FS5, NOTE_E5, NOTE_C6, NOTE_C6, NOTE_B5, NOTE_G5, NOTE_G5, NOTE_G5};
int happyBirthdayModifiedNoteDurations[] = {
8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 4, 4, 4, 8, 8, 4, 4, 4, 2,
}; 
 
 //Super Mario Bross Melody
int superMarioBross[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};

//Mario main theme tempo
int superMarioBrossNoteDurations[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
 
  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

 
//By sohail8
//Coffin Dance Meme melody
int coffinDanceMeme[] = {
NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5,
NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, 
NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, 
NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5,
NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_F4,
NOTE_G4, 0, NOTE_G4, NOTE_D5,
NOTE_C5, 0, NOTE_AS4, 0,
NOTE_A4, 0, NOTE_A4, NOTE_A4,
NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
NOTE_G4,0, NOTE_G4, NOTE_AS5,
NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
NOTE_G4,0, NOTE_G4, NOTE_AS5,
NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
NOTE_G4, 0, NOTE_G4, NOTE_D5,
NOTE_C5, 0, NOTE_AS4, 0,
NOTE_A4, 0, NOTE_A4, NOTE_A4,
NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
NOTE_G4,0, NOTE_G4, NOTE_AS5,
NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
NOTE_G4,0, NOTE_G4, NOTE_AS5,
NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5};

int coffinDanceMemeNoteDurations[] = {
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
4,4,4,4,
};
 
//ode to Joy melody
int odeToJoy[] = {
  NOTE_E4,  NOTE_E4,  NOTE_F4,  NOTE_G4,//1
  NOTE_G4,  NOTE_F4,  NOTE_E4,  NOTE_D4,
  NOTE_C4,  NOTE_C4,  NOTE_D4,  NOTE_E4,
  NOTE_E4, NOTE_D4,  NOTE_D4,
  NOTE_E4,  NOTE_E4,  NOTE_F4,  NOTE_G4,//4
  NOTE_G4,  NOTE_F4,  NOTE_E4,  NOTE_D4,
  NOTE_C4,  NOTE_C4,  NOTE_D4,  NOTE_E4,
  NOTE_D4,  NOTE_C4,  NOTE_C4,
  NOTE_D4,  NOTE_D4,  NOTE_E4,  NOTE_C4,//8
  NOTE_D4,  NOTE_E4,  NOTE_F4,  NOTE_E4, NOTE_C4,
  NOTE_D4,  NOTE_E4,  NOTE_F4,  NOTE_E4, NOTE_D4,
  NOTE_C4,  NOTE_D4,  NOTE_G3,
  NOTE_E4,  NOTE_E4,  NOTE_F4,  NOTE_G4,//12
  NOTE_G4,  NOTE_F4,  NOTE_E4,  NOTE_D4,
  NOTE_C4,  NOTE_C4,  NOTE_D4,  NOTE_E4,
  NOTE_D4,  NOTE_C4,  NOTE_C4,
};
 
int odeToJoyNoteDurations[] = {
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  2,8,2,
 
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  2,8,2,
 
  4,4,4,4,
  4,8,8,4,4,
  4,8,8,4,4,
  4,4,2,
 
  4,4,4,4,
  4,4,4,4,
  4,4,4,4,
  2,8,2,
  
};
 
 
 
//pin declarations
int ledPin[] = {4, 5};
//int buzzerPin = 8;
int RECV_PIN = 11;
//IRrecv irrecv(RECV_PIN);
//decode_results results;
unsigned long key_value = 0;              
int interruptPin = 2;
 
//Global variables
volatile int songSelect = 0;
long unsigned int lastPress = 0;
int debounceTime = 500; 
volatile int thisNote = 0;
int happyBirthdayNoteCount = sizeof(happyBirthday)/sizeof(int);
int superMarioBrossNoteCount = sizeof(superMarioBross)/sizeof(int);
int coffinDanceMemeNoteCount = sizeof(coffinDanceMeme)/sizeof(int);
int odeToJoyNoteCount = sizeof(odeToJoy)/sizeof(int);

 
void setup() {
  // put your setup code here, to run once:
  
  for(int i=0; i < 2; i++) {
  pinMode(ledPin[i], OUTPUT);
  }

  tonePin.begin(buzzer);
  

 
//  irrecv.enableIRIn(); 
//
//  irrecv.blink13(true);
 
  attachInterrupt(digitalPinToInterrupt(interruptPin), ISR_play_song, CHANGE);
Serial.begin(9600);
  
}
 
void loop() {
  // put your main code here, to run repeatedly:
 
  //Serial.println(digitalRead(interruptPin)); 
 
 
  while(songSelect == 0 && thisNote < happyBirthdayNoteCount) {
    int noteDuration = 1500 / happyBirthdayNoteDurations[thisNote];
    digitalWrite(ledPin[0], HIGH);
  delay(50);
  digitalWrite(ledPin[0], LOW);
//   tone(buzzerPin, happyBirthday[thisNote], noteDuration);
tonePin.play(happyBirthday[thisNote]);
delay(noteDuration);
   int pauseBetweenNotes = noteDuration * 1.25;
   delay(pauseBetweenNotes);
   tonePin.stop(); 
   thisNote++;
  }
 
//  while(songSelect == 2 && thisNote < superMarioBrossNoteCount) {
//    int noteDuration = 1000 / superMarioBrossNoteDurations[thisNote];
//   tone(buzzerPin, superMarioBross[thisNote], noteDuration);
//   int pauseBetweenNotes = noteDuration * 1.25;
//   delay(pauseBetweenNotes);
//   noTone(buzzerPin); 
//   thisNote++;
//  }
// 
//  while(songSelect == 3 && thisNote < coffinDanceMemeNoteCount) {
//    int noteDuration = 1000 / coffinDanceMemeNoteDurations[thisNote];
//    digitalWrite(ledPin[1], HIGH);
//  delay(50);
//  digitalWrite(ledPin[1], LOW);
//   tone(buzzerPin, coffinDanceMeme[thisNote], noteDuration);
//   int pauseBetweenNotes = noteDuration * 1.25;
//   delay(pauseBetweenNotes);
//   noTone(buzzerPin); 
//   thisNote++;
//  }
// 
//  while(songSelect == 4 && thisNote < odeToJoyNoteCount) {
//    int noteDuration = 1000 / odeToJoyNoteDurations[thisNote];
//   tone(buzzerPin, odeToJoy[thisNote], noteDuration);
//   int pauseBetweenNotes = noteDuration * 1.25;
//   delay(pauseBetweenNotes);
//   noTone(buzzerPin); 
//   thisNote++;
//  }
//  
 
}
 
 
void ISR_play_song() {

//  if (irrecv.decode(&results)){ 
//        if (results.value == 0XFFFFFFFF) 
//          //results.value = key_value; 
//          Serial.println(results.value, HEX); 
delay(1000);
          thisNote = 0;
 

//        switch(results.value){ 

//          case 0xFF30CF: //When the 1 key is clicked on the remote
//            Serial.println("1"); 
//            songSelect = 1;
//            break ; 
//
//
//          case 0xFF18E7:  //When the 2 button is clicked on the remote
//            Serial.println("2"); 
//            songSelect = 2;
//          break ; 
//
//          case 0xFF7A85:  //When the 3 button is clicked on the remote
//          Serial.println("3"); 
//           songSelect = 3;
//          break ; 
//
//
//          
//          case 0xFF10EF: //When the 4 button is clicked on the remote
//
//          Serial.println("4"); 
//            songSelect = 4;
//          break ; 
//
//
//          case 0xFF4AB5: 
//          //move backward
//          Serial.println("8"); 
//
//            break ; 
//        }
//        irrecv.resume();  

 // } 
  if((millis()-lastPress) > debounceTime) {
      lastPress = millis(); 
 
      thisNote = 0;
 
    }
}
