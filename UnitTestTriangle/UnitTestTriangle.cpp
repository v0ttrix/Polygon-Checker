#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>

extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" double calculateAngle(int a, int b, int c);



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTriangle
{
	TEST_CLASS(UnitTestTriangle)
	{
	public:

		TEST_METHOD(TestTriangle01)
		{//testing the analyzeTriangle function using 0 for all sides
			int side1 = 0;
			int side2 = 0;
			int side3 = 0;
			char* expected = "Not a Triangle";

			char* result = analyzeTriangle(side1, side2, side3);
			Assert::IsTrue(strcmp(expected, result) == 0);
		}
		TEST_METHOD(TestTriangle02)
		{//testing the analyzeTriangle function using the same length for all sides
			int side1 = 3;
			int side2 = 3;
			int side3 = 3;
			char* expected = "Equilateral Triangle";

			char* result = analyzeTriangle(side1, side2, side3);
			Assert::IsTrue(strcmp(expected, result) == 0);
		}
		TEST_METHOD(TestTriangle03)
		{//testing the analyzeTriangle function using the same length for 2 sides
			int side1 = 3;
			int side2 = 3;
			int side3 = 5;
			char* expected = "Isosceles Triangle";

			char* result = analyzeTriangle(side1, side2, side3);
			Assert::IsTrue(strcmp(expected, result) == 0);
		}
		TEST_METHOD(TestTriangle04)
		{//testing the analyzeTriangle function using different lengths for each side
			int side1 = 3;
			int side2 = 4;
			int side3 = 5;
			char* expected = "Scalene Triangle";

			char* result = analyzeTriangle(side1, side2, side3);
			Assert::IsTrue(strcmp(expected, result) == 0);
		}
		TEST_METHOD(TestTriangle05)
		{//testing the analyzeTriangle function using an outlier 
			int side1 = 4;
			int side2 = 4;
			int side3 = 99;
			char* expected = "Not a Triangle";

			char* result = analyzeTriangle(side1, side2, side3);
			Assert::IsTrue(strcmp(expected, result) == 0);
		}
		TEST_METHOD(TestTriangleAngle01)
		{//test for right angle triangle
			int side1 = 3;
			int side2 = 4;
			int side3 = 5;

			double angle1 = calculateAngle(side3, side1, side2);
			double angle2 = calculateAngle(side1, side2, side3);
			double angle3 = calculateAngle(side2, side3, side1);

			Assert::AreEqual(53.13, angle1, 0.01);
			Assert::AreEqual(90.0, angle2, 0.01);
			Assert::AreEqual(36.87, angle3, 0.01);
		}
		TEST_METHOD(TestTriangleAngle02)
		{//test for isoceles triangle
			int side1 = 3;
			int side2 = 3;
			int side3 = 5;

			double angle1 = calculateAngle(side2, side3, side1);
			double angle2 = calculateAngle(side1, side3, side2);
			double angle3 = calculateAngle(side1, side2, side3);

			Assert::AreEqual(33.55, angle1, 0.01);
			Assert::AreEqual(33.55, angle2, 0.01);
			Assert::AreEqual(112.88, angle3, 0.01);
		}
		TEST_METHOD(TestTriangleAngle03)
		{//test for scalene triangle
			int side1 = 3;
			int side2 = 8;
			int side3 = 10;

			double angle1 = calculateAngle(side2, side3, side1);
			double angle2 = calculateAngle(side1, side3, side2);
			double angle3 = calculateAngle(side1, side2, side3);

			Assert::AreEqual(14.36, angle1, 0.01);
			Assert::AreEqual(41.40, angle2, 0.01);
			Assert::AreEqual(124.22, angle3, 0.01);
		}
	};
}
