#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

int sensor = A0;

void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();
  Serial.begin(9600);
        
}

void loop()
{
   /*---------Temperature-------*/
  
  

     float reading=analogRead(sensor);
  
  Serial.println(reading);

     float temperature=reading*(5.0/1023.0)*100;

     delay(10);

  

  /*------Display Result------*/

    lcd.clear();

    lcd.setCursor(2,0);

    lcd.print("Temperature");

    lcd.setCursor(4,1);

    lcd.print(temperature);

    lcd.print(char(223));

    lcd.print("C");

    delay(1000);
}
