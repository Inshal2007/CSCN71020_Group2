#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

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
	char buffer[100];

	printf_s("Enter number: ");

	do {
		inputResult = scanf_s("%d", &shapeChoice);

		if (inputResult != 1) {
			printf_s("Invalid input. Please enter 0 or 1: ");
			scanf_s("%99s", buffer, (unsigned)sizeof(buffer));
			inputResult = 0;
		}
		else if (shapeChoice != 0 && shapeChoice != 1) {
			printf_s("Please enter 0 or 1 only: ");
			inputResult = 0;
		}
	} while (inputResult != 1);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: \n");

	for (int i = 0; i < 3; i++)
	{
		printf_s("Enter side %d: ", i + 1);

		int inputResult;
		char buffer[100];

		do {
			inputResult = scanf_s("%d", &triangleSides[i]);

			if (inputResult != 1) {
				printf_s("Invalid input. Please enter a positive number: ");
				scanf_s("%99s", buffer, (unsigned)sizeof(buffer));
				inputResult = 0;
			}
			else if (triangleSides[i] <= 0) {
				printf_s("Side length must be positive. Please enter a positive number: ");
				inputResult = 0;
			}
		} while (inputResult != 1);
	}

	return triangleSides;
}