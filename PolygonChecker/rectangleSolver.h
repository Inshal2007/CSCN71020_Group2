#pragma once 

// Rectangle analysis function declarations
char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
void getRectanglePoints(int* xCoords, int* yCoords);

// Corner detection algorithm structures and functions
typedef struct {
    int x;
    int y;
} Point;

void sortPointsByCorner(Point points[]);
void displaySortedPoints(Point points[]);

// Rectangle validation and calculation functions
bool isRectangle(Point points[]);
double calculateQuadrilateralPerimeter(Point points[]);
double calculateRectangleArea(Point points[]);
double calculateAngle(Point p1, Point p2, Point p3);
bool areLinesParallel(Point line1Start, Point line1End, Point line2Start, Point line2End);
double calculateDistance(Point p1, Point p2);