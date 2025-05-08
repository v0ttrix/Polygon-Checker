#include "main.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "rectangleSolver.h"



// Function to calculate the distance between two points
float calculateDistance(float point1[2], float point2[2]) {
    return sqrt(pow(point2[0] - point1[0], 2) + pow(point2[1] - point1[1], 2));
}

// Function to check if two vectors are perpendicular
bool isPerpendicular(float point1[2], float point2[2], float point3[2]) {

    float dx1 = point2[0] - point1[0];  //first (x,y) pair

    float dy1 = point2[1] - point1[1];  //second (x,y) pair

    float dx2 = point3[0] - point2[0];  //third (x,y) pair

    float dy2 = point3[1] - point2[1];  //fourth (x,y) pair

    // Dot product of the vectors (0 for perpendicular vectors)
    return fabs(dx1 * dx2 + dy1 * dy2) < 1e-6;
}

// Function to get the points for the rectangle
float(*getRectanglePoints(float rectanglePoints[4][2]))[2] {
    for (int i = 0; i < 4; i++) {
        printf_s("Enter x and y for Point %d: ", i + 1); //ask user for x and y points
        if (scanf_s("%f %f", &rectanglePoints[i][0], &rectanglePoints[i][1]) != 2) {
            printf_s("Invalid input. Please enter numeric values.\n");  //for invalid inputs
            rectanglePoints[0][0] = -1; // Signal invalid input
            break;
        }
    }
    return rectanglePoints;
}


// Function to check if the four points form a rectangle
char* analyzeRectangle(float rectanglePoints[4][2]) {
    if (rectanglePoints[0][0] == -1) {
        return "Invalid input for points.";
    }

    // Calculate the distances between all pairs of points
    float sideLengths[6];

    sideLengths[0] = calculateDistance(rectanglePoints[0], rectanglePoints[1]); //calculating from points 0, 1, 2
    sideLengths[1] = calculateDistance(rectanglePoints[0], rectanglePoints[2]);
    sideLengths[2] = calculateDistance(rectanglePoints[0], rectanglePoints[3]);
    sideLengths[3] = calculateDistance(rectanglePoints[1], rectanglePoints[2]);
    sideLengths[4] = calculateDistance(rectanglePoints[1], rectanglePoints[3]);
    sideLengths[5] = calculateDistance(rectanglePoints[2], rectanglePoints[3]);

    // sort distances to easily compare them
    // Opposite sides of a rectangle will have the same length
    float temp;
    for (int i = 0; i < 6 - 1; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (sideLengths[i] > sideLengths[j]) {
                temp = sideLengths[i];
                sideLengths[i] = sideLengths[j];
                sideLengths[j] = temp;
            }
        }
    }


    // For valid rectangle, the two smallest distances need to be equal (width) and the next two to be equal (height)
    if (sideLengths[0] == sideLengths[1] && sideLengths[2] == sideLengths[3] && sideLengths[4] == sideLengths[5]) {
        // Check for perpendicularity of adjacent sides
        if (isPerpendicular(rectanglePoints[0], rectanglePoints[1], rectanglePoints[2]) &&
            isPerpendicular(rectanglePoints[1], rectanglePoints[2], rectanglePoints[3])) {

            // Calculate perimeter and area
            float perimeter = 2 * (sideLengths[0] + sideLengths[2]); //double of x,y pair added together 2(x+y)=Permieter
            float area = sideLengths[0] * sideLengths[2];   //L*W=A

            static char result[256];
            snprintf(result, sizeof(result), "The points form a rectangle.\nPerimeter: %.2f\nArea: %.2f", perimeter, area);
            return result;  //return results of calculation for Perimeter & Area
        }
    }

    return "The points do not form a rectangle.";   //inform user for incorrect points for a rectangle to be made
}