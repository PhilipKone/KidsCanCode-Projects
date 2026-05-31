#include <IRremote.h>
#include <AFMotor.h>


int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;
// DC motor on M1 and M2
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {

  delay(random(500, 2000));  // delay for random time
  Serial.begin(9600);
  // turn on motor #1, #2, #3 and #4
  motor1.setSpeed(200);
  motor1.run(RELEASE);
  motor2.setSpeed(200);
  motor2.run(RELEASE);
  motor3.setSpeed(200);
  motor3.run(RELEASE);
  motor4.setSpeed(200);
  motor4.run(RELEASE);


  //  servo.attach(servoPin);           //attach servoPin to servo object
  irrecv.enableIRIn();

  irrecv.blink13(true);
}

void loop() {

motor1.run(FORWARD);

  if (irrecv.decode(&results)) {
    if (results.value == 0XFFFFFFFF)
      //          results.value = key_value;
      Serial.println(results.value, HEX);

    switch (results.value) {

      case 0xFF18E7: //When the 2 button is clicked on the remote

        Serial.println("2");

        //Move forward
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD);



        break ;


      case 0xFF10EF:  //When the 4 button is clicked on the remote

        Serial.println("4");
        // Turn left
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        motor3.run(RELEASE);
        motor4.run(RELEASE);
        motor1.run(RELEASE);
        motor2.run(BACKWARD);
        motor3.run(FORWARD);
        motor4.run(RELEASE);

        break ;

      case 0xFF38C7:  //When the 4 button is clicked on the remote

        Serial.println("5");
        // STOP
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        motor3.run(RELEASE);
        motor4.run(RELEASE);

        break ;



      case 0xFF5AA5: //When the 6 button is clicked on the remote

        Serial.println("6");
        // turn right
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        motor3.run(RELEASE);
        motor4.run(RELEASE);
        motor1.run(RELEASE);
        motor2.run(FORWARD);
        motor3.run(BACKWARD);
        motor4.run(RELEASE);

        break ;


      case 0xFF4AB5:
        //move backward
        Serial.println("8");
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        motor3.run(RELEASE);
        motor4.run(RELEASE);

        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);

        break ;


    }



    //key_value = results.value;

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
