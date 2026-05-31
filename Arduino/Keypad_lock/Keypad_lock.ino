#include <Keypad.h> //Keypad library
#include <Servo.h>   //servo library
//#include <LiquidCrystal_I2C.h>  //LCD library

Servo servo;  

//-- LCD Variables --
//#include <Wire.h>
//LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns


//Set your password or PIN
char password[4] = {'0','0','0','0'};

//Set number of wrong passwords allowed
int number_of_wrong_passwords_allowed = 3;








int number_of_wrong_passwords_Entered = 0;

byte temp[4] = {};
char passwordEntered[4] = {};
int index = 0;
bool openLock = false;
bool isPasswordEntered = false;
int servoPin = 9;
int buzzer = 12;
bool start = true;
//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
                             {'1','2','3','A'},
                             {'4','5','6','B'},
                             {'7','8','9','C'},
                             {'*','0','#','D'}
                                              };
byte rowPins[ROWS] = {0, 8, 2, 3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4, 5, 6, 7}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


void setup() 
{
  //Attach servo motor pin to servo object
  servo.attach(servoPin); 
  
  //Turn servo motor 150 degrees
  servo.write(150);

  //Setup LCD
//  lcd.init(); // 16 columns, 2 rows
//  lcd.clear();
//  lcd.setBacklight(HIGH);
  //lcd.print("Welcome Home");
//  lcd.setCursor(0, 1);
//  lcd.print("back");
  //delay(5000);
  //lcd.clear();
  Serial.begin(9600);
  //Serial.print("Enter your PIN");
  pinMode(buzzer, OUTPUT);
}


void loop()
{
  
  char customKey = customKeypad.getKey();
//  lcd.setCursor(0, 0);
//  lcd.print("Enter your PIN");
//  
  if (customKey) 
  {
//    lcd.setCursor(index, 1);
    Serial.print(customKey);
     //lcd.print(customKey);
    temp[index] = customKey;
    index++;
  }

  if(index > 3) {
    
    Serial.println("");
    //Serial.println("password entered");
    isPasswordEntered = true;
    for(int i=0; i < 4; i++) {
       passwordEntered[i] = temp[i];
      //Serial.println(passwordEntered[i]);
      if(passwordEntered[i] == password[i]) {
        //Serial.println(true);
        openLock = true;
      }
      else {
        //Serial.println(false);
        openLock = false;
      }
    }
    index = 0;
    
  }




  if(openLock && isPasswordEntered) {
    number_of_wrong_passwords_Entered = 0;
//    lcd.clear();
//    lcd.setCursor(0, 0);
   // lcd.print("Correct PIN");
//    lcd.print("Correct PIN");
Serial.println("");
    Serial.println("Correct PIN");
    delay(2000);
//    lcd.clear();
//    lcd.setCursor(0, 0);
  //lcd.print("Lock opened");
  servo.write(40);
    Serial.println("Welcome");
    Serial.println("");
        delay(5000);
        servo.write(150);
        
        openLock = false;
        isPasswordEntered = false;
        start = true;

         for(int i=0;i<20;i++) {
      Serial.print("===");
      }
      Serial.println("");
  }




  //Check for wrong password
  else if(!openLock && isPasswordEntered){
    number_of_wrong_passwords_Entered++;
//    lcd.clear();
//    lcd.setCursor(0, 0);
Serial.println("");
  Serial.println("Incorrect PIN");
  delay(1000);


///////////////////////////////////////////////////////////////////////////////////////////////////////////
//Set alarm

  if(number_of_wrong_passwords_Entered == number_of_wrong_passwords_allowed)
  {
  for(int i=0;i<20;i++) {
    Serial.println("Intruder");
      digitalWrite(buzzer, HIGH);
      delay(250);
      digitalWrite(buzzer, LOW);
      delay(250);
      }
      number_of_wrong_passwords_Entered = 1;
  }



  
  Serial.println("Try again in 5 secs");
  Serial.println("");
  //lcd.clear();
  delay(5000);
  isPasswordEntered = false;
  start = true;
  
  for(int i=0;i<20;i++) {
      Serial.print("===");
      }
      Serial.println("");
  }
  else {
    
    //lcd.setCursor(0, 0);
    if(start) {
  Serial.println("Enter your PIN: ");
  //Serial.println("");
  start = false;
    }
  }
  
    
    
  }
