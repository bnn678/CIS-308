#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

int main()
{
	int* nums;
	int i, length;

	printf("Enter size of array: ");
	scanf_s("%d", &length, sizeof(int));

	nums = malloc(length * sizeof(int));
	for (int i = 0; i < length; i++)
	{
		printf("Enter a number: ");
		scanf_s("%d", nums + i, sizeof(nums + i));
	}

	printf("The min is : %d\n", Min(nums, length));
	printf("The max is : %d\n", Max(nums, length));
	printf("THe average is : %.2lf\n", avg(nums, length));

	return 0;
}

