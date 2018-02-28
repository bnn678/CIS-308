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

#include "io.h"

// IO FUNCTIONS:

/***********************************************************************
* Description: Gets a string from the user.
* Precondition: 
* Postcondition: output will contain a string from the user
***********************************************************************/
char* GetString(char* output)
{
	fgets(output, 4, stdin);
	if (strcmp("\n", output) == 0)
		fgets(output, 4, stdin);
}


/***********************************************************************
* Description: Get the user's desired program state
* Precondition: the user inputs a char representing their desired program state
* Postcondition: the function returns a char containing the desired program state
***********************************************************************/
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


/***********************************************************************
* Description: Get the user's desired insertion number
* Precondition:	the user inputs an int respresenting their desired insertion num
* Postcondition: the function returns an int containing the desired program state
***********************************************************************/
int GetInsertionNum()
{
	char buffer[5];
	printf("Enter a number to insert: ");
	GetString(&buffer);

	return atoi(buffer);
}


/***********************************************************************
* Description: Get the user's desired number to search for in the BST
* Precondition: the user enter an int
* Postcondition: the function returns the int
***********************************************************************/
int GetSearchNum()
{
	char buffer[5];

	printf("Enter a number to search for: ");
	GetString(&buffer);

	return atoi(buffer);
}


/***********************************************************************
* Description: Display the result of the search
* Precondition: 
* Postcondition: Displays the result of the search to the Console
***********************************************************************/
void DisplaySearchResult(bool success, int num)
{
	if (success)
	{
		printf("%d is in tree.\n", num);
	}
	else
	{
		printf("%d is not in tree.\n", num);
	}
}


/***********************************************************************
* Description: Displays the transversal of the BST
* Precondition:
* Postcondition: Displays the transversal of the BST to the Console
***********************************************************************/
void DisplayTraversalString(char* traversal_string)
{
	printf("%s\n", traversal_string);
}