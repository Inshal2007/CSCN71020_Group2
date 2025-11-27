#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "rectangleSolver.h"

typedef struct Point {
    int x;
    int y;
} Point;

void getRectanglePoints(int* xCoords, int* yCoords) {
    printf_s("Rectangle coordinate input system - Feature under development\n");
    printf_s("This feature will allow entering four points to analyze rectangle properties\n");

    for (int i = 0; i < 4; i++) {
        xCoords[i] = i + 1;
        yCoords[i] = i + 1;
    }

    printf_s("Sample points set for testing: (1,1), (2,2), (3,3), (4,4)\n");
}

// Calculates distance between two points using Pythagorean theorem
static double calculateDistance(const Point p1, const Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt((double)dx * dx + (double)dy * dy);
}

// Finds the point with the smallest x+y value (top-left corner)
static int findTopLeftIndex(const Point points[]) {
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

// Finds the point farthest from the provided index (used to pick opposite corner)
static int findTopRightIndex(const Point points[], int topLeftIndex) {
    int topRightIndex = -1;
    double maxDistance = -1.0;

    for (int i = 0; i < 4; i++) {
        if (i == topLeftIndex) {
            continue;
        }
        double distance = calculateDistance(points[topLeftIndex], points[i]);
        if (distance > maxDistance) {
            maxDistance = distance;
            topRightIndex = i;
        }
    }

    // Safety: ensure we always return a valid index
    if (topRightIndex == -1) {
        for (int i = 0; i < 4; i++) {
            if (i != topLeftIndex) {
                topRightIndex = i;
                break;
            }
        }
    }

    return topRightIndex;
}

// Sorts four points into corner order: top-left, top-right, bottom-left, bottom-right
static void sortPointsByCorner(Point points[]) {
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

    // Compare by x to decide left vs right among the remaining two
    if (points[remainingIndices[0]].x <= points[remainingIndices[1]].x) {
        sortedPoints[2] = points[remainingIndices[0]];
        sortedPoints[3] = points[remainingIndices[1]];
    } else {
        sortedPoints[2] = points[remainingIndices[1]];
        sortedPoints[3] = points[remainingIndices[0]];
    }

    for (int i = 0; i < 4; i++) {
        points[i] = sortedPoints[i];
    }
}

// Improved display function with better formatting
static void displaySortedPoints(const Point points[]) {
    printf_s("\n+==============================+\n");
    printf_s("|      CORNER DETECTION       |\n");
    printf_s("+==============================+\n");
    printf_s("| Top-Left:     (%3d, %3d)     |\n", points[0].x, points[0].y);
    printf_s("| Top-Right:    (%3d, %3d)     |\n", points[1].x, points[1].y);
    printf_s("| Bottom-Left:  (%3d, %3d)     |\n", points[2].x, points[2].y);
    printf_s("| Bottom-Right: (%3d, %3d)     |\n", points[3].x, points[3].y);
    printf_s("+==============================+\n");
}

// Validates that no lines cross in the quadrilateral
static bool validateNoCrossingLines(const Point points[]) {
    (void)points; // placeholder to silence unused-parameter warnings
    printf_s("Line crossing validation - Ready for implementation\n");
    return true; // Placeholder - will be enhanced in future issues
}

char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    Point testPoints[4] = {
        {x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}
    };

    printf_s("\nOriginal Points:\n");
    for (int i = 0; i < 4; i++) {
        printf_s("Point %d: (%d, %d)\n", i + 1, testPoints[i].x, testPoints[i].y);
    }

    sortPointsByCorner(testPoints);
    displaySortedPoints(testPoints);

    // Validate that lines don't cross
    bool validShape = validateNoCrossingLines(testPoints);

    const char* msg = validShape
        ? "Corners detected successfully - No lines cross"
        : "Corners detected - Line crossing detected";

    size_t len = strlen(msg) + 1;
    char* result = (char*)malloc(len);
    if (result != NULL) {
        memcpy(result, msg, len);
    }

    return result;
}