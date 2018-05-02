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

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#pragma warning(disable:4996)

typedef struct BST_Node {
	int key;
	struct BST_Node* left_node;
	struct BST_Node* right_node;
} BST_Node;

void AddNode(BST_Node* curr_node, int key_to_add);

bool Search(BST_Node curr_node, int key_to_find);

void InorderTraversal(BST_Node curr_node, char* output);

void FreeBST(BST_Node* curr_node);

BST_Node* RemoveNode(BST_Node* curr_node, int key_to_remove);