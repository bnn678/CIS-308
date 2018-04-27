#include <stdlib.h>

#include "Shape.h"

Shape* New_Shape()
{
	Shape* squareObj = 0;
	squareObj = (Shape*)malloc(sizeof(Shape));
	return squareObj;
}