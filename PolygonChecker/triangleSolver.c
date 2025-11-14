#include <stdio.h>
#include <stdbool.h>

#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "\n It not a Triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "\n It is Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "\n It is Isosceles triangle";
	}
	else {
		result = "\n It isScalene triangle";
	}

	return result;
}