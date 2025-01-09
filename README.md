# stepper_target-
Stepper motor position and direction converter

This is to prove that you can use a 1-byte UART command to control the position and direction of a 200-step per cycle stepper motor.

The steps are as follows:
1)  The processor receives a decimal number of the desired position (from 0 to 100 steps) and a direction bit (0 = clockwise, 1 = counter-clockwise) from the user
2)  The code converts the decimal number to the hexadecimal equivalent. For instance: 100d == 0x64 
3)  The code left shifts that hex value by 1 bit, << 1 , which doubles it, then adds the direction bit (0 or 1).
   For instance, 100 steps counter clockwise becomes 0xC9: ((100d * 2) + 1) == 201d == ((0x64 << 1) + 1) == 0xC9
4)  Transmit the byte to the motor controller's processor
5)  The motor controller code reverses steps 3 through 1 above. It takes % 2 (modulus 2) of the hex number to extract the direction bit, then right shifts the hex number 1 bit (>> 1, which divides it by 2), then converts the result to decimal to get the desired number of steps in decimal.

 This algorithm is very simple and elegant, and it takes a surprisingly few lines of code.
