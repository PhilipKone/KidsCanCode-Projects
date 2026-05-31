#include <FastLED.h>

//Color sensor Pin definitions
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

//LED Pin definitions
#define LED_PIN 9
#define NUM_LEDS 30

int redfrequency = 0;
int greenfrequency = 0;
int bluefrequency = 0;
int redmappedfrequency = 0;
int greenmappedfrequency = 0;
int bluemappedfrequency = 0;

CRGB leds[NUM_LEDS];


void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.clear();
  pinMode(sensorOut, INPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  //SETTING FREQUENCY SCALINT TO 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  
  Serial.begin(9600);
}

void loop() {
  
//Setting red photodiodes to be read
digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  //Reading output frequency
  redfrequency = pulseIn(sensorOut, LOW);
  redmappedfrequency = map(redfrequency, 0, 300, 0, 255);

  Serial.print("R = ");
  Serial.print(redfrequency);
  Serial.print("  ");
  delay(100);

  //Setting green photodiodes to be read
digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  //Reading output frequency
  greenfrequency = pulseIn(sensorOut, LOW);
  greenmappedfrequency = map(greenfrequency, 0, 300, 0, 255);

  Serial.print("G = ");
  Serial.print(greenfrequency);
  Serial.print("  ");
  delay(100);


  //Setting blue photodiodes to be read
digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  //Reading output frequency
  bluefrequency = pulseIn(sensorOut, LOW);
  bluemappedfrequency = map(bluefrequency, 0, 300, 0, 255);

  Serial.print("B = ");
  Serial.print(bluefrequency);
  Serial.println("");
  delay(100);

//For red

if (redfrequency < 150) {
  for(int i=0;i<30;i++) {
    leds[i] = CRGB(255,0,0);
    FastLED.show();
  delay(10);
  }
}
//  for(int i=30;i>=0;i--) {
//    leds[i] = CRGB(0,0,0);
//    FastLED.show();
//  delay(10);
//  }
//  
if (greenfrequency < 200) {
  //For green
  for(int i=0;i<30;i++) {
    leds[i] = CRGB(0,255,0);
    FastLED.show();
  delay(10);
  }
}
//  for(int i=30;i>=0;i--) {
//    leds[i] = CRGB(0,0,0);
//    FastLED.show();
//  delay(10);
//  }
//
if (bluefrequency < 100) {
//For blue
  for(int i=0;i<30;i++) {
    leds[i] = CRGB(0,0,255);
    FastLED.show();
  delay(10);
  }
}

if (redfrequency < 150 && greenfrequency < 200) {
  for(int i=0;i<30;i++) {
    leds[i] = CRGB(255,255,0);
    FastLED.show();
  delay(10);
  }
}


if (redfrequency < 150 && bluefrequency < 100) {
  for(int i=0;i<30;i++) {
    leds[i] = CRGB(255,0,255);
    FastLED.show();
  delay(10);
  }
}

if (greenfrequency < 200 && bluefrequency < 100) {
  for(int i=0;i<30;i++) {
    leds[i] = CRGB(0,255,255);
    FastLED.show();
  delay(10);
  }
}
//  for(int i=30;i>=0;i--) {
//    leds[i] = CRGB(0,0,0);
//    FastLED.show();
//  delay(10);
//  }
}
