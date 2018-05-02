/***********************************************************************
* Name: Brandon Shaver
* Date: 2/25/2018
* Assignment: Project 2 - Sequence and Order validation
************************************************************************
* The program is designed to create a BST based on user input.
* It takes in numbers to add to BST.
* The user can test if a nod is in the BST or
* print an Inorder Traversal of the BST.
***********************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char* GetString(char* output);

int GetProgramState();

int GetInsertionNum();

int GetSearchNum();

int GetRemoveNum();

void DisplaySearchResult(bool success, int num);

void DisplayTraversalString(char* traversal_string);