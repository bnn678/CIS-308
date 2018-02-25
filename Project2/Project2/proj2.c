#include "io.h"
#include "bst.h"

enum PROGRAM_STATE { QUIT, INSERT, SEARCH, TRAVERSE};

int main()
{
	// Varibles:
	enum PROGRAM_STATE program_state;
	//Node head_node = Node_default; // doesn't work. C sucks?
	int insertion_num;

	// Controller Loop:
	while (true)
	{
		program_state = GetProgramState();

		

		if (program_state == QUIT)
		{
			return 0;
		}
		else if (program_state == INSERT)
		{
			insertion_num = GetInsertionNum();

		}
	}
}