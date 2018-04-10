#include <stdio.h>
#include <string.h>

#define LENGTH(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

#pragma warning(disable:4996)

int** ReadLists(FILE* fp, int* a, int** b)
{
	char buffer[100];

	(*a) = atoi(fgets(buffer, 100, (FILE*)fp));
	int **lists = (int **)calloc((*a) * sizeof(int *));

	char* pch;

	for (int i = 0; i < (*a); i++)
	{
		fgets(buffer, 100, (FILE*)fp);

		pch = strtok(buffer, ":");
		*(b + i) = calloc(sizeof(int*));
		(*(*b + i)) = atoi(pch);

		pch = strtok(NULL, ":");
		lists[i] = (int *)calloc((*(*b + i)) * sizeof(int));

		int c = 0;
		for (int j = 0; j < (*(*b + i)) - 1; j++)
		{
			if (j == 0)
				c = atoi(strtok(pch, ","));
			else
				c = atoi(strtok(NULL, ","));
			lists[i][j] = c;
		}

		// FOR DEBUGGING
		//for (int j = 0; j < b; j++)
		//{
		//	printf("%d\n", lists[i][j]);
		//}
	}

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
	int** sorted_lists = (int **)calloc((*a) * sizeof(int *));

	for (int i = 0; i < (*a); i++)
	{
		b2[i] = (int*)calloc(sizeof(int*));
	}

	int current_min = 100; int last_min = -1;
	int* smallest_array = 0;
	for (int i = 0; i < (*a); i++)
	{
		for (int j = 0; j < (*a); j++)
		{
			printf("%d ", *(b1[j]));
			/*
			if (b1[j] < current_min)
			{
				current_min = b1[j];
			}

			b2[i] = current_min;
			*/
		}
	}

	return lists;
}

void SortSecondDimension(int** lists)
{

}

int main()
{
	FILE *fp = fopen("list.txt", "r");
	int* a = calloc(sizeof(int*));
	int** b1 = calloc(sizeof(int**));
	int** lists = ReadLists(fp, a, b1);

	PrintLists(lists, a, b1);

	int** b2 = calloc(sizeof(int**));
	int** sorted_lists = SortFirstDimension(lists, a, b1, b2);

	printf("%d", *(b1[1]));

	for (int i = 0; i < 3; i++)
	{
		printf("\n%d", *(b2[i]));
	}
	
	//PrintLists(lists, a, b2);
}