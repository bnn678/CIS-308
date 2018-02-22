#include <stdio.h>
#include <string.h>

void To_Uppercase(char* string)
{
	if (*string)
	{
		if (string[0] >= 97 && string[0] <= 122)
			string[0] -= 32;
		To_Uppercase(string + 1);
	}
	else
		return;
}

void Reverse_String(char* string)
{
	if (*string)
	{
		Reverse_String(string + 1);
		printf("%c", *string);
	}
	else
		return;
}

int main()
{
	char name1[] = "John Smith";
	char name2[] = "Mary Cohen";
	char name3[] = "Carl Williams";

	char names[4][20] = { 0 };
	strcpy(names[0], name1);
	strcpy(names[1], name2);
	strcpy(names[2], name3);

	for (int i = 0; i < 4; i++)
	{
		To_Uppercase(names[i]);
		Reverse_String(names[i]);
		printf("\n");
	}

	return 0;
}