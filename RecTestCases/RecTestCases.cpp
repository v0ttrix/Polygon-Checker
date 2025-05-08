#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

// Function to calculate the area of a rectangle
int Rectangle(int width, int height) {
    // Validate inputs
    if (width < 1 || width > 200) {
        cerr << "Error: Width must be between 1 and 200." << endl;
        return -1; // Indicate an error
    }
    if (height < 1 || height > 100) {
        cerr << "Error: Height must be between 1 and 100." << endl;
        return -1; // Indicate an error
    }

    // Calculate and return the area
    return width * height;
}

namespace UnitTestREC
{
    TEST_CLASS(UnitTestREC)
    {
    public:

        // Test Method for Rectangle with edge case minimum width
        TEST_METHOD(TestRectangleEdgeCaseMinWidth)
        {
            Assert::AreEqual(Rectangle(1, 100), 100);   // Edge case with minimum width
        }

        // Test Method for Rectangle with edge case minimum height
        TEST_METHOD(TestRectangleEdgeCaseMinHeight)
        {
            Assert::AreEqual(Rectangle(200, 1), 200);   // Edge case with minimum height
        }

        // Test Method for Rectangle with invalid width
        TEST_METHOD(TestRectangleInvalidWidth)
        {
            Assert::AreEqual(Rectangle(-15, 10), -1);  // Invalid width
        }

        // Test Method for Rectangle with invalid height
        TEST_METHOD(TestRectangleInvalidHeight)
        {
            Assert::AreEqual(Rectangle(15, -10), -1);  // Invalid height
        }

        // Test Method for Rectangle with width out of range
        TEST_METHOD(TestRectangleWidthOutOfRange)
        {
            Assert::AreEqual(Rectangle(250, 10), -1);  // Width out of range
        }

        // Test Method for Rectangle with height out of range
        TEST_METHOD(TestRectangleHeightOutOfRange)
        {
            Assert::AreEqual(Rectangle(15, 150), -1);  // Height out of range
        }

        // Test Method for Rectangle function with valid inputs
        TEST_METHOD(TestRectangleValidInputs)
        {
            Assert::AreEqual(Rectangle(15, 10), 150);   // Valid case
        }

    };
}
