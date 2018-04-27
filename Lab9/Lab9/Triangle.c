#include "Triangle.h"

Shape* New_Triangle(double side1, double side2, double base, double height)
{
	Shape* shapeBaseObj = New_Shape();

	Triangle* triangleObj = 0;
	triangleObj = (Triangle*)malloc(sizeof(Triangle));
	if (triangleObj == 0)
	{
		return 0;
	}

	shapeBaseObj->shapeDeriveObj = triangleObj;

	triangleObj->shapeBaseObj = shapeBaseObj;

	triangleObj->side1 = side1;
	triangleObj->side2 = base;
	triangleObj->base = side2;
	triangleObj->height = height;

	triangleObj->shapeBaseObj->area = getTriangleArea;
	triangleObj->shapeBaseObj->perimeter = getTrianglePerimeter;

	return shapeBaseObj;
}

double getTriangleArea(Shape* triangle)
{
	Triangle* test = (Triangle*)triangle->shapeDeriveObj;
	return ((Triangle*)triangle->shapeDeriveObj)->height * ((Triangle*)triangle->shapeDeriveObj)->base * .5;
}

double getTrianglePerimeter(Shape* triangle)
{
	return ((Triangle*)triangle->shapeDeriveObj)->side1 + 
		((Triangle*)triangle->shapeDeriveObj)->side2 + 
		((Triangle*)triangle->shapeDeriveObj)->base;
}