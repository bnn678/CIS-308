#include "io.h"
#include "bst.h"

enum PROGRAM_STATE { QUIT, INSERT, SEARCH, TRAVERSE, REMOVE };

// MAIN CONTROLLER:
int main()
{
	// Varibles:
	enum PROGRAM_STATE program_state;
	BST_Node* head_node = (BST_Node*)calloc(1, sizeof(BST_Node));
	int num;

	// Controller Loop:
	while (true)
	{
		num = 0;
		program_state = GetProgramState();

		if (program_state == QUIT)
		{
			FreeBST(head_node);
			return 0;
		}
		else if (program_state == INSERT)
		{
			num = GetInsertionNum();
			AddNode(head_node, num);
		}
		else if (program_state == SEARCH)
		{
			num = GetSearchNum();
			DisplaySearchResult(Search(*head_node, num), num);
		}
		else if (program_state == TRAVERSE)
		{
			char* traversal_string = (char *)calloc(100, sizeof(char));

			InorderTraversal(*head_node, traversal_string);
			DisplayTraversalString(traversal_string);

			free(traversal_string);
		}
		else if (program_state == REMOVE)
		{
			num = GetRemoveNum();
			head_node = RemoveNode(head_node, num);

			if (head_node == 0)
			{
				head_node = (BST_Node*)calloc(1, sizeof(BST_Node));
			}
		}
	}
}