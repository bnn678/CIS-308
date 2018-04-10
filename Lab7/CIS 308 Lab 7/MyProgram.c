#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int item;
	struct node *next;
} Node;

void RemoveNode(Node** npp, Node* head, int i)
{
	for (npp = &head; (*npp) != NULL; *npp = (*npp)->next)
	{
		if ((*npp)->item == i) // if found
		{
			// remove this node
			
			break;
		}
	}
}

void InsertNode(Node** npp, Node* head, int i)
{
	for (npp = &head; (*npp) != NULL; *npp = (*npp)->next)
	{
		if ((*npp)->item < i && i < (*npp)->next->item) // if found
		{
			// insert next node
			Node* new_node = malloc(sizeof(Node));
			new_node->item = i;
			new_node->next = (*npp)->next;
			(*npp)->next = new_node;

			break;
		}
	}
}

int main(int argc, const char* argv[])
{
	Node *node3 = malloc(sizeof(Node));
	node3->item = 3;
	node3->next = NULL;

	Node *node2 = malloc(sizeof(Node));
	node2->item = 2;
	node2->next = node3;

	Node *head = malloc(sizeof(Node));
	head->item = 1;
	head->next = node2;

	Node **npp = &head;

	//RemoveNode(npp, head, 1);

	InsertNode(npp, head, 4);

	return 0;
}