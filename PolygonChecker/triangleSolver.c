#include <stdio.h>
#include <stdbool.h>
#include <math.h> 
#include "triangleSolver.h"

#define PI 3.14159265

char* analyzeTriangle(int side1, int side2, int side3) {
    char* result = "";

    if (side1 <= 0 || side2 <= 0 || side3 <= 0 ||
        (side1 + side2 <= side3) || (side1 + side3 <= side2) || (side2 + side3 <= side1)) {
        result = "Not a Triangle";
        return result;
    }

    // Determine the type of triangle
    if (side1 == side2 && side1 == side3) {
        result = "Equilateral Triangle";
    }
    else if ((side1 == side2 && side1 != side3) ||
        (side1 == side3 && side1 != side2) ||
        (side2 == side3 && side2 != side1)) {
        result = "Isosceles Triangle";
    }
    else {
        result = "Scalene Triangle";
    }

    printf_s("Triangle type: %s\n", result);

    // Calculate angles using the law of cosines
    double angle1 = calculateAngle(side2, side3, side1);
    double angle2 = calculateAngle(side1, side3, side2);
    double angle3 = calculateAngle(side1, side2, side3);

    printf_s("Angles (in degrees):\n");
    printf_s("Angle 1: %.2f\n", angle1);
    printf_s("Angle 2: %.2f\n", angle2);
    printf_s("Angle 3: %.2f\n", angle3);

    return result;
}
//Aya
double calculateAngle(int a, int b, int c) {
    // Law of cosines: cos(C) = (a^2 + b^2 - c^2) / (2ab)
    double cosineC = (pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2.0 * a * b);
    double angleC = acos(cosineC) * (180.0 / PI); // Convert radians to degrees
    return angleC;
}