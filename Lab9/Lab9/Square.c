#pragma once

#include "Square.h"

Shape* New_Square(double length)
{
	Shape* shapeBaseObj = New_Shape();

	Square* squareObj = 0;
	squareObj = (Square*)malloc(sizeof(Square));
	if (squareObj == 0)
	{
		return 0;
	}

	shapeBaseObj->shapeDeriveObj = squareObj;

	squareObj->shapeBaseObj = shapeBaseObj;

	squareObj->length = length;

	squareObj->shapeBaseObj->area = getSquareArea;
	squareObj->shapeBaseObj->perimeter = getSquarePerimeter;

	return shapeBaseObj;
}

double getSquareArea(Shape* square)
{
	return ((Square*)square->shapeDeriveObj)->length * ((Square*)square->shapeDeriveObj)->length;
}

double getSquarePerimeter(Shape* square)
{
	return 4 * ((Square*)square->shapeDeriveObj)->length;
}