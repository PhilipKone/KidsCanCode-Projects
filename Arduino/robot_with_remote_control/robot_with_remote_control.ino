//#include <Servo.h>

//int servoPin = 1;
//Servo servo;

//#include <ir_Lego_PF_BitStreamEncoder.h>

#include <IRremote.h>


int enA = 9;
int enB = 10;
int IN4 = 7;       //REVerse motion of Left motor
int IN3 = 6;       //ForWarD motion of Left motor
int IN2 = 5;      //REVerse motion of Right motor
int IN1 = 4;      //ForWarD motion of Right motor

long duration, distance;

const int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup() {

  delay(random(500, 2000));  // delay for random time
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IN4, OUTPUT);      // set Motor pins as output
  pinMode(IN3, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN1, OUTPUT);


  //  servo.attach(servoPin);           //attach servoPin to servo object
  irrecv.enableIRIn();

  irrecv.blink13(true);
}

void loop() {


  if (irrecv.decode(&results)) {
    if (results.value == 0XFFFFFFFF)
      // results.value = key_value;
      Serial.println(results.value, HEX);

    switch (results.value) {

      case 0xFF18E7: //When the 2 button is clicked on the remote

        Serial.println("2");

        //For left motor
     digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(enB, 150);

        //for right motor
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(enA, 120);

        delay(1500);

        // STOP
        //For left motor
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        analogWrite(enB, 0);

        //for right motor
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        analogWrite(enA, 0);




        break;


      case 0xFF10EF:  //When the 4 button is clicked on the remote

        Serial.println("4");
        // Turn left
        //For left motor
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(enB, 150);

        //for right motor
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        analogWrite(enA, 120);

        delay(300);

        // STOP
        //For left motor
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        analogWrite(enB, 0);

        //for right motor
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        analogWrite(enA, 0);

        break;

      case 0xFF38C7:  //When the 5 button is clicked on the remote

        Serial.println("5");
        // STOP
        //For left motor
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        analogWrite(enB, 0);

        //for right motor
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        analogWrite(enA, 0);


        break;



      case 0xFF5AA5: //When the 6 button is clicked on the remote

        Serial.println("6");
        // turn right
        //For left motor
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        analogWrite(enB, 120);

        //for right motor
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        analogWrite(enA, 170);

        delay(300);

        // STOP
        //For left motor
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        analogWrite(enB, 0);

        //for right motor
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        analogWrite(enA, 0);
        
        break;


      case 0xFF4AB5:
        //move backward
        Serial.println("8");

        //For left motor
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(enB, 150);

        //for right motor
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        analogWrite(enA, 150);

        delay(1500);

        // STOP
        //For left motor
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        analogWrite(enB, 0);

        //for right motor
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        analogWrite(enA, 0);

        break;


    }



            key_value = results.value;

    irrecv.resume();



  }






  // else {
  //   //no movement
  //           //For left motor
  //   digitalWrite(IN3, LOW);
  //   digitalWrite(IN4, LOW);
  //   digitalWrite(enA, 0);

  //   //for right motor
  //    digitalWrite(IN1, LOW);
  //   digitalWrite(IN2, LOW);
  //   digitalWrite(enB, 0);
  // }
}
