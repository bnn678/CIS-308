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


#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

#pragma warning(disable:4996)

// BST FUNCTIONS:

/***********************************************************************
* Description: Adds a node to the BST
* Precondition: 
* Postcondition: Node will be added to BST
***********************************************************************/
void AddNode(BST_Node head_node, int key_to_add)
{
	if (key_to_add > head_node.key)
	{
		if (head_node.right_node == 0)
		{
			BST_Node new_node = { 0 };
			new_node.key = key_to_add;
			head_node.right_node = &new_node;
		}
		else
		{
			AddNode(*(head_node.right_node), key_to_add);
		}
	}
	else if (key_to_add < head_node.key)
	{
		if (head_node.left_node == 0)
		{
			BST_Node new_node = { 0 };
			new_node.key = key_to_add;
			head_node.left_node = &new_node;
		}
		else
		{
			AddNode(*(head_node.left_node), key_to_add);
		}
	}
}

bool Search(BST_Node head_node, int key_to_find)
{
	if (head_node.key == 0)
		return false;

	if (key_to_find == head_node.key)
		return true;
	else if (key_to_find < head_node.key)
		return Search(*(head_node.left_node), key_to_find);
	else if (key_to_find > head_node.key)
		return Search(*(head_node.right_node), key_to_find);

	return false;
}

void InorderTraversal(BST_Node head_node, char* output)
{
	if (head_node.left_node != 0)
	{
		InorderTraversal(*(head_node.left_node), output++);
	}
	else if (head_node.right_node != 0)
	{
		InorderTraversal(*(head_node.right_node), output++);
	}

	sprintf(output, "%d");
}

char* GetStringInorderTraversal(BST_Node head_node)
{
	char buffer[100] = { 0 };

	InorderTraversal(head_node, buffer);

	return buffer;
}