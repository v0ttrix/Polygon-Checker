#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int main(void) {
    bool continueProgram = true;
    
    while (continueProgram) {
        printWelcome();
        int shapeChoice = printShapeMenu();
        
        switch (shapeChoice) {
            case 1: {
                printf("Triangle selected.\n");
                int triangleSides[MAX_SIDES] = {0};
                int* triangleSidesPtr = getTriangleSides(triangleSides);
                char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
                printf("%s\n", result);
                break;
            }
            case 2: {
                printf("Rectangle selected.\n");
                float rectanglePoints[MAX_POINTS][COORDINATES] = {{0}};
                float(*rectanglePointsPtr)[COORDINATES] = getRectanglePoints(rectanglePoints);
                char* rectangleResult = analyzeRectangle(rectanglePointsPtr);
                printf("%s\n", rectangleResult);
                break;
            }
            case 0:
                continueProgram = false;
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}

void printWelcome(void) {
    printf("\n **********************\n");
    printf("**     Welcome to     **\n");
    printf("**   Polygon Checker  **\n");
    printf(" **********************\n");
}

int printShapeMenu(void) {
    printf("1. Triangle\n");
    printf("2. Rectangle\n");
    printf("0. Exit\n");
    printf("Enter number: ");
    
    int shapeChoice;
    if (scanf("%d", &shapeChoice) != 1) {
        // Clear input buffer on invalid input
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return -1;
    }
    return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
    printf("Enter the three sides of the triangle: ");
    for (int i = 0; i < MAX_SIDES; i++) {
        if (scanf("%d", &triangleSides[i]) != 1) {
            triangleSides[0] = -1; // Signal invalid input
            break;
        }
    }
    return triangleSides;
}