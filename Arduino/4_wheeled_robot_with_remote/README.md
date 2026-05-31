# 4-Wheeled Robot with Remote Control

This project demonstrates how to control a 4-wheeled robot using an IR remote. The robot uses an Arduino microcontroller, DC motors, and an IR receiver to interpret remote commands and perform various movements.

## Components Used
1. **Arduino Board**: The microcontroller used to control the robot.
2. **IR Receiver**: Receives signals from the IR remote.
3. **IR Remote**: Sends commands to the robot.
4. **Adafruit Motor Shield**: Controls the four DC motors.
5. **DC Motors**: Four motors to drive the robot's wheels.
6. **Power Supply**: Provides power to the motors and Arduino.

## Libraries Used
1. **IRremote**: Used to decode IR signals from the remote.
2. **AFMotor**: Used to control the DC motors via the Adafruit Motor Shield.

## Code Overview

### Global Variables
- `RECV_PIN`: Pin connected to the IR receiver.
- `irrecv`: Object to handle IR signal decoding.
- `results`: Stores the decoded IR signal.
- `key_value`: Stores the last valid key pressed on the remote.
- `motor1`, `motor2`, `motor3`, `motor4`: Objects to control the four DC motors.

### `setup()` Function
- Initializes the serial communication at 9600 baud.
- Sets up the motors with a speed of 200 and stops them initially.
- Enables the IR receiver to start decoding signals.

### `loop()` Function
- Continuously checks for IR signals.
- Decodes the received signal and performs actions based on the button pressed on the remote.

### Remote Control Commands
| Button Pressed | Hex Code  | Action         |
|----------------|-----------|----------------|
| 2              | `0xFF18E7` | Move Forward   |
| 4              | `0xFF10EF` | Turn Left      |
| 5              | `0xFF38C7` | Stop           |
| 6              | `0xFF5AA5` | Turn Right     |
| 8              | `0xFF4AB5` | Move Backward  |

### Motor Control
- **Move Forward**: All motors run forward.
- **Turn Left**: Motors on one side run backward while others run forward.
- **Turn Right**: Motors on one side run forward while others run backward.
- **Stop**: All motors are stopped.
- **Move Backward**: All motors run backward.

## How to Use
1. Connect the components as per the circuit diagram.
2. Upload the code to the Arduino board.
3. Use the IR remote to control the robot:
   - Press `2` to move forward.
   - Press `4` to turn left.
   - Press `5` to stop.
   - Press `6` to turn right.
   - Press `8` to move backward.

## Notes
- Ensure the IR receiver is connected to the correct pin (`RECV_PIN`).
- Adjust motor speeds if necessary by modifying the `setSpeed()` function.
- Ensure the power supply is sufficient to drive all four motors.

## Troubleshooting
- If the robot does not respond to the remote, check the IR receiver connections.
- Verify the remote's hex codes match the ones in the code.
- Ensure the motors are connected to the correct ports on the motor shield.

## Future Improvements
- Add obstacle detection using ultrasonic sensors.
- Implement more complex movements or patterns.
- Add Bluetooth or Wi-Fi control for remote operation.

