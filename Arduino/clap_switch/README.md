# Clap Switch with Arduino

This project demonstrates how to create a clap switch using an Arduino and a sound sensor. The system detects claps and toggles LEDs based on the number of claps.

## Components Required

- Arduino board (e.g., Uno, Nano)
- Sound sensor module
- LEDs (e.g., Red, Green, Blue)
- Resistors (for LEDs)
- Jumper wires
- Breadboard

## Circuit Diagram

1. Connect the **VCC** pin of the sound sensor to the **5V** pin on the Arduino.
2. Connect the **GND** pin of the sound sensor to the **GND** pin on the Arduino.
3. Connect the **OUT** pin of the sound sensor to **pin 2** on the Arduino.
4. Connect the LEDs to **pins 5, 6, and 7** on the Arduino (with resistors in series).

## How It Works

1. The sound sensor detects sound intensity and sends a signal to the Arduino.
2. The Arduino counts the number of claps based on the sensor's output.
3. Depending on the number of claps:
   - **1 Clap**: Turns on the first LED.
   - **2 Claps**: Turns on the second LED.
   - **3 Claps**: Turns on the third LED.
   - **4 or more Claps**: Turns off all LEDs.

## Code Explanation

### `setup()`

- Configures the pins for the LEDs and sound sensor.
- Attaches an interrupt to detect sound signals.

### `loop()`

- Monitors the number of claps and toggles the LEDs accordingly.
- Implements a debounce mechanism to avoid false triggers.

### `ISR_turn_leds_on()`

- Interrupt Service Routine (ISR) to handle sound detection.
- Updates the clap count and resets it after a timeout.

## Usage

1. Upload the provided code to your Arduino board.
2. Assemble the circuit as per the diagram.
3. Clap near the sound sensor to toggle the LEDs.
4. Observe the LEDs turning on/off based on the number of claps.

## Notes

- Ensure the sound sensor is properly aligned to detect claps effectively.
- Adjust the debounce time in the code if the system is too sensitive or unresponsive.
- Use the Serial Monitor to debug and verify clap detection.

## Troubleshooting

- If the LEDs do not respond, check the connections and pin assignments.
- Ensure the sound sensor is functioning by monitoring its output on the Serial Monitor.
- Verify the resistor values for the LEDs to prevent damage.

## License

This project is open-source and can be used for educational purposes. Attribution is appreciated.
