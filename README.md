# Polygon Checker

A C program for analyzing geometric shapes (triangles and rectangles) with comprehensive validation and mathematical calculations.

## 🚀 Key Improvements Made

**Critical Bug Fixes:**
- Fixed scanf format specifier from `%1o` (octal) to `%d` (decimal) - this was causing menu selection to fail
- Replaced unsafe `scanf_s` and `printf_s` with standard portable functions
- Added proper input validation and buffer clearing

**Code Quality:**
- Added meaningful constants instead of magic numbers
- Improved error handling and user feedback
- Eliminated excessive comments and cleaned up code structure
- Better memory safety with input validation

**Mathematical Accuracy:**
- Added numerical stability to angle calculations with clamping
- Improved rectangle detection algorithm
- Better distance calculation and perpendicularity checking
- More precise floating-point comparisons with epsilon

## 📁 Features

### Triangle Analysis
- **Input Validation**: Checks for positive sides and triangle inequality
- **Classification**: Identifies equilateral, isosceles, or scalene triangles
- **Angle Calculation**: Uses law of cosines to compute all angles
- **Error Handling**: Comprehensive input validation and error messages

### Rectangle Analysis  
- **Point Input**: Accepts 4 coordinate points
- **Validation**: Verifies points can form a rectangle
- **Calculations**: Computes perimeter and area
- **Distance Analysis**: Calculates all inter-point distances

## 🛠 Building and Running

### Prerequisites
- C compiler (GCC, Clang, or MSVC)
- Standard math library

### Compilation
```bash
# GCC/Clang
gcc -std=c99 -Wall -Wextra -lm PolygonChecker/*.c -o polygon_checker

# MSVC
cl PolygonChecker/*.c /Fe:polygon_checker.exe
```

### Usage
```bash
./polygon_checker
```

## 📊 Improvements Summary

**Before vs After:**
- **Critical Bug**: Menu selection broken (octal format) → Fixed (decimal format)
- **Portability**: Windows-specific functions → Standard C functions
- **Validation**: Basic checks → Comprehensive input validation
- **Error Handling**: Poor → Robust with clear messages
- **Code Quality**: Cluttered → Clean and maintainable

**Technical Fixes:**
- Fixed scanf format specifier causing menu failures
- Added input buffer clearing for invalid inputs
- Improved numerical stability in calculations
- Better memory safety with validation
- Consistent error handling throughout

## 🎯 Sample Usage

```
**********************
**     Welcome to     **
**   Polygon Checker  **
**********************
1. Triangle
2. Rectangle
0. Exit
Enter number: 1

Triangle selected.
Enter the three sides of the triangle: 3 4 5
Triangle type: Scalene triangle
Angles: 90.00°, 53.13°, 36.87°
```

## 🧪 Test Coverage

The program handles:
- ✅ Valid triangles (all types)
- ✅ Invalid triangles (triangle inequality violations)
- ✅ Rectangle point validation
- ✅ Invalid input handling
- ✅ Numerical edge cases

## 📄 License

Educational use - demonstrates geometric calculations and input validation in C.
