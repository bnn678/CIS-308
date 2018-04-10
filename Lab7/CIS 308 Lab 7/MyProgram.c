#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int item;
	struct node *next;
} Node;

void Delete(Node** list, Node node_to_remove)
{
	Node** npp;
	Node* last_node;

	// for loop deletes Node with i from linked list
	for (npp = &(*list); (*npp) != NULL; *npp = (*npp)->next)
	{
		if ((*npp)->item == node_to_remove.item) // if found
		{
			// reset next node
			last_node->next = (*npp)->next;
			break;
		}
	}
}

void Insert(Node** list, Node node_to_add)
{
	Node** npp;
	Node* last_node;

	// for loop deletes Node with i from linked list
	for (npp = &(*list); (*npp) != NULL; *npp = (*npp)->next)
	{
		if ((*npp)->item >= node_to_add.item) // if found
		{
			// reset next node
			node_to_add->next = (*npp)-next;
			break;
		}
	}
}

int main(int argc, const char* argv[])
{
	Node *node3 = malloc(sizeof(Node));
	node3->item = 3;
	node3->next = node3;

	Node *node2 = malloc(sizeof(Node));
	node2->item = 2;
	node2->next = node3;

	Node *head = malloc(sizeof(Node));
	head->item = 1;
	head->next = node2;

	Node **list;
	int i = 1;

	

	return 0;
}