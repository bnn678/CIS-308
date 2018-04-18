#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int* list, int length)
{
	int* x; int* y;

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

void DisplayLists(int** lists, int elements, int* lengths)
{
	printf("%d Lists: \n", elements);
	for (int i = 0; i < elements; i++)
	{
		for (int j = 0; j < lengths[i]; j++)
		{
			printf("%d, ", lists[i][j]);
		}
		printf("\n");
	}
}

int* GetOrderedIndexes(int elements, int lengths[])
{
	int* ordered_indexes = calloc(elements, sizeof(int));

	int last_min = -1;
	int current_min;
	int current_min_index;

	for (int i = 0; i < elements; i++)
	{
		current_min = 1000; // arbitartily large value
		for (int j = 0; j < elements; j++)
		{
			if (last_min < lengths[j] && lengths[j] < current_min)
			{
				current_min = lengths[j];
				current_min_index = j;
			}
		}
		ordered_indexes[i] = current_min_index;
		last_min = current_min;
	}

	return ordered_indexes;
}

int* GetOrderedLengths(int elements, int lengths[], int ordered_indexes[])
{
	int* ordered_lengths = calloc(elements, sizeof(int));

	for (int i = 0; i < elements; i++)
	{
		ordered_lengths[i] = lengths[ordered_indexes[i]];
	}

	return ordered_lengths;
}

int** SortedLists(int** lists, int elements, int* ordered_indexes)
{
	int** sorted_lists = calloc(elements, sizeof(int*));

	for (int i = 0; i < elements; i++)
	{
		sorted_lists[i] = lists[ordered_indexes[i]];
	}

	return sorted_lists;
}

int ReadElements(FILE* fp)
{
	char buffer[100];
	int elements = atoi(fgets(buffer, 100, (FILE*)fp)); // Read number of lists (i.e. elements)

	return elements;
}

void ReadLists(FILE* fp, int elements, int* lengths, int** lists)
{
	char buffer[100];
	char* pch;

	for (int i = 0; i < elements; i++) // Main Read Loop
	{
		fgets(buffer, 100, (FILE*)fp); // Get 1 line

		pch = strtok(buffer, ":"); // Read and Parse length
		lengths[i] = atoi(pch);

		pch = strtok(NULL, ":"); // Read the rest of the line

		lists[i] = calloc(lengths[i], sizeof(int)); // Allocate lists[i]
		
		int c = 0;
		for (int j = 0; j < lengths[i]; j++) // Populate lists[i]
		{
			if (j == 0)
				c = atoi(strtok(pch, ",\n"));
			else
				c = atoi(strtok(NULL, ",\n"));

			lists[i][j] = c;
		}
		
	}

	return lists;
}

int main(int argc, char* argv)
{
	FILE* fp;
	if (argc == 1)
	{
		fp = fopen(argv[0], "r");
	}
	else
	{
		fp = fopen("list.txt", "r");
	}

	int elements = ReadElements(fp);
	int* lengths = calloc(elements, sizeof(int));
	int** lists = calloc(elements, sizeof(int*));

	ReadLists(fp, elements, lengths, lists);

	int* ordered_indexes = GetOrderedIndexes(elements, lengths);
	int* ordered_lengths = GetOrderedLengths(elements, lengths, ordered_indexes);
	
	int** sorted_lists = SortedLists(lists, elements, ordered_indexes);

	for (int i = 0; i < elements; i++)
	{
		BubbleSort(sorted_lists[i], ordered_lengths[i]);
	}

	DisplayLists(sorted_lists, elements, ordered_lengths);


	// Free Stuff
	free(lengths);
	free(ordered_indexes);
	free(ordered_lengths);
	for (int i = 0; i < elements; i++)
	{
		free(lists[i]);
	}
	free(lists);
	free(sorted_lists);
	
	return 0;
}