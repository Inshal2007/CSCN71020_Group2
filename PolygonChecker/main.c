#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {

	// Control variable to keep the program running until user chooses to exit
	bool continueProgram = true;

	// Main program loop - keeps running until user selects exit
	while (continueProgram) {
		
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:

			// if user selected triangle analysi
			printf_s("Triangle selected.\n");
			
			// Create an array to store the three triangle sides, initialized to zero
			int triangleSides[3] = { 0, 0, 0 };
			
			// Get the triangle sides from user input and store the pointer
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			
			// Analyze the triangle with the three side lengths provided by user
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			
			printf_s("%s\n", result);
			
			// Only calculate and display angles if it's a valid triangle (all sides positive)
			
			if (triangleSidesPtr[0] > 0 && triangleSidesPtr[1] > 0 && triangleSidesPtr[2] > 0) {
				
				double angle1, angle2, angle3;
				// Calculate the three interior angles of the triangle
				
				calculateTriangleAngles(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2], &angle1, &angle2, &angle3);
				// Display the calculated angles to the user
				
				printf_s("Triangle Angles: %.2f degree, %.2f degree, %.2f degree\n", angle1, angle2, angle3);
			}
			break;
		
		case 0:

			// User selected exit, set flag to false to break the loop
			continueProgram = false;
			break;
		
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

//  Function to display a welcome banner to the user
void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;
	int inputResult;
	char buffer[100]; // Buffer to clear any invalid input from user

	printf_s("Enter number: ");

	// Keep asking until we get valid input (0 or 1)
	do {
		inputResult = scanf_s("%d", &shapeChoice);

		if (inputResult != 1) {
			
			// Inform user of invalid input and prompt again
			printf_s("Invalid input. Please enter 0 or 1: ");
			scanf_s("%99s", buffer, (unsigned)sizeof(buffer));
			inputResult = 0;
		}
		// Check if user entered a number that's not 0 or 1
		else if (shapeChoice != 0 && shapeChoice != 1) {
			printf_s("Please enter 0 or 1 only: ");
			inputResult = 0;
		}
	} while (inputResult != 1); // Continue looping until we get valid input

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: \n");

	// Reasonable limits for triangle sides to prevent overflow and unrealistic values
	
	const int MIN_SIDE = 0;  // Allow 0 as input
	const int MAX_SIDE = 10000;

	// Get each of the three sides one by one
	for (int i = 0; i < 3; i++)
	{
		printf_s("Enter side %d: ", i + 1);

		int inputResult; // Stores whether we successfully read a number
		char buffer[100]; // Used to clear out any bad input like letters

		// Keep asking until we get valid input within our limits
		do {
			// Try to read a number from what the user typed
			inputResult = scanf_s("%d", &triangleSides[i]);

			// If user entered letters or symbols instead of numbers
			if (inputResult != 1) {
				
				
				printf_s("Invalid input. Please enter a number between %d and %d: ", MIN_SIDE, MAX_SIDE);
				// Clear the invalid input from the keyboard buffer
				
				scanf_s("%99s", buffer, (unsigned)sizeof(buffer));
				inputResult = 0; // Make sure we continue asking
			}
			
			// If user entered a number that's too small (triangle sides must be positive)
			else if (triangleSides[i] < 0) {  // Only block negative numbers, allow 0
				printf_s("Number too small. Please enter a number between %d and %d: ", MIN_SIDE, MAX_SIDE);
				inputResult = 0;
			}
			
			// If user entered a number that's too large (prevent overflow and unrealistic values)
			else if (triangleSides[i] > MAX_SIDE) {
				
				printf_s("Number too large. Please enter a number between %d and %d: ", MIN_SIDE, MAX_SIDE);
				inputResult = 0; // Make sure we continue asking
			}
		} while (inputResult != 1); // Keep looping until we get a valid number in range
	}

	return triangleSides;
}