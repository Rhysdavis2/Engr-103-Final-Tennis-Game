# Engr-103-Final-Tennis-Game

Inputs: Left and right buttons.
Outputs: Sound and light.

Game rules:

Start with the CPX board oriented such that texts and symbols are upside down.
You will start with a score of 0.
The game will alternate between two "serves", a serve from the left and a serve from the right.

When a serve from the left is occuring, the LED will flash green sequentially from LEDs 2 to 7; sucsesfully pressing the button at the right of the CPX board when the light first flashes at LED 7 will play a sound and increase your score by 1.
When a serve from the right is occuring, the LED will flash green sequentially from LEDs 7 to 2; sucsesfully pressing the button at the right of the CPX board when the light first flashes at LED 2 will play a sound and increase your score by 1.

If you fail to press the correct button on time, your score will reset to 0, and a high pitched tone will play.
Each time your score increases, the speed that the LED flashes across the CPX board will increase, the timing will get more difficult.
If you reach a score of 10, you have won! The game will play a quick song before resetting. 
