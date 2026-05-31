#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 5
MFRC522 rfid(SS_PIN, RST_PIN);

int servoPin = 2;
Servo servo;

String rfidCard;
byte keyTagUID[4] = {0x82, 0xF5, 0xD6, 0x4E};

void setup() {
  Serial.begin(9600);
  Serial.println("Starting the RFID Reader...");
  SPI.begin();
  rfid.PCD_Init();
  pinMode(8, OUTPUT);
  servo.attach(servoPin); 
  servo.write(180);
  Serial.println("Tap RFID/NFC Tag on reader");
}  

void loop() {
//  if (rfid.isCard()) {
//    if (rfid.readCardSerial()) {
//      rfidCard = String(rfid.serNum[0]) + " " + String(rfid.serNum[1]) + " " + String(rfid.serNum[2]) + " " + String(rfid.serNum[3]);
//      Serial.println(rfidCard);
//      if (rfidCard == "87 135 174 46" || rfidCard == "35 89 142 29") {
//        servo.write(40);
//        delay(5000);
//        servo.write(150);
//      } else {
//        digitalWrite(8, HIGH);
//        delay(2000);
//        digitalWrite(8, LOW);
//      }
//    }
//    rfid.halt();
//  }
if (rfid.PICC_IsNewCardPresent()) { // new tag is available
    if (rfid.PICC_ReadCardSerial()) { // NUID has been readed
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
      Serial.println(rfid.uid.uidByte[0]);
      Serial.println(rfid.uid.uidByte[1]);
      Serial.println(rfid.uid.uidByte[2]);
      Serial.println(rfid.uid.uidByte[3]);

      if (rfid.uid.uidByte[0] == keyTagUID[0] &&
          rfid.uid.uidByte[1] == keyTagUID[1] &&
          rfid.uid.uidByte[2] == keyTagUID[2] &&
          rfid.uid.uidByte[3] == keyTagUID[3] ) {
        Serial.println("Access is granted");
                       servo.write(100);
        delay(10000);
        servo.write(180); // lock the door
      }
      else
      {
        Serial.print("Access denied for user with UID:");
        for (int i = 0; i < rfid.uid.size; i++) {
          Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
          Serial.print(rfid.uid.uidByte[i], HEX);
        }
        Serial.println();

        servo.write(180); // lock the door

//        servo.write(0);
//        delay(5000);
//        servo.write(90); // lock the door
        
      }

      rfid.PICC_HaltA(); // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
    }
  }
}
