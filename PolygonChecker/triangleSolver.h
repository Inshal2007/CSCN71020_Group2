#pragma once

char* analyzeTriangle(double side1, double side2, double side3);
void calculateTriangleAngles(double side1, double side2, double side3, double* angle1, double* angle2, double* angle3);
char* classifyTriangleByAngles(double angle1, double angle2, double angle3);