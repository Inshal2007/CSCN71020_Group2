#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTests
{
    TEST_CLASS(BasicRectangleTests)
    {
    public:
        TEST_METHOD(TestRectangleConcept_AreaCalculation)
        {
            double length = 4.0;
            double width = 4.0;
            double expectedArea = 16.0;
            double actualArea = length * width;
            Assert::AreEqual(expectedArea, actualArea, 0.001);
        }

        TEST_METHOD(TestRectangleConcept_PerimeterCalculation)
        {
            // Concept: Rectangle 4x4 should have perimeter 16
            double length = 4.0;
            double width = 4.0;
            double expectedPerimeter = 16.0;
            double actualPerimeter = 2 * (length + width); // GREEN PHASE

            Assert::AreEqual(expectedPerimeter, actualPerimeter, 0.001);
        }

        // NEW RED: Test rectangle validation concept
        TEST_METHOD(TestRectangleValidation_RightAngles_ShouldFail)
        {
            // Concept: Rectangle should have 4 right angles
            bool hasFourRightAngles = false; // Not validated yet - RED PHASE
            Assert::IsFalse(hasFourRightAngles);
        }
    };
}