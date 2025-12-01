#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTests
{
    TEST_CLASS(RectangleConceptTests)
    {
    public:
        // Previous tests from cycles 1-3...
        TEST_METHOD(TestRectangleAreaFormula) { /* your existing code */ }
        TEST_METHOD(TestRectanglePerimeterFormula) { /* your existing code */ }
        TEST_METHOD(TestRectangleRightAngleProperty) { /* your existing code */ }
    };

    // CYCLE 4: Rectangle Validation Tests
    TEST_CLASS(RectangleValidationTests)
    {
    public:
        // Test 4: Four Points Form Valid Rectangle
        TEST_METHOD(TestFourPointsFormValidRectangle)
        {
            // Arrange
            bool fourValidPointsFormRectangle = false; // RED PHASE - should fail
            bool invalidPointsDoNotFormRectangle = false;

            // Act & Assert
            Assert::IsTrue(fourValidPointsFormRectangle); // This will FAIL
        }

        // Test 5: Invalid Points Do Not Form Rectangle
        TEST_METHOD(TestInvalidPointsDoNotFormRectangle)
        {
            // Arrange
            bool collinearPointsFormRectangle = true; // RED PHASE - should fail
            bool randomPointsFormRectangle = true;

            // Act & Assert
            Assert::IsFalse(collinearPointsFormRectangle); // This will FAIL
        }
    };
}   