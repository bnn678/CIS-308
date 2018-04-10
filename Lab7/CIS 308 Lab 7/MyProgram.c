#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int item;
	struct node *next;
} Node;

<<<<<<< HEAD
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
=======
void RemoveNode(Node** npp, Node* head, int i)
{
	for (npp = &head; (*npp) != NULL; *npp = (*npp)->next)
	{
		if ((*npp)->item == i) // if found
		{
			// remove this node
			
>>>>>>> 9c081f2f1b39934305cefa09875a11d02786936f
			break;
		}
	}
}

<<<<<<< HEAD
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
=======
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

>>>>>>> 9c081f2f1b39934305cefa09875a11d02786936f
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

<<<<<<< HEAD
	Node **list;
	int i = 1;

	
=======
	Node **npp = &head;

	//RemoveNode(npp, head, 1);

	InsertNode(npp, head, 4);
>>>>>>> 9c081f2f1b39934305cefa09875a11d02786936f

	return 0;
}