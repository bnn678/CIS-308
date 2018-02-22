#include <stdio.h>
#include <string.h>

#define INPUT_LENGTH 30

#pragma warning(disable: 4996)

enum Grade { Freshman = 1, Sophomore = 2, Junior = 3, Senior = 4 };

struct Student
{
	char name[INPUT_LENGTH+1]; // an arbitary length
	int age;
	char grade[10]; // the longest name is sophomore which is 9 chars
};

void display(struct Student* studentPtr)
{
	printf("\nStudent's name is %s", studentPtr->name);
	printf("He/she is %d years old.\n", studentPtr->age);
	printf("He/she is a %s", studentPtr->grade);
}

void IncrementGrade(char* grade)
{
	if (strcmp(grade, "Freshman\n") == 0)
		strcpy(grade, "Sophomore");
	else if (strcmp(grade, "Sophomore\n") == 0)
		strcpy(grade, "Junior");
	else if (strcmp(grade, "Junior\n") == 0)
		strcpy(grade, "Senior");
}

int main()
{
	struct Student* studentPtr;
	studentPtr = malloc(sizeof(struct Student));

	enum Grade grade = 1;

	char input[INPUT_LENGTH + 1] = { 0 };

	printf("Enter your name: ");
	fgets(input, INPUT_LENGTH, stdin);
	strcpy(studentPtr->name, input);

	printf("Enter your age: ");
	fgets(input, INPUT_LENGTH, stdin);
	studentPtr->age = atoi(input);

	printf("Enter your grade (Freshman, Sophomore, etc.): ");
	fgets(input, INPUT_LENGTH, stdin);
	strcpy(studentPtr->grade, input);

	display(studentPtr);
	studentPtr->age += 1; IncrementGrade(studentPtr->grade);
	display(studentPtr);

	free(studentPtr); // Does this free all of studentPtr or just the address?

	;
}