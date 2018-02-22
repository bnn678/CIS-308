#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable: 4996)


void reverse_function(char* str, char* first, int strlen, int depth)
{
	if (*str) {
		char c = *str;
		reverse_function(str + 1, first, strlen, ++depth);
		*(first + strlen - depth) = c;
	}
}

void Reverse(char* str)
{
	reverse_function(str, str, strlen(str), 0);
}

int main()
{
	// Primitive Data Types
	int i = 0;
	char c = 'a';
	float f = 0.0;
	double d = 0.0;



	// Arrays
	int int_array1[10]; // declaration
	int int_array2[10] = { 0 }; // init to zero
	int int_array3[10] = { 1,2,3,4,5,6,7,8,9,10 }; // init to non-zero
	int int_array4[] = { 1,2,3,4,5,6,7,8,9, 10 }; // init to non-zero
	int int_array5[10] = { 1,2,3,4,5 }; // init to non-zero w/ inspecificed elements set to 0
	int_array1[0] = 0; // first index
	int_array1[9] = 9; // last index
	//int_array1[10] = 10; // out of index



	// Identifiers and Varibles
	int x; int y;
	x = 12;
	y = 24;



	// Operators and Expressions
	printf("x + y = %d\n", x + y); // addition
	printf("x - y = %d\n", x - y); // subtraction
	printf("x * y = %d\n", x * y); // multiplication
	printf("x / y = %d\n", x / y); // division
	printf("x %% y = %d\n", x % y); // modulo // % is an escape character hence the %%



	// If, Else If, Else
	x = 12, y = 24;
	if (x == y)
		printf("They are equal\n");
	else if (x > y)
		printf("X > Y\n");
	else
		printf("X < Y\n");



	// Switch-Case
	x = 2;
	switch (x)
	{
	case(1):
		printf("X is 1\n");
		break;
	case(2):
		printf("X is 2\n");
	default:
		printf("Here because no break statement\n");
		break;
	}



	// For
	for (int i = 0; i < 3; i++)
	{
		printf("For loop count: %d\n", i);
	}




	// While
	i = 0; // was declared at the top of code
	while (i < 4)
	{
		printf("While loop count: %d\n", i);
		i++;
	}



	// Do-While
	i = 0;
	do {
		printf("Here because of do statement.");
	} while (i != 0);



	// Strings
	char string1[10]; // declaration
	char string2[10] = { 0 }; // declaration and init to 0
	char string3[10] = "Betty"; // declaration and init
	char string4[] = "BetterBetty"; // declaration and init
	//char string5[2] = "BadBetty"; // out of index
	strcpy(string1, string3); // requires string.h
	printf("These strings are equal: %d\n", strcmp(string1, string3));
	printf("These strings are not. First string is longer: %d\n", strcmp(string1, string2));
	printf("These strings are not. Second string is longer: %d\n", strcmp(string4, string3));



	// Files
	char input_buffer[20] = { 0 };
	char* input_pointer = NULL;
	FILE* file_pointer = fopen("Text.txt", "r");
	fgets(input_buffer, 19, file_pointer);
	printf("Here's what fgets found: %s\n", input_buffer);
	fclose(file_pointer);
	file_pointer = fopen("OtherText.txt", "w");
	fprintf(file_pointer, input_buffer);
	fclose(file_pointer);



	// Stack & Heap
	/*
	If allocated at compile time: stack. LIFO.
	If dynamically allocated: heap. Access in any order.
	*/



	// Pointers
	int a = 0;
	int* a_pointer = &a;
	*a_pointer = 100;
	printf("A's value: %d\n", a);
	printf("A's address: %d\n", &a);
	printf("A_pointer's value: %d\n", a_pointer);
	printf("A_pointer's address: %d\n", &a_pointer);
	printf("A_pointer's address's value: %d\n", *a_pointer);
	a = 20;
	printf("After changing a\tA_pointer's value: %d\n", a_pointer);
	printf("After changing a\tA_pointer's address's value: %d\n", *a_pointer);



	// Dynamic Memory
	printf("Memory size of an integer: %d\n", sizeof(int));
	printf("Enter a length for int[]: ");
	//fgets(input_buffer, strlen(input_buffer) - 1, stdin); cumbersome when running program many times. gonna predefine value for ease
	strcpy(input_buffer, "5");
	int input_length = atoi(input_buffer);
	int* malloc_array = malloc(input_length *sizeof(int));
	for (int i = 0; i < input_length; i++)
	{
		printf("%d contains %d\n", i, malloc_array[i]);
	}
	int* calloc_array = calloc(input_length, sizeof(int));
	for (int i = 0; i < input_length; i++)
	{
		printf("%d contains %d\n", i, calloc_array[i]);
	}
	free(malloc_array);
	free(calloc_array);



	// struct
	struct person {
		char name[20];
		int age;
	};
	struct person p;
	p.age = 25;
	printf("p's age: %d\n", p.age);
	struct phone {
		char name[20];
		int number;
	} phone1, phone2;
	strcpy(phone1.name, "Him");
	printf("phone1's name: %s\n", phone1.name);
	struct person* malloc_person;
	malloc_person = malloc(sizeof(struct person));
	(*malloc_person).age = 30;
	strcpy(malloc_person->name, "Bob");
	printf("malloc_person's name: %s, and age: %d\n", (*malloc_person).name, malloc_person->age);



	// enum
	enum medal { gold, silver, bronze };
	enum medal my_medal = gold;
	printf("my_medal: %d\n", my_medal);
	enum grade { freshman = 9, sophomore, junior, senior };
	enum grade my_grade = senior;
	printf("my_grade: %d\n", my_grade);



	// union
	union money {
		double dollars;
		int yen;
	};
	union money my_money;
	my_money.dollars = 10.00;
	printf("dollars: %f\n", my_money.dollars);
	my_money.yen = 100;
	printf("yen: %d\n", my_money.yen);
	//printf("dollars: %f\n", my_money.dollars); // BAD, may work but won't always



	// typedef
	typedef letterGrade;
	letterGrade my_letter;
	my_letter = 'F';
	printf("My letter grade: %c\n", my_letter);
	//typedef struct person; // DOESN'T WORK. C isn't sure what the name of the new data type is.
	typedef struct new_person {
		char name[20];
		enum grade his_grade;
	} person;
	person p3;
	p3.his_grade = sophomore;
	printf("His grade: %d", sophomore);



	// Recursion
	"One does not simply understand recursion.";
	"The only way to understand recursion is to understand recursion.";
	// reverse string example
	/*
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
	// sum string example
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
	*/


	printf("\n\n\n");

	char string[] = "abcdef";
	char* strPtr;
	strPtr = &string;

	Reverse(strPtr);
	printf("%s\n", string);
}