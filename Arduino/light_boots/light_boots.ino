#include <FastLED.h>

#define LED_PIN 7
#define TILT_PIN 2
#define NUM_LEDS 30

CRGB leds[NUM_LEDS];


void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.clear();
  pinMode(TILT_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  leds[0] = CRGB(255,0,0);
//  FastLED.show();
//  delay(1000);
//  leds[1] = CRGB(0,255,0);
//  FastLED.show();
//  delay(1000);
//  leds[2] = CRGB(0,0,255);
//  FastLED.show();
//  delay(1000);

//For red
int reading = digitalRead(TILT_PIN);
  Serial.println(reading);
if(reading == 0) {

  for(int i=0;i<30;i++) {
    leds[i] = CRGB(255,0,0);
    FastLED.show();
  delay(10);
  }
  for(int i=30;i>=0;i--) {
    leds[i] = CRGB(0,0,0);
    FastLED.show();
  delay(10);
  }
  
  //For green
  for(int i=0;i<30;i++) {
    leds[i] = CRGB(0,255,0);
    FastLED.show();
  delay(10);
  }
  for(int i=30;i>=0;i--) {
    leds[i] = CRGB(0,0,0);
    FastLED.show();
  delay(10);
  }

//For blue
  for(int i=0;i<30;i++) {
    leds[i] = CRGB(0,0,255);
    FastLED.show();
  delay(10);
  }
  for(int i=30;i>=0;i--) {
    leds[i] = CRGB(0,0,0);
    FastLED.show();
  delay(10);
  }
}
}
