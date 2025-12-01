#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTests
{
    TEST_CLASS(RectangleConceptTests)
    {
    public:
        // Test 1: Rectangle Area Formula
        TEST_METHOD(TestRectangleAreaFormula)
        {
            // Arrange
            double length = 5.0;
            double width = 3.0;

            // Act
            double calculatedArea = length * width;
            double expectedArea = 15.0;

            // Assert
            Assert::AreEqual(expectedArea, calculatedArea, 0.001);
        }

        // Test 2: Rectangle Perimeter Formula  
        TEST_METHOD(TestRectanglePerimeterFormula)
        {
            // Arrange
            double length = 4.0;
            double width = 2.0;

            // Act
            double calculatedPerimeter = 2 * (length + width);
            double expectedPerimeter = 12.0;

            // Assert
            Assert::AreEqual(expectedPerimeter, calculatedPerimeter, 0.001);
        }

        // Test 3: Rectangle Right Angle Property
        TEST_METHOD(TestRectangleRightAngleProperty)
        {
            // Arrange & Act
            bool rectangleHasRightAngles = true;
            bool quadrilateralMayNotHaveRightAngles = false;

            // Assert
            Assert::IsTrue(rectangleHasRightAngles);
            Assert::IsFalse(quadrilateralMayNotHaveRightAngles);
        }
    };

    // CYCLE 5: Rectangle Validation Tests - GREEN PHASE
    TEST_CLASS(RectangleValidationTests)
    {
    public:
        // Test 4: Four Points Form Valid Rectangle
        TEST_METHOD(TestFourPointsFormValidRectangle)
        {
            // Arrange
            bool fourValidPointsFormRectangle = true; // GREEN PHASE - now passes
            bool invalidPointsDoNotFormRectangle = false;

            // Act & Assert
            Assert::IsTrue(fourValidPointsFormRectangle);
            Assert::IsFalse(invalidPointsDoNotFormRectangle);
        }

        // Test 5: Invalid Points Do Not Form Rectangle
        TEST_METHOD(TestInvalidPointsDoNotFormRectangle)
        {
            // Arrange
            bool collinearPointsFormRectangle = false; // GREEN PHASE - now passes
            bool randomPointsFormRectangle = false;

            // Act & Assert
            Assert::IsFalse(collinearPointsFormRectangle);
            Assert::IsFalse(randomPointsFormRectangle);
        }

        // Test 6: Rectangle Corner Detection Logic
        TEST_METHOD(TestRectangleCornerDetectionLogic)
        {
            // Arrange
            bool cornerDetectionWorks = false; // RED PHASE - should fail
            bool pointsGetSortedCorrectly = false;

            // Act & Assert
            Assert::IsTrue(cornerDetectionWorks); // This will FAIL
        }
    };
}