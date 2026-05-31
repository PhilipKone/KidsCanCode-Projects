# Automatic Barrier with Ultrasonic Sensor

This project demonstrates how to create an automatic barrier system using an Arduino microcontroller, a servo motor, and an ultrasonic sensor. The barrier opens automatically when an object is detected within a specified distance.

## Components Used

1. **Arduino Board**: The microcontroller used to control the system.
2. **Servo Motor**: Used to open and close the barrier.
3. **Ultrasonic Sensor (HC-SR04)**: Measures the distance to detect objects.
4. **LEDs**: Red and green LEDs indicate the status of the barrier.
5. **Power Supply**: Provides power to the components and Arduino.

## Libraries Used

1. **Servo**: Used to control the servo motor.

## Code Overview

### Global Variables

- `trigPin`, `echoPin`: Pins connected to the ultrasonic sensor.
- `servoPin`: Pin connected to the servo motor.
- `redLed`, `greenLed`: Pins connected to the red and green LEDs.
- `duration`, `dist`: Variables to store the time and calculated distance.
- `aver[]`: Array to calculate the average distance.

### `setup()` Function

- Configures the pins for the ultrasonic sensor and LEDs.
- Attaches the servo motor to the specified pin.
- Initializes the servo motor to the closed position (180 degrees).
- Starts serial communication for debugging.

### `measure()` Function

- Sends a pulse from the ultrasonic sensor to measure the distance.
- Calculates the distance based on the time taken for the pulse to return.

### `loop()` Function

- Continuously measures the distance using the ultrasonic sensor.
- Calculates the average distance over three measurements.
- If the distance is less than 20 cm:
  - Opens the barrier by moving the servo to 90 degrees.
  - Turns on the green LED and turns off the red LED.
  - Waits for 3 seconds before resetting.
- If no object is detected:
  - Closes the barrier by moving the servo to 180 degrees.
  - Turns on the red LED and turns off the green LED.

## How to Use

1. Connect the components as per the circuit diagram.
2. Upload the code to the Arduino board.
3. Place an object within 20 cm of the ultrasonic sensor to open the barrier.
4. Remove the object to close the barrier.

## Notes

- Ensure the ultrasonic sensor is connected to the correct pins (`trigPin` and `echoPin`).
- Adjust the distance threshold in the code (`if (dist < 20)`) as needed.
- Ensure the power supply is sufficient to drive the servo motor.

## Troubleshooting

- If the barrier does not open or close:
  - Check the connections of the ultrasonic sensor and servo motor.
  - Verify the ultrasonic sensor is functioning correctly.
- If the LEDs do not light up:
  - Check the connections of the LEDs and their resistors.

## Future Improvements

- Add a timer to automatically close the barrier after a set duration.
- Implement a buzzer to provide an audible alert when the barrier opens or closes.
- Use a more advanced sensor for better accuracy and range.
