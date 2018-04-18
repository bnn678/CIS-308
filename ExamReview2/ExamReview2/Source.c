#include <stdio.h>
#include <stdlib.h>

// MACROS
#define MULTIPLY(x,y) ((x)*(y))
#define BAD(x,y) (x*y)
#define MIN(x, y) ((x) < (y) ? (x) : (y))

// Conditional Compilation
#ifndef PrintIfWorked
#include "header.h"
#endif

// Function Pointers
int Sum(int a, int b)
{
	return a + b;
}

int main()
{
	// MACROS
	printf("%d %d\n", MULTIPLY(3+1, 4+1), BAD(3+1, 4+1));
	printf("%d\n", MIN(3, 4));
	
	// Conditional Compilation
	PrintIfWorked();

	// Pointers & Dynamic Memory
	int i = 0;
	int* ip = &i;
	int** ipp = &ip;

	// Linked Lists

	// Pointers-to-Pointers

	// Function Pointers
	int(*fp)();
	fp = Sum;

	int sum = (*fp)(10, 5);
	printf("%d\n", sum);

	// Memory Allocation Strategies


	return 0;
}