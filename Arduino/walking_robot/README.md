# Walking Robot with Arduino

This project demonstrates how to build a walking robot using an Arduino, servos, and an ultrasonic sensor. The robot can move forward and detect obstacles using the ultrasonic sensor, adjusting its direction accordingly.

## Components Required

- Arduino board (e.g., Uno, Nano)
- 4 Servo motors
- Ultrasonic sensor (e.g., HC-SR04)
- Jumper wires
- Breadboard
- Power supply for servos

## Circuit Diagram

1. Connect the **VCC** pin of the ultrasonic sensor to the **5V** pin on the Arduino.
2. Connect the **GND** pin of the ultrasonic sensor to the **GND** pin on the Arduino.
3. Connect the **TRIG** pin of the ultrasonic sensor to **pin 6** on the Arduino.
4. Connect the **ECHO** pin of the ultrasonic sensor to **pin 10** on the Arduino.
5. Connect the servo motors to **pins 3, 5, 6, and 9** on the Arduino.
6. Ensure the servos are powered with an external power supply if needed.

## How It Works

1. The robot uses four servos to simulate walking motion.
2. The ultrasonic sensor measures the distance to obstacles in front, left, and right directions.
3. Based on the distance readings:
   - If no obstacle is detected, the robot moves forward.
   - If an obstacle is detected, the robot turns left or right depending on the distance to the sides.

## Code Explanation

### `setup()`
- Initializes the servos and ultrasonic sensor pins.
- Sets the initial position of the servos.

### `loop()`
- Simulates walking motion by controlling the servos.
- Uses the ultrasonic sensor to measure distances in different directions.
- Adjusts the robot's movement based on the distance readings.

### `lookLeft()`, `lookRight()`, `lookForward()`
- These functions control the ultrasonic sensor to measure distances in the respective directions.

### `turnLeft()`, `turnRight()`
- These functions will control the servos to turn the robot left or right (currently placeholders in the code).

## Usage

1. Upload the provided code to your Arduino board.
2. Assemble the circuit as per the diagram.
3. Place the robot on a flat surface.
4. Power the servos and the Arduino.
5. Observe the robot walking and avoiding obstacles.

## Notes

- Ensure the servos are properly calibrated for smooth motion.
- Use an external power supply for the servos if they draw too much current.
- Adjust the servo angles in the code if the walking motion is not smooth.

## Troubleshooting

- If the robot does not move, check the servo connections and power supply.
- If the ultrasonic sensor does not detect obstacles, verify the connections and alignment.
- Use the Serial Monitor to debug distance readings.

## License

This project is open-source and can be used for educational purposes. Attribution is appreciated.
