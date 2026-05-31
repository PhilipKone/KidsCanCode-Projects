# Traffic Light with Servo Motor

This project demonstrates how to simulate a traffic light system using an Arduino and a servo motor. The servo motor rotates to represent different traffic light states.

## Components Required

- Arduino board (e.g., Uno, Nano)
- Servo motor
- Jumper wires
- Breadboard

## Circuit Diagram

1. Connect the **VCC** pin of the servo motor to the **5V** pin on the Arduino.
2. Connect the **GND** pin of the servo motor to the **GND** pin on the Arduino.
3. Connect the **Signal** pin of the servo motor to **pin 1** on the Arduino.

## How It Works

1. The servo motor rotates to three different angles to represent the traffic light states:
   - **0°**: Red light
   - **90°**: Yellow light
   - **180°**: Green light
2. The servo motor pauses at each angle for a specific duration to simulate the traffic light timing.

## Code Explanation

### `setup()`
- Attaches the servo motor to the specified pin.
- Initializes the servo motor.

### `loop()`
- Rotates the servo motor to **0°**, **90°**, and **180°** sequentially.
- Delays are added between rotations to simulate the timing of traffic lights.

## Usage

1. Upload the provided code to your Arduino board.
2. Assemble the circuit as per the diagram.
3. Power the Arduino and observe the servo motor rotating to simulate traffic light states.

## Notes

- Ensure the servo motor is properly connected and powered.
- Adjust the delay values in the code to change the timing of the traffic light states.

## Troubleshooting

- If the servo motor does not move, check the connections and pin assignments.
- Ensure the servo motor is receiving sufficient power.
- Use the Serial Monitor to debug if necessary.

## License

This project is open-source and can be used for educational purposes. Attribution is appreciated.
