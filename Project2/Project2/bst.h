#include <stdbool.h>

typedef struct{
	int key;
	struct BST_Node* left_node;
	struct BST_Node* right_node;
} BST_Node;
/*
bool Search(Node head_node, int key_to_find)
{
	if (key_to_find < head_node.key)
		return Search(head_node.left_node, key_to_find);
	else if (key_to_find > head_node.key)
		return Search(*head_node.right_node, key_to_find);
	else if (key_to_find == head_node.key)
		return true;

	return false;
}

// HAS PRINT STATEMENT!?!!!
char* PrintInorderTraversal(Node head_node)
{
	if (head_node.left_node.key != 0)
	{
		PrintInorderTraversal(head_node.left_node);
	}
	else if (head_node.right_node.key != 0)
	{
		PrintInorderTraversal(head_node.right_node);
	}

	char output[5] = { 0 };
	itoa(head_node.key, output, 10);
	printf(output);
}
*/