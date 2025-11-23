#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a Triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

void calculateTriangleAngles(int side1, int side2, int side3, double* angle1, double* angle2, double* angle3) {
	// Calculate angles using Law of Cosines

	// Angle A (opposite side a)
	*angle1 = acos((side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3)) * (180.0 / 3.14159265358979323846);

	// Angle B (opposite side b)  
	*angle2 = acos((side1 * side1 + side3 * side3 - side2 * side2) / (2.0 * side1 * side3)) * (180.0 / 3.14159265358979323846);

	// Angle C (opposite side c)
	*angle3 = 180.0 - (*angle1 + *angle2);
}

char* classifyTriangleByAngles(double angle1, double angle2, double angle3) {
	
	// Check for right-angled triangle (one angle exactly 90 degrees)
	if (fabs(angle1 - 90.0) < 1.0 || fabs(angle2 - 90.0) < 1.0 || fabs(angle3 - 90.0) < 1.0) {
		return "Right-angled";
	}
	
	// Check for obtuse triangle (one angle greater than 90 degrees)
	else if (angle1 > 90.0 || angle2 > 90.0 || angle3 > 90.0) {
		return "Obtuse";
	}
	
	// Otherwise it's acute (all angles less than 90 degrees)
	else {
		return "Acute";
	}
}