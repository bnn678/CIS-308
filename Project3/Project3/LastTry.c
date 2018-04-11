/*



#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

int** ReadLists(FILE* fp, int* a, int** b)
{
	char buffer[100];

	(*a) = atoi(fgets(buffer, 100, (FILE*)fp)); // Read number of lists
	int** lists = calloc(sizeof(int**)); // Allocate lists

	char* pch;

	for (int i = 0; i < (*a); i++) // Main Read Loop
	{
		fgets(buffer, 100, (FILE*)fp); // Get 1 line

		pch = strtok(buffer, ":"); // Read and Parse b
		*(b + i) = calloc(sizeof(int*));
		(*(*b + i)) = atoi(pch);

		pch = strtok(NULL, ":"); // Read the rest of the line

		lists[i] = calloc(sizeof(int*)); // Allocate lists[i]

		int c = 0;
		for (int j = 0; j < (*(*b + i)); j++) // Populate lists[i]
		{
			if (j == 0)
				c = atoi(strtok(pch, ",\n"));
			else
				c = atoi(strtok(NULL, ",\n"));
			lists[i][j] = calloc(sizeof(int));
			lists[i][j] = c;
		}
	}

	//free(pch);
	//free(buffer);

	return lists;
}

void PrintLists(int** lists, int* a, int** b)
{
	printf("%d Lists\n", *a);

	for (int i = 0; i < (*a); i++)
	{
		for (int j = 0; j < (*(*b + i)); j++)
		{
			printf("%d ", lists[i][j]);
		}
		printf("\n");
	}
}

int** SortFirstDimension(int** lists, int* a, int** b1, int** b2)
{
	int** sorted_lists = (int **)calloc((*a) * sizeof(int *)); // allocate sorted_lists

	for (int i = 0; i < (*a); i++) // allocate b2
	{
		b2[i] = (int*)calloc(sizeof(int*));
	}

	int current_min = 100; int last_min = -1; int pos_in_list = -1; int* smallest_array = 0; // Varibles for Sorting
	for (int i = 0; i < (*a); i++) // Sorting Loop
	{
		for (int j = 0; j < (*a); j++) // Find Next Smallest Array
		{
			if (current_min >(*b1)[j] && (*b1)[j] > last_min)
			{
				current_min = (*b1)[j];
				pos_in_list = j;
			}
		}

		sorted_lists[i] = calloc(sizeof(int*)); // Allocate sorted_lists[i]
		for (int j = 0; j < current_min; j++) // Populate sorted_lists[i]
		{
			sorted_lists[i][j] = calloc(sizeof(int));
			//printf("%d %d %d\n", pos_in_list, j, lists[pos_in_list][j]);
			sorted_lists[i][j] = lists[pos_in_list][j];
		}

		(*b2)[i] = current_min; // Update Sorting Varibles
		last_min = current_min;
		current_min = 100;
	}

	return lists;
}

void SortSecondDimension(int** lists)
{

}

void Swap(int* a, int* b)
{
	int temp = *a;
	a = &b;
	*b = a;
}

int main()
{
	FILE *fp = fopen("list.txt", "r");
	int* a = calloc(sizeof(int*));
	int** b1 = calloc(sizeof(int**));
	int** lists = ReadLists(fp, a, b1);

	PrintLists(lists, a, b1);
	printf("\n\n");

	int** b2 = calloc(sizeof(int**));
	int** sorted_lists = SortFirstDimension(lists, a, b1, b2);

	int* a; int* b;
	*a = 2; *b = 3;
	Swap(a, b);
	printf("%d %d", a, b);

	PrintLists(lists, a, b2);
}

*/