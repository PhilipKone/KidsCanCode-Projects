# Word Jumble

This project demonstrates how to create a word jumble game using an Arduino microcontroller and an LCD display. The player unscrambles jumbled words using a rotary knob and a button.

## Components Used
1. **Arduino Board**: The microcontroller used to control the game.
2. **16x2 I2C LCD Display**: Displays the jumbled word and game instructions.
3. **Rotary Knob**: Used to select letters for swapping.
4. **Push Button**: Used to swap letters.
5. **Power Supply**: Provides power to the components and Arduino.

## Libraries Used
1. **LiquidCrystal_I2C**: Used to control the I2C LCD display.

## Code Overview

### Global Variables
- `wordList`: Array of words stored in program memory (PROGMEM).
- `wordIndex[]`: Array to shuffle the word list without modifying the original.
- `werd`: Stores the current word to be unscrambled.
- `jumble`: Stores the jumbled version of the current word.
- `lastKnob`: Tracks the last position of the rotary knob.
- `lastPressState`: Tracks the last state of the button.

### `setup()` Function
- Initializes the LCD display and inputs.
- Scrambles the word list and selects a new word for the game.

### `loop()` Function
- Continuously checks the rotary knob and button inputs.
- Updates the LCD display with the current state of the jumbled word.
- Checks if the player has successfully unscrambled the word.

### `NewGame()` Function
- Selects a new word from the shuffled list.
- Jumbles the selected word and displays it on the LCD.

### `KnobArrow()` Function
- Handles the rotary knob and button inputs.
- Allows the player to select letters and swap them.

### `Win()` Function
- Displays a congratulatory message when the player unscrambles the word.
- Waits for the player to press the button to start a new game.

## How to Use
1. Connect the components as per the circuit diagram.
2. Upload the code to the Arduino board.
3. Use the rotary knob to select letters and the button to swap them.
4. Unscramble the word to match the original.

## Notes
- Ensure the LCD display is connected to the correct I2C address (`0x27` by default).
- Adjust the word list in the code to include custom words.
- Ensure the power supply is sufficient to drive the LCD display.

## Troubleshooting
- If the LCD does not display text:
  - Check the I2C address and connections.
  - Verify the LiquidCrystal_I2C library is installed correctly.
- If the rotary knob or button does not work:
  - Check the connections and ensure the correct pins are used.

## Future Improvements
- Add a timer to challenge the player to solve the puzzle within a time limit.
- Implement multiple difficulty levels with varying word lengths.
- Add sound effects or a buzzer for feedback.

