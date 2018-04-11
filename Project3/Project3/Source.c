#include <stdio.h>
#include <stdlib.h>

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int* list, int length)
{
	int* x = calloc(1, sizeof(int)); int* y = calloc(1, sizeof(int));

	printf("%d\n", length);

	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
		{
			if (list[i] > list[j])
			{
				x = &(list[i]);
				y = &(list[j]);
				Swap(x, y);
			}
		}
	}
}

int* SmallestList(int** lists, int elements, int* lengths)
{
	int current_min = 1000; // arbitartily large random num
	int min_index = -1;

	for (int i = 0; i < elements; i++)
	{
		if (lengths[i] < current_min)
		{
			current_min = lengths[i];
			min_index = i;
		}
	}

	return lists[min_index];
}

int** SortedLists(int** lists, int elements, int* lengths)
{
	int** sorted_lists = calloc(elements, sizeof(int*));

	int* current_smallest_list = calloc(1, sizeof(int*));
	for (int i = 0; i < elements; i++)
	{
		current_smallest_list = SmallestList(lists, elements, lengths);

		sorted_lists[i] = &current_smallest_list;
	}
}

int main()
{
	/**
	// EXAMPLE Swap CALL

	int* x = calloc(1, sizeof(int)); int* y = calloc(1, sizeof(int));
	int a = 2; int b = 4;
	x = &a; y = &b;
	Swap(x, y);
	printf("\n%d %d\n", a, b);
	*/

	/**
	// EXAMPLE BubbleSort CALL

	int* my_list = calloc(4, sizeof(int));
	my_list[0] = 1;
	my_list[1] = 4;
	my_list[2] = 2;
	my_list[3] = 0;
	BubbleSort(my_list, 4);

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", my_list[i]);
	}
	*/

	/**
	// EXAMPLE SmallestList CALL
	
	int** lists = calloc(4, sizeof(int*));

	int kewl[] = { 1,2 };
	int kewl2[] = { 2,3,5,7 };
	int kewl3[] = { 3,3,4 };
	int kewl4[] = { 4 };

	lists[0] = &kewl;
	lists[1] = &kewl2;
	lists[2] = &kewl3;
	lists[3] = &kewl4;

	int lengths[] = { 2,4,3,1 };

	for (int i = 0; i < 4; i++)
	{
		printf("%d\n", lists[i][0]);
	}

	int* smallest_list = SmallestList(lists, 4, lengths);
	printf("%d\n", smallest_list[0]);
	*/

	return 0;
}