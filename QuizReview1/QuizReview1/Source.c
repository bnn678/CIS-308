#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int* points = calloc(10, sizeof(double));

	points[9] = 12;
	printf("%d\n", points[0]);
	printf("%d\n", points[9]);
	printf("%d\n", points[10]);

	printf("\n\n");

	double nums[] = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };

	printf("%lf\n", *nums);
	printf("%lf\n", *(nums+2));
	double* ptr = nums + 5;  printf("%lf\n", *ptr);
	printf("---%d\n", nums + 5);
	printf("%d\n", ptr);

	printf("\n\n");

	struct student {
		char* name;
		char grades[4];
	};

	struct student* sPtr;

	struct student s;
	char* name = "Laura";
	printf("%s\n", name);
	printf("%d\n", &name);
	s.name = name;
	printf("%s\n", s.name);

	s.grades[0] = 'A';
	s.grades[1] = 'C';
	s.grades[2] = 'A';
	s.grades[3] = '\0';

	sPtr = &s;

	printf("%s\n", sPtr->name);
	printf("%s\n", sPtr->grades);

	return 0;
}