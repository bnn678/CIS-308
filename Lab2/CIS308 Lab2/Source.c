#include <stdio.h>
#include <string.h>

int Repeat_Characters(char* name)
{
	int i, j = 0;

	for (int i = 0; i < strlen(name); i++)
	{
		for (j = i + 1; j < strlen(name); j++)
		{
			if(name[i] == name[j])
				return 1;
		}
	}

	return 0;
}

void Reset_String(char* name)
{
	for (int i = 0; i < strlen(name); i++)
	{
		name[i] = 0;
	}
}

int main()
{
	FILE *names_file = fopen("names.txt", "r");
	char name[20];
	int has_repeats = 0;
	
	for (int i = 0; i < 5; i++)
	{
		Reset_String(name);
		fgets(name, 19, names_file);
		has_repeats = Repeat_Characters(name);
		printf("Hello %s", name);
		
		if (has_repeats == 1)
		{
			printf("Repeats found.\n");
		}
		else if (has_repeats == 0)
		{
			printf("Repeats not found.\n");
		}
	}
	
	fclose(names_file);
}