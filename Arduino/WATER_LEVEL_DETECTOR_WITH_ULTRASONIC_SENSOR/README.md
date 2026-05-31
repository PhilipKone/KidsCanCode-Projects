# Water Level Detector with Ultrasonic Sensor

This project demonstrates how to create a water level detector using an Arduino microcontroller and an ultrasonic sensor. The system measures the water level and activates LEDs to indicate the level.

## Components Used
1. **Arduino Board**: The microcontroller used to control the system.
2. **HC-SR04 Ultrasonic Sensor**: Measures the distance to detect water levels.
3. **LEDs**: Indicates the water level (multiple LEDs for different levels).
4. **Power Supply**: Provides power to the components and Arduino.

## Code Overview

### Global Variables
- `trigPin`: Pin connected to the trigger pin of the ultrasonic sensor.
- `echoPin`: Pin connected to the echo pin of the ultrasonic sensor.
- `duration`: Stores the time taken for the ultrasonic pulse to return.
- `distance`: Stores the calculated distance based on the duration.

### `setup()` Function
- Configures the pins for the ultrasonic sensor and LEDs.
- Initializes serial communication for debugging.

### `loop()` Function
- Sends an ultrasonic pulse and measures the time taken for the echo to return.
- Calculates the distance based on the duration.
- Activates LEDs based on the measured distance:
  - **Level 1**: Activates one LED.
  - **Level 2**: Activates two LEDs.
  - **Level 3**: Activates three LEDs.
  - **Level 4**: Activates all LEDs.

## How to Use
1. Connect the components as per the circuit diagram.
2. Upload the code to the Arduino board.
3. Observe the LEDs light up based on the water level.

## Notes
- Ensure the ultrasonic sensor is connected to the correct pins (`trigPin` and `echoPin`).
- Adjust the distance thresholds in the code as needed.
- Ensure the power supply is sufficient to drive the LEDs.

## Troubleshooting
- If the LEDs do not light up:
  - Check the connections of the LEDs and their resistors.
  - Verify the ultrasonic sensor is functioning correctly.
- If the distance readings are inaccurate:
  - Check the ultrasonic sensor connections.
  - Ensure the sensor is positioned correctly.

## Future Improvements
- Add a buzzer to alert when the water level is too high.
- Implement an LCD display to show the exact water level.
- Add wireless communication to send water level data to a remote device.

