# Bowling Score Calculator (C++ Console Application)

This is a simple C++ console application that simulates a 10-frame bowling game. It allows the user to input the number of pins knocked down in each roll and calculates the final score according to standard bowling rules.

## Features

- Accepts user input for each roll
- Handles all bowling scoring rules:
  - Strikes
  - Spares
  - Bonus rolls in the 10th frame
- Displays the final score after 10 frames

## Bowling Game – Rules and Conditions

The game consists of 10 frames.

In each frame, the player has up to 2 rolls to knock down 10 pins.

If the player knocks down all 10 pins in the first roll of a frame, it’s called a strike and the frame ends immediately.

If the player knocks down all 10 pins in two rolls, it’s called a spare.

The score for a frame is:

Strike: 10 + pins from the next two rolls.

Spare: 10 + pins from the next one roll.

Open frame (less than 10 pins in two rolls): total pins knocked down in that frame.



10th Frame Special Rule

If a strike or spare is scored in the 10th frame, the player gets extra roll(s):

Strike: 2 bonus rolls

Spare: 1 bonus roll


The maximum number of rolls in a game is 21.
