#include "Shape.h"
#include "Square.h"
#include "Triangle.h"

#include <stdio.h>

int main() {
	/**
	double area = 0.0;

	double perim = 0.0;

	Shape* mySquare = New_Square(3);

	Shape* myTriangle = New_Triangle(3, 4, 5, 2);



	area = mySquare->area(mySquare);

	printf("The area of the Square is: %f\n", area);

	perim = mySquare->perimeter(mySquare);

	printf("The perimeter of the Square is: %f\n", perim);



	area = myTriangle->area(myTriangle);

	printf("The area of the Triangle is: %f\n", area);

	perim = myTriangle->perimeter(myTriangle);

	printf("The perimeter of the Triangle is: %f\n", perim);
	*/

	Square* mySquare = new_Square(4);
	int length = mySquare->length;
	printf("%d\n", mySquare->Area(length));
	printf("%d\n", mySquare->Perimeter(length));

	return 0;
}