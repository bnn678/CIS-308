/**************************************************************************************
* Name: Brandon Shaver
* Date: January 31st, 2018
* Assignment: Project 1: Interger Operations
***************************************************************************************
* The program takes an interger input as a string then outputs
* the input in reverse and the sum of the digits in the string
**************************************************************************************/

#include <stdio.h>
#include <string.h>

#define STRING_LENGTH 10
#define _CRT_SECURE_NO_WARNINGS


/**************************************************************************************
Input: user given input
Output: void
Pre-condition: input must be filled with the char[] of the user's input
Post-condition: no varibles are modified
**************************************************************************************/
void Reverse_String(char* input)
{
	if (*input)
	{
		// return the remainder of the string
		Reverse_String(input + 1);
		// print one character
		printf("%c", *input);
	}
	// NOTE: if you switched "Reverse_String" with "printf" the string would print in its original order
}


/**************************************************************************************
Input: int version user given input
Output: the sum of the digits in the user's input
Pre-condition: num must be an int version of user's input
Post-condition: Sum_Digits will ultimately return the sum of the digits in the user's input
**************************************************************************************/
int Sum_Digits(int num)
{
	// take one digit off the end at a time
	// by dividing by 10
	// when no digits are left, climb stack
	if (num != 0)
		return (num % 10 + Sum_Digits(num / 10));
	else
		return 0;
}


int main()
{
	// varible declarations
	char input[STRING_LENGTH +1];
	int input_length = 0;
	int sum = 0;

	// assigning the end for the char[]'s
	input[STRING_LENGTH] = '\0';

	// promt for and store the int from user
	printf("Enter a number: ");
	fgets(input, STRING_LENGTH, stdin);

	// remove '\n' character from input if necessary
	input_length = strlen(input);
	if (input[input_length - 1] == '\n')
		input[input_length - 1] = '\0';

	// Calculate and output the reversed string
	printf("\nReversed: ");
	Reverse_String(input);

	// calculate and display the sum of the digits in the input
	sum = atoi(input);
	sum = Sum_Digits(sum);
	printf("\nSum of digits: %d\n", sum);

	// pause the program and wait for the user to press enter
	fgets(input, STRING_LENGTH, stdin);
}

// I referenced code from https://www.geeksforgeeks.org/reverse-a-string-using-recursion/ and http://www.sanfoundry.com/c-program-sum-of-digits-using-recursion/