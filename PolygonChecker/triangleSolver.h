#pragma once
char* analyzeTriangle(int side1, int side2, int side3);
void calculateTriangleAngles(int side1, int side2, int side3, double* angle1, double* angle2, double* angle3);
char* classifyTriangleByAngles(double angle1, double angle2, double angle3);