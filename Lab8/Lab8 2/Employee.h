#include <stdio.h>
#include "Person.h"

#pragma once

typedef struct _Employee
{
	Person* pBaseObj;
	char* pDepartment;
	char* pCompany;
	int nSalary;
	// If there is any employee specific functions; add interface here.
} Employee;

Person* new_Employee(const char* const pFirstName, const char* const pLastName, const char* const pDepartment, const char* const pCompany, int nSalary);

void delete_Employee(Person* const pPersonObj);

void Employee_DisplayInfo(Person* const pPersonObj);

void Employee_WriteToFile(Person* const pPersonObj, const char* const pFileName);