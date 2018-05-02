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
***********************************************************************/
void RemoveNode(BST_Node** head, int key_to_remove)
{
	BST_Node* head_node = *head;
	BST_Node* parent_of_node_to_remove = 0;
	BST_Node* node_to_remove = 0;

	enum CHILD_SIDE { none, left, right } child_side;

	if (Search(*head_node, key_to_remove) == true)
	{
		parent_of_node_to_remove = GetNodeParent(head_node, key_to_remove);
	}
	else
		return 0;

	// Determine if node is left or right sided
	if (parent_of_node_to_remove == 0)
	{
		node_to_remove = head_node;
		child_side = none;
	}
	else if (parent_of_node_to_remove->left_node == 0)
	{
		node_to_remove = parent_of_node_to_remove->right_node;
		child_side = right;
	}
	else if (parent_of_node_to_remove->right_node == 0)
	{
		node_to_remove = parent_of_node_to_remove->left_node;
		child_side = left;
	}
	else if (parent_of_node_to_remove->left_node->key == key_to_remove)
	{
		node_to_remove = parent_of_node_to_remove->left_node;
		child_side = left;
	}
	else if (parent_of_node_to_remove->right_node->key == key_to_remove)
	{
		node_to_remove = parent_of_node_to_remove->right_node;
		child_side = right;
	}

	// Case A
	if (node_to_remove->left_node == 0 && node_to_remove->right_node == 0)
	{
		if (child_side == none)
			head_node->key = 0;

		else
		{
			if (child_side == left)
				parent_of_node_to_remove->left_node = 0;
			else if (child_side == right)
				parent_of_node_to_remove->right_node = 0;

			free(node_to_remove);
		}
	}
	// Case B
	else if (node_to_remove->left_node != 0 && node_to_remove->right_node == 0)
	{
		if (child_side == none)
		{
			*head = node_to_remove->left_node;
		}
		else
		{
			if (child_side == left)
				parent_of_node_to_remove->left_node = node_to_remove->left_node;
			else if (child_side == right)
				parent_of_node_to_remove->right_node = node_to_remove->left_node;
		}

		free(node_to_remove);
	}
	else if (node_to_remove->right_node != 0 && node_to_remove->left_node == 0)
	{
		if (child_side == none)
		{
			*head = node_to_remove->right_node;
		}
		else
		{
			if (child_side == left)
				parent_of_node_to_remove->left_node = node_to_remove->right_node;
			else if (child_side == right)
				parent_of_node_to_remove->right_node = node_to_remove->right_node;
		}

		free(node_to_remove);
	}
	// Case C
		// Find inorder successor of the node. 
		// Copy contents of the inorder successor to the node and delete the inorder successor. 
		// Note that inorder predecessor can also be used.
	else if (node_to_remove->left_node != 0 && node_to_remove->right_node != 0)
	{
		BST_Node* min_node = node_to_remove->right_node;

		// find next smallest value for a node
		while (min_node->left_node != 0)
			min_node = min_node->left_node;

		if (node_to_remove->right_node->key == min_node->key)
		{
			parent_of_node_to_remove = GetNodeParent(head_node, min_node->key);
			if (parent_of_node_to_remove->left_node->key == min_node->key)
				parent_of_node_to_remove->left_node = 0;
			else if (parent_of_node_to_remove->right_node->key == min_node->key)
				parent_of_node_to_remove->right_node = 0;
		}

		parent_of_node_to_remove = GetNodeParent(head_node, min_node->key);
		if (parent_of_node_to_remove->left_node->key == min_node->key)
			parent_of_node_to_remove->left_node = 0;
		else if (parent_of_node_to_remove->right_node->key == min_node->key)
			parent_of_node_to_remove->right_node = 0;

		node_to_remove->key = min_node->key;

		free(min_node);
	}
}
