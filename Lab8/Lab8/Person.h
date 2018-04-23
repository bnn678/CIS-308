typedef struct _Person Person;

// declaration of pointers to functions
typedef void(*fptrDisplayInfo)(Person*);
typedef void(*fptrWriteToFile)(Person*, const char*);
typedef void(*fptrDelete)(Person*);

typedef struct _Person
{
	char* pFirstName;
	char* pLastName;
	// interface for function
	fptrDisplayInfo Display;
	fptrWriteToFile WriteToFile;
	fptrDelete Delete;
} Person;