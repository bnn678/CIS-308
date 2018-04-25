#include <stdio.h>
#include "Person.h"

#pragma once

typedef struct _Employee Employee;

// declaration of pointers to functions
typedef void(*fptrDisplayInfo)(Employee*);
typedef void(*fptrWriteToFile)(Employee*, const char*);
typedef void(*fptrDelete)(Employee*);

typedef struct _Employee
{
	Person* pBaseObj;
	char* pDepartment;
	char* pCompany;
	int nSalary;
	// If there is any employee specific functions; add interface here.
	fptrDisplayInfo Display;
	fptrWriteToFile WriteToFile;
	fptrDelete Delete;
} Employee;

Employee* new_Employee(const char* const pFirstName, const char* const pLastName, const char* const pDepartment, const char* const pCompany, int nSalary);

void delete_Employee(Person* const pPersonObj);

void Employee_DisplayInfo(Person* const pPersonObj);

void Employee_WriteToFile(Person* const pPersonObj, const char* const pFileName);