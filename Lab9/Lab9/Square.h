/**
	Square.- This class will be derived from Shape and add the 
		appropriate attributes and provide the implementation for Area and Perimeter. 
		It will also implement the constructor Shape* New_Square()
*/

#include "Shape.h"

typedef struct _Square
{
	Shape* shapeBaseObj;
	double length;
} Square;

Shape* New_Square(double);

double getSquareArea(Shape*);

double getSquarePerimeter(Shape*);