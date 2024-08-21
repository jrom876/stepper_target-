//	Package:	target
//	File:		target.c 
//	Author:		jrom876

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <check.h>
#include <curses.h>
#include <stdbool.h>

//************************************
// Global Variables
//************************************
int stepperDirection=0;
int commandValue=0, initialValue=0;

//************************************
// Decimal to Hexadecimal Converter
//************************************
int power(int base, unsigned int exp) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
}

int dec_to_hex(int decimal) {
	int i = 0, hec;
	double hex = 0;
	while (decimal != 0) {
        hec = decimal % 16;
        hex = hex + (hec * power(10, i));
        decimal = floor(decimal/16);
        i += 1;
	}
	printf("decimal to hex:\t"); // DBPRINT
	printf("%d\n",(int)hex); // DBPRINT
	return (int)hex;
}

//************************************
// Functions
//************************************
int setTarget (int target, int direction){
	target = (target <= 100) ? target : 100; // this keeps target value <= 100
    initialValue = target << 1;
    initialValue += direction;
    return dec_to_hex(initialValue);
}

int getTarget (int target){
    stepperDirection = ((target % 2) != 0) ? 1 : 0;
    commandValue = target >> 1;
    return commandValue;
}

int getDirection (void){
    return stepperDirection;
}

//************************************
// Main Loop
//************************************
int main(int argc, char const *argv[]) {
	
	printf("Enter the target distance:\n");
	scanf("%d", &initialValue);	
	//~ dec_to_hex(initialValue);
	printf("Enter the direction:\n");
	scanf("%d", &stepperDirection);	
	setTarget(initialValue, stepperDirection);
	
	//~ setTarget(0x64, 1); // DBPRINT
	printf("Converted Value: %d\n", initialValue); // DBPRINT
	getTarget(initialValue);
	printf("Target Value: %d\nDirection: %d\n", getTarget(initialValue), getDirection()); // DBPRINT
	return 0;
}
