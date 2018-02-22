#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_STRING_LENGTH 35
#pragma warning(disable: 4996)

enum kindOfPerson { kid, student, adult };

typedef struct person {
	char name[20];
	int age;	
	enum KindOfPerson kindOfPerson;

	union {
		struct {
			char school[DEFAULT_STRING_LENGTH];
		} kid;
		struct {
			char college[DEFAULT_STRING_LENGTH];
			double gpa;
		} student;
		struct {
			char company[DEFAULT_STRING_LENGTH];
			double salary;
		} employee;
	} kind;
};

void DisplayPerson(struct person p)
{
	printf("Name: %s\n", p.name);
	printf("Age: %d\n", p.age);

	if (p.kindOfPerson == kid)
		printf("School: %s\n", p.kind.kid.school);

	else if (p.kindOfPerson == student)
	{
		printf("College: %s\n", p.kind.student.college);
		printf("GPA: %f\n", p.kind.student.gpa);
	}

	else if (p.kindOfPerson == adult)
	{
		printf("Company: %s\n", p.kind.employee.company);
		printf("Salary: %f\n", p.kind.employee.salary);
	}

	printf("\n");
}

int main()
{
	struct person p1 = { .age = 20, .kind.student.gpa = 3.5, .kindOfPerson = student };
	strcpy(p1.name, "Bob");
	strcpy(p1.kind.student.college, "K-State");

	struct person* p2 = malloc(sizeof(struct person));
	strcpy(p2->name, "Alison");
	p2->age = 10;
	p2->kindOfPerson = kid;
	strcpy(p2->kind.kid.school, "Amanda Arnold Elementary");

	DisplayPerson(p1);
	DisplayPerson(*p2);

	free(p2);
}