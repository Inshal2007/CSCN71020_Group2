#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "rectangleSolver.h"

// Function to clear any leftover input from the buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Function to check if a string represents a valid integer
bool isValidInteger(const char* input) {
    // Handle empty input
    if (input == NULL || strlen(input) == 0) {
        return false;
    }

    // Check each character - allow negative numbers
    int startIndex = 0;
    if (input[0] == '-') {
        startIndex = 1;
        // If it's just a minus sign, it's invalid
        if (strlen(input) == 1) {
            return false;
        }
    }

    for (int i = startIndex; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }

    return true;
}

// Function to get four coordinate points from user (basic structure)
void getRectanglePoints(int* xCoords, int* yCoords) {
    printf_s("Rectangle point input system - to be implemented in next commit\n");
}

// Function to analyze rectangle (basic structure)
char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    return "Rectangle analysis to be implemented";
}