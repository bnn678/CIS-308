#include <stdio.h>
#include "Person.h"
#include "Employee.h"

#pragma warning(disable:4996)

// What separtes OOP from Imperative if we can simulate both using any language?

int main(int argc, const char* argv[])
{
	Person* PersonObj = new_Person("Alice", "Sun");
	Employee* EmployeeObj = new_Employee("Bob", "Smith", "HR", "TCS", 40000);

	// accessing person object

	// displaying person info
	PersonObj->Display(PersonObj);
	//writing person info in the persondata.txt file
	PersonObj->WriteToFile(PersonObj, "persondata.txt");
	// calling deconstructor
	PersonObj->Delete(PersonObj);

	// accessing employee object

	// displaying employee info
	EmployeeObj->Display(EmployeeObj);
	// writiing employee info in the employeedata.txt file
	EmployeeObj->WriteToFile(EmployeeObj, "employeedata.txt");
	// calling deconstructor
	EmployeeObj->Delete(EmployeeObj);

	return 0;
}