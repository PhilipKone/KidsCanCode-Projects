# Virtual Piano with Ultrasonic Sensor

This project demonstrates how to create a virtual piano using an Arduino, an ultrasonic sensor, and a buzzer. The ultrasonic sensor measures the distance of an object, and based on the distance, the Arduino generates different musical tones through the buzzer.

## Components Required

- Arduino board (e.g., Uno, Nano)
- Ultrasonic sensor (e.g., HC-SR04)
- Buzzer or speaker
- Jumper wires
- Breadboard

## Circuit Diagram

1. Connect the **VCC** pin of the ultrasonic sensor to the **5V** pin on the Arduino.
2. Connect the **GND** pin of the ultrasonic sensor to the **GND** pin on the Arduino.
3. Connect the **TRIG** pin of the ultrasonic sensor to **pin 11** on the Arduino.
4. Connect the **ECHO** pin of the ultrasonic sensor to **pin 12** on the Arduino.
5. Connect the positive terminal of the buzzer to **pin 7** on the Arduino.
6. Connect the negative terminal of the buzzer to **GND** on the Arduino.

## How It Works

1. The ultrasonic sensor emits sound waves and measures the time it takes for the waves to bounce back after hitting an object.
2. The Arduino calculates the distance of the object based on the time measured.
3. Depending on the distance, the Arduino generates a specific tone using the `tone()` function.
4. The tones correspond to musical notes, creating a virtual piano effect.

## Code Explanation

### `setup()`

- Configures the ultrasonic sensor pins and the buzzer pin.
- Initializes the Serial Monitor for debugging.

### `loop()`

- Continuously measures the distance using the ultrasonic sensor.
- Plays a specific tone based on the distance range:
  - **0-5 cm**: C5 (523 Hz)
  - **5-10 cm**: D5 (587 Hz)
  - **10-15 cm**: E5 (659 Hz)
  - **15-20 cm**: F5 (698 Hz)
  - **20-25 cm**: G5 (784 Hz)

## Usage

1. Upload the provided code to your Arduino board.
2. Assemble the circuit as per the diagram.
3. Place your hand or an object in front of the ultrasonic sensor.
4. Move the object closer or farther to hear different tones.

## Notes

- Ensure the ultrasonic sensor is properly aligned for accurate distance measurement.
- The `delay(10)` in the `loop()` function helps improve simulation performance and prevents overlapping tones.

## Troubleshooting

- If no sound is produced, check the connections of the buzzer and ultrasonic sensor.
- Ensure the correct pins are used as per the code.
- Verify the ultrasonic sensor is functioning by printing the distance to the Serial Monitor.

## License

This project is open-source and can be used for educational purposes. Attribution is appreciated.
