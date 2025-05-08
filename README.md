# Polygon Checker (C Project)

This C program allows users to analyze geometric shapes—specifically triangles and rectangles—via a command-line interface. The solution also includes comprehensive unit tests for correctness.

## 🧠 Features

- **Triangle Analysis**
  - Classifies triangles as Equilateral, Isosceles, or Scalene.
  - Checks triangle validity.
  - Calculates internal angles using the Law of Cosines.

- **Rectangle Analysis**
  - Checks if 4 points form a rectangle.
  - Verifies perpendicular sides using dot product.
  - Calculates perimeter and area.

## 📂 File Structure

| File | Description |
|------|-------------|
| `main.c` / `main.h` | CLI logic and menu interface |
| `triangleSolver.c` / `.h` | Triangle analysis and angle calculations |
| `rectangleSolver.c` / `.h` | Rectangle geometry and validation |
| `UnitTestTriangle.cpp` | Tests for triangle functions |
| `RecTestCases.cpp` | Tests for rectangle function |

## 🧪 Unit Testing

### ✅ `UnitTestTriangle.cpp`
- Validates triangle type and angle calculations.
- Framework: Microsoft Visual Studio CppUnitTest

### ✅ `RecTestCases.cpp`
- Tests rectangle area calculation.
- Handles edge cases and invalid input.
- Framework: Microsoft Visual Studio CppUnitTest


## For educational use only.
