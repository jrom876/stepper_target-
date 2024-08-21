# stepper_target-
Stepper motor position and direction converter

This is to prove that you can use a 1-byte UART command to control the position and direction of a 200-step per cycle stepper motor.

The idea is to convert the decimal number of the desired position (from 0 to 100 steps) to the hexidecimal equivalent of that decimal number, left shift that hex value 1 (which doubles it), then add a direction bit (0 is clockwise, 1 is counter-clockwise).

After transmiting the byte, just take the %2 (modulus 2) of the hex number to extract the direction bit, right shift the hex number by 1, then convert it to decimal to get the desired number of steps. Very simple and elegant!!

This was a code snippet I wrote for the stepper motor driver of a laser particle detection device.
For some reason, I could not convince the CEO that this would work. This snippet proves that it does work.
