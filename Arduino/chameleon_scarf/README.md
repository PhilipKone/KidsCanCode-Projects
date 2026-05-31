# Chameleon Scarf

This project demonstrates how to create a scarf that changes its LED colors based on the detected color of an object. The system uses an Arduino microcontroller, a color sensor, and addressable LEDs to mimic the detected color.

## Components Used

1. **Arduino Board**: The microcontroller used to control the system.
2. **TCS3200 Color Sensor**: Detects the color of an object.
3. **WS2812 Addressable LEDs**: Displays the detected color on the scarf.
4. **Power Supply**: Provides power to the components and Arduino.

## Libraries Used

1. **FastLED**: Used to control the WS2812 addressable LEDs.

## Code Overview

### Global Variables

- `S0`, `S1`, `S2`, `S3`: Pins connected to the TCS3200 color sensor.
- `sensorOut`: Pin connected to the sensor's output.
- `LED_PIN`: Pin connected to the WS2812 LEDs.
- `NUM_LEDS`: Number of LEDs in the scarf.
- `redfrequency`, `greenfrequency`, `bluefrequency`: Variables to store the raw frequency values for red, green, and blue.
- `redmappedfrequency`, `greenmappedfrequency`, `bluemappedfrequency`: Variables to store the mapped frequency values for red, green, and blue.

### `setup()` Function

- Configures the pins for the color sensor and initializes the LEDs.
- Sets the frequency scaling of the color sensor to 20%.
- Starts serial communication for debugging.

### `loop()` Function

- Reads the frequency values for red, green, and blue from the color sensor.
- Maps the frequency values to a range of 0-255.
- Displays the detected color on the LEDs:
  - Red if the red frequency is below a threshold.
  - Green if the green frequency is below a threshold.
  - Blue if the blue frequency is below a threshold.
  - Combines colors (e.g., yellow, cyan, magenta) if multiple thresholds are met.

## How to Use

1. Connect the components as per the circuit diagram.
2. Upload the code to the Arduino board.
3. Place an object in front of the color sensor to detect its color.
4. Observe the LEDs on the scarf change to match the detected color.

## Notes

- Ensure the color sensor is connected to the correct pins (`S0`, `S1`, `S2`, `S3`, and `sensorOut`).
- Adjust the thresholds in the code to fine-tune color detection.
- Ensure the power supply is sufficient to drive the LEDs.

## Troubleshooting

- If the LEDs do not light up:
  - Check the connections of the LEDs and the `LED_PIN`.
  - Verify the FastLED library is installed correctly.
- If the detected colors are inaccurate:
  - Check the connections of the color sensor.
  - Adjust the mapping ranges and thresholds in the code.

## Future Improvements

- Add a button to toggle between different LED patterns.
- Implement a mode to cycle through colors automatically.
- Use a more advanced color sensor for better accuracy.
