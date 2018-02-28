#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
#include "io.h"
#include "bst.h"
*/
#pragma warning(disable:4996)
/***********************************************************************
* Name: Brandon Shaver
* Date: 2/25/2018
* Assignment: Project 2 - Sequence and Order validation
************************************************************************
* The program is designed to create a BST based on user input.
* It takes in numbers to add to BST.
* The user can test if a node is in the BST or 
* print an Inorder Traversal of the BST.
***********************************************************************/

// IO FUNCTIONS:
int GetProgramState()
{
	char state = 0;

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
	default:
		return 0;
	}
}

int GetInsertionNum()
{
	char buffer[5];
	printf("Enter a number to insert: ");
	fgets(buffer, 4, stdin);
	if (strcmp("\n", buffer) == 0)
		fgets(buffer, 4, stdin);

	return atoi(buffer);
}

int GetSearchNum()
{
	char buffer[5];

	printf("Enter a number to search for: ");
	fgets(buffer, 4, stdin);
	if (strcmp("\n", buffer) == 0)
		fgets(buffer, 4, stdin);

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




// BST FUNCTIONS:

typedef struct BST_Node {
	int key;
	struct BST_Node* left_node;
	struct BST_Node* right_node;
} BST_Node;

/***********************************************************************
* Description: Adds a node to the BST
* Precondition:
* Postcondition: Node will be added to BST
***********************************************************************/
void AddNode(BST_Node* curr_node, int key_to_add)
{
	if (curr_node->key == 0)
	{
		curr_node->key = key_to_add;
	}
	else if (key_to_add > curr_node->key)
	{
		if (curr_node->right_node == 0)
		{
			BST_Node new_node = { 0 };
			new_node.key = key_to_add;
			curr_node->right_node = &new_node;
		}
		else
		{
			AddNode(curr_node->right_node, key_to_add);
		}
	}
	else if (key_to_add < curr_node->key)
	{
		if (curr_node->left_node == 0)
		{
			BST_Node new_node = { 0 };
			new_node.key = key_to_add;
			curr_node->left_node = &new_node;
		}
		else
		{
			AddNode(curr_node->left_node, key_to_add);
		}
	}
}

bool Search(BST_Node curr_node, int key_to_find)
{
	if (curr_node.key == 0)
		return false;

	if (key_to_find == curr_node.key)
		return true;
	else if (key_to_find < curr_node.key)
		return Search(*(curr_node.left_node), key_to_find);
	else if (key_to_find > curr_node.key)
		return Search(*(curr_node.right_node), key_to_find);

	return false;
}

void InorderTraversal(BST_Node curr_node, char* output)
{
	if (curr_node.left_node != 0)
	{
		InorderTraversal(*(curr_node.left_node), output++);
	}
	else if (curr_node.right_node != 0)
	{
		InorderTraversal(*(curr_node.right_node), output++);
	}

	sprintf(output, "%d");
}

char* GetStringInorderTraversal(BST_Node curr_node)
{
	char buffer[100] = { 0 };

	InorderTraversal(curr_node, buffer);

	return buffer;
}





enum PROGRAM_STATE { QUIT, INSERT, SEARCH, TRAVERSE};

// MAIN CONTROLLER:
int main()
{
	// Varibles:
	enum PROGRAM_STATE program_state;
	BST_Node head_node = { 0 };
	int num;

	// Controller Loop:
	while (true)
	{
		num = 0;
		program_state = GetProgramState(); // stuff goes bad <-- HOW????

		num = GetInsertionNum();
		AddNode(&head_node, num);
		/*
		if (program_state == QUIT)
		{
			return 0;
		}
		else if (program_state == INSERT)
		{
			num = GetInsertionNum();
			AddNode(&head_node, num);
		}
		else if (program_state == SEARCH)
		{
			num = GetSearchNum();
			DisplaySearchResult(Search(head_node, num));
		}
		else if (program_state == TRAVERSE)
		{
			char* traversal_string = GetStringInorderTraversal(head_node);
			DisplayTraversalString(traversal_string);
		}
		*/
	}
}