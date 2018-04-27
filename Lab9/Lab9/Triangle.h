/**
	Triangle.- This class will be derived from Shape and add the appropriate attributes 
		and provide the implementation for Area and Perimeter. 
		It will also implement the constructor Shape* New_Triangle()
*/

#include "Shape.h"

typedef struct _Triangle
{
	Shape* shapeBaseObj;

	double base;
	double height;

	double side1;
	double side2;
} Triangle;

Shape* New_Triangle(double, double, double, double);

double getTriangleArea(Shape*);

double getTrianglePerimeter(Shape*);