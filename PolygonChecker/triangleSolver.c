#include <stdio.h>
#include <math.h>
#include "triangleSolver.h"

#define PI 3.14159265359

char* analyzeTriangle(int side1, int side2, int side3) {
    // Input validation
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        return "Invalid input: sides must be positive";
    }
    
    if (side1 == -1) {
        return "Invalid input format";
    }
    
    // Triangle inequality check
    if ((side1 + side2 <= side3) || (side1 + side3 <= side2) || (side2 + side3 <= side1)) {
        return "Not a triangle: violates triangle inequality";
    }
    
    // Determine triangle type
    char* triangleType;
    if (side1 == side2 && side2 == side3) {
        triangleType = "Equilateral triangle";
    } else if (side1 == side2 || side1 == side3 || side2 == side3) {
        triangleType = "Isosceles triangle";
    } else {
        triangleType = "Scalene triangle";
    }
    
    // Calculate and display angles
    double angle1 = calculateAngle(side2, side3, side1);
    double angle2 = calculateAngle(side1, side3, side2);
    double angle3 = calculateAngle(side1, side2, side3);
    
    printf("Triangle type: %s\n", triangleType);
    printf("Angles: %.2f°, %.2f°, %.2f°\n", angle1, angle2, angle3);
    
    return triangleType;
}

double calculateAngle(int a, int b, int c) {
    // Law of cosines: cos(C) = (a² + b² - c²) / (2ab)
    double cosineC = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2.0 * a * b);
    
    // Clamp to valid range to avoid numerical errors
    if (cosineC > 1.0) cosineC = 1.0;
    if (cosineC < -1.0) cosineC = -1.0;
    
    return acos(cosineC) * (180.0 / PI);
}