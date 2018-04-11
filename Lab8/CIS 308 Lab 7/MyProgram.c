#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int item;
	struct node *next;
} Node;

void DeleteNode(Node** npp, Node* head, int i)
{
	Node* prev_node = NULL;

	// for loop deletes Node with i from linked list
	for (npp = &head; (*npp) != NULL; (*npp) = (*npp)->next)
	{
		if ((*npp)->item == i) // if found
		{
			// reset next node
			if ((*npp) == head)
				head = &( (*npp)->next );
			else
				prev_node->next = (*npp)->next;
			break;
		}
		prev_node = (*npp);
	}
}

void InsertNode(Node** npp, Node* head, int i)
{
	Node* new_node = malloc(sizeof(Node));
	new_node->item = i;
	new_node->next = NULL;

	for (npp = &head; (*npp) != NULL; npp = &(*npp)->next)
	{
		Node* np = *npp;

		if (new_node->item < np->item)
		{
			new_node->next = np;
			*npp = new_node;
			break;
		}
	}
}

int main(int argc, const char* argv[])
{
	Node *node3 = malloc(sizeof(Node));
	node3->item = 9;
	node3->next = NULL;

	Node *node2 = malloc(sizeof(Node));
	node2->item = 6;
	node2->next = node3;

	Node *head = malloc(sizeof(Node));
	head->item = 1;
	head->next = node2;

	Node **npp = 0;

	//DeleteNode(npp, head, 1);

	Node* prev_node = NULL;
	int i = 1;

	// for loop deletes Node with i from linked list
	for (npp = &head; (*npp) != NULL; (*npp) = (*npp)->next)
	{
		if ((*npp)->item == i) // if found
		{
			// reset next node
			if ((*npp) == head)
				head = ((*npp)->next);
			else
				prev_node->next = (*npp)->next;
			break;
		}
		prev_node = (*npp);
	}

	i = 3;
	Node* new_node = malloc(sizeof(Node));
	new_node->item = i;
	new_node->next = NULL;

	for (npp = &head; (*npp) != NULL; npp = &(*npp)->next)
	{
		Node* np = *npp;

		if (new_node->item < np->item)
		{
			new_node->next = np;
			*npp = new_node;
			break;
		}
	}

	return 0;
}