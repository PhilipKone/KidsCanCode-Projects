# Wire Buzz Game

This project demonstrates how to create a wire buzz game using an Arduino microcontroller. The player must navigate a loop along a wire without touching it. If the loop touches the wire, a buzzer sounds, and the player loses.

## Components Used
1. **Arduino Board**: The microcontroller used to control the game.
2. **Buzzer**: Sounds when the loop touches the wire.
3. **Wire**: The path the player must navigate.
4. **Finish Wire**: Indicates the end of the game.
5. **16x2 I2C LCD Display**: Displays game messages.
6. **Power Supply**: Provides power to the components and Arduino.

## Libraries Used
1. **LiquidCrystal_I2C**: Used to control the I2C LCD display.

## Code Overview

### Global Variables
- `buzzerPin`: Pin connected to the buzzer.
- `wirePin`: Pin connected to the main wire.
- `finishWire`: Pin connected to the finish wire.

### `setup()` Function
- Initializes the LCD display.
- Configures the pins for the buzzer, wire, and finish wire.
- Displays a welcome message on the LCD.

### `loop()` Function
- Continuously checks the state of the wire and finish wire.
- If the loop touches the wire:
  - Activates the buzzer.
  - Displays "You Lose" on the LCD.
- If the loop reaches the finish wire:
  - Deactivates the buzzer.
  - Displays "You Win" on the LCD.
- Otherwise:
  - Displays the game title on the LCD.

## How to Use
1. Connect the components as per the circuit diagram.
2. Upload the code to the Arduino board.
3. Navigate the loop along the wire without touching it.
4. Reach the finish wire to win the game.

## Notes
- Ensure the buzzer and wires are connected to the correct pins.
- Adjust the game logic in the code if needed for different wire configurations.
- Ensure the power supply is sufficient to drive the buzzer and LCD display.

## Troubleshooting
- If the buzzer does not sound:
  - Check the connections of the buzzer and `buzzerPin`.
  - Verify the wire and finish wire connections.
- If the LCD does not display text:
  - Check the I2C address and connections.
  - Verify the LiquidCrystal_I2C library is installed correctly.

## Future Improvements
- Add a timer to track how long the player takes to complete the game.
- Implement multiple difficulty levels with different wire shapes.
- Add sound effects or a score system for better gameplay feedback.

