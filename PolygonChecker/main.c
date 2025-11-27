#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include <string.h>
#include "triangleSolver.h"
#include "rectangleSolver.h"

int side = 0;

// Main program entry point - runs the polygon checker application
int main() {
    bool continueProgram = true;

    // Main program loop - continues until user chooses to exit
    while (continueProgram) {
        printWelcome();
        int shapeChoice = printShapeMenu();

        switch (shapeChoice) {
        case 1:
            // Triangle analysis selected by user
            printf_s("Triangle selected.\n");

            double triangleSides[3] = { 0, 0, 0 };
            double* triangleSidesPtr = getTriangleSides(triangleSides);
            char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);

            // Only calculate angles if it's a valid triangle (not "Not a Triangle")
            if (strcmp(result, "Not a Triangle") != 0) {
                double angle1, angle2, angle3;
                calculateTriangleAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], &angle1, &angle2, &angle3);

                printf_s("\n+==============================+\n");
                printf_s("|       TRIANGLE ANALYSIS      |\n");
                printf_s("+==============================+\n");
                printf_s("| Type: %-21s |\n", result);
                printf_s("| Angles: %-6.2f, %-6.2f, %-6.2f   |\n", angle1, angle2, angle3);

                char* angleType = classifyTriangleByAngles(angle1, angle2, angle3);
                printf_s("| Classification: %-12s |\n", angleType);
                printf_s("+==============================+\n");
            }
            else {
                printf_s("\n+==============================+\n");
                printf_s("|       TRIANGLE ANALYSIS      |\n");
                printf_s("+==============================+\n");
                printf_s("| %-28s |\n", result);
                printf_s("+==============================+\n");
            }
            break;

        case 2:
            // Rectangle analysis selected by user
            printf_s("Rectangle selected.\n");

            int xCoords[4] = { 0, 0, 0, 0 };
            int yCoords[4] = { 0, 0, 0, 0 };

            getRectanglePoints(xCoords, yCoords);

            char* rectangleResult = analyzeRectangle(
                xCoords[0], yCoords[0],
                xCoords[1], yCoords[1],
                xCoords[2], yCoords[2],
                xCoords[3], yCoords[3]
            );

            printf_s("\n+==============================+\n");
            printf_s("|       RECTANGLE ANALYSIS     |\n");
            printf_s("+==============================+\n");
            printf_s("| Status: %-21s |\n", rectangleResult);
            printf_s("+==============================+\n");
            break;

        case 0:
            // Exit program selected by user
            continueProgram = false;
            printf_s("Thank you for using Polygon Checker. Goodbye!\n");
            break;

        default:
            printf_s("Invalid value entered.\n");
            break;
        }
    }
    return 0;
}

// Displays welcome banner when program starts
void printWelcome() {
    printf_s("\n");
    printf_s(" **********************\n");
    printf_s(" **********************\n");
    printf_s("**     Welcome to     **\n");
    printf_s("**   Polygon Checker  **\n");
    printf_s(" **********************\n");
    printf_s(" **********************\n");
}

// Displays shape selection menu and gets user choice
int printShapeMenu() {
    printf_s("1. Triangle\n");
    printf_s("2. Rectangle\n");
    printf_s("0. Exit\n");

    int shapeChoice;
    char inputBuffer[100]; // Buffer to read entire input line

    printf_s("Enter number: ");

    // Input validation loop - ensures valid menu selection
    while (1) {
       
        // Read entire line as string to capture all user input
        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) != NULL) {
            
            // Try to convert to integer and check for extra content after the number
            char extraContent[100];
            int conversionResult = sscanf_s(inputBuffer, "%d %s", &shapeChoice, extraContent, (unsigned)sizeof(extraContent));
            
            // Valid input: conversion successful, no extra content, and within valid range
            if (conversionResult == 1 && shapeChoice >= 0 && shapeChoice <= 2) {
           
                return shapeChoice; // Valid input - return the choice
            }
        }
        // Invalid input - prompt user again
        printf_s("Invalid input. Please enter 0, 1, or 2 only: ");
    }
}

// Gets three triangle side lengths from user with validation
double* getTriangleSides(double* triangleSides) {

    printf_s("Enter the three sides of the triangle: \n");

    const double MIN_SIDE = 0.1;
    const double MAX_SIDE = 10000.0;

    for (int i = 0; i < 3; i++) {
        printf_s("Enter side %d: ", i + 1);

        int validInput = 0;
        char inputLine[100];

        while (!validInput) {
            if (fgets(inputLine, sizeof(inputLine), stdin)) {

                double tempValue;
                char extraContent[100];

                // Try to parse as double and check for extra characters
                int parseResult = sscanf_s(inputLine, "%lf %s", &tempValue, extraContent, (unsigned)sizeof(extraContent));

                if (parseResult == 1) {
                    // Valid number with no extra characters
                    if (tempValue >= MIN_SIDE && tempValue <= MAX_SIDE) {
                        triangleSides[i] = tempValue;
                        validInput = 1;
                    }
                    else {
                        printf_s("Please enter a number between %.1f and %.1f: ", MIN_SIDE, MAX_SIDE);
                    }
                }
                else {
                    // Either no number found or mixed characters
                    printf_s("Invalid input. Numbers only, no characters: ");
                }
            }
        }
    }
    return triangleSides;
}