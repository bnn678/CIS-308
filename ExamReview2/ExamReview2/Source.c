#include <stdio.h>
#include <stdlib.h>

// MACROS
#define MULTIPLY(x,y) ((x)*(y))
#define BAD(x,y) (x*y)
#define MIN(x, y) ((x) < (y) ? (x) : (y))

#ifdef MYEXAMPLE
#include 
#endif

// Conditional Compilation

int main()
{
	// MACROS
	printf("%d %d\n", MULTIPLY(3+1, 4+1), BAD(3+1, 4+1));
	printf("%d\n", MIN(3, 4));

	// Pointers & Dynamic Memory

	// Linked Lists

	// Pointers-to-Pointers

	// Function Pointers

	// Memory Allocation Strategies


	return 0;
}