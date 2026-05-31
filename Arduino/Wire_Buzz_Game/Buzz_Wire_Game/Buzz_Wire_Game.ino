#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

int buzzerPin = 2;
int wirePin = 7;
int finishWire = 5;

void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();
  pinMode(buzzerPin, OUTPUT);
  pinMode(wirePin, INPUT);
  pinMode(finishWire, INPUT);
  Serial.begin(9600);

    lcd.clear();                 // clear display
  lcd.setCursor(5, 0);         // move cursor to   (0, 0)
  lcd.print("Welcome");        // print message at (0, 0)
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
        
}

void loop()
{
  int wireVal = digitalRead(wirePin);
  int finishWireVal = digitalRead(finishWire);
  Serial.print("wireVal: ");
  Serial.println(wireVal);
   Serial.print("finish: ");
  Serial.println(finishWireVal);
  delay(250);
//  lcd.clear();                 // clear display
//  lcd.setCursor(5, 0);         // move cursor to   (0, 0)
//  lcd.print("Welcome");        // print message at (0, 0)
//  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
//  lcd.print(""); // print message at (2, 1)
//  delay(5000);                 // display the above for two seconds
//
//  lcd.clear();                  // clear display
//  lcd.setCursor(3, 0);          // move cursor to   (3, 0)
//  lcd.print("Wire");        // print message at (3, 0)
//  lcd.setCursor(0, 1);          // move cursor to   (0, 1)
//  lcd.print("Buzzer Game"); // print message at (0, 1)
//  delay(2000);        
// display the above for two seconds

if(finishWireVal == HIGH) {
    digitalWrite(buzzerPin, LOW);
      lcd.clear();                 // clear display
  lcd.setCursor(5, 0);         // move cursor to   (0, 0)
  lcd.print("You Win");
  delay(5000);
  }
//  else {
//      lcd.clear();                  // clear display
//  lcd.setCursor(3, 0);          // move cursor to   (3, 0)
//  lcd.print("Wire");        // print message at (3, 0)
//  lcd.setCursor(0, 1);          // move cursor to   (0, 1)
//  lcd.print("Buzzer Game");
//  }

  if(wireVal == HIGH) {
    digitalWrite(buzzerPin, HIGH);
      lcd.clear();                 // clear display
  lcd.setCursor(5, 0);         // move cursor to   (0, 0)
  lcd.print("You Lose");
  delay(5000);
  
  }
  else {
    digitalWrite(buzzerPin, LOW);
      lcd.clear();                  // clear display
  lcd.setCursor(3, 0);          // move cursor to   (3, 0)
  lcd.print("Wire");        // print message at (3, 0)
  lcd.setCursor(0, 1);          // move cursor to   (0, 1)
  lcd.print("Buzzer Game");
  }
}
