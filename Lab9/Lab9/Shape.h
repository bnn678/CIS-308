/**

	Shape.- This will be the base class, it will define the methods Area(Shape*) 
		and Perimeter(Shape*). It will also implement the constructor Shape* New_Shape()

*/

#pragma once

typedef struct _Shape Shape;

typedef double(*fptrArea)(Shape*);
typedef double(*fptrPerimeter)(Shape*);

typedef struct _Shape
{
	void* shapeDeriveObj;

	fptrArea area;
	fptrPerimeter perimeter;
} Shape;

Shape* New_Shape();