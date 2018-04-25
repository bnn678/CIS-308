#include "Employee.h"
#include "Person.h"
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

Employee* new_Employee(const char* const pFirstName, const char* const pLastName, const char* const pDepartment, const char* const pCompany, int nSalary)
{
	Person* pObj = NULL;

	pObj = new_Person(pFirstName, pLastName);
	if (pObj == NULL)
	{
		return NULL;
	}
	pObj->pDeriveObj = (Employee*)pObj;

	Employee* eObj = NULL;
	eObj = (Employee*)malloc(sizeof(Employee));
	if (eObj == NULL)
	{
		return NULL;
	}

	eObj->pCompany = malloc(sizeof(char) * (strlen(pCompany) + 1));
	if (eObj->pCompany == NULL)
	{
		return NULL;
	}
	strcpy(eObj->pCompany, pCompany);

	eObj->pDepartment = malloc(sizeof(char) * (strlen(pDepartment) + 1));
	if (eObj->pDepartment == NULL)
	{
		return NULL;
	}
	strcpy(eObj->pDepartment, pDepartment);

	eObj->nSalary = malloc(sizeof(int));
	if (eObj->nSalary == NULL)
	{
		return NULL;
	}
	eObj->nSalary = nSalary;

	eObj->pBaseObj = pObj;

	eObj->Delete = delete_Person;
	eObj->Display = Person_DisplayInfo;
	eObj->WriteToFile = Person_WriteToFile;

	return eObj;
}

void delete_Employee(Person* const pPersonObj)
{

}

void Employee_DisplayInfo(Person* const pPersonObj)
{

}

void Employee_WriteToFile(Person* const pPersonObj, const char* const pFileName)
{

}