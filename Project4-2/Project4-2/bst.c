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
* Precondition: Parameters are defined and initilized
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


/***********************************************************************
* Description: Test if a Node is in BST
* Precondition: Parameters are defined and initilized
* Postcondition: Returns boolean. True if Node was found, false if not.
***********************************************************************/
bool Search(BST_Node curr_node, int key_to_find)
{
	if (key_to_find == curr_node.key)
		return true;
	else if (key_to_find < curr_node.key)
	{
		if (curr_node.left_node != 0)
			return Search(*(curr_node.left_node), key_to_find);
	}
	else if (key_to_find > curr_node.key)
	{
		if (curr_node.right_node != 0)
			return Search(*(curr_node.right_node), key_to_find);
	}
}


/***********************************************************************
* Description: Gets the Inorder Traversal of the BST
* Precondition: Parameters are defined and initilized. Output is long enough to account for the Traversal
* Postcondition: output will contain a string of the traversal.
***********************************************************************/
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


/***********************************************************************
* Description: Frees BST
* Precondition: All Nodes are dynamically allocated (including head).
* Postcondition: Nodes will be freed.
***********************************************************************/
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


/***********************************************************************
* Description: Gets a Node from the BST
* Precondition: All Nodes are dynamically allocated (including head)
and the Node to Get is in the tree
* Postcondition: Returns the Node with the key_to_find
***********************************************************************/
BST_Node* GetNode(BST_Node* curr_node, int key_to_find)
{
	if (key_to_find == curr_node->key)
		return curr_node;


	else if (key_to_find < curr_node->key)
	{
		if (curr_node->left_node != 0)
			return GetNode(curr_node->left_node, key_to_find);
	}
	else if (key_to_find > curr_node->key)
	{
		if (curr_node->right_node != 0)
			return GetNode(curr_node->right_node, key_to_find);
	}
}

/***********************************************************************
* Description: Gets a Node's parent from the BST
* Precondition: All Nodes are dynamically allocated (including head)
and the Node to Get is in the tree
* Postcondition: Returns the Node with the key_to_find's parent
***********************************************************************/
BST_Node* GetNodeParent(BST_Node* curr_node, int key_to_find)
{
	if (curr_node->left_node != 0)
	{
		if (key_to_find == (curr_node->left_node)->key)
		{
			return curr_node;
		}
	}
	if (curr_node->right_node != 0)
	{
		if (key_to_find == (curr_node->right_node)->key)
		{
			return curr_node;
		}
	}

	if (key_to_find < curr_node->key)
	{
		if (curr_node->left_node != 0)
			return GetNodeParent(curr_node->left_node, key_to_find);
	}
	if (key_to_find > curr_node->key)
	{
		if (curr_node->right_node != 0)
			return GetNodeParent(curr_node->right_node, key_to_find);
	}

	return 0;
}

/***********************************************************************
* Description: Removes a Node from the BST
* Precondition: All Nodes are allocated (including head)
and the Node to remove is in the tree
* Postcondition: Removes the Node from the BST, frees the Node and replaces
children so the BST is still valid

I referenced geeksforgeeks.org/binary-search-tree-set-2-delete/ to complete this code
***********************************************************************/
BST_Node* RemoveNode(BST_Node* head_node, int key_to_remove)
{
	if (head_node == 0)
		return head_node;

	if (head_node->key > key_to_remove)
		head_node->left_node = RemoveNode(head_node->left_node, key_to_remove);
	else if (head_node->key < key_to_remove)
		head_node->right_node = RemoveNode(head_node->right_node, key_to_remove);
	else
	{
		// Case B
		if (head_node->left_node == NULL)
		{
			BST_Node* temp_node = head_node->right_node;
			free(head_node);
			return temp_node;
		}
		else if (head_node->right_node == NULL)
		{
			BST_Node* temp_node = head_node->left_node;
			free(head_node);
			return temp_node;
		}
		// Case C
		else
		{
			BST_Node* temp_node = head_node->right_node;
			while (temp_node->left_node != 0)
				temp_node = temp_node->left_node;
			head_node->key = temp_node->key;
			head_node->right_node = RemoveNode(head_node->right_node, temp_node->key);
		}
	}

	return head_node;
}