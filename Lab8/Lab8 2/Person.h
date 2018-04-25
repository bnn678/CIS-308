#pragma once

typedef struct _Person Person;

// declaration of pointers to functions
typedef void(*fptrDisplayInfo)(Person*);
typedef void(*fptrWriteToFile)(Person*, const char*);
typedef void(*fptrDelete)(Person*);

typedef struct _Person
{
	void* pDeriveObj;
	char* pFirstName;
	char* pLastName;
	// interface for function
	fptrDisplayInfo Display;
	fptrWriteToFile WriteToFile;
	fptrDelete Delete;
} Person;

Person* new_Person(const char* const pFirstName, const char* const pLastName);

void delete_Person(Person* const pPersonObj);

void Person_DisplayInfo(Person* const pPersonObj);

void Person_WriteToFile(Person* const pPersonObj, const char* const pFileName);