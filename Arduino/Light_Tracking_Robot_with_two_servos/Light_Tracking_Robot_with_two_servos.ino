#include <Servo.h>



volatile int LDR1_value;

volatile int LDR2_value;

volatile int LDR3_value;

volatile int LDR4_value;

volatile int servo1_angle;

volatile int servo2_angle;



Servo servo_2;

Servo servo_3;



void setup()

{

  LDR1_value = 0;

  LDR2_value = 0;

  LDR3_value = 0;

  LDR4_value = 0;

  servo1_angle = 90;

  servo2_angle = 90;

  servo_2.attach(2);

  servo_3.attach(3);

}



void loop()

{

  LDR1_value = analogRead(A0);

  LDR2_value = analogRead(A1);

  LDR3_value = analogRead(A2);

  LDR4_value = analogRead(A3);

  if ((LDR1_value > 900 || LDR2_value > 900) || (LDR3_value > 900 || LDR4_value > 900)) {

    if (LDR1_value + LDR2_value > LDR3_value + LDR4_value) {

      if (servo1_angle < 180) {

        servo1_angle = servo1_angle + 2;

        servo_2.write(servo1_angle);

        delay(100);



      }



    } else if (LDR1_value + LDR2_value == LDR3_value + LDR4_value) {

      servo_2.write(servo1_angle);

      delay(100);

    } else {

      if (servo1_angle > 0) {

        servo1_angle = servo1_angle - 2;

        servo_2.write(servo1_angle);

        delay(100);



      }



    }

    if (LDR2_value + LDR4_value > LDR1_value + LDR3_value) {

      if (servo2_angle < 180) {

        servo2_angle = servo2_angle + 2;

        servo_3.write(servo2_angle);

        delay(100);



      }



    } else if (LDR2_value + LDR4_value > LDR1_value + LDR3_value) {

      servo_3.write(servo2_angle);

      delay(100);

    } else {

      if (servo2_angle > 0) {

        servo2_angle = servo2_angle - 2;

        servo_3.write(servo2_angle);

        delay(100);



      }



    }



  }



}
