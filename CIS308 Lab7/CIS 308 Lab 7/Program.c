#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int item;
	struct list *next;
} List;

int main(int argc, const char* argv[])
{
	List *node3 = malloc(sizeof(List));
	node3->item = 3;
	node3->next = node3;

	List *node2 = malloc(sizeof(List));
	node2->item = 2;
	node2->next = node3;

	List *list = malloc(sizeof(List));
	list->item = 1;
	list->next = node2;

	List *lp, *prevlp = NULL;
	int i = 1;

	for (lp = list; lp != NULL; lp = lp->next)
	{
		if (lp->item == i)
		{
			if (lp == list)
			{
				list = lp->next;
			}
			else
				prevlp->next = lp->next;
			break;
		}
		prevlp = lp;
	}

	return 0;
}