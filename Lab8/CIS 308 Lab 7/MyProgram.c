#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int item;
	struct node *next;
} Node;

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

	Node **npp;
	int i = 1;

	// for loop deletes Node with i from linked list
	for (npp = &head; (*npp) != NULL; *npp = (*npp)->next)
	{
		if ((*npp)->item == i) // if found
		{
			// reset next node
			if ((*npp) == head)
			{
				head = (*npp)->next;
			}
			break;
		}
	}

	return 0;
}