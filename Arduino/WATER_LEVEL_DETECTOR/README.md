# Water Level Detector

This project demonstrates how to build a water level detector using an Arduino and a water sensor. The system monitors the water level and provides visual alerts using LEDs.

## Components Required

- Arduino board (e.g., Uno, Nano)
- Water level sensor
- LEDs (Red, Yellow, Green, Blue)
- Resistors (for LEDs)
- Jumper wires
- Breadboard

## Circuit Diagram

1. Connect the **VCC** pin of the water sensor to the **5V** pin on the Arduino.
2. Connect the **GND** pin of the water sensor to the **GND** pin on the Arduino.
3. Connect the **Signal** pin of the water sensor to **A0** on the Arduino.
4. Connect the **Blue LED** to **pin 4** on the Arduino (with a resistor in series).
5. Connect the **Green LED** to **pin 5** on the Arduino (with a resistor in series).
6. Connect the **Yellow LED** to **pin 6** on the Arduino (with a resistor in series).
7. Connect the **Red LED** to **pin 7** on the Arduino (with a resistor in series).

## How It Works

1. The water sensor measures the water level and sends an analog signal to the Arduino.
2. The Arduino reads the signal and determines the water level.
3. Based on the water level:
   - The **Blue LED** lights up for very low water levels.
   - The **Green LED** lights up for low water levels.
   - The **Yellow LED** lights up for medium water levels.
   - The **Red LED** lights up for high water levels.

## Code Explanation

### `setup()`
- Configures the pins for the LEDs as outputs.
- Initializes the Serial Monitor for debugging.

### `loop()`
- Reads the water level from the sensor.
- Lights up the appropriate LED based on the water level:
  - **<= 200**: All LEDs off.
  - **201-300**: Blue LED on, others off.
  - **301-350**: Green LED on, others off.
  - **> 350**: Red and Yellow LEDs on, others off.

## Usage

1. Upload the provided code to your Arduino board.
2. Assemble the circuit as per the diagram.
3. Place the water sensor in the container to monitor the water level.
4. Observe the LEDs for alerts as the water level changes.

## Notes

- Ensure the water sensor is properly calibrated for accurate readings.
- Adjust the threshold values in the code if needed for your specific sensor.
- Use the Serial Monitor to debug and verify water level readings.

## Troubleshooting

- If the LEDs do not work, check the connections and pin assignments.
- If the water sensor does not provide readings, verify its connections and functionality.
- Ensure the resistors for the LEDs are of appropriate value to prevent damage.

## License

This project is open-source and can be used for educational purposes. Attribution is appreciated.
