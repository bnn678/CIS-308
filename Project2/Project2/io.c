/***********************************************************************
* Name: Brandon Shaver
* Date: 2/25/2018
* Assignment: Project 2 - Sequence and Order validation
************************************************************************
* The program is designed to create a BST based on user input.
* It takes in numbers to add to BST.
* The user can test if a nod is in the BST or
* print an Inorder Traversal of the BST.
***********************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// IO FUNCTIONS:
char* GetString(char* output)
{
	fgets(output, 4, stdin);
	if (strcmp("\n", output) == 0)
		fgets(output, 4, stdin);
}

int GetProgramState()
{
	char state = 0;
	char* temp = (char *)calloc(100, sizeof(char));

	printf("Enter [i]nsert, [s]earch, inorder [t]ransversal, or [q]uit: ");

	while (true)
	{
		state = fgetc(stdin);

		if (state == 'q' || state == 'i' || state == 's' || state == 't')
		{
			switch (state)
			{
			case ('q'):
				return 0;
			case ('i'):
				return 1;
			case ('s'):
				return 2;
			case ('t'):
				return 3;
			default:
				return 0;
			}
		}
	}
}

int GetInsertionNum()
{
	char buffer[5];
	printf("Enter a number to insert: ");
	GetString(&buffer);

	return atoi(buffer);
}

int GetSearchNum()
{
	char buffer[5];

	printf("Enter a number to search for: ");
	GetString(&buffer);

	return atoi(buffer);
}

void DisplaySearchResult(bool success)
{
	if (success)
	{
		printf("Num is in tree.\n");
	}
	else
	{
		printf("Num is not in tree.\n");
	}
}

void DisplayTraversalString(char* traversal_string)
{
	printf("%s\n", traversal_string);
}
// IO FUNCTIONS:
char* GetString(char* output)
{
	fgets(output, 4, stdin);
	if (strcmp("\n", output) == 0)
		fgets(output, 4, stdin);
}

int GetProgramState()
{
	char state = 0;
	char* temp = (char *)calloc(100, sizeof(char));

	printf("Enter [i]nsert, [s]earch, inorder [t]ransversal, or [q]uit: ");

	while (true)
	{
		state = fgetc(stdin);

		if (state == 'q' || state == 'i' || state == 's' || state == 't')
		{
			switch (state)
			{
			case ('q'):
				return 0;
			case ('i'):
				return 1;
			case ('s'):
				return 2;
			case ('t'):
				return 3;
			default:
				return 0;
			}
		}
	}
}

int GetInsertionNum()
{
	char buffer[5];
	printf("Enter a number to insert: ");
	GetString(&buffer);

	return atoi(buffer);
}

int GetSearchNum()
{
	char buffer[5];

	printf("Enter a number to search for: ");
	GetString(&buffer);

	return atoi(buffer);
}

void DisplaySearchResult(bool success)
{
	if (success)
	{
		printf("Num is in tree.\n");
	}
	else
	{
		printf("Num is not in tree.\n");
	}
}

void DisplayTraversalString(char* traversal_string)
{
	printf("%s\n", traversal_string);
}