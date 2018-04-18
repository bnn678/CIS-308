// EXAMPLE Swap CALL
/**
int* x = calloc(1, sizeof(int)); int* y = calloc(1, sizeof(int));
int a = 2; int b = 4;
x = &a; y = &b;
Swap(x, y);
printf("\n%d %d\n", a, b);
*/

// EXAMPLE BubbleSort CALL
/**
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

// EXAMPLE GetOrderedIndexes CALL
/**
int** lists = calloc(4, sizeof(int*));

int kewl[] = { 1,2 };
int kewl2[] = { 2,3,5,7 };
int kewl3[] = { 3,3,4 };
int kewl4[] = { 4 };

lists[0] = kewl;
lists[1] = kewl2;
lists[2] = kewl3;
lists[3] = kewl4;

int lengths[] = { 2,4,3,1 };

DisplayLists(lists, 4, lengths);

int* smallest_list = GetOrderedIndexes(4, lengths);

for (int i = 0; i < 4; i++)
{
printf("%d ", smallest_list[i]);
}
*/

// EXAMPLE DisplayLists CALL
/**
int** lists = calloc(4, sizeof(int*));
int lengths[] = { 1, 2, 3, 4 };
for (int i = 0; i < 4; i++)
{
*(lists + i) = calloc(lengths[i], sizeof(int));

for (int j = 0; j < lengths[i]; j++)
{
lists[i][j] = j;
}
}

for (int i = 0; i < 4; i++)
{
for (int j = 0; j < lengths[i]; j++)
{
printf("%d ", lists[i][j]);
}
printf("\n");
}

DisplayLists(lists, 4, lengths);
*/

// EXAMPLE SortedLists CALL
/**
int** lists = calloc(4, sizeof(int*));

int something[] = { 1,2,3 };
int something2[] = { 1,2 };
int something3[] = { 1,4,6,5 };
int something4[] = { 8 };

lists[0] = &something;
lists[1] = &something2;
lists[2] = &something3;
lists[3] = &something4;

int lengths[] = { 3, 2, 4, 1 };

DisplayLists(lists, 4, lengths);
printf("\n");

// ordered indexes
int* ordered_indexes = GetOrderedIndexes(4, lengths);
for (int i = 0; i < 4; i++)
{
printf("%d ", ordered_indexes[i]);
}
printf("\n\n");

// ordered lengths
int* ordered_lengths = GetOrderedLengths(4, lengths, ordered_indexes);
for (int i = 0; i < 4; i++)
{
printf("%d ", ordered_lengths[i]);
}
printf("\n\n");

// sorted lists
int** sorted_lists = SortedLists(lists, 4, ordered_indexes);
printf("\n");

DisplayLists(sorted_lists, 4, ordered_lengths);
*/

// EXAMPLE ReadLists CALL
/**
FILE *fp = fopen("list.txt", "r");
int elements = ReadElements(fp);
int* lengths = calloc(elements, sizeof(int));
int** lists = calloc(elements, sizeof(int*));

ReadLists(fp, elements, lengths, lists);

// Check lengths
for (int i = 0; i < elements; i++)
{
printf("%d ", lengths[i]);
}
printf("\n");

// Check lists
DisplayLists(lists, elements, lengths);
*/