#pragma once

// Function to analyze if four points form a rectangle
char* analyzeRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

// Function to get four points from user input
void getRectanglePoints(int* xCoords, int* yCoords);

// Function to validate if input is a valid integer
bool isValidInteger(const char* input);

// Function to clear input buffer
void clearInputBuffer();