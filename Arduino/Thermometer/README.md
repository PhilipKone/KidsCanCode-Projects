# Digital Thermometer with Arduino

This project demonstrates how to build a digital thermometer using an Arduino, a temperature sensor, and an LCD display. The system measures the temperature and displays it on the LCD screen.

## Components Required

- Arduino board (e.g., Uno, Nano)
- Temperature sensor (e.g., LM35)
- I2C LCD display (16x2)
- Jumper wires
- Breadboard

## Circuit Diagram

1. Connect the **VCC** pin of the temperature sensor to the **5V** pin on the Arduino.
2. Connect the **GND** pin of the temperature sensor to the **GND** pin on the Arduino.
3. Connect the **Signal** pin of the temperature sensor to **A0** on the Arduino.
4. Connect the **SDA** and **SCL** pins of the I2C LCD display to the corresponding **SDA** and **SCL** pins on the Arduino.
5. Connect the **VCC** and **GND** pins of the LCD display to the **5V** and **GND** pins on the Arduino.

## How It Works

1. The temperature sensor measures the ambient temperature and sends an analog signal to the Arduino.
2. The Arduino converts the analog signal into a temperature value in Celsius.
3. The temperature value is displayed on the LCD screen.

## Code Explanation

### `setup()`
- Initializes the LCD display.
- Configures the Serial Monitor for debugging.

### `loop()`
- Reads the analog signal from the temperature sensor.
- Converts the signal into a temperature value in Celsius.
- Displays the temperature on the LCD screen.

## Usage

1. Upload the provided code to your Arduino board.
2. Assemble the circuit as per the diagram.
3. Power the Arduino and observe the temperature displayed on the LCD screen.

## Notes

- Ensure the temperature sensor is properly connected and aligned for accurate readings.
- Adjust the conversion formula in the code if using a different temperature sensor.
- Use the Serial Monitor to debug and verify temperature readings.

## Troubleshooting

- If the LCD does not display anything, check the I2C address and connections.
- If the temperature readings are incorrect, verify the sensor connections and calibration.
- Ensure the temperature sensor is not exposed to extreme conditions that could damage it.

## License

This project is open-source and can be used for educational purposes. Attribution is appreciated.
