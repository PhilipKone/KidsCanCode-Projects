# Christmas Lights

This project demonstrates how to create a decorative Christmas lights system using an Arduino microcontroller. The lights change patterns based on a button press, cycling through two different lighting modes.

## Components Used
1. **Arduino Board**: The microcontroller used to control the lights.
2. **LEDs**: Red, green, and yellow LEDs for the lighting effects.
3. **Push Button**: Used to toggle between lighting modes.
4. **Resistors**: Used to limit current to the LEDs.
5. **Power Supply**: Provides power to the components and Arduino.

## Code Overview

### Global Variables
- `red`, `green`, `yellow`: Pins connected to the red, green, and yellow LEDs.
- `buttonPin`: Pin connected to the push button.
- `state`: Boolean variable to track the current lighting mode.
- `lastPress`: Stores the last time the button was pressed to debounce the input.

### `setup()` Function
- Configures the pins for the LEDs and the button.
- Initializes serial communication for debugging.
- Attaches an interrupt to the button pin to toggle the lighting mode.

### `loop()` Function
- Continuously checks the `state` variable to determine the current lighting mode.
- **Mode 1**: LEDs blink in a fast sequence.
- **Mode 2**: LEDs blink in a slower sequence.

### `button_ISR()` Function
- Interrupt Service Routine (ISR) triggered by the button press.
- Toggles the `state` variable to switch between lighting modes.
- Implements a debounce mechanism using the `lastPress` variable.

## How to Use
1. Connect the components as per the circuit diagram.
2. Upload the code to the Arduino board.
3. Press the button to toggle between the two lighting modes:
   - **Mode 1**: Fast blinking sequence.
   - **Mode 2**: Slow blinking sequence.

## Notes
- Ensure the button is connected with a pull-up resistor or use the internal pull-up configuration.
- Adjust the delay values in the code to modify the blinking speed.
- Ensure the power supply is sufficient to drive all LEDs.

## Troubleshooting
- If the LEDs do not light up:
  - Check the connections of the LEDs and their resistors.
  - Verify the pins in the code match the hardware setup.
- If the button does not toggle the modes:
  - Check the button connections and ensure it is properly debounced.

## Future Improvements
- Add more lighting patterns for variety.
- Use addressable LEDs for more complex effects.
- Implement a long press on the button to turn off all LEDs.

