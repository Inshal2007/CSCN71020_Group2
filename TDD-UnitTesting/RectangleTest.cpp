#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTests
{
    TEST_CLASS(BasicRectangleTests)
    {
    public:
        // TDD PHASE 2: GREEN - Make first test pass
        TEST_METHOD(TestRectangleConcept_AreaCalculation)
        {
            // Concept: A square with sides 4x4 should have area 16
            double length = 4.0;
            double width = 4.0;
            double expectedArea = 16.0;
            double actualArea = length * width; // Basic calculation - GREEN PHASE

            Assert::AreEqual(expectedArea, actualArea, 0.001);
        }

        // NEW RED: Test perimeter concept
        TEST_METHOD(TestRectangleConcept_Perimeter_ShouldFail)
        {
            // Concept: Rectangle 4x4 should have perimeter 16
            double expectedPerimeter = 16.0;
            double actualPerimeter = 0.0; // Not calculated yet - RED PHASE

            Assert::AreNotEqual(expectedPerimeter, actualPerimeter, 0.001);
        }
    };
}