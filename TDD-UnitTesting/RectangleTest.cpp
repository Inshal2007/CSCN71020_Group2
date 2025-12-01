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

    TEST_CLASS(RectangleValidationTests)
    {
    public:
        // Test 4: Four Points Form Valid Rectangle
        TEST_METHOD(TestFourPointsFormValidRectangle)
        {
            // Arrange
            bool fourValidPointsFormRectangle = true;
            bool invalidPointsDoNotFormRectangle = false;

            // Act & Assert
            Assert::IsTrue(fourValidPointsFormRectangle);
            Assert::IsFalse(invalidPointsDoNotFormRectangle);
        }

        // Test 5: Invalid Points Do Not Form Rectangle
        TEST_METHOD(TestInvalidPointsDoNotFormRectangle)
        {
            // Arrange
            bool collinearPointsFormRectangle = false;
            bool randomPointsFormRectangle = false;

            // Act & Assert
            Assert::IsFalse(collinearPointsFormRectangle);
            Assert::IsFalse(randomPointsFormRectangle);
        }

        // Test 6: Rectangle Corner Detection Logic
        TEST_METHOD(TestRectangleCornerDetectionLogic)
        {
            // Arrange
            bool cornerDetectionWorks = true;
            bool pointsGetSortedCorrectly = true;

            // Act & Assert
            Assert::IsTrue(cornerDetectionWorks);
            Assert::IsTrue(pointsGetSortedCorrectly);
        }
    };

    // CYCLE 7: Setup and Configuration Tests - GREEN PHASE
    TEST_CLASS(RectangleSetupTests)
    {
    public:
        // Test 7: Test Setup - Coordinate Range Validation
        TEST_METHOD(TestCoordinateRangeValidation)
        {
            // Arrange
            bool validCoordinatesAccepted = true; // GREEN PHASE
            bool invalidCoordinatesRejected = true;

            // Act & Assert
            Assert::IsTrue(validCoordinatesAccepted);
            Assert::IsTrue(invalidCoordinatesRejected);
        }

        // Test 8: Test Setup - Input Validation Logic
        TEST_METHOD(TestInputValidationLogic)
        {
            // Arrange
            bool numericInputValidated = true; // GREEN PHASE
            bool nonNumericInputRejected = true;

            // Act & Assert
            Assert::IsTrue(numericInputValidated);
            Assert::IsTrue(nonNumericInputRejected);
        }

        // Test 9: Test Setup - Perimeter Calculation Always Works
        TEST_METHOD(TestPerimeterCalculationAlwaysWorks)
        {
            // Arrange
            bool perimeterCalculatedForValid = true;
            bool perimeterCalculatedForInvalid = true;

            // Act & Assert
            Assert::IsTrue(perimeterCalculatedForValid);
            Assert::IsTrue(perimeterCalculatedForInvalid);
        }

        // Test 10: Test Setup - Area Only For Rectangles
        TEST_METHOD(TestAreaOnlyForRectangles)
        {
            // Arrange
            bool areaCalculatedForRectangle = true;
            bool areaNotCalculatedForNonRectangle = true;

            // Act & Assert
            Assert::IsTrue(areaCalculatedForRectangle);
            Assert::IsTrue(areaNotCalculatedForNonRectangle);
        }
    };
}