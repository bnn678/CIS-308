/**
	Square.- This class will be derived from Shape and add the 
		appropriate attributes and provide the implementation for Area and Perimeter. 
		It will also implement the constructor Shape* New_Square()
*/

typedef void(*fptrArea)(int);
typedef void(*fptrPerimeter)(int);

typedef struct _Square
{
	int length;

	fptrArea Area;
	fptrPerimeter Perimeter;
} Square;

Square* new_Square(int length);

int get_Area(length);

int get_Perimeter(length);