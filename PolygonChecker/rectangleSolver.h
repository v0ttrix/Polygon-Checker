#pragma once

float(*getRectanglePoints(float rectanglePoints[4][2]))[2];	//declare getRectanglePoints to accept the (x,y) pair
float calculateDistance(float point1[2], float point2[2]);	//calculate distance from all points
bool isPerpendicular(float point1[2], float point2[2], float point3[2]);	//declare if lines are perpendicular
char* analyzeRectangle(float rectanglePoints[4][2]);	//declare analyzeRectangle to check for rectangle