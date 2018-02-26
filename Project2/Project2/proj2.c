//#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "io.h"
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


#include "bst.h"

#pragma warning(disable:4996)

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
		program_state = GetProgramState();

		if (program_state == QUIT)
		{
			return 0;
		}
		else if (program_state == INSERT)
		{
			num = GetInsertionNum();
			AddNode(head_node, num);
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
	}
}