# Weather Station

This project demonstrates how to create a weather station using an Arduino microcontroller. The system measures temperature, humidity, and water levels, displaying the data on an LCD screen and activating a buzzer if water levels exceed a threshold.

## Components Used
1. **Arduino Board**: The microcontroller used to control the system.
2. **DHT11 Sensor**: Measures temperature and humidity.
3. **Water Level Sensor**: Detects water levels.
4. **16x2 I2C LCD Display**: Displays temperature, humidity, and water level data.
5. **Buzzer**: Sounds when water levels exceed a threshold.
6. **Power Supply**: Provides power to the components and Arduino.

## Libraries Used
1. **LiquidCrystal_I2C**: Used to control the I2C LCD display.
2. **DHT**: Used to read data from the DHT11 sensor.

## Code Overview

### Global Variables
- `DHTPIN`: Pin connected to the DHT11 sensor.
- `DHTTYPE`: Type of DHT sensor (DHT11).
- `buzzerPin`: Pin connected to the buzzer.
- `waterSensor`: Pin connected to the water level sensor.

### `setup()` Function
- Initializes the LCD display and DHT sensor.
- Configures the pins for the buzzer and water sensor.
- Displays a welcome message on the LCD.

### `loop()` Function
- Reads the water level from the water sensor.
  - Activates the buzzer if the water level exceeds a threshold.
- Reads temperature and humidity from the DHT11 sensor.
  - Displays the temperature and humidity on the LCD.
- Handles errors if the DHT sensor fails to read data.

## How to Use
1. Connect the components as per the circuit diagram.
2. Upload the code to the Arduino board.
3. Observe the temperature, humidity, and water level data on the LCD.
4. If water levels exceed the threshold, the buzzer will sound.

## Notes
- Ensure the DHT11 sensor is connected to the correct pin (`DHTPIN`).
- Adjust the water level threshold in the code as needed.
- Ensure the power supply is sufficient to drive the LCD and buzzer.

## Troubleshooting
- If the LCD does not display text:
  - Check the I2C address and connections.
  - Verify the LiquidCrystal_I2C library is installed correctly.
- If the DHT sensor fails to read data:
  - Check the connections of the DHT sensor.
  - Ensure the correct DHT type is defined in the code.
- If the buzzer does not sound:
  - Check the connections of the buzzer and `buzzerPin`.

## Future Improvements
- Add additional sensors for air quality or pressure.
- Implement data logging to an SD card or cloud storage.
- Add a real-time clock (RTC) module to timestamp the readings.

