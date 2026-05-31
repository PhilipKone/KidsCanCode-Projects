# Automatic Barrier

This project demonstrates how to create an automatic barrier system using an Arduino microcontroller, a servo motor, and an IR sensor. The barrier opens automatically when an object is detected by the IR sensor.

## Components Used

1. **Arduino Board**: The microcontroller used to control the system.
2. **Servo Motor**: Used to open and close the barrier.
3. **IR Sensor**: Detects the presence of an object.
4. **LEDs**: Red and green LEDs indicate the status of the barrier.
5. **Power Supply**: Provides power to the components and Arduino.

## Libraries Used

1. **Servo**: Used to control the servo motor.

## Code Overview

### Global Variables

- `IRPin`: Pin connected to the IR sensor.
- `servoPin`: Pin connected to the servo motor.
- `servo`: Servo object to control the barrier.
- `redPin`, `greenPin`: Pins connected to the red and green LEDs.

### `setup()` Function

- Configures the pins for the IR sensor and LEDs.
- Attaches the servo motor to the specified pin.
- Initializes the servo motor to the closed position (90 degrees).
- Starts serial communication for debugging.

### `loop()` Function

- Continuously checks the IR sensor for object detection.
- If an object is detected:
  - Opens the barrier by moving the servo to 30 degrees.
  - Turns on the green LED and turns off the red LED.
  - Waits for 3 seconds before resetting.
- If no object is detected:
  - Closes the barrier by moving the servo to 90 degrees.
  - Turns on the red LED and turns off the green LED.

## How to Use

1. Connect the components as per the circuit diagram.
2. Upload the code to the Arduino board.
3. Place an object in front of the IR sensor to open the barrier.
4. Remove the object to close the barrier.

## Notes

- Ensure the IR sensor is connected to the correct pin (`IRPin`).
- Adjust the servo angles if necessary to match the physical setup.
- Ensure the power supply is sufficient to drive the servo motor.

## Troubleshooting

- If the barrier does not open or close:
  - Check the connections of the IR sensor and servo motor.
  - Verify the IR sensor is functioning correctly.
- If the LEDs do not light up:
  - Check the connections of the LEDs and their resistors.

## Future Improvements

- Add an ultrasonic sensor for more accurate object detection.
- Implement a timer to automatically close the barrier after a set duration.
- Add a buzzer to provide an audible alert when the barrier opens or closes.
