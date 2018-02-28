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

// BST FUNCTIONS:

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
			//BST_Node new_node = { 0 };
			BST_Node* new_node = (BST_Node*)calloc(4, sizeof(BST_Node));
			new_node->key = key_to_add;
			curr_node->right_node = new_node;
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
			BST_Node* new_node = (BST_Node*)calloc(4, sizeof(BST_Node));
			new_node->key = key_to_add;
			curr_node->left_node = new_node;
		}
		else
		{
			AddNode(curr_node->left_node, key_to_add);
		}
	}
}

bool Search(BST_Node curr_node, int key_to_find)
{
	if (key_to_find == curr_node.key)
		return true;
	else if (key_to_find < curr_node.key)
	{
		if (curr_node.left_node != 0)
			return Search(*(curr_node.left_node), key_to_find);
		else
			return false;
	}
	else if (key_to_find > curr_node.key)
	{
		if (curr_node.right_node != 0)
			return Search(*(curr_node.right_node), key_to_find);
		else
			return false;
	}
}

void InorderTraversal(BST_Node curr_node, char* output)
{
	if (curr_node.left_node != 0)
	{
		InorderTraversal(*(curr_node.left_node), output);
	}

	int length = strlen(output);
	for (int i = 0; i < length; i++) // NOTE: dangerous if transversal length > 99 b/c then there's no room for \0
		output++;

	sprintf(output, "%d \0", curr_node.key);

	if (curr_node.right_node != 0)
	{
		InorderTraversal(*(curr_node.right_node), output);
	}
}

void FreeBST(BST_Node* curr_node)
{
	if (curr_node->left_node != 0)
	{
		FreeBST(curr_node->left_node);
	}
	if (curr_node->right_node != 0)
	{
		FreeBST(curr_node->right_node);
	}

	free(curr_node);
}
