#include "Square.h"

Square* new_Square(int length)
{
	Square* squareObj = 0;

	squareObj = (Square*)malloc(sizeof(Square));
	if (squareObj == 0)
	{
		return 0;
	}

	squareObj->Area = get_Area;
	squareObj->Perimeter = get_Perimeter;
}

int get_Area(length)
{
	return length * length;
}

int get_Perimeter(length)
{
	return 4 * length;
}