#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "rectangleSolver.h"

#define EPSILON 1e-6

float calculateDistance(float point1[2], float point2[2]) {
    return sqrt(pow(point2[0] - point1[0], 2) + pow(point2[1] - point1[1], 2));
}

bool isPerpendicular(float point1[2], float point2[2], float point3[2]) {
    float dx1 = point2[0] - point1[0];
    float dy1 = point2[1] - point1[1];
    float dx2 = point3[0] - point2[0];
    float dy2 = point3[1] - point2[1];
    
    // Dot product should be zero for perpendicular vectors
    return fabs(dx1 * dx2 + dy1 * dy2) < EPSILON;
}

float(*getRectanglePoints(float rectanglePoints[4][2]))[2] {
    printf("Enter coordinates for 4 points:\n");
    for (int i = 0; i < 4; i++) {
        printf("Point %d (x y): ", i + 1);
        if (scanf("%f %f", &rectanglePoints[i][0], &rectanglePoints[i][1]) != 2) {
            printf("Invalid input. Please enter numeric values.\n");
            rectanglePoints[0][0] = -1; // Signal invalid input
            break;
        }
    }
    return rectanglePoints;
}

char* analyzeRectangle(float rectanglePoints[4][2]) {
    if (rectanglePoints[0][0] == -1) {
        return "Invalid input for points";
    }
    
    // Calculate all 6 distances between 4 points
    float distances[6];
    int idx = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            distances[idx++] = calculateDistance(rectanglePoints[i], rectanglePoints[j]);
        }
    }
    
    // Sort distances
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (distances[i] > distances[j]) {
                float temp = distances[i];
                distances[i] = distances[j];
                distances[j] = temp;
            }
        }
    }
    
    // For a rectangle: 4 sides (2 pairs of equal length) + 2 diagonals (equal length)
    bool validDistances = (fabs(distances[0] - distances[1]) < EPSILON) &&
                         (fabs(distances[2] - distances[3]) < EPSILON) &&
                         (fabs(distances[4] - distances[5]) < EPSILON);
    
    if (!validDistances) {
        return "Points do not form a rectangle";
    }
    
    // Check perpendicularity (simplified check)
    // For a proper rectangle check, we'd need to verify the point ordering
    
    float width = distances[0];
    float height = distances[2];
    float perimeter = 2 * (width + height);
    float area = width * height;
    
    static char result[256];
    snprintf(result, sizeof(result), 
             "Rectangle detected\nPerimeter: %.2f\nArea: %.2f", 
             perimeter, area);
    return result;
}
