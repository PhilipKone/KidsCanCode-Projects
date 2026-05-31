#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows


int buzzerPin = 7;
int waterSensor = A0;


void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();
  pinMode(buzzerPin, OUTPUT);
  pinMode(waterSensor, INPUT);

  Serial.begin(9600);

  dht.begin();

    lcd.clear();                 // clear display
  lcd.setCursor(5, 0);         // move cursor to   (0, 0)
  lcd.print("Welcome");        // print message at (0, 0)
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
        
}

void loop()
{
  
  int waterValue = analogRead(waterSensor);
  Serial.print("waterVal: ");
  Serial.println(waterValue);
  delay(250);

if(analogRead(waterSensor) > 50) {
 digitalWrite(buzzerPin, HIGH);
}
else {
  digitalWrite(buzzerPin, LOW);
}

   // read humidity
  float humi  = dht.readHumidity();
  // read temperature as Celsius
  float tempC = dht.readTemperature();
  // read temperature as Fahrenheit
  float tempF = dht.readTemperature(true);

  // check if any reads failed
  if (isnan(humi) || isnan(tempC) || isnan(tempF)) {
    lcd.clear();                 // clear display
  lcd.setCursor(0, 0);
    Serial.println("Failed to read from DHT sensor!");
    lcd.print("Failed to read from DHT sensor!");
  } else {
    lcd.clear();                 // clear display
  lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(humi);
    lcd.print("%");

    //lcd.print("  |  "); 
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(tempC);
    lcd.print(" C");
//    lcd.print(tempF);
//    lcd.println("°F");
  }

}
