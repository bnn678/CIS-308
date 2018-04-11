<<<<<<< HEAD
#include <stdio.h>
=======
>>>>>>> ed95b82cfbaa8a0e95c829fb3bc0420e31949e86
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
	int i = 0;
	int* ip = &i;
	int** ipp = &ip;

	// Linked Lists

	// Pointers-to-Pointers

	// Function Pointers

	// Memory Allocation Strategies


	return 0;
}