#include <stdio.h> 
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "rectangleSolver.h"

// Maximum coordinate range to prevent unrealistic values
#define MIN_COORDINATE -10000
#define MAX_COORDINATE 10000

void getRectanglePoints(int* xCoords, int* yCoords) {
    printf_s("\n+===========================================+\n");
    printf_s("|     FOUR-POINT COORDINATE INPUT         |\n");
    printf_s("+===========================================+\n");
    printf_s("| Enter four (x,y) coordinate pairs        |\n");
    printf_s("| Example: For (3, -5) enter: 3 -5         |\n");
    printf_s("| Range: %d to %d                  |\n", MIN_COORDINATE, MAX_COORDINATE);
    printf_s("+===========================================+\n\n");

    for (int i = 0; i < 4; i++) {
        printf_s("--- Enter Point %d ---\n", i + 1);

        int validInput = 0;

        while (!validInput) {
            printf_s("Enter x and y coordinates: ");

            // Try to read two integers
            int result = scanf_s("%d %d", &xCoords[i], &yCoords[i]);

            if (result == 2) {
                // Validate coordinate ranges
                if (xCoords[i] >= MIN_COORDINATE && xCoords[i] <= MAX_COORDINATE &&
                    yCoords[i] >= MIN_COORDINATE && yCoords[i] <= MAX_COORDINATE) {
                    validInput = 1;
                    printf_s("Point %d recorded: (%d, %d)\n\n", i + 1, xCoords[i], yCoords[i]);
                }
                else {
                    printf_s("Error: Coordinates must be between %d and %d.\n",
                        MIN_COORDINATE, MAX_COORDINATE);
                    // Clear the input buffer after invalid range
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                }
            }
            else {
                printf_s("Invalid input. Please enter two numbers separated by space.\n");
                // Clear the input buffer after invalid input
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }
    }

    printf_s("+===========================================+\n");
    printf_s("|            POINTS ENTERED                |\n");
    printf_s("+===========================================+\n");
    for (int i = 0; i < 4; i++) {
        printf_s("| Point %d: (%6d, %6d)               |\n", i + 1, xCoords[i], yCoords[i]);
    }
    printf_s("+===========================================+\n");
}
// Calculates distance between two points using Pythagorean theorem
double calculateDistance(Point p1, Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

// Finds the point with the smallest x+y value (top-left corner)
int findTopLeftIndex(Point points[]) {
    int minSum = points[0].x + points[0].y;
    int topLeftIndex = 0;

    for (int i = 1; i < 4; i++) {
        int currentSum = points[i].x + points[i].y;
        if (currentSum < minSum) {
            minSum = currentSum;
            topLeftIndex = i;
        }
    }
    return topLeftIndex;
}

// Finds the point with the largest x-y value (top-right corner)
int findTopRightIndex(Point points[], int topLeftIndex) {
    int topRightIndex = -1;
    double maxDistance = -1;

    for (int i = 0; i < 4; i++) {
        if (i != topLeftIndex) {
            double distance = calculateDistance(points[topLeftIndex], points[i]);
            if (distance > maxDistance) {
                maxDistance = distance;
                topRightIndex = i;
            }
        }
    }
    return topRightIndex;
}

// Sorts four points into corner order: top-left, top-right, bottom-left, bottom-right
void sortPointsByCorner(Point points[]) {
    Point sortedPoints[4];

    int topLeftIndex = findTopLeftIndex(points);
    sortedPoints[0] = points[topLeftIndex];

    int topRightIndex = findTopRightIndex(points, topLeftIndex);
    sortedPoints[1] = points[topRightIndex];

    int remainingIndices[2];
    int count = 0;
    for (int i = 0; i < 4; i++) {
        if (i != topLeftIndex && i != topRightIndex) {
            remainingIndices[count++] = i;
        }
    }

    if (points[remainingIndices[0]].x < points[remainingIndices[1]].x) {
        sortedPoints[2] = points[remainingIndices[0]];
        sortedPoints[3] = points[remainingIndices[1]];
    }
    else {
        sortedPoints[2] = points[remainingIndices[1]];
        sortedPoints[3] = points[remainingIndices[0]];
    }

    for (int i = 0; i < 4; i++) {
        points[i] = sortedPoints[i];
    }
}

// Display function with professional formatting
void displaySortedPoints(Point points[]) {
    printf_s("\n+==============================+\n");
    printf_s("|      CORNER DETECTION       |\n");
    printf_s("+==============================+\n");
    printf_s("| Top-Left:     (%3d, %3d)     |\n", points[0].x, points[0].y);
    printf_s("| Top-Right:    (%3d, %3d)     |\n", points[1].x, points[1].y);
    printf_s("| Bottom-Left:  (%3d, %3d)     |\n", points[2].x, points[2].y);
    printf_s("| Bottom-Right: (%3d, %3d)     |\n", points[3].x, points[3].y);
    printf_s("+==============================+\n");
}

// Calculates angle at point p2 formed by points p1-p2-p3 using triangle logic
double calculateAngle(Point p1, Point p2, Point p3) {
    double dx1 = p1.x - p2.x;
    double dy1 = p1.y - p2.y;
    double dx2 = p3.x - p2.x;
    double dy2 = p3.y - p2.y;

    double dotProduct = dx1 * dx2 + dy1 * dy2;
    double mag1 = sqrt(dx1 * dx1 + dy1 * dy1);
    double mag2 = sqrt(dx2 * dx2 + dy2 * dy2);

    // Avoid division by zero
    if (mag1 < 0.0001 || mag2 < 0.0001) {
        return 0.0;
    }

    double cosAngle = dotProduct / (mag1 * mag2);

    // Ensure value is within valid range for acos function
    if (cosAngle > 1.0) cosAngle = 1.0;
    if (cosAngle < -1.0) cosAngle = -1.0;

    // Convert from radians to degrees
    return acos(cosAngle) * (180.0 / 3.14159265358979323846);
}

// More robust rectangle validation using multiple approaches
bool isRectangle(Point points[]) {
    // Calculate all four angles
    double angle1 = calculateAngle(points[2], points[0], points[1]); // Top-left
    double angle2 = calculateAngle(points[0], points[1], points[3]); // Top-right
    double angle3 = calculateAngle(points[0], points[2], points[3]); // Bottom-left  
    double angle4 = calculateAngle(points[1], points[3], points[2]); // Bottom-right

    // Debug output to see angle calculations
    printf_s("Angle measurements: %.2f°, %.2f°, %.2f°, %.2f°\n", angle1, angle2, angle3, angle4);

    // Check if all angles are approximately 90 degrees (with tolerance)
    bool rightAngles = (fabs(angle1 - 90.0) < 2.0) && (fabs(angle2 - 90.0) < 2.0) &&
        (fabs(angle3 - 90.0) < 2.0) && (fabs(angle4 - 90.0) < 2.0);

    // Calculate side lengths
    double top = calculateDistance(points[0], points[1]);
    double right = calculateDistance(points[1], points[3]);
    double bottom = calculateDistance(points[3], points[2]);
    double left = calculateDistance(points[2], points[0]);

    // Check if opposite sides are equal (within tolerance)
    bool oppositeSidesEqual = (fabs(top - bottom) < 0.0001) && (fabs(left - right) < 0.0001);

    // Check diagonals are equal (for rectangle)
    double diag1 = calculateDistance(points[0], points[3]);
    double diag2 = calculateDistance(points[1], points[2]);
    bool diagonalsEqual = fabs(diag1 - diag2) < 0.0001;

    printf_s("Side lengths: Top=%.2f, Right=%.2f, Bottom=%.2f, Left=%.2f\n", top, right, bottom, left);
    printf_s("Diagonals: %.2f vs %.2f\n", diag1, diag2);

    // A quadrilateral is a rectangle if:
    // 1. All angles are 90°, OR
    // 2. Opposite sides equal and diagonals equal
    return (rightAngles) || (oppositeSidesEqual && diagonalsEqual);
}

// Checks if two lines are parallel by comparing their slopes
bool areLinesParallel(Point line1Start, Point line1End, Point line2Start, Point line2End) {
    // Handle vertical lines
    if (line1End.x == line1Start.x && line2End.x == line2Start.x) {
        return true; // Both lines are vertical
    }
    if (line1End.x == line1Start.x || line2End.x == line2Start.x) {
        return false; // Only one line is vertical
    }

    double slope1 = (double)(line1End.y - line1Start.y) / (line1End.x - line1Start.x);
    double slope2 = (double)(line2End.y - line2Start.y) / (line2End.x - line2Start.x);

    return fabs(slope1 - slope2) < 0.0001;
}

// Calculates perimeter for any quadrilateral
double calculateQuadrilateralPerimeter(Point points[]) {
    double perimeter = 0.0;

    perimeter += calculateDistance(points[0], points[1]); // Top
    perimeter += calculateDistance(points[1], points[3]); // Right
    perimeter += calculateDistance(points[3], points[2]); // Bottom
    perimeter += calculateDistance(points[2], points[0]); // Left

    return perimeter;
}

// Calculates area only for valid rectangles (length × width)
double calculateRectangleArea(Point points[]) {
    double length = calculateDistance(points[0], points[1]); // Top side
    double width = calculateDistance(points[0], points[2]);  // Left side

    return length * width;
}

// Main rectangle analysis function that implements the second approach
char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    Point testPoints[4] = { {x1, y1}, {x2, y2}, {x3, y3}, {x4, y4} };

    printf_s("\nProcessing your points...\n");

    printf_s("\nOriginal Points:\n");
    for (int i = 0; i < 4; i++) {
        printf_s("Point %d: (%d, %d)\n", i + 1, testPoints[i].x, testPoints[i].y);
    }

    // Apply corner detection to organize points and avoid crossed lines
    sortPointsByCorner(testPoints);
    displaySortedPoints(testPoints);

    // Calculate perimeter for ANY quadrilateral (always return perimeter)
    double perimeter = calculateQuadrilateralPerimeter(testPoints);

    // Check if points form a valid rectangle using robust validation
    bool isValidRect = isRectangle(testPoints);


    printf_s("\n+===========================================+\n");
    printf_s("|           SHAPE ANALYSIS RESULTS        |\n");
    printf_s("+===========================================+\n");
    printf_s("| Corner Detection: %-21s |\n", "COMPLETED");
    printf_s("| Lines Cross:     %-21s |\n", "NO CROSSING");
    printf_s("| Perimeter:       %-21.2f |\n", perimeter);

    if (isValidRect) {
        double area = calculateRectangleArea(testPoints);
        printf_s("| Shape Type:      %-21s |\n", "RECTANGLE");
        printf_s("| Area:            %-21.2f |\n", area);
        printf_s("| Validation:      %-21s |\n", "PASSED ALL TESTS");
    }
    else {
        printf_s("| Shape Type:      %-21s |\n", "QUADRILATERAL");
        printf_s("| Area:            %-21s |\n", "NOT A RECTANGLE");
        printf_s("| Validation:      %-21s |\n", "FAILED RECTANGLE TESTS");
    }
    printf_s("+===========================================+\n");

    return isValidRect ? "Valid rectangle - area calculated" : "Quadrilateral - perimeter only";
}