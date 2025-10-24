#pragma once
#include <stdbool.h>

float(*getRectanglePoints(float rectanglePoints[4][2]))[2];
float calculateDistance(float point1[2], float point2[2]);
bool isPerpendicular(float point1[2], float point2[2], float point3[2]);
char* analyzeRectangle(float rectanglePoints[4][2]);