# Theremin with Arduino

This project demonstrates how to create a simple Theremin using an Arduino, a photocell, and a speaker. The Theremin generates musical tones based on the amount of light detected by the photocell.

## Components Required

- Arduino board (e.g., Uno, Nano)
- Photocell (light-dependent resistor)
- Resistor (e.g., 10kΩ)
- Speaker or buzzer
- Jumper wires
- Breadboard

## Circuit Diagram

1. Connect one leg of the photocell to **5V** on the Arduino.
2. Connect the other leg of the photocell to **A0** on the Arduino and to one leg of the resistor.
3. Connect the other leg of the resistor to **GND** on the Arduino.
4. Connect the positive terminal of the speaker to **pin 12** on the Arduino.
5. Connect the negative terminal of the speaker to **GND** on the Arduino.

## How It Works

1. The photocell measures the intensity of light and sends an analog signal to the Arduino.
2. The Arduino reads the signal and maps it to specific musical tones.
3. The speaker generates the corresponding tone, creating a Theremin-like effect.

## Code Explanation

### `setup()`
- Initializes the Arduino pins and prepares the system for operation.

### `loop()`
- Continuously reads the light intensity from the photocell.
- Maps the light intensity to specific musical notes:
  - **< 30**: C4 (262 Hz)
  - **30-60**: D4 (294 Hz)
  - **60-90**: E4 (330 Hz)
  - **90-120**: F4 (349 Hz)
  - **120-150**: G4 (392 Hz)
  - **150-180**: A4 (440 Hz)
  - **180-210**: B4 (494 Hz)
  - **> 210**: C5 (523 Hz)
- Plays the corresponding tone on the speaker.

## Usage

1. Upload the provided code to your Arduino board.
2. Assemble the circuit as per the diagram.
3. Power the Arduino and observe the speaker generating tones based on the light intensity.
4. Vary the light falling on the photocell to change the tone.

## Notes

- Ensure the photocell is properly connected and aligned for accurate light detection.
- Adjust the tone frequencies in the code if needed for your specific application.
- Use the Serial Monitor to debug and verify light intensity readings.

## Troubleshooting

- If no sound is produced, check the connections of the speaker and photocell.
- Ensure the correct pins are used as per the code.
- Verify the photocell is functioning by printing the analog readings to the Serial Monitor.

## License

This project is open-source and can be used for educational purposes. Attribution is appreciated.
