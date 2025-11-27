#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"

char* analyzeTriangle(double side1, double side2, double side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a Triangle";
	}
	// Check triangle inequality theorem
	else if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
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

void calculateTriangleAngles(double side1, double side2, double side3, double* angle1, double* angle2, double* angle3) {
	
	// Calculate angles using Law of Cosines with safety checks

	//9.4732;
	//12.43;
	//4.2;

	//0.7892137088
	//-0.5921891652

	double a = side1, b = side2, c = side3;

	// Ensure values are within valid range for acos() function
	double cosA = (b * b + c * c - a * a) / (2.0 * b * c);
	double cosB = (a * a + c * c - b * b) / (2.0 * a * c);

	// Clamp values to avoid floating point errors
	if (cosA > 1.0) cosA = 1.0;
	if (cosA < -1.0) cosA = -1.0;
	if (cosB > 1.0) cosB = 1.0;
	if (cosB < -1.0) cosB = -1.0;
	
	// Calculate angles using Law of Cosines

	// Angle A (opposite side a)
	*angle1 = acos(cosA) * (180.0 / 3.14159265358979323846);

	// Angle B (opposite side b)  
	*angle2 = acos(cosB) * (180.0 / 3.14159265358979323846);

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