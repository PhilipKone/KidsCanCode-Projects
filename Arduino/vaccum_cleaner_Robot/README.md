# Vacuum Cleaner Robot with Arduino

This project demonstrates how to build a vacuum cleaner robot using an Arduino, ultrasonic sensors, and motors. The robot can autonomously navigate and avoid obstacles while cleaning.

## Components Required

- Arduino board (e.g., Uno, Nano)
- 3 Ultrasonic sensors (e.g., HC-SR04)
- 2 DC motors
- Motor driver (e.g., L298N)
- Jumper wires
- Breadboard
- Power supply for motors

## Circuit Diagram

1. Connect the **VCC** and **GND** pins of each ultrasonic sensor to the **5V** and **GND** pins on the Arduino.
2. Connect the **TRIG** and **ECHO** pins of the forward ultrasonic sensor to **pins 2** and **3** on the Arduino.
3. Connect the **TRIG** and **ECHO** pins of the right ultrasonic sensor to **pins 4** and **5** on the Arduino.
4. Connect the **TRIG** and **ECHO** pins of the left ultrasonic sensor to **pins 6** and **7** on the Arduino.
5. Connect the motor driver to the Arduino:
   - **EN A** to **pin 9** and **EN B** to **pin 10**.
   - **IN1, IN2** (left motor) to **pins 11, 8**.
   - **IN3, IN4** (right motor) to **pins 12, 13**.
6. Connect the DC motors to the motor driver.
7. Provide an external power supply for the motors.

## How It Works

1. The robot uses three ultrasonic sensors to measure distances in the forward, left, and right directions.
2. Based on the distance readings:
   - If no obstacle is detected, the robot moves forward.
   - If an obstacle is detected, the robot decides whether to turn left or right based on the distance to the sides.
3. The robot alternates between cleaning motions and obstacle avoidance.

## Code Explanation

### `setup()`
- Configures the ultrasonic sensor pins and motor driver pins.
- Initializes the Serial Monitor for debugging.

### `loop()`
- Continuously measures distances using the ultrasonic sensors.
- Controls the motors to move forward, turn left, or turn right based on the distance readings.

### `lookForward()`, `lookLeft()`, `lookRight()`
- These functions control the ultrasonic sensors to measure distances in the respective directions.

### `cleanLeft()`, `cleanRight()`
- These functions implement cleaning motions while turning left or right.

### `initialize()`
- Determines the initial direction (left or right) based on the distance readings.

## Usage

1. Upload the provided code to your Arduino board.
2. Assemble the circuit as per the diagram.
3. Place the robot on a flat surface.
4. Power the motors and the Arduino.
5. Observe the robot navigating and cleaning autonomously.

## Notes

- Ensure the ultrasonic sensors are properly aligned for accurate distance measurement.
- Use an external power supply for the motors to prevent overloading the Arduino.
- Adjust the motor speed in the code if the robot moves too fast or too slow.

## Troubleshooting

- If the robot does not move, check the motor connections and power supply.
- If the ultrasonic sensors do not detect obstacles, verify their connections and alignment.
- Use the Serial Monitor to debug distance readings and motor actions.

## License

This project is open-source and can be used for educational purposes. Attribution is appreciated.
