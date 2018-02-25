#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int GetProgramState()
{
	char state;
	int return_num;

	printf("Enter [i]nsert, [s]earch, inorder [t]ransversal, or [q]uit: ");
	state = fgetc(stdin);

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
	}

	return state;
}

int GetInsertionNum()
{
	int num;
	char buffer[5];

	printf("Enter a number to insert: ");
	fgets(buffer, 4, stdin);

	return atoi(buffer);
}

