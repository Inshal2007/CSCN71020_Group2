#include <stdio.h>
#include <stdbool.h>
#include "main.h"
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

            int triangleSides[3] = { 0, 0, 0 };
            int* triangleSidesPtr = getTriangleSides(triangleSides);

            char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);

            // Only calculate angles if triangle is valid (all sides positive)
            if (triangleSidesPtr[0] > 0 && triangleSidesPtr[1] > 0 && triangleSidesPtr[2] > 0) {
                double angle1, angle2, angle3;
                calculateTriangleAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], &angle1, &angle2, &angle3);

                printf_s("\n+==============================+\n");
                printf_s("\n+==============================+\n");
                printf_s("|       TRIANGLE ANALYSIS      |\n");
                printf_s("\n+==============================+\n");
                printf_s("\n+==============================+\n");
                printf_s("| Type: %-21s |\n", result);
                printf_s("| Angles: %-3.0f, %-3.0f, %-3.0f         |\n", angle1, angle2, angle3);

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
    int inputResult;
    char buffer[100]; // Buffer for handling invalid input

    printf_s("Enter number: ");

    // Input validation loop - ensures valid menu selection
    do {
        inputResult = scanf_s("%d", &shapeChoice);

        if (inputResult != 1) {
            printf_s("Invalid input. Please enter 0, 1, or 2: ");
            scanf_s("%99s", buffer, (unsigned)sizeof(buffer));
            inputResult = 0;
        }
        else if (shapeChoice < 0 || shapeChoice > 2) {
            printf_s("Please enter 0, 1, or 2 only: ");
            inputResult = 0;
        }
    } while (inputResult != 1);

    return shapeChoice;
}

// Gets three triangle side lengths from user with validation
int* getTriangleSides(int* triangleSides) {
    printf_s("Enter the three sides of the triangle: \n");

    const int MIN_SIDE = 0;
    const int MAX_SIDE = 10000;

    for (int i = 0; i < 3; i++) {
        printf_s("Enter side %d: ", i + 1);

        int inputResult;
        char buffer[100];

        do {
            inputResult = scanf_s("%d", &triangleSides[i]);

            if (inputResult != 1) {
                printf_s("Invalid input. Please enter a number between %d and %d: ", MIN_SIDE, MAX_SIDE);
                scanf_s("%99s", buffer, (unsigned)sizeof(buffer));
                inputResult = 0;
            }
            else if (triangleSides[i] < 0) {
                printf_s("Number too small. Please enter a number between %d and %d: ", MIN_SIDE, MAX_SIDE);
                inputResult = 0;
            }
            else if (triangleSides[i] > MAX_SIDE) {
                printf_s("Number too large. Please enter a number between %d and %d: ", MIN_SIDE, MAX_SIDE);
                inputResult = 0;
            }
        } while (inputResult != 1);
    }

    return triangleSides;
}