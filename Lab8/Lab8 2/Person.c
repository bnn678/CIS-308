#include "Person.h"
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

Person* new_Person(const char* const pFirstName, const char* const pLastName)
{
	Person* pObj = NULL;

	pObj = (Person*)malloc(sizeof(Person));
	if (pObj == NULL)
	{
		return NULL;
	}
	pObj->pDeriveObj = NULL;

	pObj->pFirstName = malloc(sizeof(char)*(strlen(pFirstName) + 1));
	if (pObj->pFirstName == NULL)
	{
		return NULL;
	}
	strcpy(pObj->pFirstName, pFirstName);

	pObj->pLastName = malloc(sizeof(char)*(strlen(pLastName) + 1));
	if (pObj->pLastName == NULL)
	{
		return NULL;
	}
	strcpy(pObj->pLastName, pLastName);

	pObj->Delete = delete_Person;
	pObj->Display = Person_DisplayInfo;
	pObj->WriteToFile = Person_WriteToFile;

	return pObj;
}

void delete_Person(Person* const pPersonObj)
{

}

void Person_DisplayInfo(Person* const pPersonObj)
{

}

void Person_WriteToFile(Person* const pPersonObj, const char* const pFileName)
{

}